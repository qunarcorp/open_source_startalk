/****************************************************************************
** Meta object code from reading C++ file 'SnipScreenTool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../diywidgit/printscreen/SnipScreenTool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SnipScreenTool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SnipScreenTool_t {
    QByteArrayData data[13];
    char stringdata[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SnipScreenTool_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SnipScreenTool_t qt_meta_stringdata_SnipScreenTool = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 8),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 2),
QT_MOC_LITERAL(4, 28, 8),
QT_MOC_LITERAL(5, 37, 16),
QT_MOC_LITERAL(6, 54, 4),
QT_MOC_LITERAL(7, 59, 17),
QT_MOC_LITERAL(8, 77, 5),
QT_MOC_LITERAL(9, 83, 20),
QT_MOC_LITERAL(10, 104, 27),
QT_MOC_LITERAL(11, 132, 4),
QT_MOC_LITERAL(12, 137, 6)
    },
    "SnipScreenTool\0sgFinish\0\0id\0sgCancel\0"
    "onPenSizeChanged\0size\0onPenColorChanged\0"
    "color\0onToolBarTypeChanged\0"
    "SnipScreemToolBar::TOOLTYPE\0type\0"
    "onUndo\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SnipScreenTool[] = {

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
       1,    1,   44,    2, 0x06,
       4,    1,   47,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    1,   50,    2, 0x09,
       7,    1,   53,    2, 0x09,
       9,    1,   56,    2, 0x09,
      12,    0,   59,    2, 0x09,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,

       0        // eod
};

void SnipScreenTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SnipScreenTool *_t = static_cast<SnipScreenTool *>(_o);
        switch (_id) {
        case 0: _t->sgFinish((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sgCancel((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onPenSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onPenColorChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onToolBarTypeChanged((*reinterpret_cast< SnipScreemToolBar::TOOLTYPE(*)>(_a[1]))); break;
        case 5: _t->onUndo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SnipScreenTool::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SnipScreenTool::sgFinish)) {
                *result = 0;
            }
        }
        {
            typedef void (SnipScreenTool::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SnipScreenTool::sgCancel)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject SnipScreenTool::staticMetaObject = {
    { &FullScreenWidget::staticMetaObject, qt_meta_stringdata_SnipScreenTool.data,
      qt_meta_data_SnipScreenTool,  qt_static_metacall, 0, 0}
};


const QMetaObject *SnipScreenTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SnipScreenTool::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SnipScreenTool.stringdata))
        return static_cast<void*>(const_cast< SnipScreenTool*>(this));
    return FullScreenWidget::qt_metacast(_clname);
}

int SnipScreenTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = FullScreenWidget::qt_metacall(_c, _id, _a);
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
void SnipScreenTool::sgFinish(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SnipScreenTool::sgCancel(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
