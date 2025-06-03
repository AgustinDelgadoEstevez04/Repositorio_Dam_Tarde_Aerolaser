#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager(const QString& path)
    : mDatabase(std::make_unique<QSqlDatabase>(QSqlDatabase::addDatabase("QSQLITE"))),
    aplicacionDao(*mDatabase),
    aplicacionusuarioDao(*mDatabase),
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
               "icono TEXT NOT NULL)");

    query.exec("CREATE TABLE IF NOT EXISTS usuarios ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "nombre TEXT UNIQUE NOT NULL, "
               "contrasena TEXT NOT NULL)");


    query.exec("CREATE TABLE IF NOT EXISTS aplicacion_usuario ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "usuario_id INTEGER NOT NULL, "
               "aplicacion_id INTEGER NOT NULL, "
               "estado_instalacion TEXT NOT NULL, "
               "favorito BOOLEAN NOT NULL, "
               "estado_licencia TEXT NOT NULL, "
               "fecha_licencia DATE NOT NULL, "
               "FOREIGN KEY(usuario_id) REFERENCES usuarios(id), "
               "FOREIGN KEY(aplicacion_id) REFERENCES aplicaciones(id))");


    query.exec("SELECT COUNT(*) FROM aplicaciones");
    query.next();
    int numApps = query.value(0).toInt();

    if (numApps == 0) {  // Si no hay aplicaciones, se insertan
        qDebug() << "La base de datos está vacía, insertando aplicaciones por defecto...";

        query.exec("INSERT INTO aplicaciones (nombre, descripcion, icono, estado,favorito) VALUES "
                   "('Gestor de Archivos', 'Organiza documentos y archivos', ':/imagenes trabajo/archivo.png'),"
                   "('Editor de Texto', 'Escribe y edita documentos de texto', ':/imagenes trabajo/editor-de-texto.png'),"
                   "('Calculadora Científica', 'Realiza cálculos matemáticos avanzados', ':/imagenes trabajo/calculadora.png'),"
                   "('Reproductor de Música', 'Escucha tus canciones favoritas', ':/imagenes trabajo/musica.png'),"
                   "('Calendario', 'Administra tu agenda y eventos', ':/imagenes trabajo/calendario.png'),"
                   "('Gestor de Tareas', 'Organiza y gestiona tus actividades diarias', ':/imagenes trabajo/portapapeles.png'),"
                   "('Explorador Web', 'Accede a sitios web y realiza búsquedas en internet', ':/imagenes trabajo/sitio-web.png'),"
                   "('Lector de PDFs', 'Abre y visualiza archivos en formato PDF', ':/imagenes trabajo/archivo-pdf.png')");

        if (query.lastError().isValid()) {
            qDebug() << "Error al insertar aplicaciones por defecto:" << query.lastError().text();
        } else {
            qDebug() << "Aplicaciones por defecto insertadas correctamente.";
        }
    } else {
        qDebug() << "Las aplicaciones ya existen, no se insertaron nuevamente.";
    }
}




