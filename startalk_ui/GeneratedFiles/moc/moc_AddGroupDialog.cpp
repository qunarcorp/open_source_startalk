/****************************************************************************
** Meta object code from reading C++ file 'AddGroupDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AddGroupDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddGroupDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddGroupDialog_t {
    QByteArrayData data[10];
    char stringdata[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AddGroupDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AddGroupDialog_t qt_meta_stringdata_AddGroupDialog = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 8),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 4),
QT_MOC_LITERAL(4, 30, 7),
QT_MOC_LITERAL(5, 38, 11),
QT_MOC_LITERAL(6, 50, 14),
QT_MOC_LITERAL(7, 65, 13),
QT_MOC_LITERAL(8, 79, 16),
QT_MOC_LITERAL(9, 96, 4)
    },
    "AddGroupDialog\0onCancel\0\0onOK\0onClose\0"
    "onAddMember\0onRemoveMember\0onClickedItem\0"
    "QListWidgetItem*\0item\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddGroupDialog[] = {

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
       1,    1,   44,    2, 0x08,
       3,    1,   47,    2, 0x08,
       4,    1,   50,    2, 0x08,
       5,    1,   53,    2, 0x08,
       6,    1,   56,    2, 0x08,
       7,    1,   59,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void AddGroupDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddGroupDialog *_t = static_cast<AddGroupDialog *>(_o);
        switch (_id) {
        case 0: _t->onCancel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onOK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onClose((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onAddMember((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onRemoveMember((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onClickedItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AddGroupDialog::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_AddGroupDialog.data,
      qt_meta_data_AddGroupDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *AddGroupDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddGroupDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddGroupDialog.stringdata))
        return static_cast<void*>(const_cast< AddGroupDialog*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int AddGroupDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManDialog::qt_metacall(_c, _id, _a);
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
