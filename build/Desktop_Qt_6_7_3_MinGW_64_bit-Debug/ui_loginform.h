/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginForm
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditEmail;
    QLineEdit *lineEditPassword;
    QPushButton *btnLogin;
    QPushButton *btnForgotPassword;

    void setupUi(QDialog *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName("LoginForm");
        LoginForm->resize(587, 514);
        verticalLayout = new QVBoxLayout(LoginForm);
        verticalLayout->setObjectName("verticalLayout");
        lineEditEmail = new QLineEdit(LoginForm);
        lineEditEmail->setObjectName("lineEditEmail");

        verticalLayout->addWidget(lineEditEmail);

        lineEditPassword = new QLineEdit(LoginForm);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(lineEditPassword);

        btnLogin = new QPushButton(LoginForm);
        btnLogin->setObjectName("btnLogin");

        verticalLayout->addWidget(btnLogin);

        btnForgotPassword = new QPushButton(LoginForm);
        btnForgotPassword->setObjectName("btnForgotPassword");

        verticalLayout->addWidget(btnForgotPassword);


        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QDialog *LoginForm)
    {
        LoginForm->setWindowTitle(QCoreApplication::translate("LoginForm", "Login", nullptr));
        lineEditEmail->setPlaceholderText(QCoreApplication::translate("LoginForm", "Email", nullptr));
        lineEditPassword->setPlaceholderText(QCoreApplication::translate("LoginForm", "Password", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginForm", "Login", nullptr));
        btnForgotPassword->setText(QCoreApplication::translate("LoginForm", "Forgot Password?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
