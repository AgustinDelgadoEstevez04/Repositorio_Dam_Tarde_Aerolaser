#ifndef LOGGIN_H
#define LOGGIN_H

#include <QMainWindow>
#include "databasemanager.h"
#include "usuario.h"
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

private:
    Ui::loggin *ui;
     int usuarioActualId;
};

#endif // LOGGIN_H
