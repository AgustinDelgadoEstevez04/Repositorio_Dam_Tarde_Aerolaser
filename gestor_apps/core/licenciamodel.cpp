#include "licenciamodel.h"

LicenciaModel::LicenciaModel(const licencia& lic, QObject* parent) : QObject(parent), mLicencia(lic) {}

int LicenciaModel::id() const {
    return mLicencia.id();
}

int LicenciaModel::appId() const {
    return mLicencia.appId();
}

int LicenciaModel::userId() const {
    return mLicencia.userId();
}

int LicenciaModel::estado() const {
    return static_cast<int>(mLicencia.estado());
}

QDate LicenciaModel::fechaInicio() const {
    return mLicencia.fechaInicio();
}

QDate LicenciaModel::fechaFin() const {
    return mLicencia.fechaFin();
}

void LicenciaModel::actualizarLicencia(const licencia& lic) {
    mLicencia = lic;
    emit licenciaActualizada();
}

