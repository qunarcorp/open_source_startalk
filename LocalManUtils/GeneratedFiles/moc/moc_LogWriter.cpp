/****************************************************************************
** Meta object code from reading C++ file 'LogWriter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LogWriter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LogWriter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Util__LogWriter_t {
    QByteArrayData data[12];
    char stringdata[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Util__LogWriter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Util__LogWriter_t qt_meta_stringdata_Util__LogWriter = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 7),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 7),
QT_MOC_LITERAL(4, 33, 6),
QT_MOC_LITERAL(5, 40, 6),
QT_MOC_LITERAL(6, 47, 9),
QT_MOC_LITERAL(7, 57, 9),
QT_MOC_LITERAL(8, 67, 6),
QT_MOC_LITERAL(9, 74, 24),
QT_MOC_LITERAL(10, 99, 4),
QT_MOC_LITERAL(11, 104, 3)
    },
    "Util::LogWriter\0sgDebug\0\0sgError\0"
    "sgInfo\0sgWarn\0sgConsole\0QtMsgType\0"
    "sgXmpp\0QXmppLogger::MessageType\0type\0"
    "val\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Util__LogWriter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,
       3,    1,   47,    2, 0x06,
       4,    1,   50,    2, 0x06,
       5,    1,   53,    2, 0x06,
       6,    2,   56,    2, 0x06,
       8,    2,   61,    2, 0x06,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString,   10,   11,

       0        // eod
};

void Util::LogWriter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LogWriter *_t = static_cast<LogWriter *>(_o);
        switch (_id) {
        case 0: _t->sgDebug((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sgError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->sgInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->sgWarn((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->sgConsole((*reinterpret_cast< QtMsgType(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->sgXmpp((*reinterpret_cast< QXmppLogger::MessageType(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LogWriter::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogWriter::sgDebug)) {
                *result = 0;
            }
        }
        {
            typedef void (LogWriter::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogWriter::sgError)) {
                *result = 1;
            }
        }
        {
            typedef void (LogWriter::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogWriter::sgInfo)) {
                *result = 2;
            }
        }
        {
            typedef void (LogWriter::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogWriter::sgWarn)) {
                *result = 3;
            }
        }
        {
            typedef void (LogWriter::*_t)(QtMsgType , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogWriter::sgConsole)) {
                *result = 4;
            }
        }
        {
            typedef void (LogWriter::*_t)(QXmppLogger::MessageType , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogWriter::sgXmpp)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject Util::LogWriter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Util__LogWriter.data,
      qt_meta_data_Util__LogWriter,  qt_static_metacall, 0, 0}
};


const QMetaObject *Util::LogWriter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Util::LogWriter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Util__LogWriter.stringdata))
        return static_cast<void*>(const_cast< LogWriter*>(this));
    return QObject::qt_metacast(_clname);
}

int Util::LogWriter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void Util::LogWriter::sgDebug(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Util::LogWriter::sgError(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Util::LogWriter::sgInfo(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Util::LogWriter::sgWarn(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Util::LogWriter::sgConsole(QtMsgType _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Util::LogWriter::sgXmpp(QXmppLogger::MessageType _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
