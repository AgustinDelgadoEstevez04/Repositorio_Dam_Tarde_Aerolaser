#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <memory>
#include <QString>

#include "aplicaciondao.h"
#include "licenciadao.h"
#include "usuariodao.h"

const QString DATABASE_FILENAME = "aplicaciones.db";
class QSqlQuery;
class QSqlDatabase;
class DatabaseManager
{
public:
    static void debugQuery(const QSqlQuery& query);
    QSqlDatabase& obtenerBaseDeDatos();
    static DatabaseManager& instance();
    ~DatabaseManager();
void inicializarBaseDeDatos();
protected:
    DatabaseManager(const QString& path = DATABASE_FILENAME);
    DatabaseManager& operator=(const DatabaseManager& rhs) = delete;
    DatabaseManager(const DatabaseManager& rhs) = delete;

private:
    std::unique_ptr<QSqlDatabase> mDatabase;

public:
    const aplicaciondao aplicacionDao;
    const licenciadao licenciaDao;
    const usuariodao usuarioDao;
};

#endif // DATABASEMANAGER_H

