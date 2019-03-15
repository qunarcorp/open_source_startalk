/****************************************************************************
** Meta object code from reading C++ file 'FriendsSearcher.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FriendsSearcher.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FriendsSearcher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FriendsSearcher_t {
    QByteArrayData data[14];
    char stringdata[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_FriendsSearcher_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_FriendsSearcher_t qt_meta_stringdata_FriendsSearcher = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 17),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 1),
QT_MOC_LITERAL(4, 37, 7),
QT_MOC_LITERAL(5, 45, 24),
QT_MOC_LITERAL(6, 70, 8),
QT_MOC_LITERAL(7, 79, 29),
QT_MOC_LITERAL(8, 109, 6),
QT_MOC_LITERAL(9, 116, 6),
QT_MOC_LITERAL(10, 123, 3),
QT_MOC_LITERAL(11, 127, 22),
QT_MOC_LITERAL(12, 150, 5),
QT_MOC_LITERAL(13, 156, 5)
    },
    "FriendsSearcher\0onGoSearchClicked\0\0b\0"
    "onClose\0onDomainListSelectChange\0"
    "selectid\0onFriendVerifyResponceReceive\0"
    "result\0reason\0jid\0onFriendDeletedReceive\0"
    "reson\0ntype\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FriendsSearcher[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a,
       4,    0,   42,    2, 0x0a,
       5,    1,   43,    2, 0x0a,
       7,    3,   46,    2, 0x0a,
      11,    3,   53,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,   12,   10,   13,

       0        // eod
};

void FriendsSearcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FriendsSearcher *_t = static_cast<FriendsSearcher *>(_o);
        switch (_id) {
        case 0: _t->onGoSearchClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onClose(); break;
        case 2: _t->onDomainListSelectChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onFriendVerifyResponceReceive((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: _t->onFriendDeletedReceive((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject FriendsSearcher::staticMetaObject = {
    { &LocalManWidget::staticMetaObject, qt_meta_stringdata_FriendsSearcher.data,
      qt_meta_data_FriendsSearcher,  qt_static_metacall, 0, 0}
};


const QMetaObject *FriendsSearcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FriendsSearcher::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FriendsSearcher.stringdata))
        return static_cast<void*>(const_cast< FriendsSearcher*>(this));
    return LocalManWidget::qt_metacast(_clname);
}

int FriendsSearcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
