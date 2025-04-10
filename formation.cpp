#include "formation.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>  // Pour le débogage
#include <QSqlError>  // Pour gérer les erreurs SQL

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

// Méthode pour ajouter une formation
bool Formation::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO \"ABDALLAH\".\"FORMATION\" (ID_FORMATION, DATEDEBUT, DATEFIN, FORMATEUR, LIEU, PRIX) "
                  "VALUES (:id, :dateDebut, :dateFin, :formateur, :lieu, :prix)");

    query.bindValue(":id", id);
    query.bindValue(":dateDebut", QString::fromStdString(dateDebut));
    query.bindValue(":dateFin", QString::fromStdString(dateFin));
    query.bindValue(":formateur", QString::fromStdString(formateur));
    query.bindValue(":lieu", QString::fromStdString(lieu));
    query.bindValue(":prix", prix);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout : " << query.lastError().text();
        return false;
    }

    return true;
}

// Méthode pour afficher la liste des formations
QSqlQueryModel* Formation::afficherListe() {
    QSqlQueryModel *model = new QSqlQueryModel();

    // Requête SQL pour sélectionner toutes les formations
    model->setQuery("SELECT ID_FORMATION, DATEDEBUT, DATEFIN, FORMATEUR, LIEU, PRIX FROM \"ABDALLAH\".\"FORMATION\"");

    // Définir les en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Fin"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Formateur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix"));

    return model;
}

bool Formation::supprimer(int id) {
    qDebug() << "Tentative de suppression pour ID :" << id;

    if (!existe(id)) {
        qDebug() << "Échec : ID inexistant dans la base de données.";
        return false;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM \"ABDALLAH\".\"FORMATION\" WHERE ID_FORMATION = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "Suppression réussie pour ID :" << id;
        return true;
    } else {
        qDebug() << "Erreur SQL suppression() :" << query.lastError().text();
        return false;
    }
}



bool Formation::existe(int id) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM \"ABDALLAH\".\"FORMATION\" WHERE ID_FORMATION = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        qDebug() << "Vérification de l'existence : ID =" << id << ", Trouvé =" << count;
        return count > 0;  // Si count > 0, l'ID existe
    } else {
        qDebug() << "Erreur SQL dans existe() :" << query.lastError().text();
    }

    return false;
}





// Méthode pour modifier une formation par son ID
bool Formation::modifier() {
    QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("UPDATE \"ABDALLAH\".\"FORMATION\" SET "
                  "DATEDEBUT = :dateDebut, "
                  "DATEFIN = :dateFin, "
                  "FORMATEUR = :formateur, "
                  "LIEU = :lieu, "
                  "PRIX = :prix "
                  "WHERE ID_FORMATION = :id");

    query.bindValue(":id", res);
    query.bindValue(":dateDebut", QString::fromStdString(dateDebut));
    query.bindValue(":dateFin", QString::fromStdString(dateFin));
    query.bindValue(":formateur", QString::fromStdString(formateur));
    query.bindValue(":lieu", QString::fromStdString(lieu));
    query.bindValue(":prix", prix);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification : " << query.lastError().text();
        return false;
    }

    // Vérifier combien de lignes ont été modifiées
    qDebug() << "Nombre de lignes modifiées :" << query.numRowsAffected();

    if (query.numRowsAffected() == 0) {
        qDebug() << "Aucune ligne modifiée. L'ID spécifié est peut-être introuvable.";
        return false;
    }

    return true;
}

// Méthode pour trier les formations par prix
QSqlQueryModel* Formation::trierParPrix() {
    QSqlQueryModel *model = new QSqlQueryModel();

    // Requête SQL pour trier les formations par prix

    model->setQuery("SELECT ID_FORMATION, DATEDEBUT, DATEFIN, FORMATEUR, LIEU, PRIX FROM \"ABDALLAH\".\"FORMATION\" ORDER BY PRIX ASC");

    // Définir les en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Fin"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Formateur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix"));

    return model;
}

// Méthode pour trier les formations par date
QSqlQueryModel* Formation::trierParDate() {
    QSqlQueryModel *model = new QSqlQueryModel();

    // Requête SQL pour trier les formations par date
    model->setQuery("SELECT ID_FORMATION, DATEDEBUT, DATEFIN, FORMATEUR, LIEU, PRIX FROM \"ABDALLAH\".\"FORMATION\" ORDER BY DATEDEBUT ASC");

    // Définir les en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Fin"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Formateur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix"));

    return model;
}
QSqlQueryModel* Formation::rechercherParLieu(const QString& lieu) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_FORMATION, TO_CHAR(DATEDEBUT, 'DD/MM/YYYY'), TO_CHAR(DATEFIN, 'DD/MM/YYYY'), FORMATEUR, LIEU, PRIX FROM FORMATION WHERE LIEU LIKE :lieu");
    query.bindValue(":lieu", "%" + lieu + "%");
    query.exec();
    model->setQuery(query);
    return model;
}
