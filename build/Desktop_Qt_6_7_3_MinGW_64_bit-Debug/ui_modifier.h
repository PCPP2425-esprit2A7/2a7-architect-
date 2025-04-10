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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_modifier
{
public:
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QFrame *line;
    QWidget *widget_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_nom;
    QPlainTextEdit *textEdit_description;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QDateEdit *dateEdit_debut;
    QDateEdit *dateEdit_fin;
    QComboBox *comboBox_statut;
    QWidget *widget_3;
    QWidget *widget_4;
    QWidget *widget_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;

    void setupUi(QDialog *modifier)
    {
        if (modifier->objectName().isEmpty())
            modifier->setObjectName("modifier");
        modifier->resize(595, 544);
        widget = new QWidget(modifier);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-30, -10, 641, 111));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 30, 71, 61));
        label->setStyleSheet(QString::fromUtf8("image: url(:/img/338f0f59-de2e-4b18-ba36-958153a5cd68-removebg-preview.png);"));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 40, 151, 61));
        line = new QFrame(widget);
        line->setObjectName("line");
        line->setGeometry(QRect(260, 80, 101, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        widget_2 = new QWidget(modifier);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(130, 120, 311, 341));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 221);"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(12, 10, 81, 20));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(12, 50, 81, 20));
        lineEdit_nom = new QLineEdit(widget_2);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(120, 10, 113, 26));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        textEdit_description = new QPlainTextEdit(widget_2);
        textEdit_description->setObjectName("textEdit_description");
        textEdit_description->setGeometry(QRect(110, 50, 161, 131));
        textEdit_description->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 200, 63, 20));
        label_6 = new QLabel(widget_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 250, 101, 20));
        label_7 = new QLabel(widget_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 290, 63, 20));
        dateEdit_debut = new QDateEdit(widget_2);
        dateEdit_debut->setObjectName("dateEdit_debut");
        dateEdit_debut->setGeometry(QRect(110, 250, 110, 26));
        dateEdit_debut->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        dateEdit_fin = new QDateEdit(widget_2);
        dateEdit_fin->setObjectName("dateEdit_fin");
        dateEdit_fin->setGeometry(QRect(90, 290, 110, 26));
        dateEdit_fin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        comboBox_statut = new QComboBox(widget_2);
        comboBox_statut->addItem(QString());
        comboBox_statut->addItem(QString());
        comboBox_statut->addItem(QString());
        comboBox_statut->setObjectName("comboBox_statut");
        comboBox_statut->setGeometry(QRect(70, 200, 141, 26));
        comboBox_statut->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255)"));
        widget_3 = new QWidget(modifier);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 100, 101, 451));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);"));
        widget_4 = new QWidget(modifier);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(490, 100, 111, 451));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);"));
        widget_5 = new QWidget(modifier);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(90, 480, 441, 80));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 118, 127);"));
        pushButton = new QPushButton(widget_5);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(100, 10, 93, 29));
        pushButton_2 = new QPushButton(widget_5);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(210, 10, 93, 29));
        line_2 = new QFrame(modifier);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(110, 160, 20, 291));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(modifier);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(440, 120, 20, 301));
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        line_4 = new QFrame(modifier);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(150, 100, 261, 20));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);

        retranslateUi(modifier);

        QMetaObject::connectSlotsByName(modifier);
    } // setupUi

    void retranslateUi(QDialog *modifier)
    {
        modifier->setWindowTitle(QCoreApplication::translate("modifier", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("modifier", "Modifier projet", nullptr));
        label_3->setText(QCoreApplication::translate("modifier", "Nom Projet", nullptr));
        label_4->setText(QCoreApplication::translate("modifier", "Description", nullptr));
        label_5->setText(QCoreApplication::translate("modifier", "Statut", nullptr));
        label_6->setText(QCoreApplication::translate("modifier", "Date debut", nullptr));
        label_7->setText(QCoreApplication::translate("modifier", "Date fin", nullptr));
        comboBox_statut->setItemText(0, QCoreApplication::translate("modifier", "termin\303\251", nullptr));
        comboBox_statut->setItemText(1, QCoreApplication::translate("modifier", "en cours", nullptr));
        comboBox_statut->setItemText(2, QCoreApplication::translate("modifier", "suspendu", nullptr));

        pushButton->setText(QCoreApplication::translate("modifier", "Confirmer", nullptr));
        pushButton_2->setText(QCoreApplication::translate("modifier", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class modifier: public Ui_modifier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIER_H
