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
    } else {
        qDebug() << "Échec de la connexion à amin_connction.";
        return -1;
    }

    qDebug() << "Pilotes disponibles :" << QSqlDatabase::drivers();

    // Créer les fenêtres
    MainWindow w;
    dashbord dashboard(&w); // Passer MainWindow comme parent

    // Connecter le signal returnRequested du tableau de bord pour afficher MainWindow
    QObject::connect(&dashboard, &dashbord::returnRequested, [&w]() {
        w.show();
    });

    // Afficher le tableau de bord en premier
    dashboard.show();

    return a.exec();
}
