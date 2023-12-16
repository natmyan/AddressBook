#ifndef SIGN_IN_MENU_LOGIC_HPP
#define SIGN_IN_MENU_LOGIC_HPP

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QDebug>

class SignInMenuLogic : public QObject {
    Q_OBJECT

    public:
        explicit SignInMenuLogic(QObject *parent = nullptr);

    signals:
        void sigSignInSuccess(QString username);
        void sigSignInFailed();

    public slots:
        void signIn(QString username, QString password);

    private:
        bool checkCredentials(const QString &username, const QString &hashedPassword);
        QString hashPassword(const QString &password);
        bool openDatabase();
    
    private:
        QSqlDatabase db;
};

#endif // SIGN_IN_MENU_LOGIC_HPP

