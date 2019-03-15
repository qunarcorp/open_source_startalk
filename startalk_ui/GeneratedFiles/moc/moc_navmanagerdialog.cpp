/****************************************************************************
** Meta object code from reading C++ file 'navmanagerdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../navmanagerdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'navmanagerdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NavManagerDialog_t {
    QByteArrayData data[11];
    char stringdata[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NavManagerDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NavManagerDialog_t qt_meta_stringdata_NavManagerDialog = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 8),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 11),
QT_MOC_LITERAL(4, 39, 10),
QT_MOC_LITERAL(5, 50, 14),
QT_MOC_LITERAL(6, 65, 21),
QT_MOC_LITERAL(7, 87, 16),
QT_MOC_LITERAL(8, 104, 4),
QT_MOC_LITERAL(9, 109, 14),
QT_MOC_LITERAL(10, 124, 12)
    },
    "NavManagerDialog\0onAddNav\0\0ondeleteNav\0"
    "onApplyNav\0onCloseclicked\0"
    "onListWidgetItemClick\0QListWidgetItem*\0"
    "item\0onAdverClicked\0onSelectNone\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NavManagerDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a,
       3,    0,   50,    2, 0x0a,
       4,    0,   51,    2, 0x0a,
       5,    0,   52,    2, 0x0a,
       6,    1,   53,    2, 0x0a,
       9,    0,   56,    2, 0x0a,
      10,    0,   57,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NavManagerDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NavManagerDialog *_t = static_cast<NavManagerDialog *>(_o);
        switch (_id) {
        case 0: _t->onAddNav(); break;
        case 1: _t->ondeleteNav(); break;
        case 2: _t->onApplyNav(); break;
        case 3: _t->onCloseclicked(); break;
        case 4: _t->onListWidgetItemClick((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->onAdverClicked(); break;
        case 6: _t->onSelectNone(); break;
        default: ;
        }
    }
}

const QMetaObject NavManagerDialog::staticMetaObject = {
    { &LocalManWidget::staticMetaObject, qt_meta_stringdata_NavManagerDialog.data,
      qt_meta_data_NavManagerDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *NavManagerDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NavManagerDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NavManagerDialog.stringdata))
        return static_cast<void*>(const_cast< NavManagerDialog*>(this));
    return LocalManWidget::qt_metacast(_clname);
}

int NavManagerDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
