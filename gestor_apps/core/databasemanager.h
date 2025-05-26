#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class databasemanager {
private:
    static databasemanager *instancia;
    QSqlDatabase db;

    databasemanager();

public:
    static databasemanager *obtenerinstancia();
    bool abrirconexion(const QString &nombrebd);
    void cerrarconexion();
    bool ejecutaconsulta(const QString &consulta);
    QSqlDatabase obtenerbase();

    ~databasemanager();
};

#endif
