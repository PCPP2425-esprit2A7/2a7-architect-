// Gclinet.cpp
#include "gclinet.h"
#include "ui_gclinet.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QDebug>
//pour le pdf
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QListWidget>


//satats
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

//pour mail

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


Gclinet::Gclinet(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Gclinet), trayIcon(new QSystemTrayIcon(this)) {

    ui->setupUi(this);
    trayIcon->setIcon(QIcon(":/res/11.jpg"));
    trayIcon->show();

    //affichage stats
    connect(ui->buttonStatistique, &QPushButton::clicked, this, &Gclinet::afficherStatistiquesCompletes);


    connect(ui->tri, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Gclinet::onTriChanged);
    connect(ui->buttonRechercher, &QPushButton::clicked, this, [this]() {
        QString prenom = ui->lineEditPrenom->text();
        ui->tableView->setModel(Client.rechercherParPrenom(prenom));
    });
    connect(ui->tableView, &QTableView::clicked, this, &Gclinet::on_tableView_clicked);

    ui->stackedWidget->setCurrentWidget(ui->page);



    ui->lineEditPrenom->setPlaceholderText("Rechercher...");
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setModel(Client.afficher("ASC"));

    ui->buttonModifier->setVisible(false);
    ui->buttonSupprimer->setVisible(false);
    ui->buttonAnnuler->setVisible(false);
}


Gclinet::~Gclinet() {
    delete trayIcon;
    delete ui;
}





//stats

void Gclinet::afficherStatistiquesCompletes() {
    QSqlQuery query;

    QPieSeries *pieSeries = new QPieSeries();
    query.prepare("SELECT prenom, nb_projet FROM client");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération des données.");
        return;
    }

    // Données pour camembert + barres
    QBarSet *barSet = new QBarSet("Nombre de projets");
    QStringList categories;

    int totalProjets = 0;
    QVector<QPair<QString, int>> donnees;

    while (query.next()) {
        QString prenom = query.value(0).toString();
        int nb_projet = query.value(1).toInt();
        totalProjets += nb_projet;
        donnees.append({prenom, nb_projet});

        *barSet << nb_projet;
        categories << prenom;
    }

    // Ajouter les parts avec pourcentage
    for (const auto &d : donnees) {
        double pourcentage = (double(d.second) / totalProjets) * 100.0;
        QPieSlice *slice = pieSeries->append(
            QString("%1 (%2%)").arg(d.first).arg(QString::number(pourcentage, 'f', 1)),
            d.second
            );
        slice->setLabelVisible(true); // rendre visible sur le cercle
    }

    // Camembert
    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Répartition des projets (camembert)");

    QChartView *pieChartView = new QChartView(pieChart);
    pieChartView->setRenderHint(QPainter::Antialiasing);

    // -------- Barres --------
    QBarSeries *barSeries = new QBarSeries();
    barSeries->append(barSet);

    QChart *barChart = new QChart();
    barChart->addSeries(barSeries);
    barChart->setTitle("Nombre de projets par client (barres)");

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    barChart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Projets");
    barChart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    QChartView *barChartView = new QChartView(barChart);
    barChartView->setRenderHint(QPainter::Antialiasing);

    // -------- Fenêtre --------
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Statistiques Complètes");

    QHBoxLayout *layout = new QHBoxLayout(dialog);
    layout->addWidget(pieChartView);
    layout->addWidget(barChartView);

    dialog->resize(1200, 500);
    dialog->exec();
}




void Gclinet::on_validerClient_clicked() {
    int id_client = ui->IDC->text().toInt();
    QString nom = ui->nomClient_2->text();
    QString prenom = ui->prenomClient_2->text();
    QString email = ui->emailClient_2->text();
    QString num_tlf = ui->numClient_2->text();
    int nb_projet = ui->nbcProjet_2->text().toInt();

    if (nom.isEmpty() || prenom.isEmpty() || email.isEmpty() || num_tlf.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs.");
        return;
    }

    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Email invalide", "Veuillez entrer une adresse email valide.");
        return;
    }

    QRegularExpression phoneRegex(R"(^\d{8,10}$)");
    if (!phoneRegex.match(num_tlf).hasMatch()) {
        QMessageBox::warning(this, "Numéro invalide", "Numéro de téléphone incorrect.");
        return;
    }

    ClientManager cl(id_client, nom, prenom, email, num_tlf, nb_projet);
    if (cl.ajouter()) {
        ui->tableView->setModel(Client.afficher());
        QMessageBox::information(this, "Succès", "Client ajouté avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client.");
    }
}

void Gclinet::onTriChanged() {
    bool asc = (ui->tri->currentIndex() == 0);
    ui->tableView->setModel(Client.trierParNbProjet(asc));
}

void Gclinet::on_tableView_clicked(const QModelIndex &index) {
    remplirChampsDepuisIndex(index);
    currentSelectedId = ui->IDC->text().toInt();
    ui->buttonModifier->setVisible(true);
    ui->buttonSupprimer->setVisible(true);
    ui->buttonAnnuler->setVisible(true);

    lastNom = ui->nomClient_2->text();
    lastPrenom = ui->prenomClient_2->text();
    lastEmail = ui->emailClient_2->text();
    lastNumTlf = ui->numClient_2->text();
    lastNbProjet = ui->nbcProjet_2->text().toInt();
}

void Gclinet::remplirChampsDepuisIndex(const QModelIndex &index) {
    QAbstractItemModel *model = ui->tableView->model();
    ui->IDC->setText(model->index(index.row(), 0).data().toString());
    ui->nomClient_2->setText(model->index(index.row(), 1).data().toString());
    ui->prenomClient_2->setText(model->index(index.row(), 2).data().toString());
    ui->emailClient_2->setText(model->index(index.row(), 3).data().toString());
    ui->numClient_2->setText(model->index(index.row(), 4).data().toString());
    ui->nbcProjet_2->setText(model->index(index.row(), 5).data().toString());
}

bool Gclinet::hasModifications() const {
    return lastNom != ui->nomClient_2->text() ||
           lastPrenom != ui->prenomClient_2->text() ||
           lastEmail != ui->emailClient_2->text() ||
           lastNumTlf != ui->numClient_2->text() ||
           lastNbProjet != ui->nbcProjet_2->text().toInt();
}



void Gclinet::on_buttonModifier_clicked() {
    if (!hasModifications()) {
        QMessageBox::information(this, "Aucune modification", "Aucune modification détectée.");
        return;
    }

    // Ensure the fields are not empty
    QString nom = ui->nomClient_2->text();
    QString prenom = ui->prenomClient_2->text();
    QString email = ui->emailClient_2->text();
    QString num_tlf = ui->numClient_2->text();
    int nb_projet = ui->nbcProjet_2->text().toInt();

    if (nom.isEmpty() || prenom.isEmpty() || email.isEmpty() || num_tlf.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs.");
        return;
    }

    // Check if email is valid
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Email invalide", "Veuillez entrer une adresse email valide.");
        return;
    }

    // Check if phone number is valid
    QRegularExpression phoneRegex(R"(^\d{8,10}$)");
    if (!phoneRegex.match(num_tlf).hasMatch()) {
        QMessageBox::warning(this, "Numéro invalide", "Numéro de téléphone incorrect.");
        return;
    }

    // Proceed to modify client
    ClientManager cl(currentSelectedId, nom, prenom, email, num_tlf, nb_projet);
    if (cl.modifier()) {
        ui->tableView->setModel(Client.afficher());
        QMessageBox::information(this, "Succès", "Client modifié avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification.");
    }
}



void Gclinet::on_buttonSupprimer_clicked() {
    if (currentSelectedId == -1) {
        QMessageBox::warning(this, "Sélection nécessaire", "Veuillez sélectionner un client à supprimer.");
        return;
    }

    // Confirm deletion
    if (QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer ce client ?") == QMessageBox::Yes) {
        if (Client.supprimer(currentSelectedId)) {
            ui->tableView->setModel(Client.afficher());
            QMessageBox::information(this, "Succès", "Client supprimé.");
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
        }
    }
}


void Gclinet::on_buttonAnnuler_clicked() {
    ui->IDC->clear();
    ui->nomClient_2->clear();
    ui->prenomClient_2->clear();
    ui->emailClient_2->clear();
    ui->numClient_2->clear();
    ui->nbcProjet_2->clear();
    currentSelectedId = -1;

    ui->buttonModifier->setVisible(false);
    ui->buttonSupprimer->setVisible(false);
    ui->buttonAnnuler->setVisible(false);
}


//pdf

void Gclinet::on_exportPdfButton_clicked()
{
    // Récupérer la liste des clients existants
    QSqlQuery query("SELECT ID_CLIENT, NOM, PRENOM, EMAIL, NUM_TLF, NB_PROJET FROM CLIENT");

    // Créer une liste pour stocker les clients
    QStringList clients;
    while (query.next()) {
        int id = query.value(0).toInt();
        QString nom = query.value(1).toString();
        QString prenom = query.value(2).toString();
        clients << QString("ID: %1 - Nom: %2 %3").arg(id).arg(nom).arg(prenom);
    }

    // Boîte de dialogue personnalisée pour sélectionner plusieurs clients
    QDialog dialog(this);
    dialog.setWindowTitle("Sélectionner des clients");
    QVBoxLayout layout(&dialog);
    QListWidget listWidget(&dialog);

    // Ajouter les clients à la QListWidget
    for (const QString &client : clients) {
        listWidget.addItem(client);
    }
    listWidget.setSelectionMode(QAbstractItemView::MultiSelection); // Permettre la sélection multiple

    QPushButton button("Valider", &dialog);
    layout.addWidget(&listWidget);
    layout.addWidget(&button);

    // Liste pour stocker les IDs des clients sélectionnés
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
    pdfWriter.setTitle("Détails des clients"); // Définir le titre du document

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
    QString title = "Détails des clients";
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
    QString headers[] = {"ID", "Nom", "Prénom", "Email", "Téléphone", "Nombre de projets"};

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

    // Récupérer les données des clients sélectionnés
    QString ids;
    for (int id : selectedIds) {
        ids += QString::number(id) + ",";
    }
    ids.chop(1); // Supprimer la dernière virgule

    QSqlQuery queryClient;
    queryClient.prepare(QString("SELECT ID_CLIENT, NOM, PRENOM, EMAIL, NUM_TLF, NB_PROJET FROM CLIENT WHERE ID_CLIENT IN (%1)").arg(ids));
    queryClient.exec();

    // Parcourir les résultats de la requête et les écrire dans le PDF
    while (queryClient.next()) {
        int id = queryClient.value(0).toInt();
        QString nom = queryClient.value(1).toString();
        QString prenom = queryClient.value(2).toString();
        QString email = queryClient.value(3).toString();
        QString num_tlf = queryClient.value(4).toString();
        QString nb_projet = queryClient.value(5).toString();

        // Dessiner les données du client dans les cellules
        x = tableStartX;
        QString values[] = {QString::number(id), nom, prenom, email, num_tlf, nb_projet};
        for (int i = 0; i < 6; ++i) {
            painter.drawRect(x, y, colWidths[i], 40); // Cellules plus hautes (40 pixels)
            painter.drawText(x + 10, y + 30, values[i]); // Texte centré dans la cellule
            x += colWidths[i];
        }
        y += 600; // Espacement entre les lignés

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


void Gclinet::on_pushButton_envoyerMail_clicked() {
    QSqlQuery query;
    query.prepare(R"(
        SELECT c.NOM, c.PRENOM, c.EMAIL, p.NOM_PROJET
        FROM CLIENT c
        JOIN PROJET p ON c.ID_CLIENT = p.ID_CLIENT
        WHERE p.STATUT = 'terminee'
    )");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        return;
    }

    bool emailsEnvoyes = false;
    while (query.next()) {
        QString nom = query.value(0).toString();
        QString prenom = query.value(1).toString();
        QString email = query.value(2).toString();
        QString nomProjet = query.value(3).toString();

        // Appel de la fonction pour envoyer l'email
        envoyerEmail(nom, prenom, email, nomProjet);
        emailsEnvoyes = true;
    }

    if (emailsEnvoyes) {
        QMessageBox::information(this, "Fait", "Les emails ont été envoyés aux clients concernés.");
    } else {
        QMessageBox::information(this, "Aucun projet terminé", "Aucun client n'a de projet terminé.");
    }
}

void Gclinet::envoyerEmail(const QString& nom, const QString& prenom, const QString& email, const QString& nomProjet) {

    QString fromEmail = "aminzomita56@gmail.com";  // L'email validé chez SendGrid

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QUrl url("https://api.sendgrid.com/v3/mail/send");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer " + apiKey.toUtf8());

    // Construction du JSON
    QJsonObject json;
    QJsonObject from;
    from["email"] = fromEmail;
    from["name"] = "Gestion Client";
    json["from"] = from;

    QJsonArray personalizations;
    QJsonObject personalization;
    QJsonArray to;
    QJsonObject toEmail;
    toEmail["email"] = email;
    toEmail["name"] = nom + " " + prenom;
    to.append(toEmail);
    personalization["to"] = to;
    personalization["subject"] = "Validation de votre projet terminé !";
    personalizations.append(personalization);
    json["personalizations"] = personalizations;

    QJsonObject content;
    content["type"] = "text/plain";
    content["value"] = "aslemma ya hmema " + prenom + ",\n\nVotre projet \"" + nomProjet + "\" est maintenant terminé.\naychek ala thi9a teek.\n\nyaatk **** ,\nL’équipe Gestion Client ely dima lehya bik";
    QJsonArray contents;
    contents.append(content);
    json["content"] = contents;

    QJsonDocument doc(json);

    // Envoi de la requête
    QNetworkReply* reply = manager->post(request, doc.toJson());

    // Traitement de la réponse
    connect(reply, &QNetworkReply::finished, this, [reply, nom, prenom, email]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "[SUCCÈS] Email envoyé à" << nom << prenom << "(" << email << ")";
        } else {
            qDebug() << "[ÉCHEC] Erreur lors de l'envoi à" << nom << prenom << ":" << reply->errorString();
        }
        reply->deleteLater();
    });
}



