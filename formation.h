#ifndef FORMATION_H
#define FORMATION_H

#include <iostream>
#include <string>
#include <QSqlQuery>
#include <QSqlQueryModel>
using namespace std;

class Formation {
private:
    int id;
    string dateDebut;
    string dateFin;
    string formateur;
    string lieu;
    double prix;

public:
    // Constructeurs
    Formation();
    Formation(int id, string dateDebut, string dateFin, string formateur, string lieu, double prix);

    // Getters
    int getId() const;
    string getDateDebut() const;
    string getDateFin() const;
    string getFormateur() const;
    string getLieu() const;
    double getPrix() const;

    // Setters
    void setId(int id);
    void setDateDebut(const string &dateDebut);
    void setDateFin(const string &dateFin);
    void setFormateur(const string &formateur);
    void setLieu(const string &lieu);
    void setPrix(double prix);

    // Méthodes CRUD
    bool ajouter();
    bool modifier(int id);
    bool supprimer(int id);
    QSqlQueryModel* afficherListe();
};

#endif // FORMATION_H
