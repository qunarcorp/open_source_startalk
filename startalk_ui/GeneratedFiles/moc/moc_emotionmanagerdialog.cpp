/****************************************************************************
** Meta object code from reading C++ file 'emotionmanagerdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../emotionmanagerdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'emotionmanagerdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EmotionManagerDialog_t {
    QByteArrayData data[25];
    char stringdata[441];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_EmotionManagerDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_EmotionManagerDialog_t qt_meta_stringdata_EmotionManagerDialog = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 14),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 15),
QT_MOC_LITERAL(4, 53, 5),
QT_MOC_LITERAL(5, 59, 26),
QT_MOC_LITERAL(6, 86, 29),
QT_MOC_LITERAL(7, 116, 20),
QT_MOC_LITERAL(8, 137, 19),
QT_MOC_LITERAL(9, 157, 16),
QT_MOC_LITERAL(10, 174, 4),
QT_MOC_LITERAL(11, 179, 7),
QT_MOC_LITERAL(12, 187, 20),
QT_MOC_LITERAL(13, 208, 23),
QT_MOC_LITERAL(14, 232, 23),
QT_MOC_LITERAL(15, 256, 4),
QT_MOC_LITERAL(16, 261, 25),
QT_MOC_LITERAL(17, 287, 31),
QT_MOC_LITERAL(18, 319, 48),
QT_MOC_LITERAL(19, 368, 4),
QT_MOC_LITERAL(20, 373, 19),
QT_MOC_LITERAL(21, 393, 5),
QT_MOC_LITERAL(22, 399, 8),
QT_MOC_LITERAL(23, 408, 23),
QT_MOC_LITERAL(24, 432, 7)
    },
    "EmotionManagerDialog\0onCloseclicked\0"
    "\0onTabBarClicked\0index\0"
    "onAddSaveEmotionBtnClicked\0"
    "onDeleteSaveEmotionBtnClicked\0"
    "onDownloadBtnClicked\0onCurrentItemChange\0"
    "QListWidgetItem*\0item\0preitem\0"
    "onCurrentItemClicked\0onCustomEmotionSelected\0"
    "onReloadEmojiconPackage\0pkgi\0"
    "onCurrentItemServerChange\0"
    "onManagerEmotionInfoListRecvied\0"
    "QList<QSharedPointer<Biz::EmoticonPackageInfo> >\0"
    "list\0onUpdateDescription\0pkgid\0descinfo\0"
    "onDownloadPackageResult\0bResult\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EmotionManagerDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08,
       3,    1,   80,    2, 0x08,
       5,    0,   83,    2, 0x08,
       6,    0,   84,    2, 0x08,
       7,    0,   85,    2, 0x08,
       8,    2,   86,    2, 0x08,
      12,    1,   91,    2, 0x08,
      13,    0,   94,    2, 0x08,
      14,    1,   95,    2, 0x08,
      16,    2,   98,    2, 0x08,
      17,    1,  103,    2, 0x08,
      20,    2,  106,    2, 0x08,
      23,    2,  111,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9,   10,   11,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9,   10,   11,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   21,   22,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   21,   24,

       0        // eod
};

void EmotionManagerDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EmotionManagerDialog *_t = static_cast<EmotionManagerDialog *>(_o);
        switch (_id) {
        case 0: _t->onCloseclicked(); break;
        case 1: _t->onTabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onAddSaveEmotionBtnClicked(); break;
        case 3: _t->onDeleteSaveEmotionBtnClicked(); break;
        case 4: _t->onDownloadBtnClicked(); break;
        case 5: _t->onCurrentItemChange((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 6: _t->onCurrentItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 7: _t->onCustomEmotionSelected(); break;
        case 8: _t->onReloadEmojiconPackage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->onCurrentItemServerChange((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 10: _t->onManagerEmotionInfoListRecvied((*reinterpret_cast< const QList<QSharedPointer<Biz::EmoticonPackageInfo> >(*)>(_a[1]))); break;
        case 11: _t->onUpdateDescription((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 12: _t->onDownloadPackageResult((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSharedPointer<Biz::EmoticonPackageInfo> > >(); break;
            }
            break;
        }
    }
}

const QMetaObject EmotionManagerDialog::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_EmotionManagerDialog.data,
      qt_meta_data_EmotionManagerDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *EmotionManagerDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EmotionManagerDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmotionManagerDialog.stringdata))
        return static_cast<void*>(const_cast< EmotionManagerDialog*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int EmotionManagerDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
