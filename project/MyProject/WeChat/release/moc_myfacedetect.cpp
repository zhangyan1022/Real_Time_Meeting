/****************************************************************************
** Meta object code from reading C++ file 'myfacedetect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RecordVideo/myfacedetect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myfacedetect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyFaceDetect_t {
    QByteArrayData data[8];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyFaceDetect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyFaceDetect_t qt_meta_stringdata_MyFaceDetect = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MyFaceDetect"
QT_MOC_LITERAL(1, 13, 16), // "detectAndDisplay"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "Mat&"
QT_MOC_LITERAL(4, 36, 5), // "frame"
QT_MOC_LITERAL(5, 42, 18), // "std::vector<Rect>&"
QT_MOC_LITERAL(6, 61, 5), // "faces"
QT_MOC_LITERAL(7, 67, 14) // "FaceDetectInit"

    },
    "MyFaceDetect\0detectAndDisplay\0\0Mat&\0"
    "frame\0std::vector<Rect>&\0faces\0"
    "FaceDetectInit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyFaceDetect[] = {

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
       1,    2,   24,    2, 0x0a /* Public */,
       7,    0,   29,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,

       0        // eod
};

void MyFaceDetect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyFaceDetect *_t = static_cast<MyFaceDetect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->detectAndDisplay((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< std::vector<Rect>(*)>(_a[2]))); break;
        case 1: _t->FaceDetectInit(); break;
        default: ;
        }
    }
}

const QMetaObject MyFaceDetect::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyFaceDetect.data,
      qt_meta_data_MyFaceDetect,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyFaceDetect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyFaceDetect::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyFaceDetect.stringdata0))
        return static_cast<void*>(const_cast< MyFaceDetect*>(this));
    return QObject::qt_metacast(_clname);
}

int MyFaceDetect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
