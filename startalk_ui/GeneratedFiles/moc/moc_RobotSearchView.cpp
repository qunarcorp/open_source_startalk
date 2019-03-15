/****************************************************************************
** Meta object code from reading C++ file 'RobotSearchView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RobotSearchView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RobotSearchView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RobotSearchView_t {
    QByteArrayData data[9];
    char stringdata[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RobotSearchView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RobotSearchView_t qt_meta_stringdata_RobotSearchView = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 17),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 5),
QT_MOC_LITERAL(4, 41, 11),
QT_MOC_LITERAL(5, 53, 6),
QT_MOC_LITERAL(6, 60, 19),
QT_MOC_LITERAL(7, 80, 4),
QT_MOC_LITERAL(8, 85, 28)
    },
    "RobotSearchView\0sgOpenRobotDialog\0\0"
    "rbtid\0onTabChange\0bckech\0onSearchTextChanged\0"
    "text\0onRobotSubscriptedListChange\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotSearchView[] = {

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
       8,    0,   43,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void RobotSearchView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RobotSearchView *_t = static_cast<RobotSearchView *>(_o);
        switch (_id) {
        case 0: _t->sgOpenRobotDialog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onTabChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onSearchTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onRobotSubscriptedListChange(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RobotSearchView::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RobotSearchView::sgOpenRobotDialog)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject RobotSearchView::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_RobotSearchView.data,
      qt_meta_data_RobotSearchView,  qt_static_metacall, 0, 0}
};


const QMetaObject *RobotSearchView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RobotSearchView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RobotSearchView.stringdata))
        return static_cast<void*>(const_cast< RobotSearchView*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int RobotSearchView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManDialog::qt_metacall(_c, _id, _a);
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
void RobotSearchView::sgOpenRobotDialog(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
