#ifndef APLICACIONUSUARIODAO_H
#define APLICACIONUSUARIODAO_H

#include "aplicacionusuario.h"
#include <QList>
#include <QSqlDatabase>

class AplicacionUsuarioDAO {
public:
    AplicacionUsuarioDAO(QSqlDatabase& database);

    bool guardarRelacion(const AplicacionUsuario& aplicacionUsuario);
    AplicacionUsuario obtenerRelacionPorIds(int usuarioId, int aplicacionId);
    QList<AplicacionUsuario> obtenerRelacionesPorUsuario(int usuarioId);
    bool actualizarRelacion(const AplicacionUsuario& aplicacionUsuario);
    bool eliminarRelacion(int usuarioId, int aplicacionId);

private:
    QSqlDatabase& mDatabase;
};

#endif // APLICACIONUSUARIODAO_H

