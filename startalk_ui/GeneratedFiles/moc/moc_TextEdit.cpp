/****************************************************************************
** Meta object code from reading C++ file 'TextEdit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TextEdit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TextEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TextEdit_t {
    QByteArrayData data[12];
    char stringdata[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TextEdit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TextEdit_t qt_meta_stringdata_TextEdit = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 14),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 19),
QT_MOC_LITERAL(4, 45, 15),
QT_MOC_LITERAL(5, 61, 20),
QT_MOC_LITERAL(6, 82, 16),
QT_MOC_LITERAL(7, 99, 8),
QT_MOC_LITERAL(8, 108, 7),
QT_MOC_LITERAL(9, 116, 21),
QT_MOC_LITERAL(10, 138, 3),
QT_MOC_LITERAL(11, 142, 7)
    },
    "TextEdit\0sgAltS_Pressed\0\0sgCtrl_EnterPressed\0"
    "sgEnter_Pressed\0sgShift_EnterPressed\0"
    "sgScreenShotFile\0QString&\0sgPaste\0"
    "onInputTextSizeChange\0val\0animate\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06,
       3,    0,   55,    2, 0x06,
       4,    0,   56,    2, 0x06,
       5,    0,   57,    2, 0x06,
       6,    1,   58,    2, 0x06,
       8,    0,   61,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       9,    1,   62,    2, 0x0a,
      11,    0,   65,    2, 0x08,

 // signals: parameters
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal,   10,
    QMetaType::Void,

       0        // eod
};

void TextEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TextEdit *_t = static_cast<TextEdit *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->sgAltS_Pressed();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->sgCtrl_EnterPressed();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->sgEnter_Pressed();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->sgShift_EnterPressed();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: _t->sgScreenShotFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->sgPaste(); break;
        case 6: _t->onInputTextSizeChange((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 7: _t->animate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef bool (TextEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextEdit::sgAltS_Pressed)) {
                *result = 0;
            }
        }
        {
            typedef bool (TextEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextEdit::sgCtrl_EnterPressed)) {
                *result = 1;
            }
        }
        {
            typedef bool (TextEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextEdit::sgEnter_Pressed)) {
                *result = 2;
            }
        }
        {
            typedef bool (TextEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextEdit::sgShift_EnterPressed)) {
                *result = 3;
            }
        }
        {
            typedef void (TextEdit::*_t)(QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextEdit::sgScreenShotFile)) {
                *result = 4;
            }
        }
        {
            typedef void (TextEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextEdit::sgPaste)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject TextEdit::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_TextEdit.data,
      qt_meta_data_TextEdit,  qt_static_metacall, 0, 0}
};


const QMetaObject *TextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TextEdit.stringdata))
        return static_cast<void*>(const_cast< TextEdit*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int TextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
bool TextEdit::sgAltS_Pressed()
{
    bool _t0 = bool();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
bool TextEdit::sgCtrl_EnterPressed()
{
    bool _t0 = bool();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
bool TextEdit::sgEnter_Pressed()
{
    bool _t0 = bool();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
    return _t0;
}

// SIGNAL 3
bool TextEdit::sgShift_EnterPressed()
{
    bool _t0 = bool();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
    return _t0;
}

// SIGNAL 4
void TextEdit::sgScreenShotFile(QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TextEdit::sgPaste()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
