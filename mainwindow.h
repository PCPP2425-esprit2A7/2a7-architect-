#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDate>  // Ajoutez cette ligne
#include <QMainWindow>
#include <formation.h>
#include <QSqlError>  // Doit être avant toute utilisation de QSqlError
#include <QSqlQuery>
#include <QSqlDatabase>
#include "ui_dashbord.h"
#include "dashbord.h"
#include "map.h"
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
    const QStringList& pendingNotifications() const { return m_pendingNotifications; }
    void clearPendingNotifications() { m_pendingNotifications.clear(); }
private slots:
    void on_btnAjouter_clicked();
    void on_btnSupprimer_clicked();
    void on_btnAjouter_3_clicked();
    void on_btnPdf_clicked();
    void on_select_activated(int index);
    void on_lineEdit_4_textChanged(const QString &arg1);
    void afficherStatistiques(); // Ajout de la déclaration du slot



    void on_maps_clicked();

    void on_pushButton_6_clicked();
    void onMapLocationSelected(const QGeoCoordinate &coord);

private:
    Ui::MainWindow *ui;
    Formation fr;
    void trierParPrix();  // Méthode pour trier par prix
    void trierParDate();  // Méthode pour trier par date
    QWidget *dashboardWidget;  // Pointeur vers le dashboard
    Ui::dashbord dashboardUi;  // Interface du dashboard
    Map *mapWidget;
    dashbord *m_dashbord = nullptr;
    void highlightNewRow(int id);
    QStringList m_pendingNotifications;
signals:
 void nouvelleFormationAjoutee(const QString &message); // Déjà présent
};

#endif // MAINWINDOW_H
