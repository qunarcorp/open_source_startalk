/****************************************************************************
** Meta object code from reading C++ file 'LambdaRunnnable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LambdaRunnnable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LambdaRunnnable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Util__LambdaRunnnable_t {
    QByteArrayData data[6];
    char stringdata[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Util__LambdaRunnnable_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Util__LambdaRunnnable_t qt_meta_stringdata_Util__LambdaRunnnable = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 11),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 10),
QT_MOC_LITERAL(4, 46, 7),
QT_MOC_LITERAL(5, 54, 5)
    },
    "Util::LambdaRunnnable\0excuteBlock\0\0"
    "postexcute\0onBlock\0onRun\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Util__LambdaRunnnable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06,
       3,    0,   35,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x09,
       5,    0,   37,    2, 0x09,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Util::LambdaRunnnable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LambdaRunnnable *_t = static_cast<LambdaRunnnable *>(_o);
        switch (_id) {
        case 0: _t->excuteBlock(); break;
        case 1: _t->postexcute(); break;
        case 2: _t->onBlock(); break;
        case 3: _t->onRun(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LambdaRunnnable::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LambdaRunnnable::excuteBlock)) {
                *result = 0;
            }
        }
        {
            typedef void (LambdaRunnnable::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LambdaRunnnable::postexcute)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Util::LambdaRunnnable::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Util__LambdaRunnnable.data,
      qt_meta_data_Util__LambdaRunnnable,  qt_static_metacall, 0, 0}
};


const QMetaObject *Util::LambdaRunnnable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Util::LambdaRunnnable::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Util__LambdaRunnnable.stringdata))
        return static_cast<void*>(const_cast< LambdaRunnnable*>(this));
    return QObject::qt_metacast(_clname);
}

int Util::LambdaRunnnable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Util::LambdaRunnnable::excuteBlock()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Util::LambdaRunnnable::postexcute()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
