/****************************************************************************
** Meta object code from reading C++ file 'AddressWidget.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GUI/AddressWidget.hpp"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddressWidget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSAddressWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAddressWidgetENDCLASS = QtMocHelpers::stringData(
    "AddressWidget",
    "selectionChanged",
    "",
    "QItemSelection",
    "selected",
    "showAddEntryDialog",
    "showOpenEntryDialog",
    "addEntry",
    "name",
    "phone",
    "email",
    "openEntry",
    "filePath",
    "editEntry",
    "removeEntry",
    "addNewEntry",
    "openNewEntry"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAddressWidgetENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[14];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[9];
    char stringdata5[19];
    char stringdata6[20];
    char stringdata7[9];
    char stringdata8[5];
    char stringdata9[6];
    char stringdata10[6];
    char stringdata11[10];
    char stringdata12[9];
    char stringdata13[10];
    char stringdata14[12];
    char stringdata15[12];
    char stringdata16[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAddressWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAddressWidgetENDCLASS_t qt_meta_stringdata_CLASSAddressWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "AddressWidget"
        QT_MOC_LITERAL(14, 16),  // "selectionChanged"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 14),  // "QItemSelection"
        QT_MOC_LITERAL(47, 8),  // "selected"
        QT_MOC_LITERAL(56, 18),  // "showAddEntryDialog"
        QT_MOC_LITERAL(75, 19),  // "showOpenEntryDialog"
        QT_MOC_LITERAL(95, 8),  // "addEntry"
        QT_MOC_LITERAL(104, 4),  // "name"
        QT_MOC_LITERAL(109, 5),  // "phone"
        QT_MOC_LITERAL(115, 5),  // "email"
        QT_MOC_LITERAL(121, 9),  // "openEntry"
        QT_MOC_LITERAL(131, 8),  // "filePath"
        QT_MOC_LITERAL(140, 9),  // "editEntry"
        QT_MOC_LITERAL(150, 11),  // "removeEntry"
        QT_MOC_LITERAL(162, 11),  // "addNewEntry"
        QT_MOC_LITERAL(174, 12)   // "openNewEntry"
    },
    "AddressWidget",
    "selectionChanged",
    "",
    "QItemSelection",
    "selected",
    "showAddEntryDialog",
    "showOpenEntryDialog",
    "addEntry",
    "name",
    "phone",
    "email",
    "openEntry",
    "filePath",
    "editEntry",
    "removeEntry",
    "addNewEntry",
    "openNewEntry"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAddressWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   71,    2, 0x0a,    3 /* Public */,
       6,    0,   72,    2, 0x0a,    4 /* Public */,
       7,    3,   73,    2, 0x0a,    5 /* Public */,
      11,    1,   80,    2, 0x0a,    9 /* Public */,
      13,    0,   83,    2, 0x0a,   11 /* Public */,
      14,    0,   84,    2, 0x0a,   12 /* Public */,
      15,    0,   85,    2, 0x0a,   13 /* Public */,
      16,    0,   86,    2, 0x0a,   14 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    9,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject AddressWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QTabWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSAddressWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAddressWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAddressWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AddressWidget, std::true_type>,
        // method 'selectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>,
        // method 'showAddEntryDialog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showOpenEntryDialog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addEntry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'openEntry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'editEntry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeEntry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addNewEntry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openNewEntry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AddressWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AddressWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->selectionChanged((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1]))); break;
        case 1: _t->showAddEntryDialog(); break;
        case 2: _t->showOpenEntryDialog(); break;
        case 3: _t->addEntry((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 4: _t->openEntry((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->editEntry(); break;
        case 6: _t->removeEntry(); break;
        case 7: _t->addNewEntry(); break;
        case 8: _t->openNewEntry(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QItemSelection >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AddressWidget::*)(const QItemSelection & );
            if (_t _q_method = &AddressWidget::selectionChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *AddressWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddressWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAddressWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QTabWidget::qt_metacast(_clname);
}

int AddressWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void AddressWidget::selectionChanged(const QItemSelection & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
