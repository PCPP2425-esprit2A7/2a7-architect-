#ifndef MODIFIER_H
#define MODIFIER_H

#include <QDialog>
#include <QDateEdit>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>

namespace Ui {
class modifier;
}

class modifier : public QDialog
{
    Q_OBJECT

public:
    explicit modifier(QWidget *parent = nullptr, int id = 0, QString nom = "", QString desc = "", QString statut = "", QString date_debut = "", QString date_fin = "");
    ~modifier();

    QString getNom();
    QString getDescription();
    QString getStatut();
    QString getDateDebut();
    QString getDateFin();

signals:
    void projetModifie(); // Signal pour indiquer que le projet a été modifié

private slots:
    void on_pushButton_clicked();

private:
    Ui::modifier *ui;
    int projectId; // ID du projet à modifier
};

#endif // MODIFIER_H
