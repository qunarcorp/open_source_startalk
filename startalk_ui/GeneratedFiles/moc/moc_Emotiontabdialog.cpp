/****************************************************************************
** Meta object code from reading C++ file 'Emotiontabdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Emotiontabdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Emotiontabdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EmotionTabDialog_t {
    QByteArrayData data[22];
    char stringdata[340];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_EmotionTabDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_EmotionTabDialog_t qt_meta_stringdata_EmotionTabDialog = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 12),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 3),
QT_MOC_LITERAL(4, 35, 5),
QT_MOC_LITERAL(5, 41, 8),
QT_MOC_LITERAL(6, 50, 11),
QT_MOC_LITERAL(7, 62, 9),
QT_MOC_LITERAL(8, 72, 14),
QT_MOC_LITERAL(9, 87, 15),
QT_MOC_LITERAL(10, 103, 1),
QT_MOC_LITERAL(11, 105, 18),
QT_MOC_LITERAL(12, 124, 24),
QT_MOC_LITERAL(13, 149, 6),
QT_MOC_LITERAL(14, 156, 24),
QT_MOC_LITERAL(15, 181, 48),
QT_MOC_LITERAL(16, 230, 4),
QT_MOC_LITERAL(17, 235, 23),
QT_MOC_LITERAL(18, 259, 19),
QT_MOC_LITERAL(19, 279, 24),
QT_MOC_LITERAL(20, 304, 3),
QT_MOC_LITERAL(21, 308, 30)
    },
    "EmotionTabDialog\0sgSelectItem\0\0wid\0"
    "pkgid\0shortcut\0sgSendImage\0imagePath\0"
    "sgSendUrlImage\0onTabBtnClicked\0b\0"
    "onEmoticonSelected\0onCheckEmotionBtnClicked\0"
    "bcheck\0onEmotionInfoListRecvied\0"
    "QList<QSharedPointer<Biz::EmoticonPackageInfo> >\0"
    "list\0onReloadEmojiconPackage\0"
    "OnSettingBtnClicked\0onDeleteCustormerEmotion\0"
    "pkg\0OnDownloadFinishEmotionPackage\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EmotionTabDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   69,    2, 0x06,
       6,    2,   76,    2, 0x06,
       8,    3,   81,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       9,    1,   88,    2, 0x08,
      11,    2,   91,    2, 0x0a,
      12,    1,   96,    2, 0x0a,
      14,    1,   99,    2, 0x0a,
      17,    1,  102,    2, 0x0a,
      18,    0,  105,    2, 0x0a,
      19,    1,  106,    2, 0x0a,
      21,    1,  109,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString,   20,

       0        // eod
};

void EmotionTabDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EmotionTabDialog *_t = static_cast<EmotionTabDialog *>(_o);
        switch (_id) {
        case 0: _t->sgSelectItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->sgSendImage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->sgSendUrlImage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 3: _t->onTabBtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onEmoticonSelected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->onCheckEmotionBtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->onEmotionInfoListRecvied((*reinterpret_cast< const QList<QSharedPointer<Biz::EmoticonPackageInfo> >(*)>(_a[1]))); break;
        case 7: _t->onReloadEmojiconPackage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->OnSettingBtnClicked(); break;
        case 9: _t->onDeleteCustormerEmotion((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->OnDownloadFinishEmotionPackage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EmotionTabDialog::*_t)(const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EmotionTabDialog::sgSelectItem)) {
                *result = 0;
            }
        }
        {
            typedef void (EmotionTabDialog::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EmotionTabDialog::sgSendImage)) {
                *result = 1;
            }
        }
        {
            typedef void (EmotionTabDialog::*_t)(const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EmotionTabDialog::sgSendUrlImage)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject EmotionTabDialog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EmotionTabDialog.data,
      qt_meta_data_EmotionTabDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *EmotionTabDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EmotionTabDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmotionTabDialog.stringdata))
        return static_cast<void*>(const_cast< EmotionTabDialog*>(this));
    return QWidget::qt_metacast(_clname);
}

int EmotionTabDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void EmotionTabDialog::sgSelectItem(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EmotionTabDialog::sgSendImage(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EmotionTabDialog::sgSendUrlImage(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_EmoticonDownloadInfoWidget_t {
    QByteArrayData data[8];
    char stringdata[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_EmoticonDownloadInfoWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_EmoticonDownloadInfoWidget_t qt_meta_stringdata_EmoticonDownloadInfoWidget = {
    {
QT_MOC_LITERAL(0, 0, 26),
QT_MOC_LITERAL(1, 27, 19),
QT_MOC_LITERAL(2, 47, 0),
QT_MOC_LITERAL(3, 48, 5),
QT_MOC_LITERAL(4, 54, 8),
QT_MOC_LITERAL(5, 63, 23),
QT_MOC_LITERAL(6, 87, 7),
QT_MOC_LITERAL(7, 95, 22)
    },
    "EmoticonDownloadInfoWidget\0"
    "onUpdateDescription\0\0pkgid\0descinfo\0"
    "onDownloadPackageResult\0bResult\0"
    "onDeleteEmotionPackage\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EmoticonDownloadInfoWidget[] = {

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
       1,    2,   29,    2, 0x0a,
       5,    2,   34,    2, 0x0a,
       7,    1,   39,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    3,    6,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void EmoticonDownloadInfoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EmoticonDownloadInfoWidget *_t = static_cast<EmoticonDownloadInfoWidget *>(_o);
        switch (_id) {
        case 0: _t->onUpdateDescription((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->onDownloadPackageResult((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->onDeleteEmotionPackage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject EmoticonDownloadInfoWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EmoticonDownloadInfoWidget.data,
      qt_meta_data_EmoticonDownloadInfoWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *EmoticonDownloadInfoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EmoticonDownloadInfoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmoticonDownloadInfoWidget.stringdata))
        return static_cast<void*>(const_cast< EmoticonDownloadInfoWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int EmoticonDownloadInfoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
