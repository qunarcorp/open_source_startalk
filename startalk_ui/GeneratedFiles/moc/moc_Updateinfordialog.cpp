/****************************************************************************
** Meta object code from reading C++ file 'Updateinfordialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Updateinfordialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Updateinfordialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UpdateInforDialog_t {
    QByteArrayData data[7];
    char stringdata[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_UpdateInforDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_UpdateInforDialog_t qt_meta_stringdata_UpdateInforDialog = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 13),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 14),
QT_MOC_LITERAL(4, 48, 17),
QT_MOC_LITERAL(5, 66, 4),
QT_MOC_LITERAL(6, 71, 5)
    },
    "UpdateInforDialog\0onOnceClicked\0\0"
    "onLaterClicked\0onProgressDisplay\0done\0"
    "total\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UpdateInforDialog[] = {

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
       1,    1,   29,    2, 0x08,
       3,    1,   32,    2, 0x08,
       4,    2,   35,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    5,    6,

       0        // eod
};

void UpdateInforDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UpdateInforDialog *_t = static_cast<UpdateInforDialog *>(_o);
        switch (_id) {
        case 0: _t->onOnceClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onLaterClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onProgressDisplay((*reinterpret_cast< const qint64(*)>(_a[1])),(*reinterpret_cast< const qint64(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject UpdateInforDialog::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_UpdateInforDialog.data,
      qt_meta_data_UpdateInforDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *UpdateInforDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UpdateInforDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UpdateInforDialog.stringdata))
        return static_cast<void*>(const_cast< UpdateInforDialog*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int UpdateInforDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
