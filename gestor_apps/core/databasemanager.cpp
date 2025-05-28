#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager(const QString& path)
    : mDatabase(std::make_unique<QSqlDatabase>(QSqlDatabase::addDatabase("QSQLITE"))),
    aplicacionDao(*mDatabase),
    licenciaDao(*mDatabase),
    usuarioDao(*mDatabase) {


    mDatabase->setDatabaseName(path);

    if (!mDatabase->open()) {
        qDebug() << "Error al abrir la base de datos:" << mDatabase->lastError().text();
    } else {
        qDebug() << "Base de datos abierta correctamente.";
    }
}

DatabaseManager::~DatabaseManager() {
    if (mDatabase->isOpen()) {
        mDatabase->close();
        qDebug() << "Conexión a la base de datos cerrada.";
    }
}

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager instancia;
    return instancia;
}

void DatabaseManager::debugQuery(const QSqlQuery& query) {
    if (query.lastError().isValid()) {
        qDebug() << "Error en consulta SQL:" << query.lastError().text();
    }
}
QSqlDatabase& DatabaseManager::obtenerBaseDeDatos() {
    return *mDatabase;
}
void DatabaseManager::inicializarBaseDeDatos() {
    QSqlQuery query(*mDatabase);
    query.exec("CREATE TABLE IF NOT EXISTS aplicaciones ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "nombre TEXT UNIQUE NOT NULL, "
               "descripcion TEXT NOT NULL, "
               "icono TEXT NOT NULL, "
               "estado INTEGER NOT NULL)");


    query.exec("CREATE TABLE IF NOT EXISTS usuarios ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "nombre TEXT UNIQUE NOT NULL, "
               "contraseña TEXT NOT NULL)");


    query.exec("CREATE TABLE IF NOT EXISTS licencias ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "appId INTEGER NOT NULL, "
               "userId INTEGER NOT NULL, "
               "estado INTEGER NOT NULL, "
               "fechaInicio DATE NOT NULL, "
               "fechaFin DATE NOT NULL, "
               "FOREIGN KEY(appId) REFERENCES aplicaciones(id), "
               "FOREIGN KEY(userId) REFERENCES usuarios(id))");
}



