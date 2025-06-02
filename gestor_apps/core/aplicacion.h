#ifndef APLICACION_H
#define APLICACION_H
#include <QString>
class aplicacion
{
public:
    enum Estado{Instalado=1, no_instalado=2};
    enum Favorito { EsFavorito=3, NoFavorito=4 };

    aplicacion(int id = -1, const QString& nombre = "",
               const QString& descripcion = "", const QString& icono = "",
               Estado estado = no_instalado, Favorito favorito = NoFavorito);

    int id() const;
    QString nombre() const;
    QString descripcion() const;
    QString icono() const;
    Estado estado() const;
    Favorito favorito() const;

    QString estadoToString() const;
    QString favoritoToString() const;

    void setEstado(Estado estado);
    void setFavorito(Favorito favorito);

private:
    int mid;
    QString mnombre;
    QString mdescripcion;
    QString micono;
    Estado mestado;
    Favorito mfavorito;
};

#endif // APLICACION_H
