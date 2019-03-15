/****************************************************************************
** Meta object code from reading C++ file 'userminiprofile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../userminiprofile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userminiprofile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserMiniProfile_t {
    QByteArrayData data[16];
    char stringdata[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_UserMiniProfile_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_UserMiniProfile_t qt_meta_stringdata_UserMiniProfile = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 12),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 6),
QT_MOC_LITERAL(4, 37, 11),
QT_MOC_LITERAL(5, 49, 10),
QT_MOC_LITERAL(6, 60, 18),
QT_MOC_LITERAL(7, 79, 7),
QT_MOC_LITERAL(8, 87, 21),
QT_MOC_LITERAL(9, 109, 6),
QT_MOC_LITERAL(10, 116, 8),
QT_MOC_LITERAL(11, 125, 9),
QT_MOC_LITERAL(12, 135, 11),
QT_MOC_LITERAL(13, 147, 32),
QT_MOC_LITERAL(14, 180, 4),
QT_MOC_LITERAL(15, 185, 5)
    },
    "UserMiniProfile\0sgChatDialog\0\0userID\0"
    "displayName\0sgSendFile\0onHDPortraitUpdate\0"
    "userjid\0onUserMoodInforChange\0userid\0"
    "moodInfo\0hideEvent\0QHideEvent*\0"
    "onPictureDownloadProgressDisplay\0done\0"
    "total\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserMiniProfile[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06,
       5,    1,   49,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    1,   52,    2, 0x0a,
       8,    2,   55,    2, 0x0a,
      11,    1,   60,    2, 0x0a,
      13,    3,   63,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::LongLong, QMetaType::LongLong,    9,   14,   15,

       0        // eod
};

void UserMiniProfile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserMiniProfile *_t = static_cast<UserMiniProfile *>(_o);
        switch (_id) {
        case 0: _t->sgChatDialog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->sgSendFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onHDPortraitUpdate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onUserMoodInforChange((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->hideEvent((*reinterpret_cast< QHideEvent*(*)>(_a[1]))); break;
        case 5: _t->onPictureDownloadProgressDisplay((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const qint64(*)>(_a[2])),(*reinterpret_cast< const qint64(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UserMiniProfile::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserMiniProfile::sgChatDialog)) {
                *result = 0;
            }
        }
        {
            typedef void (UserMiniProfile::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserMiniProfile::sgSendFile)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject UserMiniProfile::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserMiniProfile.data,
      qt_meta_data_UserMiniProfile,  qt_static_metacall, 0, 0}
};


const QMetaObject *UserMiniProfile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserMiniProfile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UserMiniProfile.stringdata))
        return static_cast<void*>(const_cast< UserMiniProfile*>(this));
    return QWidget::qt_metacast(_clname);
}

int UserMiniProfile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void UserMiniProfile::sgChatDialog(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UserMiniProfile::sgSendFile(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
