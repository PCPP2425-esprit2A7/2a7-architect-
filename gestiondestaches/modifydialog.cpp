#include "modifydialog.h"
#include "ui_modifydialog.h"

ModifyDialog::ModifyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyDialog)
{
    ui->setupUi(this);
}

ModifyDialog::~ModifyDialog()
{
    delete ui;
}

void ModifyDialog::setValues(const QString &mission, const QString &statut, const QString &description,
                             const QDate &dateDebut, const QDate &dateFin)
{
    ui->lineEditMission->setText(mission);
    ui->comboBoxStatut->setCurrentText(statut);
    ui->textEditDescription->setPlainText(description);
    ui->dateEditDebut->setDate(dateDebut);
    ui->dateEditFin->setDate(dateFin);
}

QString ModifyDialog::mission() const {
    return ui->lineEditMission->text();
}

QString ModifyDialog::statut() const {
    return ui->comboBoxStatut->currentText();
}

QString ModifyDialog::description() const {
    return ui->textEditDescription->toPlainText();
}

QDate ModifyDialog::dateDebut() const {
    return ui->dateEditDebut->date();
}

QDate ModifyDialog::dateFin() const {
    return ui->dateEditFin->date();
}
