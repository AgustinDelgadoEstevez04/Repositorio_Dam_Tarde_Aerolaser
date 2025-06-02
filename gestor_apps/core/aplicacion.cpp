#include "aplicacion.h"

aplicacion::aplicacion(int id, const QString& nombre, const QString& descripcion, const QString& icono, Estado estado, Favorito favorito)
    : mid(id), mnombre(nombre), mdescripcion(descripcion), micono(icono), mestado(estado), mfavorito(favorito) {}

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

aplicacion::Favorito aplicacion::favorito()const{
    return mfavorito;
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

QString aplicacion::favoritoToString() const{
    switch (mfavorito) {
    case EsFavorito:
        return "favorito";
        break;
    case NoFavorito:
        return "no favorito";
        break;
    default:
        "desconocido";
        break;
    }
}

void aplicacion::setEstado(Estado estado){
    mestado=estado;
}

void aplicacion::setFavorito(Favorito favorito){
    mfavorito=favorito;
}
