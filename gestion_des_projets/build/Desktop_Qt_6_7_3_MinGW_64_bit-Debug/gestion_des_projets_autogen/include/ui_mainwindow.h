/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListView *listView;
    QListView *listView_2;
    QPushButton *Projets;
    QPushButton *Formations;
    QPushButton *Taches;
    QPushButton *Clients;
    QPushButton *Dashboard;
    QListView *listView_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QDateEdit *dateEdit;
    QComboBox *comboBox;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QListView *listView_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QLabel *label_8;
    QComboBox *comboBox_2;
    QPushButton *pushButton_11;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *pushButton_12;
    QLabel *label_16;
    QPushButton *pushButton_13;
    QGroupBox *groupBox;
    QPushButton *pushButton_14;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1279, 811);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        listView = new QListView(centralwidget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(0, 0, 1281, 141));
        listView->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);"));
        listView_2 = new QListView(centralwidget);
        listView_2->setObjectName("listView_2");
        listView_2->setGeometry(QRect(0, 140, 256, 651));
        listView_2->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);"));
        Projets = new QPushButton(centralwidget);
        Projets->setObjectName("Projets");
        Projets->setGeometry(QRect(30, 630, 181, 101));
        Projets->setStyleSheet(QString::fromUtf8("font: 900 italic 9pt \"Segoe UI\";\n"
"background-color: rgb(255, 245, 221);"));
        Formations = new QPushButton(centralwidget);
        Formations->setObjectName("Formations");
        Formations->setGeometry(QRect(30, 500, 181, 101));
        Formations->setStyleSheet(QString::fromUtf8("font: 900 italic 9pt \"Segoe UI\";\n"
"background-color: rgb(255, 245, 221);"));
        Taches = new QPushButton(centralwidget);
        Taches->setObjectName("Taches");
        Taches->setGeometry(QRect(30, 380, 181, 101));
        Taches->setStyleSheet(QString::fromUtf8("font: 900 italic 9pt \"Segoe UI\";\n"
"background-color: rgb(255, 245, 221);"));
        Clients = new QPushButton(centralwidget);
        Clients->setObjectName("Clients");
        Clients->setGeometry(QRect(30, 260, 181, 101));
        Clients->setStyleSheet(QString::fromUtf8("font: 900 italic 9pt \"Segoe UI\";\n"
"background-color: rgb(255, 245, 221);"));
        Dashboard = new QPushButton(centralwidget);
        Dashboard->setObjectName("Dashboard");
        Dashboard->setGeometry(QRect(30, 150, 181, 101));
        Dashboard->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"font: 900 italic 9pt \"Segoe UI\";"));
        listView_3 = new QListView(centralwidget);
        listView_3->setObjectName("listView_3");
        listView_3->setGeometry(QRect(300, 220, 351, 511));
        listView_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 270, 71, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(310, 330, 81, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(310, 560, 91, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(310, 500, 91, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(310, 390, 91, 20));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(400, 270, 113, 26));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(410, 330, 113, 26));
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(410, 550, 110, 26));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(410, 500, 76, 26));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(410, 380, 171, 101));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(340, 680, 93, 29));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(480, 680, 93, 29));
        listView_4 = new QListView(centralwidget);
        listView_4->setObjectName("listView_4");
        listView_4->setGeometry(QRect(690, 260, 561, 391));
        listView_4->setStyleSheet(QString::fromUtf8(""));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(270, 160, 131, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 900 italic 9pt \"Segoe UI\";"));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(400, 160, 131, 61));
        pushButton_9->setStyleSheet(QString::fromUtf8("font: 900 italic 9pt \"Segoe UI\";"));
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(530, 160, 131, 61));
        pushButton_10->setStyleSheet(QString::fromUtf8("font: 900 italic 9pt \"Segoe UI\";"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(700, 220, 151, 20));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(850, 220, 113, 26));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(1010, 220, 71, 20));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(1080, 220, 76, 26));
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(1050, 660, 81, 71));
        pushButton_11->setStyleSheet(QString::fromUtf8("image: url(:/img/C:/Users/amirs/OneDrive/Bureau/imggg/9.png);"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(1170, 30, 81, 81));
        label_9->setStyleSheet(QString::fromUtf8("image: url(:/img/C:/Users/amirs/OneDrive/Bureau/imggg/2.png);"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(30, 180, 61, 41));
        label_10->setStyleSheet(QString::fromUtf8("image: url(:/img/C:/Users/amirs/OneDrive/Bureau/imggg/8.png);"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 290, 91, 41));
        label_11->setStyleSheet(QString::fromUtf8("image: url(:/img/C:/Users/amirs/OneDrive/Bureau/imggg/6.png);"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 410, 81, 41));
        label_12->setStyleSheet(QString::fromUtf8("image: url(:/img/C:/Users/amirs/OneDrive/Bureau/imggg/1.png);"));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 530, 91, 41));
        label_13->setStyleSheet(QString::fromUtf8("image: url(:/img/C:/Users/amirs/OneDrive/Bureau/imggg/7.png);"));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 660, 91, 41));
        label_14->setStyleSheet(QString::fromUtf8("image: url(:/img/C:/Users/amirs/OneDrive/Bureau/imggg/4.png);"));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(290, 130, 81, 51));
        label_15->setStyleSheet(QString::fromUtf8("image: url(:/img/C:/Users/amirs/OneDrive/Bureau/imggg/3.png);"));
        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(790, 660, 93, 71));
        pushButton_12->setStyleSheet(QString::fromUtf8("image: url(:/img/C:/Users/amirs/OneDrive/Bureau/imggg/5.png);"));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(-30, -90, 301, 321));
        label_16->setStyleSheet(QString::fromUtf8("image: url(:/img/C:/Users/amirs/Downloads/WhatsApp_Image_2025-01-29_at_7.59.54_PM-removebg-preview.png);"));
        pushButton_13 = new QPushButton(centralwidget);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(310, 600, 161, 29));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(480, 590, 120, 41));
        pushButton_14 = new QPushButton(centralwidget);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(600, 600, 21, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1279, 26));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Projets->setText(QCoreApplication::translate("MainWindow", "Projets", nullptr));
        Formations->setText(QCoreApplication::translate("MainWindow", "      Formations", nullptr));
        Taches->setText(QCoreApplication::translate("MainWindow", "Taches", nullptr));
        Clients->setText(QCoreApplication::translate("MainWindow", "Clients", nullptr));
        Dashboard->setText(QCoreApplication::translate("MainWindow", "  Dashboard", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "id projet :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "nom projet :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Date debut :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Status :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Description :", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("MainWindow", "c'est la description du projet", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Ajouter Projet", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Modifier Projet", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Supprimer Projet", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Rechercher par Nom :", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Trier par :", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Nom", nullptr));

        pushButton_11->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
        label_15->setText(QString());
        pushButton_12->setText(QString());
        label_16->setText(QString());
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "G\303\251n\303\251rer la date de fin :", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Date fin :", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
