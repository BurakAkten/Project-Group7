/****************************************************************************
** Meta object code from reading C++ file 'secondwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../proje_gui/secondwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'secondwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SecondWindow_t {
    QByteArrayData data[15];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SecondWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SecondWindow_t qt_meta_stringdata_SecondWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SecondWindow"
QT_MOC_LITERAL(1, 13, 17), // "on_baslat_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 23), // "on_bolgeGrafigi_clicked"
QT_MOC_LITERAL(4, 56, 24), // "on_openDateGraph_clicked"
QT_MOC_LITERAL(5, 81, 15), // "on_play_clicked"
QT_MOC_LITERAL(6, 97, 15), // "on_stop_clicked"
QT_MOC_LITERAL(7, 113, 21), // "on_fullScreen_clicked"
QT_MOC_LITERAL(8, 135, 15), // "on_ekle_clicked"
QT_MOC_LITERAL(9, 151, 16), // "on_cikar_clicked"
QT_MOC_LITERAL(10, 168, 32), // "on_tableWidget_cellDoubleClicked"
QT_MOC_LITERAL(11, 201, 3), // "row"
QT_MOC_LITERAL(12, 205, 6), // "column"
QT_MOC_LITERAL(13, 212, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(14, 234, 5) // "index"

    },
    "SecondWindow\0on_baslat_clicked\0\0"
    "on_bolgeGrafigi_clicked\0"
    "on_openDateGraph_clicked\0on_play_clicked\0"
    "on_stop_clicked\0on_fullScreen_clicked\0"
    "on_ekle_clicked\0on_cikar_clicked\0"
    "on_tableWidget_cellDoubleClicked\0row\0"
    "column\0on_comboBox_activated\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SecondWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    2,   72,    2, 0x08 /* Private */,
      13,    1,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void SecondWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SecondWindow *_t = static_cast<SecondWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_baslat_clicked(); break;
        case 1: _t->on_bolgeGrafigi_clicked(); break;
        case 2: _t->on_openDateGraph_clicked(); break;
        case 3: _t->on_play_clicked(); break;
        case 4: _t->on_stop_clicked(); break;
        case 5: _t->on_fullScreen_clicked(); break;
        case 6: _t->on_ekle_clicked(); break;
        case 7: _t->on_cikar_clicked(); break;
        case 8: _t->on_tableWidget_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->on_comboBox_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SecondWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SecondWindow.data,
      qt_meta_data_SecondWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SecondWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SecondWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SecondWindow.stringdata0))
        return static_cast<void*>(const_cast< SecondWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SecondWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
