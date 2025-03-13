#include "clientmanager.h"
#include <QDebug>
#include <QString>
#include <QPdfWriter>
#include <QPainter>
#include <QFont>



ClientManager::ClientManager(int id_client,QString nom,QString prenom,QString email,QString num_tlf,int nb_projet)
{
    this->id_client=id_client;
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;
    this->num_tlf=num_tlf;
    this->nb_projet=nb_projet;

}

bool ClientManager::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id_client);

    query.prepare("INSERT INTO Client (id_client, nom, prenom, email, num_tlf, nb_projet) "
                  "VALUES (:id_client, :nom, :prenom, :email, :num_tlf, :nb_projet)");

    query.bindValue(":id_client", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":num_tlf", num_tlf);
    query.bindValue(":nb_projet", nb_projet);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de l'ajout :" << query.lastError().text();
        return false;
    }

    return true;
}




//suppression

bool ClientManager::supprimer(int id_client)
{
    QSqlQuery query;
    QString res=QString::number(id_client);

    query.prepare("Delete from Client where Id_client= :id_client");
    query.bindValue(":id_client",res);
    return query.exec();

}

QSqlQueryModel * ClientManager::afficher(QString ordre) {
    QSqlQueryModel * model = new QSqlQueryModel();

    QString query = "SELECT * FROM Client ORDER BY nb_projet " + ordre;
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("num_tlf"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nb_projet"));

    return model;
}



bool ClientManager::modifier()
{
    QSqlQuery query;
    QString res = QString::number(id_client);

    query.prepare("UPDATE Client SET nom=:nom, prenom=:prenom, email=:email, num_tlf=:num_tlf, nb_projet=:nb_projet WHERE id_client=:id_client");

    query.bindValue(":id_client", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":num_tlf", num_tlf);
    query.bindValue(":nb_projet", nb_projet);

    return query.exec();
}


//tri
QSqlQueryModel * ClientManager::trierParNbProjet(bool ascendant) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QString query = "SELECT * FROM client ORDER BY nb_projet " + QString(ascendant ? "ASC" : "DESC");
    model->setQuery(query);
    return model;
}


QSqlQueryModel * ClientManager::rechercherParPrenom(const QString &prenom) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Préparer la requête SQL pour rechercher par prénom
    query.prepare("SELECT * FROM Client WHERE prenom LIKE :prenom ORDER BY nb_projet ASC");
    query.bindValue(":prenom", "%" + prenom + "%");

    if (query.exec()) {
        model->setQuery(query);
    } else {
        // Gérer l'erreur de la requête
        qDebug() << "Erreur lors de la recherche par prénom:" << query.lastError().text();
    }

    // Définir les en-têtes de colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("num_tlf"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nb_projet"));

    return model;
}









