#include "AplicacionUsuarioDAO.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

AplicacionUsuarioDAO::AplicacionUsuarioDAO(QSqlDatabase& database)
    : mDatabase(database) {}

bool AplicacionUsuarioDAO::guardarRelacion(const AplicacionUsuario& aplicacionUsuario) const {
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO aplicacion_usuario (usuario_id, aplicacion_id, estado_instalacion, favorito, estado_licencia, fecha_licencia) "
                  "VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(aplicacionUsuario.getUsuarioId());
    query.addBindValue(aplicacionUsuario.getAplicacionId());
    query.addBindValue(aplicacionUsuario.getEstadoInstalacion());
    query.addBindValue(aplicacionUsuario.esFavorito());
    query.addBindValue(aplicacionUsuario.getEstadoLicencia());
    query.addBindValue(aplicacionUsuario.getFechaLicencia().toString("yyyy-MM-dd"));

    if (!query.exec()) {
        qDebug() << "Error al insertar relación:" << query.lastError().text();
        return false;
    }
    return true;
}

AplicacionUsuario AplicacionUsuarioDAO::obtenerRelacionPorIds(int usuarioId, int aplicacionId) const {
    QSqlQuery query(mDatabase);
    query.prepare("SELECT estado_instalacion, favorito, estado_licencia, fecha_licencia FROM aplicacion_usuario "
                  "WHERE usuario_id = ? AND aplicacion_id = ?");
    query.addBindValue(usuarioId);
    query.addBindValue(aplicacionId);

    if (query.exec() && query.next()) {
        return AplicacionUsuario(usuarioId, aplicacionId, query.value("estado_instalacion").toString(),
                                 query.value("favorito").toBool(), query.value("estado_licencia").toString(),
                                 QDate::fromString(query.value("fecha_licencia").toString(), "yyyy-MM-dd"));
    } else {
        qDebug() << "Error al obtener relación:" << query.lastError().text();
        return AplicacionUsuario(0, 0, "", false, "", QDate());
    }
}

QList<AplicacionUsuario> AplicacionUsuarioDAO::obtenerRelacionesPorUsuario(int usuarioId) const {
    QList<AplicacionUsuario> relaciones;
    QSqlQuery query(mDatabase);
    query.prepare("SELECT aplicacion_id, estado_instalacion, favorito, estado_licencia, fecha_licencia FROM aplicacion_usuario WHERE usuario_id = ?");
    query.addBindValue(usuarioId);

    if (query.exec()) {
        while (query.next()) {
            relaciones.append(AplicacionUsuario(usuarioId, query.value("aplicacion_id").toInt(),
                                                query.value("estado_instalacion").toString(),
                                                query.value("favorito").toBool(),
                                                query.value("estado_licencia").toString(),
                                                QDate::fromString(query.value("fecha_licencia").toString(), "yyyy-MM-dd")));
        }
    } else {
        qDebug() << "Error al obtener relaciones de usuario:" << query.lastError().text();
    }

    return relaciones;
}

bool AplicacionUsuarioDAO::actualizarRelacion(const AplicacionUsuario& aplicacionUsuario) {
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE aplicacion_usuario SET estado_instalacion = ?, favorito = ?, estado_licencia = ?, fecha_licencia = ? "
                  "WHERE usuario_id = ? AND aplicacion_id = ?");
    query.addBindValue(aplicacionUsuario.getEstadoInstalacion());
    query.addBindValue(aplicacionUsuario.esFavorito());
    query.addBindValue(aplicacionUsuario.getEstadoLicencia());
    query.addBindValue(aplicacionUsuario.getFechaLicencia().toString("yyyy-MM-dd"));
    query.addBindValue(aplicacionUsuario.getUsuarioId());
    query.addBindValue(aplicacionUsuario.getAplicacionId());

    if (!query.exec()) {
        qDebug() << "Error al actualizar relación:" << query.lastError().text();
        return false;
    }
    return true;
}

bool AplicacionUsuarioDAO::eliminarRelacion(int usuarioId, int aplicacionId) {
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM aplicacion_usuario WHERE usuario_id = ? AND aplicacion_id = ?");
    query.addBindValue(usuarioId);
    query.addBindValue(aplicacionId);

    if (!query.exec()) {
        qDebug() << "Error al eliminar relación:" << query.lastError().text();
        return false;
    }
    return true;
}



