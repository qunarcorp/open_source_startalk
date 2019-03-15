/****************************************************************************
** Meta object code from reading C++ file 'combinationlistview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../combinationlistview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'combinationlistview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CombinationListView_t {
    QByteArrayData data[9];
    char stringdata[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CombinationListView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CombinationListView_t qt_meta_stringdata_CombinationListView = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 24),
QT_MOC_LITERAL(2, 45, 0),
QT_MOC_LITERAL(3, 46, 2),
QT_MOC_LITERAL(4, 49, 13),
QT_MOC_LITERAL(5, 63, 19),
QT_MOC_LITERAL(6, 83, 5),
QT_MOC_LITERAL(7, 89, 22),
QT_MOC_LITERAL(8, 112, 6)
    },
    "CombinationListView\0sgcombinationItemClicked\0"
    "\0id\0onitemClicked\0onItemdoubleClicked\0"
    "index\0onWorkSpaceCountChange\0ncount\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CombinationListView[] = {

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
       7,    1,   43,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void CombinationListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CombinationListView *_t = static_cast<CombinationListView *>(_o);
        switch (_id) {
        case 0: _t->sgcombinationItemClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onitemClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->onItemdoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->onWorkSpaceCountChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CombinationListView::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CombinationListView::sgcombinationItemClicked)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CombinationListView::staticMetaObject = {
    { &QListView::staticMetaObject, qt_meta_stringdata_CombinationListView.data,
      qt_meta_data_CombinationListView,  qt_static_metacall, 0, 0}
};


const QMetaObject *CombinationListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CombinationListView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CombinationListView.stringdata))
        return static_cast<void*>(const_cast< CombinationListView*>(this));
    return QListView::qt_metacast(_clname);
}

int CombinationListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListView::qt_metacall(_c, _id, _a);
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
void CombinationListView::sgcombinationItemClicked(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
