#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "DatabaseManager.h"
#include "AplicacionModel.h"
#include "LicenciaModel.h"
#include "UsuarioModel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void filtrarAplicaciones();
    void mostrarDetallesAplicacion();
    void mostrarLicenciasDeAplicacion();
    void iniciarSesion();
    void cerrarSesion();

private:
    Ui::MainWindow *ui;
    DatabaseManager &dbManager;
    QStandardItemModel *modeloAplicaciones;
    QStandardItemModel *modeloLicencias;
    QList<AplicacionModel*> aplicaciones;
    QList<LicenciaModel*> licencias;
    UsuarioModel *usuarioActual;

    void cargarAplicaciones();
    void cargarLicencias(int appId);
};

#endif // MAINWINDOW_H

