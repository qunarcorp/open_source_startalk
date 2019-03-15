/****************************************************************************
** Meta object code from reading C++ file 'quickrepysetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../quickrepysetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quickrepysetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QuickRepySetting_t {
    QByteArrayData data[20];
    char stringdata[291];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QuickRepySetting_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QuickRepySetting_t qt_meta_stringdata_QuickRepySetting = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 7),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 9),
QT_MOC_LITERAL(4, 36, 10),
QT_MOC_LITERAL(5, 47, 12),
QT_MOC_LITERAL(6, 60, 13),
QT_MOC_LITERAL(7, 74, 13),
QT_MOC_LITERAL(8, 88, 15),
QT_MOC_LITERAL(9, 104, 17),
QT_MOC_LITERAL(10, 122, 11),
QT_MOC_LITERAL(11, 134, 15),
QT_MOC_LITERAL(12, 150, 14),
QT_MOC_LITERAL(13, 165, 17),
QT_MOC_LITERAL(14, 183, 17),
QT_MOC_LITERAL(15, 201, 5),
QT_MOC_LITERAL(16, 207, 19),
QT_MOC_LITERAL(17, 227, 25),
QT_MOC_LITERAL(18, 253, 27),
QT_MOC_LITERAL(19, 281, 8)
    },
    "QuickRepySetting\0onClose\0\0onAddItem\0"
    "onModyItem\0onDeleteItem\0onExportReply\0"
    "onImportReply\0onContentMoveUp\0"
    "onContentMoveDown\0onClickedOk\0"
    "onClickedCancel\0onClickedReply\0"
    "onClickedGroupMgr\0groupSelectChange\0"
    "index\0contentSelectChange\0"
    "quickReplyGroupDataChange\0"
    "quickReplyContentDataChange\0groupCid\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuickRepySetting[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08,
       3,    0,   95,    2, 0x08,
       4,    0,   96,    2, 0x08,
       5,    0,   97,    2, 0x08,
       6,    0,   98,    2, 0x08,
       7,    0,   99,    2, 0x08,
       8,    0,  100,    2, 0x08,
       9,    0,  101,    2, 0x08,
      10,    0,  102,    2, 0x08,
      11,    0,  103,    2, 0x08,
      12,    0,  104,    2, 0x08,
      13,    0,  105,    2, 0x08,
      14,    1,  106,    2, 0x08,
      16,    1,  109,    2, 0x08,
      17,    0,  112,    2, 0x08,
      18,    1,  113,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   15,
    QMetaType::Void, QMetaType::QModelIndex,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,

       0        // eod
};

void QuickRepySetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QuickRepySetting *_t = static_cast<QuickRepySetting *>(_o);
        switch (_id) {
        case 0: _t->onClose(); break;
        case 1: _t->onAddItem(); break;
        case 2: _t->onModyItem(); break;
        case 3: _t->onDeleteItem(); break;
        case 4: _t->onExportReply(); break;
        case 5: _t->onImportReply(); break;
        case 6: _t->onContentMoveUp(); break;
        case 7: _t->onContentMoveDown(); break;
        case 8: _t->onClickedOk(); break;
        case 9: _t->onClickedCancel(); break;
        case 10: _t->onClickedReply(); break;
        case 11: _t->onClickedGroupMgr(); break;
        case 12: _t->groupSelectChange((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 13: _t->contentSelectChange((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 14: _t->quickReplyGroupDataChange(); break;
        case 15: _t->quickReplyContentDataChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject QuickRepySetting::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_QuickRepySetting.data,
      qt_meta_data_QuickRepySetting,  qt_static_metacall, 0, 0}
};


const QMetaObject *QuickRepySetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuickRepySetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QuickRepySetting.stringdata))
        return static_cast<void*>(const_cast< QuickRepySetting*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int QuickRepySetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
