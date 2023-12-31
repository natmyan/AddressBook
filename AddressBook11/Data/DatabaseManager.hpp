#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "Contact.hpp"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QList>

class DatabaseManager : public QSqlDatabase {    
    public:
        DatabaseManager(const QString& fileName);
        ~DatabaseManager();

    public:
        void makeDatabase(const QString& fileName);
        void openDatabase(const QString& filePath, const QString& dbName, const QString& fields);
        void closeDatabase();
        bool createTable();
        QList<Contact> readContacts();
        bool writeContacts(const QList<Contact>& contacts);
        QSqlDatabase getDatabase();
        void setDatabase(const QSqlDatabase& db);
        void changeDatabaseName(const QString& fileName);

    private:
        QSqlDatabase db_;
        QString fileName_;
};

#endif // DATABASE_HPP
