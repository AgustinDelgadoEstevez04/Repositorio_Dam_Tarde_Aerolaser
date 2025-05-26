#include "databasemanager.h"

databasemanager *databasemanager::instancia = nullptr;

databasemanager::databasemanager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
}

databasemanager *databasemanager::obtenerinstancia() {
    if (!instancia) {
        instancia = new databasemanager();
    }
    return instancia;
}

bool databasemanager::abrirconexion(const QString &nombrebd) {
    db.setDatabaseName(nombrebd);
    if (!db.open()) {
        qDebug() << "Error al conectar con la base de datos:" << db.lastError().text();
        return false;
    }
    qDebug() << "Conexión a la base de datos establecida.";
    return true;
}

void databasemanager::cerrarconexion() {
    if (db.isOpen()) {
        db.close();
        qDebug() << "Conexión a la base de datos cerrada.";
    }
}

bool databasemanager::ejecutaconsulta(const QString &consulta) {
    QSqlQuery query(db);
    if (!query.exec(consulta)) {
        qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlDatabase databasemanager::obtenerbase() {
    return db;
}

databasemanager::~databasemanager() {
    cerrarconexion();
}
