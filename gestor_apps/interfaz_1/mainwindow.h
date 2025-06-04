#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QListWidgetItem>
#include "databasemanager.h"
#include "aplicacionmodel.h"
#include "aplicacionusuariomodel.h"
#include "aplicacion.h"
#include <QIcon>
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int usuarioid, QWidget *parent = nullptr);
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

    void on_favorito_app_clicked();

    void on_descargar_app_clicked();

    void on_no_descargados_2_clicked();

    void mostrarNombreUsuario();

    void on_barraProgreso_valueChanged(int value);

    void actualizarListaFiltro(int tipofiltro);

private:
    Ui::MainWindow *ui;
    DatabaseManager &dbManager;
    QStandardItemModel *modeloAplicaciones;
    QList<AplicacionModel*> aplicaciones;
    QList<AplicacionUsuarioModel*> aplicacionusuario;
     int usuarioActualId;
    bool ultimaSeleccionEnListaApps;
    int filtroActivo;
};

#endif // MAINWINDOW_H


