/****************************************************************************
** Meta object code from reading C++ file 'collectiontreeview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../collectiontreeview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'collectiontreeview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CollectionTreeView_t {
    QByteArrayData data[23];
    char stringdata[371];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CollectionTreeView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CollectionTreeView_t qt_meta_stringdata_CollectionTreeView = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 24),
QT_MOC_LITERAL(2, 44, 0),
QT_MOC_LITERAL(3, 45, 51),
QT_MOC_LITERAL(4, 97, 9),
QT_MOC_LITERAL(5, 107, 13),
QT_MOC_LITERAL(6, 121, 5),
QT_MOC_LITERAL(7, 127, 7),
QT_MOC_LITERAL(8, 135, 13),
QT_MOC_LITERAL(9, 149, 10),
QT_MOC_LITERAL(10, 160, 6),
QT_MOC_LITERAL(11, 167, 21),
QT_MOC_LITERAL(12, 189, 13),
QT_MOC_LITERAL(13, 203, 20),
QT_MOC_LITERAL(14, 224, 2),
QT_MOC_LITERAL(15, 227, 19),
QT_MOC_LITERAL(16, 247, 8),
QT_MOC_LITERAL(17, 256, 16),
QT_MOC_LITERAL(18, 273, 38),
QT_MOC_LITERAL(19, 312, 4),
QT_MOC_LITERAL(20, 317, 17),
QT_MOC_LITERAL(21, 335, 13),
QT_MOC_LITERAL(22, 349, 20)
    },
    "CollectionTreeView\0onCollectionBindUserList\0"
    "\0QList<QSharedPointer<Biz::CollectionBindUserInfo> >\0"
    "inforlist\0doubleClicked\0index\0clicked\0"
    "keyPressEvent\0QKeyEvent*\0event1\0"
    "showChatDialog_helper\0expand_helper\0"
    "onCollectionPortrait\0id\0onUpdateGroupHeader\0"
    "groupjid\0onInitRoomsVcard\0"
    "QList<QSharedPointer<Biz::RoomVcard> >\0"
    "list\0OnUserVcardChange\0userinforlist\0"
    "onCollectionBindUser\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CollectionTreeView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a,
       5,    1,   72,    2, 0x0a,
       7,    1,   75,    2, 0x0a,
       8,    1,   78,    2, 0x0a,
      11,    0,   81,    2, 0x0a,
      12,    0,   82,    2, 0x0a,
      13,    1,   83,    2, 0x0a,
      15,    1,   86,    2, 0x0a,
      17,    1,   89,    2, 0x0a,
      20,    1,   92,    2, 0x0a,
      22,    1,   95,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::QStringList,   21,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void CollectionTreeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CollectionTreeView *_t = static_cast<CollectionTreeView *>(_o);
        switch (_id) {
        case 0: _t->onCollectionBindUserList((*reinterpret_cast< QList<QSharedPointer<Biz::CollectionBindUserInfo> >(*)>(_a[1]))); break;
        case 1: _t->doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 4: _t->showChatDialog_helper(); break;
        case 5: _t->expand_helper(); break;
        case 6: _t->onCollectionPortrait((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->onUpdateGroupHeader((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->onInitRoomsVcard((*reinterpret_cast< QList<QSharedPointer<Biz::RoomVcard> >(*)>(_a[1]))); break;
        case 9: _t->OnUserVcardChange((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 10: _t->onCollectionBindUser((*reinterpret_cast< QList<QSharedPointer<Biz::CollectionBindUserInfo> >(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CollectionTreeView::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_CollectionTreeView.data,
      qt_meta_data_CollectionTreeView,  qt_static_metacall, 0, 0}
};


const QMetaObject *CollectionTreeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CollectionTreeView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CollectionTreeView.stringdata))
        return static_cast<void*>(const_cast< CollectionTreeView*>(this));
    return QTreeView::qt_metacast(_clname);
}

int CollectionTreeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
