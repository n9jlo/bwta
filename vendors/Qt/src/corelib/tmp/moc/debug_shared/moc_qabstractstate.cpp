/****************************************************************************
** Meta object code from reading C++ file 'qabstractstate.h'
**
** Created: Wed Jun 2 12:27:22 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../statemachine/qabstractstate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qabstractstate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QAbstractState[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      26,   15,   15,   15, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_QAbstractState[] = {
    "QAbstractState\0\0entered()\0exited()\0"
};

const QMetaObject QAbstractState::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QAbstractState,
      qt_meta_data_QAbstractState, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QAbstractState::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QAbstractState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QAbstractState::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QAbstractState))
        return static_cast<void*>(const_cast< QAbstractState*>(this));
    return QObject::qt_metacast(_clname);
}

int QAbstractState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: entered(); break;
        case 1: exited(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QAbstractState::entered()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QAbstractState::exited()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
