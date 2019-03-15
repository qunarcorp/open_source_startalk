/****************************************************************************
** Meta object code from reading C++ file 'conversationselectwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../conversationselectwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'conversationselectwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ConversationSelectWidget_t {
    QByteArrayData data[7];
    char stringdata[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ConversationSelectWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ConversationSelectWidget_t qt_meta_stringdata_ConversationSelectWidget = {
    {
QT_MOC_LITERAL(0, 0, 24),
QT_MOC_LITERAL(1, 25, 23),
QT_MOC_LITERAL(2, 49, 0),
QT_MOC_LITERAL(3, 50, 5),
QT_MOC_LITERAL(4, 56, 18),
QT_MOC_LITERAL(5, 75, 14),
QT_MOC_LITERAL(6, 90, 19)
    },
    "ConversationSelectWidget\0"
    "onSearchEditInputChange\0\0input\0"
    "onSearchChatResult\0conversationId\0"
    "onSearchGroupResult\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConversationSelectWidget[] = {

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
       1,    1,   29,    2, 0x0a,
       4,    1,   32,    2, 0x0a,
       6,    1,   35,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void ConversationSelectWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConversationSelectWidget *_t = static_cast<ConversationSelectWidget *>(_o);
        switch (_id) {
        case 0: _t->onSearchEditInputChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onSearchChatResult((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onSearchGroupResult((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ConversationSelectWidget::staticMetaObject = {
    { &QIMLogicDialog::staticMetaObject, qt_meta_stringdata_ConversationSelectWidget.data,
      qt_meta_data_ConversationSelectWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *ConversationSelectWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConversationSelectWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConversationSelectWidget.stringdata))
        return static_cast<void*>(const_cast< ConversationSelectWidget*>(this));
    return QIMLogicDialog::qt_metacast(_clname);
}

int ConversationSelectWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QIMLogicDialog::qt_metacall(_c, _id, _a);
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
