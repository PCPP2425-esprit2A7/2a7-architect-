#ifndef MODIFIER_H
#define MODIFIER_H

#include <QDialog>

namespace Ui {
class modifier;
}

class modifier : public QDialog
{
    Q_OBJECT
signals:
    void modifierrr();
public:
    explicit modifier(QWidget *parent = nullptr);
    ~modifier();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::modifier *ui;
};

#endif // MODIFIER_H
