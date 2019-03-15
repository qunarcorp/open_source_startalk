/****************************************************************************
** Meta object code from reading C++ file 'SystemIcon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SystemIcon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SystemIcon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SystemIcon_t {
    QByteArrayData data[7];
    char stringdata[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SystemIcon_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SystemIcon_t qt_meta_stringdata_SystemIcon = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 13),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 12),
QT_MOC_LITERAL(4, 39, 12),
QT_MOC_LITERAL(5, 52, 20),
QT_MOC_LITERAL(6, 73, 33)
    },
    "SystemIcon\0sgDoubleClick\0\0sgMouseHover\0"
    "sgMouseLeave\0onTrayIconActivation\0"
    "QSystemTrayIcon::ActivationReason\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SystemIcon[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06,
       3,    1,   35,    2, 0x06,
       4,    0,   38,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    1,   39,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRect,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    2,

       0        // eod
};

void SystemIcon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SystemIcon *_t = static_cast<SystemIcon *>(_o);
        switch (_id) {
        case 0: _t->sgDoubleClick(); break;
        case 1: _t->sgMouseHover((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 2: _t->sgMouseLeave(); break;
        case 3: _t->onTrayIconActivation((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SystemIcon::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SystemIcon::sgDoubleClick)) {
                *result = 0;
            }
        }
        {
            typedef void (SystemIcon::*_t)(const QRect & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SystemIcon::sgMouseHover)) {
                *result = 1;
            }
        }
        {
            typedef void (SystemIcon::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SystemIcon::sgMouseLeave)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject SystemIcon::staticMetaObject = {
    { &QSystemTrayIcon::staticMetaObject, qt_meta_stringdata_SystemIcon.data,
      qt_meta_data_SystemIcon,  qt_static_metacall, 0, 0}
};


const QMetaObject *SystemIcon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SystemIcon::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SystemIcon.stringdata))
        return static_cast<void*>(const_cast< SystemIcon*>(this));
    return QSystemTrayIcon::qt_metacast(_clname);
}

int SystemIcon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSystemTrayIcon::qt_metacall(_c, _id, _a);
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
void SystemIcon::sgDoubleClick()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SystemIcon::sgMouseHover(const QRect & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SystemIcon::sgMouseLeave()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
