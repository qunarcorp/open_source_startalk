/****************************************************************************
** Meta object code from reading C++ file 'combinationcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../combinationcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'combinationcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainApp__CombinationController_t {
    QByteArrayData data[16];
    char stringdata[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainApp__CombinationController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainApp__CombinationController_t qt_meta_stringdata_MainApp__CombinationController = {
    {
QT_MOC_LITERAL(0, 0, 30),
QT_MOC_LITERAL(1, 31, 16),
QT_MOC_LITERAL(2, 48, 0),
QT_MOC_LITERAL(3, 49, 10),
QT_MOC_LITERAL(4, 60, 17),
QT_MOC_LITERAL(5, 78, 6),
QT_MOC_LITERAL(6, 85, 11),
QT_MOC_LITERAL(7, 97, 8),
QT_MOC_LITERAL(8, 106, 26),
QT_MOC_LITERAL(9, 133, 2),
QT_MOC_LITERAL(10, 136, 12),
QT_MOC_LITERAL(11, 149, 24),
QT_MOC_LITERAL(12, 174, 16),
QT_MOC_LITERAL(13, 191, 19),
QT_MOC_LITERAL(14, 211, 9),
QT_MOC_LITERAL(15, 221, 9)
    },
    "MainApp::CombinationController\0"
    "sgCombinationbtn\0\0sgchatsbtn\0"
    "onGroupChatDialog\0userID\0displayName\0"
    "autoJoin\0onPublicAccountItemClicked\0"
    "id\0onChatDialog\0onCombinationItemClicked\0"
    "ongroupItemclick\0onLoginStatusChange\0"
    "oldstatus\0newstatus\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainApp__CombinationController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06,
       3,    0,   55,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    3,   56,    2, 0x0a,
       8,    1,   63,    2, 0x0a,
      10,    2,   66,    2, 0x0a,
      11,    1,   71,    2, 0x0a,
      12,    0,   74,    2, 0x0a,
      13,    2,   75,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    5,    6,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,

       0        // eod
};

void MainApp::CombinationController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CombinationController *_t = static_cast<CombinationController *>(_o);
        switch (_id) {
        case 0: _t->sgCombinationbtn(); break;
        case 1: _t->sgchatsbtn(); break;
        case 2: _t->onGroupChatDialog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->onPublicAccountItemClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onChatDialog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->onCombinationItemClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->ongroupItemclick(); break;
        case 7: _t->onLoginStatusChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CombinationController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CombinationController::sgCombinationbtn)) {
                *result = 0;
            }
        }
        {
            typedef void (CombinationController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CombinationController::sgchatsbtn)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MainApp::CombinationController::staticMetaObject = {
    { &ControllerBase::staticMetaObject, qt_meta_stringdata_MainApp__CombinationController.data,
      qt_meta_data_MainApp__CombinationController,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainApp::CombinationController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainApp::CombinationController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainApp__CombinationController.stringdata))
        return static_cast<void*>(const_cast< CombinationController*>(this));
    return ControllerBase::qt_metacast(_clname);
}

int MainApp::CombinationController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ControllerBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MainApp::CombinationController::sgCombinationbtn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MainApp::CombinationController::sgchatsbtn()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
