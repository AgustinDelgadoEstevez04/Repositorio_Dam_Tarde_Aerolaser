#ifndef APLICACIONUSUARIO_H
#define APLICACIONUSUARIO_H

#include <QString>
#include <QDate>

class AplicacionUsuario {
public:
    enum EstadoInstalacion {
        NoInstalado = 0,
        Instalado = 1
    };

    enum EstadoLicencia {
        SinLicencia = 0,
        Activa = 1,
        Expirada = 2
    };

    AplicacionUsuario(int usuarioId, int aplicacionId, EstadoInstalacion estadoInstalacion,
                      bool favorito, EstadoLicencia estadoLicencia, const QDate& fechaLicencia);

    int getUsuarioId() const;
    int getAplicacionId() const;
    EstadoInstalacion getEstadoInstalacion() const;
    bool esFavorito() const;
    EstadoLicencia getEstadoLicencia() const;
    QDate getFechaLicencia() const;

    void setEstadoInstalacion(EstadoInstalacion estado);
    void setFavorito(bool fav);
    void setEstadoLicencia(EstadoLicencia estado);
    void setFechaLicencia(const QDate& fecha);
    static QString toString(EstadoInstalacion estado);
    static QString toString(EstadoLicencia estado);

private:
    int usuarioId;
    int aplicacionId;
    EstadoInstalacion estadoInstalacion;
    bool favorito;
    EstadoLicencia estadoLicencia;
    QDate fechaLicencia;
};

#endif // APLICACIONUSUARIO_H

