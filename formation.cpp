#include "formation.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>  // Ajouté pour le débogage
#include <QSqlError>  // Assure-toi que cette ligne est présente
#include <QDebug>
#include <QVector>
// Constructeurs
Formation::Formation() : id(0), dateDebut(""), dateFin(""), formateur(""), lieu(""), prix(0.0) {}

Formation::Formation(int id, string dateDebut, string dateFin, string formateur, string lieu, double prix) {
    this->id = id;
    this->dateDebut = dateDebut;
    this->dateFin = dateFin;
    this->formateur = formateur;
    this->lieu = lieu;
    this->prix = prix;
}

bool Formation::ajouter() {
    QSqlQuery query;
    // Correction du nom de la table et des colonnes
    query.prepare("INSERT INTO \"ABDALLAH\".\"FORMATION\" (ID_FORMATION, DATEDEBUT, DATEFIN, FORMATEUR, LIEU, PRIX) "
                  "VALUES (:id, :dateDebut, :dateFin, :formateur, :lieu, :prix)");

    query.bindValue(":id", id);  // Liaison de l'ID
    query.bindValue(":dateDebut", QString::fromStdString(dateDebut));
    query.bindValue(":dateFin", QString::fromStdString(dateFin));
    query.bindValue(":formateur", QString::fromStdString(formateur));
    query.bindValue(":lieu", QString::fromStdString(lieu));
    query.bindValue(":prix", prix);

    if (!query.exec()) {
        // Affiche des détails d'erreur si la requête échoue
        qDebug() << "Erreur lors de l'ajout : " << query.lastError().text();  // Affiche l'erreur complète
        return false;
    }

    return true;
}

QSqlQueryModel* Formation::afficherListe() {
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from formation");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("dateDebut"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("dateFin"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("formateur"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("lieu"));

    return model;
}

bool Formation::supprimer(int id) {
    (void)id; // Évite le warning "unused parameter"
    // ToDo
    return false; // Ajout d'un retour pour éviter l'erreur
}

bool Formation::modifier(int id) {
    (void)id; // Évite le warning "unused parameter"
    // ToDo
    return false; // Ajout d'un retour pour éviter l'erreur
}
