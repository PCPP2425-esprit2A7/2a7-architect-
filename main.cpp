#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;
    qDebug() << "Tentative de connexion...";
    if (c.ouvrirConnexion()) {
        qDebug() << "Connexion a formation reussie.";
    } else {
        qDebug() << "echec de la connexion a soussou_connction.";
        return -1;  // Arrête l'application si la connexion échoue
    }
    MainWindow w;
    w.show();
    return a.exec();
}
