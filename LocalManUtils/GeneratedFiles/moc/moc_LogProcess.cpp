/****************************************************************************
** Meta object code from reading C++ file 'LogProcess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LogProcess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LogProcess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Util__LogProcess_t {
    QByteArrayData data[11];
    char stringdata[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Util__LogProcess_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Util__LogProcess_t qt_meta_stringdata_Util__LogProcess = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 8),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 8),
QT_MOC_LITERAL(4, 36, 7),
QT_MOC_LITERAL(5, 44, 7),
QT_MOC_LITERAL(6, 52, 10),
QT_MOC_LITERAL(7, 63, 9),
QT_MOC_LITERAL(8, 73, 7),
QT_MOC_LITERAL(9, 81, 4),
QT_MOC_LITERAL(10, 86, 3)
    },
    "Util::LogProcess\0LogDebug\0\0LogError\0"
    "LogInfo\0LogWarn\0LogConsole\0QtMsgType\0"
    "LogXmpp\0type\0val\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Util__LogProcess[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a,
       3,    1,   47,    2, 0x0a,
       4,    1,   50,    2, 0x0a,
       5,    1,   53,    2, 0x0a,
       6,    2,   56,    2, 0x0a,
       8,    2,   61,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    9,   10,

       0        // eod
};

void Util::LogProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LogProcess *_t = static_cast<LogProcess *>(_o);
        switch (_id) {
        case 0: _t->LogDebug((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->LogError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->LogInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->LogWarn((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->LogConsole((*reinterpret_cast< QtMsgType(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->LogXmpp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject Util::LogProcess::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Util__LogProcess.data,
      qt_meta_data_Util__LogProcess,  qt_static_metacall, 0, 0}
};


const QMetaObject *Util::LogProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Util::LogProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Util__LogProcess.stringdata))
        return static_cast<void*>(const_cast< LogProcess*>(this));
    return QObject::qt_metacast(_clname);
}

int Util::LogProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
