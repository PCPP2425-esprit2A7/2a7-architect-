#ifndef TACHE_H
#define TACHE_H

#include <string>

class Tache {
public:
    // Constructeur
    Tache(int id, const std::string &dateDebut, const std::string &dateFin,
          const std::string &mission, const std::string &statut,
          const std::string &description);

    // Méthode pour ajouter une tâche
    bool ajouter();

    // Getters
    int getId() const;
    std::string getDateDebut() const;
    std::string getDateFin() const;
    std::string getMission() const;
    std::string getStatut() const;
    std::string getDescription() const;

    // Setters
    void setId(int id);
    void setDateDebut(const std::string &dateDebut);
    void setDateFin(const std::string &dateFin);
    void setMission(const std::string &mission);
    void setStatut(const std::string &statut);
    void setDescription(const std::string &description);

private:
    int id; // Identifiant de la tâche
    std::string dateDebut; // Date de début
    std::string dateFin; // Date de fin
    std::string mission; // Mission
    std::string statut; // Statut de la tâche
    std::string description; // Description de la tâche
};

#endif // TACHE_H
