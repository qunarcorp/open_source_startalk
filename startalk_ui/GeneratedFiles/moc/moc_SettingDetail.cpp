/****************************************************************************
** Meta object code from reading C++ file 'SettingDetail.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SettingDetail.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SettingDetail.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SettingDetail_t {
    QByteArrayData data[28];
    char stringdata[360];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SettingDetail_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SettingDetail_t qt_meta_stringdata_SettingDetail = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 14),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 13),
QT_MOC_LITERAL(4, 44, 9),
QT_MOC_LITERAL(5, 54, 15),
QT_MOC_LITERAL(6, 70, 16),
QT_MOC_LITERAL(7, 87, 14),
QT_MOC_LITERAL(8, 102, 13),
QT_MOC_LITERAL(9, 116, 13),
QT_MOC_LITERAL(10, 130, 10),
QT_MOC_LITERAL(11, 141, 9),
QT_MOC_LITERAL(12, 151, 4),
QT_MOC_LITERAL(13, 156, 13),
QT_MOC_LITERAL(14, 170, 13),
QT_MOC_LITERAL(15, 184, 39),
QT_MOC_LITERAL(16, 224, 10),
QT_MOC_LITERAL(17, 235, 14),
QT_MOC_LITERAL(18, 250, 7),
QT_MOC_LITERAL(19, 258, 4),
QT_MOC_LITERAL(20, 263, 17),
QT_MOC_LITERAL(21, 281, 4),
QT_MOC_LITERAL(22, 286, 5),
QT_MOC_LITERAL(23, 292, 15),
QT_MOC_LITERAL(24, 308, 19),
QT_MOC_LITERAL(25, 328, 6),
QT_MOC_LITERAL(26, 335, 17),
QT_MOC_LITERAL(27, 353, 5)
    },
    "SettingDetail\0sgClientUpdate\0\0"
    "strCurVersion\0autocheck\0onSyetemSetting\0"
    "onProfileSetting\0messageClicked\0"
    "screenClicked\0searchClicked\0onOkHotKey\0"
    "strhotkey\0type\0onmbordHotKey\0onCheckUpdate\0"
    "QSharedPointer<Biz::CheckVersionUpdate>\0"
    "updateinfo\0onVoiceSetting\0onClose\0"
    "bret\0onProgressDisplay\0done\0total\0"
    "onTabBtnClicked\0onWorkStatusClicked\0"
    "bcheck\0onCollectLogsInfo\0infor\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingDetail[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    0,   94,    2, 0x0a,
       6,    0,   95,    2, 0x0a,
       7,    0,   96,    2, 0x0a,
       8,    0,   97,    2, 0x0a,
       9,    0,   98,    2, 0x0a,
      10,    2,   99,    2, 0x0a,
      13,    0,  104,    2, 0x0a,
      14,    1,  105,    2, 0x0a,
      17,    0,  108,    2, 0x0a,
      18,    1,  109,    2, 0x08,
      20,    2,  112,    2, 0x08,
      23,    1,  117,    2, 0x08,
      24,    1,  120,    2, 0x08,
      26,    1,  123,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   11,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   21,   22,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::QString,   27,

       0        // eod
};

void SettingDetail::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SettingDetail *_t = static_cast<SettingDetail *>(_o);
        switch (_id) {
        case 0: _t->sgClientUpdate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->onSyetemSetting(); break;
        case 2: _t->onProfileSetting(); break;
        case 3: _t->messageClicked(); break;
        case 4: _t->screenClicked(); break;
        case 5: _t->searchClicked(); break;
        case 6: _t->onOkHotKey((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->onmbordHotKey(); break;
        case 8: _t->onCheckUpdate((*reinterpret_cast< const QSharedPointer<Biz::CheckVersionUpdate>(*)>(_a[1]))); break;
        case 9: _t->onVoiceSetting(); break;
        case 10: _t->onClose((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->onProgressDisplay((*reinterpret_cast< const qint64(*)>(_a[1])),(*reinterpret_cast< const qint64(*)>(_a[2]))); break;
        case 12: _t->onTabBtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->onWorkStatusClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->onCollectLogsInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SettingDetail::*_t)(const QString & , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SettingDetail::sgClientUpdate)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SettingDetail::staticMetaObject = {
    { &LocalManWidget::staticMetaObject, qt_meta_stringdata_SettingDetail.data,
      qt_meta_data_SettingDetail,  qt_static_metacall, 0, 0}
};


const QMetaObject *SettingDetail::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingDetail::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SettingDetail.stringdata))
        return static_cast<void*>(const_cast< SettingDetail*>(this));
    return LocalManWidget::qt_metacast(_clname);
}

int SettingDetail::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void SettingDetail::sgClientUpdate(const QString & _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
