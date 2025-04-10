#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gestion_projet.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_13_clicked();
    void on_modifier_clicked();
    void on_lineEdit_rechercher_textChanged(const QString &arg1);
    void on_comboBox_tri_currentIndexChanged(int index);
    void on_pushButton_pdf_clicked();

private:
    Ui::MainWindow *ui;
    GestionProjet GP;
};

#endif // MAINWINDOW_H
