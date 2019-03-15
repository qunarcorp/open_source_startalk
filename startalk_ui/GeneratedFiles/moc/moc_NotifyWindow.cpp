/****************************************************************************
** Meta object code from reading C++ file 'NotifyWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../NotifyWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NotifyWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NotifyWindow_t {
    QByteArrayData data[8];
    char stringdata[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NotifyWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NotifyWindow_t qt_meta_stringdata_NotifyWindow = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 18),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 8),
QT_MOC_LITERAL(4, 42, 13),
QT_MOC_LITERAL(5, 56, 15),
QT_MOC_LITERAL(6, 72, 21),
QT_MOC_LITERAL(7, 94, 18)
    },
    "NotifyWindow\0sgOpenConversation\0\0"
    "onClosed\0onTextClicked\0showNotifyItems\0"
    "onTrayIconDoubleClick\0onChangeNotifyItem\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NotifyWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,   47,    2, 0x08,
       4,    0,   50,    2, 0x08,
       5,    0,   51,    2, 0x08,
       6,    0,   52,    2, 0x08,
       7,    0,   53,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NotifyWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NotifyWindow *_t = static_cast<NotifyWindow *>(_o);
        switch (_id) {
        case 0: _t->sgOpenConversation((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onClosed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onTextClicked(); break;
        case 3: _t->showNotifyItems(); break;
        case 4: _t->onTrayIconDoubleClick(); break;
        case 5: _t->onChangeNotifyItem(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NotifyWindow::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NotifyWindow::sgOpenConversation)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject NotifyWindow::staticMetaObject = {
    { &LocalManWidget::staticMetaObject, qt_meta_stringdata_NotifyWindow.data,
      qt_meta_data_NotifyWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *NotifyWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NotifyWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NotifyWindow.stringdata))
        return static_cast<void*>(const_cast< NotifyWindow*>(this));
    return LocalManWidget::qt_metacast(_clname);
}

int NotifyWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManWidget::qt_metacall(_c, _id, _a);
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
void NotifyWindow::sgOpenConversation(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
