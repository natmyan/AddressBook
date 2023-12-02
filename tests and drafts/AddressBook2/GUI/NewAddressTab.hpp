#ifndef NEW_ADDRESS_TAB_HPP
#define NEW_ADDRESS_TAB_HPP

#include <QWidget>

class NewAddressTab : public QWidget {
    Q_OBJECT

    public:
        NewAddressTab(QWidget *parent = nullptr);

    public slots:
        void addEntry();
        void openEntry();

    signals:
        void sendDetails(const QString &name, const QString &phone, const QString &email);
        void sendFilePath(const QString &filePath);
};

#endif // NEW_ADDRESS_TAB_HPP