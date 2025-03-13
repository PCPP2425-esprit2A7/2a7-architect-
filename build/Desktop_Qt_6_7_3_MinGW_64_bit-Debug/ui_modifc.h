/********************************************************************************
** Form generated from reading UI file 'modifc.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFC_H
#define UI_MODIFC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_modifc
{
public:
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
    QSlider *nbcProjet_2;
    QLabel *label_8;
    QLabel *label_7;
    QLineEdit *IDC;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *modifc)
    {
        if (modifc->objectName().isEmpty())
            modifc->setObjectName("modifc");
        modifc->resize(897, 632);
        groupBox = new QGroupBox(modifc);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(250, 50, 311, 521));
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
        nomClient->setGeometry(QRect(50, 90, 81, 20));
        nomClient->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        prenomClient = new QLabel(groupBox);
        prenomClient->setObjectName("prenomClient");
        prenomClient->setGeometry(QRect(50, 150, 71, 21));
        emailClient = new QLabel(groupBox);
        emailClient->setObjectName("emailClient");
        emailClient->setGeometry(QRect(50, 220, 63, 20));
        numClient = new QLabel(groupBox);
        numClient->setObjectName("numClient");
        numClient->setGeometry(QRect(50, 300, 63, 20));
        nbcProjet = new QLabel(groupBox);
        nbcProjet->setObjectName("nbcProjet");
        nbcProjet->setGeometry(QRect(50, 380, 81, 20));
        nomClient_2 = new QLineEdit(groupBox);
        nomClient_2->setObjectName("nomClient_2");
        nomClient_2->setGeometry(QRect(50, 120, 171, 31));
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
        prenomClient_2->setGeometry(QRect(50, 180, 171, 31));
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
        IDC->setGeometry(QRect(50, 50, 161, 26));
        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(60, 460, 151, 32));
        buttonBox->setStyleSheet(QString::fromUtf8("QDialogButtonBox QPushButton {\n"
"    background-color: #4A4A4A; /* Couleur similaire \303\240 la bordure du QLineEdit */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #4A4A4A;\n"
"    border-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QDialogButtonBox QPushButton:hover {\n"
"    background-color: #1f618d; /* M\303\252me couleur que le focus du QLineEdit */\n"
"    border: 2px solid #1f618d;\n"
"}\n"
"\n"
"QDialogButtonBox QPushButton:pressed {\n"
"    background-color: #154360; /* L\303\251g\303\250rement plus fonc\303\251 pour l'effet press\303\251 */\n"
"    border: 2px solid #154360;\n"
"}\n"
""));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(modifc);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, modifc, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, modifc, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(modifc);
    } // setupUi

    void retranslateUi(QDialog *modifc)
    {
        modifc->setWindowTitle(QCoreApplication::translate("modifc", "Dialog", nullptr));
        groupBox->setTitle(QString());
        nomClient->setText(QCoreApplication::translate("modifc", "Nom", nullptr));
        prenomClient->setText(QCoreApplication::translate("modifc", "Pr\303\251nom", nullptr));
        emailClient->setText(QCoreApplication::translate("modifc", "Email", nullptr));
        numClient->setText(QCoreApplication::translate("modifc", "Num-tel", nullptr));
        nbcProjet->setText(QCoreApplication::translate("modifc", "Nb-projet", nullptr));
        label_8->setText(QString());
        label_7->setText(QCoreApplication::translate("modifc", "Modifier un Clinet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class modifc: public Ui_modifc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFC_H
