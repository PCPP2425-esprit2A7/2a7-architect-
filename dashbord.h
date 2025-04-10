#ifndef DASHBORD_H
#define DASHBORD_H

#include <QDialog>
#include <QDate>  // Ajoutez cette ligne
namespace Ui {
class dashbord;
}

class dashbord : public QDialog
{
    Q_OBJECT

public:
    explicit dashbord(QWidget *parent = nullptr);
    ~dashbord();

private:
    Ui::dashbord *ui;
};

#endif // DASHBORD_H
