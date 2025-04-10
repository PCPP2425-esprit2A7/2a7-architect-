#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDate>  // Ajoutez cette ligne
#include <QMainWindow>
#include <formation.h>
#include <QSqlError>  // Doit être avant toute utilisation de QSqlError
#include <QSqlQuery>
#include <QSqlDatabase>
#include "ui_dashbord.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAjouter_clicked();
    void on_btnSupprimer_clicked();
    void on_btnAjouter_3_clicked();
    void on_btnPdf_clicked();
    void on_select_activated(int index);
    void on_lineEdit_4_textChanged(const QString &arg1);
    void afficherStatistiques(); // Ajout de la déclaration du slot

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    Formation fr;
    void trierParPrix();  // Méthode pour trier par prix
    void trierParDate();  // Méthode pour trier par date
    QWidget *dashboardWidget;  // Pointeur vers le dashboard
    Ui::dashbord dashboardUi;  // Interface du dashboard

    void highlightNewRow(int id);
signals:
    void nouvelleFormationAjoutee(QString formateur, QString lieu, QDate date);

};

#endif // MAINWINDOW_H
