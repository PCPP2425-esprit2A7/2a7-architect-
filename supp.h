#ifndef SUPP_H
#define SUPP_H

#include <QDialog>
#include "mainwindow.h"
#include "formation.h"  // Ajoute cette ligne

namespace Ui {
class supp;
}

class supp : public QDialog
{
    Q_OBJECT
signals:
    void suppressionEffectuee();
public:
    explicit supp(MainWindow *mainWin, QWidget *parent = nullptr);  // Modifie le constructeur
    ~supp();

private slots:
    void on_btnSupprimer_clicked();
    void on_pushButtonanuul_clicked();

private:
    Ui::supp *ui;
    MainWindow *mainWindow; // Ajoute un pointeur vers MainWindow
    Formation fr; // Instance de la classe Formation
};

#endif // SUPP_H
