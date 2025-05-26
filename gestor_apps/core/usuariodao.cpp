#include "usuariodao.h"
#include "usuario.h"
#include "databasemanager.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

usuario_dao::usuario_dao() {
    databasemanager *dbmanager = databasemanager::obtenerinstancia();
    db = dbmanager->obtenerbase();
}

bool usuario_dao::agregarusuario(const usuario &u) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO usuarios (nombre, contraseña) VALUES (:nombre, :contraseña)");
    query.bindValue(":nombre", u.getnombre());
    query.bindValue(":contraseña", u.getcontraseña());

    if (!query.exec()) {
        qDebug() << "Error al agregar usuario:" << query.lastError().text();
        return false;
    }
    return true;
}

usuario usuario_dao::obtenerusuario(int id) {
    QSqlQuery query(db);
    query.prepare("SELECT nombre, contraseña FROM usuarios WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return usuario(query.value(0).toString(), query.value(1).toString(), id);
    } else {
        qDebug() << "Usuario no encontrado:" << query.lastError().text();
        return usuario("", "", -1);
    }
}

bool usuario_dao::actualizarusuario(const usuario &u) {
    QSqlQuery query(db);
    query.prepare("UPDATE usuarios SET nombre = :nombre, contraseña = :contraseña WHERE id = :id");
    query.bindValue(":nombre", u.getnombre());
    query.bindValue(":contraseña", u.getcontraseña());
    query.bindValue(":id", u.getid());

    if (!query.exec()) {
        qDebug() << "Error al actualizar usuario:" << query.lastError().text();
        return false;
    }
    return true;
}

bool usuario_dao::eliminarusuario(int id) {
    QSqlQuery query(db);
    query.prepare("DELETE FROM usuarios WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Error al eliminar usuario:" << query.lastError().text();
        return false;
    }
    return true;
}

bool usuario_dao::verificarcredenciales(const QString &nombre, const QString &contraseña) {
    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM usuarios WHERE nombre = :nombre AND contraseña = :contraseña");
    query.bindValue(":nombre", nombre);
    query.bindValue(":contraseña", contraseña);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    } else {
        qDebug() << "Error al verificar credenciales:" << query.lastError().text();
        return false;
    }
}
