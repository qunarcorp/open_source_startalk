/****************************************************************************
** Meta object code from reading C++ file 'ChatDisplayOptionWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChatDisplayOptionWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChatDisplayOptionWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChatDisplayOptionWidget_t {
    QByteArrayData data[11];
    char stringdata[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ChatDisplayOptionWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ChatDisplayOptionWidget_t qt_meta_stringdata_ChatDisplayOptionWidget = {
    {
QT_MOC_LITERAL(0, 0, 23),
QT_MOC_LITERAL(1, 24, 16),
QT_MOC_LITERAL(2, 41, 0),
QT_MOC_LITERAL(3, 42, 17),
QT_MOC_LITERAL(4, 60, 23),
QT_MOC_LITERAL(5, 84, 5),
QT_MOC_LITERAL(6, 90, 24),
QT_MOC_LITERAL(7, 115, 20),
QT_MOC_LITERAL(8, 136, 1),
QT_MOC_LITERAL(9, 138, 20),
QT_MOC_LITERAL(10, 159, 23)
    },
    "ChatDisplayOptionWidget\0sgSelfFontChange\0"
    "\0sgOtherFontChange\0sgSelfBubbleColorChange\0"
    "color\0sgOtherBubbleColorChange\0"
    "onCurrentFontChanged\0f\0onCurrentTextChanged\0"
    "onColorSelectBtnClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatDisplayOptionWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06,
       3,    0,   50,    2, 0x06,
       4,    1,   51,    2, 0x06,
       6,    1,   54,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    1,   57,    2, 0x0a,
       9,    1,   60,    2, 0x0a,
      10,    1,   63,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QFont,    8,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void ChatDisplayOptionWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChatDisplayOptionWidget *_t = static_cast<ChatDisplayOptionWidget *>(_o);
        switch (_id) {
        case 0: _t->sgSelfFontChange(); break;
        case 1: _t->sgOtherFontChange(); break;
        case 2: _t->sgSelfBubbleColorChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sgOtherBubbleColorChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onCurrentFontChanged((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 5: _t->onCurrentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->onColorSelectBtnClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ChatDisplayOptionWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatDisplayOptionWidget::sgSelfFontChange)) {
                *result = 0;
            }
        }
        {
            typedef void (ChatDisplayOptionWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatDisplayOptionWidget::sgOtherFontChange)) {
                *result = 1;
            }
        }
        {
            typedef void (ChatDisplayOptionWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatDisplayOptionWidget::sgSelfBubbleColorChange)) {
                *result = 2;
            }
        }
        {
            typedef void (ChatDisplayOptionWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatDisplayOptionWidget::sgOtherBubbleColorChange)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject ChatDisplayOptionWidget::staticMetaObject = {
    { &LocalManWidget::staticMetaObject, qt_meta_stringdata_ChatDisplayOptionWidget.data,
      qt_meta_data_ChatDisplayOptionWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *ChatDisplayOptionWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatDisplayOptionWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChatDisplayOptionWidget.stringdata))
        return static_cast<void*>(const_cast< ChatDisplayOptionWidget*>(this));
    return LocalManWidget::qt_metacast(_clname);
}

int ChatDisplayOptionWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ChatDisplayOptionWidget::sgSelfFontChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ChatDisplayOptionWidget::sgOtherFontChange()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ChatDisplayOptionWidget::sgSelfBubbleColorChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ChatDisplayOptionWidget::sgOtherBubbleColorChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
