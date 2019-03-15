/****************************************************************************
** Meta object code from reading C++ file 'MenuRobotDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MenuRobotDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MenuRobotDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MenuRobotDialog_t {
    QByteArrayData data[13];
    char stringdata[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MenuRobotDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MenuRobotDialog_t qt_meta_stringdata_MenuRobotDialog = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 17),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 32),
QT_MOC_LITERAL(4, 68, 27),
QT_MOC_LITERAL(5, 96, 3),
QT_MOC_LITERAL(6, 100, 28),
QT_MOC_LITERAL(7, 129, 7),
QT_MOC_LITERAL(8, 137, 7),
QT_MOC_LITERAL(9, 145, 28),
QT_MOC_LITERAL(10, 174, 14),
QT_MOC_LITERAL(11, 189, 16),
QT_MOC_LITERAL(12, 206, 14)
    },
    "MenuRobotDialog\0onMessageReceived\0\0"
    "QSharedPointer<Biz::XmppMessage>\0"
    "onCollectionMessageReceived\0msg\0"
    "onUpdateRawHtmlElementStatus\0vcardId\0"
    "message\0onConverStationMenuRobotType\0"
    "conversationId\0onMsgTypeChanged\0"
    "onBtnMsgFilter\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuRobotDialog[] = {

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
       1,    1,   44,    2, 0x0a,
       4,    1,   47,    2, 0x0a,
       6,    2,   50,    2, 0x0a,
       9,    1,   55,    2, 0x0a,
      11,    0,   58,    2, 0x08,
      12,    0,   59,    2, 0x08,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MenuRobotDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MenuRobotDialog *_t = static_cast<MenuRobotDialog *>(_o);
        switch (_id) {
        case 0: _t->onMessageReceived((*reinterpret_cast< const QSharedPointer<Biz::XmppMessage>(*)>(_a[1]))); break;
        case 1: _t->onCollectionMessageReceived((*reinterpret_cast< const QSharedPointer<Biz::XmppMessage>(*)>(_a[1]))); break;
        case 2: _t->onUpdateRawHtmlElementStatus((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->onConverStationMenuRobotType((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onMsgTypeChanged(); break;
        case 5: _t->onBtnMsgFilter(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSharedPointer<Biz::XmppMessage> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSharedPointer<Biz::XmppMessage> >(); break;
            }
            break;
        }
    }
}

const QMetaObject MenuRobotDialog::staticMetaObject = {
    { &ChatDialog::staticMetaObject, qt_meta_stringdata_MenuRobotDialog.data,
      qt_meta_data_MenuRobotDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *MenuRobotDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuRobotDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MenuRobotDialog.stringdata))
        return static_cast<void*>(const_cast< MenuRobotDialog*>(this));
    return ChatDialog::qt_metacast(_clname);
}

int MenuRobotDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ChatDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
