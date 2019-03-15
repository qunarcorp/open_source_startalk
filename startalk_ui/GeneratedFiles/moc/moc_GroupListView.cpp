/****************************************************************************
** Meta object code from reading C++ file 'GroupListView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GroupListView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GroupListView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GroupListView_t {
    QByteArrayData data[8];
    char stringdata[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GroupListView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GroupListView_t qt_meta_stringdata_GroupListView = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 17),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 12),
QT_MOC_LITERAL(4, 46, 22),
QT_MOC_LITERAL(5, 69, 8),
QT_MOC_LITERAL(6, 78, 9),
QT_MOC_LITERAL(7, 88, 12)
    },
    "GroupListView\0onOpenSettingView\0\0"
    "onLeaveGroup\0onGroupNoticeTipChange\0"
    "groupjid\0addoption\0removeoption\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupListView[] = {

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
       4,    3,   35,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    5,    6,    7,

       0        // eod
};

void GroupListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupListView *_t = static_cast<GroupListView *>(_o);
        switch (_id) {
        case 0: _t->onOpenSettingView((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onLeaveGroup((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onGroupNoticeTipChange((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject GroupListView::staticMetaObject = {
    { &PinnedListView::staticMetaObject, qt_meta_stringdata_GroupListView.data,
      qt_meta_data_GroupListView,  qt_static_metacall, 0, 0}
};


const QMetaObject *GroupListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupListView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GroupListView.stringdata))
        return static_cast<void*>(const_cast< GroupListView*>(this));
    return PinnedListView::qt_metacast(_clname);
}

int GroupListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PinnedListView::qt_metacall(_c, _id, _a);
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
