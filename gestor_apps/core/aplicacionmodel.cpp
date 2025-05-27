#include "aplicacionmodel.h"

AplicacionModel::AplicacionModel(const aplicacion& app, QObject* parent) : QObject(parent), mAplicacion(app) {}

int AplicacionModel::id() const {
    return mAplicacion.id();
}

QString AplicacionModel::nombre() const {
    return mAplicacion.nombre();
}

QString AplicacionModel::descripcion() const {
    return mAplicacion.descripcion();
}

QString AplicacionModel::icono() const {
    return mAplicacion.icono();
}

int AplicacionModel::estado() const {
    return static_cast<int>(mAplicacion.estado());
}

void AplicacionModel::actualizarAplicacion(const aplicacion& app) {
    mAplicacion = app;
    emit aplicacionActualizada();
}

