/****************************************************************************
** Meta object code from reading C++ file 'qimdroplistview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../diywidgit/customviews/qimdroplistview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qimdroplistview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QIMDropListView_t {
    QByteArrayData data[9];
    char stringdata[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QIMDropListView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QIMDropListView_t qt_meta_stringdata_QIMDropListView = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 18),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 4),
QT_MOC_LITERAL(4, 41, 22),
QT_MOC_LITERAL(5, 64, 39),
QT_MOC_LITERAL(6, 104, 8),
QT_MOC_LITERAL(7, 113, 19),
QT_MOC_LITERAL(8, 133, 8)
    },
    "QIMDropListView\0currentTextChanged\0\0"
    "text\0currentUserDataChanged\0"
    "QSharedPointer<QIMDropListViewUserData>\0"
    "userData\0popupVisableChanged\0bVisable\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QIMDropListView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06,
       4,    1,   32,    2, 0x06,
       7,    1,   35,    2, 0x06,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Bool,    8,

       0        // eod
};

void QIMDropListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QIMDropListView *_t = static_cast<QIMDropListView *>(_o);
        switch (_id) {
        case 0: _t->currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->currentUserDataChanged((*reinterpret_cast< const QSharedPointer<QIMDropListViewUserData>(*)>(_a[1]))); break;
        case 2: _t->popupVisableChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QIMDropListView::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QIMDropListView::currentTextChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (QIMDropListView::*_t)(const QSharedPointer<QIMDropListViewUserData> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QIMDropListView::currentUserDataChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (QIMDropListView::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QIMDropListView::popupVisableChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject QIMDropListView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QIMDropListView.data,
      qt_meta_data_QIMDropListView,  qt_static_metacall, 0, 0}
};


const QMetaObject *QIMDropListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QIMDropListView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QIMDropListView.stringdata))
        return static_cast<void*>(const_cast< QIMDropListView*>(this));
    return QWidget::qt_metacast(_clname);
}

int QIMDropListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void QIMDropListView::currentTextChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QIMDropListView::currentUserDataChanged(const QSharedPointer<QIMDropListViewUserData> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QIMDropListView::popupVisableChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
