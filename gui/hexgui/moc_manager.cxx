/****************************************************************************
** Meta object code from reading C++ file 'manager.h'
**
** Created: Thu Feb 25 18:42:47 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "manager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_manager[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      30,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,    8,    8,    8, 0x0a,
      53,    8,    8,    8, 0x0a,
      63,    8,    8,    8, 0x0a,
      76,    8,    8,    8, 0x0a,
      87,    8,    8,    8, 0x0a,
     102,    8,    8,    8, 0x0a,
     117,    8,    8,    8, 0x0a,
     133,    8,    8,    8, 0x0a,
     149,    8,    8,    8, 0x0a,
     164,    8,    8,    8, 0x0a,
     182,    8,    8,    8, 0x0a,
     201,    8,    8,    8, 0x0a,
     215,    8,    8,    8, 0x0a,
     228,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_manager[] = {
    "manager\0\0stateChanged(Player)\0"
    "movePlayed()\0newGame()\0genMove()\0"
    "searchMove()\0playMove()\0autoReply(int)\0"
    "showTreeGame()\0closeTreeGame()\0"
    "changeCurrent()\0showTreeMcts()\0"
    "setPlayouts(uint)\0setTreeDepth(uint)\0"
    "clearLabels()\0showLabels()\0clearMarkers()\0"
};

const QMetaObject manager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_manager,
      qt_meta_data_manager, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &manager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *manager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *manager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_manager))
        return static_cast<void*>(const_cast< manager*>(this));
    return QObject::qt_metacast(_clname);
}

int manager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: stateChanged((*reinterpret_cast< const Player(*)>(_a[1]))); break;
        case 1: movePlayed(); break;
        case 2: newGame(); break;
        case 3: genMove(); break;
        case 4: searchMove(); break;
        case 5: playMove(); break;
        case 6: autoReply((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: showTreeGame(); break;
        case 8: closeTreeGame(); break;
        case 9: changeCurrent(); break;
        case 10: showTreeMcts(); break;
        case 11: setPlayouts((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 12: setTreeDepth((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 13: clearLabels(); break;
        case 14: showLabels(); break;
        case 15: clearMarkers(); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void manager::stateChanged(const Player & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void manager::movePlayed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
