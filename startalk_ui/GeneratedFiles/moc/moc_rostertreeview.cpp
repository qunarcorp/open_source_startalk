/****************************************************************************
** Meta object code from reading C++ file 'rostertreeview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../rostertreeview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rostertreeview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RosterTreeView_t {
    QByteArrayData data[24];
    char stringdata[286];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RosterTreeView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RosterTreeView_t qt_meta_stringdata_RosterTreeView = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 12),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 6),
QT_MOC_LITERAL(4, 36, 11),
QT_MOC_LITERAL(5, 48, 15),
QT_MOC_LITERAL(6, 64, 9),
QT_MOC_LITERAL(7, 74, 14),
QT_MOC_LITERAL(8, 89, 6),
QT_MOC_LITERAL(9, 96, 19),
QT_MOC_LITERAL(10, 116, 7),
QT_MOC_LITERAL(11, 124, 11),
QT_MOC_LITERAL(12, 136, 11),
QT_MOC_LITERAL(13, 148, 13),
QT_MOC_LITERAL(14, 162, 5),
QT_MOC_LITERAL(15, 168, 7),
QT_MOC_LITERAL(16, 176, 13),
QT_MOC_LITERAL(17, 190, 10),
QT_MOC_LITERAL(18, 201, 6),
QT_MOC_LITERAL(19, 208, 21),
QT_MOC_LITERAL(20, 230, 13),
QT_MOC_LITERAL(21, 244, 21),
QT_MOC_LITERAL(22, 266, 3),
QT_MOC_LITERAL(23, 270, 14)
    },
    "RosterTreeView\0sgChatDialog\0\0userID\0"
    "displayName\0sgGroupAttached\0groupname\0"
    "sgUserAttached\0userid\0onRosterListChanged\0"
    "roaster\0onTraceItem\0oncleanData\0"
    "doubleClicked\0index\0clicked\0keyPressEvent\0"
    "QKeyEvent*\0event1\0showChatDialog_helper\0"
    "expand_helper\0slotCustomContextMenu\0"
    "pos\0selectedUserID\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RosterTreeView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06,
       5,    1,   84,    2, 0x06,
       7,    1,   87,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       9,    1,   90,    2, 0x0a,
      11,    1,   93,    2, 0x0a,
      12,    0,   96,    2, 0x0a,
      13,    1,   97,    2, 0x08,
      15,    1,  100,    2, 0x08,
      16,    1,  103,    2, 0x08,
      19,    0,  106,    2, 0x08,
      20,    0,  107,    2, 0x08,
      21,    1,  108,    2, 0x08,
      23,    0,  111,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariantList,   10,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   14,
    QMetaType::Void, QMetaType::QModelIndex,   14,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   22,
    QMetaType::QString,

       0        // eod
};

void RosterTreeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RosterTreeView *_t = static_cast<RosterTreeView *>(_o);
        switch (_id) {
        case 0: _t->sgChatDialog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->sgGroupAttached((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->sgUserAttached((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onRosterListChanged((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        case 4: _t->onTraceItem((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->oncleanData(); break;
        case 6: _t->doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 9: _t->showChatDialog_helper(); break;
        case 10: _t->expand_helper(); break;
        case 11: _t->slotCustomContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 12: { QString _r = _t->selectedUserID();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RosterTreeView::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RosterTreeView::sgChatDialog)) {
                *result = 0;
            }
        }
        {
            typedef void (RosterTreeView::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RosterTreeView::sgGroupAttached)) {
                *result = 1;
            }
        }
        {
            typedef void (RosterTreeView::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RosterTreeView::sgUserAttached)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject RosterTreeView::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_RosterTreeView.data,
      qt_meta_data_RosterTreeView,  qt_static_metacall, 0, 0}
};


const QMetaObject *RosterTreeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RosterTreeView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RosterTreeView.stringdata))
        return static_cast<void*>(const_cast< RosterTreeView*>(this));
    return QTreeView::qt_metacast(_clname);
}

int RosterTreeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void RosterTreeView::sgChatDialog(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RosterTreeView::sgGroupAttached(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RosterTreeView::sgUserAttached(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
