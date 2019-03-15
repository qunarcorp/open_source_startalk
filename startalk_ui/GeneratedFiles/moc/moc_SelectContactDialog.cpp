/****************************************************************************
** Meta object code from reading C++ file 'SelectContactDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SelectContactDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SelectContactDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SelectContactDialog_t {
    QByteArrayData data[17];
    char stringdata[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SelectContactDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SelectContactDialog_t qt_meta_stringdata_SelectContactDialog = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 7),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 19),
QT_MOC_LITERAL(4, 49, 5),
QT_MOC_LITERAL(5, 55, 19),
QT_MOC_LITERAL(6, 75, 20),
QT_MOC_LITERAL(7, 96, 20),
QT_MOC_LITERAL(8, 117, 16),
QT_MOC_LITERAL(9, 134, 4),
QT_MOC_LITERAL(10, 139, 12),
QT_MOC_LITERAL(11, 152, 12),
QT_MOC_LITERAL(12, 165, 4),
QT_MOC_LITERAL(13, 170, 8),
QT_MOC_LITERAL(14, 179, 14),
QT_MOC_LITERAL(15, 194, 4),
QT_MOC_LITERAL(16, 199, 19)
    },
    "SelectContactDialog\0onClose\0\0"
    "onLeftSelectChanged\0index\0onLeftItemDBClicked\0"
    "onRightSelectChanged\0onRightItemDBClicked\0"
    "QListWidgetItem*\0item\0onAddClicked\0"
    "onDelClicked\0onOK\0onCancel\0onSearchResult\0"
    "text\0onSearchTextChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelectContactDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08,
       3,    1,   72,    2, 0x08,
       5,    1,   75,    2, 0x08,
       6,    0,   78,    2, 0x08,
       7,    1,   79,    2, 0x08,
      10,    1,   82,    2, 0x08,
      11,    1,   85,    2, 0x08,
      12,    1,   88,    2, 0x08,
      13,    1,   91,    2, 0x08,
      14,    1,   94,    2, 0x08,
      16,    1,   97,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void SelectContactDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SelectContactDialog *_t = static_cast<SelectContactDialog *>(_o);
        switch (_id) {
        case 0: _t->onClose((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onLeftSelectChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->onLeftItemDBClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->onRightSelectChanged(); break;
        case 4: _t->onRightItemDBClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->onAddClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->onDelClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->onOK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->onCancel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->onSearchResult((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->onSearchTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SelectContactDialog::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_SelectContactDialog.data,
      qt_meta_data_SelectContactDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *SelectContactDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelectContactDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SelectContactDialog.stringdata))
        return static_cast<void*>(const_cast< SelectContactDialog*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int SelectContactDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
