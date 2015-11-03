/****************************************************************************
** Meta object code from reading C++ file 'myglwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cc_qt/myglwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myglwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GLWidget_t {
    QByteArrayData data[25];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GLWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GLWidget_t qt_meta_stringdata_GLWidget = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GLWidget"
QT_MOC_LITERAL(1, 9, 6), // "setBGR"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 1), // "r"
QT_MOC_LITERAL(4, 19, 6), // "setBGG"
QT_MOC_LITERAL(5, 26, 1), // "g"
QT_MOC_LITERAL(6, 28, 6), // "setBGB"
QT_MOC_LITERAL(7, 35, 1), // "b"
QT_MOC_LITERAL(8, 37, 8), // "setCubeX"
QT_MOC_LITERAL(9, 46, 1), // "x"
QT_MOC_LITERAL(10, 48, 8), // "setCubeY"
QT_MOC_LITERAL(11, 57, 1), // "y"
QT_MOC_LITERAL(12, 59, 8), // "setCubeZ"
QT_MOC_LITERAL(13, 68, 1), // "z"
QT_MOC_LITERAL(14, 70, 8), // "setLevel"
QT_MOC_LITERAL(15, 79, 5), // "level"
QT_MOC_LITERAL(16, 85, 16), // "setWireFrameTrue"
QT_MOC_LITERAL(17, 102, 9), // "wireframe"
QT_MOC_LITERAL(18, 112, 17), // "setWireFrameFalse"
QT_MOC_LITERAL(19, 130, 17), // "setWithOffsetTrue"
QT_MOC_LITERAL(20, 148, 10), // "withOffset"
QT_MOC_LITERAL(21, 159, 18), // "setWithOffsetFalse"
QT_MOC_LITERAL(22, 178, 9), // "setOffset"
QT_MOC_LITERAL(23, 188, 9), // "offsetVal"
QT_MOC_LITERAL(24, 198, 9) // "fetchFile"

    },
    "GLWidget\0setBGR\0\0r\0setBGG\0g\0setBGB\0b\0"
    "setCubeX\0x\0setCubeY\0y\0setCubeZ\0z\0"
    "setLevel\0level\0setWireFrameTrue\0"
    "wireframe\0setWireFrameFalse\0"
    "setWithOffsetTrue\0withOffset\0"
    "setWithOffsetFalse\0setOffset\0offsetVal\0"
    "fetchFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GLWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x0a /* Public */,
       4,    1,   82,    2, 0x0a /* Public */,
       6,    1,   85,    2, 0x0a /* Public */,
       8,    1,   88,    2, 0x0a /* Public */,
      10,    1,   91,    2, 0x0a /* Public */,
      12,    1,   94,    2, 0x0a /* Public */,
      14,    1,   97,    2, 0x0a /* Public */,
      16,    1,  100,    2, 0x0a /* Public */,
      18,    1,  103,    2, 0x0a /* Public */,
      19,    1,  106,    2, 0x0a /* Public */,
      21,    1,  109,    2, 0x0a /* Public */,
      22,    1,  112,    2, 0x0a /* Public */,
      24,    0,  115,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,

       0        // eod
};

void GLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GLWidget *_t = static_cast<GLWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setBGR((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setBGG((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setBGB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setCubeX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setCubeY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setCubeZ((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setWireFrameTrue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setWireFrameFalse((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setWithOffsetTrue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setWithOffsetFalse((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->setOffset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->fetchFile(); break;
        default: ;
        }
    }
}

const QMetaObject GLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_GLWidget.data,
      qt_meta_data_GLWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GLWidget.stringdata0))
        return static_cast<void*>(const_cast< GLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int GLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
