#include "tache.h"

// Constructor
Tache::Tache(int id, const std::string &dateDebut, const std::string &dateFin,
             const std::string &mission, const std::string &statut,
             const std::string &description)
    : id(id), dateDebut(dateDebut), dateFin(dateFin),
    mission(mission), statut(statut), description(description) {}

// Getters
int Tache::getId() const { return id; }
std::string Tache::getDateDebut() const { return dateDebut; }
std::string Tache::getDateFin() const { return dateFin; }
std::string Tache::getMission() const { return mission; }
std::string Tache::getStatut() const { return statut; }
std::string Tache::getDescription() const { return description; }

// Setters
void Tache::setId(int id) { this->id = id; }
void Tache::setDateDebut(const std::string &dateDebut) { this->dateDebut = dateDebut; }
void Tache::setDateFin(const std::string &dateFin) { this->dateFin = dateFin; }
void Tache::setMission(const std::string &mission) { this->mission = mission; }
void Tache::setStatut(const std::string &statut) { this->statut = statut; }
void Tache::setDescription(const std::string &description) { this->description = description; }
