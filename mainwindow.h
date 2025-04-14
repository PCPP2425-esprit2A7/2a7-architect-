#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QDate>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QTextDocument>
#include <QTextStream>
#include <QFile>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QProgressDialog>
#include <QVBoxLayout>
#include <QButtonGroup>
// Project Headers
#include "gestion_projet.h"
#include "connexion.h"
#include "modifier.h"

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
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_13_clicked();
    void on_modifier_clicked();
    void on_lineEdit_rechercher_textChanged(const QString &arg1);
    void on_comboBox_tri_currentIndexChanged(int index);
    void on_pushButton_pdf_clicked();

private:
    Ui::MainWindow *ui;
    GestionProjet GP;
    QDate startDate;
    QDate endDate;
    void updateDateLabels();
    void drawFooter(QPainter* painter, int pageNumber, int pageWidth, int pageHeight, int margin);
};

#endif // MAINWINDOW_H
