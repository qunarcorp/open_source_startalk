/****************************************************************************
** Meta object code from reading C++ file 'Quickreplymsgdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Quickreplymsgdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Quickreplymsgdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QuickReplyMsgDialog_t {
    QByteArrayData data[18];
    char stringdata[291];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QuickReplyMsgDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QuickReplyMsgDialog_t qt_meta_stringdata_QuickReplyMsgDialog = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 14),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 2),
QT_MOC_LITERAL(4, 39, 3),
QT_MOC_LITERAL(5, 43, 13),
QT_MOC_LITERAL(6, 57, 16),
QT_MOC_LITERAL(7, 74, 5),
QT_MOC_LITERAL(8, 80, 18),
QT_MOC_LITERAL(9, 99, 18),
QT_MOC_LITERAL(10, 118, 44),
QT_MOC_LITERAL(11, 163, 14),
QT_MOC_LITERAL(12, 178, 23),
QT_MOC_LITERAL(13, 202, 28),
QT_MOC_LITERAL(14, 231, 25),
QT_MOC_LITERAL(15, 257, 8),
QT_MOC_LITERAL(16, 266, 18),
QT_MOC_LITERAL(17, 285, 4)
    },
    "QuickReplyMsgDialog\0sgItemSelected\0\0"
    "id\0str\0onItemClicked\0QListWidgetItem*\0"
    "pItem\0onpbSettingClicked\0onQuickReplyUpdate\0"
    "QList<QSharedPointer<Biz::QuickReplyGroup> >\0"
    "replyGroupList\0onQuickReplyGroupChange\0"
    "onQuickReplyAllContentChange\0"
    "onQuickReplyContentChange\0groupCid\0"
    "onRightItemEntered\0item\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuickReplyMsgDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    1,   59,    2, 0x08,
       8,    0,   62,    2, 0x08,
       9,    1,   63,    2, 0x08,
      12,    0,   66,    2, 0x08,
      13,    0,   67,    2, 0x08,
      14,    1,   68,    2, 0x08,
      16,    1,   71,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, 0x80000000 | 6,   17,

       0        // eod
};

void QuickReplyMsgDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QuickReplyMsgDialog *_t = static_cast<QuickReplyMsgDialog *>(_o);
        switch (_id) {
        case 0: _t->sgItemSelected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->onItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->onpbSettingClicked(); break;
        case 3: _t->onQuickReplyUpdate((*reinterpret_cast< const QList<QSharedPointer<Biz::QuickReplyGroup> >(*)>(_a[1]))); break;
        case 4: _t->onQuickReplyGroupChange(); break;
        case 5: _t->onQuickReplyAllContentChange(); break;
        case 6: _t->onQuickReplyContentChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->onRightItemEntered((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSharedPointer<Biz::QuickReplyGroup> > >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QuickReplyMsgDialog::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QuickReplyMsgDialog::sgItemSelected)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QuickReplyMsgDialog::staticMetaObject = {
    { &LocalManWidget::staticMetaObject, qt_meta_stringdata_QuickReplyMsgDialog.data,
      qt_meta_data_QuickReplyMsgDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *QuickReplyMsgDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuickReplyMsgDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QuickReplyMsgDialog.stringdata))
        return static_cast<void*>(const_cast< QuickReplyMsgDialog*>(this));
    return LocalManWidget::qt_metacast(_clname);
}

int QuickReplyMsgDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QuickReplyMsgDialog::sgItemSelected(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
