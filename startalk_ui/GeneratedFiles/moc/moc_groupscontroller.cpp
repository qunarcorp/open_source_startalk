/****************************************************************************
** Meta object code from reading C++ file 'groupscontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../groupscontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'groupscontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainApp__GroupsController_t {
    QByteArrayData data[10];
    char stringdata[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainApp__GroupsController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainApp__GroupsController_t qt_meta_stringdata_MainApp__GroupsController = {
    {
QT_MOC_LITERAL(0, 0, 25),
QT_MOC_LITERAL(1, 26, 19),
QT_MOC_LITERAL(2, 46, 0),
QT_MOC_LITERAL(3, 47, 10),
QT_MOC_LITERAL(4, 58, 22),
QT_MOC_LITERAL(5, 81, 9),
QT_MOC_LITERAL(6, 91, 12),
QT_MOC_LITERAL(7, 104, 3),
QT_MOC_LITERAL(8, 108, 14),
QT_MOC_LITERAL(9, 123, 21)
    },
    "MainApp::GroupsController\0onGroupListReceived\0"
    "\0discoverIq\0onRoomListNameReceived\0"
    "groupjids\0onGroupAdded\0jid\0onGroupDelItem\0"
    "onOpenNewGroupSession\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainApp__GroupsController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a,
       4,    1,   42,    2, 0x0a,
       6,    1,   45,    2, 0x0a,
       8,    1,   48,    2, 0x0a,
       9,    1,   51,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void, QMetaType::QStringList,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void MainApp::GroupsController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupsController *_t = static_cast<GroupsController *>(_o);
        switch (_id) {
        case 0: _t->onGroupListReceived((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 1: _t->onRoomListNameReceived((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 2: _t->onGroupAdded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onGroupDelItem((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onOpenNewGroupSession((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainApp::GroupsController::staticMetaObject = {
    { &ControllerBase::staticMetaObject, qt_meta_stringdata_MainApp__GroupsController.data,
      qt_meta_data_MainApp__GroupsController,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainApp::GroupsController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainApp::GroupsController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainApp__GroupsController.stringdata))
        return static_cast<void*>(const_cast< GroupsController*>(this));
    return ControllerBase::qt_metacast(_clname);
}

int MainApp::GroupsController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ControllerBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
