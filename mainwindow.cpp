#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QDate>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QListWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QRegularExpression>
#include <QInputDialog>
#include <QLineEdit>
#include <QButtonGroup>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->comboBox_tri->addItem("Date la plus récente");
    ui->comboBox_tri->addItem("Date la plus ancienne");

    // Connexion des signaux/slots
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_pushButton_3_clicked);
    connect(ui->pushButton_13, &QPushButton::clicked, this, &MainWindow::on_pushButton_13_clicked);
    connect(ui->pushButton_pdf, &QPushButton::clicked, this, &MainWindow::on_pushButton_pdf_clicked);
    connect(ui->modifier, &QPushButton::clicked, this, &MainWindow::on_modifier_clicked);
    connect(ui->comboBox_tri, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::on_comboBox_tri_currentIndexChanged);
    connect(ui->lineEdit_rechercher, &QLineEdit::textChanged,
            this, &MainWindow::on_lineEdit_rechercher_textChanged);
    connect(ui->stat, &QPushButton::clicked, this, &MainWindow::on_stat_clicked);
    connect(ui->predictEndDateBtn, &QPushButton::clicked, this, &MainWindow::on_predictEndDateBtn_clicked);

    // Entraîner le modèle ML au démarrage
    if (!mlPredictor.trainModel()) {
        qDebug() << "Erreur lors de l'entraînement du modèle ML";
    }

    // Initialize calendar and date selection
    startDate = QDate::currentDate();
    endDate = QDate::currentDate();

    // Ajouter les boutons radio pour la sélection de date
    QButtonGroup* dateButtonGroup = new QButtonGroup(this);
    dateButtonGroup->addButton(ui->radioButton_start);
    dateButtonGroup->addButton(ui->radioButton_end);
    ui->radioButton_start->setChecked(true);  // Par défaut, sélectionner la date de début

    // Connect calendar date changed signal
    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, [this](const QDate &date) {
        if (ui->radioButton_start->isChecked()) {
            startDate = date;
            if (endDate < startDate) {
                endDate = startDate;
            }
        } else {
            endDate = date;
            if (endDate < startDate) {
                startDate = endDate;
            }
        }
        updateDateLabels();
    });

    // Afficher les projets au démarrage
    ui->tableView->setModel(GP.afficher());

    // Initialisation du modèle ML
}

void MainWindow::updateDateLabels() {
    // Mettre à jour les labels avec les dates sélectionnées
    ui->label_startDate->setText(startDate.toString("dd/MM/yyyy"));
    ui->label_endDate->setText(endDate.toString("dd/MM/yyyy"));
}

void MainWindow::on_pushButton_2_clicked() {
    bool ok;
    int id = ui->lineEdit1->text().toInt(&ok);
    QString nom = ui->lineEdit_2->text();
    QString desc = ui->desc->toPlainText();
    QString statut = ui->combo->currentText();
    QString date_debut = startDate.toString("dd/MM/yyyy");
    QString date_fin = endDate.toString("dd/MM/yyyy");

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

            // Reset dates
            startDate = QDate::currentDate();
            endDate = QDate::currentDate().addMonths(6);
            ui->calendarWidget->setSelectedDate(startDate);
            updateDateLabels();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de l'ajout du projet.");
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::information(this, "Information", "Bouton 3 cliqué");
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

void MainWindow::on_lineEdit_rechercher_textChanged(const QString &text) {
    QString recherche = text;

    if (ui->tableView->model()) {
        delete ui->tableView->model();
    }

    QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);
    QSqlQuery query;
    query.prepare("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, STATUT, TO_CHAR(DATE_DEBUT, 'DD/MM/YYYY'), TO_CHAR(DATE_FIN, 'DD/MM/YYYY') FROM GESTION_PROJET WHERE UPPER(NOM_PROJET) LIKE UPPER(:recherche)");
    query.bindValue(":recherche", "%" + recherche + "%");

    if (query.exec()) {
        model->setQuery(std::move(query));
        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, tr("Description"));
        model->setHeaderData(3, Qt::Horizontal, tr("Statut"));
        model->setHeaderData(4, Qt::Horizontal, tr("Date Début"));
        model->setHeaderData(5, Qt::Horizontal, tr("Date Fin"));

        ui->tableView->setModel(model);
    } else {
        delete model;
        QMessageBox::warning(this, tr("Erreur"), tr("Erreur lors de la recherche : ") + query.lastError().text());
    }
}

void MainWindow::on_comboBox_tri_currentIndexChanged(int index) {
    if (ui->tableView->model()) {
        delete ui->tableView->model();
    }

    QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);
    QSqlQuery query;

    QString queryStr = "SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, STATUT, TO_CHAR(DATE_DEBUT, 'DD/MM/YYYY'), TO_CHAR(DATE_FIN, 'DD/MM/YYYY') FROM GESTION_PROJET ORDER BY ";

    switch(index) {
    case 0: // Date la plus récente
        queryStr += "DATE_DEBUT DESC";
        break;
    case 1: // Date la plus ancienne
        queryStr += "DATE_DEBUT ASC";
        break;
    default:
        queryStr += "DATE_DEBUT DESC";
    }

    query.prepare(queryStr);

    if (query.exec()) {
        model->setQuery(std::move(query));
        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, tr("Description"));
        model->setHeaderData(3, Qt::Horizontal, tr("Statut"));
        model->setHeaderData(4, Qt::Horizontal, tr("Date Début"));
        model->setHeaderData(5, Qt::Horizontal, tr("Date Fin"));

        ui->tableView->setModel(model);
    } else {
        delete model;
        QMessageBox::warning(this, tr("Erreur"), tr("Erreur lors du tri : ") + query.lastError().text());
    }
}

void MainWindow::on_stat_clicked()
{
    showStatistics();
}

void MainWindow::on_predictEndDateBtn_clicked()
{
    QString description = ui->desc->toPlainText();
    QString statut = ui->combo->currentText();

    if (description.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez d'abord saisir une description du projet.");
        return;
    }

    int dureePredit = mlPredictor.predictDuration(description, statut);

    if (dureePredit <= 0) {
        QMessageBox::warning(this, "Erreur", "Impossible de prédire la durée du projet.");
        return;
    }

    QDate dateDebut = ui->calendarWidget->selectedDate();
    QDate dateFin = dateDebut.addDays(dureePredit);

    // Update the endDate member variable
    endDate = dateFin;

    // Set the "Date fin" radio button as checked
    ui->radioButton_end->setChecked(true);

    // Temporarily disconnect the calendar's clicked signal to prevent interference
    disconnect(ui->calendarWidget, &QCalendarWidget::clicked, nullptr, nullptr);

    // Update the calendar to show the predicted end date
    ui->calendarWidget->setSelectedDate(dateFin);

    // Reconnect the clicked signal
    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, [this](const QDate &date) {
        if (ui->radioButton_start->isChecked()) {
            startDate = date;
            if (endDate < startDate) {
                endDate = startDate;
            }
        } else {
            endDate = date;
            if (endDate < startDate) {
                startDate = endDate;
            }
        }
        updateDateLabels();
    });

    // Update the date labels to reflect the new endDate
    updateDateLabels();

    // Show the prediction message
    QString message = QString("Durée prédite : %1 jours\nDate de fin prédite : %2")
                          .arg(dureePredit)
                          .arg(dateFin.toString("dd/MM/yyyy"));
    QMessageBox::information(this, "Prédiction", message);
}

void MainWindow::showStatistics()
{
    QSqlQuery query;
    query.prepare("SELECT STATUT, COUNT(*) as count FROM GESTION_PROJET GROUP BY STATUT");

    if (!query.exec()) {
        qDebug() << "Erreur SQL:" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les statistiques: " + query.lastError().text());
        return;
    }

    QPieSeries *series = new QPieSeries();
    int totalProjets = 0;

    QMap<QString, int> statusCounts;
    while (query.next()) {
        QString status = query.value("STATUT").toString();
        int count = query.value("count").toInt();
        statusCounts[status] = count;
        totalProjets += count;
    }

    if (totalProjets == 0) {
        QMessageBox::information(this, "Information", "Aucun projet trouvé dans la base de données.");
        return;
    }

    for (auto it = statusCounts.begin(); it != statusCounts.end(); ++it) {
        double percentage = (it.value() * 100.0) / totalProjets;
        QString label = QString("%1: %2%").arg(it.key()).arg(QString::number(percentage, 'f', 1));
        series->append(label, it.value());
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des projets par statut");
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(600, 400);

    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Statistiques des projets");
    dialog->setModal(true);

    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);

    QString statsText = "Statistiques détaillées:\n\n";
    for (auto it = statusCounts.begin(); it != statusCounts.end(); ++it) {
        double percentage = (it.value() * 100.0) / totalProjets;
        statsText += QString("%1: %2 projets (%3%)\n")
                         .arg(it.key())
                         .arg(it.value())
                         .arg(QString::number(percentage, 'f', 1));
    }
    statsText += QString("\nTotal: %1 projets").arg(totalProjets);

    QLabel *statsLabel = new QLabel(statsText);
    statsLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(statsLabel);

    dialog->setLayout(layout);
    dialog->resize(800, 600);
    dialog->exec();

    delete dialog;
}

void MainWindow::drawFooter(QPainter* painter, int pageNumber, int pageWidth, int pageHeight, int margin)
{
    painter->save();

    QRect footerRect(0, pageHeight - 60, pageWidth, 60);
    painter->fillRect(footerRect, QColor(245, 245, 245));

    painter->setPen(QPen(QColor(100, 100, 100), 1));
    painter->drawLine(margin, pageHeight - 60, pageWidth - margin, pageHeight - 60);

    QFont footerFont("Arial", 9);
    painter->setFont(footerFont);
    painter->setPen(QColor(80, 80, 80));

    QString companyInfo = "ESPRIT - École Supérieure Privée d'Ingénierie et de Technologies";
    painter->drawText(margin, pageHeight - 40, companyInfo);

    QString dateTime = QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm");
    QRect dateRect(0, pageHeight - 40, pageWidth, 20);
    painter->drawText(dateRect, Qt::AlignHCenter, dateTime);

    QString pageText = QString("Page %1").arg(pageNumber);
    painter->drawText(pageWidth - margin - 100, pageHeight - 40, pageText);

    painter->restore();
}

void MainWindow::on_pushButton_pdf_clicked() {
    QSqlQuery query("SELECT ID_PROJET, NOM_PROJET, STATUT FROM GESTION_PROJET ORDER BY ID_PROJET");
    QStringList projets;
    QMap<int, QString> statutMap;

    while (query.next()) {
        int id = query.value(0).toInt();
        QString nom = query.value(1).toString();
        QString statut = query.value(2).toString();
        projets << QString("ID: %1 - %2 (%3)").arg(id).arg(nom).arg(statut);
        statutMap[id] = statut;
    }

    QDialog dialog(this);
    dialog.setWindowTitle("Sélectionner des projets pour le rapport");
    dialog.setMinimumWidth(400);

    QVBoxLayout layout(&dialog);

    QLabel* label = new QLabel("Sélectionnez les projets à inclure dans le rapport :", &dialog);
    label->setWordWrap(true);
    layout.addWidget(label);

    QListWidget listWidget(&dialog);
    listWidget.setAlternatingRowColors(true);

    for (const QString &projet : projets) {
        QListWidgetItem* item = new QListWidgetItem(projet);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);

        QString statut = projet.split("(").last().split(")").first();
        if (statut.toLower() == "en cours") {
            item->setBackground(QColor(217, 237, 247));
        } else if (statut.toLower() == "termine") {
            item->setBackground(QColor(223, 240, 216));
        } else if (statut.toLower() == "suspendu") {
            item->setBackground(QColor(252, 248, 227));
        }

        listWidget.addItem(item);
    }

    layout.addWidget(&listWidget);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    QPushButton* selectAllButton = new QPushButton("Tout sélectionner", &dialog);
    QPushButton* validateButton = new QPushButton("Générer le rapport", &dialog);
    validateButton->setDefault(true);

    buttonLayout->addWidget(selectAllButton);
    buttonLayout->addWidget(validateButton);
    layout.addLayout(buttonLayout);

    QList<int> selectedIds;

    QObject::connect(selectAllButton, &QPushButton::clicked, [&]() {
        for (int i = 0; i < listWidget.count(); ++i) {
            QListWidgetItem* item = listWidget.item(i);
            item->setCheckState(Qt::Checked);
        }
    });

    QObject::connect(validateButton, &QPushButton::clicked, [&]() {
        for (int i = 0; i < listWidget.count(); ++i) {
            QListWidgetItem* item = listWidget.item(i);
            if (item->checkState() == Qt::Checked) {
                int id = item->text().split(" - ")[0].split(": ")[1].toInt();
                selectedIds << id;
            }
        }
        if (selectedIds.isEmpty()) {
            QMessageBox::warning(&dialog, "Attention", "Veuillez sélectionner au moins un projet.");
            return;
        }
        dialog.accept();
    });

    if (dialog.exec() != QDialog::Accepted) {
        return;
    }

    QString defaultName = QString("Rapport_Projets_%1").arg(QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss"));
    QString filePath = QFileDialog::getSaveFileName(
        this,
        tr("Enregistrer le rapport"),
        QDir::homePath() + "/" + defaultName + ".pdf",
        tr("Fichiers PDF (*.pdf)"));

    if (filePath.isEmpty()) {
        return;
    }

    QProgressDialog progress("Génération du rapport PDF...", "Annuler", 0, selectedIds.count(), this);
    progress.setWindowModality(Qt::WindowModal);
    progress.setMinimumDuration(0);

    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setTitle("Rapport des Projets");
    pdfWriter.setCreator("Gestion des Projets - ESPRIT");
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    const int margin = 100;
    const int pageWidth = pdfWriter.width();
    const int pageHeight = pdfWriter.height();
    int y = margin;
    int pageNumber = 1;

    QLinearGradient headerGradient(QPointF(0, y), QPointF(0, y + 120));
    headerGradient.setColorAt(0, QColor(41, 128, 185));
    headerGradient.setColorAt(1, QColor(52, 152, 219));

    QRect headerRect(0, y, pageWidth, 120);
    painter.fillRect(headerRect, headerGradient);

    painter.setPen(Qt::white);
    QRect logoRect(margin -70, y +15 , 80, 80);
    painter.drawRoundedRect(logoRect, 10, 10);
    painter.drawText(logoRect, Qt::AlignCenter, "ESPRIT");

    QFont titleFont("Arial", 28, QFont::Bold);
    painter.setFont(titleFont);
    QString title = "Rapport Détaillé des Projets";
    QRect titleRect(margin + 10, y, pageWidth - 2 * margin - 100, 120);
    painter.setPen(Qt::white);
    painter.drawText(titleRect, Qt::AlignVCenter, title);
    y += 140;

    y += 30;
    QFont infoFont("Arial", 11);
    painter.setFont(infoFont);
    painter.setPen(Qt::black);

    QDateTime now = QDateTime::currentDateTime();
    QString dateTime = now.toString("dd/MM/yyyy HH:mm");
    QString reportInfo = QString("Rapport généré le %1").arg(dateTime);

    painter.drawText(margin, y, reportInfo);
    y += 50;

    QString selectedIdsStr;
    for (int i = 0; i < selectedIds.size(); ++i) {
        selectedIdsStr += QString::number(selectedIds[i]);
        if (i < selectedIds.size() - 1) {
            selectedIdsStr += ",";
        }
    }

    QSqlQuery querySummary;
    querySummary.prepare(
        "SELECT STATUT, COUNT(*) as count "
        "FROM GESTION_PROJET "
        "WHERE ID_PROJET IN (" + selectedIdsStr + ") "
                           "GROUP BY STATUT");

    if (querySummary.exec()) {
        QRect summaryRect(margin, y, pageWidth - 2 * margin, 200);
        painter.fillRect(summaryRect, QColor(250, 250, 250));
        painter.setPen(QPen(QColor(200, 200, 200)));
        painter.drawRect(summaryRect);

        painter.setFont(QFont("Arial", 12, QFont::Bold));
        painter.setPen(Qt::black);
        painter.drawText(margin + 30, y + 40, "Résumé des projets");

        painter.setFont(QFont("Arial", 10));
        int summaryY = y + 90;
        int totalProjets = 0;

        while (querySummary.next()) {
            QString statut = querySummary.value(0).toString().toUpper();
            int count = querySummary.value(1).toInt();
            totalProjets += count;

            QString statusText = QString("%1: %2 projet(s)").arg(statut).arg(count);

            if (statut == "EN COURS") {
                painter.setPen(QColor(52, 152, 219));
            } else if (statut == "TERMINE") {
                painter.setPen(QColor(46, 204, 113));
            } else if (statut == "SUSPENDU") {
                painter.setPen(QColor(241, 196, 15));
            } else {
                painter.setPen(Qt::black);
            }

            painter.drawText(margin + 35, summaryY, statusText);
            summaryY += 50;
        }

        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 10, QFont::Bold));
        painter.drawText(margin + 70, summaryY +350, QString("Total: %1 projet(s)").arg(totalProjets));
    }

    y += 200;

    const int numColumns = 6;
    int colWidths[numColumns] = {32, 30, 35, 50, 50, 50};
    QString headers[numColumns] = {
        "ID",
        "Nom du Projet",
        "Description",
        "Statut",
        "Date Début",
        "Date Fin"
    };

    float pixelsPerMm = pdfWriter.width() / 210.0;
    for (int i = 0; i < numColumns; ++i) {
        colWidths[i] = colWidths[i] * pixelsPerMm;
    }

    int totalTableWidth = 0;
    for (int i = 0; i < numColumns; ++i) {
        totalTableWidth += colWidths[i];
    }
    int tableStartX = (pageWidth - totalTableWidth) / 2;

    QLinearGradient tableHeaderGradient(QPointF(tableStartX, y), QPointF(tableStartX, y + 45));
    tableHeaderGradient.setColorAt(0, QColor(52, 73, 94));
    tableHeaderGradient.setColorAt(1, QColor(44, 62, 80));

    painter.setFont(QFont("Arial", 10, QFont::Bold));
    int x = tableStartX;

    painter.fillRect(QRect(tableStartX, y, totalTableWidth, 45), tableHeaderGradient);

    painter.setPen(Qt::white);
    for (int i = 0; i < numColumns; ++i) {
        QRect headerCell(x, y, colWidths[i], 45);

        painter.setPen(QPen(QColor(200, 200, 200)));
        painter.drawLine(x + colWidths[i], y, x + colWidths[i], y + 45);

        painter.setPen(Qt::white);
        painter.drawText(headerCell.adjusted(10, 0, -10, 0), Qt::AlignVCenter | Qt::AlignLeft, headers[i]);
        x += colWidths[i];
    }
    y += 45;

    QSqlQuery queryProjet;
    queryProjet.prepare(
        "SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, STATUT, "
        "TO_CHAR(DATE_DEBUT, 'DD/MM/YYYY'), TO_CHAR(DATE_FIN, 'DD/MM/YYYY') "
        "FROM GESTION_PROJET "
        "WHERE ID_PROJET IN (" + selectedIdsStr + ") "
                           "ORDER BY ID_PROJET");

    if (!queryProjet.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération des données : " + queryProjet.lastError().text());
        return;
    }

    int rowCount = 0;
    while (queryProjet.next()) {
        progress.setValue(rowCount++);
        if (progress.wasCanceled()) break;

        int id = queryProjet.value(0).toInt();
        QString nom = queryProjet.value(1).toString();
        QString desc = queryProjet.value(2).toString();
        QString statut = queryProjet.value(3).toString().toUpper();
        QString date_debut = queryProjet.value(4).toString();
        QString date_fin = queryProjet.value(5).toString();

        QColor rowColor;
        if (statut == "EN COURS") {
            rowColor = QColor(235, 245, 251);
        } else if (statut == "TERMINE") {
            rowColor = QColor(235, 251, 238);
        } else if (statut == "SUSPENDU") {
            rowColor = QColor(251, 248, 235);
        } else {
            rowColor = Qt::white;
        }

        int rowHeight = 50;
        QFontMetrics fm(QFont("Arial", 10));

        int descWidth = colWidths[2] - 24;
        QRect descRect = fm.boundingRect(
            QRect(0, 0, descWidth, 2000),
            Qt::TextWordWrap | Qt::AlignLeft | Qt::AlignVCenter,
            desc
            );

        rowHeight = qMax(rowHeight, descRect.height() + 24);
        rowHeight = qMin(rowHeight, 200);

        if (y + rowHeight > pageHeight - margin - 60) {
            drawFooter(&painter, pageNumber, pageWidth, pageHeight, margin);
            pdfWriter.newPage();
            pageNumber++;
            y = margin + 40;
        }

        painter.fillRect(QRect(tableStartX, y, totalTableWidth, rowHeight), rowColor);

        x = tableStartX;
        QString values[] = {QString::number(id), nom, desc, statut, date_debut, date_fin};

        for (int i = 0; i < numColumns; ++i) {
            QRect cellRect(x, y, colWidths[i], rowHeight);

            painter.setPen(QPen(QColor(200, 200, 200)));
            painter.drawRect(cellRect);

            if (i == 3) {
                int indicatorSize = 12;
                int textPadding = 20;
                QRect indicatorRect(x + 10, y + (rowHeight - indicatorSize) / 2, indicatorSize, indicatorSize);

                QColor statusColor;
                if (statut == "EN COURS") {
                    statusColor = QColor(52, 152, 219);
                } else if (statut == "TERMINE") {
                    statusColor = QColor(46, 204, 113);
                } else if (statut == "SUSPENDU") {
                    statusColor = QColor(241, 196, 15);
                } else {
                    statusColor = QColor(231, 76, 60);
                }

                painter.save();
                painter.setPen(Qt::NoPen);
                painter.setBrush(statusColor);
                painter.drawEllipse(indicatorRect);
                painter.restore();

                painter.setPen(statusColor);
                QRect textRect = cellRect.adjusted(textPadding + 10, 0, -10, 0);
                painter.drawText(textRect, Qt::AlignVCenter | Qt::AlignLeft, statut);
            } else if (i == 2) {
                QTextOption options;
                options.setWrapMode(QTextOption::WordWrap);
                options.setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

                painter.save();
                painter.setPen(QColor(80, 80, 80));
                painter.drawText(cellRect.adjusted(12, 8, -12, -8), desc, options);
                painter.restore();
            } else if (i == 4 || i == 5) {
                painter.save();
                painter.setPen(QColor(150, 150, 150));
                QRect calendarRect(x + 10, y + (rowHeight - 14) / 2, 14, 14);
                painter.drawRect(calendarRect);
                painter.drawLine(calendarRect.left(), calendarRect.top() + 4, calendarRect.right(), calendarRect.top() + 4);

                QRect textRect = cellRect.adjusted(30, 0, -10, 0);
                QString displayText = fm.elidedText(values[i], Qt::ElideRight, textRect.width());
                painter.setPen(Qt::black);
                painter.drawText(textRect, Qt::AlignVCenter | Qt::AlignLeft, displayText);
                painter.restore();
            } else {
                painter.setPen(Qt::black);
                QRect textRect = cellRect.adjusted(10, 0, -10, 0);
                QString displayText = fm.elidedText(values[i], Qt::ElideRight, textRect.width());
                painter.drawText(textRect, Qt::AlignVCenter | Qt::AlignLeft, displayText);
            }
            x += colWidths[i];
        }
        y += rowHeight;

        if (y > pageHeight - margin - 50) {
            drawFooter(&painter, pageNumber, pageWidth, pageHeight, margin);

            pdfWriter.newPage();
            pageNumber++;
            y = margin;

            painter.setFont(QFont("Arial", 10, QFont::Bold));
            painter.setPen(Qt::white);
            x = tableStartX;
            for (int i = 0; i < 6; ++i) {
                QRect headerCell(x, y, colWidths[i], 40);
                painter.fillRect(headerCell, QColor(51, 122, 183));
                painter.drawRect(headerCell);
                painter.drawText(headerCell.adjusted(10, 0, -10, 0), Qt::AlignVCenter, headers[i]);
                x += colWidths[i];
            }
            y += 40;
            QFont normalFont("Arial", 10);
            painter.setFont(normalFont);
            painter.setPen(Qt::black);
        }
    }

    drawFooter(&painter, pageNumber, pageWidth, pageHeight, margin);

    painter.end();
    QMessageBox::information(this, tr("Succès"), tr("Le fichier PDF a été généré avec succès."));
}

MainWindow::~MainWindow() {
    delete ui;
}
