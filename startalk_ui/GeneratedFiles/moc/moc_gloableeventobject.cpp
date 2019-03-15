/****************************************************************************
** Meta object code from reading C++ file 'gloableeventobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gloableeventobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gloableeventobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GloableEventObject_t {
    QByteArrayData data[25];
    char stringdata[383];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GloableEventObject_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GloableEventObject_t qt_meta_stringdata_GloableEventObject = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 17),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 11),
QT_MOC_LITERAL(4, 50, 5),
QT_MOC_LITERAL(5, 56, 7),
QT_MOC_LITERAL(6, 64, 22),
QT_MOC_LITERAL(7, 87, 9),
QT_MOC_LITERAL(8, 97, 21),
QT_MOC_LITERAL(9, 119, 18),
QT_MOC_LITERAL(10, 138, 25),
QT_MOC_LITERAL(11, 164, 12),
QT_MOC_LITERAL(12, 177, 23),
QT_MOC_LITERAL(13, 201, 28),
QT_MOC_LITERAL(14, 230, 25),
QT_MOC_LITERAL(15, 256, 8),
QT_MOC_LITERAL(16, 265, 17),
QT_MOC_LITERAL(17, 283, 3),
QT_MOC_LITERAL(18, 287, 18),
QT_MOC_LITERAL(19, 306, 7),
QT_MOC_LITERAL(20, 314, 16),
QT_MOC_LITERAL(21, 331, 5),
QT_MOC_LITERAL(22, 337, 15),
QT_MOC_LITERAL(23, 353, 15),
QT_MOC_LITERAL(24, 369, 12)
    },
    "GloableEventObject\0sgMainDialogMoved\0"
    "\0QMoveEvent*\0event\0sgShake\0"
    "sgMainDialogActivitied\0activited\0"
    "sgShowDeleteCatchMenu\0sgQuickReplyUpdate\0"
    "QList<QuickReplyMsgItem*>\0replymsgList\0"
    "sgQuickReplyGroupChange\0"
    "sgQuickReplyAllContentChange\0"
    "sgQuickReplyContentChange\0groupCid\0"
    "sgInputTextChange\0val\0sgNewVersionPrompt\0"
    "bPrompt\0sgFontSizeChange\0nsize\0"
    "sgHideMainWidge\0sgShowMainWidge\0"
    "sgMainDlgMin\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GloableEventObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06,
       5,    0,   87,    2, 0x06,
       6,    1,   88,    2, 0x06,
       8,    0,   91,    2, 0x06,
       9,    1,   92,    2, 0x06,
      12,    0,   95,    2, 0x06,
      13,    0,   96,    2, 0x06,
      14,    1,   97,    2, 0x06,
      16,    1,  100,    2, 0x06,
      18,    1,  103,    2, 0x06,
      20,    1,  106,    2, 0x06,
      22,    0,  109,    2, 0x06,
      23,    0,  110,    2, 0x06,
      24,    0,  111,    2, 0x06,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QReal,   17,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::UShort,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GloableEventObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GloableEventObject *_t = static_cast<GloableEventObject *>(_o);
        switch (_id) {
        case 0: _t->sgMainDialogMoved((*reinterpret_cast< QMoveEvent*(*)>(_a[1]))); break;
        case 1: _t->sgShake(); break;
        case 2: _t->sgMainDialogActivitied((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->sgShowDeleteCatchMenu(); break;
        case 4: _t->sgQuickReplyUpdate((*reinterpret_cast< const QList<QuickReplyMsgItem*>(*)>(_a[1]))); break;
        case 5: _t->sgQuickReplyGroupChange(); break;
        case 6: _t->sgQuickReplyAllContentChange(); break;
        case 7: _t->sgQuickReplyContentChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->sgInputTextChange((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 9: _t->sgNewVersionPrompt((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->sgFontSizeChange((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 11: _t->sgHideMainWidge(); break;
        case 12: _t->sgShowMainWidge(); break;
        case 13: _t->sgMainDlgMin(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GloableEventObject::*_t)(QMoveEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GloableEventObject::sgMainDialogMoved)) {
                *result = 0;
            }
        }
        {
            typedef void (GloableEventObject::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GloableEventObject::sgShake)) {
                *result = 1;
            }
        }
        {
            typedef void (GloableEventObject::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GloableEventObject::sgMainDialogActivitied)) {
                *result = 2;
            }
        }
        {
            typedef void (GloableEventObject::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GloableEventObject::sgShowDeleteCatchMenu)) {
                *result = 3;
            }
        }
        {
            typedef void (GloableEventObject::*_t)(const QList<QuickReplyMsgItem*> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GloableEventObject::sgQuickReplyUpdate)) {
                *result = 4;
            }
        }
        {
            typedef void (GloableEventObject::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GloableEventObject::sgQuickReplyGroupChange)) {
                *result = 5;
            }
        }
        {
            typedef void (GloableEventObject::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GloableEventObject::sgQuickReplyAllContentChange)) {
                *result = 6;
            }
        }
        {
            typedef void (GloableEventObject::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GloableEventObject::sgQuickReplyContentChange)) {
                *result = 7;
            }
        }
        {
            typedef void (GloableEventObject::*_t)(qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GloableEventObject::sgInputTextChange)) {
                *result = 8;
            }
        }
        {
            typedef void (GloableEventObject::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GloableEventObject::sgNewVersionPrompt)) {
                *result = 9;
            }
        }
        {
            typedef void (GloableEventObject::*_t)(quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GloableEventObject::sgFontSizeChange)) {
                *result = 10;
            }
        }
        {
            typedef void (GloableEventObject::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GloableEventObject::sgHideMainWidge)) {
                *result = 11;
            }
        }
        {
            typedef void (GloableEventObject::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GloableEventObject::sgShowMainWidge)) {
                *result = 12;
            }
        }
        {
            typedef void (GloableEventObject::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GloableEventObject::sgMainDlgMin)) {
                *result = 13;
            }
        }
    }
}

const QMetaObject GloableEventObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GloableEventObject.data,
      qt_meta_data_GloableEventObject,  qt_static_metacall, 0, 0}
};


const QMetaObject *GloableEventObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GloableEventObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GloableEventObject.stringdata))
        return static_cast<void*>(const_cast< GloableEventObject*>(this));
    return QObject::qt_metacast(_clname);
}

int GloableEventObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void GloableEventObject::sgMainDialogMoved(QMoveEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GloableEventObject::sgShake()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void GloableEventObject::sgMainDialogActivitied(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GloableEventObject::sgShowDeleteCatchMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void GloableEventObject::sgQuickReplyUpdate(const QList<QuickReplyMsgItem*> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GloableEventObject::sgQuickReplyGroupChange()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void GloableEventObject::sgQuickReplyAllContentChange()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void GloableEventObject::sgQuickReplyContentChange(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void GloableEventObject::sgInputTextChange(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void GloableEventObject::sgNewVersionPrompt(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void GloableEventObject::sgFontSizeChange(quint16 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void GloableEventObject::sgHideMainWidge()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void GloableEventObject::sgShowMainWidge()
{
    QMetaObject::activate(this, &staticMetaObject, 12, 0);
}

// SIGNAL 13
void GloableEventObject::sgMainDlgMin()
{
    QMetaObject::activate(this, &staticMetaObject, 13, 0);
}
QT_END_MOC_NAMESPACE
