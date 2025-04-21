// loginform.h
#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QMessageBox>

namespace Ui {
class LoginForm;
}

class LoginForm : public QDialog {
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

private slots:
    void on_btnLogin_clicked();
    void on_btnForgotPassword_clicked();

private:
    Ui::LoginForm *ui;
    QString hashString(const QString &input);
    void openPasswordResetDialog(const QString &email);
};

#endif // LOGINFORM_H
