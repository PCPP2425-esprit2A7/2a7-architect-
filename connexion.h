#ifndef CONNEXION_H
#define CONNEXION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

// Connexion.h
class Connexion {
public:
    Connexion();
    bool ouvrirConnexion();
    void fermerConnexion();
private:
    QSqlDatabase db;  // Déclarer ici pour l'utiliser dans les deux méthodes
};


#endif // CONNEXION_H
