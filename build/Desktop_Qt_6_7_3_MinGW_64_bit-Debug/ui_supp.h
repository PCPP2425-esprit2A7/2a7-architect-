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
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_supp
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_idsupp;

    void setupUi(QDialog *supp)
    {
        if (supp->objectName().isEmpty())
            supp->setObjectName("supp");
        supp->resize(551, 353);
        supp->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 213, 213);"));
        buttonBox = new QDialogButtonBox(supp);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(160, 240, 171, 32));
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
        lineEdit_idsupp = new QLineEdit(supp);
        lineEdit_idsupp->setObjectName("lineEdit_idsupp");
        lineEdit_idsupp->setGeometry(QRect(160, 170, 211, 31));
        lineEdit_idsupp->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    color: black;\n"
"    font-size: 10px;\n"
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

        retranslateUi(supp);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, supp, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, supp, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(supp);
    } // setupUi

    void retranslateUi(QDialog *supp)
    {
        supp->setWindowTitle(QCoreApplication::translate("supp", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class supp: public Ui_supp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPP_H
