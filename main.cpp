#include "gclinet.h"
#include "connexion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connexion c; //une seule instance de la classe connexion

    qDebug() << "Tentative de connexion...";
    if (c.ouvrirConnexion()) {
        qDebug() << "Connexion a formation reussie.";
    } else {
        qDebug() << "echec de la connexion a amin_connction.";
        return -1;  // Arrête l'application si la connexion échoue
    }

    Gclinet w;
    w.show();
    return a.exec();
}
