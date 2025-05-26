
#ifndef USUARIO_DAO_H
#define USUARIO_DAO_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "usuario.h"
#include "databasemanager.h"

class usuario_dao {
private:
    QSqlDatabase db;

public:
    usuario_dao();

    bool agregarusuario(const usuario &u);
    usuario obtenerusuario(int id);
    bool actualizarusuario(const usuario &u);
    bool eliminarusuario(int id);
    bool verificarcredenciales(const QString &nombre, const QString &contraseña);
};

#endif
