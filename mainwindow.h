#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "architect.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();
    void refreshTable();
    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Architect architect; // Instance of the Architect class
};

#endif // MAINWINDOW_H
