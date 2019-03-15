/****************************************************************************
** Meta object code from reading C++ file 'Personinfordialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Personinfordialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Personinfordialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PersonInforDialog_t {
    QByteArrayData data[11];
    char stringdata[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PersonInforDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PersonInforDialog_t qt_meta_stringdata_PersonInforDialog = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 16),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 2),
QT_MOC_LITERAL(4, 39, 17),
QT_MOC_LITERAL(5, 57, 17),
QT_MOC_LITERAL(6, 75, 6),
QT_MOC_LITERAL(7, 82, 17),
QT_MOC_LITERAL(8, 100, 5),
QT_MOC_LITERAL(9, 106, 11),
QT_MOC_LITERAL(10, 118, 7)
    },
    "PersonInforDialog\0onGetPersonInfor\0\0"
    "iq\0onSavePersonInfor\0onSaveResultInfor\0"
    "iqjson\0onUserVcardUpdate\0users\0"
    "eventFilter\0QEvent*\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PersonInforDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08,
       4,    0,   42,    2, 0x08,
       5,    1,   43,    2, 0x08,
       7,    1,   46,    2, 0x08,
       9,    2,   49,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QStringList,    8,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 10,    2,    2,

       0        // eod
};

void PersonInforDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PersonInforDialog *_t = static_cast<PersonInforDialog *>(_o);
        switch (_id) {
        case 0: _t->onGetPersonInfor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onSavePersonInfor(); break;
        case 2: _t->onSaveResultInfor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onUserVcardUpdate((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 4: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject PersonInforDialog::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_PersonInforDialog.data,
      qt_meta_data_PersonInforDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *PersonInforDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PersonInforDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PersonInforDialog.stringdata))
        return static_cast<void*>(const_cast< PersonInforDialog*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int PersonInforDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
