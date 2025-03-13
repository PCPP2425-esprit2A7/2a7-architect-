#ifndef SUPP_H
#define SUPP_H

#include <QDialog>

namespace Ui {
class supp;
}

class supp : public QDialog
{
    Q_OBJECT
    signals:
    void suppressionEffectuee();


public:
    explicit supp(QWidget *parent = nullptr);
    ~supp();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::supp *ui;
};

#endif // SUPP_H
