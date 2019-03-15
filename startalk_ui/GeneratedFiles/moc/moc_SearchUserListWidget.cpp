/****************************************************************************
** Meta object code from reading C++ file 'SearchUserListWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SearchUserListWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SearchUserListWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SearchUserListWidget_t {
    QByteArrayData data[14];
    char stringdata[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SearchUserListWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SearchUserListWidget_t qt_meta_stringdata_SearchUserListWidget = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 14),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 14),
QT_MOC_LITERAL(4, 52, 15),
QT_MOC_LITERAL(5, 68, 13),
QT_MOC_LITERAL(6, 82, 15),
QT_MOC_LITERAL(7, 98, 14),
QT_MOC_LITERAL(8, 113, 10),
QT_MOC_LITERAL(9, 124, 9),
QT_MOC_LITERAL(10, 134, 15),
QT_MOC_LITERAL(11, 150, 13),
QT_MOC_LITERAL(12, 164, 16),
QT_MOC_LITERAL(13, 181, 4)
    },
    "SearchUserListWidget\0sgItemSelected\0"
    "\0conversationId\0sgGroupSelected\0"
    "coversationId\0sgRobotSelected\0"
    "sgMoreSelected\0selectedid\0searchkey\0"
    "sgHistoryRecord\0onItemClicked\0"
    "QListWidgetItem*\0item\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchUserListWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,
       4,    1,   47,    2, 0x06,
       6,    1,   50,    2, 0x06,
       7,    2,   53,    2, 0x06,
      10,    0,   58,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      11,    1,   59,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void SearchUserListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SearchUserListWidget *_t = static_cast<SearchUserListWidget *>(_o);
        switch (_id) {
        case 0: _t->sgItemSelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sgGroupSelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->sgRobotSelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->sgMoreSelected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->sgHistoryRecord(); break;
        case 5: _t->onItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SearchUserListWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearchUserListWidget::sgItemSelected)) {
                *result = 0;
            }
        }
        {
            typedef void (SearchUserListWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearchUserListWidget::sgGroupSelected)) {
                *result = 1;
            }
        }
        {
            typedef void (SearchUserListWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearchUserListWidget::sgRobotSelected)) {
                *result = 2;
            }
        }
        {
            typedef void (SearchUserListWidget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearchUserListWidget::sgMoreSelected)) {
                *result = 3;
            }
        }
        {
            typedef void (SearchUserListWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearchUserListWidget::sgHistoryRecord)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject SearchUserListWidget::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_SearchUserListWidget.data,
      qt_meta_data_SearchUserListWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *SearchUserListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchUserListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SearchUserListWidget.stringdata))
        return static_cast<void*>(const_cast< SearchUserListWidget*>(this));
    return QListWidget::qt_metacast(_clname);
}

int SearchUserListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void SearchUserListWidget::sgItemSelected(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SearchUserListWidget::sgGroupSelected(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SearchUserListWidget::sgRobotSelected(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SearchUserListWidget::sgMoreSelected(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SearchUserListWidget::sgHistoryRecord()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
