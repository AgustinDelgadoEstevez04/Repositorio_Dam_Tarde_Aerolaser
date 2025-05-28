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
        inicializarBaseDeDatos();
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


    query.exec("SELECT COUNT(*) FROM aplicaciones");
    query.next();
    int numApps = query.value(0).toInt();

    if (numApps == 0) {  // Si no hay aplicaciones, se insertan
        qDebug() << "La base de datos está vacía, insertando aplicaciones por defecto...";

        query.exec("INSERT INTO aplicaciones (nombre, descripcion, icono, estado) VALUES "
                   "('Gestor de Archivos', 'Organiza documentos y archivos', ':/imagenes/archivos.png', 2),"
                   "('Editor de Texto', 'Escribe y edita documentos de texto', ':/imagenes/editor.png', 2),"
                   "('Calculadora Científica', 'Realiza cálculos matemáticos avanzados', ':/imagenes/calculadora.png', 2),"
                   "('Reproductor de Música', 'Escucha tus canciones favoritas', ':/imagenes/musica.png', 2),"
                   "('Calendario', 'Administra tu agenda y eventos', ':/imagenes/calendario.png', 2),"
                   "('Gestor de Tareas', 'Organiza y gestiona tus actividades diarias', ':/imagenes/tareas.png', 2),"
                   "('Explorador Web', 'Accede a sitios web y realiza búsquedas en internet', ':/imagenes/web.png', 2),"
                   "('Lector de PDFs', 'Abre y visualiza archivos en formato PDF', ':/imagenes/pdf.png', 2)");

        if (query.lastError().isValid()) {
            qDebug() << "Error al insertar aplicaciones por defecto:" << query.lastError().text();
        } else {
            qDebug() << "Aplicaciones por defecto insertadas correctamente.";
        }
    } else {
        qDebug() << "Las aplicaciones ya existen, no se insertaron nuevamente.";
    }
}




