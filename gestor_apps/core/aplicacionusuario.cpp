#include "aplicacionusuario.h"

// Constructor
AplicacionUsuario::AplicacionUsuario(int usuarioId, int aplicacionId, EstadoInstalacion estadoInstalacion,
                                     bool favorito, EstadoLicencia estadoLicencia, const QDate& fechaLicencia)
    : usuarioId(usuarioId), aplicacionId(aplicacionId), estadoInstalacion(estadoInstalacion),
    favorito(favorito), estadoLicencia(estadoLicencia), fechaLicencia(fechaLicencia) {}

// Getters
int AplicacionUsuario::getUsuarioId() const { return usuarioId; }
int AplicacionUsuario::getAplicacionId() const { return aplicacionId; }
AplicacionUsuario::EstadoInstalacion AplicacionUsuario::getEstadoInstalacion() const { return estadoInstalacion; }
bool AplicacionUsuario::esFavorito() const { return favorito; }
AplicacionUsuario::EstadoLicencia AplicacionUsuario::getEstadoLicencia() const { return estadoLicencia; }
QDate AplicacionUsuario::getFechaLicencia() const { return fechaLicencia; }

// Setters
void AplicacionUsuario::setEstadoInstalacion(EstadoInstalacion estado) { estadoInstalacion = estado; }
void AplicacionUsuario::setFavorito(bool fav) { favorito = fav; }
void AplicacionUsuario::setEstadoLicencia(EstadoLicencia estado) { estadoLicencia = estado; }
void AplicacionUsuario::setFechaLicencia(const QDate& fecha) { fechaLicencia = fecha; }

QString AplicacionUsuario::toString(EstadoInstalacion estado) {
    switch (estado) {
    case NoInstalado: return "No Instalado";
    case Instalado: return "Instalado";
    default: return "Desconocido";
    }
}

QString AplicacionUsuario::toString(EstadoLicencia estado) {
    switch (estado) {
    case SinLicencia: return "Sin Licencia";
    case Activa: return "Activa";
    case Expirada: return "Expirada";
    default: return "Desconocido";
    }
}





