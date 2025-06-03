#include "aplicacionusuariodao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
licenciadao::licenciadao(QSqlDatabase& database) : mdatabase(database) {}

bool licenciadao::guardarLicencia(const licencia& lic) {
    QSqlQuery query(mdatabase);
    query.prepare("INSERT INTO licencias (id, appId, userId, estado, fechaInicio, fechaFin) VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(lic.id());
    query.addBindValue(lic.appId());
    query.addBindValue(lic.userId());
    query.addBindValue(static_cast<int>(lic.estado()));
    query.addBindValue(lic.fechaInicio());
    query.addBindValue(lic.fechaFin());

    if (!query.exec()) {
        qDebug() << "Error al insertar licencia:" << query.lastError().text();
        return false;
    }
    return true;
}

licencia licenciadao::obtenerLicenciaPorId(int id) const {
    QSqlQuery query(mdatabase);
    query.prepare("SELECT id, appId, userId, estado, fechaInicio, fechaFin FROM licencias WHERE id = ?");
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        return licencia(query.value(0).toInt(),
                        query.value(1).toInt(),
                        query.value(2).toInt(),
                        static_cast<licencia::Estado>(query.value(3).toInt()),
                        query.value(4).toDate(),
                        query.value(5).toDate());
    }
    return licencia();
}

QList<licencia> licenciadao::obtenerTodasLasLicencias() {
    QSqlQuery query(mdatabase);
    query.prepare("SELECT id, appId, userId, estado, fechaInicio, fechaFin FROM licencias");

    QList<licencia> lista;
    if (query.exec()) {
        while (query.next()) {
            lista.append(licencia(query.value(0).toInt(),
                                  query.value(1).toInt(),
                                  query.value(2).toInt(),
                                  static_cast<licencia::Estado>(query.value(3).toInt()),
                                  query.value(4).toDate(),
                                  query.value(5).toDate()));
        }
    }
    return lista;
}

QList<licencia> licenciadao::obtenerLicenciasPorEstado(licencia::Estado estado) const{
    QSqlQuery query(mdatabase);
    query.prepare("SELECT id, appId, userId, estado, fechaInicio, fechaFin FROM licencias WHERE estado = ?");
    query.addBindValue(static_cast<int>(estado));

    QList<licencia> lista;
    if (query.exec()) {
        while (query.next()) {
            lista.append(licencia(query.value(0).toInt(),
                                  query.value(1).toInt(),
                                  query.value(2).toInt(),
                                  static_cast<licencia::Estado>(query.value(3).toInt()),
                                  query.value(4).toDate(),
                                  query.value(5).toDate()));
        }
    }
    return lista;
}

bool licenciadao::actualizarLicencia(const licencia& lic) {
    QSqlQuery query(mdatabase);
    query.prepare("UPDATE licencias SET appId = ?, userId = ?, estado = ?, fechaInicio = ?, fechaFin = ? WHERE id = ?");
    query.addBindValue(lic.appId());
    query.addBindValue(lic.userId());
    query.addBindValue(static_cast<int>(lic.estado()));
    query.addBindValue(lic.fechaInicio());
    query.addBindValue(lic.fechaFin());
    query.addBindValue(lic.id());

    if (!query.exec()) {
        qDebug() << "Error al actualizar licencia:" << query.lastError().text();
        return false;
    }
    return true;
}

bool licenciadao::eliminarLicencia(int id) {
    QSqlQuery query(mdatabase);
    query.prepare("DELETE FROM licencias WHERE id = ?");
    query.addBindValue(id);

    if (!query.exec()) {
        qDebug() << "Error al eliminar licencia:" << query.lastError().text();
        return false;
    }
    return true;
}

bool licenciadao::estaActiva(int id) {
    QSqlQuery query(mdatabase);
    query.prepare("SELECT estado FROM licencias WHERE id = ?");
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() == static_cast<int>(licencia::Activa);
    }
    return false;
}

bool licenciadao::estaCaducada(int id) {
    QSqlQuery query(mdatabase);
    query.prepare("SELECT estado FROM licencias WHERE id = ?");
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() == static_cast<int>(licencia::Caducada);
    }
    return false;
}

bool licenciadao::estaProximaACaducar(int id) {
    QSqlQuery query(mdatabase);
    query.prepare("SELECT estado FROM licencias WHERE id = ?");
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() == static_cast<int>(licencia::Proximaacaducar);
    }
    return false;
}

