#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "DatabaseManager.h"
#include "AplicacionModel.h"
#include "LicenciaModel.h"

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
    void cargarLicencias(int appId);
    void cargaraplicaciones();

private:
    Ui::MainWindow *ui;
    DatabaseManager &dbManager;
    QStandardItemModel *modeloAplicaciones;
    QList<AplicacionModel*> aplicaciones;
    QList<LicenciaModel*> licencias;
};

#endif // MAINWINDOW_H


