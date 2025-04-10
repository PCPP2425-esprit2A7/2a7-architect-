#ifndef FORMATION_H
#define FORMATION_H

#include <iostream>
#include <string>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>
#include <QFont>
#include <QTableView>
using namespace std;

class Formation {
private:
    int id;                // Identifiant de la formation
    string dateDebut;      // Date de début de la formation
    string dateFin;        // Date de fin de la formation
    string formateur;      // Nom du formateur
    string lieu;           // Lieu de la formation
    double prix;           // Prix de la formation

public:
    // Constructeurs
    Formation();  // Constructeur par défaut
    Formation(int id, string dateDebut, string dateFin, string formateur, string lieu, double prix);  // Constructeur paramétré

    // Getters
    int getId() const;              // Récupérer l'ID
    string getDateDebut() const;    // Récupérer la date de début
    string getDateFin() const;      // Récupérer la date de fin
    string getFormateur() const;    // Récupérer le formateur
    string getLieu() const;         // Récupérer le lieu
    double getPrix() const;         // Récupérer le prix

    // Setters
    void setId(int id);                      // Définir l'ID
    void setDateDebut(const string &dateDebut);  // Définir la date de début
    void setDateFin(const string &dateFin);      // Définir la date de fin
    void setFormateur(const string &formateur);  // Définir le formateur
    void setLieu(const string &lieu);            // Définir le lieu
    void setPrix(double prix);                   // Définir le prix

    // Méthodes CRUD
    bool existe(int id);
    bool ajouter();                  // Ajouter une formation à la base de données
    bool modifier();           // Modifier une formation existante par son ID
    bool supprimer(int id);          // Supprimer une formation par son ID
    QSqlQueryModel* afficherListe(); // Afficher la liste des formations dans un modèle de requête SQL
    void exporterPDF(QTableView *tableView);
    QSqlQueryModel* trierParPrix();  // Trier les formations par prix
    QSqlQueryModel* trierParDate();  // Trier les formations par date
    QSqlQueryModel* rechercherParLieu(const QString& lieu);
};

#endif // FORMATION_H
