/****************************************************************************
** Meta object code from reading C++ file 'groupfileview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../groupfileview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'groupfileview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GroupFileView_t {
    QByteArrayData data[12];
    char stringdata[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GroupFileView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GroupFileView_t qt_meta_stringdata_GroupFileView = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 21),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 1),
QT_MOC_LITERAL(4, 39, 15),
QT_MOC_LITERAL(5, 55, 25),
QT_MOC_LITERAL(6, 81, 3),
QT_MOC_LITERAL(7, 85, 8),
QT_MOC_LITERAL(8, 94, 4),
QT_MOC_LITERAL(9, 99, 5),
QT_MOC_LITERAL(10, 105, 24),
QT_MOC_LITERAL(11, 130, 8)
    },
    "GroupFileView\0onDownloadFileClicked\0"
    "\0b\0onSaveAsClicked\0onDownloadProgressDisplay\0"
    "key\0fileName\0done\0total\0"
    "onDownloadProgressFinish\0filePath\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupFileView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08,
       4,    1,   37,    2, 0x08,
       5,    4,   40,    2, 0x08,
      10,    3,   49,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::LongLong, QMetaType::LongLong,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,   11,

       0        // eod
};

void GroupFileView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupFileView *_t = static_cast<GroupFileView *>(_o);
        switch (_id) {
        case 0: _t->onDownloadFileClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onSaveAsClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onDownloadProgressDisplay((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const qint64(*)>(_a[3])),(*reinterpret_cast< const qint64(*)>(_a[4]))); break;
        case 3: _t->onDownloadProgressFinish((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject GroupFileView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GroupFileView.data,
      qt_meta_data_GroupFileView,  qt_static_metacall, 0, 0}
};


const QMetaObject *GroupFileView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupFileView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GroupFileView.stringdata))
        return static_cast<void*>(const_cast< GroupFileView*>(this));
    return QWidget::qt_metacast(_clname);
}

int GroupFileView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
