#include "aplicacion.h"

aplicacion::aplicacion(int id, const QString& nombre, const QString& descripcion, const QString& icono, Estado estado)
    : mid(id), mnombre(nombre), mdescripcion(descripcion), micono(icono), mestado(estado) {}

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

aplicacion::Estado aplicacion::estado()const{
    return mestado;
}

QString aplicacion::estadoToString() const{
    switch (mestado) {
    case Instalado:
        return "instalado";
        break;
    case no_instalado:
        return "no instalado";
        break;
    default:
        "desconocido";
        break;
    }
}

void aplicacion::setEstado(Estado estado){
    mestado=estado;
}
