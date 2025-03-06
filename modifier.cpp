#include "modifier.h"
#include "ui_modifier.h"

modifier::modifier(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::modifier)
{
    ui->setupUi(this);

    // Optionnel : Personnaliser la fenêtre
    this->setWindowTitle("Modification");
}

modifier::~modifier()
{
    delete ui;
}
