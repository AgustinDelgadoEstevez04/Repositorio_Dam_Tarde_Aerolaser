#include "usuariodao.h"
#include "aplicacionusuario.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

usuariodao::usuariodao(QSqlDatabase& database) : mdatabase(database) {}

bool usuariodao::guardarUsuario(const usuario& usr) {
    QSqlQuery query(mdatabase);
    query.prepare("INSERT INTO usuarios (nombre, contrasena) VALUES (?, ?)");
    query.addBindValue(usr.getnombre());
    query.addBindValue(usr.getcontrasena());

    if (!query.exec()) {
        qDebug() << "Error al insertar usuario:" << query.lastError().text();
        return false;
    }
    int nuevoUsuarioId = query.lastInsertId().toInt(); //Obtener el ID generado automáticamente

    //Insertar registros en aplicacion_usuario para el nuevo usuario
    QSqlQuery appQuery(mdatabase);
    appQuery.prepare("INSERT INTO aplicacion_usuario (usuario_id, aplicacion_id, estado_instalacion, favorito, estado_licencia, fecha_licencia) "
                     "SELECT ?, id, ?, 0, ?, NULL FROM aplicaciones");
    appQuery.addBindValue(nuevoUsuarioId);
    appQuery.addBindValue(static_cast<int>(AplicacionUsuario::NoInstalado)); //Se usa el valor numérico del enum
    appQuery.addBindValue(static_cast<int>(AplicacionUsuario::Expirada));

    if (!appQuery.exec()) {
        qDebug() << "Error al insertar relaciones de aplicaciones para el usuario:" << appQuery.lastError().text();
        return false;
    }

    return true;
}

usuario usuariodao::obtenerUsuarioPorId(int id) const {
    QSqlQuery query(mdatabase);
    query.prepare("SELECT id, nombre, contrasena, avatar FROM usuarios WHERE id = ?");
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        return usuario(query.value(1).toString(),
                       query.value(2).toString(),
                       query.value(0).toInt(),
                       query.value(3).toString());
    }
    return usuario("", "", -1, "");
}

usuario usuariodao::obtenerUsuarioPorNombre(const QString& nombre) const {
    QSqlQuery query(mdatabase);
    query.prepare("SELECT id, nombre, contrasena, avatar FROM usuarios WHERE nombre = ?");
    query.addBindValue(nombre);

    if (query.exec() && query.next()) {
        return usuario(query.value(1).toString(),
                       query.value(2).toString(),
                       query.value(0).toInt(),
                       query.value(3).toString());
    }

    qDebug() << "Error: Usuario no encontrado en la base de datos."; // Verifica si la consulta falla
    return usuario("", "", -1, ""); // Devuelve un usuario vacío si no existe
}


QList<usuario> usuariodao::obtenerTodosLosUsuarios() {
    QSqlQuery query(mdatabase);
    query.prepare("SELECT id, nombre, contrasena, avatar FROM usuarios");

    QList<usuario> lista;
    if (query.exec()) {
        while (query.next()) {
            lista.append(usuario(query.value(1).toString(),
                                 query.value(2).toString(),
                                 query.value(0).toInt(),
                                 query.value(3).toString()));
        }
    }
    return lista;
}

bool usuariodao::actualizarUsuario(const usuario& usr) {
    QSqlQuery query(mdatabase);
    query.prepare("UPDATE usuarios SET nombre = ?, contrasena = ? WHERE id = ?");
    query.addBindValue(usr.getnombre());
    query.addBindValue(usr.getcontrasena());
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
    query.prepare("SELECT id FROM usuarios WHERE nombre = ? AND contrasena = ?");
    query.addBindValue(nombre);
    query.addBindValue(contrasena);

    return query.exec() && query.next();
}

bool usuariodao::actualizarAvatar(int id, const QString& rutaAvatar) {
    QSqlQuery query(mdatabase);
    query.prepare("UPDATE usuarios SET avatar = ? WHERE id = ?");
    query.addBindValue(rutaAvatar);
    query.addBindValue(id);

    if (!query.exec()) {
        qDebug() << "Error al actualizar avatar:" << query.lastError().text();
        return false;
    }
    return true;
}

