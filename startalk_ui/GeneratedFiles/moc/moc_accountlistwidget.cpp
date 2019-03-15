/****************************************************************************
** Meta object code from reading C++ file 'accountlistwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../accountlistwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accountlistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QDeleteButton_t {
    QByteArrayData data[4];
    char stringdata[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QDeleteButton_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QDeleteButton_t qt_meta_stringdata_QDeleteButton = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 13),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 6)
    },
    "QDeleteButton\0sgdeleteclick\0\0nIndex\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QDeleteButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void QDeleteButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QDeleteButton *_t = static_cast<QDeleteButton *>(_o);
        switch (_id) {
        case 0: _t->sgdeleteclick((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QDeleteButton::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDeleteButton::sgdeleteclick)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QDeleteButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_QDeleteButton.data,
      qt_meta_data_QDeleteButton,  qt_static_metacall, 0, 0}
};


const QMetaObject *QDeleteButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDeleteButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeleteButton.stringdata))
        return static_cast<void*>(const_cast< QDeleteButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int QDeleteButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QDeleteButton::sgdeleteclick(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_AccountItemView_t {
    QByteArrayData data[1];
    char stringdata[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AccountItemView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AccountItemView_t qt_meta_stringdata_AccountItemView = {
    {
QT_MOC_LITERAL(0, 0, 15)
    },
    "AccountItemView\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccountItemView[] = {

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

void AccountItemView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject AccountItemView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AccountItemView.data,
      qt_meta_data_AccountItemView,  qt_static_metacall, 0, 0}
};


const QMetaObject *AccountItemView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccountItemView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AccountItemView.stringdata))
        return static_cast<void*>(const_cast< AccountItemView*>(this));
    return QWidget::qt_metacast(_clname);
}

int AccountItemView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_AccountListWidgetAdapter_t {
    QByteArrayData data[3];
    char stringdata[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AccountListWidgetAdapter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AccountListWidgetAdapter_t qt_meta_stringdata_AccountListWidgetAdapter = {
    {
QT_MOC_LITERAL(0, 0, 24),
QT_MOC_LITERAL(1, 25, 20),
QT_MOC_LITERAL(2, 46, 0)
    },
    "AccountListWidgetAdapter\0sgLoginAccountDelete\0"
    "\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccountListWidgetAdapter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x06,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,

       0        // eod
};

void AccountListWidgetAdapter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AccountListWidgetAdapter *_t = static_cast<AccountListWidgetAdapter *>(_o);
        switch (_id) {
        case 0: _t->sgLoginAccountDelete((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AccountListWidgetAdapter::*_t)(const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AccountListWidgetAdapter::sgLoginAccountDelete)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject AccountListWidgetAdapter::staticMetaObject = {
    { &ListWidgetBaseAdapter::staticMetaObject, qt_meta_stringdata_AccountListWidgetAdapter.data,
      qt_meta_data_AccountListWidgetAdapter,  qt_static_metacall, 0, 0}
};


const QMetaObject *AccountListWidgetAdapter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccountListWidgetAdapter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AccountListWidgetAdapter.stringdata))
        return static_cast<void*>(const_cast< AccountListWidgetAdapter*>(this));
    return ListWidgetBaseAdapter::qt_metacast(_clname);
}

int AccountListWidgetAdapter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ListWidgetBaseAdapter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void AccountListWidgetAdapter::sgLoginAccountDelete(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_AccountListWidget_t {
    QByteArrayData data[11];
    char stringdata[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AccountListWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AccountListWidget_t qt_meta_stringdata_AccountListWidget = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 21),
QT_MOC_LITERAL(2, 40, 0),
QT_MOC_LITERAL(3, 41, 43),
QT_MOC_LITERAL(4, 85, 12),
QT_MOC_LITERAL(5, 98, 13),
QT_MOC_LITERAL(6, 112, 16),
QT_MOC_LITERAL(7, 129, 4),
QT_MOC_LITERAL(8, 134, 20),
QT_MOC_LITERAL(9, 155, 8),
QT_MOC_LITERAL(10, 164, 7)
    },
    "AccountListWidget\0sgAccountItemSelected\0"
    "\0QSharedPointer<Biz::LoginAccountConfigInfo>\0"
    "loginaccount\0onItemClicked\0QListWidgetItem*\0"
    "item\0onLoginAccountDelete\0loginpwd\0"
    "navaddr\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccountListWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    1,   32,    2, 0x0a,
       8,    3,   35,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    9,   10,

       0        // eod
};

void AccountListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AccountListWidget *_t = static_cast<AccountListWidget *>(_o);
        switch (_id) {
        case 0: _t->sgAccountItemSelected((*reinterpret_cast< const QSharedPointer<Biz::LoginAccountConfigInfo>(*)>(_a[1]))); break;
        case 1: _t->onItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->onLoginAccountDelete((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSharedPointer<Biz::LoginAccountConfigInfo> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AccountListWidget::*_t)(const QSharedPointer<Biz::LoginAccountConfigInfo> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AccountListWidget::sgAccountItemSelected)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject AccountListWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AccountListWidget.data,
      qt_meta_data_AccountListWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *AccountListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccountListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AccountListWidget.stringdata))
        return static_cast<void*>(const_cast< AccountListWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AccountListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void AccountListWidget::sgAccountItemSelected(const QSharedPointer<Biz::LoginAccountConfigInfo> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
