// loginform.cpp
#include "loginform.h"
#include "ui_loginform.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QDebug>
#include <QInputDialog>
#include <QSqlError>

LoginForm::LoginForm(QWidget *parent) :
    QDialog(parent), ui(new Ui::LoginForm) {
    ui->setupUi(this);
    connect(ui->btnLogin, &QPushButton::clicked, this, &LoginForm::on_btnLogin_clicked);
    connect(ui->btnForgotPassword, &QPushButton::clicked, this, &LoginForm::on_btnForgotPassword_clicked);
}

LoginForm::~LoginForm() {
    delete ui;
}

QString LoginForm::hashString(const QString &input) {
    return QString(QCryptographicHash::hash(input.toUtf8(), QCryptographicHash::Sha256).toHex());
}

void LoginForm::on_btnLogin_clicked() {
    QString email = ui->lineEditEmail->text().trimmed();
    QString password = hashString(ui->lineEditPassword->text());

    qDebug() << "Trying login with email:" << email;
    qDebug() << "Password hash:" << password;

    QSqlQuery query;
    query.prepare("SELECT * FROM ARCHITECTE WHERE COURRIEL = :email AND MOT_DE_PASSE = :password");
    query.bindValue(":email", email);
    query.bindValue(":password", password);
    // TEMPORARY DEBUG: Show all emails and password hashes in DB
    QSqlQuery debugQuery;
    debugQuery.exec("SELECT COURRIEL, MOT_DE_PASSE FROM ARCHITECTE");

    qDebug() << "----- DATABASE RECORDS -----";
    while (debugQuery.next()) {
        QString dbEmail = debugQuery.value(0).toString();
        QString dbHash = debugQuery.value(1).toString();
        qDebug() << "Email in DB: [" << dbEmail << "]";
        qDebug() << "Password hash in DB: [" << dbHash << "]";
    }
    qDebug() << "-----------------------------";


    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Query execution failed!");
        return;
    }

    if (!query.next()) {
        qDebug() << "Login failed — no matching user found.";
        QMessageBox::warning(this, "Error", "Invalid credentials.");
        return;
    }

    QMessageBox::information(this, "Success", "Login successful!");
    MainWindow *mainWin = new MainWindow();
    mainWin->show();
    this->close();
}

void LoginForm::on_btnForgotPassword_clicked() {
    QString email = QInputDialog::getText(this, "Password Recovery", "Enter your email:");
    if (email.isEmpty()) return;

    QSqlQuery query;
    query.prepare("SELECT SECURITY_QUESTION FROM ARCHITECTE WHERE COURRIEL = :email");
    query.bindValue(":email", email);
    if (query.exec() && query.next()) {
        QString question = query.value(0).toString();
        QString answer = QInputDialog::getText(this, "Security Question", question);
        QSqlQuery answerQuery;
        answerQuery.prepare("SELECT SECURITY_ANSWER FROM ARCHITECTE WHERE COURRIEL = :email");
        answerQuery.bindValue(":email", email);
        if (answerQuery.exec() && answerQuery.next()) {
            QString correctHash = answerQuery.value(0).toString();
            if (hashString(answer) == correctHash) {
                QString newPassword = QInputDialog::getText(this, "Reset Password", "Enter new password:");
                QSqlQuery updateQuery;
                updateQuery.prepare("UPDATE ARCHITECTE SET MOT_DE_PASSE = :newPass WHERE COURRIEL = :email");
                updateQuery.bindValue(":newPass", hashString(newPassword));
                updateQuery.bindValue(":email", email);
                if (updateQuery.exec()) {
                    QMessageBox::information(this, "Success", "Password reset successfully.");
                } else {
                    QMessageBox::warning(this, "Error", "Password reset failed.");
                }
            } else {
                QMessageBox::warning(this, "Error", "Incorrect answer.");
            }
        }
    } else {
        QMessageBox::warning(this, "Error", "Email not found.");
    }
}
