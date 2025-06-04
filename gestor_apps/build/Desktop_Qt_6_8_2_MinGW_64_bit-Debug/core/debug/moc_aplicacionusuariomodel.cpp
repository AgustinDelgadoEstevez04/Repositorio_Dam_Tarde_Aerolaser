/****************************************************************************
** Meta object code from reading C++ file 'aplicacionusuariomodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../core/aplicacionusuariomodel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aplicacionusuariomodel.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN22AplicacionUsuarioModelE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN22AplicacionUsuarioModelE = QtMocHelpers::stringData(
    "AplicacionUsuarioModel",
    "aplicacionUsuarioActualizada",
    "",
    "actualizarDesdeDAO",
    "usuarioId",
    "aplicacionId",
    "estadoInstalacion",
    "favorito",
    "estadoLicencia",
    "fechaLicencia"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN22AplicacionUsuarioModelE[] = {

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
       6, QMetaType::QString, 0x00015001, uint(0), 0,
       7, QMetaType::Bool, 0x00015001, uint(0), 0,
       8, QMetaType::QString, 0x00015001, uint(0), 0,
       9, QMetaType::QDate, 0x00015001, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject AplicacionUsuarioModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN22AplicacionUsuarioModelE.offsetsAndSizes,
    qt_meta_data_ZN22AplicacionUsuarioModelE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN22AplicacionUsuarioModelE_t,
        // property 'usuarioId'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'aplicacionId'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'estadoInstalacion'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'favorito'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'estadoLicencia'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'fechaLicencia'
        QtPrivate::TypeAndForceComplete<QDate, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AplicacionUsuarioModel, std::true_type>,
        // method 'aplicacionUsuarioActualizada'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'actualizarDesdeDAO'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AplicacionUsuarioModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AplicacionUsuarioModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->aplicacionUsuarioActualizada(); break;
        case 1: _t->actualizarDesdeDAO(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (AplicacionUsuarioModel::*)();
            if (_q_method_type _q_method = &AplicacionUsuarioModel::aplicacionUsuarioActualizada; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->usuarioId(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->aplicacionId(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->estadoInstalacion(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->favorito(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->estadoLicencia(); break;
        case 5: *reinterpret_cast< QDate*>(_v) = _t->fechaLicencia(); break;
        default: break;
        }
    }
}

const QMetaObject *AplicacionUsuarioModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AplicacionUsuarioModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN22AplicacionUsuarioModelE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AplicacionUsuarioModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void AplicacionUsuarioModel::aplicacionUsuarioActualizada()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
