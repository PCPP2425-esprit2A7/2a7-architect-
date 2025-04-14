#include "ml_predictor.h"
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QtMath>
#include <QDateTime>
#include <QSqlError>
#include <QDebug>

MLPredictor::MLPredictor() : bias(6.0) {} // Durée de base de 6 mois

bool MLPredictor::trainModel() {
    // Réinitialiser les données d'entraînement
    trainingFeatures.clear();
    trainingDurations.clear();
    vocabulary.clear();
    statusAvgDuration.clear();
    
    // Récupérer les données d'entraînement
    QSqlQuery query;
    query.prepare("SELECT DESCRIPTION, STATUT, "
                 "ROUND(JULIANDAY(DATE_FIN) - JULIANDAY(DATE_DEBUT)) as DURATION_DAYS "
                 "FROM GESTION_PROJET WHERE DATE_FIN IS NOT NULL");
                 
    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération des données:" << query.lastError().text();
        return false;
    }
    
    // Collecter les données et construire le vocabulaire
    QMap<QString, int> statusCount;
    
    while (query.next()) {
        QString desc = preprocessText(query.value(0).toString());
        QString statut = query.value(1).toString();
        int durationDays = query.value(2).toInt();
        int durationMonths = qMax(1, durationDays / 30); // Convertir les jours en mois
        
        // Ajouter les mots au vocabulaire
        QStringList words = desc.split(' ', Qt::SkipEmptyParts);
        for (const QString& word : words) {
            vocabulary.insert(word);
        }
        
        // Collecter les statistiques par statut
        statusAvgDuration[statut] += durationMonths;
        statusCount[statut]++;
        
        // Stocker les features et la durée
        QVector<double> features = extractFeatures(desc, statut);
        if (!features.isEmpty()) {
            trainingFeatures.append(features);
            trainingDurations.append(durationMonths);
        }
    }
    
    // Si pas assez de données d'entraînement
    if (trainingFeatures.isEmpty()) {
        return false;
    }
    
    // Calculer les moyennes par statut
    for (auto it = statusAvgDuration.begin(); it != statusAvgDuration.end(); ++it) {
        it.value() /= statusCount[it.key()];
    }
    
    // Initialiser les poids du modèle
    int numFeatures = vocabulary.size() + 1; // +1 pour le statut
    weights.resize(numFeatures);
    for (int i = 0; i < numFeatures; ++i) {
        weights[i] = 1.0 / numFeatures;
    }
    
    // Entraîner le modèle avec une régression linéaire simple
    const int numEpochs = 100;
    const double learningRate = 0.01;
    
    for (int epoch = 0; epoch < numEpochs; ++epoch) {
        for (int i = 0; i < trainingFeatures.size(); ++i) {
            double prediction = 0;
            for (int j = 0; j < weights.size(); ++j) {
                prediction += weights[j] * trainingFeatures[i][j];
            }
            prediction += bias;
            
            double error = trainingDurations[i] - prediction;
            
            // Mettre à jour les poids
            for (int j = 0; j < weights.size(); ++j) {
                weights[j] += learningRate * error * trainingFeatures[i][j];
            }
            bias += learningRate * error;
        }
    }
    
    return true;
}

int MLPredictor::predictDuration(const QString& description, const QString& statut) {
    if (vocabulary.isEmpty()) {
        return 6; // Durée par défaut si pas de données d'entraînement
    }

    QVector<double> features = extractFeatures(description, statut);
    if (features.isEmpty()) {
        return 6; // Durée par défaut si impossible d'extraire les features
    }
    
    // Calculer la prédiction
    double prediction = bias;
    for (int i = 0; i < qMin(weights.size(), features.size()); ++i) {
        prediction += weights[i] * features[i];
    }
    
    // Ajuster avec la moyenne du statut
    if (statusAvgDuration.contains(statut)) {
        prediction = (prediction + statusAvgDuration[statut]) / 2;
    }
    
    // Assurer une durée minimale de 1 mois et maximale de 24 mois
    return qBound(1, qRound(prediction), 24);
}

QString MLPredictor::preprocessText(const QString& text) {
    QString processed = text.toLower();
    processed.replace(QRegularExpression("[^\\w\\s]"), " ");
    return processed.simplified();
}

QVector<double> MLPredictor::extractFeatures(const QString& description, const QString& statut) {
    if (vocabulary.isEmpty()) {
        return QVector<double>();
    }

    QString processedText = preprocessText(description);
    QStringList words = processedText.split(' ', Qt::SkipEmptyParts);
    
    // Créer le vecteur TF (Term Frequency)
    QVector<double> features(vocabulary.size() + 1, 0.0);
    
    // Calculer les features textuelles
    QVector<QString> vocabList = vocabulary.values();
    for (const QString& word : words) {
        int index = vocabList.indexOf(word);
        if (index >= 0) {
            features[index] += 1.0 / words.size(); // Normalisation par la longueur du texte
        }
    }
    
    // Ajouter la feature du statut
    features[features.size() - 1] = statusAvgDuration.value(statut, 6.0) / 12.0; // Normaliser par année
    
    return features;
}

double MLPredictor::calculateSimilarity(const QString& text1, const QString& text2) {
    // Convertir les textes en ensembles de mots
    QStringList list1 = preprocessText(text1).split(' ', Qt::SkipEmptyParts);
    QStringList list2 = preprocessText(text2).split(' ', Qt::SkipEmptyParts);
    
    QSet<QString> words1(list1.begin(), list1.end());
    QSet<QString> words2(list2.begin(), list2.end());
    
    // Calculer l'intersection et l'union
    QSet<QString> intersection = words1.intersect(words2);
    QSet<QString> union_set = words1.unite(words2);
    
    // Calculer le coefficient de Jaccard (taille de l'intersection / taille de l'union)
    return union_set.isEmpty() ? 0.0 : static_cast<double>(intersection.size()) / union_set.size();
}
