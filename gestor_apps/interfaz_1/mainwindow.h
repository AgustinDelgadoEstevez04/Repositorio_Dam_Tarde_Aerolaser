#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QListWidgetItem>
#include "DatabaseManager.h"
#include "AplicacionModel.h"
#include "LicenciaModel.h"
#include "aplicacion.h"

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


    void on_usuario_nombre_linkActivated(const QString &link);

    void on_cerrar_sesion_clicked();

    void on_barra_busqueda_cursorPositionChanged(int arg1, int arg2);

    void on_favoritos_clicked();

    void on_descargados_clicked();

    void on_no_descargados_clicked();

    void on_lista_apps_indexesMoved(const QModelIndexList &indexes);

    void on_lista_filtro_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::MainWindow *ui;
    DatabaseManager &dbManager;
    QStandardItemModel *modeloAplicaciones;
    QList<AplicacionModel*> aplicaciones;
    QList<LicenciaModel*> licencias;
};

#endif // MAINWINDOW_H


