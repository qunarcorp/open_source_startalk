/****************************************************************************
** Meta object code from reading C++ file 'RobotSearchedItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RobotSearchedItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RobotSearchedItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RobotSearchedItem_t {
    QByteArrayData data[8];
    char stringdata[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RobotSearchedItem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RobotSearchedItem_t qt_meta_stringdata_RobotSearchedItem = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 17),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 5),
QT_MOC_LITERAL(4, 43, 18),
QT_MOC_LITERAL(5, 62, 6),
QT_MOC_LITERAL(6, 69, 19),
QT_MOC_LITERAL(7, 89, 21)
    },
    "RobotSearchedItem\0sgOpenRobotDialog\0"
    "\0rbtid\0onAddRobotBtnClick\0bcheck\0"
    "onOpenRobotBtnClick\0onCancelRobotBtnClick\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotSearchedItem[] = {

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
       6,    1,   40,    2, 0x08,
       7,    1,   43,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,

       0        // eod
};

void RobotSearchedItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RobotSearchedItem *_t = static_cast<RobotSearchedItem *>(_o);
        switch (_id) {
        case 0: _t->sgOpenRobotDialog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onAddRobotBtnClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onOpenRobotBtnClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onCancelRobotBtnClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RobotSearchedItem::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RobotSearchedItem::sgOpenRobotDialog)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject RobotSearchedItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RobotSearchedItem.data,
      qt_meta_data_RobotSearchedItem,  qt_static_metacall, 0, 0}
};


const QMetaObject *RobotSearchedItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RobotSearchedItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RobotSearchedItem.stringdata))
        return static_cast<void*>(const_cast< RobotSearchedItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int RobotSearchedItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void RobotSearchedItem::sgOpenRobotDialog(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
