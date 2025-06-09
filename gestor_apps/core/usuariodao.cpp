// usuariodao.cpp
#include "usuariodao.h"
#include "aplicacionusuario.h" // Necesario para AplicacionUsuario::NoInstalado, etc.
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVariant> // Necesario para QVariant para lastInsertId

usuariodao::usuariodao(QSqlDatabase& database) : mdatabase(database) {}

bool usuariodao::guardarUsuario(const usuario& usr) {
    QSqlQuery query(mdatabase);
    // MODIFICADO: Añadir 'icono_nombre' en el INSERT
    query.prepare("INSERT INTO usuarios (nombre, contrasena, icono_nombre) VALUES (?, ?, ?)");
    query.addBindValue(usr.getnombre());
    query.addBindValue(usr.getcontrasena());
    query.addBindValue(usr.getIconoNombre());

    if (!query.exec()) {
        qDebug() << "Error al insertar usuario:" << query.lastError().text();
        return false;
    }
    int nuevoUsuarioId = query.lastInsertId().toInt();

    // 🔹 Insertar registros en aplicacion_usuario para el nuevo usuario
    QSqlQuery appQuery(mdatabase);
    appQuery.prepare("INSERT INTO aplicacion_usuario (usuario_id, aplicacion_id, estado_instalacion, favorito, estado_licencia, fecha_licencia) "
                     "SELECT ?, id, ?, 0, ?, NULL FROM aplicaciones");
    appQuery.addBindValue(nuevoUsuarioId);
    appQuery.addBindValue(static_cast<int>(AplicacionUsuario::NoInstalado));
    appQuery.addBindValue(static_cast<int>(AplicacionUsuario::Expirada));

    if (!appQuery.exec()) {
        qDebug() << "Error al insertar relaciones de aplicaciones para el usuario:" << appQuery.lastError().text();
        // Opcional: Podrías considerar eliminar el usuario recién insertado si esto falla.
        return false;
    }
    return true;
}

usuario usuariodao::obtenerUsuarioPorId(int id) const {
    QSqlQuery query(mdatabase);
    // MODIFICADO: Seleccionar 'icono_nombre'
    query.prepare("SELECT id, nombre, contrasena, icono_nombre FROM usuarios WHERE id = ?");
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        // MODIFICADO: Pasar icono_nombre al constructor
        return usuario(query.value("nombre").toString(),
                       query.value("contrasena").toString(),
                       query.value("id").toInt(),
                       query.value("icono_nombre").toString());
    } else {
        qDebug() << "Error al obtener usuario por ID:" << query.lastError().text();
        return usuario("", "", -1); // Usuario inválido
    }
}

usuario usuariodao::obtenerUsuarioPorNombre(const QString& nombre) const {
    QSqlQuery query(mdatabase);
    // MODIFICADO: Seleccionar 'icono_nombre'
    query.prepare("SELECT id, nombre, contrasena, icono_nombre FROM usuarios WHERE nombre = ?");
    query.addBindValue(nombre);

    if (query.exec() && query.next()) {
        // MODIFICADO: Pasar icono_nombre al constructor
        return usuario(query.value("nombre").toString(),
                       query.value("contrasena").toString(),
                       query.value("id").toInt(),
                       query.value("icono_nombre").toString());
    } else {
        qDebug() << "No se encontró usuario con nombre:" << nombre << ". Error:" << query.lastError().text();
        return usuario("", "", -1); // Usuario inválido
    }
}

QList<usuario> usuariodao::obtenerTodosLosUsuarios() {
    QSqlQuery query(mdatabase);
    // MODIFICADO: Seleccionar 'icono_nombre'
    query.prepare("SELECT id, nombre, contrasena, icono_nombre FROM usuarios");

    QList<usuario> lista;
    if (query.exec()) {
        while (query.next()) {
            // MODIFICADO: Pasar icono_nombre al constructor
            lista.append(usuario(query.value("nombre").toString(),
                                 query.value("contrasena").toString(),
                                 query.value("id").toInt(),
                                 query.value("icono_nombre").toString()));
        }
    }
    return lista;
}

bool usuariodao::actualizarUsuario(const usuario& usr) {
    QSqlQuery query(mdatabase);
    // MODIFICADO: Actualizar 'icono_nombre'
    query.prepare("UPDATE usuarios SET nombre = ?, contrasena = ?, icono_nombre = ? WHERE id = ?");
    query.addBindValue(usr.getnombre());
    query.addBindValue(usr.getcontrasena());
    query.addBindValue(usr.getIconoNombre()); // <-- AÑADIR EL VALOR DEL ICONO
    query.addBindValue(usr.getid());

    if (!query.exec()) {
        qDebug() << "Error al actualizar usuario:" << query.lastError().text();
        return false;
    }
    return true;
}

bool usuariodao::eliminarUsuario(int id) {
    QSqlQuery query(mdatabase);
    query.prepare("DELETE FROM usuarios WHERE id = ?");
    query.addBindValue(id);

    if (!query.exec()) {
        qDebug() << "Error al eliminar usuario:" << query.lastError().text();
        return false;
    }
    return true;
}

bool usuariodao::verificarCredenciales(const QString& nombre, const QString& contrasena) const {
    QSqlQuery query(mdatabase);
    // No necesita 'icono_nombre' para verificar credenciales, pero se podría añadir si se quisiera cargar el usuario completo.
    query.prepare("SELECT id FROM usuarios WHERE nombre = ? AND contrasena = ?");
    query.addBindValue(nombre);
    query.addBindValue(contrasena);

    if (query.exec() && query.next()) {
        return true;
    }
    return false;
}
