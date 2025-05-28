#ifndef APLICACION_H
#define APLICACION_H
#include <QString>
class aplicacion
{
public:
    enum Estado{Instalado=1, no_instalado=2};
    aplicacion(int id = -1, const QString& nombre = "",
               const QString& descripcion = "", const QString& icono = "",
               Estado estado = no_instalado);

    int id() const;
    QString nombre() const;
    QString descripcion()const;
    QString icono()const;
    Estado estado()const;
    QString estadoToString() const;

    void setEstado(Estado estado);

private:
    int mid;
    QString mnombre;
    QString mdescripcion;
    QString micono;
    Estado mestado;
};

#endif // APLICACION_H
