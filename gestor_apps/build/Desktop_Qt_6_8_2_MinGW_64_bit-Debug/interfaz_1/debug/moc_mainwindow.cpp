/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../interfaz_1/mainwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
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
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10MainWindowE = QtMocHelpers::stringData(
    "MainWindow",
    "filtrarAplicaciones",
    "",
    "mostrarDetallesAplicacion",
    "cargarLicencias",
    "appId",
    "cargaraplicaciones",
    "on_usuario_nombre_linkActivated",
    "link",
    "on_cerrar_sesion_clicked",
    "on_barra_busqueda_cursorPositionChanged",
    "arg1",
    "arg2",
    "on_favoritos_clicked",
    "on_descargados_clicked",
    "on_no_descargados_clicked",
    "on_lista_apps_indexesMoved",
    "QModelIndexList",
    "indexes",
    "on_lista_filtro_currentItemChanged",
    "QListWidgetItem*",
    "current",
    "previous",
    "on_favorito_app_clicked",
    "on_descargar_app_clicked",
    "on_no_descargados_2_clicked",
    "mostrarNombreUsuario",
    "on_barraProgreso_valueChanged",
    "value",
    "actualizarListaFiltro",
    "tipofiltro",
    "actualizarEstadoLicencias",
    "eventFilter",
    "obj",
    "QEvent*",
    "event",
    "cargarIconoUsuario",
    "on_btnCambiarIcono_clicked",
    "onIconoSeleccionado",
    "iconoNombre"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10MainWindowE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  152,    2, 0x08,    1 /* Private */,
       3,    0,  153,    2, 0x08,    2 /* Private */,
       4,    1,  154,    2, 0x08,    3 /* Private */,
       6,    0,  157,    2, 0x08,    5 /* Private */,
       7,    1,  158,    2, 0x08,    6 /* Private */,
       9,    0,  161,    2, 0x08,    8 /* Private */,
      10,    2,  162,    2, 0x08,    9 /* Private */,
      13,    0,  167,    2, 0x08,   12 /* Private */,
      14,    0,  168,    2, 0x08,   13 /* Private */,
      15,    0,  169,    2, 0x08,   14 /* Private */,
      16,    1,  170,    2, 0x08,   15 /* Private */,
      19,    2,  173,    2, 0x08,   17 /* Private */,
      23,    0,  178,    2, 0x08,   20 /* Private */,
      24,    0,  179,    2, 0x08,   21 /* Private */,
      25,    0,  180,    2, 0x08,   22 /* Private */,
      26,    0,  181,    2, 0x08,   23 /* Private */,
      27,    1,  182,    2, 0x08,   24 /* Private */,
      29,    1,  185,    2, 0x08,   26 /* Private */,
      31,    0,  188,    2, 0x08,   28 /* Private */,
      32,    2,  189,    2, 0x08,   29 /* Private */,
      36,    0,  194,    2, 0x08,   32 /* Private */,
      37,    0,  195,    2, 0x08,   33 /* Private */,
      38,    1,  196,    2, 0x08,   34 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 20,   21,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 34,   33,   35,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   39,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ZN10MainWindowE.offsetsAndSizes,
    qt_meta_data_ZN10MainWindowE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10MainWindowE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'filtrarAplicaciones'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mostrarDetallesAplicacion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cargarLicencias'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'cargaraplicaciones'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_usuario_nombre_linkActivated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_cerrar_sesion_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_barra_busqueda_cursorPositionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_favoritos_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_descargados_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_no_descargados_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_lista_apps_indexesMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndexList &, std::false_type>,
        // method 'on_lista_filtro_currentItemChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_favorito_app_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_descargar_app_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_no_descargados_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mostrarNombreUsuario'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_barraProgreso_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'actualizarListaFiltro'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'actualizarEstadoLicencias'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'eventFilter'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QObject *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QEvent *, std::false_type>,
        // method 'cargarIconoUsuario'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnCambiarIcono_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onIconoSeleccionado'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->filtrarAplicaciones(); break;
        case 1: _t->mostrarDetallesAplicacion(); break;
        case 2: _t->cargarLicencias((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->cargaraplicaciones(); break;
        case 4: _t->on_usuario_nombre_linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->on_cerrar_sesion_clicked(); break;
        case 6: _t->on_barra_busqueda_cursorPositionChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 7: _t->on_favoritos_clicked(); break;
        case 8: _t->on_descargados_clicked(); break;
        case 9: _t->on_no_descargados_clicked(); break;
        case 10: _t->on_lista_apps_indexesMoved((*reinterpret_cast< std::add_pointer_t<QModelIndexList>>(_a[1]))); break;
        case 11: _t->on_lista_filtro_currentItemChanged((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[2]))); break;
        case 12: _t->on_favorito_app_clicked(); break;
        case 13: _t->on_descargar_app_clicked(); break;
        case 14: _t->on_no_descargados_2_clicked(); break;
        case 15: _t->mostrarNombreUsuario(); break;
        case 16: _t->on_barraProgreso_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->actualizarListaFiltro((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->actualizarEstadoLicencias(); break;
        case 19: { bool _r = _t->eventFilter((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QEvent*>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 20: _t->cargarIconoUsuario(); break;
        case 21: _t->on_btnCambiarIcono_clicked(); break;
        case 22: _t->onIconoSeleccionado((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QModelIndexList >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10MainWindowE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_WARNING_POP
