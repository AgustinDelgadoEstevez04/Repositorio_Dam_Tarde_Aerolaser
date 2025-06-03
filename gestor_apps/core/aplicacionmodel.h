#ifndef APLICACIONMODEL_H
#define APLICACIONMODEL_H

#include <QObject>
#include "aplicacion.h"
class AplicacionModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id NOTIFY aplicacionActualizada)
    Q_PROPERTY(QString nombre READ nombre NOTIFY aplicacionActualizada)
    Q_PROPERTY(QString descripcion READ descripcion NOTIFY aplicacionActualizada)
    Q_PROPERTY(QString icono READ icono NOTIFY aplicacionActualizada)

public:
    explicit AplicacionModel(const aplicacion& app, QObject* parent = nullptr);

    int id() const;
    QString nombre() const;
    QString descripcion() const;
    QString icono() const;

signals:
    void aplicacionActualizada();

public slots:
    void actualizarDesdeDAO();



private:
    aplicacion mAplicacion;
};

#endif // APLICACIONMODEL_H

