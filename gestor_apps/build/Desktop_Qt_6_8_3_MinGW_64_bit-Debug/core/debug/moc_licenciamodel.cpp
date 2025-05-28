/****************************************************************************
** Meta object code from reading C++ file 'licenciamodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../core/licenciamodel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'licenciamodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN13LicenciaModelE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN13LicenciaModelE = QtMocHelpers::stringData(
    "LicenciaModel",
    "licenciaActualizada",
    "",
    "actualizarDesdeDAO",
    "id",
    "appId",
    "userId",
    "estado",
    "fechaInicio",
    "fechaFin"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN13LicenciaModelE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       6,   28, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   27,    2, 0x0a,    8 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags, notifyId, revision
       4, QMetaType::Int, 0x00015001, uint(0), 0,
       5, QMetaType::Int, 0x00015001, uint(0), 0,
       6, QMetaType::Int, 0x00015001, uint(0), 0,
       7, QMetaType::Int, 0x00015001, uint(0), 0,
       8, QMetaType::QDate, 0x00015001, uint(0), 0,
       9, QMetaType::QDate, 0x00015001, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject LicenciaModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN13LicenciaModelE.offsetsAndSizes,
    qt_meta_data_ZN13LicenciaModelE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN13LicenciaModelE_t,
        // property 'id'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'appId'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'userId'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'estado'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'fechaInicio'
        QtPrivate::TypeAndForceComplete<QDate, std::true_type>,
        // property 'fechaFin'
        QtPrivate::TypeAndForceComplete<QDate, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<LicenciaModel, std::true_type>,
        // method 'licenciaActualizada'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'actualizarDesdeDAO'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void LicenciaModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<LicenciaModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->licenciaActualizada(); break;
        case 1: _t->actualizarDesdeDAO(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (LicenciaModel::*)();
            if (_q_method_type _q_method = &LicenciaModel::licenciaActualizada; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->id(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->appId(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->userId(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->estado(); break;
        case 4: *reinterpret_cast< QDate*>(_v) = _t->fechaInicio(); break;
        case 5: *reinterpret_cast< QDate*>(_v) = _t->fechaFin(); break;
        default: break;
        }
    }
}

const QMetaObject *LicenciaModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LicenciaModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN13LicenciaModelE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LicenciaModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void LicenciaModel::licenciaActualizada()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
