#include "mainwindow.h"
#include <QDebug>
#include <QSqlDatabase>
#include "connexion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connexion c;
    qDebug() << "Tentative de connexion...";

    if (c.ouvrirConnexion()) {
        qDebug() << "Connexion à abdallah_connction réussie.";
        // Affichage de l'interface utilisateur après une connexion réussie
        //w.show();
    } else {
        qDebug() << "Échec de la connexion à amin_connction.";
        return -1;  // Arrête l'application si la connexion échoue
    }

    // Ce code est exécuté après l'affichage de l'interface utilisateur
    qDebug() << "Pilotes disponibles :" << QSqlDatabase::drivers();
    MainWindow w;
    w.show();


    return a.exec();  // Démarre la boucle d'événements Qt
}
