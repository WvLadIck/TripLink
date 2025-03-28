/****************************************************************************
** Meta object code from reading C++ file 'networkclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../networkclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networkclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NetworkClient_t {
    QByteArrayData data[18];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetworkClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetworkClient_t qt_meta_stringdata_NetworkClient = {
    {
QT_MOC_LITERAL(0, 0, 13), // "NetworkClient"
QT_MOC_LITERAL(1, 14, 23), // "connectionStatusChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 9), // "connected"
QT_MOC_LITERAL(4, 49, 5), // "error"
QT_MOC_LITERAL(5, 55, 7), // "message"
QT_MOC_LITERAL(6, 63, 11), // "authSuccess"
QT_MOC_LITERAL(7, 75, 10), // "authFailed"
QT_MOC_LITERAL(8, 86, 10), // "regSuccess"
QT_MOC_LITERAL(9, 97, 9), // "regFailed"
QT_MOC_LITERAL(10, 107, 9), // "readyRead"
QT_MOC_LITERAL(11, 117, 16), // "bookTripResponse"
QT_MOC_LITERAL(12, 134, 8), // "response"
QT_MOC_LITERAL(13, 143, 17), // "connectedToServer"
QT_MOC_LITERAL(14, 161, 22), // "disconnectedFromServer"
QT_MOC_LITERAL(15, 184, 11), // "socketError"
QT_MOC_LITERAL(16, 196, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(17, 225, 10) // "_readyRead"

    },
    "NetworkClient\0connectionStatusChanged\0"
    "\0connected\0error\0message\0authSuccess\0"
    "authFailed\0regSuccess\0regFailed\0"
    "readyRead\0bookTripResponse\0response\0"
    "connectedToServer\0disconnectedFromServer\0"
    "socketError\0QAbstractSocket::SocketError\0"
    "_readyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetworkClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       6,    0,   80,    2, 0x06 /* Public */,
       7,    0,   81,    2, 0x06 /* Public */,
       8,    0,   82,    2, 0x06 /* Public */,
       9,    0,   83,    2, 0x06 /* Public */,
      10,    1,   84,    2, 0x06 /* Public */,
      11,    1,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   90,    2, 0x0a /* Public */,
      14,    0,   91,    2, 0x0a /* Public */,
      15,    1,   92,    2, 0x0a /* Public */,
      17,    0,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   15,
    QMetaType::Void,

       0        // eod
};

void NetworkClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NetworkClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connectionStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->authSuccess(); break;
        case 3: _t->authFailed(); break;
        case 4: _t->regSuccess(); break;
        case 5: _t->regFailed(); break;
        case 6: _t->readyRead((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->bookTripResponse((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->connectedToServer(); break;
        case 9: _t->disconnectedFromServer(); break;
        case 10: _t->socketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 11: _t->_readyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NetworkClient::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkClient::connectionStatusChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NetworkClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkClient::error)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NetworkClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkClient::authSuccess)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NetworkClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkClient::authFailed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (NetworkClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkClient::regSuccess)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (NetworkClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkClient::regFailed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (NetworkClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkClient::readyRead)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (NetworkClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkClient::bookTripResponse)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NetworkClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_NetworkClient.data,
    qt_meta_data_NetworkClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NetworkClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NetworkClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void NetworkClient::connectionStatusChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetworkClient::error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NetworkClient::authSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void NetworkClient::authFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void NetworkClient::regSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void NetworkClient::regFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void NetworkClient::readyRead(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void NetworkClient::bookTripResponse(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
