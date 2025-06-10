#include "usuario.h"

usuario::usuario(const QString &nombre, const QString &contrasena, int id, const QString &avatar):
    m_id(id), m_avatar(avatar) {
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
QString usuario::getAvatar() const {
    return m_avatar;
}
void usuario::setAvatar(const QString& rutaAvatar) {
    m_avatar = rutaAvatar;
}
