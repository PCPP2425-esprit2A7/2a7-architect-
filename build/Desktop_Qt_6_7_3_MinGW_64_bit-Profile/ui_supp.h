/********************************************************************************
** Form generated from reading UI file 'supp.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPP_H
#define UI_SUPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_supp
{
public:
    QLineEdit *lineEditsupp;
    QLabel *label;
    QPushButton *supprimer;
    QPushButton *pushButtonanuul;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *supp)
    {
        if (supp->objectName().isEmpty())
            supp->setObjectName("supp");
        supp->resize(524, 379);
        lineEditsupp = new QLineEdit(supp);
        lineEditsupp->setObjectName("lineEditsupp");
        lineEditsupp->setGeometry(QRect(270, 121, 121, 31));
        lineEditsupp->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label = new QLabel(supp);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 110, 131, 51));
        label->setStyleSheet(QString::fromUtf8("/* Style du formulaire */\n"
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
        supprimer = new QPushButton(supp);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(130, 230, 111, 31));
        supprimer->setStyleSheet(QString::fromUtf8("#supprimer {\n"
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
"#supprimer:hover {\n"
"    background-color: #219150; /* Vert plus fonc\303\251 */\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"#supprimer:pressed"
                        " {\n"
"    background-color: #1e8449; /* Vert encore plus fonc\303\251 */\n"
"    border: 2px solid #166735;\n"
"}\n"
""));
        pushButtonanuul = new QPushButton(supp);
        pushButtonanuul->setObjectName("pushButtonanuul");
        pushButtonanuul->setGeometry(QRect(270, 230, 111, 31));
        pushButtonanuul->setStyleSheet(QString::fromUtf8("#pushButtonanuul {\n"
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
"#pushButtonanuul:hover {\n"
"    background-color: #219150; /* Vert plus fonc\303\251 */\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"#pushB"
                        "uttonanuul:pressed {\n"
"    background-color: #1e8449; /* Vert encore plus fonc\303\251 */\n"
"    border: 2px solid #166735;\n"
"}\n"
""));
        label_2 = new QLabel(supp);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 531, 51));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);"));
        label_3 = new QLabel(supp);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(440, 10, 81, 31));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/res/98.png);"));
        label_4 = new QLabel(supp);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 330, 531, 51));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);"));

        retranslateUi(supp);

        QMetaObject::connectSlotsByName(supp);
    } // setupUi

    void retranslateUi(QDialog *supp)
    {
        supp->setWindowTitle(QCoreApplication::translate("supp", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("supp", "Supprimer Par ID : ", nullptr));
        supprimer->setText(QCoreApplication::translate("supp", "Supprimer", nullptr));
        pushButtonanuul->setText(QCoreApplication::translate("supp", "Annul\303\251", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class supp: public Ui_supp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPP_H
