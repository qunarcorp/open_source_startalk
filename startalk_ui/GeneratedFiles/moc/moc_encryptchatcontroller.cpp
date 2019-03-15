/****************************************************************************
** Meta object code from reading C++ file 'encryptchatcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../encryptchatcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'encryptchatcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainApp__EncryptChatController_t {
    QByteArrayData data[11];
    char stringdata[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainApp__EncryptChatController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainApp__EncryptChatController_t qt_meta_stringdata_MainApp__EncryptChatController = {
    {
QT_MOC_LITERAL(0, 0, 30),
QT_MOC_LITERAL(1, 31, 19),
QT_MOC_LITERAL(2, 51, 0),
QT_MOC_LITERAL(3, 52, 14),
QT_MOC_LITERAL(4, 67, 13),
QT_MOC_LITERAL(5, 81, 13),
QT_MOC_LITERAL(6, 95, 21),
QT_MOC_LITERAL(7, 117, 4),
QT_MOC_LITERAL(8, 122, 5),
QT_MOC_LITERAL(9, 128, 18),
QT_MOC_LITERAL(10, 147, 20)
    },
    "MainApp::EncryptChatController\0"
    "sgCancelEncryptChat\0\0conversationId\0"
    "sgEncryptChat\0sgDecryptChat\0"
    "sgEncryptResponeInfor\0type\0Infor\0"
    "sgCloseEncryptChat\0sgLocalArgeeOrRefuse\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainApp__EncryptChatController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,
       4,    1,   47,    2, 0x06,
       5,    1,   50,    2, 0x06,
       6,    3,   53,    2, 0x06,
       9,    1,   60,    2, 0x06,
      10,    2,   63,    2, 0x06,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    7,    3,    8,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    7,

       0        // eod
};

void MainApp::EncryptChatController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EncryptChatController *_t = static_cast<EncryptChatController *>(_o);
        switch (_id) {
        case 0: _t->sgCancelEncryptChat((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sgEncryptChat((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->sgDecryptChat((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->sgEncryptResponeInfor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: _t->sgCloseEncryptChat((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->sgLocalArgeeOrRefuse((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EncryptChatController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EncryptChatController::sgCancelEncryptChat)) {
                *result = 0;
            }
        }
        {
            typedef void (EncryptChatController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EncryptChatController::sgEncryptChat)) {
                *result = 1;
            }
        }
        {
            typedef void (EncryptChatController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EncryptChatController::sgDecryptChat)) {
                *result = 2;
            }
        }
        {
            typedef void (EncryptChatController::*_t)(int , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EncryptChatController::sgEncryptResponeInfor)) {
                *result = 3;
            }
        }
        {
            typedef void (EncryptChatController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EncryptChatController::sgCloseEncryptChat)) {
                *result = 4;
            }
        }
        {
            typedef void (EncryptChatController::*_t)(const QString & , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EncryptChatController::sgLocalArgeeOrRefuse)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject MainApp::EncryptChatController::staticMetaObject = {
    { &ControllerBase::staticMetaObject, qt_meta_stringdata_MainApp__EncryptChatController.data,
      qt_meta_data_MainApp__EncryptChatController,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainApp::EncryptChatController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainApp::EncryptChatController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainApp__EncryptChatController.stringdata))
        return static_cast<void*>(const_cast< EncryptChatController*>(this));
    return ControllerBase::qt_metacast(_clname);
}

int MainApp::EncryptChatController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void MainApp::EncryptChatController::sgCancelEncryptChat(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainApp::EncryptChatController::sgEncryptChat(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainApp::EncryptChatController::sgDecryptChat(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainApp::EncryptChatController::sgEncryptResponeInfor(int _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainApp::EncryptChatController::sgCloseEncryptChat(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainApp::EncryptChatController::sgLocalArgeeOrRefuse(const QString & _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
