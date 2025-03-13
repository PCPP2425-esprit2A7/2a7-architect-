#include "modifc.h"
#include "ui_modifc.h"
#include "clientmanager.h"
#include <QMessageBox>
#include <QRegularExpression>

modifc::modifc(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::modifc)
{
    ui->setupUi(this);

    // Optionnel : Personnaliser la fenêtre
    this->setWindowTitle("modifier");
}

modifc::~modifc()
{
    delete ui;
}

void modifc::on_buttonBox_accepted()
{
    // Récupération des informations saisies
    int id_client = ui->IDC->text().toInt();
    QString nom = ui->nomClient_2->text();
    QString prenom = ui->prenomClient_2->text();
    QString email = ui->emailClient_2->text();
    QString num_tlf = ui->numClient_2->text();
    int nb_projet = ui->nbcProjet_2->value();

    // Vérifier si les champs obligatoires sont remplis
    if (nom.isEmpty() || prenom.isEmpty() || email.isEmpty() || num_tlf.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs.");
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
        QMessageBox::warning(this, "ID inexistant", "L'ID du client n'existe pas.");
        return;
    }

    // Vérifier que l'email est valide
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Email invalide", "Veuillez entrer une adresse email valide.");
        return;
    }

    // Vérifier que le numéro de téléphone contient uniquement des chiffres et a une longueur correcte (ex: 8-10 chiffres)
    QRegularExpression phoneRegex(R"(^\d{8,10}$)");
    if (!phoneRegex.match(num_tlf).hasMatch()) {
        QMessageBox::warning(this, "Numéro invalide", "Le numéro de téléphone doit contenir entre 8 et 10 chiffres.");
        return;
    }

    // Vérifier que le nombre de projets n'est pas négatif
    if (nb_projet < 0) {
        QMessageBox::warning(this, "Nombre de projets invalide", "Le nombre de projets ne peut pas être négatif.");
        return;
    }

    // Création de l'objet client avec les nouvelles valeurs
    ClientManager CL(id_client, nom, prenom, email, num_tlf, nb_projet);

    // Appel de la fonction modifier()
    bool test = CL.modifier();

    if (test) {
        QMessageBox::information(this, "Succès", "Modification effectuée avec succès !");
        emit modificationEffectuee(); // Émettre le signal
        accept(); // Ferme la fenêtre en validant l'action
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du client.");
    }
}



void modifc::on_buttonBox_rejected()
{
    reject(); // Ferme la fenêtre sans effectuer d’action
}

