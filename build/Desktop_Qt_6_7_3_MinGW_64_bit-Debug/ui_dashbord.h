/********************************************************************************
** Form generated from reading UI file 'dashbord.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBORD_H
#define UI_DASHBORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_dashbord
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *anuule;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QLabel *label_15;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_22;
    QPushButton *btnAjouter_2;
    QLabel *label_10;
    QTableWidget *tableView;

    void setupUi(QDialog *dashbord)
    {
        if (dashbord->objectName().isEmpty())
            dashbord->setObjectName("dashbord");
        dashbord->resize(1559, 682);
        label = new QLabel(dashbord);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1581, 81));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);"));
        label_2 = new QLabel(dashbord);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 80, 241, 591));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);"));
        label_3 = new QLabel(dashbord);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(-170, -90, 581, 341));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/res/10.jpeg);\n"
"image: url(:/res/989.png);"));
        pushButton_6 = new QPushButton(dashbord);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(0, 160, 241, 71));
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
        pushButton_2 = new QPushButton(dashbord);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(0, 240, 241, 71));
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
        pushButton_3 = new QPushButton(dashbord);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(0, 320, 241, 71));
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
        anuule = new QPushButton(dashbord);
        anuule->setObjectName("anuule");
        anuule->setGeometry(QRect(0, 400, 241, 71));
        anuule->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_5 = new QPushButton(dashbord);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(0, 480, 241, 71));
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
        pushButton_7 = new QPushButton(dashbord);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(0, 560, 241, 71));
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
        label_15 = new QLabel(dashbord);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(20, 180, 41, 31));
        label_15->setStyleSheet(QString::fromUtf8("image: url(:/res/16854774.png);"));
        label_11 = new QLabel(dashbord);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 260, 41, 31));
        label_11->setStyleSheet(QString::fromUtf8("image: url(:/res/7891470.png);"));
        label_13 = new QLabel(dashbord);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 340, 41, 31));
        label_13->setStyleSheet(QString::fromUtf8("image: url(:/res/33.png);"));
        label_12 = new QLabel(dashbord);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 420, 31, 31));
        label_12->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/res/12214354.png);"));
        label_14 = new QLabel(dashbord);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 500, 41, 31));
        label_14->setStyleSheet(QString::fromUtf8("image: url(:/res/2942499.png);"));
        label_22 = new QLabel(dashbord);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(30, 580, 31, 31));
        label_22->setStyleSheet(QString::fromUtf8("image: url(:/res/777.png);"));
        btnAjouter_2 = new QPushButton(dashbord);
        btnAjouter_2->setObjectName("btnAjouter_2");
        btnAjouter_2->setGeometry(QRect(50, 630, 141, 31));
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
        label_10 = new QLabel(dashbord);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(1460, 10, 91, 51));
        label_10->setStyleSheet(QString::fromUtf8("image: url(:/res/98.png);"));
        tableView = new QTableWidget(dashbord);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(540, 140, 651, 471));
        tableView->setStyleSheet(QString::fromUtf8("/* Style de base pour le tableau */\n"
"#tableView {\n"
" background-color: #ffffff;\n"
"    border: 2px solid #e0e0e0;\n"
"    border-radius: 12px;\n"
"    alternate-background-color: #f8fafc;\n"
"    gridline-color: #e2e8f0;\n"
"    font-family: 'Segoe UI', 'Roboto', sans-serif;\n"
"    font-size: 14px;  /* Taille de police augment\303\251e */\n"
"    padding: 4px;\n"
"    box-shadow: 0 1px 3px rgba(0, 0, 0, 0.05);\n"
"}\n"
"\n"
"/* Style des cellules */\n"
"#tableView::item {\n"
"   padding: 8px;\n"
"    border-bottom: 1px solid #f0f0f0;\n"
"}\n"
"\n"
"/* En-t\303\252tes avec couleur ARCHITOPIA */\n"
"#tableView QHeaderView::section {\n"
"    background-color: #15767f;  /* Couleur bleu-vert comme la navbar */\n"
"    color: white;\n"
"    padding: 14px 16px;  /* Espacement augment\303\251 */\n"
"    border: none;\n"
"    font-weight: 600;\n"
"    font-size: 15px;  /* Taille de police augment\303\251e */\n"
"    border-radius: 8px;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"/* S\303\251lection stylis\303\251e */\n"
""
                        "#tableView::item:selected {\n"
"    background-color: #e6fffa;\n"
"    color: #234e52;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"/* Barres de d\303\251filement */\n"
"#tableView QScrollBar:vertical {\n"
"    width: 10px;\n"
"    background: #f0fdfa;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"#tableView QScrollBar::handle:vertical {\n"
"    background: #15767f;  /* Couleur ARCHITOPIA */\n"
"    border-radius: 5px;\n"
"    min-height: 3px;\n"
"}\n"
"\n"
"/* Effets de survol */\n"
"#tableView::item:hover {\n"
"    background-color: #f0fdf4;\n"
"    transition: background-color 0.2s ease;\n"
"}\n"
"\n"
"/* Style altern\303\251 des lignes */\n"
"#tableView::item:alternate {\n"
"    background-color: #f7fafc;\n"
"}\n"
"\n"
"/* Coins arrondis */\n"
"QHeaderView {\n"
"    border-top-left-radius: 12px;\n"
"    border-top-right-radius: 12px;\n"
"}\n"
"\n"
"QTableView {\n"
"    border-bottom-left-radius: 12px;\n"
"    border-bottom-right-radius: 12px;\n"
"}"));

        retranslateUi(dashbord);

        QMetaObject::connectSlotsByName(dashbord);
    } // setupUi

    void retranslateUi(QDialog *dashbord)
    {
        dashbord->setWindowTitle(QCoreApplication::translate("dashbord", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("dashbord", "Dashbord", nullptr));
        pushButton_2->setText(QCoreApplication::translate("dashbord", "Clients", nullptr));
        pushButton_3->setText(QCoreApplication::translate("dashbord", "Taches", nullptr));
        anuule->setText(QCoreApplication::translate("dashbord", "Formations", nullptr));
        pushButton_5->setText(QCoreApplication::translate("dashbord", "Projets", nullptr));
        pushButton_7->setText(QCoreApplication::translate("dashbord", "Architectes", nullptr));
        label_15->setText(QString());
        label_11->setText(QString());
        label_13->setText(QString());
        label_12->setText(QString());
        label_14->setText(QString());
        label_22->setText(QString());
        btnAjouter_2->setText(QCoreApplication::translate("dashbord", "Se D\303\251connecter", nullptr));
        label_10->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dashbord: public Ui_dashbord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBORD_H
