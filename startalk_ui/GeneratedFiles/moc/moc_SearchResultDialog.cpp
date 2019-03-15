/****************************************************************************
** Meta object code from reading C++ file 'SearchResultDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SearchResultDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SearchResultDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SearchResultDialog_t {
    QByteArrayData data[10];
    char stringdata[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SearchResultDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SearchResultDialog_t qt_meta_stringdata_SearchResultDialog = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 14),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 3),
QT_MOC_LITERAL(4, 39, 16),
QT_MOC_LITERAL(5, 56, 22),
QT_MOC_LITERAL(6, 79, 15),
QT_MOC_LITERAL(7, 95, 20),
QT_MOC_LITERAL(8, 116, 5),
QT_MOC_LITERAL(9, 122, 17)
    },
    "SearchResultDialog\0sgItemSelected\0\0"
    "str\0sgItemSelectedEx\0const QListWidgetItem*\0"
    "sgGroupSelected\0onLianxirenItemEnter\0"
    "pitem\0onMainWidgetMoved\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchResultDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06,
       4,    1,   42,    2, 0x06,
       6,    1,   45,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    1,   48,    2, 0x08,
       9,    0,   51,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    8,
    QMetaType::Void,

       0        // eod
};

void SearchResultDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SearchResultDialog *_t = static_cast<SearchResultDialog *>(_o);
        switch (_id) {
        case 0: _t->sgItemSelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sgItemSelectedEx((*reinterpret_cast< const QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->sgGroupSelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onLianxirenItemEnter((*reinterpret_cast< const QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->onMainWidgetMoved(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SearchResultDialog::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearchResultDialog::sgItemSelected)) {
                *result = 0;
            }
        }
        {
            typedef void (SearchResultDialog::*_t)(const QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearchResultDialog::sgItemSelectedEx)) {
                *result = 1;
            }
        }
        {
            typedef void (SearchResultDialog::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearchResultDialog::sgGroupSelected)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject SearchResultDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SearchResultDialog.data,
      qt_meta_data_SearchResultDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *SearchResultDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchResultDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SearchResultDialog.stringdata))
        return static_cast<void*>(const_cast< SearchResultDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SearchResultDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SearchResultDialog::sgItemSelected(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SearchResultDialog::sgItemSelectedEx(const QListWidgetItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SearchResultDialog::sgGroupSelected(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
