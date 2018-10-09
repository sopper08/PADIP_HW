/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hw2/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[16];
    char stringdata0[266];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 25), // "set_histogram_visble_true"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 26), // "set_histogram_visble_false"
QT_MOC_LITERAL(4, 61, 15), // "set_ADJ_visible"
QT_MOC_LITERAL(5, 77, 5), // "state"
QT_MOC_LITERAL(6, 83, 13), // "choose_source"
QT_MOC_LITERAL(7, 97, 21), // "convert_to_grayscaleI"
QT_MOC_LITERAL(8, 119, 18), // "display_compareImg"
QT_MOC_LITERAL(9, 138, 22), // "set_value_of_threshold"
QT_MOC_LITERAL(10, 161, 23), // "set_value_of_brightness"
QT_MOC_LITERAL(11, 185, 22), // "set_value_of_constrast"
QT_MOC_LITERAL(12, 208, 18), // "set_value_of_scale"
QT_MOC_LITERAL(13, 227, 17), // "display_grayscale"
QT_MOC_LITERAL(14, 245, 9), // "test_func"
QT_MOC_LITERAL(15, 255, 10) // "display_HE"

    },
    "Widget\0set_histogram_visble_true\0\0"
    "set_histogram_visble_false\0set_ADJ_visible\0"
    "state\0choose_source\0convert_to_grayscaleI\0"
    "display_compareImg\0set_value_of_threshold\0"
    "set_value_of_brightness\0set_value_of_constrast\0"
    "set_value_of_scale\0display_grayscale\0"
    "test_func\0display_HE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

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
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    1,   81,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    1,   86,    2, 0x08 /* Private */,
       9,    1,   89,    2, 0x08 /* Private */,
      10,    1,   92,    2, 0x08 /* Private */,
      11,    1,   95,    2, 0x08 /* Private */,
      12,    1,   98,    2, 0x08 /* Private */,
      13,    1,  101,    2, 0x08 /* Private */,
      14,    0,  104,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->set_histogram_visble_true(); break;
        case 1: _t->set_histogram_visble_false(); break;
        case 2: _t->set_ADJ_visible((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->choose_source(); break;
        case 4: _t->convert_to_grayscaleI(); break;
        case 5: _t->display_compareImg((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->set_value_of_threshold((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->set_value_of_brightness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->set_value_of_constrast((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->set_value_of_scale((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->display_grayscale((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->test_func(); break;
        case 12: _t->display_HE(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
