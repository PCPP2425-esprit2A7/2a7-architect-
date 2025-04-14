#ifndef ML_PREDICTOR_H
#define ML_PREDICTOR_H

#include <QString>
#include <QDate>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVector>
#include <QMap>
#include <QSet>

class MLPredictor {
public:
    MLPredictor();
    
    // Entraîne le modèle avec les données historiques
    bool trainModel();
    
    // Prédit la durée d'un nouveau projet
    int predictDuration(const QString& description, const QString& statut);
    
private:
    // Convertit le texte en features numériques
    QVector<double> extractFeatures(const QString& description, const QString& statut);
    
    // Nettoie et prépare le texte
    QString preprocessText(const QString& text);
    
    // Calcule la similarité entre deux textes
    double calculateSimilarity(const QString& text1, const QString& text2);
    
    // Données d'entraînement
    QVector<QVector<double>> trainingFeatures;
    QVector<int> trainingDurations;
    
    // Poids du modèle
    QVector<double> weights;
    double bias;
    
    // Vocabulaire pour les features
    QSet<QString> vocabulary;
    
    // Statistiques par statut
    QMap<QString, double> statusAvgDuration;
};

#endif // ML_PREDICTOR_H
