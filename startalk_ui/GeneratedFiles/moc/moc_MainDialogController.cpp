/****************************************************************************
** Meta object code from reading C++ file 'MainDialogController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainDialogController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainDialogController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainApp__MainDialogController_t {
    QByteArrayData data[20];
    char stringdata[318];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainApp__MainDialogController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainApp__MainDialogController_t qt_meta_stringdata_MainApp__MainDialogController = {
    {
QT_MOC_LITERAL(0, 0, 29),
QT_MOC_LITERAL(1, 30, 18),
QT_MOC_LITERAL(2, 49, 0),
QT_MOC_LITERAL(3, 50, 18),
QT_MOC_LITERAL(4, 69, 25),
QT_MOC_LITERAL(5, 95, 7),
QT_MOC_LITERAL(6, 103, 16),
QT_MOC_LITERAL(7, 120, 18),
QT_MOC_LITERAL(8, 139, 12),
QT_MOC_LITERAL(9, 152, 32),
QT_MOC_LITERAL(10, 185, 7),
QT_MOC_LITERAL(11, 193, 11),
QT_MOC_LITERAL(12, 205, 40),
QT_MOC_LITERAL(13, 246, 9),
QT_MOC_LITERAL(14, 256, 14),
QT_MOC_LITERAL(15, 271, 2),
QT_MOC_LITERAL(16, 274, 2),
QT_MOC_LITERAL(17, 277, 17),
QT_MOC_LITERAL(18, 295, 14),
QT_MOC_LITERAL(19, 310, 6)
    },
    "MainApp::MainDialogController\0"
    "sgMainDialogClosed\0\0sgMainThemeChanged\0"
    "sgMainDialogVisableChange\0visable\0"
    "sgShowChatDialog\0onMainDialogClosed\0"
    "onShowUrlAdv\0QSharedPointer<Biz::AdvDataItem>\0"
    "urlItem\0onPopImages\0"
    "QList<QSharedPointer<Biz::AdvDataItem> >\0"
    "imagelist\0onAddBlackName\0id\0rt\0"
    "onCancelBlackName\0onHistoryError\0"
    "errMsg\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainApp__MainDialogController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06,
       3,    0,   65,    2, 0x06,
       4,    1,   66,    2, 0x06,
       6,    1,   69,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    0,   72,    2, 0x0a,
       8,    1,   73,    2, 0x0a,
      11,    1,   76,    2, 0x0a,
      14,    2,   79,    2, 0x0a,
      17,    2,   84,    2, 0x0a,
      18,    1,   89,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   15,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   15,   16,
    QMetaType::Void, QMetaType::QString,   19,

       0        // eod
};

void MainApp::MainDialogController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainDialogController *_t = static_cast<MainDialogController *>(_o);
        switch (_id) {
        case 0: _t->sgMainDialogClosed(); break;
        case 1: _t->sgMainThemeChanged(); break;
        case 2: _t->sgMainDialogVisableChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->sgShowChatDialog((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onMainDialogClosed(); break;
        case 5: _t->onShowUrlAdv((*reinterpret_cast< const QSharedPointer<Biz::AdvDataItem>(*)>(_a[1]))); break;
        case 6: _t->onPopImages((*reinterpret_cast< const QList<QSharedPointer<Biz::AdvDataItem> >(*)>(_a[1]))); break;
        case 7: _t->onAddBlackName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->onCancelBlackName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->onHistoryError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainDialogController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainDialogController::sgMainDialogClosed)) {
                *result = 0;
            }
        }
        {
            typedef void (MainDialogController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainDialogController::sgMainThemeChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (MainDialogController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainDialogController::sgMainDialogVisableChange)) {
                *result = 2;
            }
        }
        {
            typedef void (MainDialogController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainDialogController::sgShowChatDialog)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject MainApp::MainDialogController::staticMetaObject = {
    { &ControllerBase::staticMetaObject, qt_meta_stringdata_MainApp__MainDialogController.data,
      qt_meta_data_MainApp__MainDialogController,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainApp::MainDialogController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainApp::MainDialogController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainApp__MainDialogController.stringdata))
        return static_cast<void*>(const_cast< MainDialogController*>(this));
    return ControllerBase::qt_metacast(_clname);
}

int MainApp::MainDialogController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ControllerBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MainApp::MainDialogController::sgMainDialogClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MainApp::MainDialogController::sgMainThemeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainApp::MainDialogController::sgMainDialogVisableChange(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainApp::MainDialogController::sgShowChatDialog(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
