#include "connection.h"
#include <QSqlError>
#include <QDebug>

Connection::Connection() {
    // Check if the connection already exists before adding a new one
    if (!QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::addDatabase("QODBC", "qt_sql_default_connection"); // Only add connection if not already present
    } else {
        db = QSqlDatabase::database("qt_sql_default_connection"); // Use existing connection
    }

    db.setDatabaseName("architopia"); // Make sure this matches your ODBC setup
    db.setUserName("f3ddi");
    db.setPassword("123456");
}

bool Connection::createconnect() {
    return ouvrirConnexion();
}

bool Connection::ouvrirConnexion() {
    if (!db.open()) {
        qDebug() << "Error connecting to database: " << db.lastError().text();
        return false;
    }
    qDebug() << "Database connection successful!";
    return true;
}

void Connection::fermerConnexion() {
    db.close();
    QSqlDatabase::removeDatabase("qt_sql_default_connection"); // Remove connection when closing
}

QSqlDatabase Connection::getDB() {
    return db;
}
