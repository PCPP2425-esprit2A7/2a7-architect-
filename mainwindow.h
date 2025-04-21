#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "architect.h"
#include <QSortFilterProxyModel>

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
    void on_btnLogout_clicked();
    void on_pdf_clicked();
    void on_tri_currentIndexChanged(const QString &text);
    void on_darkModeBtn_clicked();




private:
    Ui::MainWindow *ui;
    Architect architect; // Instance of the Architect class
    QSortFilterProxyModel *proxyModel;
    bool darkModeEnabled = false;
};

#endif // MAINWINDOW_H
