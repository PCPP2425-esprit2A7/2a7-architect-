#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>
#include <QInputDialog>  // <-- Add this line for QInputDialog

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Debugging: Check available database drivers
    qDebug() << "Available drivers:" << QSqlDatabase::drivers();

    // Connect buttons to slots
    connect(ui->btnAjouter, &QPushButton::clicked, this, &MainWindow::btnAjouterClicked);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &MainWindow::btnSupprimerClicked);
    connect(ui->btnModifier, &QPushButton::clicked, this, &MainWindow::btnModifierClicked);

    // Database Connection
    Connection conn;
    if (!conn.createconnect()) {
        QMessageBox::critical(this, "ERREUR", "CONNEXION À LA BASE DE DONNÉES ÉCHOUÉE !");
    } else {
        qDebug() << "✅ Database connection established successfully.";
    }

    afficherTaches(); // Load tasks on startup
}

// Function to display tasks
void MainWindow::afficherTaches() {
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("TACHES");

    if (!model->select()) {
        qDebug() << "❌ Error loading table: " << model->lastError().text();
        return;
    }

    model->setHeaderData(0, Qt::Horizontal, "ID_TACHE");
    model->setHeaderData(1, Qt::Horizontal, "DATEDEB");
    model->setHeaderData(2, Qt::Horizontal, "DATEFIN");
    model->setHeaderData(3, Qt::Horizontal, "MISSION");
    model->setHeaderData(4, Qt::Horizontal, "STATUT");
    model->setHeaderData(5, Qt::Horizontal, "DESCRIPTION");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

// Method to add a task
bool MainWindow::ajouter(const QString &ID_TACHE, const QString &DATEDEB, const QString &DATEFIN,
                         const QString &MISSION, const QString &STATUT, const QString &DESCRIPTION)
{
    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection"); // Ensure correct connection
    if (!db.isOpen()) {
        QMessageBox::critical(this, "ERREUR", "LA CONNEXION À LA BASE DE DONNÉES EST FERMÉE !");
        return false;
    }

    bool ok;
    int ID = ID_TACHE.toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "ERREUR", "L'ID DE LA TÂCHE DOIT ÊTRE UN ENTIER VALIDE.");
        return false;
    }

    if (DESCRIPTION.length() > 20) {
        QMessageBox::critical(this, "ERREUR", "LA DESCRIPTION NE DOIT PAS DÉPASSER 20 CARACTÈRES !");
        return false;
    }

    // Check if ID_TACHE already exists
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM TACHES WHERE ID_TACHE = :ID_TACHE");
    checkQuery.bindValue(":ID_TACHE", ID);
    if (!checkQuery.exec()) {
        qDebug() << "Check query error:" << checkQuery.lastError().text();
        return false;
    }
    checkQuery.next();
    if (checkQuery.value(0).toInt() > 0) {
        QMessageBox::critical(this, "ERREUR", "Cet ID_TACHE existe déjà !");
        return false;
    }

    // Insert new task
    QSqlQuery query;
    query.prepare("INSERT INTO TACHES (ID_TACHE, DATEDEB, DATEFIN, MISSION, STATUT, DESCRIPTION) "
                  "VALUES (:ID_TACHE, :DATEDEB, :DATEFIN, :MISSION, :STATUT, :DESCRIPTION)");

    query.bindValue(":ID_TACHE", ID);
    query.bindValue(":DATEDEB", QDate::fromString(DATEDEB, "yyyy-MM-dd"));
    query.bindValue(":DATEFIN", QDate::fromString(DATEFIN, "yyyy-MM-dd"));
    query.bindValue(":MISSION", MISSION);
    query.bindValue(":STATUT", STATUT);
    query.bindValue(":DESCRIPTION", DESCRIPTION);

    if (!query.exec()) {
        qDebug() << "ERREUR SQL : " << query.lastError().text();
        QMessageBox::critical(this, "ERREUR D'INSERTION", "ERREUR SQL : " + query.lastError().text());
        return false;
    }

    afficherTaches(); // Refresh task list
    return true;
}

// Slot for adding a task
void MainWindow::btnAjouterClicked() {
    QString ID_TACHE = ui->LINE_EDIT_ID_TACHE->text();
    QString DATEDEB = ui->DATE_EDIT_DEBUT->date().toString("yyyy-MM-dd");
    QString DATEFIN = ui->DATE_EDIT_FIN->date().toString("yyyy-MM-dd");
    QString MISSION = ui->LINE_EDIT_MISSION->text();
    QString STATUT = ui->COMBO_BOX_STATUT->currentText();
    QString DESCRIPTION = ui->EDIT_DESCRIPTION->toPlainText();

    if (ID_TACHE.isEmpty() || MISSION.isEmpty()) {
        QMessageBox::warning(this, "CHAMP(S) MANQUANT(S)", "VEUILLEZ REMPLIR TOUS LES CHAMPS OBLIGATOIRES.");
        return;
    }

    if (ajouter(ID_TACHE, DATEDEB, DATEFIN, MISSION, STATUT, DESCRIPTION)) {
        QMessageBox::information(this, "SUCCÈS", "LA TÂCHE A ÉTÉ AJOUTÉE AVEC SUCCÈS.");

        // Reset form
        ui->LINE_EDIT_ID_TACHE->clear();
        ui->DATE_EDIT_DEBUT->setDate(QDate::currentDate());
        ui->DATE_EDIT_FIN->setDate(QDate::currentDate());
        ui->LINE_EDIT_MISSION->clear();
        ui->COMBO_BOX_STATUT->setCurrentIndex(0);
        ui->EDIT_DESCRIPTION->clear();
    }
}

// Slot for deleting a task
void MainWindow::btnSupprimerClicked() {
    QString ID_TACHE = ui->suppline->text(); // Get ID from the "suppline" field for deletion

    if (ID_TACHE.isEmpty()) {
        QMessageBox::warning(this, "SUPPRESSION", "VEUILLEZ ENTRER UN ID DE TÂCHE !");
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM TACHES WHERE ID_TACHE = :ID_TACHE");
    query.bindValue(":ID_TACHE", ID_TACHE.toInt());

    if (query.exec()) {
        QMessageBox::information(this, "SUCCÈS", "TÂCHE SUPPRIMÉE AVEC SUCCÈS !");
        afficherTaches();
    } else {
        QMessageBox::critical(this, "ERREUR", "ÉCHEC DE LA SUPPRESSION : " + query.lastError().text());
    }
}

// Slot for modifying a task
#include <QInputDialog>

// Slot for modifying a task
void MainWindow::btnModifierClicked() {
    QString ID_TACHE = ui->modline->text();  // Get ID from the "modline" field for modification

    // Check if ID_TACHE is empty
    if (ID_TACHE.isEmpty()) {
        QMessageBox::warning(this, "MODIFICATION", "VEUILLEZ ENTRER UN ID DE TÂCHE !");
        return;
    }

    // Ensure ID_TACHE is a valid integer
    bool ok;
    int idTacheInt = ID_TACHE.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "MODIFICATION", "L'ID DE LA TÂCHE DOIT ÊTRE UN ENTIER VALIDE !");
        return;
    }

    // Ask user for confirmation to modify the task
    bool confirm = QMessageBox::question(this, "Confirmer la modification",
                                         "Êtes-vous sûr de vouloir modifier cette tâche ?",
                                         QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes;

    if (confirm) {
        // Prompt user for new values
        QString newMission = QInputDialog::getText(this, "Modifier la mission", "Nouvelle mission:", QLineEdit::Normal, ui->LINE_EDIT_MISSION->text());
        QString newStatut = QInputDialog::getItem(this, "Modifier le statut", "Nouveau statut:", {"En cours", "Terminé", "À faire"}, ui->COMBO_BOX_STATUT->currentIndex(), false);
        QString newDescription = QInputDialog::getText(this, "Modifier la description", "Nouvelle description:", QLineEdit::Normal, ui->EDIT_DESCRIPTION->toPlainText());
        QString newDateDeb = QInputDialog::getText(this, "Modifier la date de début", "Nouvelle date de début (dd/MM/yy):", QLineEdit::Normal, ui->DATE_EDIT_DEBUT->date().toString("dd/MM/yy"));
        QString newDateFin = QInputDialog::getText(this, "Modifier la date de fin", "Nouvelle date de fin (dd/MM/yy):", QLineEdit::Normal, ui->DATE_EDIT_FIN->date().toString("dd/MM/yy"));

        // If any of the new fields are empty, keep the old value
        if (newMission.isEmpty()) {
            newMission = ui->LINE_EDIT_MISSION->text();
        }
        if (newStatut.isEmpty()) {
            newStatut = ui->COMBO_BOX_STATUT->currentText();
        }
        if (newDescription.isEmpty()) {
            newDescription = ui->EDIT_DESCRIPTION->toPlainText();
        }
        if (newDateDeb.isEmpty()) {
            newDateDeb = ui->DATE_EDIT_DEBUT->date().toString("dd/MM/yy");
        }
        if (newDateFin.isEmpty()) {
            newDateFin = ui->DATE_EDIT_FIN->date().toString("dd/MM/yy");
        }

        // Prepare the UPDATE query
        QSqlQuery query;
        query.prepare("UPDATE TACHES SET DATEDEB = :DATEDEB, DATEFIN = :DATEFIN, MISSION = :MISSION, "
                      "STATUT = :STATUT, DESCRIPTION = :DESCRIPTION WHERE ID_TACHE = :ID_TACHE");

        // Bind the values
        query.bindValue(":ID_TACHE", idTacheInt);
        query.bindValue(":DATEDEB", newDateDeb);  // Date in dd/MM/yy format
        query.bindValue(":DATEFIN", newDateFin);  // Date in dd/MM/yy format
        query.bindValue(":MISSION", newMission);
        query.bindValue(":STATUT", newStatut);
        query.bindValue(":DESCRIPTION", newDescription);

        // Execute the query
        if (query.exec()) {
            QMessageBox::information(this, "SUCCÈS", "TÂCHE MODIFIÉE AVEC SUCCÈS !");
            afficherTaches();  // Refresh the task list
        } else {
            QMessageBox::critical(this, "ERREUR", "ÉCHEC DE LA MODIFICATION : " + query.lastError().text());
        }
    }
}




// Destructor
MainWindow::~MainWindow() {
    delete ui;
}
