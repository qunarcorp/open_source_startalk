/****************************************************************************
** Meta object code from reading C++ file 'Transferchatdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Transferchatdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Transferchatdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TransferChatDialog_t {
    QByteArrayData data[15];
    char stringdata[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TransferChatDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TransferChatDialog_t qt_meta_stringdata_TransferChatDialog = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 14),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 21),
QT_MOC_LITERAL(4, 57, 16),
QT_MOC_LITERAL(5, 74, 4),
QT_MOC_LITERAL(6, 79, 6),
QT_MOC_LITERAL(7, 86, 17),
QT_MOC_LITERAL(8, 104, 14),
QT_MOC_LITERAL(9, 119, 11),
QT_MOC_LITERAL(10, 131, 16),
QT_MOC_LITERAL(11, 148, 4),
QT_MOC_LITERAL(12, 153, 14),
QT_MOC_LITERAL(13, 168, 15),
QT_MOC_LITERAL(14, 184, 4)
    },
    "TransferChatDialog\0OnClickedBtnOk\0\0"
    "onTreeWidgetItemPress\0QTreeWidgetItem*\0"
    "item\0column\0onHideTransferDlg\0"
    "onUpdateStatus\0onlineUsers\0onSearchShopInfo\0"
    "text\0createBindTree\0onRecivedRetMsg\0"
    "from\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TransferChatDialog[] = {

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
       1,    0,   49,    2, 0x08,
       3,    2,   50,    2, 0x08,
       7,    0,   55,    2, 0x08,
       8,    1,   56,    2, 0x08,
      10,    1,   59,    2, 0x08,
      12,    0,   62,    2, 0x08,
      13,    2,   63,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   14,    2,

       0        // eod
};

void TransferChatDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TransferChatDialog *_t = static_cast<TransferChatDialog *>(_o);
        switch (_id) {
        case 0: _t->OnClickedBtnOk(); break;
        case 1: _t->onTreeWidgetItemPress((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->onHideTransferDlg(); break;
        case 3: _t->onUpdateStatus((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 4: _t->onSearchShopInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->createBindTree(); break;
        case 6: _t->onRecivedRetMsg((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject TransferChatDialog::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_TransferChatDialog.data,
      qt_meta_data_TransferChatDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *TransferChatDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TransferChatDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TransferChatDialog.stringdata))
        return static_cast<void*>(const_cast< TransferChatDialog*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int TransferChatDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManDialog::qt_metacall(_c, _id, _a);
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
