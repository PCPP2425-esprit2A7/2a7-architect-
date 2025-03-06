#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "formation.h"  // Assure-toi que le fichier d'en-tête Formation est inclus
#include <supp.h>
#include <modifier.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(fr.afficherListe());
    // Set placeholder text for the search field
    ui->lineEdit_4->setPlaceholderText("Rechercher...");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAjouter_clicked() {
    // Récupérer les valeurs saisies dans les QLineEdits
    int id = ui->lineEdit_id->text().toInt();  // Assure-toi que lineEdit_id existe dans ton UI
    QString dateDebut = ui->lineEdit_dateDebut->text();  // Assure-toi que lineEdit_dateDebut existe
    QString dateFin = ui->lineEdit_dateFin->text();  // Assure-toi que lineEdit_dateFin existe
    QString formateur = ui->lineEdit_formateur->text();  // Assure-toi que lineEdit_formateur existe
    QString lieu = ui->lineEdit_lieu->text();  // Assure-toi que lineEdit_lieu existe
    double prix = ui->lineEdit_prix->text().toDouble();  // Assure-toi que lineEdit_prix existe

    // Création d'un objet Formation avec les données saisies
    Formation f(id, dateDebut.toStdString(), dateFin.toStdString(),
                formateur.toStdString(), lieu.toStdString(), prix);

    // Appel de la méthode ajouter() pour insérer la formation dans la base de données
    bool test = f.ajouter();

    // Affichage d'un message de confirmation ou d'erreur en fonction du résultat
    if (test) {
        QMessageBox::information(this, "OK", "Ajout effectué");
    } else {
        QMessageBox::critical(this, "Erreur", "Ajout non effectué");
    }
}

void MainWindow::on_btnSupprimer_clicked()
{
    supp *suppWindow = new supp(); // Créer une instance de la fenêtre supp
    suppWindow->show();            // Afficher la nouvelle fenêtre
    this->close();                 // Fermer la fenêtre actuelle (MainWindow)
}

void MainWindow::on_btnAjouter_3_clicked()
{
    modifier *modifierWindow = new modifier(); // Créer une instance de la fenêtre supp
    modifierWindow->show();            // Afficher la nouvelle fenêtre
    this->close();                 // Fermer la fenêtre actuelle (MainWindow)
}

