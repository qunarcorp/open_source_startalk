/****************************************************************************
** Meta object code from reading C++ file 'ConversationListWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ConversationListWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConversationListWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ConversationListWidget_t {
    QByteArrayData data[15];
    char stringdata[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ConversationListWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ConversationListWidget_t qt_meta_stringdata_ConversationListWidget = {
    {
QT_MOC_LITERAL(0, 0, 22),
QT_MOC_LITERAL(1, 23, 19),
QT_MOC_LITERAL(2, 43, 0),
QT_MOC_LITERAL(3, 44, 14),
QT_MOC_LITERAL(4, 59, 19),
QT_MOC_LITERAL(5, 79, 14),
QT_MOC_LITERAL(6, 94, 17),
QT_MOC_LITERAL(7, 112, 8),
QT_MOC_LITERAL(8, 121, 15),
QT_MOC_LITERAL(9, 137, 7),
QT_MOC_LITERAL(10, 145, 18),
QT_MOC_LITERAL(11, 164, 16),
QT_MOC_LITERAL(12, 181, 7),
QT_MOC_LITERAL(13, 189, 8),
QT_MOC_LITERAL(14, 198, 11)
    },
    "ConversationListWidget\0conversationActived\0"
    "\0conversationID\0conversationClicked\0"
    "conversationId\0extendListActived\0"
    "extendid\0showAtInfoBlock\0atmsgid\0"
    "currentItemChanged\0QListWidgetItem*\0"
    "current\0previous\0itemClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConversationListWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,
       4,    1,   47,    2, 0x06,
       6,    1,   50,    2, 0x06,
       8,    2,   53,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      10,    2,   58,    2, 0x0a,
      14,    1,   63,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 11,   12,   13,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void ConversationListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConversationListWidget *_t = static_cast<ConversationListWidget *>(_o);
        switch (_id) {
        case 0: _t->conversationActived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->conversationClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->extendListActived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->showAtInfoBlock((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->currentItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 5: _t->itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ConversationListWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConversationListWidget::conversationActived)) {
                *result = 0;
            }
        }
        {
            typedef void (ConversationListWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConversationListWidget::conversationClicked)) {
                *result = 1;
            }
        }
        {
            typedef void (ConversationListWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConversationListWidget::extendListActived)) {
                *result = 2;
            }
        }
        {
            typedef void (ConversationListWidget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConversationListWidget::showAtInfoBlock)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject ConversationListWidget::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_ConversationListWidget.data,
      qt_meta_data_ConversationListWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *ConversationListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConversationListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConversationListWidget.stringdata))
        return static_cast<void*>(const_cast< ConversationListWidget*>(this));
    return QListWidget::qt_metacast(_clname);
}

int ConversationListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ConversationListWidget::conversationActived(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ConversationListWidget::conversationClicked(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ConversationListWidget::extendListActived(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ConversationListWidget::showAtInfoBlock(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
