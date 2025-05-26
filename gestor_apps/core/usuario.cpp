#include "usuario.h"

usuario::usuario(const QString &nombre, const QString &contraseña, int id)
    : id(id) {
    setnombre(nombre);
    setcontraseña(contraseña);
}

QString usuario::getnombre() const {
    return nombre;
}

bool usuario::setnombre(const QString &nuevonombre) {
    if (nuevonombre.length() >= 6 && nuevonombre.length() <= 30) {
        nombre = nuevonombre;
        return true;
    } else {
        qDebug() << "Error: el nombre debe tener entre 6 y 30 caracteres.";
        return false;
    }
}

bool usuario::verificarcredenciales(const QString &nombreIngresado, const QString &contraseñaIngresada) const {
    return (nombreIngresado == nombre && contraseñaIngresada == contraseña);
}

bool usuario::setcontraseña(const QString &nuevacontraseña) {
    if (nuevacontraseña.length() >= 6 && nuevacontraseña.length() <= 30) {
        contraseña = nuevacontraseña;
        return true;
    } else {
        qDebug() << "Error: la contraseña debe tener entre 6 y 30 caracteres.";
        return false;
    }
}

int usuario::getid() const {
    return id;
}
