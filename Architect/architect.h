#ifndef ARCHITECT_H
#define ARCHITECT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>

class Architect {
public:
    // Constructors
    Architect();
    Architect(int id, QString name, QString email, QString role, QString password, QString securityQuestion, QString securityAnswer);

    // CRUD Operations
    bool add();
    QSqlQueryModel* read();
    bool update(int id);
    bool remove(int id);

private:
    int id;
    QString name;
    QString email;
    QString role;
    QString password;
    QString securityQuestion;
    QString securityAnswer;
};

#endif // ARCHITECT_H
