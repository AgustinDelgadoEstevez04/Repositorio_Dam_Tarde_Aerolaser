#ifndef APLICACIONUSUARIO_H
#define APLICACIONUSUARIO_H

#include <QString>
#include <QDate>

class AplicacionUsuario {
public:
    AplicacionUsuario(int usuarioId, int aplicacionId, const QString& estadoInstalacion,
                      bool favorito, const QString& estadoLicencia, const QDate& fechaLicencia);

    // Getters
    int getUsuarioId() const;
    int getAplicacionId() const;
    QString getEstadoInstalacion() const;
    bool esFavorito() const;
    QString getEstadoLicencia() const;
    QDate getFechaLicencia() const;

    // Setters
    void setEstadoInstalacion(const QString& estado);
    void setFavorito(bool favorito);
    void setEstadoLicencia(const QString& estado);
    void setFechaLicencia(const QDate& fecha);

private:
    int usuarioId;
    int aplicacionId;
    QString estadoInstalacion; // 'instalado' | 'no_instalado'
    bool favorito;
    QString estadoLicencia; // 'vigente' | 'caducada' | 'proxima_a_caducar'
    QDate fechaLicencia; // Fecha de la licencia
};

#endif // APLICACIONUSUARIO_H

