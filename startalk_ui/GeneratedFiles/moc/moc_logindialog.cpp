/****************************************************************************
** Meta object code from reading C++ file 'logindialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../logindialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logindialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LoginDialog_t {
    QByteArrayData data[23];
    char stringdata[333];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LoginDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LoginDialog_t qt_meta_stringdata_LoginDialog = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 14),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 11),
QT_MOC_LITERAL(4, 40, 14),
QT_MOC_LITERAL(5, 55, 14),
QT_MOC_LITERAL(6, 70, 12),
QT_MOC_LITERAL(7, 83, 17),
QT_MOC_LITERAL(8, 101, 4),
QT_MOC_LITERAL(9, 106, 5),
QT_MOC_LITERAL(10, 112, 17),
QT_MOC_LITERAL(11, 130, 6),
QT_MOC_LITERAL(12, 137, 8),
QT_MOC_LITERAL(13, 146, 23),
QT_MOC_LITERAL(14, 170, 22),
QT_MOC_LITERAL(15, 193, 11),
QT_MOC_LITERAL(16, 205, 9),
QT_MOC_LITERAL(17, 215, 21),
QT_MOC_LITERAL(18, 237, 43),
QT_MOC_LITERAL(19, 281, 12),
QT_MOC_LITERAL(20, 294, 23),
QT_MOC_LITERAL(21, 318, 6),
QT_MOC_LITERAL(22, 325, 6)
    },
    "LoginDialog\0sgLoginSuccess\0\0sgLoginFail\0"
    "onLoginSucceed\0onLoginFailure\0"
    "onDisconnect\0onProgressDisplay\0done\0"
    "total\0onUpdateLoginInfo\0strmsg\0onSubmit\0"
    "onAutoLoginStateChanged\0onRememberStateChanged\0"
    "onLoginInfo\0loginInfo\0onAccountItemSelected\0"
    "QSharedPointer<Biz::LoginAccountConfigInfo>\0"
    "loginaccount\0onServerPolicyVillation\0"
    "nError\0reason\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06,
       3,    1,   82,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   85,    2, 0x08,
       5,    2,   86,    2, 0x08,
       6,    0,   91,    2, 0x08,
       7,    2,   92,    2, 0x08,
      10,    1,   97,    2, 0x08,
      12,    1,  100,    2, 0x08,
      13,    1,  103,    2, 0x08,
      14,    1,  106,    2, 0x08,
      15,    1,  109,    2, 0x08,
      17,    1,  112,    2, 0x08,
      20,    2,  115,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    8,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   21,   22,

       0        // eod
};

void LoginDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginDialog *_t = static_cast<LoginDialog *>(_o);
        switch (_id) {
        case 0: _t->sgLoginSuccess((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sgLoginFail((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onLoginSucceed(); break;
        case 3: _t->onLoginFailure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->onDisconnect(); break;
        case 5: _t->onProgressDisplay((*reinterpret_cast< const qint64(*)>(_a[1])),(*reinterpret_cast< const qint64(*)>(_a[2]))); break;
        case 6: _t->onUpdateLoginInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->onSubmit((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->onAutoLoginStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->onRememberStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->onLoginInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->onAccountItemSelected((*reinterpret_cast< const QSharedPointer<Biz::LoginAccountConfigInfo>(*)>(_a[1]))); break;
        case 12: _t->onServerPolicyVillation((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSharedPointer<Biz::LoginAccountConfigInfo> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoginDialog::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginDialog::sgLoginSuccess)) {
                *result = 0;
            }
        }
        {
            typedef void (LoginDialog::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginDialog::sgLoginFail)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject LoginDialog::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_LoginDialog.data,
      qt_meta_data_LoginDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *LoginDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LoginDialog.stringdata))
        return static_cast<void*>(const_cast< LoginDialog*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int LoginDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void LoginDialog::sgLoginSuccess(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LoginDialog::sgLoginFail(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
