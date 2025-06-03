#include "AplicacionUsuarioDAO.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

AplicacionUsuarioDAO::AplicacionUsuarioDAO(QSqlDatabase& database)
    : mDatabase(database) {}

bool AplicacionUsuarioDAO::guardarRelacion(const AplicacionUsuario& aplicacionUsuario) {
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO aplicacion_usuario (usuario_id, aplicacion_id, estado_instalacion, favorito, estado_licencia, fecha_licencia) "
                  "VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(aplicacionUsuario.getUsuarioId());
    query.addBindValue(aplicacionUsuario.getAplicacionId());
    query.addBindValue(static_cast<int>(aplicacionUsuario.getEstadoInstalacion())); // 🔹 Convertir enum a int
    query.addBindValue(aplicacionUsuario.esFavorito());
    query.addBindValue(static_cast<int>(aplicacionUsuario.getEstadoLicencia())); // 🔹 Convertir enum a int
    query.addBindValue(aplicacionUsuario.getFechaLicencia().toString("yyyy-MM-dd"));

    if (!query.exec()) {
        qDebug() << "Error al insertar relación:" << query.lastError().text();
        return false;
    }
    return true;
}

AplicacionUsuario AplicacionUsuarioDAO::obtenerRelacionPorIds(int usuarioId, int aplicacionId) {
    QSqlQuery query(mDatabase);
    query.prepare("SELECT estado_instalacion, favorito, estado_licencia, fecha_licencia FROM aplicacion_usuario "
                  "WHERE usuario_id = ? AND aplicacion_id = ?");
    query.addBindValue(usuarioId);
    query.addBindValue(aplicacionId);

    if (query.exec() && query.next()) {
        return AplicacionUsuario(usuarioId, aplicacionId,
                                 static_cast<AplicacionUsuario::EstadoInstalacion>(query.value(0).toInt()), // 🔹 Convertir int a enum
                                 query.value(1).toBool(),
                                 static_cast<AplicacionUsuario::EstadoLicencia>(query.value(2).toInt()), // 🔹 Convertir int a enum
                                 QDate::fromString(query.value(3).toString(), "yyyy-MM-dd"));
    } else {
        qDebug() << "No se encontró relación para usuarioId:" << usuarioId << " aplicacionId:" << aplicacionId;
    }

    return AplicacionUsuario(0, 0, AplicacionUsuario::NoInstalado, false, AplicacionUsuario::SinLicencia, QDate());
}

QList<AplicacionUsuario> AplicacionUsuarioDAO::obtenerRelacionesPorUsuario(int usuarioId) {
    QList<AplicacionUsuario> relaciones;
    QSqlQuery query(mDatabase);
    query.prepare("SELECT aplicacion_id, estado_instalacion, favorito, estado_licencia, fecha_licencia FROM aplicacion_usuario WHERE usuario_id = ?");
    query.addBindValue(usuarioId);

    if (query.exec()) {
        while (query.next()) {
            relaciones.append(AplicacionUsuario(usuarioId, query.value("aplicacion_id").toInt(),
                                                static_cast<AplicacionUsuario::EstadoInstalacion>(query.value("estado_instalacion").toInt()), // 🔹 Convertir int a enum
                                                query.value("favorito").toBool(),
                                                static_cast<AplicacionUsuario::EstadoLicencia>(query.value("estado_licencia").toInt()), // 🔹 Convertir int a enum
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
    query.addBindValue(static_cast<int>(aplicacionUsuario.getEstadoInstalacion())); // 🔹 Convertir enum a int
    query.addBindValue(aplicacionUsuario.esFavorito());
    query.addBindValue(static_cast<int>(aplicacionUsuario.getEstadoLicencia())); // 🔹 Convertir enum a int
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



