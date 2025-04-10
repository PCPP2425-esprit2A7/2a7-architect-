#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_projet.h"
#include "modifier.h"
#include <QMessageBox>
#include <QDate>
#include <QInputDialog>
#include <QFormLayout>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QSqlError>
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->comboBox_tri->addItem("Date la plus récente");
    ui->comboBox_tri->addItem("Date la plus ancienne");
    connect(ui->pushButton_pdf, &QPushButton::clicked, this, &MainWindow::on_pushButton_pdf_clicked);

    connect(ui->comboBox_tri, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_comboBox_tri_currentIndexChanged);
    ui->dateEdit->setDisplayFormat("dd/MM/yyyy");
    ui->dateEdit_2->setDisplayFormat("dd/MM/yyyy");

    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
    connect(ui->lineEdit_rechercher, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_rechercher_textChanged);
    ui->tableView->setModel(GP.afficher());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_2_clicked() {
    bool ok;
    int id = ui->lineEdit1->text().toInt(&ok);
    QString nom = ui->lineEdit_2->text();
    QString desc = ui->desc->toPlainText();
    QString statut = ui->combo->currentText();
    QString date_debut = ui->dateEdit->text();
    QString date_fin = ui->dateEdit_2->text();

    if (ui->lineEdit1->text().isEmpty() || nom.isEmpty() || desc.isEmpty() || statut.isEmpty() || date_debut.isEmpty() || date_fin.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Tous les champs doivent être remplis.");
        return;
    }

    if (!ok) {
        QMessageBox::warning(this, "ID invalide", "L'ID doit être un nombre entier.");
        return;
    }

    if (id <= 0) {
        QMessageBox::warning(this, "ID invalide", "L'ID doit être un nombre entier positif.");
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

    GestionProjet projet(id, nom, desc, statut, date_debut, date_fin);

    if (projet.existe(id)) {
        QMessageBox::warning(this, "Projet existant", "Un projet avec cet ID existe déjà.");
    } else {
        if (projet.ajouter()) {
            ui->tableView->setModel(GP.afficher());
            QMessageBox::information(this, "Succès", "Projet ajouté avec succès.");

            ui->lineEdit1->clear();
            ui->lineEdit_2->clear();
            ui->desc->clear();
            ui->combo->setCurrentIndex(0);
            ui->dateEdit->setDate(QDate::currentDate());
            ui->dateEdit_2->setDate(QDate::currentDate());
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de l'ajout du projet.");
        }
    }
}

void MainWindow::on_pushButton_13_clicked() {
    bool ok;
    QString idText = QInputDialog::getText(this, tr("Supprimer un projet"),
                                           tr("Entrez l'ID du projet à supprimer :"),
                                           QLineEdit::Normal, "", &ok);

    if (ok && !idText.isEmpty()) {
        int id = idText.toInt(&ok);

        if (!ok) {
            QMessageBox::warning(this, tr("ID invalide"), tr("L'ID doit être un nombre entier."));
            return;
        }

        if (!GP.existe(id)) {
            QMessageBox::warning(this, tr("ID inexistant"), tr("Aucun projet avec cet ID n'existe."));
            return;
        }

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Confirmation"),
                                      tr("Êtes-vous sûr de vouloir supprimer le projet ID: %1 ?").arg(id),
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            bool test = GP.supprimer(id);
            if (test) {
                ui->tableView->setModel(GP.afficher());
                QMessageBox::information(this, tr("Succès"),
                                         tr("Le projet a été supprimé avec succès."));
            } else {
                QMessageBox::critical(this, tr("Erreur"),
                                      tr("La suppression du projet a échoué. Vérifiez l'ID et réessayez."));
            }
        }
    }
}

void MainWindow::on_modifier_clicked() {
    bool ok;
    QString idText = QInputDialog::getText(this, tr("Modifier un projet"),
                                           tr("Entrez l'ID du projet à modifier :"),
                                           QLineEdit::Normal, "", &ok);

    if (!ok || idText.isEmpty()) {
        return;
    }

    int id = idText.toInt(&ok);
    if (!ok || id <= 0) {
        QMessageBox::warning(this, tr("ID invalide"), tr("L'ID doit être un nombre entier positif."));
        return;
    }

    if (!GP.existe(id)) {
        QMessageBox::warning(this, tr("ID inexistant"), tr("Aucun projet avec cet ID n'existe."));
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT NOM_PROJET, DESCRIPTION, STATUT, TO_CHAR(DATE_DEBUT, 'DD/MM/YYYY'), TO_CHAR(DATE_FIN, 'DD/MM/YYYY') FROM GESTION_PROJET WHERE ID_PROJET = :id");
    query.bindValue(":id", id);
    query.exec();

    if (!query.next()) {
        QMessageBox::critical(this, tr("Erreur"), tr("Impossible de récupérer les informations du projet."));
        return;
    }

    QString nom = query.value(0).toString();
    QString desc = query.value(1).toString();
    QString statut = query.value(2).toString();
    QString date_debut = query.value(3).toString();
    QString date_fin = query.value(4).toString();

    modifier *modDialog = new modifier(this, id, nom, desc, statut, date_debut, date_fin);

    connect(modDialog, &modifier::projetModifie, this, [this]() {
        ui->tableView->setModel(GP.afficher());
    });

    modDialog->setModal(true);
    modDialog->exec();

    delete modDialog;
}

// Rest of the implementation remains the same...

void MainWindow::on_lineEdit_rechercher_textChanged(const QString &text) {
    QString recherche = text;
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, STATUT, TO_CHAR(DATE_DEBUT, 'DD/MM/YYYY'), TO_CHAR(DATE_FIN, 'DD/MM/YYYY') FROM GESTION_PROJET WHERE NOM_PROJET LIKE :recherche");
    query.bindValue(":recherche", recherche + "%");
    query.exec();

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Fin"));

    ui->tableView->setModel(model);
}

void MainWindow::on_comboBox_tri_currentIndexChanged(int index) {
    QString orderBy;
    if (index == 0) {
        orderBy = "DATE_DEBUT DESC";
    } else if (index == 1) {
        orderBy = "DATE_DEBUT ASC";
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, STATUT, TO_CHAR(DATE_DEBUT, 'DD/MM/YYYY'), TO_CHAR(DATE_FIN, 'DD/MM/YYYY') FROM GESTION_PROJET ORDER BY " + orderBy);
    query.exec();

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Fin"));

    ui->tableView->setModel(model);
}

void MainWindow::on_pushButton_pdf_clicked() {
    QSqlQuery query("SELECT ID_PROJET, NOM_PROJET FROM GESTION_PROJET");
    QStringList projets;
    while (query.next()) {
        int id = query.value(0).toInt();
        QString nom = query.value(1).toString();
        projets << QString("ID: %1 - Nom: %2").arg(id).arg(nom);
    }

    QDialog dialog(this);
    dialog.setWindowTitle("Sélectionner des projets");
    QVBoxLayout layout(&dialog);
    QListWidget listWidget(&dialog);

    for (const QString &projet : projets) {
        listWidget.addItem(projet);
    }
    listWidget.setSelectionMode(QAbstractItemView::MultiSelection);

    QPushButton button("Valider", &dialog);
    layout.addWidget(&listWidget);
    layout.addWidget(&button);

    QList<int> selectedIds;

    QObject::connect(&button, &QPushButton::clicked, [&]() {
        QList<QListWidgetItem*> selectedItems = listWidget.selectedItems();
        for (QListWidgetItem *item : selectedItems) {
            int id = item->text().split(" - ")[0].split(": ")[1].toInt();
            selectedIds << id;
        }
        dialog.accept();
    });

    if (dialog.exec() != QDialog::Accepted || selectedIds.isEmpty()) {
        return;
    }

    QString filePath = QFileDialog::getSaveFileName(this, tr("Enregistrer le PDF"), "", tr("Fichiers PDF (*.pdf)"));

    if (filePath.isEmpty()) {
        return;
    }

    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setTitle("Détails des projets");

    QPainter painter(&pdfWriter);

    int margin = 30;
    int y = margin;

    QFont titleFont = painter.font();
    titleFont.setPointSize(24);
    titleFont.setBold(true);
    painter.setFont(titleFont);
    painter.setPen(Qt::darkBlue);

    QString title = "Détails des projets";
    int titleWidth = painter.fontMetrics().horizontalAdvance(title);
    int centerX = (pdfWriter.width() - titleWidth) / 2;
    painter.drawText(centerX, y, title);
    y += 600;

    QFont headerFont = painter.font();
    headerFont.setPointSize(16);
    headerFont.setBold(true);
    painter.setFont(headerFont);

    int colWidths[] = {1000, 1100, 1500, 1500, 1600, 1600};
    QString headers[] = {"ID", "Nom", "Description", "Statut", "Date Début", "Date Fin"};

    int totalTableWidth = 0;
    for (int i = 0; i < 6; ++i) {
        totalTableWidth += colWidths[i];
    }
    int tableStartX = (pdfWriter.width() - totalTableWidth) / 2;

    painter.setPen(Qt::darkCyan);
    painter.setBrush(Qt::darkGreen);

    int x = tableStartX;
    for (int i = 0; i < 6; ++i) {
        painter.drawRect(x, y, colWidths[i], 50);
        painter.drawText(x + 10, y + 35, headers[i]);
        x += colWidths[i];
    }
    y += 600;

    QFont contentFont = painter.font();
    contentFont.setPointSize(14);
    contentFont.setBold(false);
    painter.setFont(contentFont);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::white);

    QString ids;
    for (int id : selectedIds) {
        ids += QString::number(id) + ",";
    }
    ids.chop(1);

    QSqlQuery queryProjet;
    queryProjet.prepare(QString("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, STATUT, TO_CHAR(DATE_DEBUT, 'DD/MM/YYYY'), TO_CHAR(DATE_FIN, 'DD/MM/YYYY') FROM GESTION_PROJET WHERE ID_PROJET IN (%1)").arg(ids));
    queryProjet.exec();

    while (queryProjet.next()) {
        int id = queryProjet.value(0).toInt();
        QString nom = queryProjet.value(1).toString();
        QString desc = queryProjet.value(2).toString();
        QString statut = queryProjet.value(3).toString();
        QString date_debut = queryProjet.value(4).toString();
        QString date_fin = queryProjet.value(5).toString();

        x = tableStartX;
        QString values[] = {QString::number(id), nom, desc, statut, date_debut, date_fin};
        for (int i = 0; i < 6; ++i) {
            painter.drawRect(x, y, colWidths[i], 50);
            painter.drawText(x + 10, y + 35, values[i]);
            x += colWidths[i];
        }
        y += 600;

        if (y > pdfWriter.height() - margin) {
            pdfWriter.newPage();
            y = margin;
        }
    }

    painter.end();
    QMessageBox::information(this, tr("Succès"), tr("Le fichier PDF a été généré avec succès."));
}
