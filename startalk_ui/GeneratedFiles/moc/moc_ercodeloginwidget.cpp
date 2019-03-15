/****************************************************************************
** Meta object code from reading C++ file 'ercodeloginwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ercodeloginwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ercodeloginwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ErCodeLoginWidget_t {
    QByteArrayData data[9];
    char stringdata[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ErCodeLoginWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ErCodeLoginWidget_t qt_meta_stringdata_ErCodeLoginWidget = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 18),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 7),
QT_MOC_LITERAL(4, 46, 8),
QT_MOC_LITERAL(5, 55, 16),
QT_MOC_LITERAL(6, 72, 5),
QT_MOC_LITERAL(7, 78, 13),
QT_MOC_LITERAL(8, 92, 4)
    },
    "ErCodeLoginWidget\0onShowAuthUserInfo\0"
    "\0userurl\0nickname\0onResultUserInfo\0"
    "infor\0onCloseWidget\0bret\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ErCodeLoginWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x0a,
       5,    1,   34,    2, 0x0a,
       7,    1,   37,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Bool,    8,

       0        // eod
};

void ErCodeLoginWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ErCodeLoginWidget *_t = static_cast<ErCodeLoginWidget *>(_o);
        switch (_id) {
        case 0: _t->onShowAuthUserInfo((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->onResultUserInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onCloseWidget((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ErCodeLoginWidget::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_ErCodeLoginWidget.data,
      qt_meta_data_ErCodeLoginWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *ErCodeLoginWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ErCodeLoginWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ErCodeLoginWidget.stringdata))
        return static_cast<void*>(const_cast< ErCodeLoginWidget*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int ErCodeLoginWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
