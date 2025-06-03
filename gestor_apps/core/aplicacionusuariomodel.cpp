#include "AplicacionUsuarioModel.h"

// Constructor
AplicacionUsuarioModel::AplicacionUsuarioModel(const AplicacionUsuario& appUsuario, QObject* parent)
    : QObject(parent), mAplicacionUsuario(appUsuario) {}

// Getters
int AplicacionUsuarioModel::usuarioId() const {
    return mAplicacionUsuario.getUsuarioId();
}

int AplicacionUsuarioModel::aplicacionId() const {
    return mAplicacionUsuario.getAplicacionId();
}

QString AplicacionUsuarioModel::estadoInstalacion() const {
    return AplicacionUsuario::toString(mAplicacionUsuario.getEstadoInstalacion()); // ✅ Conversión correcta
}

QString AplicacionUsuarioModel::estadoLicencia() const {
    return AplicacionUsuario::toString(mAplicacionUsuario.getEstadoLicencia()); // ✅ Conversión correcta
}


bool AplicacionUsuarioModel::favorito() const {
    return mAplicacionUsuario.esFavorito();
}

QDate AplicacionUsuarioModel::fechaLicencia() const {
    return mAplicacionUsuario.getFechaLicencia();
}

void AplicacionUsuarioModel::actualizarDesdeDAO() {

    emit aplicacionUsuarioActualizada();
}



