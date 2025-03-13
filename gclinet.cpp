#include "gclinet.h"
#include "clientmanager.h"
#include "./ui_gclinet.h"
#include "supp.h"
#include "modifc.h"
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QListWidget>

Gclinet::Gclinet(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gclinet)
    , trayIcon(new QSystemTrayIcon(this)) // Initialisation


{

    ui->setupUi(this);
    qDebug() << "UI setup completed!";

    if (!ui) {
        qDebug() << "Erreur : ui n'a pas été alloué correctement.";
    }
    if (!parent) {
        qDebug() << "Attention : parent est nul.";
    }

    trayIcon->setIcon(QIcon(":/res/11.jpg")); // Icône personnalisée
    trayIcon->show(); // Affiche l'icône dans la barre système



     // Connexion du signal du combobox au slot pour le tri
    connect(ui->tri, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Gclinet::onTriChanged);


    connect(ui->buttonRechercher, &QPushButton::clicked, this, [this]() {
        QString prenom = ui->lineEditPrenom->text();
        QSqlQueryModel *model = Client.rechercherParPrenom(prenom);
        ui->tableView->setModel(model);
    });

    ui->stackedWidget->setCurrentWidget(ui->page);

    // Set placeholder text for search
    ui->lineEditPrenom->setPlaceholderText("Recherher..."); 
    // Active les couleurs alternées pour les lignes
    ui->tableView->setAlternatingRowColors(true);
    //initialisation d'affichage
    ui->tableView->setModel(Client.afficher("ASC")); // Tri par défaut croissant


}

Gclinet::~Gclinet()
{
    delete trayIcon;  // Libérer la mémoire
    delete ui;
}

void Gclinet::showNotification(QString message, QString titre, QSystemTrayIcon::MessageIcon icon)
{
    trayIcon->showMessage(titre, message, icon, 3000); // Notification pendant 3 secondes
}

void Gclinet::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);

}


void Gclinet::onTriChanged(int index) {
    QString ordre = (index == 0) ? "ASC" : "DESC"; // 0 = Croissant, 1 = Décroissant
    ui->tableView->setModel(Client.afficher(ordre)); // Met à jour le QTableView
}

void Gclinet::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
}


void Gclinet::on_validerClient_clicked()
{
    // Récupération des informations
    QString idStr = ui->IDC->text();
    QString nom = ui->nomClient_2->text();
    QString prenom = ui->prenomClient_2->text();
    QString email = ui->emailClient_2->text();
    QString num_tlf = ui->numClient_2->text();
    int nb_projet = ui->nbcProjet_2->value();  // Récupérer la valeur du QSlider

    // Vérifier si tous les champs obligatoires sont remplis
    if (idStr.isEmpty() || nom.isEmpty() || prenom.isEmpty() || email.isEmpty() || num_tlf.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    // Vérifier si l'ID est un entier valide
    bool conversionOk;
    int id_client = idStr.toInt(&conversionOk);
    if (!conversionOk) {
        QMessageBox::warning(this, "ID invalide", "L'ID doit être un nombre entier.");
        return;
    }

    // Vérifier si l'ID existe déjà dans la base de données
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Client WHERE id_client = :id_client");
    query.bindValue(":id_client", id_client);
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la vérification de l'ID.");
        return;
    }
    query.next();
    if (query.value(0).toInt() > 0) {
        QMessageBox::warning(this, "ID déjà existant", "L'ID du client existe déjà. Veuillez en choisir un autre.");
        return;
    }

    // Vérifier la validité de l'adresse email
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Email invalide", "Veuillez entrer une adresse email valide.");
        return;
    }

    // Vérifier que le numéro de téléphone contient uniquement des chiffres et a une longueur correcte (8 à 10 chiffres)
    QRegularExpression phoneRegex(R"(^\d{8,10}$)");
    if (!phoneRegex.match(num_tlf).hasMatch()) {
        QMessageBox::warning(this, "Numéro invalide", "Le numéro de téléphone doit contenir entre 8 et 10 chiffres.");
        return;
    }

    // Création de l'objet client
    ClientManager CL(id_client, nom, prenom, email, num_tlf, nb_projet);

    // Ajout du client
    bool test = CL.ajouter();

    if (test) {
        // Rafraîchir l'affichage
        ui->tableView->setModel(Client.afficher());

        QMessageBox::information(this, "Succès", "Ajout effectué avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client.");
    }
}




void Gclinet::on_anuulerClient_clicked()
{
    //QMessageBox::warning(this,"information","cette action va annuler l'ajout de ce clinet" );
    showNotification("Ajout effectué avec succès", "Succès", QSystemTrayIcon::Information);

}



void Gclinet::on_suppclient_clicked()
{

    supp *suppWindow = new supp(this); // Création avec this pour gestion mémoire automatique
    connect(suppWindow, &supp::suppressionEffectuee, this, [=]() {
        ui->tableView->setModel(Client.afficher("ASC")); // Mise à jour du tableView
    });
    suppWindow->setModal(true);
    suppWindow->exec();
    delete suppWindow; // Libération mémoire après fermeture

}


void Gclinet::on_modifierClient_clicked()
{
    modifc *modifcWindow = new modifc(this); // Création avec this pour gestion mémoire automatique
    connect(modifcWindow, &modifc::modificationEffectuee, this, [=]() {
        ui->tableView->setModel(Client.afficher("ASC")); // Mise à jour du tableView
    });
    modifcWindow->setModal(true);
    modifcWindow->exec();
    delete modifcWindow; // Libération mémoire après fermeture
}


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





