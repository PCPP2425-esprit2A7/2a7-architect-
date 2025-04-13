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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QGroupBox *groupBox;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_formateur;
    QLineEdit *lineEdit_lieu;
    QDateEdit *lineEdit_dateFin;
    QDateEdit *lineEdit_dateDebut;
    QPushButton *btnAjouter;
    QPushButton *btnAj;
    QLineEdit *lineEdit_prix;
    QLabel *label_10;
    QPushButton *pushButton_6;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *lineEdit_4;
    QLabel *label_17;
    QComboBox *select;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QPushButton *btnPdf;
    QLabel *label_21;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QPushButton *pushButton_7;
    QLabel *label_22;
    QPushButton *afficherStatistiques;
    QPushButton *btnAjouter_2;
    QPushButton *btnAjouter_3;
    QPushButton *btnSupprimer;
    QTableView *tableView;
    QPushButton *maps;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1584, 695);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(-2, 0, 1581, 81));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 80, 241, 591));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(-170, -110, 581, 341));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/res/10.jpeg);\n"
"image: url(:/res/989.png);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(0, 220, 241, 71));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   background-color: rgb(255, 245, 221);\n"
"    color: Black;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"    border: 2px solid #1f618d;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1f618d; /* Bleu encore plus fonc\303\251 au clic */\n"
"    border: 2px solid #154360;\n"
"}\n"
"\n"
"\n"
""));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(0, 300, 241, 71));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   background-color: rgb(255, 245, 221);\n"
"    color: Black;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"    border: 2px solid #1f618d;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1f618d; /* Bleu encore plus fonc\303\251 au clic */\n"
"    border: 2px solid #154360;\n"
"}\n"
"\n"
"\n"
""));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(0, 380, 241, 71));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   background-color: rgb(255, 245, 221);\n"
"    color: Black;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"    border: 2px solid #1f618d;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1f618d; /* Bleu encore plus fonc\303\251 au clic */\n"
"    border: 2px solid #154360;\n"
"}\n"
"\n"
"\n"
""));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(0, 460, 241, 71));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   background-color: rgb(255, 245, 221);\n"
"    color: Black;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"    border: 2px solid #1f618d;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1f618d; /* Bleu encore plus fonc\303\251 au clic */\n"
"    border: 2px solid #154360;\n"
"}\n"
"\n"
"\n"
""));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(300, 180, 321, 471));
        groupBox->setStyleSheet(QString::fromUtf8("/* Style du formulaire */\n"
"QWidget {\n"
"    background-color: #f4f4f4; /* Fond gris clair moderne */\n"
"}\n"
"\n"
"/* Style des champs de saisie (ID, Formateur, Lieu, etc.) */\n"
"QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #3498db; /* Bleu moderne au focus */\n"
"}\n"
"\n"
"/* Style des DateEdit */\n"
"QDateEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 3px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    border: none;\n"
"}\n"
"\n"
"/* Style du QSlider (Prix) */\n"
"QSlider::groove:horizontal {\n"
"    background: #ddd;\n"
"    height: 6px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #3498db;\n"
"    width: 14px;\n"
"    height: 14px;\n"
"    border-radius: 7px;\n"
"    margin: -4px 0;\n"
"}\n"
""
                        "\n"
"/* Style des labels */\n"
"QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 pour un effet pro */\n"
"}\n"
""));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 50, 51, 21));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 120, 81, 31));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 370, 49, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 310, 49, 16));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 180, 71, 31));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 240, 91, 31));
        lineEdit_id = new QLineEdit(groupBox);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(130, 50, 141, 31));
        lineEdit_formateur = new QLineEdit(groupBox);
        lineEdit_formateur->setObjectName("lineEdit_formateur");
        lineEdit_formateur->setGeometry(QRect(130, 240, 141, 31));
        lineEdit_lieu = new QLineEdit(groupBox);
        lineEdit_lieu->setObjectName("lineEdit_lieu");
        lineEdit_lieu->setGeometry(QRect(130, 300, 141, 31));
        lineEdit_dateFin = new QDateEdit(groupBox);
        lineEdit_dateFin->setObjectName("lineEdit_dateFin");
        lineEdit_dateFin->setGeometry(QRect(130, 180, 141, 31));
        lineEdit_dateDebut = new QDateEdit(groupBox);
        lineEdit_dateDebut->setObjectName("lineEdit_dateDebut");
        lineEdit_dateDebut->setGeometry(QRect(130, 120, 141, 31));
        btnAjouter = new QPushButton(groupBox);
        btnAjouter->setObjectName("btnAjouter");
        btnAjouter->setGeometry(QRect(50, 420, 91, 31));
        btnAjouter->setStyleSheet(QString::fromUtf8("#btnAjouter {\n"
"   background-color: rgb(21, 118, 127);\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #219150;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;QPushButton {\n"
"    background-color: #27ae60; /* Vert moderne */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #219150;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton:hover {\n"
"    background-color: #219150;\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"QPushButton:pressed {\n"
"    background-color: #1e8449;\n"
"    border: 2px solid #166735;\n"
"}\n"
"\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"#btnAjouter:hover {\n"
"    background-color: #219150; /* Vert plus fonc\303\251 */\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"#btnAjouter:pres"
                        "sed {\n"
"    background-color: #1e8449; /* Vert encore plus fonc\303\251 */\n"
"    border: 2px solid #166735;\n"
"}\n"
""));
        btnAj = new QPushButton(groupBox);
        btnAj->setObjectName("btnAj");
        btnAj->setGeometry(QRect(180, 420, 91, 31));
        btnAj->setStyleSheet(QString::fromUtf8("#btnAj {\n"
"   background-color: rgb(21, 118, 127);\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #219150;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;QPushButton {\n"
"    background-color: #27ae60; /* Vert moderne */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #219150;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton:hover {\n"
"    background-color: #ff0000;\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"QPushButton:pressed {\n"
"    background-color: #1e8449;\n"
"    border: 2px solid #166735;\n"
"}\n"
"\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"#btnAjr:hover {\n"
"    background-color: #219150; /* Vert plus fonc\303\251 */\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"#btnAj:pressed {\n"
"    "
                        "background-color: #1e8449; /* Vert encore plus fonc\303\251 */\n"
"    border: 2px solid #166735;\n"
"}\n"
""));
        lineEdit_prix = new QLineEdit(groupBox);
        lineEdit_prix->setObjectName("lineEdit_prix");
        lineEdit_prix->setGeometry(QRect(130, 360, 141, 31));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(1450, 10, 91, 51));
        label_10->setStyleSheet(QString::fromUtf8("image: url(:/res/98.png);"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(0, 140, 241, 71));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   background-color: rgb(255, 245, 221);\n"
"    color: Black;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"    border: 2px solid #1f618d;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1f618d; /* Bleu encore plus fonc\303\251 au clic */\n"
"    border: 2px solid #154360;\n"
"}\n"
"\n"
"\n"
""));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 400, 31, 31));
        label_12->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/res/12214354.png);"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 240, 41, 31));
        label_11->setStyleSheet(QString::fromUtf8("image: url(:/res/7891470.png);"));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 320, 41, 31));
        label_13->setStyleSheet(QString::fromUtf8("image: url(:/res/33.png);"));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 480, 41, 31));
        label_14->setStyleSheet(QString::fromUtf8("image: url(:/res/2942499.png);"));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 160, 41, 31));
        label_15->setStyleSheet(QString::fromUtf8("image: url(:/res/16854774.png);"));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(720, 149, 181, 31));
        label_16->setStyleSheet(QString::fromUtf8("/* Style du formulaire */\n"
"QWidget {\n"
"    background-color: #f4f4f4; /* Fond gris clair moderne */\n"
"}\n"
"\n"
"/* Style des champs de saisie (ID, Formateur, Lieu, etc.) */\n"
"QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #3498db; /* Bleu moderne au focus */\n"
"}\n"
"\n"
"/* Style des DateEdit */\n"
"QDateEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 3px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    border: none;\n"
"}\n"
"\n"
"/* Style du QSlider (Prix) */\n"
"QSlider::groove:horizontal {\n"
"    background: #ddd;\n"
"    height: 6px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #3498db;\n"
"    width: 14px;\n"
"    height: 14px;\n"
"    border-radius: 7px;\n"
"    margin: -4px 0;\n"
"}\n"
""
                        "\n"
"/* Style des labels */\n"
"QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 pour un effet pro */\n"
"}\n"
""));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(932, 151, 121, 31));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #3498db; /* Bleu moderne au focus */\n"
"}\n"
"\n"
"/* Style des DateEdit */\n"
"QDateEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 3px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    border: none;\n"
"}\n"
""));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(1160, 150, 91, 31));
        label_17->setStyleSheet(QString::fromUtf8("/* Style du formulaire */\n"
"QWidget {\n"
"    background-color: #f4f4f4; /* Fond gris clair moderne */\n"
"}\n"
"\n"
"/* Style des champs de saisie (ID, Formateur, Lieu, etc.) */\n"
"QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #3498db; /* Bleu moderne au focus */\n"
"}\n"
"\n"
"/* Style des DateEdit */\n"
"QDateEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 3px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    border: none;\n"
"}\n"
"\n"
"/* Style du QSlider (Prix) */\n"
"QSlider::groove:horizontal {\n"
"    background: #ddd;\n"
"    height: 6px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #3498db;\n"
"    width: 14px;\n"
"    height: 14px;\n"
"    border-radius: 7px;\n"
"    margin: -4px 0;\n"
"}\n"
""
                        "\n"
"/* Style des labels */\n"
"QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 pour un effet pro */\n"
"}\n"
""));
        select = new QComboBox(centralwidget);
        select->addItem(QString());
        select->addItem(QString());
        select->setObjectName("select");
        select->setGeometry(QRect(1320, 150, 111, 31));
        select->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"      border: 2px solid #3498db; /* Bleu moderne au focus */\n"
"\n"
"        border: 2px solid #cccccc;\n"
"\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 5px;\n"
"font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 pour un effet pro */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"        border: 2px solid #cccccc;\n"
"\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"     border: 2px solid #cccccc;\n"
"\n"
"}\n"
""));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(1100, 30, 31, 31));
        label_18->setStyleSheet(QString::fromUtf8("image: url(:/res/66.png);\n"
"image: url(:/res/55.png);"));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(690, 20, 51, 41));
        label_19->setStyleSheet(QString::fromUtf8("image: url(:/res/3309927.png);"));
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(300, 110, 251, 71));
        label_20->setStyleSheet(QString::fromUtf8("/* Style du formulaire */\n"
"QWidget {\n"
"    background-color: #f4f4f4; /* Fond gris clair moderne */\n"
"}\n"
"\n"
"/* Style des champs de saisie (ID, Formateur, Lieu, etc.) */\n"
"QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 5px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #3498db; /* Bleu moderne au focus */\n"
"}\n"
"\n"
"/* Style des DateEdit */\n"
"QDateEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    padding: 3px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    border: none;\n"
"}\n"
"\n"
"/* Style du QSlider (Prix) */\n"
"QSlider::groove:horizontal {\n"
"    background: #ddd;\n"
"    height: 6px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #3498db;\n"
"    width: 14px;\n"
"    height: 14px;\n"
"    border-radius: 7px;\n"
"    margin: -4px 0;\n"
"}\n"
""
                        "\n"
"/* Style des labels */\n"
"QLabel {\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50; /* Gris fonc\303\251 pour un effet pro */\n"
"}\n"
""));
        btnPdf = new QPushButton(centralwidget);
        btnPdf->setObjectName("btnPdf");
        btnPdf->setGeometry(QRect(1180, 20, 91, 31));
        btnPdf->setStyleSheet(QString::fromUtf8("#btnPdf {\n"
"   background-color: rgb(21, 118, 127);\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #219150;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;QPushButton {\n"
"    background-color: #27ae60; /* Vert moderne */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #219150;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton:hover {\n"
"    background-color: #219150;\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"QPushButton:pressed {\n"
"    background-color: #1e8449;\n"
"    border: 2px solid #166735;\n"
"}\n"
"\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"#btnPdf:hover {\n"
"    background-color: #219150; /* Vert plus fonc\303\251 */\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"#btnPdf:pressed {\n"
"  "
                        "  background-color: #1e8449; /* Vert encore plus fonc\303\251 */\n"
"    border: 2px solid #166735;\n"
"}\n"
""));
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(550, 110, 71, 71));
        label_21->setStyleSheet(QString::fromUtf8("image: url(:/res/2481936.png);"));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(720, 180, 151, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(1150, 180, 101, 16));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(670, 250, 20, 301));
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(1490, 240, 16, 301));
        line_4->setFrameShape(QFrame::Shape::VLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(720, 200, 731, 20));
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(930, 140, 118, 3));
        line_6->setFrameShape(QFrame::Shape::HLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName("line_7");
        line_7->setGeometry(QRect(1320, 140, 118, 3));
        line_7->setFrameShape(QFrame::Shape::HLine);
        line_7->setFrameShadow(QFrame::Shadow::Sunken);
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName("line_8");
        line_8->setGeometry(QRect(270, 120, 20, 511));
        line_8->setFrameShape(QFrame::Shape::VLine);
        line_8->setFrameShadow(QFrame::Shadow::Sunken);
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(0, 540, 241, 71));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   background-color: rgb(255, 245, 221);\n"
"    color: Black;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #2980b9;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Bleu plus fonc\303\251 au survol */\n"
"    border: 2px solid #1f618d;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1f618d; /* Bleu encore plus fonc\303\251 au clic */\n"
"    border: 2px solid #154360;\n"
"}\n"
"\n"
"\n"
""));
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(20, 560, 31, 31));
        label_22->setStyleSheet(QString::fromUtf8("image: url(:/res/777.png);"));
        afficherStatistiques = new QPushButton(centralwidget);
        afficherStatistiques->setObjectName("afficherStatistiques");
        afficherStatistiques->setGeometry(QRect(790, 20, 131, 31));
        afficherStatistiques->setStyleSheet(QString::fromUtf8("#afficherStatistiques {\n"
"   background-color: rgb(21, 118, 127);\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #219150;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;QPushButton {\n"
"    background-color: #27ae60; /* Vert moderne */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #219150;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton:hover {\n"
"    background-color: #219150;\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"QPushButton:pressed {\n"
"    background-color: #1e8449;\n"
"    border: 2px solid #166735;\n"
"}\n"
"\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"#afficherStatistiques:hover {\n"
"    background-color: #219150; /* Vert plus fonc\303\251 */\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
""
                        "#afficherStatistiques:pressed {\n"
"    background-color: #1e8449; /* Vert encore plus fonc\303\251 */\n"
"    border: 2px solid #166735;\n"
"}\n"
""));
        btnAjouter_2 = new QPushButton(centralwidget);
        btnAjouter_2->setObjectName("btnAjouter_2");
        btnAjouter_2->setGeometry(QRect(50, 610, 141, 31));
        btnAjouter_2->setStyleSheet(QString::fromUtf8("#btnAjouter_2 {\n"
"   background-color: rgb(21, 118, 127);\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #219150;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;QPushButton {\n"
"    background-color: #27ae60; /* Vert moderne */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #219150;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton:hover {\n"
"    background-color: #219150;\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"QPushButton:pressed {\n"
"    background-color: #1e8449;\n"
"    border: 2px solid #166735;\n"
"}\n"
"\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"#btnAjouter_2:hover {\n"
"    background-color: #219150; /* Vert plus fonc\303\251 */\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"#btnAjouter_"
                        "2:pressed {\n"
"    background-color: #1e8449; /* Vert encore plus fonc\303\251 */\n"
"    border: 2px solid #166735;\n"
"}\n"
""));
        btnAjouter_3 = new QPushButton(centralwidget);
        btnAjouter_3->setObjectName("btnAjouter_3");
        btnAjouter_3->setGeometry(QRect(1320, 600, 131, 31));
        btnAjouter_3->setStyleSheet(QString::fromUtf8("#btnAjouter_3 {\n"
"   background-color: rgb(21, 118, 127);\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #219150;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;QPushButton {\n"
"    background-color: #27ae60; /* Vert moderne */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #219150;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton:hover {\n"
"    background-color: #219150;\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"QPushButton:pressed {\n"
"    background-color: #1e8449;\n"
"    border: 2px solid #166735;\n"
"}\n"
"\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"#btnAjouter_3:hover {\n"
"    background-color: #219150; /* Vert plus fonc\303\251 */\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"#btnAjouter_"
                        "3:pressed {\n"
"    background-color: #1e8449; /* Vert encore plus fonc\303\251 */\n"
"    border: 2px solid #166735;\n"
"}\n"
""));
        btnSupprimer = new QPushButton(centralwidget);
        btnSupprimer->setObjectName("btnSupprimer");
        btnSupprimer->setGeometry(QRect(1170, 600, 131, 31));
        btnSupprimer->setStyleSheet(QString::fromUtf8("#btnSupprimer {\n"
"   background-color: rgb(21, 118, 127);\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #219150;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;QPushButton {\n"
"    background-color: #27ae60; /* Vert moderne */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #219150;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton:hover {\n"
"    background-color: #219150;\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"QPushButton:pressed {\n"
"    background-color: #1e8449;\n"
"    border: 2px solid #166735;\n"
"}\n"
"\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"#btnSupprimer:hover {\n"
"    background-color: #219150; /* Vert plus fonc\303\251 */\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"#btnSupprime"
                        "r:pressed {\n"
"    background-color: #1e8449; /* Vert encore plus fonc\303\251 */\n"
"    border: 2px solid #166735;\n"
"}\n"
""));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(730, 250, 711, 271));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #f8f9fa; /* Fond g\303\251n\303\251ral */\n"
"    alternate-background-color: #e9ecef; /* Lignes altern\303\251es */\n"
"    selection-background-color: #007BFF; /* Fond bleu pour la s\303\251lection */\n"
"    selection-color: white; /* Texte blanc quand s\303\251lectionn\303\251 */\n"
"    border: 1px solid #dee2e6; /* Bordure l\303\251g\303\250re */\n"
"    gridline-color: #ced4da; /* Grille plus douce */\n"
"    font-size: 14px; /* Taille de police plus lisible */\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"background-color: rgb(21, 118, 127);/* Fond bleu pour les en-t\303\252tes */\n"
"    color: white; /* Texte blanc */\n"
"    font-weight: bold;\n"
"    padding: 8px;\n"
"    border: 1px solid #0056b3;\n"
"    border-radius: 3px;\n"
"    text-align: center;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 6px;\n"
"    border-bottom: 1px solid #ddd;\n"
"    transition: background 0.3s ease-in-out; /* Animation douc"
                        "e */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #0056b3;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTableView::item:hover {\n"
"    background-color: #d6e4ff; /* Effet de survol */\n"
"}"));
        maps = new QPushButton(centralwidget);
        maps->setObjectName("maps");
        maps->setGeometry(QRect(1010, 20, 91, 31));
        maps->setStyleSheet(QString::fromUtf8("#maps {\n"
"   background-color: rgb(21, 118, 127);\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #219150;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;QPushButton {\n"
"    background-color: #27ae60; /* Vert moderne */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #219150;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton:hover {\n"
"    background-color: #219150;\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"QPushButton:pressed {\n"
"    background-color: #1e8449;\n"
"    border: 2px solid #166735;\n"
"}\n"
"\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"#maps:hover {\n"
"    background-color: #219150; /* Vert plus fonc\303\251 */\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"#maps:pressed {\n"
"    back"
                        "ground-color: #1e8449; /* Vert encore plus fonc\303\251 */\n"
"    border: 2px solid #166735;\n"
"}\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1584, 22));
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
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Clients", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Taches", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Formations", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Projets", nullptr));
        groupBox->setTitle(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "ID :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "DateDebut :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Prix :", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Lieu :", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "DateFin :", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Formateur :", nullptr));
        btnAjouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        btnAj->setText(QCoreApplication::translate("MainWindow", "Annule", nullptr));
        label_10->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Dashbord", nullptr));
        label_12->setText(QString());
        label_11->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
        label_15->setText(QString());
        label_16->setText(QCoreApplication::translate("MainWindow", "Recherch\303\251 Par Lieu :", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Trier Par :", nullptr));
        select->setItemText(0, QCoreApplication::translate("MainWindow", "Date", nullptr));
        select->setItemText(1, QCoreApplication::translate("MainWindow", "Prix", nullptr));

        label_18->setText(QString());
        label_19->setText(QString());
        label_20->setText(QCoreApplication::translate("MainWindow", "   Ajouter Une Formation", nullptr));
        btnPdf->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        label_21->setText(QString());
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Architectes", nullptr));
        label_22->setText(QString());
        afficherStatistiques->setText(QCoreApplication::translate("MainWindow", "Statestique", nullptr));
        btnAjouter_2->setText(QCoreApplication::translate("MainWindow", "Se D\303\251connecter", nullptr));
        btnAjouter_3->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        maps->setText(QCoreApplication::translate("MainWindow", "maps", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
