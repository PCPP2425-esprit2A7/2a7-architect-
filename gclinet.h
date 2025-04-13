// Gclinet.h
#ifndef GCLINET_H
#define GCLINET_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QSqlQueryModel>
#include <QItemSelection>
#include "clientmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Gclinet; }
QT_END_NAMESPACE

class Gclinet : public QMainWindow {
    Q_OBJECT

public:
    Gclinet(QWidget *parent = nullptr);
    ~Gclinet();

private slots:
    void on_validerClient_clicked();
    void onTriChanged();
    void on_tableView_clicked(const QModelIndex &index);
    void on_buttonModifier_clicked();
    void on_buttonSupprimer_clicked();
    void on_buttonAnnuler_clicked();

    void on_exportPdfButton_clicked();

    void afficherStatistiquesCompletes();

    void envoyerEmail(const QString& nom, const QString& prenom, const QString& email, const QString& nomProjet);




    void on_pushButton_envoyerMail_clicked();

private:
    Ui::Gclinet *ui;
    QSystemTrayIcon *trayIcon;
    ClientManager Client;

    int currentSelectedId = -1;
    QString lastNom, lastPrenom, lastEmail, lastNumTlf;
    int lastNbProjet = 0;

    void remplirChampsDepuisIndex(const QModelIndex &index);
    bool hasModifications() const;
};

#endif // GCLINET_H
