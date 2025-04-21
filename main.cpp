#include "loginform.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;
    bool test = c.ouvrirConnexion();

    if (test) {
        LoginForm login;
        login.show();
        return a.exec();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Database not open"),
                              QObject::tr("Connection failed.\nClick Cancel to exit."),
                              QMessageBox::Cancel);
        return -1;
    }
}
