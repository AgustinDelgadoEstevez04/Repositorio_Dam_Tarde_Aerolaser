#include "aplicacion.h"

aplicacion::aplicacion(int id, const QString& nombre, const QString& descripcion, const QString& icono, Estado estado, Favorito favorito)
    : mid(id), mnombre(nombre), mdescripcion(descripcion), micono(icono){}

int aplicacion::id()const{
    return mid;
}

QString aplicacion::nombre() const{
    return mnombre;
}

QString aplicacion::descripcion()const {
    return mdescripcion;
}

QString aplicacion::icono() const{
    return micono;
}

