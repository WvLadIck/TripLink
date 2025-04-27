/****************************************************************************
** Meta object code from reading C++ file 'profile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../profile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'profile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Profile_t {
    QByteArrayData data[10];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Profile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Profile_t qt_meta_stringdata_Profile = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Profile"
QT_MOC_LITERAL(1, 8, 8), // "finished"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 25), // "goToDriverCompanionWindow"
QT_MOC_LITERAL(4, 44, 19), // "goToBlacklistWindow"
QT_MOC_LITERAL(5, 64, 23), // "on_toolButton_0_clicked"
QT_MOC_LITERAL(6, 88, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 110, 15), // "ProfileResponse"
QT_MOC_LITERAL(8, 126, 7), // "message"
QT_MOC_LITERAL(9, 134, 23) // "on_pushButton_2_clicked"

    },
    "Profile\0finished\0\0goToDriverCompanionWindow\0"
    "goToBlacklistWindow\0on_toolButton_0_clicked\0"
    "on_pushButton_clicked\0ProfileResponse\0"
    "message\0on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Profile[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

       0        // eod
};

void Profile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Profile *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->goToDriverCompanionWindow(); break;
        case 2: _t->goToBlacklistWindow(); break;
        case 3: _t->on_toolButton_0_clicked(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->ProfileResponse((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Profile::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Profile::finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Profile::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Profile::goToDriverCompanionWindow)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Profile::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Profile::goToBlacklistWindow)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Profile::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Profile.data,
    qt_meta_data_Profile,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Profile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Profile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Profile.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Profile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Profile::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Profile::goToDriverCompanionWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Profile::goToBlacklistWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
