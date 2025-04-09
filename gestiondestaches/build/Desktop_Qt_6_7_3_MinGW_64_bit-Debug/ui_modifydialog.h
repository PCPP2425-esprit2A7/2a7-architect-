/********************************************************************************
** Form generated from reading UI file 'modifydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYDIALOG_H
#define UI_MODIFYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ModifyDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEditMission;
    QComboBox *comboBoxStatut;
    QTextEdit *textEditDescription;
    QDateEdit *dateEditDebut;
    QDateEdit *dateEditFin;

    void setupUi(QDialog *ModifyDialog)
    {
        if (ModifyDialog->objectName().isEmpty())
            ModifyDialog->setObjectName("ModifyDialog");
        ModifyDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(ModifyDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        lineEditMission = new QLineEdit(ModifyDialog);
        lineEditMission->setObjectName("lineEditMission");
        lineEditMission->setGeometry(QRect(90, 40, 113, 22));
        comboBoxStatut = new QComboBox(ModifyDialog);
        comboBoxStatut->addItem(QString());
        comboBoxStatut->addItem(QString());
        comboBoxStatut->addItem(QString());
        comboBoxStatut->setObjectName("comboBoxStatut");
        comboBoxStatut->setGeometry(QRect(260, 50, 69, 22));
        textEditDescription = new QTextEdit(ModifyDialog);
        textEditDescription->setObjectName("textEditDescription");
        textEditDescription->setGeometry(QRect(100, 120, 104, 71));
        dateEditDebut = new QDateEdit(ModifyDialog);
        dateEditDebut->setObjectName("dateEditDebut");
        dateEditDebut->setGeometry(QRect(270, 110, 110, 22));
        dateEditFin = new QDateEdit(ModifyDialog);
        dateEditFin->setObjectName("dateEditFin");
        dateEditFin->setGeometry(QRect(270, 150, 110, 22));

        retranslateUi(ModifyDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ModifyDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ModifyDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ModifyDialog);
    } // setupUi

    void retranslateUi(QDialog *ModifyDialog)
    {
        ModifyDialog->setWindowTitle(QCoreApplication::translate("ModifyDialog", "Dialog", nullptr));
        comboBoxStatut->setItemText(0, QCoreApplication::translate("ModifyDialog", "\303\200 faire", nullptr));
        comboBoxStatut->setItemText(1, QCoreApplication::translate("ModifyDialog", "En cours", nullptr));
        comboBoxStatut->setItemText(2, QCoreApplication::translate("ModifyDialog", "Termin\303\251", nullptr));

    } // retranslateUi

};

namespace Ui {
    class ModifyDialog: public Ui_ModifyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYDIALOG_H
