#include "supp.h"
#include "ui_supp.h"

supp::supp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::supp)
{
    ui->setupUi(this);

    // Optionnel : Personnaliser la fenêtre
    this->setWindowTitle("Suppression");
}

supp::~supp()
{
    delete ui;
}
