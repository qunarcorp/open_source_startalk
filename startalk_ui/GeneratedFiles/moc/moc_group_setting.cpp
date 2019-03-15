/****************************************************************************
** Meta object code from reading C++ file 'group_setting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../group_setting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'group_setting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GroupSettingDialog_t {
    QByteArrayData data[12];
    char stringdata[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GroupSettingDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GroupSettingDialog_t qt_meta_stringdata_GroupSettingDialog = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 6),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 1),
QT_MOC_LITERAL(4, 29, 8),
QT_MOC_LITERAL(5, 38, 5),
QT_MOC_LITERAL(6, 44, 15),
QT_MOC_LITERAL(7, 60, 14),
QT_MOC_LITERAL(8, 75, 17),
QT_MOC_LITERAL(9, 93, 11),
QT_MOC_LITERAL(10, 105, 23),
QT_MOC_LITERAL(11, 129, 8)
    },
    "GroupSettingDialog\0onQuit\0\0b\0onCancle\0"
    "onTab\0onModifySubject\0onDestroyGroup\0"
    "onClickedOkChange\0onQuitGroup\0"
    "updateAvatarGroupHeader\0groupjid\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupSettingDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a,
       4,    1,   57,    2, 0x0a,
       5,    1,   60,    2, 0x0a,
       6,    1,   63,    2, 0x0a,
       7,    1,   66,    2, 0x0a,
       8,    0,   69,    2, 0x0a,
       9,    0,   70,    2, 0x0a,
      10,    1,   71,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void GroupSettingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupSettingDialog *_t = static_cast<GroupSettingDialog *>(_o);
        switch (_id) {
        case 0: _t->onQuit((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onCancle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onTab((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onModifySubject((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onDestroyGroup((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onClickedOkChange(); break;
        case 6: _t->onQuitGroup(); break;
        case 7: _t->updateAvatarGroupHeader((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GroupSettingDialog::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_GroupSettingDialog.data,
      qt_meta_data_GroupSettingDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *GroupSettingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupSettingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GroupSettingDialog.stringdata))
        return static_cast<void*>(const_cast< GroupSettingDialog*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int GroupSettingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
