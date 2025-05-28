#ifndef USUARIO_H
#define USUARIO_H
#include <QString>
#include <QDebug>

class usuario {
private:
    QString m_nombre;
    QString m_contrasena;
    int m_id;

public:
    usuario(const QString &nombre, const QString &contraseña, int id);

    QString getnombre() const;
    bool setnombre(const QString &nuevonombre);
    QString getcontrasena() const;
    bool verificarcontrasena(const QString &contraseña) const;
    bool setcontrasena(const QString &nuevacontraseña);
    bool verificarcredenciales(const QString &nombreIngresado, const QString &contraseñaIngresada) const;

    int getid() const;
};



#endif // USUARIO_H
