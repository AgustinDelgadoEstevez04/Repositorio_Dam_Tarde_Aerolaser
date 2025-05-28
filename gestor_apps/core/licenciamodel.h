#ifndef LICENCIAMODEL_H
#define LICENCIAMODEL_H

#include <QObject>
#include "licencia.h"
class LicenciaModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id NOTIFY licenciaActualizada)
    Q_PROPERTY(int appId READ appId NOTIFY licenciaActualizada)
    Q_PROPERTY(int userId READ userId NOTIFY licenciaActualizada)
    Q_PROPERTY(int estado READ estado NOTIFY licenciaActualizada)
    Q_PROPERTY(QDate fechaInicio READ fechaInicio NOTIFY licenciaActualizada)
    Q_PROPERTY(QDate fechaFin READ fechaFin NOTIFY licenciaActualizada)

public:
    explicit LicenciaModel(const licencia& lic, QObject* parent = nullptr);

    int id() const;
    int appId() const;
    int userId() const;
    int estado() const;
    QDate fechaInicio() const;
    QDate fechaFin() const;

signals:
    void licenciaActualizada();

public slots:
    void actualizarDesdeDAO();
;

private:
    licencia mLicencia;
};

#endif // LICENCIAMODEL_H
