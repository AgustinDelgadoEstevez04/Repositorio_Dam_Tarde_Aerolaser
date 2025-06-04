#ifndef APLICACIONUSUARIOMODEL_H
#define APLICACIONUSUARIOMODEL_H

#include <QObject>
#include <QDate>
#include "aplicacionusuario.h"

class AplicacionUsuarioModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int usuarioId READ usuarioId NOTIFY aplicacionUsuarioActualizada)
    Q_PROPERTY(int aplicacionId READ aplicacionId NOTIFY aplicacionUsuarioActualizada)
    Q_PROPERTY(QString estadoInstalacion READ estadoInstalacion NOTIFY aplicacionUsuarioActualizada)
    Q_PROPERTY(bool favorito READ favorito NOTIFY aplicacionUsuarioActualizada)
    Q_PROPERTY(QString estadoLicencia READ estadoLicencia NOTIFY aplicacionUsuarioActualizada)
    Q_PROPERTY(QDate fechaLicencia READ fechaLicencia NOTIFY aplicacionUsuarioActualizada)

public:
    explicit AplicacionUsuarioModel(const AplicacionUsuario& appUsuario, QObject* parent = nullptr);

    int usuarioId() const;
    int aplicacionId() const;
    QString estadoInstalacion() const;
    bool favorito() const;
    QString estadoLicencia() const;
    QDate fechaLicencia() const;

signals:
    void aplicacionUsuarioActualizada();

public slots:
    void actualizarDesdeDAO();

private:
    AplicacionUsuario mAplicacionUsuario;
};

#endif // APLICACIONUSUARIOMODEL_H

