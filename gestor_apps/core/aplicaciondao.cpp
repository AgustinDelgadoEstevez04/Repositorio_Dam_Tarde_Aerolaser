#include "aplicaciondao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

aplicaciondao::aplicaciondao(QSqlDatabase &database):
    mdatabase(database)
{}

bool aplicaciondao::guardarAplicacion(const aplicacion& app) const {
    QSqlQuery query(mdatabase);
    query.prepare("INSERT INTO aplicaciones (id, nombre, descripcion, icono, estado, favorito) VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(app.id());
    query.addBindValue(app.nombre());
    query.addBindValue(app.descripcion());
    query.addBindValue(app.icono());
    query.addBindValue(static_cast<int>(app.estado()));
    query.addBindValue(static_cast<int>(app.favorito()));  // 🔹 Nuevo campo de favorito

    if (!query.exec()) {
        qDebug() << "Error al insertar aplicación:" << query.lastError().text();
        return false;
    }
    return true;
}

aplicacion aplicaciondao::obtenerAplicacionPorId(int id) const {
    QSqlQuery query(mdatabase);
    query.prepare("SELECT id, nombre, descripcion, icono, estado, favorito FROM aplicaciones WHERE id = ?");
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        return aplicacion(query.value(0).toInt(),
                          query.value(1).toString(),
                          query.value(2).toString(),
                          query.value(3).toString(),
                          static_cast<aplicacion::Estado>(query.value(4).toInt()),
                          static_cast<aplicacion::Favorito>(query.value(5).toInt()));  // 🔹 Agregado favorito
    }
    return aplicacion();
}

QList<aplicacion> aplicaciondao::obtenerTodasLasAplicaciones() const {
    QSqlQuery query(mdatabase);
    query.prepare("SELECT id, nombre, descripcion, icono, estado, favorito FROM aplicaciones");

    QList<aplicacion> lista;
    if (query.exec()) {
        while (query.next()) {
            lista.append(aplicacion(query.value(0).toInt(),
                                    query.value(1).toString(),
                                    query.value(2).toString(),
                                    query.value(3).toString(),
                                    static_cast<aplicacion::Estado>(query.value(4).toInt()),
                                    static_cast<aplicacion::Favorito>(query.value(5).toInt())));  // 🔹 Agregado favorito
        }
    }
    return lista;
}

QList<aplicacion> aplicaciondao::obtenerAplicacionesPorEstado(aplicacion::Estado estado) {
    QSqlQuery query(mdatabase);
    query.prepare("SELECT id, nombre, descripcion, icono, estado, favorito FROM aplicaciones WHERE estado = ?");
    query.addBindValue(static_cast<int>(estado));

    QList<aplicacion> lista;
    if (query.exec()) {
        while (query.next()) {
            lista.append(aplicacion(query.value(0).toInt(),
                                    query.value(1).toString(),
                                    query.value(2).toString(),
                                    query.value(3).toString(),
                                    static_cast<aplicacion::Estado>(query.value(4).toInt()),
                                    static_cast<aplicacion::Favorito>(query.value(5).toInt())));  // 🔹 Agregado favorito
        }
    }
    return lista;
}

// 🔹 Nueva función para obtener aplicaciones por favorito
QList<aplicacion> aplicaciondao::obtenerAplicacionesPorFavorito(aplicacion::Favorito favorito) {
    QSqlQuery query(mdatabase);
    query.prepare("SELECT id, nombre, descripcion, icono, estado, favorito FROM aplicaciones WHERE favorito = ?");
    query.addBindValue(static_cast<int>(favorito));

    QList<aplicacion> lista;
    if (query.exec()) {
        while (query.next()) {
            lista.append(aplicacion(query.value(0).toInt(),
                                    query.value(1).toString(),
                                    query.value(2).toString(),
                                    query.value(3).toString(),
                                    static_cast<aplicacion::Estado>(query.value(4).toInt()),
                                    static_cast<aplicacion::Favorito>(query.value(5).toInt())));
        }
    }
    return lista;
}

bool aplicaciondao::actualizarAplicacion(const aplicacion& app) {
    QSqlQuery query(mdatabase);
    query.prepare("UPDATE aplicaciones SET nombre = ?, descripcion = ?, icono = ?, estado = ?, favorito = ? WHERE id = ?");
    query.addBindValue(app.nombre());
    query.addBindValue(app.descripcion());
    query.addBindValue(app.icono());
    query.addBindValue(static_cast<int>(app.estado()));
    query.addBindValue(static_cast<int>(app.favorito()));  // 🔹 Agregado favorito
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



