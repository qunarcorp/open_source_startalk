/****************************************************************************
** Meta object code from reading C++ file 'userprofilewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../userprofilewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userprofilewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserProfileWidget_t {
    QByteArrayData data[14];
    char stringdata[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_UserProfileWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_UserProfileWidget_t qt_meta_stringdata_UserProfileWidget = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 13),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 4),
QT_MOC_LITERAL(4, 38, 17),
QT_MOC_LITERAL(5, 56, 7),
QT_MOC_LITERAL(6, 64, 21),
QT_MOC_LITERAL(7, 86, 6),
QT_MOC_LITERAL(8, 93, 21),
QT_MOC_LITERAL(9, 115, 6),
QT_MOC_LITERAL(10, 122, 8),
QT_MOC_LITERAL(11, 131, 20),
QT_MOC_LITERAL(12, 152, 7),
QT_MOC_LITERAL(13, 160, 4)
    },
    "UserProfileWidget\0onLinkClicked\0\0link\0"
    "onUserVcardChange\0userids\0"
    "onChangeAvatarClicked\0bcheck\0"
    "onUserMoodInforChange\0userid\0moodinfo\0"
    "onUserPortraitUpdate\0onClose\0bret\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserProfileWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08,
       4,    1,   47,    2, 0x08,
       6,    1,   50,    2, 0x08,
       8,    2,   53,    2, 0x08,
      11,    1,   58,    2, 0x08,
      12,    1,   61,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QStringList,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Bool,   13,

       0        // eod
};

void UserProfileWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserProfileWidget *_t = static_cast<UserProfileWidget *>(_o);
        switch (_id) {
        case 0: _t->onLinkClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onUserVcardChange((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 2: _t->onChangeAvatarClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onUserMoodInforChange((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->onUserPortraitUpdate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onClose((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject UserProfileWidget::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_UserProfileWidget.data,
      qt_meta_data_UserProfileWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *UserProfileWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserProfileWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UserProfileWidget.stringdata))
        return static_cast<void*>(const_cast< UserProfileWidget*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int UserProfileWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
