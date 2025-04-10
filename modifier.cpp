#include "modifier.h"
#include "ui_modifier.h"
#include <QMessageBox>
#include "formation.h"
#include <QRegularExpression> // Pour les expressions régulières
#include <QMessageBox>       // Pour les boîtes de dialogue
#include <QDate>             // Pour la manipulation des dates

modifier::modifier(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::modifier)
{
    ui->setupUi(this);

    // Optionnel : Personnaliser la fenêtre
    this->setWindowTitle("Modification");
}

modifier::~modifier()
{
    delete ui;
}

void modifier::on_buttonBox_accepted() {
    // Récupération des informations saisies
    QString idText = ui->lineEdit_id->text();
    QString dateDebutText = ui->lineEdit_dateDebut->text();
    QString dateFinText = ui->lineEdit_dateFin->text();
    QString formateur = ui->lineEdit_formateur->text();
    QString lieu = ui->lineEdit_lieu->text();
    QString prixText = ui->lineEdit_prix->text();

    // Contrôle de saisie pour l'ID (doit être un nombre entier positif)
    bool idOk;
    int id = idText.toInt(&idOk);
    if (!idOk || id <= 0) {
        QMessageBox::warning(this, "Erreur", "L'ID doit être un nombre entier positif.");
        return;
    }

    // Vérifier si l'ID existe dans la base de données
    Formation fr; // Utilisez le même objet pour la vérification et la modification
    if (!fr.existe(id)) {
        QMessageBox::warning(this, "Erreur", "L'ID spécifié n'existe pas dans la base de données.");
        return;
    }

    // Contrôle de saisie pour les dates (format JJ/MM/AAAA)
    QRegularExpression dateRegex("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/(19|20)\\d{2}$");
    if (!dateRegex.match(dateDebutText).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "La date de début doit être au format JJ/MM/AAAA et valide.");
        return;
    }
    if (!dateRegex.match(dateFinText).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "La date de fin doit être au format JJ/MM/AAAA et valide.");
        return;
    }

    // Convertir les dates en objets QDate
    QDate dateDebut = QDate::fromString(dateDebutText, "dd/MM/yyyy");
    QDate dateFin = QDate::fromString(dateFinText, "dd/MM/yyyy");

    // Vérifier que la date de début est antérieure à la date de fin
    if (dateDebut > dateFin) {
        QMessageBox::warning(this, "Erreur", "La date de début doit être antérieure à la date de fin.");
        return;
    }

    // Contrôle de saisie pour le formateur (uniquement des lettres et des espaces)
    QRegularExpression textRegex("^[A-Za-z\\s]+$");
    if (!textRegex.match(formateur).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le champ Formateur ne doit contenir que des lettres.");
        return;
    }

    // Contrôle de saisie pour le lieu (uniquement des lettres et des espaces)
    if (!textRegex.match(lieu).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le champ Lieu ne doit contenir que des lettres.");
        return;
    }

    // Contrôle de saisie pour le prix (doit être un nombre décimal positif)
    bool prixOk;
    double prix = prixText.toDouble(&prixOk);
    if (!prixOk || prix < 0) {
        QMessageBox::warning(this, "Erreur", "Le prix doit être un nombre décimal positif.");
        return;
    }

    // Mettre à jour l'objet Formation avec les nouvelles valeurs
    fr = Formation(id, dateDebutText.toStdString(), dateFinText.toStdString(),
                   formateur.toStdString(), lieu.toStdString(), prix);

    // Appel de la fonction modifier()
    bool test = fr.modifier(); // Utilisez l'objet fr pour appeler modifier()
    if (test) {
        QMessageBox::information(this, "Succès", "Modification effectuée avec succès !");
        emit modifierrr(); // Émettre le signal
        accept(); // Ferme la fenêtre en validant l'action
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification de la formation.");
    }
}



