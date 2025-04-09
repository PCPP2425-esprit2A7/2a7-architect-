#ifndef MODIFYDIALOG_H
#define MODIFYDIALOG_H

#include <QDialog>
#include <QDate>

namespace Ui {
class ModifyDialog;
}

class ModifyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyDialog(QWidget *parent = nullptr);
    ~ModifyDialog();

    QString mission() const;
    QString statut() const;
    QString description() const;
    QDate dateDebut() const;
    QDate dateFin() const;

    void setValues(const QString &mission, const QString &statut, const QString &description,
                   const QDate &dateDebut, const QDate &dateFin);

private:
    Ui::ModifyDialog *ui;
};

#endif // MODIFYDIALOG_H
