/****************************************************************************
** Meta object code from reading C++ file 'colorset.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../colorset.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colorset.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ColorSet_t {
    QByteArrayData data[19];
    char stringdata[455];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ColorSet_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ColorSet_t qt_meta_stringdata_ColorSet = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 11),
QT_MOC_LITERAL(2, 21, 20),
QT_MOC_LITERAL(3, 42, 22),
QT_MOC_LITERAL(4, 65, 24),
QT_MOC_LITERAL(5, 90, 25),
QT_MOC_LITERAL(6, 116, 23),
QT_MOC_LITERAL(7, 140, 24),
QT_MOC_LITERAL(8, 165, 22),
QT_MOC_LITERAL(9, 188, 22),
QT_MOC_LITERAL(10, 211, 25),
QT_MOC_LITERAL(11, 237, 26),
QT_MOC_LITERAL(12, 264, 26),
QT_MOC_LITERAL(13, 291, 27),
QT_MOC_LITERAL(14, 319, 27),
QT_MOC_LITERAL(15, 347, 26),
QT_MOC_LITERAL(16, 374, 25),
QT_MOC_LITERAL(17, 400, 28),
QT_MOC_LITERAL(18, 429, 24)
    },
    "ColorSet\0transparent\0recent_item_bk_hover\0"
    "recent_item_bk_checked\0recent_item_title_normal\0"
    "recent_item_title_checked\0"
    "recent_item_desc_normal\0"
    "recent_item_desc_checked\0"
    "main_theme_text_active\0main_theme_text_normal\0"
    "qchat_notice_promo_normal\0"
    "qchat_notice_promo_checked\0"
    "qchat_notice_option_normal\0"
    "qchat_notice_option_checked\0"
    "pinned_list_item_bk_checked\0"
    "pinned_list_item_bk_normal\0"
    "pinned_list_item_bk_hover\0"
    "pinned_list_group_bk_checked\0"
    "pinned_list_text_checked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ColorSet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      18,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095003,
       2, QMetaType::QString, 0x00095003,
       3, QMetaType::QString, 0x00095003,
       4, QMetaType::QString, 0x00095003,
       5, QMetaType::QString, 0x00095003,
       6, QMetaType::QString, 0x00095003,
       7, QMetaType::QString, 0x00095003,
       8, QMetaType::QString, 0x00095003,
       9, QMetaType::QString, 0x00095003,
      10, QMetaType::QString, 0x00095003,
      11, QMetaType::QString, 0x00095003,
      12, QMetaType::QString, 0x00095003,
      13, QMetaType::QString, 0x00095003,
      14, QMetaType::QString, 0x00095003,
      15, QMetaType::QString, 0x00095003,
      16, QMetaType::QString, 0x00095003,
      17, QMetaType::QString, 0x00095003,
      18, QMetaType::QString, 0x00095003,

       0        // eod
};

void ColorSet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ColorSet::staticMetaObject = {
    { &IJsonSerializeable::staticMetaObject, qt_meta_stringdata_ColorSet.data,
      qt_meta_data_ColorSet,  qt_static_metacall, 0, 0}
};


const QMetaObject *ColorSet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorSet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ColorSet.stringdata))
        return static_cast<void*>(const_cast< ColorSet*>(this));
    return IJsonSerializeable::qt_metacast(_clname);
}

int ColorSet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IJsonSerializeable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = transparent(); break;
        case 1: *reinterpret_cast< QString*>(_v) = recent_item_bk_hover(); break;
        case 2: *reinterpret_cast< QString*>(_v) = recent_item_bk_checked(); break;
        case 3: *reinterpret_cast< QString*>(_v) = recent_item_title_normal(); break;
        case 4: *reinterpret_cast< QString*>(_v) = recent_item_title_checked(); break;
        case 5: *reinterpret_cast< QString*>(_v) = recent_item_desc_normal(); break;
        case 6: *reinterpret_cast< QString*>(_v) = recent_item_desc_checked(); break;
        case 7: *reinterpret_cast< QString*>(_v) = main_theme_text_active(); break;
        case 8: *reinterpret_cast< QString*>(_v) = main_theme_text_normal(); break;
        case 9: *reinterpret_cast< QString*>(_v) = qchat_notice_promo_normal(); break;
        case 10: *reinterpret_cast< QString*>(_v) = qchat_notice_promo_checked(); break;
        case 11: *reinterpret_cast< QString*>(_v) = qchat_notice_option_normal(); break;
        case 12: *reinterpret_cast< QString*>(_v) = qchat_notice_option_checked(); break;
        case 13: *reinterpret_cast< QString*>(_v) = pinned_list_item_bk_checked(); break;
        case 14: *reinterpret_cast< QString*>(_v) = pinned_list_item_bk_normal(); break;
        case 15: *reinterpret_cast< QString*>(_v) = pinned_list_item_bk_hover(); break;
        case 16: *reinterpret_cast< QString*>(_v) = pinned_list_group_bk_checked(); break;
        case 17: *reinterpret_cast< QString*>(_v) = pinned_list_text_checked(); break;
        }
        _id -= 18;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: transparent(*reinterpret_cast< QString*>(_v)); break;
        case 1: recent_item_bk_hover(*reinterpret_cast< QString*>(_v)); break;
        case 2: recent_item_bk_checked(*reinterpret_cast< QString*>(_v)); break;
        case 3: recent_item_title_normal(*reinterpret_cast< QString*>(_v)); break;
        case 4: recent_item_title_checked(*reinterpret_cast< QString*>(_v)); break;
        case 5: recent_item_desc_normal(*reinterpret_cast< QString*>(_v)); break;
        case 6: recent_item_desc_checked(*reinterpret_cast< QString*>(_v)); break;
        case 7: main_theme_text_active(*reinterpret_cast< QString*>(_v)); break;
        case 8: main_theme_text_normal(*reinterpret_cast< QString*>(_v)); break;
        case 9: qchat_notice_promo_normal(*reinterpret_cast< QString*>(_v)); break;
        case 10: qchat_notice_promo_checked(*reinterpret_cast< QString*>(_v)); break;
        case 11: qchat_notice_option_normal(*reinterpret_cast< QString*>(_v)); break;
        case 12: qchat_notice_option_checked(*reinterpret_cast< QString*>(_v)); break;
        case 13: pinned_list_item_bk_checked(*reinterpret_cast< QString*>(_v)); break;
        case 14: pinned_list_item_bk_normal(*reinterpret_cast< QString*>(_v)); break;
        case 15: pinned_list_item_bk_hover(*reinterpret_cast< QString*>(_v)); break;
        case 16: pinned_list_group_bk_checked(*reinterpret_cast< QString*>(_v)); break;
        case 17: pinned_list_text_checked(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 18;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 18;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 18;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
