#ifndef APLICACIONDAO_H
#define APLICACIONDAO_H

#include "aplicacion.h"
#include <QList>
class QSqlDatabase;
class aplicaciondao
{
public:
    aplicaciondao(QSqlDatabase& database);

    bool guardarAplicacion(const aplicacion& app) const;
    aplicacion obtenerAplicacionPorId(int id) const;
    QList<aplicacion> obtenerTodasLasAplicaciones()const;
    QList<aplicacion> obtenerAplicacionesPorEstado(aplicacion::Estado estado);
    bool actualizarAplicacion(const aplicacion& app);
    bool eliminarAplicacion(int id);

private:
    QSqlDatabase& mdatabase;
};

#endif // APLICACIONDAO_H
