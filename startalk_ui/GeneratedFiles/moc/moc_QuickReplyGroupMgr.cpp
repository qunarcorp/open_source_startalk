/****************************************************************************
** Meta object code from reading C++ file 'QuickReplyGroupMgr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QuickReplyGroupMgr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QuickReplyGroupMgr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QuickReplyGroupEditDlg_t {
    QByteArrayData data[5];
    char stringdata[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QuickReplyGroupEditDlg_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QuickReplyGroupEditDlg_t qt_meta_stringdata_QuickReplyGroupEditDlg = {
    {
QT_MOC_LITERAL(0, 0, 22),
QT_MOC_LITERAL(1, 23, 7),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 11),
QT_MOC_LITERAL(4, 44, 13)
    },
    "QuickReplyGroupEditDlg\0onClose\0\0"
    "onSaveGroup\0onCancelGroup\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuickReplyGroupEditDlg[] = {

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

void QuickReplyGroupEditDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QuickReplyGroupEditDlg *_t = static_cast<QuickReplyGroupEditDlg *>(_o);
        switch (_id) {
        case 0: _t->onClose(); break;
        case 1: _t->onSaveGroup(); break;
        case 2: _t->onCancelGroup(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QuickReplyGroupEditDlg::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_QuickReplyGroupEditDlg.data,
      qt_meta_data_QuickReplyGroupEditDlg,  qt_static_metacall, 0, 0}
};


const QMetaObject *QuickReplyGroupEditDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuickReplyGroupEditDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QuickReplyGroupEditDlg.stringdata))
        return static_cast<void*>(const_cast< QuickReplyGroupEditDlg*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int QuickReplyGroupEditDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_QuickReplyGroupMgr_t {
    QByteArrayData data[11];
    char stringdata[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QuickReplyGroupMgr_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QuickReplyGroupMgr_t qt_meta_stringdata_QuickReplyGroupMgr = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 23),
QT_MOC_LITERAL(2, 43, 0),
QT_MOC_LITERAL(3, 44, 7),
QT_MOC_LITERAL(4, 52, 10),
QT_MOC_LITERAL(5, 63, 11),
QT_MOC_LITERAL(6, 75, 13),
QT_MOC_LITERAL(7, 89, 13),
QT_MOC_LITERAL(8, 103, 15),
QT_MOC_LITERAL(9, 119, 11),
QT_MOC_LITERAL(10, 131, 13)
    },
    "QuickReplyGroupMgr\0sgQuickReplyGroupChange\0"
    "\0onClose\0onAddGroup\0onModyGroup\0"
    "onDeleteGroup\0onMoveUpGroup\0onMoveDownGroup\0"
    "onSaveGroup\0onCancelGroup\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuickReplyGroupMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x08,
       4,    0,   61,    2, 0x08,
       5,    0,   62,    2, 0x08,
       6,    0,   63,    2, 0x08,
       7,    0,   64,    2, 0x08,
       8,    0,   65,    2, 0x08,
       9,    0,   66,    2, 0x08,
      10,    0,   67,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QuickReplyGroupMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QuickReplyGroupMgr *_t = static_cast<QuickReplyGroupMgr *>(_o);
        switch (_id) {
        case 0: _t->sgQuickReplyGroupChange(); break;
        case 1: _t->onClose(); break;
        case 2: _t->onAddGroup(); break;
        case 3: _t->onModyGroup(); break;
        case 4: _t->onDeleteGroup(); break;
        case 5: _t->onMoveUpGroup(); break;
        case 6: _t->onMoveDownGroup(); break;
        case 7: _t->onSaveGroup(); break;
        case 8: _t->onCancelGroup(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QuickReplyGroupMgr::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QuickReplyGroupMgr::sgQuickReplyGroupChange)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QuickReplyGroupMgr::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_QuickReplyGroupMgr.data,
      qt_meta_data_QuickReplyGroupMgr,  qt_static_metacall, 0, 0}
};


const QMetaObject *QuickReplyGroupMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuickReplyGroupMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QuickReplyGroupMgr.stringdata))
        return static_cast<void*>(const_cast< QuickReplyGroupMgr*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int QuickReplyGroupMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void QuickReplyGroupMgr::sgQuickReplyGroupChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
