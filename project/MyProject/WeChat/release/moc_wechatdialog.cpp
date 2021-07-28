/****************************************************************************
** Meta object code from reading C++ file 'wechatdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wechatdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wechatdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WeChatDialog_t {
    QByteArrayData data[22];
    char stringdata0[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeChatDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeChatDialog_t qt_meta_stringdata_WeChatDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "WeChatDialog"
QT_MOC_LITERAL(1, 13, 9), // "SIG_close"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "SIG_addFriend"
QT_MOC_LITERAL(4, 38, 14), // "SIG_createRoom"
QT_MOC_LITERAL(5, 53, 12), // "SIG_joinRoom"
QT_MOC_LITERAL(6, 66, 13), // "SIG_systemSet"
QT_MOC_LITERAL(7, 80, 11), // "SIG_offLine"
QT_MOC_LITERAL(8, 92, 12), // "slot_setInfo"
QT_MOC_LITERAL(9, 105, 2), // "id"
QT_MOC_LITERAL(10, 108, 4), // "name"
QT_MOC_LITERAL(11, 113, 6), // "iconid"
QT_MOC_LITERAL(12, 120, 7), // "feeling"
QT_MOC_LITERAL(13, 128, 16), // "slot_addUserItem"
QT_MOC_LITERAL(14, 145, 8), // "QWidget*"
QT_MOC_LITERAL(15, 154, 4), // "item"
QT_MOC_LITERAL(16, 159, 19), // "slot_removeUserItem"
QT_MOC_LITERAL(17, 179, 13), // "slot_dealMenu"
QT_MOC_LITERAL(18, 193, 8), // "QAction*"
QT_MOC_LITERAL(19, 202, 6), // "action"
QT_MOC_LITERAL(20, 209, 18), // "on_pb_menu_clicked"
QT_MOC_LITERAL(21, 228, 19) // "on_pb_close_clicked"

    },
    "WeChatDialog\0SIG_close\0\0SIG_addFriend\0"
    "SIG_createRoom\0SIG_joinRoom\0SIG_systemSet\0"
    "SIG_offLine\0slot_setInfo\0id\0name\0"
    "iconid\0feeling\0slot_addUserItem\0"
    "QWidget*\0item\0slot_removeUserItem\0"
    "slot_dealMenu\0QAction*\0action\0"
    "on_pb_menu_clicked\0on_pb_close_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeChatDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    1,   77,    2, 0x06 /* Public */,
       6,    0,   80,    2, 0x06 /* Public */,
       7,    0,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    4,   82,    2, 0x0a /* Public */,
      13,    1,   91,    2, 0x0a /* Public */,
      16,    1,   94,    2, 0x0a /* Public */,
      17,    1,   97,    2, 0x0a /* Public */,
      20,    0,  100,    2, 0x08 /* Private */,
      21,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString,    9,   10,   11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WeChatDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WeChatDialog *_t = static_cast<WeChatDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_close(); break;
        case 1: _t->SIG_addFriend(); break;
        case 2: _t->SIG_createRoom(); break;
        case 3: _t->SIG_joinRoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->SIG_systemSet(); break;
        case 5: _t->SIG_offLine(); break;
        case 6: _t->slot_setInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 7: _t->slot_addUserItem((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 8: _t->slot_removeUserItem((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 9: _t->slot_dealMenu((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 10: _t->on_pb_menu_clicked(); break;
        case 11: _t->on_pb_close_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WeChatDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeChatDialog::SIG_close)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WeChatDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeChatDialog::SIG_addFriend)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WeChatDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeChatDialog::SIG_createRoom)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (WeChatDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeChatDialog::SIG_joinRoom)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (WeChatDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeChatDialog::SIG_systemSet)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (WeChatDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeChatDialog::SIG_offLine)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject WeChatDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_WeChatDialog.data,
      qt_meta_data_WeChatDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WeChatDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeChatDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WeChatDialog.stringdata0))
        return static_cast<void*>(const_cast< WeChatDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int WeChatDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void WeChatDialog::SIG_close()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void WeChatDialog::SIG_addFriend()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void WeChatDialog::SIG_createRoom()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void WeChatDialog::SIG_joinRoom(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void WeChatDialog::SIG_systemSet()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void WeChatDialog::SIG_offLine()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
