/****************************************************************************
** Meta object code from reading C++ file 'createnewgroup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../createnewgroup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'createnewgroup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BaseItem_t {
    QByteArrayData data[1];
    char stringdata[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_BaseItem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_BaseItem_t qt_meta_stringdata_BaseItem = {
    {
QT_MOC_LITERAL(0, 0, 8)
    },
    "BaseItem\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaseItem[] = {

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

void BaseItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject BaseItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BaseItem.data,
      qt_meta_data_BaseItem,  qt_static_metacall, 0, 0}
};


const QMetaObject *BaseItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaseItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BaseItem.stringdata))
        return static_cast<void*>(const_cast< BaseItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int BaseItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_GroupItem_L_t {
    QByteArrayData data[9];
    char stringdata[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GroupItem_L_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GroupItem_L_t qt_meta_stringdata_GroupItem_L = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 16),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 4),
QT_MOC_LITERAL(4, 35, 16),
QT_MOC_LITERAL(5, 52, 5),
QT_MOC_LITERAL(6, 58, 7),
QT_MOC_LITERAL(7, 66, 17),
QT_MOC_LITERAL(8, 84, 5)
    },
    "GroupItem_L\0sgLoadItemsChild\0\0name\0"
    "QTreeWidgetItem*\0pItem\0checked\0"
    "sgSelectMembersIn\0check\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupItem_L[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x06,
       7,    3,   31,    2, 0x06,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, QMetaType::Bool,    3,    5,    6,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, QMetaType::Bool,    3,    5,    8,

       0        // eod
};

void GroupItem_L::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupItem_L *_t = static_cast<GroupItem_L *>(_o);
        switch (_id) {
        case 0: _t->sgLoadItemsChild((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->sgSelectMembersIn((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GroupItem_L::*_t)(const QString & , QTreeWidgetItem * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupItem_L::sgLoadItemsChild)) {
                *result = 0;
            }
        }
        {
            typedef void (GroupItem_L::*_t)(const QString & , QTreeWidgetItem * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupItem_L::sgSelectMembersIn)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject GroupItem_L::staticMetaObject = {
    { &BaseItem::staticMetaObject, qt_meta_stringdata_GroupItem_L.data,
      qt_meta_data_GroupItem_L,  qt_static_metacall, 0, 0}
};


const QMetaObject *GroupItem_L::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupItem_L::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GroupItem_L.stringdata))
        return static_cast<void*>(const_cast< GroupItem_L*>(this));
    return BaseItem::qt_metacast(_clname);
}

int GroupItem_L::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseItem::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void GroupItem_L::sgLoadItemsChild(const QString & _t1, QTreeWidgetItem * _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GroupItem_L::sgSelectMembersIn(const QString & _t1, QTreeWidgetItem * _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_PersonItem_L_t {
    QByteArrayData data[8];
    char stringdata[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PersonItem_L_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PersonItem_L_t qt_meta_stringdata_PersonItem_L = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 14),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 13),
QT_MOC_LITERAL(4, 43, 7),
QT_MOC_LITERAL(5, 51, 8),
QT_MOC_LITERAL(6, 60, 16),
QT_MOC_LITERAL(7, 77, 7)
    },
    "PersonItem_L\0sgSelectPerson\0\0PersonItem_L*\0"
    "personL\0selected\0onSelectBtnClick\0"
    "cheched\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PersonItem_L[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    1,   29,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void PersonItem_L::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PersonItem_L *_t = static_cast<PersonItem_L *>(_o);
        switch (_id) {
        case 0: _t->sgSelectPerson((*reinterpret_cast< PersonItem_L*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->onSelectBtnClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PersonItem_L* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PersonItem_L::*_t)(PersonItem_L * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PersonItem_L::sgSelectPerson)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject PersonItem_L::staticMetaObject = {
    { &BaseItem::staticMetaObject, qt_meta_stringdata_PersonItem_L.data,
      qt_meta_data_PersonItem_L,  qt_static_metacall, 0, 0}
};


const QMetaObject *PersonItem_L::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PersonItem_L::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PersonItem_L.stringdata))
        return static_cast<void*>(const_cast< PersonItem_L*>(this));
    return BaseItem::qt_metacast(_clname);
}

int PersonItem_L::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void PersonItem_L::sgSelectPerson(PersonItem_L * _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_PersonItem_R_t {
    QByteArrayData data[6];
    char stringdata[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PersonItem_R_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PersonItem_R_t qt_meta_stringdata_PersonItem_R = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 14),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 3),
QT_MOC_LITERAL(4, 33, 14),
QT_MOC_LITERAL(5, 48, 5)
    },
    "PersonItem_R\0sgDeletePerson\0\0jid\0"
    "onDeletePerson\0ignal\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PersonItem_R[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    1,   27,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,

       0        // eod
};

void PersonItem_R::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PersonItem_R *_t = static_cast<PersonItem_R *>(_o);
        switch (_id) {
        case 0: _t->sgDeletePerson((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onDeletePerson((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PersonItem_R::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PersonItem_R::sgDeletePerson)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject PersonItem_R::staticMetaObject = {
    { &BaseItem::staticMetaObject, qt_meta_stringdata_PersonItem_R.data,
      qt_meta_data_PersonItem_R,  qt_static_metacall, 0, 0}
};


const QMetaObject *PersonItem_R::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PersonItem_R::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PersonItem_R.stringdata))
        return static_cast<void*>(const_cast< PersonItem_R*>(this));
    return BaseItem::qt_metacast(_clname);
}

int PersonItem_R::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseItem::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void PersonItem_R::sgDeletePerson(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_CreateNewGroup_t {
    QByteArrayData data[27];
    char stringdata[363];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CreateNewGroup_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CreateNewGroup_t qt_meta_stringdata_CreateNewGroup = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 16),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 4),
QT_MOC_LITERAL(4, 38, 16),
QT_MOC_LITERAL(5, 55, 5),
QT_MOC_LITERAL(6, 61, 7),
QT_MOC_LITERAL(7, 69, 19),
QT_MOC_LITERAL(8, 89, 1),
QT_MOC_LITERAL(9, 91, 23),
QT_MOC_LITERAL(10, 115, 3),
QT_MOC_LITERAL(11, 119, 15),
QT_MOC_LITERAL(12, 135, 13),
QT_MOC_LITERAL(13, 149, 7),
QT_MOC_LITERAL(14, 157, 8),
QT_MOC_LITERAL(15, 166, 24),
QT_MOC_LITERAL(16, 191, 15),
QT_MOC_LITERAL(17, 207, 3),
QT_MOC_LITERAL(18, 211, 11),
QT_MOC_LITERAL(19, 223, 27),
QT_MOC_LITERAL(20, 251, 22),
QT_MOC_LITERAL(21, 274, 21),
QT_MOC_LITERAL(22, 296, 20),
QT_MOC_LITERAL(23, 317, 7),
QT_MOC_LITERAL(24, 325, 9),
QT_MOC_LITERAL(25, 335, 19),
QT_MOC_LITERAL(26, 355, 6)
    },
    "CreateNewGroup\0onLoadItemsChild\0\0name\0"
    "QTreeWidgetItem*\0pItem\0checked\0"
    "onAddMembersInGroup\0b\0onSearchEditInputChange\0"
    "key\0onLSelectChange\0PersonItem_L*\0"
    "personL\0selected\0onFriendListSelectChange\0"
    "onRDeletePerson\0jid\0onAddmember\0"
    "onRightScrollBarValueChange\0"
    "setItemChildrenChecked\0onCreateGroupBtnClick\0"
    "onCreateGroupSuccess\0groupid\0groupname\0"
    "onTabButtionClicked\0bCheck\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateNewGroup[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   74,    2, 0x0a,
       7,    3,   81,    2, 0x0a,
       9,    1,   88,    2, 0x0a,
      11,    2,   91,    2, 0x0a,
      15,    2,   96,    2, 0x0a,
      16,    1,  101,    2, 0x0a,
      18,    1,  104,    2, 0x0a,
      19,    1,  107,    2, 0x0a,
      20,    2,  110,    2, 0x0a,
      21,    0,  115,    2, 0x0a,
      22,    2,  116,    2, 0x0a,
      25,    1,  121,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, QMetaType::Bool,    3,    5,    6,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, QMetaType::Bool,    3,    5,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Bool,   13,   14,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Bool,   13,   14,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Bool,    5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   23,   24,
    QMetaType::Void, QMetaType::Bool,   26,

       0        // eod
};

void CreateNewGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateNewGroup *_t = static_cast<CreateNewGroup *>(_o);
        switch (_id) {
        case 0: _t->onLoadItemsChild((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->onAddMembersInGroup((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->onSearchEditInputChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onLSelectChange((*reinterpret_cast< PersonItem_L*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->onFriendListSelectChange((*reinterpret_cast< PersonItem_L*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->onRDeletePerson((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->onAddmember((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->onRightScrollBarValueChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setItemChildrenChecked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->onCreateGroupBtnClick(); break;
        case 10: _t->onCreateGroupSuccess((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: _t->onTabButtionClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PersonItem_L* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PersonItem_L* >(); break;
            }
            break;
        }
    }
}

const QMetaObject CreateNewGroup::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_CreateNewGroup.data,
      qt_meta_data_CreateNewGroup,  qt_static_metacall, 0, 0}
};


const QMetaObject *CreateNewGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateNewGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CreateNewGroup.stringdata))
        return static_cast<void*>(const_cast< CreateNewGroup*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int CreateNewGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
