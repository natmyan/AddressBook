#include "TableInterface.hpp"

#include <QInputDialog>
#include <QHeaderView>
#include <QSqlTableModel>
#include <QStandardItemModel>

TableInterface::TableInterface(TableLogic* logic, QWidget* parent) :
    QWidget(parent),
    tabWidget_(new QTabWidget),
    addTabButton_(new QPushButton("Add Tab")),
    addContactButton_(new QPushButton("Add")),
    signOutButton_(new QPushButton("Sign Out")),
    searchButton_(new QPushButton("Search")),
    currentTable_(new QTableWidget),
    logic_(logic)
{
    setupUi();
    connect(addTabButton_, &QPushButton::clicked, this, &TableInterface::onAddTabClicked);
    connect(addContactButton_, &QPushButton::clicked, this, &TableInterface::onAddContactClicked);
    connect(searchButton_, &QPushButton::clicked, this, &TableInterface::onSearchContacts);
    connect(signOutButton_, &QPushButton::clicked, this, &TableInterface::onSignOutClicked);
    setupTabs();
    onShowDatabaseContents();
}

void TableInterface::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(addContactButton_);
    buttonLayout->addWidget(searchButton_);
    buttonLayout->addWidget(signOutButton_);
    
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(addTabButton_);

    for (int i = 0; i < tabNames_.getTabNames().size(); ++i) {
        QTableWidget* table = new QTableWidget;
        tabWidget_->addTab(table, tabNames_.getTabNames().at(i));
    }
    tabWidget_->addTab(addTabButton_, "+");
    
    mainLayout->addWidget(tabWidget_);
}

void TableInterface::setupTabs() {
    connect(tabWidget_, &QTabWidget::currentChanged, [this](int index) {
        if (index == tabWidget_->count() - 1) {
            onAddTabClicked();
            logic_->addContact();
        } 
        else {
            currentTable_ = qobject_cast<QTableWidget*>(tabWidget_->widget(index));
            currentTable_->setProperty("TabName", tabWidget_->tabText(index));
        }
    });

    connect(addTabButton_, &QPushButton::clicked, this, &TableInterface::onAddTabClicked);
    connect(currentTable_, &QTableWidget::itemDoubleClicked, this, &TableInterface::onEditContact);
}

void TableInterface::onSignOutClicked() {
    emit sigSignOutClicked();
}

void TableInterface::onAddTabClicked() {
    bool ok;
    QString tabName = QInputDialog::getText(this, "New Tab", "Enter tab name:", QLineEdit::Normal, QString(), &ok);

    if (ok && !tabName.isEmpty()) {
        QTableWidget* newTable = new QTableWidget;
        tabWidget_->insertTab(tabWidget_->count() - 1, newTable, tabName);
        tabWidget_->setCurrentIndex(tabWidget_->count() - 2);
        tabNames_.addTabName(tabName);
    }
}

void TableInterface::onAddContactClicked() {
    if (currentTable_) {
        logic_->addContact();
        onShowDatabaseContents();
    }
}

void TableInterface::onEditContact(QTableWidgetItem* item) {
    if (currentTable_)
        logic_->editContact(item);
}

void TableInterface::onSearchContacts() {
    logic_->searchContacts();
}

QTableWidget* TableInterface::createEditableTable() {
    QTableWidget* table = new QTableWidget(this);
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"Name", "Phone", "Email"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(table, &QTableWidget::itemDoubleClicked, this, &TableInterface::onEditContact);

    return table;
}

QTableWidget* TableInterface::getCurrentTable() const {
    return currentTable_;
}

void TableInterface::onShowDatabaseContents() {
    for (int tabIndex = 0; tabIndex < tabWidget_->count() - 1; ++tabIndex) {
        QTableWidget* table = qobject_cast<QTableWidget*>(tabWidget_->widget(tabIndex));

        if (table) {
            table->clearContents();
            table->setRowCount(0);

            QSqlTableModel model(nullptr, logic_->getDB());
            model.setTable("contacts");

            if (model.select()) {
                int rowCount = model.rowCount();
                int columnCount = model.columnCount();

                qDebug() << rowCount << columnCount;

                table->setRowCount(rowCount);
                table->setColumnCount(columnCount);
                
                for (int row = 0; row < rowCount; ++row) {
                    QString tabNameFromData = model.data(model.index(row, 3)).toString(); 
                    if (tabNameFromData == tabWidget_->tabText(tabIndex)) {
                        tabWidget_->setCurrentIndex(tabIndex);
                        for (int col = 0; col < columnCount; ++col) {
                            QTableWidgetItem* item = new QTableWidgetItem(model.data(model.index(row, col)).toString());
                            table->setItem(row, col, item);
                        }
                    }
                    else {
                        int existingTabIndex = -1;
                        for (int i = 0; i < tabWidget_->count(); ++i) {
                            if (tabWidget_->tabText(i) == tabNameFromData) {
                                existingTabIndex = i;
                                break;
                            }
                        }
                        if (existingTabIndex == -1) {
                            QTableWidget* newTable = new QTableWidget(this);
                            newTable->setColumnCount(columnCount);
                            tabWidget_->insertTab(tabWidget_->count() - 1, newTable, tabNameFromData);
                            tabWidget_->setCurrentIndex(tabWidget_->count() - 2); 

                            for (int col = 0; col < columnCount; ++col) {
                                QTableWidgetItem* item = new QTableWidgetItem(model.data(model.index(row, col)).toString());
                                newTable->setItem(0, col, item);
                            }
                        }
                    }
                }
            } 
            else {
                qDebug() << "Failed to fetch database contents: " << model.lastError().text();
            }
        }
    }
}


/*void TableInterface::onShowDatabaseContents() {
    for (int tabIndex = 0; tabIndex < tabWidget->count() - 1; ++tabIndex) {
        QTableWidget* table = qobject_cast<QTableWidget*>(tabWidget->widget(tabIndex));
        if (table) {
            table->clearContents();
            table->setRowCount(0);

            QSqlTableModel model(nullptr, logic->getDB());
            model.setTable("contacts");

            if (model.select()) {
                int rowCount = model.rowCount();
                int columnCount = model.columnCount();

                qDebug() << rowCount << columnCount;
                
                auto currTableRowCount = 0;
                QList<int> rows;
                int existingTabIndex = -1;
                QString tabNameFromData;

                for (int row = 0; row < rowCount; ++row) {
                    tabNameFromData = model.data(model.index(row, 3)).toString(); 
                    if (tabNameFromData == tabWidget->tabText(tabIndex)) {
                        ++currTableRowCount;
                        rows.append(row);
                    }
                    else {
                        existingTabIndex = -2;
                        for (int i = 0; i < tabWidget->count(); ++i) {
                            if (tabWidget->tabText(i) == tabNameFromData) {
                                existingTabIndex = i;
                                break;
                            }
                        }
                    }
                }
                table->setRowCount(currTableRowCount);
                table->setColumnCount(columnCount);

                for (auto row : rows) {
                    if (existingTabIndex == -1) {
                        tabWidget->setCurrentIndex(tabIndex);
                        for (int col = 0; col < columnCount; ++col) {
                            QTableWidgetItem* item = new QTableWidgetItem(model.data(model.index(row, col)).toString());
                            table->setItem(row, col, item);
                        }
                    }
                    else if (existingTabIndex == -2) {
                        QTableWidget* newTable = new QTableWidget(this);
                        newTable->setColumnCount(columnCount);
                        tabWidget->insertTab(tabWidget->count() - 1, newTable, tabNameFromData);
                        tabWidget->setCurrentIndex(tabWidget->count() - 2);
                        for (int col = 0; col < columnCount; ++col) {
                            QTableWidgetItem* item = new QTableWidgetItem(model.data(model.index(row, col)).toString());
                            newTable->setItem(0, col, item);
                        }
                    }
                }
            }
            else {
                qDebug() << "Failed to fetch database contents: " << model.lastError().text();
            }
        }
    }
}*/
