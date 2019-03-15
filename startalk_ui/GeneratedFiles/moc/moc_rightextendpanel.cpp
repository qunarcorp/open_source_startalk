/****************************************************************************
** Meta object code from reading C++ file 'rightextendpanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../rightextendpanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rightextendpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RightExtendPanel_t {
    QByteArrayData data[6];
    char stringdata[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RightExtendPanel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RightExtendPanel_t qt_meta_stringdata_RightExtendPanel = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 13),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 10),
QT_MOC_LITERAL(4, 43, 13),
QT_MOC_LITERAL(5, 57, 3)
    },
    "RightExtendPanel\0visibleChange\0\0"
    "rightClose\0onOpenUrlbyPc\0url\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RightExtendPanel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06,
       3,    0,   30,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    1,   31,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void RightExtendPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RightExtendPanel *_t = static_cast<RightExtendPanel *>(_o);
        switch (_id) {
        case 0: _t->visibleChange(); break;
        case 1: _t->rightClose(); break;
        case 2: _t->onOpenUrlbyPc((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RightExtendPanel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RightExtendPanel::visibleChange)) {
                *result = 0;
            }
        }
        {
            typedef void (RightExtendPanel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RightExtendPanel::rightClose)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject RightExtendPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RightExtendPanel.data,
      qt_meta_data_RightExtendPanel,  qt_static_metacall, 0, 0}
};


const QMetaObject *RightExtendPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RightExtendPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RightExtendPanel.stringdata))
        return static_cast<void*>(const_cast< RightExtendPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int RightExtendPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void RightExtendPanel::visibleChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void RightExtendPanel::rightClose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
