#include "modifier.h"
#include "ui_modifier.h"
#include "gestion_projet.h"
#include <QMessageBox>
#include <QFormLayout>
#include <QDate>
#include <QFile>

modifier::modifier(QWidget *parent, int id, QString nom, QString desc, QString statut, QString date_debut, QString date_fin)
    : QDialog(parent)
    , ui(new Ui::modifier)
    , projectId(id)
{
    ui->setupUi(this);

    // Chargement du style
    QFile styleFile("styles/form_style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(styleFile.readAll());
        setStyleSheet(styleSheet);
        styleFile.close();
    }

    ui->lineEdit_nom->setText(nom);
    ui->textEdit_description->setPlainText(desc);
    ui->comboBox_statut->setCurrentText(statut);
    ui->dateEdit_debut->setDate(QDate::fromString(date_debut, "dd/MM/yyyy"));
    ui->dateEdit_fin->setDate(QDate::fromString(date_fin, "dd/MM/yyyy"));
}

modifier::~modifier()
{
    delete ui;
}

QString modifier::getNom() {
    return ui->lineEdit_nom->text();
}

QString modifier::getDescription() {
    return ui->textEdit_description->toPlainText();
}

QString modifier::getStatut() {
    return ui->comboBox_statut->currentText();
}

QString modifier::getDateDebut() {
    return ui->dateEdit_debut->date().toString("dd/MM/yyyy");
}

QString modifier::getDateFin() {
    return ui->dateEdit_fin->date().toString("dd/MM/yyyy");
}

void modifier::on_pushButton_clicked()
{
    QString nom = getNom();
    QString desc = getDescription();
    QString statut = getStatut();
    QString date_debut = getDateDebut();
    QString date_fin = getDateFin();

    if (nom.isEmpty() || desc.isEmpty() || statut.isEmpty() || date_debut.isEmpty() || date_fin.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Tous les champs doivent être remplis.");
        return;
    }

    QDate debut = QDate::fromString(date_debut, "dd/MM/yyyy");
    QDate fin = QDate::fromString(date_fin, "dd/MM/yyyy");
    QDate aujourdhui = QDate::currentDate();

    if (!debut.isValid()) {
        QMessageBox::warning(this, "Date invalide", "Le format de la date de début doit être JJ/MM/AAAA.");
        return;
    }

    if (!fin.isValid()) {
        QMessageBox::warning(this, "Date invalide", "Le format de la date de fin doit être JJ/MM/AAAA.");
        return;
    }

    if (debut < aujourdhui) {
        QMessageBox::warning(this, "Date de début invalide", "La date de début doit être aujourd'hui ou une date future.");
        return;
    }

    if (fin <= debut) {
        QMessageBox::warning(this, "Date de fin invalide", "La date de fin doit être supérieure à la date de début.");
        return;
    }

    if (debut.daysTo(fin) < 180) {
        QMessageBox::warning(this, "Erreur", "Il faut un minimum de 6 mois.");
        return;
    }

    // Call the modifier() method to update the project in the database
    GestionProjet projet;
    if (projet.modifier(projectId, nom, desc, statut, date_debut, date_fin)) {
        emit projetModifie();
        QMessageBox::information(this, "Succès", "Projet modifié avec succès.");
        this->close();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du projet.");
    }
}
