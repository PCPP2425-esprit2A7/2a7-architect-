#include "gestion_projet.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>
#include <QString>

GestionProjet::GestionProjet() {
    id_projet = 0;
    nom_projet = "";
    description = "";
    statut = "";
    date_debut = "";
    date_fin = "";
}

GestionProjet::GestionProjet(int id, QString nom, QString desc, QString stat, QString debut, QString fin) {
    id_projet = id;
    nom_projet = nom;
    description = desc;
    statut = stat;
    date_debut = debut;
    date_fin = fin;
}

bool GestionProjet::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO GESTION_PROJET (ID_PROJET, NOM_PROJET, DESCRIPTION, STATUT, DATE_DEBUT, DATE_FIN) "
                  "VALUES (:id, :nom, :desc, :statut, TO_DATE(:date_debut, 'DD/MM/YYYY'), TO_DATE(:date_fin, 'DD/MM/YYYY'))");

    query.bindValue(":id", id_projet);
    query.bindValue(":nom", nom_projet);
    query.bindValue(":desc", description);
    query.bindValue(":statut", statut);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":date_fin", date_fin);

    return query.exec();
}

bool GestionProjet::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM GESTION_PROJET WHERE ID_PROJET = :id");
    query.bindValue(":id", id);
    return query.exec();
}

QSqlQueryModel *GestionProjet::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, STATUT, TO_CHAR(DATE_DEBUT, 'DD/MM/YYYY'), TO_CHAR(DATE_FIN, 'DD/MM/YYYY') FROM GESTION_PROJET");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Fin"));
    return model;
}

bool GestionProjet::existe(int id) {
    QSqlQuery query;
    query.prepare("SELECT ID_PROJET FROM GESTION_PROJET WHERE ID_PROJET = :id");
    query.bindValue(":id", id);
    query.exec();
    return query.next();
}

bool GestionProjet::modifier(int id, QString nom, QString desc, QString statut, QString date_debut, QString date_fin) {
    QSqlQuery query;
    query.prepare("UPDATE GESTION_PROJET SET NOM_PROJET = :nom, DESCRIPTION = :desc, STATUT = :statut, DATE_DEBUT = TO_DATE(:date_debut, 'DD/MM/YYYY'), DATE_FIN = TO_DATE(:date_fin, 'DD/MM/YYYY') WHERE ID_PROJET = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":desc", desc);
    query.bindValue(":statut", statut);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":date_fin", date_fin);

    return query.exec();
}
