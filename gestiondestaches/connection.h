#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class Connection {
public:
    Connection();
    bool createconnect();
    bool ouvrirConnexion();
    void fermerConnexion();
    QSqlDatabase getDB();

private:
    QSqlDatabase db;
};

#endif // CONNECTION_H
