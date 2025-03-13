#include "connexion.h"

Connexion::Connexion() {}

bool Connexion::ouvrirConnexion() {
    // Afficher les pilotes disponibles pour voir si "QOCI" est dans la liste
    qDebug() << "Pilotes disponibles :" << QSqlDatabase::drivers();

    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("sousso"); // DSN configuré dans ODBC
    db.setUserName("abdallah"); // Utilisateur Oracle
    db.setPassword("1925"); // Mot de passe Oracle

    if (db.open()) test=true;
    return test;
}

void Connexion::fermerConnexion() {
    db.close();  // Ferme la connexion ouverte
    QSqlDatabase::removeDatabase("QODBC");  // Supprime la base de données (et libère les ressources)
}
