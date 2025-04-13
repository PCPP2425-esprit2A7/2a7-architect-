#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "formation.h"  // Assure-toi que le fichier d'en-tête Formation est inclus
#include <supp.h>
#include <modifier.h>
#include <QRegularExpression> // Include QRegularExpression
#include <QRegularExpressionValidator>
#include <QDate>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QListWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlDatabase>
#include "dashbord.h"
#include "ui_dashbord.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_dashbord(new dashbord(this))  // Initialisation directe

{
    ui->setupUi(this);
    ui->tableView->setModel(fr.afficherListe());
    ui->lineEdit_4->setPlaceholderText("Rechercher...");

    // Connectez le signal de notification dès l'initialisation
    connect(this, &MainWindow::nouvelleFormationAjoutee, m_dashbord, &dashbord::ajouterNotification);
    // Connectez les autres signaux comme avant
    connect(ui->afficherStatistiques, &QPushButton::clicked,
            this, &MainWindow::afficherStatistiques);
    connect(ui->btnPdf, &QPushButton::clicked,
            this, &MainWindow::on_btnPdf_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked,
            this, &MainWindow::on_pushButton_6_clicked);
}
MainWindow::~MainWindow()
{
    delete ui;

}


// Pour la manipulation des dates

void MainWindow::on_btnAjouter_clicked() {
    // Récupérer les valeurs saisies dans les QLineEdits
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

    // Contrôle de saisie pour les dates (format JJ/MM/AAAA)
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

    // Vérifier que la date de début est au moins aujourd'hui
    QDate aujourdhui = QDate::currentDate();  // Récupérer la date d'aujourd'hui
    if (dateDebut < aujourdhui) {
        QMessageBox::warning(this, "Erreur", "La date de début doit être aujourd'hui ou une date future.");
        return;
    }

    // Contrôle de saisie pour le formateur (uniquement des lettres et des espaces)
    QRegularExpression textRegex("^[A-Za-z\\s]+$");
    if (!textRegex.match(formateur).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le champ Formateur ne doit contenir que des lettres.");
        return;
    }

    // Contrôle de saisie pour le lieu (uniquement des lettres et des espaces)
    /*if (!textRegex.match(lieu).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le champ Lieu ne doit contenir que des lettres.");
        return;
    }*/

    // Contrôle de saisie pour le prix (doit être un nombre décimal positif)
    bool prixOk;
    double prix = prixText.toDouble(&prixOk);
    if (!prixOk || prix < 0) {
        QMessageBox::warning(this, "Erreur", "Le prix doit être un nombre décimal positif.");
        return;
    }

    // Si tous les contrôles sont passés, créer l'objet Formation
    Formation f(id, dateDebutText.toStdString(), dateFinText.toStdString(),
                formateur.toStdString(), lieu.toStdString(), prix);

    // Appel de la méthode ajouter() pour insérer la formation dans la base de données
    bool test = f.ajouter();

    // Affichage d'un message de confirmation ou d'erreur en fonction du résultat
    if (test) {
        ui->tableView->setModel(fr.afficherListe());

        // Utiliser QMessageBox de manière modale
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Succès");
        msgBox.setText("Ajout effectué avec succès");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec(); // Utilisation de exec() au lieu de information()
        QString notification = QString("Nouvelle formation ajoutée\n"
                                       "Formateur: %1\n"
                                       "ID: %2\n"
                                       "Lieu: %3")
                                   .arg(QString::fromStdString(f.getFormateur()))
                                   .arg(f.getId())
                                   .arg(QString::fromStdString(f.getLieu()));

        // Émettez toujours le signal
        emit nouvelleFormationAjoutee(notification);

        // Réinitialisation
        ui->lineEdit_id->clear();
        ui->lineEdit_formateur->clear();
        ui->lineEdit_lieu->clear();
        ui->lineEdit_prix->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "Ajout non effectué");
    }
}
void MainWindow::on_btnSupprimer_clicked()
{
    /*supp *suppWindow = new supp(this); // Passer l'instance actuelle*/
    supp *suppWindow = new supp(this); // Création avec this pour gestion mémoire automatique
    connect(suppWindow, &supp::suppressionEffectuee, this, [=]() {
        ui->tableView->setModel(fr.afficherListe()); // Mise à jour du tableView
    });
    suppWindow->show();
    this->hide(); // Cacher MainWindow au lieu de la fermer
}

void MainWindow::on_btnAjouter_3_clicked()
{
    //modifier *modifierWindow = new modifier(); // Créer une instance de la fenêtre supp
    modifier *modifierWindow = new modifier(this); // Création avec this pour gestion mémoire automatique
    connect(modifierWindow, &modifier::modifierrr, this, [=]() {
        ui->tableView->setModel(fr.afficherListe()); // Mise à jour du tableView
    });
    modifierWindow->setModal(true);
    modifierWindow->exec();
    delete modifierWindow; // Libération mémoire après fermeture

}


void MainWindow::on_btnPdf_clicked()
{
    // Récupérer la liste des formations existantes
    QSqlQuery query("SELECT ID_FORMATION, FORMATEUR, PRIX FROM FORMATION");

    // Créer une liste pour stocker les formations
    QStringList formations;
    while (query.next()) {
        int id = query.value(0).toInt();
        QString formateur = query.value(1).toString();
        formations << QString("ID: %1 - Formateur: %2").arg(id).arg(formateur);
    }

    // Boîte de dialogue personnalisée pour sélectionner plusieurs formations
    QDialog dialog(this);
    dialog.setWindowTitle("Sélectionner des formations");
    QVBoxLayout layout(&dialog);
    QListWidget listWidget(&dialog);

    // Ajouter les formations à la QListWidget
    for (const QString &formation : formations) {
        listWidget.addItem(formation);
    }
    listWidget.setSelectionMode(QAbstractItemView::MultiSelection); // Permettre la sélection multiple

    QPushButton button("Valider", &dialog);
    layout.addWidget(&listWidget);
    layout.addWidget(&button);

    // Liste pour stocker les IDs des formations sélectionnées
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
    pdfWriter.setTitle("Détails des formations"); // Définir le titre du document

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
    QString title = "Détails des formations";
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
    int colWidths[] = {950, 1000, 2100, 1700, 1800, 1800}; // Largeurs des colonnes ajustées
    QString headers[] = {"ID", "Date Debut", "Date Fin", "Formateur", "Lieu", "Prix"};

    // Calculer la position de départ pour centrer le tableau
    int totalTableWidth = 0;
    for (int i = 0; i < 6; ++i) {
        totalTableWidth += colWidths[i];
    }
    int tableStartX = (pdfWriter.width() - totalTableWidth) / 2;

    // Définir la couleur des en-têtes
    painter.setPen(Qt::darkCyan); // Texte en cyan foncé
    painter.setBrush(Qt::darkGreen); // Fond vert foncé pour les en-têtes

    // Dessiner les en-têtes de colonnes
    int x = tableStartX;
    for (int i = 0; i < 6; ++i) {
        painter.drawRect(x, y, colWidths[i], 40); // Cellules plus hautes (40 pixels)
        painter.drawText(x + 10, y + 30, headers[i]); // Texte centré dans la cellule
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

    // Récupérer les données des formations sélectionnées
    QString ids;
    for (int id : selectedIds) {
        ids += QString::number(id) + ",";
    }
    ids.chop(1); // Supprimer la dernière virgule

    QSqlQuery queryFormation;
    queryFormation.prepare(QString("SELECT ID_FORMATION, TO_CHAR(DATEDEBUT, 'DD/MM/YYYY'), TO_CHAR(DATEFIN, 'DD/MM/YYYY'), FORMATEUR, LIEU, PRIX FROM FORMATION WHERE ID_FORMATION IN (%1)").arg(ids));
    queryFormation.exec();

    // Parcourir les résultats de la requête et les écrire dans le PDF
    while (queryFormation.next()) {
        int id = queryFormation.value(0).toInt();
        QString dateDebut = queryFormation.value(1).toString();
        QString dateFin = queryFormation.value(2).toString();
        QString formateur = queryFormation.value(3).toString();
        QString lieu = queryFormation.value(4).toString();
        QString prix = queryFormation.value(5).toString();

        // Dessiner les données de la formation dans les cellules
        x = tableStartX;
        QString values[] = {QString::number(id), dateDebut, dateFin, formateur, lieu, prix};
        for (int i = 0; i < 6; ++i) {
            painter.drawRect(x, y, colWidths[i], 40); // Cellules plus hautes (40 pixels)
            painter.drawText(x + 10, y + 30, values[i]); // Texte centré dans la cellule
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

void MainWindow::on_select_activated(int index)
{
    switch (index) {
    case 0: // Tri par Prix

        trierParDate();
        break;
    case 1: // Tri par Date
        trierParPrix();
        break;
    default:
        // Option par défaut ou non reconnue
        break;
    }
}

// Méthode pour trier par prix
void MainWindow::trierParPrix()
{
    QSqlQueryModel *model = fr.trierParPrix();  // Utiliser la méthode de tri de la classe Formation
    ui->tableView->setModel(model);
}

// Méthode pour trier par date
void MainWindow::trierParDate()
{
    QSqlQueryModel *model = fr.trierParDate();  // Utiliser la méthode de tri de la classe Formation
    ui->tableView->setModel(model);
}




void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    QSqlQueryModel *model = fr.rechercherParLieu(arg1);
    ui->tableView->setModel(model);
}
void MainWindow::afficherStatistiques() {
    // 1. Requête SQL pour obtenir la somme des prix par formateur
    QSqlQuery query;
    if(!query.exec("SELECT FORMATEUR, SUM(PRIX) FROM FORMATION GROUP BY FORMATEUR ORDER BY SUM(PRIX) DESC")) {
        QMessageBox::critical(this, "Erreur", "Erreur SQL: " + query.lastError().text());
        return;
    }

    // 2. Préparation des données
    QMap<QString, double> data; // Utilisation d'une map pour éviter les doublons
    while(query.next()) {
        QString formateur = query.value(0).toString();
        double prixTotal = query.value(1).toDouble();
        data[formateur] = prixTotal;
    }

    if(data.isEmpty()) {
        QMessageBox::information(this, "Info", "Aucune donnée disponible");
        return;
    }

    // 3. Création des graphiques
    // Camembert
    QPieSeries *pieSeries = new QPieSeries();
    for(auto it = data.begin(); it != data.end(); ++it) {
        QString label = QString("%1 (%2 DT)").arg(it.key()).arg(it.value());
        QPieSlice *slice = pieSeries->append(label, it.value());
        slice->setLabelVisible();
    }

    // Graphique à barres
    QBarSeries *barSeries = new QBarSeries();
    QBarSet *barSet = new QBarSet("Prix (DT)");

    QStringList categories;
    for(auto it = data.begin(); it != data.end(); ++it) {
        *barSet << it.value();
        categories << it.key();
    }
    barSeries->append(barSet);

    // 4. Configuration des graphiques
    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Répartition des prix par formateur");
    pieChart->legend()->setAlignment(Qt::AlignRight);

    QChart *barChart = new QChart();
    barChart->addSeries(barSeries);
    barChart->setTitle("Prix des formations par formateur");

    // Configuration des axes pour le graphique à barres
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setTitleText("Formateurs");
    barChart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Prix (DT)");
    barChart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    // 5. Affichage
    QChartView *pieView = new QChartView(pieChart);
    pieView->setRenderHint(QPainter::Antialiasing);

    QChartView *barView = new QChartView(barChart);
    barView->setRenderHint(QPainter::Antialiasing);

    // Fenêtre de visualisation
    QWidget *statsWindow = new QWidget();
    statsWindow->setWindowTitle("Statistiques des formations");
    QHBoxLayout *layout = new QHBoxLayout(statsWindow);
    layout->addWidget(pieView);
    layout->addWidget(barView);
    statsWindow->resize(1200, 600);
    statsWindow->show();
}










/*void MainWindow::onMapClicked(double latitude, double longitude)
{
    // Update the address field with coordinates
    QString coordinates = QString("%1, %2").arg(latitude).arg(longitude);
    ui->lineEdit_lieu->setText(coordinates);

    // You might want to update the current centre's coordinate
    fr.setCoordinate(latitude, longitude);
}
*/
void MainWindow::on_maps_clicked()
{
    Map mapDialog(this);
    connect(&mapDialog, &Map::locationSelected, this, &MainWindow::onMapLocationSelected);
    mapDialog.setupMap();
    mapDialog.loadFormationsToMap();
    mapDialog.exec();
}

void MainWindow::onMapLocationSelected(const QGeoCoordinate &coord)
{
    QString location = QString("%1, %2").arg(coord.latitude()).arg(coord.longitude());
    ui->lineEdit_lieu->setText(location);

    // Also store the coordinate in the Formation object if needed
    fr.setCoordinate(coord.latitude(), coord.longitude());
}
void MainWindow::on_pushButton_6_clicked() {
    m_dashbord->show();
    this->hide();
}
