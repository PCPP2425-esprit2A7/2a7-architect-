/********************************************************************************
** Form generated from reading UI file 'modifier.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIER_H
#define UI_MODIFIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_modifier
{
public:
    QLabel *label;
    QLabel *label_2;
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
    QLineEdit *lineEdit_prix;
    QDialogButtonBox *buttonBox;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_3;

    void setupUi(QDialog *modifier)
    {
        if (modifier->objectName().isEmpty())
            modifier->setObjectName("modifier");
        modifier->resize(642, 549);
        label = new QLabel(modifier);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 641, 61));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);\n"
""));
        label_2 = new QLabel(modifier);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 490, 641, 61));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);\n"
""));
        groupBox = new QGroupBox(modifier);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(150, 60, 321, 471));
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
        label_4->setGeometry(QRect(10, 75, 51, 21));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 140, 81, 31));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 390, 49, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 330, 49, 16));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 210, 71, 31));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 270, 91, 31));
        lineEdit_id = new QLineEdit(groupBox);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(132, 70, 141, 31));
        lineEdit_formateur = new QLineEdit(groupBox);
        lineEdit_formateur->setObjectName("lineEdit_formateur");
        lineEdit_formateur->setGeometry(QRect(132, 270, 141, 31));
        lineEdit_lieu = new QLineEdit(groupBox);
        lineEdit_lieu->setObjectName("lineEdit_lieu");
        lineEdit_lieu->setGeometry(QRect(132, 330, 141, 31));
        lineEdit_dateFin = new QDateEdit(groupBox);
        lineEdit_dateFin->setObjectName("lineEdit_dateFin");
        lineEdit_dateFin->setGeometry(QRect(129, 210, 141, 31));
        lineEdit_dateDebut = new QDateEdit(groupBox);
        lineEdit_dateDebut->setObjectName("lineEdit_dateDebut");
        lineEdit_dateDebut->setGeometry(QRect(129, 140, 141, 31));
        lineEdit_prix = new QLineEdit(groupBox);
        lineEdit_prix->setObjectName("lineEdit_prix");
        lineEdit_prix->setGeometry(QRect(130, 380, 141, 31));
        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(80, 430, 156, 24));
        buttonBox->setStyleSheet(QString::fromUtf8("#buttonBox {\n"
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
"#buttonBox:hover {\n"
"    background-color: #219150; /* Vert plus fonc\303\251 */\n"
"    border: 2px solid #1e8449;\n"
"}\n"
"\n"
"/* Effet au clic */\n"
"#buttonBox:pressed"
                        " {\n"
"    background-color: #1e8449; /* Vert encore plus fonc\303\251 */\n"
"    border: 2px solid #166735;\n"
"}\n"
""));
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label_20 = new QLabel(modifier);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(150, 20, 251, 71));
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
        label_21 = new QLabel(modifier);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(400, 20, 71, 71));
        label_21->setStyleSheet(QString::fromUtf8("image: url(:/res/2481936.png);"));
        label_3 = new QLabel(modifier);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(560, 10, 71, 41));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/res/98.png);"));

        retranslateUi(modifier);

        QMetaObject::connectSlotsByName(modifier);
    } // setupUi

    void retranslateUi(QDialog *modifier)
    {
        modifier->setWindowTitle(QCoreApplication::translate("modifier", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        groupBox->setTitle(QString());
        label_4->setText(QCoreApplication::translate("modifier", "ID :", nullptr));
        label_5->setText(QCoreApplication::translate("modifier", "DateDebut :", nullptr));
        label_6->setText(QCoreApplication::translate("modifier", "Prix :", nullptr));
        label_7->setText(QCoreApplication::translate("modifier", "Lieu :", nullptr));
        label_8->setText(QCoreApplication::translate("modifier", "DateFin :", nullptr));
        label_9->setText(QCoreApplication::translate("modifier", "Formateur :", nullptr));
        label_20->setText(QCoreApplication::translate("modifier", "   Modifier Une Formation", nullptr));
        label_21->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class modifier: public Ui_modifier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIER_H
