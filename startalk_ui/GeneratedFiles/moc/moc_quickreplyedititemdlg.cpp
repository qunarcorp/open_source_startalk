/****************************************************************************
** Meta object code from reading C++ file 'quickreplyedititemdlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../quickreplyedititemdlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quickreplyedititemdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QuickReplyEditItemDlg_t {
    QByteArrayData data[5];
    char stringdata[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QuickReplyEditItemDlg_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QuickReplyEditItemDlg_t qt_meta_stringdata_QuickReplyEditItemDlg = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 7),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 11),
QT_MOC_LITERAL(4, 43, 15)
    },
    "QuickReplyEditItemDlg\0onClose\0\0"
    "onClickedOk\0onClickedCancle\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuickReplyEditItemDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08,
       3,    0,   30,    2, 0x08,
       4,    0,   31,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QuickReplyEditItemDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QuickReplyEditItemDlg *_t = static_cast<QuickReplyEditItemDlg *>(_o);
        switch (_id) {
        case 0: _t->onClose(); break;
        case 1: _t->onClickedOk(); break;
        case 2: _t->onClickedCancle(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QuickReplyEditItemDlg::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_QuickReplyEditItemDlg.data,
      qt_meta_data_QuickReplyEditItemDlg,  qt_static_metacall, 0, 0}
};


const QMetaObject *QuickReplyEditItemDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuickReplyEditItemDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QuickReplyEditItemDlg.stringdata))
        return static_cast<void*>(const_cast< QuickReplyEditItemDlg*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int QuickReplyEditItemDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
