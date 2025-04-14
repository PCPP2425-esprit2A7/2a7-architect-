#ifndef GESTION_PROJET_H
#define GESTION_PROJET_H

#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDate>
#include <QDebug>

class GestionProjet {
private:
    int id_projet;
    QString nom_projet;
    QString description;
    QString statut;
    QString date_debut;
    QString date_fin;

public:
    GestionProjet(int id, QString nom, QString desc, QString stat, QString debut, QString fin);
    GestionProjet();
    bool ajouter();
    bool supprimer(int id);
    bool existe(int id);
    bool modifier(int id, QString nom, QString desc, QString statut, QString date_debut, QString date_fin);
    QSqlQueryModel* afficher();
};

#endif // GESTION_PROJET_H
