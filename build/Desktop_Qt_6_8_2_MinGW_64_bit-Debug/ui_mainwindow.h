/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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
    QTableView *tableView;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QGroupBox *groupBox;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_9;
    QLineEdit *lineEdit_6;
    QLabel *label_10;
    QLineEdit *lineEdit_7;
    QLabel *label_11;
    QLineEdit *lineEdit_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QLineEdit *lineEdit_5;
    QComboBox *comboBox;
    QLabel *label_4;
    QLabel *label_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1626, 694);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(580, 190, 891, 381));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(-8, 0, 281, 681));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(242, -11, 1391, 101));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(40, 180, 191, 61));
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
        QIcon icon;
        icon.addFile(QString::fromUtf8("16854774.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(50, 50));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(310, 160, 241, 461));
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
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 410, 83, 29));
        QPalette palette;
        QBrush brush(QColor(244, 244, 244, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_2->setPalette(palette);
        pushButton_2->setStyleSheet(QString::fromUtf8("#btnAjouter {\n"
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
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(140, 410, 83, 29));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_3->setPalette(palette1);
        pushButton_3->setStyleSheet(QString::fromUtf8("#btnAjouter {\n"
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
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(90, 80, 141, 28));
        QPalette palette2;
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lineEdit->setPalette(palette2);
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(90, 130, 141, 28));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lineEdit_2->setPalette(palette3);
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(90, 180, 141, 28));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lineEdit_3->setPalette(palette4);
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(90, 220, 141, 28));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lineEdit_4->setPalette(palette5);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 80, 63, 20));
        label_3->setStyleSheet(QString::fromUtf8("/* Style du formulaire */\n"
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
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 220, 63, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 180, 63, 20));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 130, 63, 20));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 260, 63, 20));
        lineEdit_6 = new QLineEdit(groupBox);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(90, 260, 141, 28));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lineEdit_6->setPalette(palette6);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(2, 300, 91, 21));
        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(90, 300, 141, 28));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lineEdit_7->setPalette(palette7);
        label_11 = new QLabel(groupBox);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(0, 340, 91, 21));
        lineEdit_8 = new QLineEdit(groupBox);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(90, 340, 141, 28));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        lineEdit_8->setPalette(palette8);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(40, 530, 191, 61));
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
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(40, 460, 191, 61));
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
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(40, 390, 191, 61));
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
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(40, 320, 191, 61));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(40, 250, 191, 61));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_9->setIconSize(QSize(50, 50));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 610, 131, 31));
        pushButton->setStyleSheet(QString::fromUtf8("#btnAjouter_2 {\n"
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
"QPushButton {\n"
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
"\n"
""));
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(1220, 590, 83, 29));
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(1370, 590, 83, 29));
        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(960, 30, 83, 29));
        pushButton_12->setStyleSheet(QString::fromUtf8("#btnAjouterr_2 {\n"
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
"#btnAjouterr_2:hover {\n"
"    background-color: #219150; /* Vert plus fonc\303\251 */\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"#btnAjoute"
                        "rr_2:pressed {\n"
"    background-color: #1e8449; /* Vert encore plus fonc\303\251 */\n"
"    border: 2px solid #166735;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("3309927.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_12->setIcon(icon1);
        pushButton_13 = new QPushButton(centralwidget);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(1270, 30, 83, 29));
        pushButton_13->setStyleSheet(QString::fromUtf8("#btnAjouterr_2 {\n"
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
"#btnAjouterr_2:hover {\n"
"    background-color: #219150; /* Vert plus fonc\303\251 */\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"#btnAjoute"
                        "rr_2:pressed {\n"
"    background-color: #1e8449; /* Vert encore plus fonc\303\251 */\n"
"    border: 2px solid #166735;\n"
"}\n"
"\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("55.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_13->setIcon(icon2);
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(870, 150, 171, 28));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(1350, 150, 82, 28));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(712, 150, 131, 20));
        label_4->setStyleSheet(QString::fromUtf8("/* Style du formulaire */\n"
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
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(1230, 150, 71, 20));
        label_8->setStyleSheet(QString::fromUtf8("/* Style du formulaire */\n"
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
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1626, 25));
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
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        groupBox->setTitle(QString());
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Role", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Courriel", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Nom ", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "password ", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "securityQuestion ", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "securityAnswer ", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Architectes", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Projets", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Formations", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Taches", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Clients", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "se deconnect\303\251", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "stats", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "pdf", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "ID", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "Cherch\303\251 par Nom", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Trier Par", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
