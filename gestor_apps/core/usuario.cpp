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
        m_nombre = nuevonombre;
        return true;

}

bool usuario::verificarcredenciales(const QString &nombreIngresado, const QString &contrasenaIngresada) const {
    return (nombreIngresado == m_nombre && contrasenaIngresada == m_contrasena);
}

bool usuario::setcontrasena(const QString &nuevacontrasena) {

        m_contrasena = nuevacontrasena;
        return true;

}

int usuario::getid() const {
    return m_id;
}
