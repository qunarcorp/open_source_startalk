/****************************************************************************
** Meta object code from reading C++ file 'groupfilelistview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../groupfilelistview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'groupfilelistview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GroupListFileItemView_t {
    QByteArrayData data[12];
    char stringdata[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GroupListFileItemView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GroupListFileItemView_t qt_meta_stringdata_GroupListFileItemView = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 25),
QT_MOC_LITERAL(2, 48, 0),
QT_MOC_LITERAL(3, 49, 3),
QT_MOC_LITERAL(4, 53, 8),
QT_MOC_LITERAL(5, 62, 4),
QT_MOC_LITERAL(6, 67, 5),
QT_MOC_LITERAL(7, 73, 21),
QT_MOC_LITERAL(8, 95, 1),
QT_MOC_LITERAL(9, 97, 15),
QT_MOC_LITERAL(10, 113, 24),
QT_MOC_LITERAL(11, 138, 8)
    },
    "GroupListFileItemView\0onDownloadProgressDisplay\0"
    "\0key\0fileName\0done\0total\0onDownloadFileClicked\0"
    "b\0onSaveAsClicked\0onDownloadProgressFinish\0"
    "filePath\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupListFileItemView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   34,    2, 0x0a,
       7,    1,   43,    2, 0x0a,
       9,    1,   46,    2, 0x0a,
      10,    3,   49,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::LongLong, QMetaType::LongLong,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,   11,

       0        // eod
};

void GroupListFileItemView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupListFileItemView *_t = static_cast<GroupListFileItemView *>(_o);
        switch (_id) {
        case 0: _t->onDownloadProgressDisplay((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const qint64(*)>(_a[3])),(*reinterpret_cast< const qint64(*)>(_a[4]))); break;
        case 1: _t->onDownloadFileClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onSaveAsClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onDownloadProgressFinish((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject GroupListFileItemView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GroupListFileItemView.data,
      qt_meta_data_GroupListFileItemView,  qt_static_metacall, 0, 0}
};


const QMetaObject *GroupListFileItemView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupListFileItemView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GroupListFileItemView.stringdata))
        return static_cast<void*>(const_cast< GroupListFileItemView*>(this));
    return QWidget::qt_metacast(_clname);
}

int GroupListFileItemView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
struct qt_meta_stringdata_GroupFileListViewAdapter_t {
    QByteArrayData data[1];
    char stringdata[26];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GroupFileListViewAdapter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GroupFileListViewAdapter_t qt_meta_stringdata_GroupFileListViewAdapter = {
    {
QT_MOC_LITERAL(0, 0, 24)
    },
    "GroupFileListViewAdapter\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupFileListViewAdapter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void GroupFileListViewAdapter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject GroupFileListViewAdapter::staticMetaObject = {
    { &ListWidgetBaseAdapter::staticMetaObject, qt_meta_stringdata_GroupFileListViewAdapter.data,
      qt_meta_data_GroupFileListViewAdapter,  qt_static_metacall, 0, 0}
};


const QMetaObject *GroupFileListViewAdapter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupFileListViewAdapter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GroupFileListViewAdapter.stringdata))
        return static_cast<void*>(const_cast< GroupFileListViewAdapter*>(this));
    return ListWidgetBaseAdapter::qt_metacast(_clname);
}

int GroupFileListViewAdapter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ListWidgetBaseAdapter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_GroupFileListView_t {
    QByteArrayData data[1];
    char stringdata[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GroupFileListView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GroupFileListView_t qt_meta_stringdata_GroupFileListView = {
    {
QT_MOC_LITERAL(0, 0, 17)
    },
    "GroupFileListView\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupFileListView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void GroupFileListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject GroupFileListView::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_GroupFileListView.data,
      qt_meta_data_GroupFileListView,  qt_static_metacall, 0, 0}
};


const QMetaObject *GroupFileListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupFileListView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GroupFileListView.stringdata))
        return static_cast<void*>(const_cast< GroupFileListView*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int GroupFileListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
