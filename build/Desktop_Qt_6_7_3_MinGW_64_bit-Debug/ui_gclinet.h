/********************************************************************************
** Form generated from reading UI file 'gclinet.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GCLINET_H
#define UI_GCLINET_H

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
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gclinet
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGroupBox *groupBox;
    QLabel *nomClient;
    QLabel *prenomClient;
    QLabel *emailClient;
    QLabel *numClient;
    QLabel *nbcProjet;
    QLineEdit *nomClient_2;
    QLineEdit *prenomClient_2;
    QLineEdit *emailClient_2;
    QLineEdit *numClient_2;
    QPushButton *validerClient;
    QPushButton *anuulerClient;
    QSlider *nbcProjet_2;
    QLabel *label_8;
    QLabel *label_7;
    QLineEdit *IDC;
    QLabel *nomClient_3;
    QTableView *tableView;
    QComboBox *tri;
    QPushButton *buttonRechercher;
    QPushButton *suppclient;
    QLineEdit *lineEditPrenom;
    QPushButton *modifierClient;
    QWidget *widget;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_16;
    QWidget *widget_3;
    QPushButton *pushButton_18;
    QPushButton *exportPdfButton;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_9;
    QWidget *page_2;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Gclinet)
    {
        if (Gclinet->objectName().isEmpty())
            Gclinet->setObjectName("Gclinet");
        Gclinet->resize(1503, 661);
        Gclinet->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);"));
        centralwidget = new QWidget(Gclinet);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(70, 0, 1411, 611));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        page = new QWidget();
        page->setObjectName("page");
        groupBox = new QGroupBox(page);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(360, 80, 311, 521));
        groupBox->setAutoFillBackground(false);
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
"}"));
        groupBox->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        groupBox->setChecked(false);
        nomClient = new QLabel(groupBox);
        nomClient->setObjectName("nomClient");
        nomClient->setGeometry(QRect(50, 80, 81, 20));
        nomClient->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        prenomClient = new QLabel(groupBox);
        prenomClient->setObjectName("prenomClient");
        prenomClient->setGeometry(QRect(50, 140, 71, 21));
        emailClient = new QLabel(groupBox);
        emailClient->setObjectName("emailClient");
        emailClient->setGeometry(QRect(50, 220, 63, 20));
        numClient = new QLabel(groupBox);
        numClient->setObjectName("numClient");
        numClient->setGeometry(QRect(50, 290, 63, 20));
        nbcProjet = new QLabel(groupBox);
        nbcProjet->setObjectName("nbcProjet");
        nbcProjet->setGeometry(QRect(50, 380, 81, 20));
        nomClient_2 = new QLineEdit(groupBox);
        nomClient_2->setObjectName("nomClient_2");
        nomClient_2->setGeometry(QRect(50, 105, 171, 31));
        nomClient_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"\n"
"border-radius: 8px;\n"
"padding: 8px 16px;\n"
"font-size: 12px;\n"
"font-weight: bold;\n"
""));
        prenomClient_2 = new QLineEdit(groupBox);
        prenomClient_2->setObjectName("prenomClient_2");
        prenomClient_2->setGeometry(QRect(50, 175, 171, 31));
        prenomClient_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"\n"
"border-radius: 8px;\n"
"padding: 8px 16px;\n"
"font-size: 12px;\n"
"font-weight: bold;\n"
""));
        prenomClient_2->setAlignment(Qt::AlignmentFlag::AlignJustify|Qt::AlignmentFlag::AlignVCenter);
        emailClient_2 = new QLineEdit(groupBox);
        emailClient_2->setObjectName("emailClient_2");
        emailClient_2->setGeometry(QRect(50, 255, 171, 31));
        emailClient_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"\n"
"border-radius: 8px;\n"
"padding: 8px 16px;\n"
"font-size: 12px;\n"
"font-weight: bold;\n"
""));
        numClient_2 = new QLineEdit(groupBox);
        numClient_2->setObjectName("numClient_2");
        numClient_2->setGeometry(QRect(50, 330, 171, 31));
        numClient_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"\n"
"border-radius: 8px;\n"
"padding: 8px 16px;\n"
"font-size: 12px;\n"
"font-weight: bold;\n"
""));
        validerClient = new QPushButton(groupBox);
        validerClient->setObjectName("validerClient");
        validerClient->setGeometry(QRect(20, 470, 101, 31));
        validerClient->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"/* Effet au survol */"));
        anuulerClient = new QPushButton(groupBox);
        anuulerClient->setObjectName("anuulerClient");
        anuulerClient->setGeometry(QRect(162, 470, 111, 31));
        anuulerClient->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"/* Effet au survol */"));
        nbcProjet_2 = new QSlider(groupBox);
        nbcProjet_2->setObjectName("nbcProjet_2");
        nbcProjet_2->setGeometry(QRect(50, 420, 160, 22));
        nbcProjet_2->setOrientation(Qt::Orientation::Horizontal);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(240, 10, 81, 51));
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/res/client.png);"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 0, 171, 31));
        label_7->setStyleSheet(QString::fromUtf8("font: 350 italic 12pt \"Nirmala UI\";"));
        IDC = new QLineEdit(groupBox);
        IDC->setObjectName("IDC");
        IDC->setGeometry(QRect(50, 40, 161, 31));
        IDC->setStyleSheet(QString::fromUtf8(""));
        nomClient_3 = new QLabel(groupBox);
        nomClient_3->setObjectName("nomClient_3");
        nomClient_3->setGeometry(QRect(20, 40, 21, 31));
        nomClient_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        tableView = new QTableView(page);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(710, 220, 651, 291));
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
"    background-color: #007BFF; /* Fond bleu pour les en-t\303\252tes */\n"
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
"    transition: background 0.3s ease-in-out; /* Animation douce */\n"
""
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
"}\n"
""));
        tri = new QComboBox(page);
        tri->addItem(QString());
        tri->addItem(QString());
        tri->setObjectName("tri");
        tri->setGeometry(QRect(1200, 170, 151, 31));
        tri->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
"}"));
        buttonRechercher = new QPushButton(page);
        buttonRechercher->setObjectName("buttonRechercher");
        buttonRechercher->setGeometry(QRect(920, 170, 161, 31));
        buttonRechercher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   \n"
"    color: Black;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #4A4A4A;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    \n"
"    border: 2px solid #1f618d;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1f618d; /* Bleu encore plus fonc\303\251 au clic */\n"
"    border: 2px solid #154360;\n"
"}"));
        suppclient = new QPushButton(page);
        suppclient->setObjectName("suppclient");
        suppclient->setGeometry(QRect(1110, 530, 141, 31));
        suppclient->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   \n"
"    color: Black;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #4A4A4A;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    \n"
"    border: 2px solid #1f618d;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1f618d; /* Bleu encore plus fonc\303\251 au clic */\n"
"    border: 2px solid #154360;\n"
"}"));
        lineEditPrenom = new QLineEdit(page);
        lineEditPrenom->setObjectName("lineEditPrenom");
        lineEditPrenom->setGeometry(QRect(730, 170, 181, 31));
        lineEditPrenom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    color: black;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #4A4A4A; /* Bleu comme le bouton */\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #1f618d; /* Changement au focus, comme le hover du bouton */\n"
"}\n"
""));
        modifierClient = new QPushButton(page);
        modifierClient->setObjectName("modifierClient");
        modifierClient->setGeometry(QRect(940, 530, 141, 31));
        modifierClient->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   \n"
"    color: Black;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #4A4A4A;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    \n"
"    border: 2px solid #1f618d;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1f618d; /* Bleu encore plus fonc\303\251 au clic */\n"
"    border: 2px solid #154360;\n"
"}"));
        widget = new QWidget(page);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-1, 0, 271, 611));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);"));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(0, 160, 271, 61));
        pushButton_3->setMaximumSize(QSize(16777200, 16777208));
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
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/dashboard.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(35, 35));
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(0, 230, 271, 61));
        pushButton_4->setMaximumSize(QSize(16777200, 16777208));
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
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/client.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_4->setIcon(icon1);
        pushButton_4->setIconSize(QSize(35, 35));
        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(0, 370, 271, 61));
        pushButton_6->setMaximumSize(QSize(16777200, 16777208));
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
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/formation.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_6->setIcon(icon2);
        pushButton_6->setIconSize(QSize(35, 35));
        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(0, 300, 271, 61));
        pushButton_5->setMaximumSize(QSize(16777200, 16777208));
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
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/tache.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_5->setIcon(icon3);
        pushButton_5->setIconSize(QSize(35, 35));
        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(0, 440, 271, 61));
        pushButton_7->setMaximumSize(QSize(16777200, 16777208));
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
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/projet.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_7->setIcon(icon4);
        pushButton_7->setIconSize(QSize(35, 35));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, -20, 181, 171));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/res/logo1.png);"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 580, 171, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 221);\n"
"border-radius: 8px;\n"
"padding: 8px 8px;\n"
"font-size: 14px;\n"
"font-weight: bold;"));
        pushButton_16 = new QPushButton(widget);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(0, 510, 271, 61));
        pushButton_16->setMaximumSize(QSize(16777200, 16777208));
        pushButton_16->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/aeeeee.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_16->setIcon(icon5);
        pushButton_16->setIconSize(QSize(35, 35));
        widget_3 = new QWidget(page);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(270, 0, 1141, 71));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);"));
        pushButton_18 = new QPushButton(widget_3);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(490, 20, 131, 41));
        pushButton_18->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"/* Effet au survol */"));
        exportPdfButton = new QPushButton(widget_3);
        exportPdfButton->setObjectName("exportPdfButton");
        exportPdfButton->setGeometry(QRect(820, 30, 91, 31));
        exportPdfButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"/* Effet au survol */"));
        exportPdfButton->setIconSize(QSize(35, 35));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(410, 20, 71, 41));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/res/stats.png);"));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(760, 30, 51, 31));
        label_5->setStyleSheet(QString::fromUtf8("image: url(:/res/pdffffffffff.png);"));
        label_6 = new QLabel(widget_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(1070, 0, 61, 51));
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/res/4444.png);"));
        label_9 = new QLabel(page);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(1160, 170, 31, 31));
        label_9->setStyleSheet(QString::fromUtf8("font: 350 italic 12pt \"Nirmala UI\";"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(210, 0, 161, 31));
        stackedWidget->addWidget(page_2);
        Gclinet->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Gclinet);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1503, 26));
        Gclinet->setMenuBar(menubar);
        statusbar = new QStatusBar(Gclinet);
        statusbar->setObjectName("statusbar");
        Gclinet->setStatusBar(statusbar);

        retranslateUi(Gclinet);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Gclinet);
    } // setupUi

    void retranslateUi(QMainWindow *Gclinet)
    {
        Gclinet->setWindowTitle(QCoreApplication::translate("Gclinet", "Gclinet", nullptr));
        groupBox->setTitle(QString());
        nomClient->setText(QCoreApplication::translate("Gclinet", "Nom", nullptr));
        prenomClient->setText(QCoreApplication::translate("Gclinet", "Pr\303\251nom", nullptr));
        emailClient->setText(QCoreApplication::translate("Gclinet", "Email", nullptr));
        numClient->setText(QCoreApplication::translate("Gclinet", "Num-tel", nullptr));
        nbcProjet->setText(QCoreApplication::translate("Gclinet", "Nb-projet", nullptr));
        validerClient->setText(QCoreApplication::translate("Gclinet", "Valider", nullptr));
        anuulerClient->setText(QCoreApplication::translate("Gclinet", "Anuuler", nullptr));
        label_8->setText(QString());
        label_7->setText(QCoreApplication::translate("Gclinet", "Ajouter un Clinet", nullptr));
        nomClient_3->setText(QCoreApplication::translate("Gclinet", "ID:", nullptr));
        tri->setItemText(0, QCoreApplication::translate("Gclinet", "nb_projet+", nullptr));
        tri->setItemText(1, QCoreApplication::translate("Gclinet", "Nb-projet-", nullptr));

        buttonRechercher->setText(QCoreApplication::translate("Gclinet", "Recherche", nullptr));
        suppclient->setText(QCoreApplication::translate("Gclinet", "Supprimer", nullptr));
        lineEditPrenom->setText(QString());
        modifierClient->setText(QCoreApplication::translate("Gclinet", "Modifer", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Gclinet", "Dashboard", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Gclinet", "Clients", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Gclinet", "Formations", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Gclinet", "Taches", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Gclinet", "Projets", nullptr));
        label_2->setText(QString());
        pushButton->setText(QCoreApplication::translate("Gclinet", "Se D\303\251connecter", nullptr));
        pushButton_16->setText(QCoreApplication::translate("Gclinet", "Architect", nullptr));
        pushButton_18->setText(QCoreApplication::translate("Gclinet", "statistiques", nullptr));
        exportPdfButton->setText(QCoreApplication::translate("Gclinet", "PDF", nullptr));
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_9->setText(QCoreApplication::translate("Gclinet", "Tri:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Gclinet", "Acceuil", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gclinet: public Ui_Gclinet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GCLINET_H
