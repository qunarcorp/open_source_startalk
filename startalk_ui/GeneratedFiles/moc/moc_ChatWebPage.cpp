/****************************************************************************
** Meta object code from reading C++ file 'ChatWebPage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChatWebPage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChatWebPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChatWebPage_t {
    QByteArrayData data[9];
    char stringdata[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ChatWebPage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ChatWebPage_t qt_meta_stringdata_ChatWebPage = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 11),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 7),
QT_MOC_LITERAL(4, 33, 14),
QT_MOC_LITERAL(5, 48, 2),
QT_MOC_LITERAL(6, 51, 16),
QT_MOC_LITERAL(7, 68, 17),
QT_MOC_LITERAL(8, 86, 19)
    },
    "ChatWebPage\0onCssChange\0\0cssPath\0"
    "onLoadFinished\0ok\0onSelfFontChange\0"
    "onOtherFontChange\0onSelfmsgStatusFont\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatWebPage[] = {

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
       4,    1,   42,    2, 0x08,
       6,    0,   45,    2, 0x08,
       7,    0,   46,    2, 0x08,
       8,    0,   47,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChatWebPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChatWebPage *_t = static_cast<ChatWebPage *>(_o);
        switch (_id) {
        case 0: _t->onCssChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onLoadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onSelfFontChange(); break;
        case 3: _t->onOtherFontChange(); break;
        case 4: _t->onSelfmsgStatusFont(); break;
        default: ;
        }
    }
}

const QMetaObject ChatWebPage::staticMetaObject = {
    { &WebPage::staticMetaObject, qt_meta_stringdata_ChatWebPage.data,
      qt_meta_data_ChatWebPage,  qt_static_metacall, 0, 0}
};


const QMetaObject *ChatWebPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatWebPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChatWebPage.stringdata))
        return static_cast<void*>(const_cast< ChatWebPage*>(this));
    return WebPage::qt_metacast(_clname);
}

int ChatWebPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WebPage::qt_metacall(_c, _id, _a);
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
