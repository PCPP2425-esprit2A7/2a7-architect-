#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QVector>
#include <QMap>

class ClientManager {
    QString nom, prenom, email, num_tlf;
    int id_client, nb_projet;

public:
    // Constructor
    ClientManager(){}
    ClientManager(int,QString,QString,QString,QString,int);

    // Getters
    int getId_client(){return id_client;}
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getEmail(){return email;}
    QString getNum_tlf(){return num_tlf;}
    int getNb_projet(){return nb_projet;}

    // Setters
    void setId_client(int id){this->id_client=id;}
    void setNom(QString n){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setEmail(QString e){email=e;}
    void setNum_tlf(QString t){num_tlf=t;}
    void setNb_projet(int nbp){this->nb_projet=nbp;}

    // Database operations for Client
    bool ajouter();
    QSqlQueryModel * afficher(QString ordre = "ASC");
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * trierParNbProjet(bool ascendant);

    // Recherche par prénom
    QSqlQueryModel * rechercherParPrenom(const QString &prenom);


};

#endif // CLIENTMANAGER_H
