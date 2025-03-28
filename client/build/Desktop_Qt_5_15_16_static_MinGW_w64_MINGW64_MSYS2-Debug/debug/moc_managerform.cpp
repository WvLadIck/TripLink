/****************************************************************************
** Meta object code from reading C++ file 'managerform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.16)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../managerform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'managerform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.16. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ManagerForm_t {
    QByteArrayData data[10];
    char stringdata0[169];
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
QT_MOC_LITERAL(8, 129, 22), // "handleReturnToPrevious"
QT_MOC_LITERAL(9, 152, 16) // "showFinishWindow"

    },
    "ManagerForm\0showLoginWindow\0\0"
    "showRegistrationWindow\0showDriverCompanionWindow\0"
    "showCompanionWindow\0showDriverWindow\0"
    "showCarWindow\0handleReturnToPrevious\0"
    "showFinishWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManagerForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 5: _t->showCarWindow(); break;
        case 6: _t->handleReturnToPrevious(); break;
        case 7: _t->showFinishWindow(); break;
        default: ;
        }
    }
    (void)_a;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
