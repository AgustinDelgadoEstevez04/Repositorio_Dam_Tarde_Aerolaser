#ifndef usuario_h
#define usuario_h

#include <QString>
#include <QDebug>

class usuario {
private:
    QString m_nombre;
    QString m_contraseña;
    int m_id;

public:
    usuario(const QString &nombre, const QString &contraseña, int id);

    QString getnombre() const;
    bool setnombre(const QString &nuevonombre);
    QString getcontraseña() const { return m_contraseña; }
    bool verificarcontraseña(const QString &contraseña) const;
    bool setcontraseña(const QString &nuevacontraseña);
    bool verificarcredenciales(const QString &nombreIngresado, const QString &contraseñaIngresada) const;

    int getid() const;
};

#endif
