/****************************************************************************
** Meta object code from reading C++ file 'snipscreemtoolbar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../snipscreemtoolbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'snipscreemtoolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SnipScreemToolBar_t {
    QByteArrayData data[14];
    char stringdata[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SnipScreemToolBar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SnipScreemToolBar_t qt_meta_stringdata_SnipScreemToolBar = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 13),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 11),
QT_MOC_LITERAL(4, 45, 15),
QT_MOC_LITERAL(5, 61, 7),
QT_MOC_LITERAL(6, 69, 12),
QT_MOC_LITERAL(7, 82, 8),
QT_MOC_LITERAL(8, 91, 4),
QT_MOC_LITERAL(9, 96, 6),
QT_MOC_LITERAL(10, 103, 4),
QT_MOC_LITERAL(11, 108, 8),
QT_MOC_LITERAL(12, 117, 18),
QT_MOC_LITERAL(13, 136, 7)
    },
    "SnipScreemToolBar\0sgColorChange\0\0"
    "colorString\0sgPenSizeChange\0penSize\0"
    "sgToolSelect\0TOOLTYPE\0type\0sgUndo\0"
    "sgOk\0sgCancle\0onEditToolSelected\0"
    "checked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SnipScreemToolBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06,
       4,    1,   52,    2, 0x06,
       6,    1,   55,    2, 0x06,
       9,    0,   58,    2, 0x06,
      10,    0,   59,    2, 0x06,
      11,    0,   60,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      12,    1,   61,    2, 0x09,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   13,

       0        // eod
};

void SnipScreemToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SnipScreemToolBar *_t = static_cast<SnipScreemToolBar *>(_o);
        switch (_id) {
        case 0: _t->sgColorChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sgPenSizeChange((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->sgToolSelect((*reinterpret_cast< TOOLTYPE(*)>(_a[1]))); break;
        case 3: _t->sgUndo(); break;
        case 4: _t->sgOk(); break;
        case 5: _t->sgCancle(); break;
        case 6: _t->onEditToolSelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SnipScreemToolBar::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SnipScreemToolBar::sgColorChange)) {
                *result = 0;
            }
        }
        {
            typedef void (SnipScreemToolBar::*_t)(const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SnipScreemToolBar::sgPenSizeChange)) {
                *result = 1;
            }
        }
        {
            typedef void (SnipScreemToolBar::*_t)(TOOLTYPE );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SnipScreemToolBar::sgToolSelect)) {
                *result = 2;
            }
        }
        {
            typedef void (SnipScreemToolBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SnipScreemToolBar::sgUndo)) {
                *result = 3;
            }
        }
        {
            typedef void (SnipScreemToolBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SnipScreemToolBar::sgOk)) {
                *result = 4;
            }
        }
        {
            typedef void (SnipScreemToolBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SnipScreemToolBar::sgCancle)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject SnipScreemToolBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SnipScreemToolBar.data,
      qt_meta_data_SnipScreemToolBar,  qt_static_metacall, 0, 0}
};


const QMetaObject *SnipScreemToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SnipScreemToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SnipScreemToolBar.stringdata))
        return static_cast<void*>(const_cast< SnipScreemToolBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int SnipScreemToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SnipScreemToolBar::sgColorChange(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SnipScreemToolBar::sgPenSizeChange(const int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SnipScreemToolBar::sgToolSelect(TOOLTYPE _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SnipScreemToolBar::sgUndo()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void SnipScreemToolBar::sgOk()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void SnipScreemToolBar::sgCancle()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
