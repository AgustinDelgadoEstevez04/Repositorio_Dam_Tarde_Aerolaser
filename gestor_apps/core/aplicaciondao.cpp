#include "aplicaciondao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

aplicaciondao::aplicaciondao(QSqlDatabase &database) : mdatabase(database) {}

bool aplicaciondao::guardarAplicacion(const aplicacion& app) const {
    QSqlQuery query(mdatabase);
    query.prepare("INSERT INTO aplicaciones (id, nombre, descripcion, icono) VALUES (?, ?, ?, ?)");
    query.addBindValue(app.id());
    query.addBindValue(app.nombre());
    query.addBindValue(app.descripcion());
    query.addBindValue(app.icono());

    if (!query.exec()) {
        qDebug() << "Error al insertar aplicación:" << query.lastError().text();
        return false;
    }
    return true;
}

aplicacion aplicaciondao::obtenerAplicacionPorId(int id) const {
    QSqlQuery query(mdatabase);
    query.prepare("SELECT id, nombre, descripcion, icono FROM aplicaciones WHERE id = ?");
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        return aplicacion(query.value(0).toInt(),
                          query.value(1).toString(),
                          query.value(2).toString(),
                          query.value(3).toString());
    }
    return aplicacion();
}

QList<aplicacion> aplicaciondao::obtenerTodasLasAplicaciones() const {
    QSqlQuery query(mdatabase);
    query.prepare("SELECT id, nombre, descripcion, icono FROM aplicaciones");

    QList<aplicacion> lista;
    if (query.exec()) {
        while (query.next()) {
            lista.append(aplicacion(query.value(0).toInt(),
                                    query.value(1).toString(),
                                    query.value(2).toString(),
                                    query.value(3).toString()));
        }
    }
    return lista;
}

bool aplicaciondao::actualizarAplicacion(const aplicacion& app) {
    QSqlQuery query(mdatabase);
    query.prepare("UPDATE aplicaciones SET nombre = ?, descripcion = ?, icono = ? WHERE id = ?");
    query.addBindValue(app.nombre());
    query.addBindValue(app.descripcion());
    query.addBindValue(app.icono());
    query.addBindValue(app.id());

    if (!query.exec()) {
        qDebug() << "Error al actualizar aplicación:" << query.lastError().text();
        return false;
    }
    return true;
}

bool aplicaciondao::eliminarAplicacion(int id) {
    QSqlQuery query(mdatabase);
    query.prepare("DELETE FROM aplicaciones WHERE id = ?");
    query.addBindValue(id);

    if (!query.exec()) {
        qDebug() << "Error al eliminar aplicación:" << query.lastError().text();
        return false;
    }
    return true;
}



