#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "Contact.hpp"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QList>

class Database {
    public:
        // Database(QObject *parent = nullptr);
        bool openDatabase(const QString &databaseName);
        void closeDatabase();
        bool createTable();
        QList<Contact> readContacts();
        bool writeContacts(const QList<Contact> &contacts);

    private:
        QSqlDatabase db;
};

#endif // DATABASE_HPP