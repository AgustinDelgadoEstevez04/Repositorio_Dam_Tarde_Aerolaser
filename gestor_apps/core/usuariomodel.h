#ifndef USUARIOMODEL_H
#define USUARIOMODEL_H

#include <QObject>
#include "usuario.h"

class UsuarioModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id NOTIFY usuarioActualizado)
    Q_PROPERTY(QString nombre READ nombre NOTIFY usuarioActualizado)
    Q_PROPERTY(QString contraseña READ contraseña NOTIFY usuarioActualizado)

public:
    explicit UsuarioModel(const usuario& usr, QObject* parent = nullptr);

    int id() const;
    QString nombre() const;
    QString contraseña() const;

signals:
    void usuarioActualizado();

public slots:
    void actualizarUsuario(const usuario& usr);

private:
    usuario mUsuario;
};

#endif // USUARIOMODEL_H

