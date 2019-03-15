/****************************************************************************
** Meta object code from reading C++ file 'joingroupfaileddialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../joingroupfaileddialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'joingroupfaileddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GroupJoinFailedItem_t {
    QByteArrayData data[7];
    char stringdata[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GroupJoinFailedItem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GroupJoinFailedItem_t qt_meta_stringdata_GroupJoinFailedItem = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 10),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 2),
QT_MOC_LITERAL(4, 35, 16),
QT_MOC_LITERAL(5, 52, 14),
QT_MOC_LITERAL(6, 67, 13)
    },
    "GroupJoinFailedItem\0removeItem\0\0id\0"
    "onReJoinCliecked\0onLeftCliecked\0"
    "onReJoinGroup\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupJoinFailedItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x08,
       5,    1,   40,    2, 0x08,
       6,    0,   43,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void GroupJoinFailedItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupJoinFailedItem *_t = static_cast<GroupJoinFailedItem *>(_o);
        switch (_id) {
        case 0: _t->removeItem((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onReJoinCliecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onLeftCliecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onReJoinGroup(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GroupJoinFailedItem::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupJoinFailedItem::removeItem)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject GroupJoinFailedItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GroupJoinFailedItem.data,
      qt_meta_data_GroupJoinFailedItem,  qt_static_metacall, 0, 0}
};


const QMetaObject *GroupJoinFailedItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupJoinFailedItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GroupJoinFailedItem.stringdata))
        return static_cast<void*>(const_cast< GroupJoinFailedItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int GroupJoinFailedItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void GroupJoinFailedItem::removeItem(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_JoinGroupFailedDialog_t {
    QByteArrayData data[7];
    char stringdata[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_JoinGroupFailedDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_JoinGroupFailedDialog_t qt_meta_stringdata_JoinGroupFailedDialog = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 18),
QT_MOC_LITERAL(2, 41, 0),
QT_MOC_LITERAL(3, 42, 8),
QT_MOC_LITERAL(4, 51, 15),
QT_MOC_LITERAL(5, 67, 7),
QT_MOC_LITERAL(6, 75, 16)
    },
    "JoinGroupFailedDialog\0onGroupJoinSuccess\0"
    "\0groupjid\0onGroupJoinFail\0groupid\0"
    "rejoinAllClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JoinGroupFailedDialog[] = {

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
       4,    1,   32,    2, 0x08,
       6,    1,   35,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void JoinGroupFailedDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        JoinGroupFailedDialog *_t = static_cast<JoinGroupFailedDialog *>(_o);
        switch (_id) {
        case 0: _t->onGroupJoinSuccess((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onGroupJoinFail((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->rejoinAllClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject JoinGroupFailedDialog::staticMetaObject = {
    { &LocalManWidget::staticMetaObject, qt_meta_stringdata_JoinGroupFailedDialog.data,
      qt_meta_data_JoinGroupFailedDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *JoinGroupFailedDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JoinGroupFailedDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JoinGroupFailedDialog.stringdata))
        return static_cast<void*>(const_cast< JoinGroupFailedDialog*>(this));
    return LocalManWidget::qt_metacast(_clname);
}

int JoinGroupFailedDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManWidget::qt_metacall(_c, _id, _a);
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
