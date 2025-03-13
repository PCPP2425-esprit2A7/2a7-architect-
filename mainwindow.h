#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <formation.h>
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
    void on_btnAjouter_clicked();  // Déclaration du slot pour le bouton "Ajouter"

    void on_btnSupprimer_clicked();

    void on_btnAjouter_3_clicked();




    void on_btnPdf_clicked();
    //void on_comboBoxTri_currentIndexChanged(int index);  // Slot pour le tri
    void on_select_activated(int index);

private:
    Ui::MainWindow *ui;
    Formation fr;
    void trierParPrix();  // Méthode pour trier par prix
    void trierParDate();  // Méthode pour trier par date
};

#endif // MAINWINDOW_H
