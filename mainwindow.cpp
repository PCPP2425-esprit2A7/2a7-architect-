#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_projet.h"
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

    // Connecter le signal currentIndexChanged() du QComboBox au slot
    connect(ui->comboBox_tri, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_comboBox_tri_currentIndexChanged);
    // Définir le format d'affichage des QDateEdit
    ui->dateEdit->setDisplayFormat("dd/MM/yyyy");
    ui->dateEdit_2->setDisplayFormat("dd/MM/yyyy");

    // Définir la date courante comme valeur par défaut pour date_debut et date_fin
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
    connect(ui->lineEdit_rechercher, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_rechercher_textChanged);
    // Rafraîchir la table
    ui->tableView->setModel(GP.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_2_clicked()
{
    bool ok;
    int id = ui->lineEdit1->text().toInt(&ok); // Convertir l'ID en entier
    QString nom = ui->lineEdit_2->text();
    QString desc = ui->desc->toPlainText();
    QString statut = ui->combo->currentText(); // Récupérer la valeur du QComboBox
    QString date_debut = ui->dateEdit->text();
    QString date_fin = ui->dateEdit_2->text();
    // Vérifier si un champ obligatoire est vide
    if (ui->lineEdit1->text().isEmpty() || nom.isEmpty() || desc.isEmpty() || statut.isEmpty() || date_debut.isEmpty() || date_fin.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Tous les champs doivent être remplis.");
        return;
    }

    // Vérifier si l'ID est un entier valide
    if (!ok) {
        QMessageBox::warning(this, "ID invalide", "L'ID doit être un nombre entier.");
        return;
    }

    // Vérifier si l'ID est un entier positif
    if (id <= 0) {
        QMessageBox::warning(this, "ID invalide", "L'ID doit être un nombre entier positif.");
        return;
    }

    // Convertir les dates en QDate
    QDate debut = QDate::fromString(date_debut, "dd/MM/yyyy");
    QDate fin = QDate::fromString(date_fin, "dd/MM/yyyy");
    QDate aujourdhui = QDate::currentDate(); // Date d'aujourd'hui

    // Vérifier si la date de début est valide
    if (!debut.isValid()) {
        QMessageBox::warning(this, "Date invalide", "Le format de la date de début doit être JJ/MM/AAAA.");
        return;
    }

    // Vérifier si la date de fin est valide
    if (!fin.isValid()) {
        QMessageBox::warning(this, "Date invalide", "Le format de la date de fin doit être JJ/MM/AAAA.");
        return;
    }

    // Vérifier que la date de début est aujourd'hui ou dans le futur
    if (debut < aujourdhui) {
        QMessageBox::warning(this, "Date de début invalide", "La date de début doit être aujourd'hui ou une date future.");
        return;
    }

    // Vérifier que la date de fin est supérieure à la date de début
    if (fin <= debut) {
        QMessageBox::warning(this, "Date de fin invalide", "La date de fin doit être supérieure à la date de début.");
        return;
    }

    GestionProjet projet(id, nom, desc, statut, date_debut, date_fin);

    if (projet.existe(id)) {
        QMessageBox::warning(this, "Projet existant", "Un projet avec cet ID existe déjà.");
    } else {
        if (projet.ajouter()) {
            ui->tableView->setModel(GP.afficher()); // Rafraîchir la table
            QMessageBox::information(this, "Succès", "Projet ajouté avec succès.");

            // Vider le formulaire après un ajout réussi
            ui->lineEdit1->clear();          // Vider l'ID
            ui->lineEdit_2->clear();         // Vider le nom
            ui->desc->clear();               // Vider la description
            ui->combo->setCurrentIndex(0); // Réinitialiser le statut
            ui->dateEdit->setDate(QDate::currentDate()); // Réinitialiser la date de début
            ui->dateEdit_2->setDate(QDate::currentDate()); // Réinitialiser la date de fin
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de l'ajout du projet.");
        }
    }
}

void MainWindow::on_pushButton_13_clicked()
{
    bool ok;
    QString idText = QInputDialog::getText(this, tr("Supprimer un projet"),
                                           tr("Entrez l'ID du projet à supprimer :"),
                                           QLineEdit::Normal, "", &ok);

    if (ok && !idText.isEmpty()) // Si l'utilisateur a cliqué sur OK et a saisi quelque chose
    {
        // Convertir la chaîne en entier
        int id = idText.toInt(&ok);

        if (!ok) // Si la conversion échoue (par exemple, si l'utilisateur a saisi des caractères non numériques)
        {
            QMessageBox::warning(this, tr("ID invalide"), tr("L'ID doit être un nombre entier."));
            return;
        }

        // Vérifier si l'ID existe dans la base de données
        if (!GP.existe(id)) {
            QMessageBox::warning(this, tr("ID inexistant"), tr("Aucun projet avec cet ID n'existe."));
            return;
        }

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Confirmation"),
                                      tr("Êtes-vous sûr de vouloir supprimer le projet ID: %1 ?").arg(id),
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) // L'utilisateur confirme la suppression
        {
            bool test = GP.supprimer(id);
            if (test)
            {
                ui->tableView->setModel(GP.afficher()); // Rafraîchir la table
                QMessageBox::information(this, tr("Succès"),
                                         tr("Le projet a été supprimé avec succès."));
            }
            else
            {
                QMessageBox::critical(this, tr("Erreur"),
                                      tr("La suppression du projet a échoué. Vérifiez l'ID et réessayez."));
            }
        }
    }
}



void MainWindow::on_modifier_clicked()
{


    bool ok;
    QString idText = QInputDialog::getText(this, tr("Modifier un projet"),
                                           tr("Entrez l'ID du projet à modifier :"),
                                           QLineEdit::Normal, "", &ok);

    if (ok && !idText.isEmpty()) // Si l'utilisateur a cliqué sur OK et a saisi quelque chose
    {
        // Convertir la chaîne en entier
        int id = idText.toInt(&ok);

        if (!ok) // Si la conversion échoue (par exemple, si l'utilisateur a saisi des caractères non numériques)
        {
            QMessageBox::warning(this, tr("ID invalide"), tr("L'ID doit être un nombre entier."));
            return;
        }

        // Vérifier si l'ID existe
        if (!GP.existe(id)) {
            QMessageBox::warning(this, tr("ID inexistant"), tr("Aucun projet avec cet ID n'existe."));
            return;
        }

        // Récupérer les informations actuelles du projet
        QSqlQuery query;
        query.prepare("SELECT NOM_PROJET, DESCRIPTION, STATUT, TO_CHAR(DATE_DEBUT, 'DD/MM/YYYY'), TO_CHAR(DATE_FIN, 'DD/MM/YYYY') FROM GESTION_PROJET WHERE ID_PROJET = :id");
        query.bindValue(":id", id);
        query.exec();

        if (query.next()) {
            QString nom = query.value(0).toString();
            QString desc = query.value(1).toString();
            QString statut = query.value(2).toString();
            QString date_debut = query.value(3).toString();
            QString date_fin = query.value(4).toString();

            // Afficher une boîte de dialogue pour modifier les informations
            QDialog dialog(this);
            QFormLayout form(&dialog);

            QLineEdit *nomEdit = new QLineEdit(nom, &dialog);
            QTextEdit *descEdit = new QTextEdit(desc, &dialog);
            QComboBox *statutCombo = new QComboBox(&dialog);
            statutCombo->addItems({"terminé", "en cours", "suspendu"});
            statutCombo->setCurrentText(statut);
            QDateEdit *dateDebutEdit = new QDateEdit(QDate::fromString(date_debut, "dd/MM/yyyy"), &dialog);
            dateDebutEdit->setDisplayFormat("dd/MM/yyyy");
            QDateEdit *dateFinEdit = new QDateEdit(QDate::fromString(date_fin, "dd/MM/yyyy"), &dialog);
            dateFinEdit->setDisplayFormat("dd/MM/yyyy");

            form.addRow("Nom du projet :", nomEdit);
            form.addRow("Description :", descEdit);
            form.addRow("Statut :", statutCombo);
            form.addRow("Date de début :", dateDebutEdit);
            form.addRow("Date de fin :", dateFinEdit);

            QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
            form.addRow(&buttonBox);

            QObject::connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
            QObject::connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

            if (dialog.exec() == QDialog::Accepted) {
                // Récupérer les nouvelles valeurs
                QString nouveauNom = nomEdit->text();
                QString nouvelleDesc = descEdit->toPlainText();
                QString nouveauStatut = statutCombo->currentText();
                QString nouvelleDateDebut = dateDebutEdit->date().toString("dd/MM/yyyy");
                QString nouvelleDateFin = dateFinEdit->date().toString("dd/MM/yyyy");

                // Vérifier que les champs ne sont pas vides
                if (nouveauNom.isEmpty() || nouvelleDesc.isEmpty() || nouvelleDateDebut.isEmpty() || nouvelleDateFin.isEmpty()) {
                    QMessageBox::warning(this, tr("Champ vide"), tr("Tous les champs doivent être remplis."));
                    return;
                }

                // Vérifier que la date de fin est supérieure à la date de début
                if (QDate::fromString(nouvelleDateFin, "dd/MM/yyyy") <= QDate::fromString(nouvelleDateDebut, "dd/MM/yyyy")) {
                    QMessageBox::warning(this, tr("Date invalide"), tr("La date de fin doit être supérieure à la date de début."));
                    return;
                }

                // Modifier le projet
                if (GP.modifier(id, nouveauNom, nouvelleDesc, nouveauStatut, nouvelleDateDebut, nouvelleDateFin)) {
                    ui->tableView->setModel(GP.afficher()); // Rafraîchir la table
                    QMessageBox::information(this, tr("Succès"), tr("Le projet a été modifié avec succès."));
                } else {
                    QMessageBox::critical(this, tr("Erreur"), tr("La modification du projet a échoué."));
                }
            }
        }
    }

}


void MainWindow::on_lineEdit_rechercher_textChanged(const QString &text)
{
    // Récupérer le texte saisi dans le champ de recherche
    QString recherche = text;

    // Filtrer les projets en fonction du texte saisi
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, STATUT, TO_CHAR(DATE_DEBUT, 'DD/MM/YYYY'), TO_CHAR(DATE_FIN, 'DD/MM/YYYY') FROM GESTION_PROJET WHERE NOM_PROJET LIKE :recherche");
    query.bindValue(":recherche", recherche + "%"); // Recherche des noms qui commencent par le texte saisi
    query.exec();

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Fin"));

    // Mettre à jour la table avec les résultats de la recherche
    ui->tableView->setModel(model);
}


void MainWindow::on_comboBox_tri_currentIndexChanged(int index)
{
    QString orderBy;
    if (index == 0) {
        // Trier par date la plus récente
        orderBy = "DATE_DEBUT DESC";
    } else if (index == 1) {
        // Trier par date la plus ancienne
        orderBy = "DATE_DEBUT ASC";
    }

    // Exécuter la requête SQL avec le tri approprié
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

    // Mettre à jour la table avec les résultats triés
    ui->tableView->setModel(model);
}


void MainWindow::on_pushButton_pdf_clicked()
{
    // Récupérer la liste des projets existants
    QSqlQuery query("SELECT ID_PROJET, NOM_PROJET FROM GESTION_PROJET");

    // Créer une liste pour stocker les projets
    QStringList projets;
    while (query.next()) {
        int id = query.value(0).toInt();
        QString nom = query.value(1).toString();
        projets << QString("ID: %1 - Nom: %2").arg(id).arg(nom);
    }

    // Boîte de dialogue personnalisée pour sélectionner plusieurs projets
    QDialog dialog(this);
    dialog.setWindowTitle("Sélectionner des projets");
    QVBoxLayout layout(&dialog);
    QListWidget listWidget(&dialog);

    // Ajouter les projets à la QListWidget
    for (const QString &projet : projets) {
        listWidget.addItem(projet);
    }
    listWidget.setSelectionMode(QAbstractItemView::MultiSelection); // Permettre la sélection multiple

    QPushButton button("Valider", &dialog);
    layout.addWidget(&listWidget);
    layout.addWidget(&button);

    // Liste pour stocker les IDs des projets sélectionnés
    QList<int> selectedIds;

    // Connecter le bouton "Valider" à une action
    QObject::connect(&button, &QPushButton::clicked, [&]() {
        QList<QListWidgetItem*> selectedItems = listWidget.selectedItems();
        for (QListWidgetItem *item : selectedItems) {
            int id = item->text().split(" - ")[0].split(": ")[1].toInt();
            selectedIds << id;
        }
        dialog.accept();
    });

    // Afficher la boîte de dialogue
    if (dialog.exec() != QDialog::Accepted || selectedIds.isEmpty()) {
        return; // L'utilisateur a annulé ou n'a rien sélectionné
    }

    // Demander à l'utilisateur où enregistrer le fichier PDF
    QString filePath = QFileDialog::getSaveFileName(this, tr("Enregistrer le PDF"), "", tr("Fichiers PDF (*.pdf)"));

    if (filePath.isEmpty()) {
        return; // L'utilisateur a annulé
    }

    // Créer un QPdfWriter pour écrire dans le fichier PDF
    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4)); // Définir la taille de la page
    pdfWriter.setTitle("Détails des projets"); // Définir le titre du document

    // Créer un QPainter pour dessiner sur le PDF
    QPainter painter(&pdfWriter);

    // Définir les marges
    int margin = 30; // Marge de 30 pixels
    int y = margin;  // Position Y initiale

    // Définir la police pour le titre
    QFont titleFont = painter.font();
    titleFont.setPointSize(24); // Police très grande pour le titre
    titleFont.setBold(true);
    painter.setFont(titleFont);

    // Définir la couleur du titre
    painter.setPen(Qt::darkBlue); // Couleur bleu foncé pour le titre

    // Centrer le titre
    QString title = "Détails des projets";
    int titleWidth = painter.fontMetrics().horizontalAdvance(title);
    int centerX = (pdfWriter.width() - titleWidth) / 2;
    painter.drawText(centerX, y, title);
    y += 600; // Espacement après le titre

    // Définir la police pour les en-têtes de colonnes
    QFont headerFont = painter.font();
    headerFont.setPointSize(16); // Police grande pour les en-têtes
    headerFont.setBold(true);
    painter.setFont(headerFont);

    // Définir les largeurs des colonnes (plus larges pour plus de lisibilité)
    int colWidths[] = {1000, 1100, 1500, 1500, 1600, 1600}; // Largeurs des colonnes ajustées
    QString headers[] = {"ID", "Nom", "Description", "Statut", "Date Début", "Date Fin"};

    // Calculer la position de départ pour centrer le tableau
    int totalTableWidth = 0;
    for (int i = 0; i < 6; ++i) {
        totalTableWidth += colWidths[i];
    }
    int tableStartX = (pdfWriter.width() - totalTableWidth) / 2;

    // Définir la couleur des en-têtes
    painter.setPen(Qt::darkCyan); // Texte en blanc
    painter.setBrush(Qt::darkGreen); // Fond vert foncé pour les en-têtes

    // Dessiner les en-têtes de colonnes
    int x = tableStartX;
    for (int i = 0; i < 6; ++i) {
        painter.drawRect(x, y, colWidths[i], 50); // Cellules plus hautes (50 pixels)
        painter.drawText(x + 10, y + 35, headers[i]); // Texte centré dans la cellule
        x += colWidths[i];
    }
    y += 600; // Espacement après les en-têtes

    // Définir la police pour le contenu
    QFont contentFont = painter.font();
    contentFont.setPointSize(14); // Police grande pour le contenu
    contentFont.setBold(false);
    painter.setFont(contentFont);

    // Définir la couleur du contenu
    painter.setPen(Qt::black); // Texte en noir
    painter.setBrush(Qt::white); // Fond blanc pour les cellules

    // Récupérer les données des projets sélectionnés
    QString ids;
    for (int id : selectedIds) {
        ids += QString::number(id) + ",";
    }
    ids.chop(1); // Supprimer la dernière virgule

    QSqlQuery queryProjet;
    queryProjet.prepare(QString("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, STATUT, TO_CHAR(DATE_DEBUT, 'DD/MM/YYYY'), TO_CHAR(DATE_FIN, 'DD/MM/YYYY') FROM GESTION_PROJET WHERE ID_PROJET IN (%1)").arg(ids));
    queryProjet.exec();

    // Parcourir les résultats de la requête et les écrire dans le PDF
    while (queryProjet.next()) {
        int id = queryProjet.value(0).toInt();
        QString nom = queryProjet.value(1).toString();
        QString desc = queryProjet.value(2).toString();
        QString statut = queryProjet.value(3).toString();
        QString date_debut = queryProjet.value(4).toString();
        QString date_fin = queryProjet.value(5).toString();

        // Dessiner les données du projet dans les cellules
        x = tableStartX;
        QString values[] = {QString::number(id), nom, desc, statut, date_debut, date_fin};
        for (int i = 0; i < 6; ++i) {
            painter.drawRect(x, y, colWidths[i], 50); // Cellules plus hautes (50 pixels)
            painter.drawText(x + 10, y + 35, values[i]); // Texte centré dans la cellule
            x += colWidths[i];
        }
        y += 600; // Espacement entre les lignes

        // Vérifier si on dépasse la page
        if (y > pdfWriter.height() - margin) {
            pdfWriter.newPage(); // Passer à une nouvelle page
            y = margin; // Réinitialiser la position Y
        }
    }

    // Terminer le dessin
    painter.end();

    // Afficher un message de succès
    QMessageBox::information(this, tr("Succès"), tr("Le fichier PDF a été généré avec succès."));
}

