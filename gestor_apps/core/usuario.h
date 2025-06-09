#ifndef USUARIO_H
#define USUARIO_H
#include <QString>
#include <QDebug>

class usuario {
private:
    QString m_nombre;
    QString m_contrasena;
    int m_id;
    QString m_iconoNombre;

public:

    usuario(const QString &nombre, const QString &contrasena, int id, const QString &iconoNombre = ":/imagenes trabajo/usuario.png");

    QString getnombre() const;
    bool setnombre(const QString &nuevonombre);
    QString getcontrasena() const;
    bool verificarcontrasena(const QString &contrasena) const;
    bool setcontrasena(const QString &nuevacontrasena);
    bool verificarcredenciales(const QString &nombreIngresado, const QString &contrasenaIngresada) const;

    int getid() const;

    // NUEVOS GETTER Y SETTER PARA EL ICONO
    QString getIconoNombre() const;
    void setIconoNombre(const QString &nuevoIconoNombre);
};



#endif // USUARIO_H
