#ifndef ML_PREDICTOR_H
#define ML_PREDICTOR_H

#include <QString>
#include <QMap>
#include <QVector>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class MLPredictor {
public:
    MLPredictor();
    bool trainModel();
    int predictDuration(const QString& description, const QString& status);

private:
    struct ProjectData {
        int duration;
        QString status;
        QString description;
        QVector<double> features;
    };

    QVector<ProjectData> trainingData;
    QMap<QString, double> wordWeights;
    QMap<QString, QPair<int, int>> statusStats; // moyenne et nombre pour chaque statut

    QVector<double> extractFeatures(const QString& description, const QString& status);
    void calculateWordWeights();
    double calculateSimilarity(const QVector<double>& features1, const QVector<double>& features2);
    int predictBasedOnSimilarProjects(const QVector<double>& features, const QString& status);
    void analyzeHistoricalData();
};

#endif // ML_PREDICTOR_H
