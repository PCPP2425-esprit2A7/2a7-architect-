#include "supp.h"
#include "ui_supp.h"
#include "clientmanager.h"
#include <QMessageBox>

supp::supp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::supp)
{
    ui->setupUi(this);

    // Optionnel : Personnaliser la fenêtre
    this->setWindowTitle("Suppression");

    ui->lineEdit_idsupp->setPlaceholderText("ID...");

}

supp::~supp()
{
    delete ui;
}


void supp::on_buttonBox_accepted()
{
    // Récupérer l'ID du champ de saisie
    QString idStr = ui->lineEdit_idsupp->text();

    // Vérifier si le champ est vide
    if (idStr.isEmpty()) {
        QMessageBox::warning(this, "Champs vide", "Veuillez entrer un ID à supprimer.");
        return;
    }

    // Vérifier si l'ID est un entier valide
    bool conversionOk;
    int id_client = idStr.toInt(&conversionOk);
    if (!conversionOk) {
        QMessageBox::warning(this, "ID invalide", "L'ID doit être un nombre entier.");
        return;
    }

    // Vérifier si l'ID existe dans la base de données
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Client WHERE id_client = :id_client");
    query.bindValue(":id_client", id_client);
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la vérification de l'ID.");
        return;
    }
    query.next();
    if (query.value(0).toInt() == 0) {
        QMessageBox::warning(this, "ID inexistant", "L'ID du client que vous essayez de supprimer n'existe pas.");
        return;
    }

    // Confirmation avant suppression
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Êtes-vous sûr de vouloir supprimer ce client ?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return; // Annuler la suppression
    }

    // Suppression du client
    ClientManager client;
    bool test = client.supprimer(id_client);

    if (test) {
        QMessageBox::information(this, "Succès", "Suppression effectuée avec succès !");
        emit suppressionEffectuee(); // Émettre le signal
        accept(); // Ferme la fenêtre en validant l'action
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression !");
    }
}



void supp::on_buttonBox_rejected()
{
     reject(); // Ferme la fenêtre sans effectuer d’action
}

