/****************************************************************************
** Meta object code from reading C++ file 'pinnedlistview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../diywidgit/customviews/pinnedlistview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pinnedlistview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SmoothVScrollBar_t {
    QByteArrayData data[5];
    char stringdata[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SmoothVScrollBar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SmoothVScrollBar_t qt_meta_stringdata_SmoothVScrollBar = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 23),
QT_MOC_LITERAL(2, 41, 0),
QT_MOC_LITERAL(3, 42, 5),
QT_MOC_LITERAL(4, 48, 26)
    },
    "SmoothVScrollBar\0onScrollBarValueChanged\0"
    "\0value\0onScrollBarActionTriggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SmoothVScrollBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x09,
       4,    1,   27,    2, 0x09,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void SmoothVScrollBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SmoothVScrollBar *_t = static_cast<SmoothVScrollBar *>(_o);
        switch (_id) {
        case 0: _t->onScrollBarValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onScrollBarActionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SmoothVScrollBar::staticMetaObject = {
    { &QScrollBar::staticMetaObject, qt_meta_stringdata_SmoothVScrollBar.data,
      qt_meta_data_SmoothVScrollBar,  qt_static_metacall, 0, 0}
};


const QMetaObject *SmoothVScrollBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SmoothVScrollBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SmoothVScrollBar.stringdata))
        return static_cast<void*>(const_cast< SmoothVScrollBar*>(this));
    return QScrollBar::qt_metacast(_clname);
}

int SmoothVScrollBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_PinnedListView_t {
    QByteArrayData data[10];
    char stringdata[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PinnedListView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PinnedListView_t qt_meta_stringdata_PinnedListView = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 18),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 3),
QT_MOC_LITERAL(4, 39, 19),
QT_MOC_LITERAL(5, 59, 13),
QT_MOC_LITERAL(6, 73, 11),
QT_MOC_LITERAL(7, 85, 19),
QT_MOC_LITERAL(8, 105, 5),
QT_MOC_LITERAL(9, 111, 13)
    },
    "PinnedListView\0sgContextMenuEvent\0\0"
    "jid\0sgItemDoubleClicked\0sgItemClicked\0"
    "sgListEmpty\0onItemDoubleClicked\0index\0"
    "onItemClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PinnedListView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,
       4,    1,   47,    2, 0x06,
       5,    1,   50,    2, 0x06,
       6,    0,   53,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    1,   54,    2, 0x09,
       9,    1,   57,    2, 0x09,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void, QMetaType::QModelIndex,    8,

       0        // eod
};

void PinnedListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PinnedListView *_t = static_cast<PinnedListView *>(_o);
        switch (_id) {
        case 0: _t->sgContextMenuEvent((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sgItemDoubleClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->sgItemClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->sgListEmpty(); break;
        case 4: _t->onItemDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->onItemClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PinnedListView::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PinnedListView::sgContextMenuEvent)) {
                *result = 0;
            }
        }
        {
            typedef void (PinnedListView::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PinnedListView::sgItemDoubleClicked)) {
                *result = 1;
            }
        }
        {
            typedef void (PinnedListView::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PinnedListView::sgItemClicked)) {
                *result = 2;
            }
        }
        {
            typedef void (PinnedListView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PinnedListView::sgListEmpty)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject PinnedListView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PinnedListView.data,
      qt_meta_data_PinnedListView,  qt_static_metacall, 0, 0}
};


const QMetaObject *PinnedListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PinnedListView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PinnedListView.stringdata))
        return static_cast<void*>(const_cast< PinnedListView*>(this));
    return QWidget::qt_metacast(_clname);
}

int PinnedListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void PinnedListView::sgContextMenuEvent(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PinnedListView::sgItemDoubleClicked(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PinnedListView::sgItemClicked(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PinnedListView::sgListEmpty()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
