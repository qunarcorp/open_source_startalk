/****************************************************************************
** Meta object code from reading C++ file 'vidioandaudiodialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../vidioandaudiodialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vidioandaudiodialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VidioAndAudioDialog_t {
    QByteArrayData data[22];
    char stringdata[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_VidioAndAudioDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_VidioAndAudioDialog_t qt_meta_stringdata_VidioAndAudioDialog = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 14),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 2),
QT_MOC_LITERAL(4, 39, 5),
QT_MOC_LITERAL(5, 45, 7),
QT_MOC_LITERAL(6, 53, 16),
QT_MOC_LITERAL(7, 70, 16),
QT_MOC_LITERAL(8, 87, 4),
QT_MOC_LITERAL(9, 92, 18),
QT_MOC_LITERAL(10, 111, 16),
QT_MOC_LITERAL(11, 128, 15),
QT_MOC_LITERAL(12, 144, 3),
QT_MOC_LITERAL(13, 148, 17),
QT_MOC_LITERAL(14, 166, 16),
QT_MOC_LITERAL(15, 183, 24),
QT_MOC_LITERAL(16, 208, 12),
QT_MOC_LITERAL(17, 221, 4),
QT_MOC_LITERAL(18, 226, 16),
QT_MOC_LITERAL(19, 243, 6),
QT_MOC_LITERAL(20, 250, 18),
QT_MOC_LITERAL(21, 269, 5)
    },
    "VidioAndAudioDialog\0sgLoadFinished\0\0"
    "id\0onMin\0onClose\0onLoadHtmlFinish\0"
    "onRecievedSingle\0json\0OnVideoSendSingnal\0"
    "OnCloseRtcWindow\0onWriteLocalLog\0log\0"
    "onStartVideoSound\0onStopVideoSound\0"
    "onVideoOrAudeoRecievPing\0conversation\0"
    "type\0OnCloseVideoRoom\0roomid\0"
    "onFullScreenWindow\0bflag\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VidioAndAudioDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   82,    2, 0x0a,
       5,    0,   83,    2, 0x0a,
       6,    0,   84,    2, 0x0a,
       7,    2,   85,    2, 0x0a,
       9,    2,   90,    2, 0x0a,
      10,    1,   95,    2, 0x0a,
      11,    2,   98,    2, 0x0a,
      13,    1,  103,    2, 0x0a,
      14,    1,  106,    2, 0x0a,
      15,    2,  109,    2, 0x0a,
      18,    1,  114,    2, 0x0a,
      20,    2,  117,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,   12,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   16,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   19,   21,

       0        // eod
};

void VidioAndAudioDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VidioAndAudioDialog *_t = static_cast<VidioAndAudioDialog *>(_o);
        switch (_id) {
        case 0: _t->sgLoadFinished((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onMin(); break;
        case 2: _t->onClose(); break;
        case 3: _t->onLoadHtmlFinish(); break;
        case 4: _t->onRecievedSingle((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->OnVideoSendSingnal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->OnCloseRtcWindow((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->onWriteLocalLog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->onStartVideoSound((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->onStopVideoSound((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->onVideoOrAudeoRecievPing((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->OnCloseVideoRoom((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->onFullScreenWindow((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VidioAndAudioDialog::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VidioAndAudioDialog::sgLoadFinished)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject VidioAndAudioDialog::staticMetaObject = {
    { &LocalManDialog::staticMetaObject, qt_meta_stringdata_VidioAndAudioDialog.data,
      qt_meta_data_VidioAndAudioDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *VidioAndAudioDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VidioAndAudioDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VidioAndAudioDialog.stringdata))
        return static_cast<void*>(const_cast< VidioAndAudioDialog*>(this));
    return LocalManDialog::qt_metacast(_clname);
}

int VidioAndAudioDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LocalManDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void VidioAndAudioDialog::sgLoadFinished(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
