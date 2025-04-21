#include "connexion.h"

Connexion::Connexion() {}

bool Connexion::ouvrirConnexion() {
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A"); // DSN configuré dans ODBC
    db.setUserName("Aziz"); // Utilisateur Oracle
    db.setPassword("1925"); // Mot de passe Oracle

    // Afficher les pilotes disponibles pour voir si "QOCI" est dans la liste
    qDebug() << "Pilotes disponibles :" << QSqlDatabase::drivers();

    if (db.open()) {
        qDebug() << "Connexion réussie à la base de données !";
        return true;
    } else {
        qDebug() << "Erreur de connexion :" << db.lastError().text();
        return false;
    }
}

void Connexion::fermerConnexion() {
    db.close();  // Ferme la connexion ouverte
    QSqlDatabase::removeDatabase("QODBC");  // Supprime la base de données (et libère les ressources)
}
