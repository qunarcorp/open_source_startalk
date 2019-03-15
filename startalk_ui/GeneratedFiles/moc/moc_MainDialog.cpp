/****************************************************************************
** Meta object code from reading C++ file 'MainDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainDialog_t {
    QByteArrayData data[17];
    char stringdata[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainDialog_t qt_meta_stringdata_MainDialog = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 15),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 15),
QT_MOC_LITERAL(4, 44, 7),
QT_MOC_LITERAL(5, 52, 11),
QT_MOC_LITERAL(6, 64, 10),
QT_MOC_LITERAL(7, 75, 11),
QT_MOC_LITERAL(8, 87, 21),
QT_MOC_LITERAL(9, 109, 6),
QT_MOC_LITERAL(10, 116, 19),
QT_MOC_LITERAL(11, 136, 4),
QT_MOC_LITERAL(12, 141, 12),
QT_MOC_LITERAL(13, 154, 5),
QT_MOC_LITERAL(14, 160, 18),
QT_MOC_LITERAL(15, 179, 5),
QT_MOC_LITERAL(16, 185, 19)
    },
    "MainDialog\0onShowMainWidge\0\0onHideMainWidge\0"
    "onShake\0onShakeMove\0framevalue\0"
    "onShakeOver\0onNodifyWindowClicked\0"
    "userID\0onSystemIconChanged\0path\0"
    "userNickName\0title\0onUnreadMsgChanged\0"
    "count\0hasNoCountUnreadMsg\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08,
       3,    0,   55,    2, 0x08,
       4,    0,   56,    2, 0x08,
       5,    1,   57,    2, 0x08,
       7,    0,   60,    2, 0x08,
       8,    1,   61,    2, 0x08,
      10,    4,   64,    2, 0x08,
      14,    2,   73,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,    9,   12,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   15,   16,

       0        // eod
};

void MainDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainDialog *_t = static_cast<MainDialog *>(_o);
        switch (_id) {
        case 0: _t->onShowMainWidge(); break;
        case 1: _t->onHideMainWidge(); break;
        case 2: _t->onShake(); break;
        case 3: _t->onShakeMove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onShakeOver(); break;
        case 5: _t->onNodifyWindowClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->onSystemIconChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 7: _t->onUnreadMsgChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject MainDialog::staticMetaObject = {
    { &LocalManWidget::staticMetaObject, qt_meta_stringdata_MainDialog.data,
      qt_meta_data_MainDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainDialog.stringdata))
        return static_cast<void*>(const_cast< MainDialog*>(this));
    return LocalManWidget::qt_metacast(_clname);
}

int MainDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
