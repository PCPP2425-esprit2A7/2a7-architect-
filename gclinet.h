#ifndef GCLINET_H
#define GCLINET_H

#include <QMainWindow>
#include "clientmanager.h"
#include"QMessageBox"
#include <QSystemTrayIcon>

QT_BEGIN_NAMESPACE
namespace Ui {
class Gclinet;
}
QT_END_NAMESPACE

class Gclinet : public QMainWindow
{
    Q_OBJECT

public:
    Gclinet(QWidget *parent = nullptr);
    ~Gclinet();

    void showNotification(QString message, QString titre, QSystemTrayIcon::MessageIcon icon);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_validerClient_clicked();

    void on_anuulerClient_clicked();


    void on_suppclient_clicked();

    void on_modifierClient_clicked();

    void on_exportPdfButton_clicked();

    void onTriChanged(int index);


private:
    Ui::Gclinet *ui;
    ClientManager Client;  // Déclaration de l'objet
    QSystemTrayIcon *trayIcon;  // Déclaration d'un attribut trayIcon

};
#endif // GCLINET_H
