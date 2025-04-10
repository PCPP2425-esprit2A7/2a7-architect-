#include "dashbord.h"
#include "ui_dashbord.h"

dashbord::dashbord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dashbord)
{
    ui->setupUi(this);
}

dashbord::~dashbord()
{
    delete ui;
}
