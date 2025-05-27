#include "usuario.h"

usuario::usuario(const QString &nombre, const QString &contraseña, int id)
    : m_id(id) {
    setnombre(nombre);
    setcontraseña(contraseña);
}

QString usuario::getnombre() const {
    return m_nombre;
}

bool usuario::setnombre(const QString &nuevonombre) {
    if (nuevonombre.length() >= 6 && nuevonombre.length() <= 30) {
        m_nombre = nuevonombre;
        return true;
    } else {
        qDebug() << "Error: el nombre debe tener entre 6 y 30 caracteres.";
        return false;
    }
}

bool usuario::verificarcredenciales(const QString &nombreIngresado, const QString &contraseñaIngresada) const {
    return (nombreIngresado == m_nombre && contraseñaIngresada == m_contraseña);
}

bool usuario::setcontraseña(const QString &nuevacontraseña) {
    if (nuevacontraseña.length() >= 6 && nuevacontraseña.length() <= 30) {
        m_contraseña = nuevacontraseña;
        return true;
    } else {
        qDebug() << "Error: la contraseña debe tener entre 6 y 30 caracteres.";
        return false;
    }
}

int usuario::getid() const {
    return m_id;
}
