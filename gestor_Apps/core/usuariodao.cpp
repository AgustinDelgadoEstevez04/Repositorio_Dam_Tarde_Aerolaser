#include "usuariodao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

usuariodao::usuariodao(QSqlDatabase& database) : mdatabase(database) {}

bool usuariodao::guardarUsuario(const usuario& usr) {
    QSqlQuery query(mdatabase);
    query.prepare("INSERT INTO usuarios (id, nombre, contrasena) VALUES (?, ?, ?)");
    query.addBindValue(usr.getid());
    query.addBindValue(usr.getnombre());
    query.addBindValue(usr.getcontrasena());

    if (!query.exec()) {
        qDebug() << "Error al insertar usuario:" << query.lastError().text();
        return false;
    }
    return true;
}

usuario usuariodao::obtenerUsuarioPorId(int id) const {
    QSqlQuery query(mdatabase);
    query.prepare("SELECT id, nombre, contrasena FROM usuarios WHERE id = ?");
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        return usuario(query.value(1).toString(),
                       query.value(2).toString(),
                       query.value(0).toInt());
    }
    return usuario("", "", -1);
}

usuario usuariodao::obtenerUsuarioPorNombre(const QString& nombre) const { // <-- DEBE SER CONST AQUÍ TAMBIÉN
    QSqlQuery query(mdatabase);
    query.prepare("SELECT id, nombre, contrasena FROM usuarios WHERE nombre = ?");
    query.addBindValue(nombre);

    if (query.exec() && query.next()) {
        return usuario(query.value(1).toString(),
                       query.value(2).toString(),
                       query.value(0).toInt());
    }
    return usuario("", "", -1);
}

QList<usuario> usuariodao::obtenerTodosLosUsuarios() {
    QSqlQuery query(mdatabase);
    query.prepare("SELECT id, nombre, contrasena FROM usuarios");

    QList<usuario> lista;
    if (query.exec()) {
        while (query.next()) {
            lista.append(usuario(query.value(1).toString(),
                                 query.value(2).toString(),
                                 query.value(0).toInt()));
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

bool usuariodao::verificarCredenciales(const QString& nombre, const QString& contrasena) const { // <-- DEBE SER CONST AQUÍ TAMBIÉN
    QSqlQuery query(mdatabase);
    query.prepare("SELECT id FROM usuarios WHERE nombre = ? AND contrasena = ?");
    query.addBindValue(nombre);
    query.addBindValue(contrasena);

    return query.exec() && query.next();
}
