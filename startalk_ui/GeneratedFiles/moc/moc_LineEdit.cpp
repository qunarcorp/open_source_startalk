/****************************************************************************
** Meta object code from reading C++ file 'LineEdit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LineEdit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LineEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LineEdit_t {
    QByteArrayData data[12];
    char stringdata[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LineEdit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LineEdit_t qt_meta_stringdata_LineEdit = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 14),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 19),
QT_MOC_LITERAL(4, 45, 15),
QT_MOC_LITERAL(5, 61, 7),
QT_MOC_LITERAL(6, 69, 15),
QT_MOC_LITERAL(7, 85, 14),
QT_MOC_LITERAL(8, 100, 2),
QT_MOC_LITERAL(9, 103, 15),
QT_MOC_LITERAL(10, 119, 10),
QT_MOC_LITERAL(11, 130, 10)
    },
    "LineEdit\0sgAltS_Pressed\0\0sgCtrl_EnterPressed\0"
    "sgEnter_Pressed\0sgPaste\0LineEditClicked\0"
    "onShowEditMenu\0pt\0onEditSelectAll\0"
    "onEditCopy\0onEditPast\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LineEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06,
       3,    0,   60,    2, 0x06,
       4,    0,   61,    2, 0x06,
       5,    0,   62,    2, 0x06,
       6,    0,   63,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    1,   64,    2, 0x0a,
       9,    0,   67,    2, 0x0a,
      10,    0,   68,    2, 0x0a,
      11,    0,   69,    2, 0x0a,

 // signals: parameters
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LineEdit *_t = static_cast<LineEdit *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->sgAltS_Pressed();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->sgCtrl_EnterPressed();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->sgEnter_Pressed();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->sgPaste(); break;
        case 4: _t->LineEditClicked(); break;
        case 5: _t->onShowEditMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 6: _t->onEditSelectAll(); break;
        case 7: _t->onEditCopy(); break;
        case 8: _t->onEditPast(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef bool (LineEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LineEdit::sgAltS_Pressed)) {
                *result = 0;
            }
        }
        {
            typedef bool (LineEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LineEdit::sgCtrl_EnterPressed)) {
                *result = 1;
            }
        }
        {
            typedef bool (LineEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LineEdit::sgEnter_Pressed)) {
                *result = 2;
            }
        }
        {
            typedef void (LineEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LineEdit::sgPaste)) {
                *result = 3;
            }
        }
        {
            typedef void (LineEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LineEdit::LineEditClicked)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject LineEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_LineEdit.data,
      qt_meta_data_LineEdit,  qt_static_metacall, 0, 0}
};


const QMetaObject *LineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LineEdit.stringdata))
        return static_cast<void*>(const_cast< LineEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int LineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
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
bool LineEdit::sgAltS_Pressed()
{
    bool _t0 = bool();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
bool LineEdit::sgCtrl_EnterPressed()
{
    bool _t0 = bool();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
bool LineEdit::sgEnter_Pressed()
{
    bool _t0 = bool();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
    return _t0;
}

// SIGNAL 3
void LineEdit::sgPaste()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void LineEdit::LineEditClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
