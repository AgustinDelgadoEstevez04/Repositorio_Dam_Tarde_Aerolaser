#ifndef LICENCIADAO_H
#define LICENCIADAO_H

#include "licencia.h"
#include <QList>
class QSqlDatabase;

class licenciadao
{
public:
    licenciadao(QSqlDatabase& database);

    bool guardarLicencia(const licencia& lic);
    licencia obtenerLicenciaPorId(int id) const;
    QList<licencia> obtenerTodasLasLicencias();
    QList<licencia> obtenerLicenciasPorEstado(licencia::Estado estado);
    bool actualizarLicencia(const licencia& lic);
    bool eliminarLicencia(int id);

    bool estaActiva(int id);
    bool estaCaducada(int id);
    bool estaProximaACaducar(int id);

private:
    QSqlDatabase& mdatabase;
};

#endif // LICENCIADAO_H

