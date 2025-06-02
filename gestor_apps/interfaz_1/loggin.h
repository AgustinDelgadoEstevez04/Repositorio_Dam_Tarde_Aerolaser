 #ifndef LOGGIN_H
#define LOGGIN_H

#include <QMainWindow>
#include "databasemanager.h" // Se incluye porque DatabaseManager es usado en loggin.cpp
#include "usuario.h"         // Se incluye porque la clase usuario es usada en loggin.cpp

QT_BEGIN_NAMESPACE
namespace Ui {
class loggin;
}
QT_END_NAMESPACE

class loggin : public QMainWindow
{
    Q_OBJECT

public:
    loggin(QWidget *parent = nullptr);
    ~loggin();

private slots:
    void on_iniciar_clicked();
    void on_registrar_clicked();
    void on_eliminar_clicked();

private:
    Ui::loggin *ui;
    // Se elimina QSet<QString> usuariosRegistrados; ya que la gestión de usuarios ahora es con la base de datos
};

#endif // LOGGIN_H
