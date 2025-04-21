#include "architect.h"
#include <QSqlError>
#include <QCryptographicHash>
QString hashString(const QString &input) {
    return QString(QCryptographicHash::hash(input.toUtf8(), QCryptographicHash::Sha256).toHex());
}

// Default Constructor
Architect::Architect() {
    id = 0;
    name = "";
    email = "";
    role = "";
    password = "";
    securityQuestion = "";
    securityAnswer = "";
}

// Parameterized Constructor
Architect::Architect(int id, QString name, QString email, QString role, QString password, QString securityQuestion, QString securityAnswer) {
    this->id = id;
    this->name = name;
    this->email = email;
    this->role = role;
    this->password = password;
    this->securityQuestion = securityQuestion;
    this->securityAnswer = securityAnswer;
}

// CREATE (Insert Data)
bool Architect::add() {
    QSqlQuery query;
    query.prepare("INSERT INTO ARCHITECTE (ID_ARCHITECTE, NOM, COURRIEL, ROLE, MOT_DE_PASSE, SECURITY_QUESTION, SECURITY_ANSWER) "
                  "VALUES (:id, :name, :email, :role, :password, :securityQuestion, :securityAnswer)");
    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":email", email);
    query.bindValue(":role", role);
    query.bindValue(":password", hashString(password));
    query.bindValue(":securityQuestion", securityQuestion);
    query.bindValue(":securityAnswer", hashString(securityAnswer));

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Add Error: " << query.lastError();
        return false;
    }
}

// READ (Fetch Data)
QSqlQueryModel* Architect::read() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM ARCHITECTE"); // Select all columns
    return model;
}

// UPDATE (Modify Data)
bool Architect::update(int id) {
    QSqlQuery query;
    query.prepare("UPDATE ARCHITECTE SET NOM=:name, COURRIEL=:email, ROLE=:role, MOT_DE_PASSE=:password, "
                  "SECURITY_QUESTION=:securityQuestion, SECURITY_ANSWER=:securityAnswer WHERE ID_ARCHITECTE=:id");
    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":email", email);
    query.bindValue(":role", role);
    query.bindValue(":password", hashString(password));
    query.bindValue(":securityQuestion", securityQuestion);
    query.bindValue(":securityAnswer", hashString(securityAnswer));

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Update Error: " << query.lastError();
        return false;
    }
}

// DELETE (Remove Entry)
bool Architect::remove(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM ARCHITECTE WHERE ID_ARCHITECTE=:id");
    query.bindValue(":id", id);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Delete Error: " << query.lastError();
        return false;
    }
}
