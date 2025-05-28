#ifndef USUARIODAO_H
#define USUARIODAO_H

#include "usuario.h"
#include <QList>
class QSqlDatabase;

class usuariodao
{
public:
    usuariodao(QSqlDatabase& database);

    bool guardarUsuario(const usuario& usr);
    usuario obtenerUsuarioPorId(int id) const;
    usuario obtenerUsuarioPorNombre(const QString& nombre) const; // ¡Asegúrate de que TIENE 'const'!
    QList<usuario> obtenerTodosLosUsuarios();
    bool actualizarUsuario(const usuario& usr);
    bool eliminarUsuario(int id);

    bool verificarCredenciales(const QString& nombre, const QString& contrasena) const; // ¡Asegúrate de que TIENE 'const'!

private:
    QSqlDatabase& mdatabase;
};

#endif // USUARIODAO_H
