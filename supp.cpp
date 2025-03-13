#include "supp.h"
#include "ui_supp.h"
#include <QMessageBox>

// Constructeur modifié pour recevoir un pointeur vers MainWindow
supp::supp(MainWindow *mainWin, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supp),
    mainWindow(mainWin)  // Associer mainWindow
{
    ui->setupUi(this);

    // Connecter le bouton "Supprimer" à la slot on_btnSupprimer_clicked
    connect(ui->supprimer, &QPushButton::clicked, this, &supp::on_btnSupprimer_clicked);
}

// Destructeur
supp::~supp()
{
    delete ui;
}

// Slot pour la suppression d'une formation
void supp::on_btnSupprimer_clicked()
{
    if (ui->lineEditsupp->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    int id = ui->lineEditsupp->text().toInt();

    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "L'ID doit être un nombre positif.");
        return;
    }

    if (!fr.existe(id)) {
        QMessageBox::warning(this, "Erreur", "L'ID que vous avez saisi n'existe pas.");
        return;
    }

    bool test = fr.supprimer(id);
    qDebug() << "Résultat de la suppression :" << test;

    if (test) {
        QMessageBox::information(this, "Succès", "Formation supprimée avec succès.");
        emit suppressionEffectuee(); // Émettre le signal
        accept(); // Ferme la fenêtre en validant l'action
        // Fermer la fenêtre actuelle (supp) et revenir à MainWindow
        this->close();  // Fermer la fenêtre de suppression (supp)

        // Vérifier si MainWindow est déjà instancié, sinon on le crée
        if (mainWindow) {
            mainWindow->show();  // Afficher l'interface principale
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}
// Méthode pour le bouton "Annuler"
void supp::on_pushButtonanuul_clicked()
{
    // Fermer la fenêtre actuelle (supp)
    this->close();

    // Vérifier si MainWindow est déjà instancié, sinon on le crée
    if (mainWindow) {
        mainWindow->show();  // Afficher MainWindow
    }
}
