#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "modifydialog.h"

#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>

// Constructeur
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "Drivers disponibles:" << QSqlDatabase::drivers();
    connect(ui->comboBox_2, &QComboBox::currentTextChanged, this, &MainWindow::trierTaches);
    connect(ui->btnAjouter, &QPushButton::clicked, this, &MainWindow::btnAjouterClicked);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &MainWindow::btnSupprimerClicked);
    connect(ui->btnModifier, &QPushButton::clicked, this, &MainWindow::btnModifierClicked);

    Connection conn;
    if (!conn.createconnect()) {
        QMessageBox::critical(this, "ERREUR", "Connexion à la base de données échouée !");
    } else {
        qDebug() << "✅ Connexion réussie à la base de données.";
    }

    afficherTaches();
}

void MainWindow::trierTaches(const QString &critere)
{
    QSqlTableModel *model = qobject_cast<QSqlTableModel *>(ui->tableView->model());
    if (!model) return;

    int column = 0;  // par défaut ID_TACHE

    if (critere == "id") {
        column = 0;  // ID_TACHE
    } else if (critere == "datedeb") {
        column = 1;  // DATEDEB
    } else if (critere == "datefin") {
        column = 2;  // DATEFIN
    }

    model->setSort(column, Qt::AscendingOrder);
    model->select();  // Rafraîchir les données triées
}

// Affichage des tâches dans le tableau
void MainWindow::afficherTaches()
{
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("TACHES");
    model->setSort(0, Qt::AscendingOrder);  // Tri par ID_TACHE
    model->select();

    if (!model->select()) {
        qDebug() << "❌ Erreur lors du chargement de la table :" << model->lastError().text();
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

// Ajout d'une tâche
bool MainWindow::ajouter(const QString &ID_TACHE, const QString &DATEDEB, const QString &DATEFIN,
                         const QString &MISSION, const QString &STATUT, const QString &DESCRIPTION)
{
    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection");
    if (!db.isOpen()) {
        QMessageBox::critical(this, "ERREUR", "Connexion à la base de données fermée !");
        return false;
    }

    bool ok;
    int ID = ID_TACHE.toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "ERREUR", "L'ID de la tâche doit être un entier valide.");
        return false;
    }

    if (DESCRIPTION.length() > 20) {
        QMessageBox::critical(this, "ERREUR", "La description ne doit pas dépasser 20 caractères !");
        return false;
    }

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM TACHES WHERE ID_TACHE = :ID_TACHE");
    checkQuery.bindValue(":ID_TACHE", ID);
    if (!checkQuery.exec()) {
        qDebug() << "Erreur checkQuery :" << checkQuery.lastError().text();
        return false;
    }
    checkQuery.next();
    if (checkQuery.value(0).toInt() > 0) {
        QMessageBox::critical(this, "ERREUR", "Cet ID_TACHE existe déjà !");
        return false;
    }

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
        qDebug() << "ERREUR SQL :" << query.lastError().text();
        QMessageBox::critical(this, "ERREUR D'INSERTION", "Erreur SQL : " + query.lastError().text());
        return false;
    }

    afficherTaches();
    return true;
}

// Click sur bouton Ajouter
void MainWindow::btnAjouterClicked()
{
    QString ID_TACHE = ui->LINE_EDIT_ID_TACHE->text();
    QString DATEDEB = ui->DATE_EDIT_DEBUT->date().toString("yyyy-MM-dd");
    QString DATEFIN = ui->DATE_EDIT_FIN->date().toString("yyyy-MM-dd");
    QString MISSION = ui->LINE_EDIT_MISSION->text();
    QString STATUT = ui->COMBO_BOX_STATUT->currentText();
    QString DESCRIPTION = ui->EDIT_DESCRIPTION->toPlainText();

    if (ID_TACHE.isEmpty() || MISSION.isEmpty()) {
        QMessageBox::warning(this, "CHAMP(S) MANQUANT(S)", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    if (ajouter(ID_TACHE, DATEDEB, DATEFIN, MISSION, STATUT, DESCRIPTION)) {
        QMessageBox::information(this, "SUCCÈS", "Tâche ajoutée avec succès.");

        // Réinitialiser les champs
        ui->LINE_EDIT_ID_TACHE->clear();
        ui->DATE_EDIT_DEBUT->setDate(QDate::currentDate());
        ui->DATE_EDIT_FIN->setDate(QDate::currentDate());
        ui->LINE_EDIT_MISSION->clear();
        ui->COMBO_BOX_STATUT->setCurrentIndex(0);
        ui->EDIT_DESCRIPTION->clear();
    }
}

// Click sur bouton Supprimer
void MainWindow::btnSupprimerClicked() {
    QString idTache = ui->suppline->text().trimmed();

    if (idTache.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID de tâche.");
        return;
    }

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM TACHES WHERE ID_TACHE = :id");
    checkQuery.bindValue(":id", idTache);

    if (checkQuery.exec() && checkQuery.next()) {
        int count = checkQuery.value(0).toInt();
        if (count == 0) {
            QMessageBox::information(this, "Suppression", "ID non trouvé.");
            return;
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la vérification de l'ID.");
        return;
    }

    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM TACHES WHERE ID_TACHE = :id");
    deleteQuery.bindValue(":id", idTache);

    if (deleteQuery.exec()) {
        QMessageBox::information(this, "Succès", "Tâche supprimée avec succès.");
        afficherTaches(); // Refresh the task list
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression de la tâche.");
    }
}

// Click sur bouton Modifier
void MainWindow::btnModifierClicked()
{
    QString ID_TACHE = ui->modline->text();

    if (ID_TACHE.isEmpty()) {
        QMessageBox::warning(this, "MODIFICATION", "Veuillez entrer un ID de tâche !");
        return;
    }

    bool ok;
    int idTacheInt = ID_TACHE.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "MODIFICATION", "L'ID de tâche doit être un nombre valide !");
        return;
    }

    ModifyDialog dialog(this);
    dialog.setValues(ui->LINE_EDIT_MISSION->text(),
                     ui->COMBO_BOX_STATUT->currentText(),
                     ui->EDIT_DESCRIPTION->toPlainText(),
                     ui->DATE_EDIT_DEBUT->date(),
                     ui->DATE_EDIT_FIN->date());

    if (dialog.exec() == QDialog::Accepted) {

        // Récupération des nouvelles valeurs
        QDate dateDeb = dialog.dateDebut();
        QDate dateFin = dialog.dateFin();
        QString mission = dialog.mission();
        QString statut = dialog.statut();
        QString description = dialog.description();

        // --- Contrôle de saisie ---
        if (dateDeb == dateFin) {
            QMessageBox::warning(this, "Erreur", "La date de début ne peut pas être égale à la date de fin.");
            return;
        }

        if (mission.trimmed().isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Le champ mission ne peut pas être vide.");
            return;
        }

        if (description.trimmed().isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Le champ description ne peut pas être vide.");
            return;
        }

        QSqlQuery query;
        query.prepare("UPDATE TACHES SET DATEDEB = :DATEDEB, DATEFIN = :DATEFIN, MISSION = :MISSION, "
                      "STATUT = :STATUT, DESCRIPTION = :DESCRIPTION WHERE ID_TACHE = :ID_TACHE");

        query.bindValue(":ID_TACHE", idTacheInt);
        query.bindValue(":DATEDEB", dateDeb);
        query.bindValue(":DATEFIN", dateFin);
        query.bindValue(":MISSION", mission);
        query.bindValue(":STATUT", statut);
        query.bindValue(":DESCRIPTION", description);

        if (query.exec()) {
            QMessageBox::information(this, "SUCCÈS", "Tâche modifiée avec succès !");
            afficherTaches();
        } else {
            QMessageBox::critical(this, "ERREUR", "Échec de la modification : " + query.lastError().text());
        }
    }
}


// Destructeur
MainWindow::~MainWindow()
{
    delete ui;
}
