/****************************************************************************
** Meta object code from reading C++ file 'roomdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../roomdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roomdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RoomDialog_t {
    QByteArrayData data[21];
    char stringdata0[326];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RoomDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RoomDialog_t qt_meta_stringdata_RoomDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RoomDialog"
QT_MOC_LITERAL(1, 11, 14), // "SIG_closeVideo"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 13), // "SIG_openVideo"
QT_MOC_LITERAL(4, 41, 14), // "SIG_closeSound"
QT_MOC_LITERAL(5, 56, 13), // "SIG_openSound"
QT_MOC_LITERAL(6, 70, 13), // "SIG_leaveRoom"
QT_MOC_LITERAL(7, 84, 23), // "on_pu_leaveroom_clicked"
QT_MOC_LITERAL(8, 108, 12), // "slot_setInfo"
QT_MOC_LITERAL(9, 121, 5), // "clear"
QT_MOC_LITERAL(10, 127, 23), // "on_pb_openVideo_clicked"
QT_MOC_LITERAL(11, 151, 23), // "on_pb_openSound_clicked"
QT_MOC_LITERAL(12, 175, 31), // "on_cb_photo_currentIndexChanged"
QT_MOC_LITERAL(13, 207, 4), // "arg1"
QT_MOC_LITERAL(14, 212, 19), // "on_pb_close_clicked"
QT_MOC_LITERAL(15, 232, 17), // "slot_addVideoform"
QT_MOC_LITERAL(16, 250, 10), // "VideoForm*"
QT_MOC_LITERAL(17, 261, 5), // "video"
QT_MOC_LITERAL(18, 267, 20), // "slot_removeVideoform"
QT_MOC_LITERAL(19, 288, 18), // "slot_setBigImageID"
QT_MOC_LITERAL(20, 307, 18) // "slot_getBigImageID"

    },
    "RoomDialog\0SIG_closeVideo\0\0SIG_openVideo\0"
    "SIG_closeSound\0SIG_openSound\0SIG_leaveRoom\0"
    "on_pu_leaveroom_clicked\0slot_setInfo\0"
    "clear\0on_pb_openVideo_clicked\0"
    "on_pb_openSound_clicked\0"
    "on_cb_photo_currentIndexChanged\0arg1\0"
    "on_pb_close_clicked\0slot_addVideoform\0"
    "VideoForm*\0video\0slot_removeVideoform\0"
    "slot_setBigImageID\0slot_getBigImageID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoomDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    0,   96,    2, 0x06 /* Public */,
       5,    0,   97,    2, 0x06 /* Public */,
       6,    1,   98,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  101,    2, 0x0a /* Public */,
       8,    1,  102,    2, 0x0a /* Public */,
       9,    0,  105,    2, 0x0a /* Public */,
      10,    0,  106,    2, 0x0a /* Public */,
      11,    0,  107,    2, 0x0a /* Public */,
      12,    1,  108,    2, 0x0a /* Public */,
      14,    0,  111,    2, 0x0a /* Public */,
      15,    1,  112,    2, 0x0a /* Public */,
      18,    1,  115,    2, 0x0a /* Public */,
      19,    2,  118,    2, 0x0a /* Public */,
      20,    0,  123,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Int,

       0        // eod
};

void RoomDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RoomDialog *_t = static_cast<RoomDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_closeVideo(); break;
        case 1: _t->SIG_openVideo(); break;
        case 2: _t->SIG_closeSound(); break;
        case 3: _t->SIG_openSound(); break;
        case 4: _t->SIG_leaveRoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_pu_leaveroom_clicked(); break;
        case 6: _t->slot_setInfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->clear(); break;
        case 8: _t->on_pb_openVideo_clicked(); break;
        case 9: _t->on_pb_openSound_clicked(); break;
        case 10: _t->on_cb_photo_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_pb_close_clicked(); break;
        case 12: _t->slot_addVideoform((*reinterpret_cast< VideoForm*(*)>(_a[1]))); break;
        case 13: _t->slot_removeVideoform((*reinterpret_cast< VideoForm*(*)>(_a[1]))); break;
        case 14: _t->slot_setBigImageID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 15: { int _r = _t->slot_getBigImageID();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VideoForm* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VideoForm* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RoomDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomDialog::SIG_closeVideo)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RoomDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomDialog::SIG_openVideo)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RoomDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomDialog::SIG_closeSound)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (RoomDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomDialog::SIG_openSound)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (RoomDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomDialog::SIG_leaveRoom)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject RoomDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RoomDialog.data,
      qt_meta_data_RoomDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RoomDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoomDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RoomDialog.stringdata0))
        return static_cast<void*>(const_cast< RoomDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int RoomDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void RoomDialog::SIG_closeVideo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void RoomDialog::SIG_openVideo()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void RoomDialog::SIG_closeSound()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void RoomDialog::SIG_openSound()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void RoomDialog::SIG_leaveRoom(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
