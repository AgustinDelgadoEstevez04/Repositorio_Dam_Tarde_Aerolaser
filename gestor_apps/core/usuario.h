#ifndef USUARIO_H
#define USUARIO_H
#include <QString>
#include <QDebug>

class usuario {
private:
    QString nombre;
    QString contraseña;
    int id;

public:
    usuario(const QString &nombre, const QString &contraseña, int id);

    QString getnombre() const;
    bool setnombre(const QString &nuevonombre);
    QString getcontraseña() const;
    bool verificarcontraseña(const QString &contraseña) const;
    bool setcontraseña(const QString &nuevacontraseña);
    bool verificarcredenciales(const QString &nombreIngresado, const QString &contraseñaIngresada) const;

    int getid() const;
};



#endif // USUARIO_H
