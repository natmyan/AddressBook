#include "SignInMenuLogic.hpp"
#include "../Data/User.hpp"

#include <QSqlError>

SignInMenuLogic::SignInMenuLogic(QObject* parent) : QObject(parent) {
    openDatabase();
}

void SignInMenuLogic::signIn(QString& username, QString& password) {
    QString hashedPassword = hashPassword(password);

    if (checkCredentials(username, hashedPassword)) {
        User::setName(username);
        qDebug() << "Sign in successful!";
        emit sigSignInSuccess(username, password);
    } 
    else {
        qDebug() << "Sign in failed. Please try again.";
        emit sigSignInFailed();
    }
}

bool SignInMenuLogic::checkCredentials(const QString& username, const QString& hashedPassword) {
    if (!openDatabase()) {
        qDebug() << "Failed to open the database.";
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT username, password FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", hashedPassword);

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return false;
    }

    return query.next();
}

QString SignInMenuLogic::hashPassword(const QString& password) {
    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(password.toUtf8());
    return hash.result().toHex();
}

bool SignInMenuLogic::openDatabase() {
    db_ = QSqlDatabase::addDatabase("QSQLITE");
    db_.setDatabaseName("../zinfo/users.db");

    if (!db_.open()) {
        qDebug() << "Database connection failed:" << db_.lastError().text();
        return false;
    }

    return true;
}

QSqlDatabase SignInMenuLogic::getUserDB() {
    return db_;
}