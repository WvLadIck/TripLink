/****************************************************************************
** Meta object code from reading C++ file 'drivercompanionwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../drivercompanionwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drivercompanionwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DriverCompanionWindow_t {
    QByteArrayData data[10];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DriverCompanionWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DriverCompanionWindow_t qt_meta_stringdata_DriverCompanionWindow = {
    {
QT_MOC_LITERAL(0, 0, 21), // "DriverCompanionWindow"
QT_MOC_LITERAL(1, 22, 22), // "returnToPreviousWindow"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 19), // "goToCompanionWindow"
QT_MOC_LITERAL(4, 66, 16), // "goToDriverWindow"
QT_MOC_LITERAL(5, 83, 18), // "goToFeedbackWindow"
QT_MOC_LITERAL(6, 102, 27), // "on_toolButton_then0_clicked"
QT_MOC_LITERAL(7, 130, 31), // "on_pushButton_companion_clicked"
QT_MOC_LITERAL(8, 162, 28), // "on_pushButton_driver_clicked"
QT_MOC_LITERAL(9, 191, 30) // "on_pushButton_feetback_clicked"

    },
    "DriverCompanionWindow\0returnToPreviousWindow\0"
    "\0goToCompanionWindow\0goToDriverWindow\0"
    "goToFeedbackWindow\0on_toolButton_then0_clicked\0"
    "on_pushButton_companion_clicked\0"
    "on_pushButton_driver_clicked\0"
    "on_pushButton_feetback_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DriverCompanionWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DriverCompanionWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DriverCompanionWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->returnToPreviousWindow(); break;
        case 1: _t->goToCompanionWindow(); break;
        case 2: _t->goToDriverWindow(); break;
        case 3: _t->goToFeedbackWindow(); break;
        case 4: _t->on_toolButton_then0_clicked(); break;
        case 5: _t->on_pushButton_companion_clicked(); break;
        case 6: _t->on_pushButton_driver_clicked(); break;
        case 7: _t->on_pushButton_feetback_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DriverCompanionWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DriverCompanionWindow::returnToPreviousWindow)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DriverCompanionWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DriverCompanionWindow::goToCompanionWindow)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DriverCompanionWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DriverCompanionWindow::goToDriverWindow)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DriverCompanionWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DriverCompanionWindow::goToFeedbackWindow)) {
                *result = 3;
                return;
            }
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject DriverCompanionWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DriverCompanionWindow.data,
    qt_meta_data_DriverCompanionWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DriverCompanionWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DriverCompanionWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DriverCompanionWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DriverCompanionWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void DriverCompanionWindow::returnToPreviousWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DriverCompanionWindow::goToCompanionWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DriverCompanionWindow::goToDriverWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DriverCompanionWindow::goToFeedbackWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
