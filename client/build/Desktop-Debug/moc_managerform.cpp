/****************************************************************************
** Meta object code from reading C++ file 'managerform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../managerform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'managerform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ManagerForm_t {
    QByteArrayData data[18];
    char stringdata0[322];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ManagerForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ManagerForm_t qt_meta_stringdata_ManagerForm = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ManagerForm"
QT_MOC_LITERAL(1, 12, 15), // "showLoginWindow"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 22), // "showRegistrationWindow"
QT_MOC_LITERAL(4, 52, 25), // "showDriverCompanionWindow"
QT_MOC_LITERAL(5, 78, 19), // "showCompanionWindow"
QT_MOC_LITERAL(6, 98, 16), // "showDriverWindow"
QT_MOC_LITERAL(7, 115, 13), // "showCarWindow"
QT_MOC_LITERAL(8, 129, 6), // "tripId"
QT_MOC_LITERAL(9, 136, 8), // "tripInfo"
QT_MOC_LITERAL(10, 145, 22), // "handleReturnToPrevious"
QT_MOC_LITERAL(11, 168, 16), // "showFinishWindow"
QT_MOC_LITERAL(12, 185, 24), // "showMainWindowFromFinish"
QT_MOC_LITERAL(13, 210, 25), // "onConnectionStatusChanged"
QT_MOC_LITERAL(14, 236, 9), // "connected"
QT_MOC_LITERAL(15, 246, 18), // "showFeedbackWindow"
QT_MOC_LITERAL(16, 265, 38), // "showDriverCompanionWindowFrom..."
QT_MOC_LITERAL(17, 304, 17) // "showProfileWindow"

    },
    "ManagerForm\0showLoginWindow\0\0"
    "showRegistrationWindow\0showDriverCompanionWindow\0"
    "showCompanionWindow\0showDriverWindow\0"
    "showCarWindow\0tripId\0tripInfo\0"
    "handleReturnToPrevious\0showFinishWindow\0"
    "showMainWindowFromFinish\0"
    "onConnectionStatusChanged\0connected\0"
    "showFeedbackWindow\0"
    "showDriverCompanionWindowFromCompanion\0"
    "showProfileWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManagerForm[] = {

 // content:
       8,       // revision
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
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    2,   84,    2, 0x08 /* Private */,
      10,    0,   89,    2, 0x08 /* Private */,
      11,    0,   90,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    1,   92,    2, 0x08 /* Private */,
      15,    0,   95,    2, 0x08 /* Private */,
      16,    0,   96,    2, 0x08 /* Private */,
      17,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QVariantMap,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ManagerForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ManagerForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showLoginWindow(); break;
        case 1: _t->showRegistrationWindow(); break;
        case 2: _t->showDriverCompanionWindow(); break;
        case 3: _t->showCompanionWindow(); break;
        case 4: _t->showDriverWindow(); break;
        case 5: _t->showCarWindow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 6: _t->handleReturnToPrevious(); break;
        case 7: _t->showFinishWindow(); break;
        case 8: _t->showMainWindowFromFinish(); break;
        case 9: _t->onConnectionStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->showFeedbackWindow(); break;
        case 11: _t->showDriverCompanionWindowFromCompanion(); break;
        case 12: _t->showProfileWindow(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ManagerForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ManagerForm.data,
    qt_meta_data_ManagerForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ManagerForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManagerForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManagerForm.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ManagerForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
