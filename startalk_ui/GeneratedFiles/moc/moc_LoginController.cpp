/****************************************************************************
** Meta object code from reading C++ file 'LoginController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LoginController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LoginController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainApp__LoginController_t {
    QByteArrayData data[10];
    char stringdata[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainApp__LoginController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainApp__LoginController_t qt_meta_stringdata_MainApp__LoginController = {
    {
QT_MOC_LITERAL(0, 0, 24),
QT_MOC_LITERAL(1, 25, 10),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 14),
QT_MOC_LITERAL(4, 52, 20),
QT_MOC_LITERAL(5, 73, 11),
QT_MOC_LITERAL(6, 85, 10),
QT_MOC_LITERAL(7, 96, 9),
QT_MOC_LITERAL(8, 106, 13),
QT_MOC_LITERAL(9, 120, 13)
    },
    "MainApp::LoginController\0onWebLogin\0"
    "\0onLoginSucceed\0onSystemTrayDbClieck\0"
    "onLoginFail\0nMainError\0nSubError\0"
    "onErCodeLogin\0onLoginKitOut\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainApp__LoginController[] = {

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
       1,    0,   44,    2, 0x0a,
       3,    0,   45,    2, 0x0a,
       4,    0,   46,    2, 0x0a,
       5,    2,   47,    2, 0x0a,
       8,    0,   52,    2, 0x0a,
       9,    0,   53,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainApp::LoginController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginController *_t = static_cast<LoginController *>(_o);
        switch (_id) {
        case 0: _t->onWebLogin(); break;
        case 1: _t->onLoginSucceed(); break;
        case 2: _t->onSystemTrayDbClieck(); break;
        case 3: _t->onLoginFail((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->onErCodeLogin(); break;
        case 5: _t->onLoginKitOut(); break;
        default: ;
        }
    }
}

const QMetaObject MainApp::LoginController::staticMetaObject = {
    { &ControllerBase::staticMetaObject, qt_meta_stringdata_MainApp__LoginController.data,
      qt_meta_data_MainApp__LoginController,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainApp::LoginController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainApp::LoginController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainApp__LoginController.stringdata))
        return static_cast<void*>(const_cast< LoginController*>(this));
    return ControllerBase::qt_metacast(_clname);
}

int MainApp::LoginController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ControllerBase::qt_metacall(_c, _id, _a);
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
