/****************************************************************************
** Meta object code from reading C++ file 'Ordermanagedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Ordermanagedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Ordermanagedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OrderManageDialog_t {
    QByteArrayData data[10];
    char stringdata[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_OrderManageDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_OrderManageDialog_t qt_meta_stringdata_OrderManageDialog = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 5),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 7),
QT_MOC_LITERAL(4, 33, 16),
QT_MOC_LITERAL(5, 50, 4),
QT_MOC_LITERAL(6, 55, 10),
QT_MOC_LITERAL(7, 66, 3),
QT_MOC_LITERAL(8, 70, 11),
QT_MOC_LITERAL(9, 82, 15)
    },
    "OrderManageDialog\0onMin\0\0onClose\0"
    "onJsCloseBrowser\0code\0onOpenLink\0url\0"
    "onPlayVodio\0onButtonClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OrderManageDialog[] = {

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
       1,    0,   44,    2, 0x08,
       3,    0,   45,    2, 0x08,
       4,    1,   46,    2, 0x08,
       6,    1,   49,    2, 0x08,
       8,    1,   52,    2, 0x08,
       9,    1,   55,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QUrl,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QUrl,    7,

       0        // eod
};

void OrderManageDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OrderManageDialog *_t = static_cast<OrderManageDialog *>(_o);
        switch (_id) {
        case 0: _t->onMin(); break;
        case 1: _t->onClose(); break;
        case 2: _t->onJsCloseBrowser((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onOpenLink((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 4: _t->onPlayVodio((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onButtonClicked((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject OrderManageDialog::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_OrderManageDialog.data,
      qt_meta_data_OrderManageDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *OrderManageDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OrderManageDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OrderManageDialog.stringdata))
        return static_cast<void*>(const_cast< OrderManageDialog*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int OrderManageDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
