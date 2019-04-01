/****************************************************************************
** Meta object code from reading C++ file 'mandalaman.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GraphicInterfaceMandalaProject-master/Mandalaman/mandalaman.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mandalaman.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Mandalaman[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      25,   11,   11,   11, 0x08,
      40,   11,   11,   11, 0x08,
      60,   11,   11,   11, 0x08,
      75,   11,   11,   11, 0x08,
      98,   87,   11,   11, 0x08,
     128,   11,  121,   11, 0x08,
     142,   11,   11,   11, 0x08,
     153,   11,   11,   11, 0x08,
     161,   11,   11,   11, 0x08,
     187,   11,   11,   11, 0x08,
     214,   11,   11,   11, 0x08,
     243,   11,   11,   11, 0x08,
     265,   11,   11,   11, 0x08,
     285,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Mandalaman[] = {
    "Mandalaman\0\0mirrorFnct()\0rainbowColor()\0"
    "resolutionFnct(int)\0sliceFnct(int)\0"
    "clearFnct()\0fileFormat\0saveToFile(QByteArray)\0"
    "QColor\0changeColor()\0closeApp()\0about()\0"
    "on_actionQuit_triggered()\0"
    "on_actionAbout_triggered()\0"
    "on_actionSave_as_triggered()\0"
    "on_colorBtn_clicked()\0changePenWidth(int)\0"
    "on_actionOpen_triggered()\0"
};

void Mandalaman::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Mandalaman *_t = static_cast<Mandalaman *>(_o);
        switch (_id) {
        case 0: _t->mirrorFnct(); break;
        case 1: _t->rainbowColor(); break;
        case 2: _t->resolutionFnct((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sliceFnct((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->clearFnct(); break;
        case 5: _t->saveToFile((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 6: { QColor _r = _t->changeColor();
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 7: _t->closeApp(); break;
        case 8: _t->about(); break;
        case 9: _t->on_actionQuit_triggered(); break;
        case 10: _t->on_actionAbout_triggered(); break;
        case 11: _t->on_actionSave_as_triggered(); break;
        case 12: _t->on_colorBtn_clicked(); break;
        case 13: _t->changePenWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_actionOpen_triggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Mandalaman::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Mandalaman::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Mandalaman,
      qt_meta_data_Mandalaman, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Mandalaman::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Mandalaman::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Mandalaman::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Mandalaman))
        return static_cast<void*>(const_cast< Mandalaman*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Mandalaman::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
