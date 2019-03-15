/****************************************************************************
** Meta object code from reading C++ file 'WebViewCommObject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WebViewCommObject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WebViewCommObject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WebViewCommObject_t {
    QByteArrayData data[15];
    char stringdata[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WebViewCommObject_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WebViewCommObject_t qt_meta_stringdata_WebViewCommObject = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 14),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 4),
QT_MOC_LITERAL(4, 39, 26),
QT_MOC_LITERAL(5, 66, 3),
QT_MOC_LITERAL(6, 70, 11),
QT_MOC_LITERAL(7, 82, 7),
QT_MOC_LITERAL(8, 90, 11),
QT_MOC_LITERAL(9, 102, 11),
QT_MOC_LITERAL(10, 114, 5),
QT_MOC_LITERAL(11, 120, 3),
QT_MOC_LITERAL(12, 124, 14),
QT_MOC_LITERAL(13, 139, 14),
QT_MOC_LITERAL(14, 154, 12)
    },
    "WebViewCommObject\0sgCloseBrowser\0\0"
    "code\0sgOpenUrlInInnerWebBrowser\0url\0"
    "jsGotoToUrl\0openUrl\0openNewLink\0"
    "jsTranslate\0jslog\0log\0openNewSession\0"
    "otherSessionId\0closeBrowser\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebViewCommObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06,
       4,    1,   62,    2, 0x06,

 // methods: name, argc, parameters, tag, flags
       6,    1,   65,    2, 0x02,
       7,    1,   68,    2, 0x02,
       8,    1,   71,    2, 0x02,
       9,    1,   74,    2, 0x02,
      10,    1,   77,    2, 0x02,
      12,    1,   80,    2, 0x02,
      14,    1,   83,    2, 0x02,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::QString, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void WebViewCommObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WebViewCommObject *_t = static_cast<WebViewCommObject *>(_o);
        switch (_id) {
        case 0: _t->sgCloseBrowser((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sgOpenUrlInInnerWebBrowser((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->jsGotoToUrl((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->openUrl((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->openNewLink((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: { QString _r = _t->jsTranslate((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: _t->jslog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->openNewSession((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->closeBrowser((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WebViewCommObject::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebViewCommObject::sgCloseBrowser)) {
                *result = 0;
            }
        }
        {
            typedef void (WebViewCommObject::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebViewCommObject::sgOpenUrlInInnerWebBrowser)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject WebViewCommObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WebViewCommObject.data,
      qt_meta_data_WebViewCommObject,  qt_static_metacall, 0, 0}
};


const QMetaObject *WebViewCommObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebViewCommObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WebViewCommObject.stringdata))
        return static_cast<void*>(const_cast< WebViewCommObject*>(this));
    return QObject::qt_metacast(_clname);
}

int WebViewCommObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void WebViewCommObject::sgCloseBrowser(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WebViewCommObject::sgOpenUrlInInnerWebBrowser(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
