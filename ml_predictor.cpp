#include "ml_predictor.h"
#include <QDateTime>
#include <QRegularExpression>
#include <QtMath>
#include <algorithm>

MLPredictor::MLPredictor() {
    analyzeHistoricalData();
}

bool MLPredictor::trainModel() {
    calculateWordWeights();
    return true;
}

void MLPredictor::analyzeHistoricalData() {
    QSqlQuery query;
    query.prepare("SELECT DESCRIPTION, STATUT, "
                "(CAST(DATE_FIN AS DATE) - CAST(DATE_DEBUT AS DATE)) as DURATION "
                "FROM GESTION_PROJET WHERE DATE_FIN IS NOT NULL");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'analyse des données historiques:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        ProjectData data;
        data.duration = query.value("DURATION").toInt();
        data.status = query.value("STATUT").toString();
        data.description = query.value("DESCRIPTION").toString();
        data.features = extractFeatures(data.description, data.status);
        
        trainingData.append(data);

        // Mettre à jour les statistiques par statut
        auto& stats = statusStats[data.status];
        stats.first = (stats.first * stats.second + data.duration) / (stats.second + 1);
        stats.second++;
    }
}

QVector<double> MLPredictor::extractFeatures(const QString& description, const QString& status) {
    QVector<double> features;
    
    // Nombre de mots
    int wordCount = description.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts).count();
    features.append(wordCount);

    // Longueur de la description
    features.append(description.length());

    // Présence de mots clés importants
    QStringList keywords = {"urgent", "complexe", "simple", "prioritaire", "maintenance",
                          "développement", "test", "debug", "optimisation", "analyse"};
    
    for (const QString& keyword : keywords) {
        features.append(description.toLower().contains(keyword) ? 1.0 : 0.0);
    }

    // Facteur basé sur le statut
    double statusFactor = 1.0;
    if (status == "EN COURS") statusFactor = 1.2;
    else if (status == "SUSPENDU") statusFactor = 1.5;
    features.append(statusFactor);

    return features;
}

void MLPredictor::calculateWordWeights() {
    // Calculer l'importance des mots basée sur leur fréquence
    QMap<QString, int> wordFrequency;
    
    for (const ProjectData& project : trainingData) {
        QStringList words = project.description.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
        for (const QString& word : words) {
            wordFrequency[word.toLower()]++;
        }
    }

    // Calculer les poids TF-IDF
    int totalProjects = trainingData.size();
    for (auto it = wordFrequency.begin(); it != wordFrequency.end(); ++it) {
        double tf = static_cast<double>(it.value()) / totalProjects;
        double idf = qLn(totalProjects / static_cast<double>(it.value()));
        wordWeights[it.key()] = tf * idf;
    }
}

double MLPredictor::calculateSimilarity(const QVector<double>& features1, const QVector<double>& features2) {
    if (features1.size() != features2.size()) return 0.0;

    double dotProduct = 0.0;
    double norm1 = 0.0;
    double norm2 = 0.0;

    for (int i = 0; i < features1.size(); ++i) {
        dotProduct += features1[i] * features2[i];
        norm1 += features1[i] * features1[i];
        norm2 += features2[i] * features2[i];
    }

    if (norm1 == 0.0 || norm2 == 0.0) return 0.0;
    return dotProduct / (qSqrt(norm1) * qSqrt(norm2));
}

int MLPredictor::predictBasedOnSimilarProjects(const QVector<double>& features, const QString& status) {
    const double SIMILARITY_THRESHOLD = 0.7;
    QVector<QPair<double, int>> similarities;

    // Calculer les similarités avec tous les projets d'entraînement
    for (const ProjectData& project : trainingData) {
        if (project.status == status) {
            double similarity = calculateSimilarity(features, project.features);
            if (similarity > SIMILARITY_THRESHOLD) {
                similarities.append({similarity, project.duration});
            }
        }
    }

    if (similarities.isEmpty()) {
        // Utiliser la moyenne pour ce statut si disponible
        if (statusStats.contains(status)) {
            return statusStats[status].first;
        }
        return 30; // Durée par défaut si aucune donnée disponible
    }

    // Trier par similarité décroissante
    std::sort(similarities.begin(), similarities.end(),
              [](const QPair<double, int>& a, const QPair<double, int>& b) {
                  return a.first > b.first;
              });

    // Prendre la moyenne pondérée des 3 projets les plus similaires
    double weightedSum = 0.0;
    double weightSum = 0.0;
    int count = qMin(3, similarities.size());

    for (int i = 0; i < count; ++i) {
        weightedSum += similarities[i].first * similarities[i].second;
        weightSum += similarities[i].first;
    }

    return static_cast<int>(weightedSum / weightSum);
}

int MLPredictor::predictDuration(const QString& description, const QString& status) {
    QVector<double> features = extractFeatures(description, status);
    int predictedDuration = predictBasedOnSimilarProjects(features, status);

    // Ajuster la prédiction en fonction du statut
    if (status == "SUSPENDU") {
        predictedDuration = static_cast<int>(predictedDuration * 1.5);
    } else if (status == "EN COURS") {
        predictedDuration = static_cast<int>(predictedDuration * 1.2);
    }

    qDebug() << "Durée prédite:" << predictedDuration << "jours pour le statut:" << status;
    return predictedDuration;
}
