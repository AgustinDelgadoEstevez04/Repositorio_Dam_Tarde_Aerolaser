#ifndef APLICACIONDAO_H
#define APLICACIONDAO_H

#include "aplicacion.h"
#include <QList>
class QSqlDatabase;
class aplicaciondao
{
public:
    aplicaciondao(QSqlDatabase& database);

    bool guardarAplicacion(const aplicacion& app);
    aplicacion obtenerAplicacionPorId(int id) const;
    QList<aplicacion> obtenerTodasLasAplicaciones();
    QList<aplicacion> obtenerAplicacionesPorEstado(aplicacion::Estado estado);
    bool actualizarAplicacion(const aplicacion& app);
    bool eliminarAplicacion(int id);

private:
    QSqlDatabase& mdatabase;
};

#endif // APLICACIONDAO_H
