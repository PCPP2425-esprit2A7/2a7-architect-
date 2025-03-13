#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void btnAjouterClicked();
    void btnSupprimerClicked();
    void btnModifierClicked();

private:
    Ui::MainWindow *ui;
    void afficherTaches();
    bool ajouter(const QString &ID_TACHE, const QString &DATEDEB, const QString &DATEFIN,
                 const QString &MISSION, const QString &STATUT, const QString &DESCRIPTION);
};

#endif // MAINWINDOW_H
