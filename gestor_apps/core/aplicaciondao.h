#ifndef APLICACIONDAO_H
#define APLICACIONDAO_H
#include "aplicacion.h"
#include <QList>

class aplicaciondao
{
public:
    aplicaciondao();
    void guardaraplicacion(const aplicacion& app);
    aplicacion obteneraplicacionporid(int id);
    QList<aplicacion> obtenertodaslasaplicaciones();
    void actualizaraplicacion(const aplicacion& app);
    void eliminaraplicacion(int id);
};

#endif // APLICACIONDAO_H
