#ifndef MODIFC_H
#define MODIFC_H

#include <QDialog>

namespace Ui {
class modifc;
}

class modifc : public QDialog
{
    Q_OBJECT
signals:
    void modificationEffectuee();

public:
    explicit modifc(QWidget *parent = nullptr);
    ~modifc();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::modifc *ui;
};

#endif // MODIFC_H
