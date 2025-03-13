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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView_2;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QLabel *label_24;
    QLabel *label_3;
    QLabel *label_14;
    QLabel *label_10;
    QPushButton *btnAjouter;
    QLabel *label_22;
    QLineEdit *LINE_EDIT_ID_TACHE;
    QPushButton *btnPDF;
    QComboBox *comboBox_2;
    QLabel *label;
    QLabel *label_13;
    QLabel *label_16;
    QComboBox *COMBO_BOX_STATUT;
    QPushButton *btnModifier;
    QPushButton *pushButton_4;
    QLabel *label_11;
    QLabel *label_2;
    QPushButton *btnSupprimer;
    QPushButton *pushButton;
    QGraphicsView *graphicsView;
    QLabel *label_7;
    QLabel *label_21;
    QPushButton *pushButton_3;
    QLabel *label_6;
    QPushButton *pushButton_6;
    QLabel *label_15;
    QLabel *label_9;
    QLineEdit *LINE_EDIT_MISSION;
    QLabel *label_12;
    QLabel *label_20;
    QLabel *label_17;
    QDateEdit *DATE_EDIT_DEBUT;
    QLabel *label_4;
    QDateEdit *DATE_EDIT_FIN;
    QLabel *label_18;
    QLineEdit *lineEdit_4;
    QLabel *label_19;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *btnStat;
    QLabel *label_8;
    QTableView *tableView;
    QPlainTextEdit *EDIT_DESCRIPTION;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *btnAnnuler;
    QLabel *label_23;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLineEdit *suppline;
    QLineEdit *modline;
    QLabel *label_36;
    QLabel *label_37;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(894, 613);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView_2 = new QGraphicsView(centralwidget);
        graphicsView_2->setObjectName("graphicsView_2");
        graphicsView_2->setGeometry(QRect(130, 0, 941, 61));
        graphicsView_2->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);\n"
""));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(170, 90, 131, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: italic 12pt \"Segoe UI\";\n"
"color: rgb(21, 118, 127);\n"
""));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 160, 111, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"font: italic 9pt \"Segoe UI\";\n"
""));
        label_24 = new QLabel(centralwidget);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(90, 450, 31, 21));
        label_24->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/1319f4cc41046ac126244d0ef3245b87-removebg-preview.png);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(550, 10, 61, 31));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/images/477607596_596477099948834_7067065610743688655_n-removebg-preview.png);"));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(180, 170, 71, 16));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(21, 118, 127);\n"
"font: 600 9pt \"Segoe UI\";"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(0, 320, 51, 21));
        label_10->setStyleSheet(QString::fromUtf8("image: url(:/images/367371986_358087480090301_3383985156011745966_n.png);"));
        btnAjouter = new QPushButton(centralwidget);
        btnAjouter->setObjectName("btnAjouter");
        btnAjouter->setGeometry(QRect(190, 420, 81, 31));
        btnAjouter->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"font: italic 9pt \"Segoe UI\";\n"
""));
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(780, 470, 61, 31));
        label_22->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/07330b37741337ace891d483cc7cb42c-removebg-preview.png);"));
        LINE_EDIT_ID_TACHE = new QLineEdit(centralwidget);
        LINE_EDIT_ID_TACHE->setObjectName("LINE_EDIT_ID_TACHE");
        LINE_EDIT_ID_TACHE->setGeometry(QRect(240, 140, 113, 22));
        LINE_EDIT_ID_TACHE->setStyleSheet(QString::fromUtf8("border: 2px solid #cccccc;\n"
"border-radius: 8px;"));
        btnPDF = new QPushButton(centralwidget);
        btnPDF->setObjectName("btnPDF");
        btnPDF->setGeometry(QRect(600, 20, 61, 21));
        btnPDF->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"font: italic 9pt \"Segoe UI\";\n"
""));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(740, 140, 81, 22));
        comboBox_2->setStyleSheet(QString::fromUtf8("border: 2px solid #cccccc;\n"
"border-radius: 8px;"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(-130, -60, 381, 211));
        label->setStyleSheet(QString::fromUtf8("image: url(:/images/475119185_1617747645539697_2462832556827082104_n.png);"));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(180, 140, 61, 16));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(21, 118, 127);\n"
"font: 600 9pt \"Segoe UI\";"));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(180, 230, 61, 16));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(21, 118, 127);\n"
"font: 600 9pt \"Segoe UI\";"));
        COMBO_BOX_STATUT = new QComboBox(centralwidget);
        COMBO_BOX_STATUT->addItem(QString());
        COMBO_BOX_STATUT->addItem(QString());
        COMBO_BOX_STATUT->addItem(QString());
        COMBO_BOX_STATUT->setObjectName("COMBO_BOX_STATUT");
        COMBO_BOX_STATUT->setGeometry(QRect(230, 260, 81, 22));
        COMBO_BOX_STATUT->setStyleSheet(QString::fromUtf8("border: 2px solid #cccccc;\n"
"border-radius: 8px;"));
        btnModifier = new QPushButton(centralwidget);
        btnModifier->setObjectName("btnModifier");
        btnModifier->setGeometry(QRect(490, 500, 91, 21));
        btnModifier->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"font: italic 9pt \"Segoe UI\";\n"
""));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 260, 111, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"font: italic 9pt \"Segoe UI\";\n"
""));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(0, 370, 51, 21));
        label_11->setStyleSheet(QString::fromUtf8("image: url(:/images/479516505_526890736583330_638293357505507653_n.png);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(370, 10, 61, 31));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/images/385542126_680655700570078_413661943973173125_n.png);"));
        btnSupprimer = new QPushButton(centralwidget);
        btnSupprimer->setObjectName("btnSupprimer");
        btnSupprimer->setGeometry(QRect(660, 500, 91, 21));
        btnSupprimer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"font: italic 9pt \"Segoe UI\";\n"
""));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 110, 111, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"font: italic 9pt \"Segoe UI\";\n"
""));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 131, 661));
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);\n"
""));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 170, 51, 21));
        label_7->setStyleSheet(QString::fromUtf8("image: url(:/images/476777382_1500858751317521_1233079034650026765_n.png);"));
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(620, 500, 51, 21));
        label_21->setStyleSheet(QString::fromUtf8("image: url(:/img/07330b37741337ace891d483cc7cb42c-removebg-preview.png);"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 210, 111, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"font: italic 9pt \"Segoe UI\";\n"
""));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 120, 51, 21));
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/images/477050281_557493740650231_7827970764697288155_n.png);"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(10, 360, 111, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"font: italic 9pt \"Segoe UI\";\n"
""));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(180, 200, 61, 16));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(21, 118, 127);\n"
"font: 600 9pt \"Segoe UI\";"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(0, 270, 51, 21));
        label_9->setStyleSheet(QString::fromUtf8("image: url(:/images/476914103_2918381941655201_5669318058414440152_n.png);"));
        LINE_EDIT_MISSION = new QLineEdit(centralwidget);
        LINE_EDIT_MISSION->setObjectName("LINE_EDIT_MISSION");
        LINE_EDIT_MISSION->setGeometry(QRect(230, 230, 113, 22));
        LINE_EDIT_MISSION->setStyleSheet(QString::fromUtf8("border: 2px solid #cccccc;\n"
"border-radius: 8px;"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(300, 80, 71, 41));
        label_12->setStyleSheet(QString::fromUtf8("image: url(:/images/476585331_608884388555411_862061415062346978_n.png);"));
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(670, 140, 61, 16));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(21, 118, 127);\n"
"font: 600 9pt \"Segoe UI\";"));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(180, 260, 49, 16));
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(21, 118, 127);\n"
"font: 600 9pt \"Segoe UI\";"));
        DATE_EDIT_DEBUT = new QDateEdit(centralwidget);
        DATE_EDIT_DEBUT->setObjectName("DATE_EDIT_DEBUT");
        DATE_EDIT_DEBUT->setGeometry(QRect(250, 170, 110, 22));
        DATE_EDIT_DEBUT->setStyleSheet(QString::fromUtf8("border: 2px solid #cccccc;\n"
"border-radius: 8px;"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(770, 10, 91, 41));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/images/461833517_463946476660446_4629749051515532142_n.png);"));
        DATE_EDIT_FIN = new QDateEdit(centralwidget);
        DATE_EDIT_FIN->setObjectName("DATE_EDIT_FIN");
        DATE_EDIT_FIN->setGeometry(QRect(240, 200, 110, 22));
        DATE_EDIT_FIN->setStyleSheet(QString::fromUtf8("border: 2px solid #cccccc;\n"
"border-radius: 8px;"));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(180, 290, 71, 16));
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(21, 118, 127);\n"
"font: 600 9pt \"Segoe UI\";"));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(530, 140, 113, 22));
        lineEdit_4->setStyleSheet(QString::fromUtf8("border: 2px solid #cccccc;\n"
"border-radius: 8px;"));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(430, 140, 101, 16));
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(21, 118, 127);\n"
"font: 600 9pt \"Segoe UI\";"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(10, 430, 111, 21));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"font: italic 9pt \"Segoe UI\";\n"
"text-align: left; /* Aligne le texte \303\240 gauche */"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(10, 310, 111, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"font: italic 9pt \"Segoe UI\";\n"
""));
        btnStat = new QPushButton(centralwidget);
        btnStat->setObjectName("btnStat");
        btnStat->setGeometry(QRect(420, 20, 91, 21));
        btnStat->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"font: italic 9pt \"Segoe UI\";\n"
""));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 220, 51, 21));
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/images/477024155_1845634632858108_7086397153038724283_n.png);"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(430, 180, 421, 281));
        EDIT_DESCRIPTION = new QPlainTextEdit(centralwidget);
        EDIT_DESCRIPTION->setObjectName("EDIT_DESCRIPTION");
        EDIT_DESCRIPTION->setGeometry(QRect(180, 310, 211, 101));
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(10, 160, 111, 41));
        pushButton_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"font: italic 9pt \"Segoe UI\";\n"
""));
        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(10, 260, 111, 41));
        pushButton_12->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"font: italic 9pt \"Segoe UI\";\n"
""));
        pushButton_13 = new QPushButton(centralwidget);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(10, 110, 111, 41));
        pushButton_13->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"font: italic 9pt \"Segoe UI\";\n"
""));
        btnAnnuler = new QPushButton(centralwidget);
        btnAnnuler->setObjectName("btnAnnuler");
        btnAnnuler->setGeometry(QRect(290, 420, 81, 31));
        btnAnnuler->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"font: italic 9pt \"Segoe UI\";\n"
""));
        label_23 = new QLabel(centralwidget);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(0, 370, 51, 21));
        label_23->setStyleSheet(QString::fromUtf8("image: url(:/img/479516505_526890736583330_638293357505507653_n.png);"));
        label_25 = new QLabel(centralwidget);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(0, 320, 51, 21));
        label_25->setStyleSheet(QString::fromUtf8("image: url(:/img/367371986_358087480090301_3383985156011745966_n.png);"));
        label_26 = new QLabel(centralwidget);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(0, 270, 51, 21));
        label_26->setStyleSheet(QString::fromUtf8("image: url(:/img/476914103_2918381941655201_5669318058414440152_n.png);"));
        label_27 = new QLabel(centralwidget);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(0, 220, 51, 21));
        label_27->setStyleSheet(QString::fromUtf8("image: url(:/img/477024155_1845634632858108_7086397153038724283_n.png);"));
        label_28 = new QLabel(centralwidget);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(0, 170, 51, 21));
        label_28->setStyleSheet(QString::fromUtf8("image: url(:/img/476777382_1500858751317521_1233079034650026765_n.png);"));
        label_29 = new QLabel(centralwidget);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(0, 120, 51, 21));
        label_29->setStyleSheet(QString::fromUtf8("image: url(:/img/477050281_557493740650231_7827970764697288155_n.png);"));
        label_30 = new QLabel(centralwidget);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(80, 430, 51, 21));
        label_30->setStyleSheet(QString::fromUtf8("image: url(:/img/1319f4cc41046ac126244d0ef3245b87-removebg-preview.png);"));
        label_31 = new QLabel(centralwidget);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(560, 20, 51, 21));
        label_31->setStyleSheet(QString::fromUtf8("image: url(:/img/477607596_596477099948834_7067065610743688655_n-removebg-preview.png);"));
        label_32 = new QLabel(centralwidget);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(380, 20, 51, 21));
        label_32->setStyleSheet(QString::fromUtf8("image: url(:/img/385542126_680655700570078_413661943973173125_n.png);"));
        label_33 = new QLabel(centralwidget);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(300, 80, 81, 51));
        label_33->setStyleSheet(QString::fromUtf8("image: url(:/img/476585331_608884388555411_862061415062346978_n.png);"));
        label_34 = new QLabel(centralwidget);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(-80, -50, 271, 201));
        label_34->setStyleSheet(QString::fromUtf8("image: url(:/img/475119185_1617747645539697_2462832556827082104_n.png);"));
        label_35 = new QLabel(centralwidget);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(800, 10, 61, 41));
        label_35->setStyleSheet(QString::fromUtf8("image: url(:/img/461833517_463946476660446_4629749051515532142_n.png);"));
        suppline = new QLineEdit(centralwidget);
        suppline->setObjectName("suppline");
        suppline->setGeometry(QRect(680, 470, 71, 22));
        modline = new QLineEdit(centralwidget);
        modline->setObjectName("modline");
        modline->setGeometry(QRect(500, 470, 81, 22));
        label_36 = new QLabel(centralwidget);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(620, 470, 61, 16));
        label_36->setStyleSheet(QString::fromUtf8("color: rgb(21, 118, 127);\n"
"font: 600 9pt \"Segoe UI\";"));
        label_37 = new QLabel(centralwidget);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(440, 470, 61, 16));
        label_37->setStyleSheet(QString::fromUtf8("color: rgb(21, 118, 127);\n"
"font: 600 9pt \"Segoe UI\";"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 894, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Ajouter Une Tache", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        label_24->setText(QString());
        label_3->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "Date Debut :", nullptr));
        label_10->setText(QString());
        btnAjouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_22->setText(QString());
        btnPDF->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Id Tache", nullptr));

        label->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Id Tache :", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Mission :", nullptr));
        COMBO_BOX_STATUT->setItemText(0, QCoreApplication::translate("MainWindow", "En cours", nullptr));
        COMBO_BOX_STATUT->setItemText(1, QCoreApplication::translate("MainWindow", "Termin\303\251e ", nullptr));
        COMBO_BOX_STATUT->setItemText(2, QCoreApplication::translate("MainWindow", "En attente", nullptr));

        btnModifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Formation", nullptr));
        label_11->setText(QString());
        label_2->setText(QString());
        btnSupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Dashbord", nullptr));
        label_7->setText(QString());
        label_21->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Tache", nullptr));
        label_6->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Architecte", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Date Fin :", nullptr));
        label_9->setText(QString());
        label_12->setText(QString());
        label_20->setText(QCoreApplication::translate("MainWindow", "Trier  Par :", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Statut :", nullptr));
        label_4->setText(QString());
        label_18->setText(QCoreApplication::translate("MainWindow", "Description :", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Recherche Par ID :", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_7->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Se deconnecter", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Projet", nullptr));
        btnStat->setText(QCoreApplication::translate("MainWindow", "Staistique", nullptr));
        label_8->setText(QString());
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Formation", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Dashbord", nullptr));
        btnAnnuler->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_23->setText(QString());
        label_25->setText(QString());
        label_26->setText(QString());
        label_27->setText(QString());
        label_28->setText(QString());
        label_29->setText(QString());
        label_30->setText(QString());
        label_31->setText(QString());
        label_32->setText(QString());
        label_33->setText(QString());
        label_34->setText(QString());
        label_35->setText(QString());
        label_36->setText(QCoreApplication::translate("MainWindow", "Id Tache :", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "Id Tache :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
