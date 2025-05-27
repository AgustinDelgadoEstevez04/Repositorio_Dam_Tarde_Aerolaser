#include "usuario.h"

usuario::usuario(const QString &nombre, const QString &contrasena, int id):
    m_id(id) {
    setnombre(nombre);
    setcontrasena(contrasena);
}

QString usuario::getnombre() const {
    return m_nombre;
}
QString usuario::getcontrasena() const {
    return m_contrasena;
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

bool usuario::verificarcredenciales(const QString &nombreIngresado, const QString &contrasenaIngresada) const {
    return (nombreIngresado == m_nombre && contrasenaIngresada == m_contrasena);
}

bool usuario::setcontrasena(const QString &nuevacontrasena) {
    if (nuevacontrasena.length() >= 6 && nuevacontrasena.length() <= 30) {
        m_contrasena = nuevacontrasena;
        return true;
    } else {
        qDebug() << "Error: la contraseña debe tener entre 6 y 30 caracteres.";
        return false;
    }
}

int usuario::getid() const {
    return m_id;
}
