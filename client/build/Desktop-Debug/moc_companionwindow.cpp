/****************************************************************************
** Meta object code from reading C++ file 'companionwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../companionwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'companionwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CompanionWindow_t {
    QByteArrayData data[16];
    char stringdata0[272];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CompanionWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CompanionWindow_t qt_meta_stringdata_CompanionWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CompanionWindow"
QT_MOC_LITERAL(1, 16, 22), // "returnToPreviousWindow"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 13), // "goToCarWindow"
QT_MOC_LITERAL(4, 54, 6), // "tripId"
QT_MOC_LITERAL(5, 61, 8), // "tripInfo"
QT_MOC_LITERAL(6, 70, 12), // "tripNotFound"
QT_MOC_LITERAL(7, 83, 25), // "goToDriverCompanionWindow"
QT_MOC_LITERAL(8, 109, 27), // "on_toolButton_then0_clicked"
QT_MOC_LITERAL(9, 137, 27), // "on_toolButton_then1_clicked"
QT_MOC_LITERAL(10, 165, 22), // "handleFindTripResponse"
QT_MOC_LITERAL(11, 188, 7), // "message"
QT_MOC_LITERAL(12, 196, 22), // "handleBookTripResponse"
QT_MOC_LITERAL(13, 219, 30), // "on_listWidget_info_itemClicked"
QT_MOC_LITERAL(14, 250, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(15, 267, 4) // "item"

    },
    "CompanionWindow\0returnToPreviousWindow\0"
    "\0goToCarWindow\0tripId\0tripInfo\0"
    "tripNotFound\0goToDriverCompanionWindow\0"
    "on_toolButton_then0_clicked\0"
    "on_toolButton_then1_clicked\0"
    "handleFindTripResponse\0message\0"
    "handleBookTripResponse\0"
    "on_listWidget_info_itemClicked\0"
    "QListWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CompanionWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    2,   60,    2, 0x06 /* Public */,
       6,    0,   65,    2, 0x06 /* Public */,
       7,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   67,    2, 0x0a /* Public */,
       9,    0,   68,    2, 0x0a /* Public */,
      10,    1,   69,    2, 0x0a /* Public */,
      12,    1,   72,    2, 0x0a /* Public */,
      13,    1,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QVariantMap,    4,    5,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void CompanionWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CompanionWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->returnToPreviousWindow(); break;
        case 1: _t->goToCarWindow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 2: _t->tripNotFound(); break;
        case 3: _t->goToDriverCompanionWindow(); break;
        case 4: _t->on_toolButton_then0_clicked(); break;
        case 5: _t->on_toolButton_then1_clicked(); break;
        case 6: _t->handleFindTripResponse((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->handleBookTripResponse((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_listWidget_info_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CompanionWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CompanionWindow::returnToPreviousWindow)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CompanionWindow::*)(int , QVariantMap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CompanionWindow::goToCarWindow)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CompanionWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CompanionWindow::tripNotFound)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CompanionWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CompanionWindow::goToDriverCompanionWindow)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CompanionWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CompanionWindow.data,
    qt_meta_data_CompanionWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CompanionWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CompanionWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CompanionWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CompanionWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CompanionWindow::returnToPreviousWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CompanionWindow::goToCarWindow(int _t1, QVariantMap _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CompanionWindow::tripNotFound()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CompanionWindow::goToDriverCompanionWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
