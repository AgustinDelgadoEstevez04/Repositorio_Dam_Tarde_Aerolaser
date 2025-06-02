#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DatabaseManager.h"
#include <QMessageBox>
#include <QDebug>
#include <QIcon>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), dbManager(DatabaseManager::instance()), modeloAplicaciones(new QStandardItemModel(this)) {
    ui->setupUi(this);
    cargaraplicaciones();

    ui->lista_apps->setModel(modeloAplicaciones);
    ui->lista_apps->setIconSize(QSize(32, 32));

    connect(ui->barra_busqueda, &QLineEdit::textChanged, this, &MainWindow::filtrarAplicaciones); // Renombrado de ui->lineEdit_3 a ui->barra_busqueda
    connect(ui->lista_apps, &QListView::clicked, this, &MainWindow::mostrarDetallesAplicacion); // Renombrado de ui->listView a ui->lista_apps
}

MainWindow::~MainWindow() {
    delete ui;
    delete modeloAplicaciones;
}



void MainWindow::cargaraplicaciones() {
    aplicaciones.clear();
    QList<aplicacion> listaApps = dbManager.aplicacionDao.obtenerTodasLasAplicaciones();
    modeloAplicaciones->clear();

    for (const aplicacion &app : listaApps) {
        AplicacionModel *modeloApp = new AplicacionModel(app, this);
        aplicaciones.append(modeloApp);

        QStandardItem *item = new QStandardItem(app.nombre());

        // Cargar el icono desde la ruta de la aplicación
        QIcon icon(app.icono());
        if (!icon.isNull()) {
            item->setIcon(icon);

        } else {
            qDebug() << "Advertencia: No se pudo cargar el icono para:" << app.nombre() << "en la ruta:" << app.icono();

        }

        item->setData(app.id(), Qt::UserRole); // Almacena el ID de la aplicación
        modeloAplicaciones->appendRow(item);
    }
}



void MainWindow::filtrarAplicaciones() {
    QString textoBusqueda = ui->barra_busqueda->text().trimmed(); // Obtiene el texto del buscador
    modeloAplicaciones->clear(); // Limpia el modelo actual

    QList<aplicacion> listaCompletaApps = dbManager.aplicacionDao.obtenerTodasLasAplicaciones(); // O si tienes una lista en memoria, úsala

    for (const aplicacion &app : listaCompletaApps) {
        // Filtra si el nombre de la aplicación contiene el texto de búsqueda
        if (app.nombre().contains(textoBusqueda, Qt::CaseInsensitive)) {
            QStandardItem *item = new QStandardItem(app.nombre());


            QIcon icon(app.icono());
            if (!icon.isNull()) {
                item->setIcon(icon);
            } else {
                qDebug() << "Advertencia: No se pudo cargar el icono para:" << app.nombre() << "en la ruta:" << app.icono();

            }


            item->setData(app.id(), Qt::UserRole); // Almacena el ID de la aplicación
            modeloAplicaciones->appendRow(item);
        }
    }
}

void MainWindow::mostrarDetallesAplicacion() {
    QModelIndex index = ui->lista_apps->currentIndex();
    if (!index.isValid()) return;

    int idApp = index.data(Qt::UserRole).toInt();
    aplicacion app = dbManager.aplicacionDao.obtenerAplicacionPorId(idApp);

    ui->label->setText("Descripción: " + app.descripcion());

    cargarLicencias(idApp);
}

void MainWindow::cargarLicencias(int appId) {
    licencias.clear();
    ui->lista_filtro->clear();

    QList<licencia> listaLicencias = dbManager.licenciaDao.obtenerLicenciasPorEstado(licencia::Activa);

    for (const licencia &lic : listaLicencias) {
        if (lic.appId() == appId) {
            LicenciaModel *modeloLic = new LicenciaModel(lic, this);
            licencias.append(modeloLic);

            ui->lista_filtro->addItem(lic.estadoToString());
        }
    }
}

void MainWindow::on_usuario_nombre_linkActivated(const QString &link)
{

}


void MainWindow::on_cerrar_sesion_clicked()
{

}


void MainWindow::on_barra_busqueda_cursorPositionChanged(int arg1, int arg2)
{

}


void MainWindow::on_favoritos_clicked()
{

}


void MainWindow::on_descargados_clicked()
{

}


void MainWindow::on_no_descargados_clicked()
{

}


void MainWindow::on_lista_apps_indexesMoved(const QModelIndexList &indexes)
{

}


void MainWindow::on_lista_filtro_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{

}


void MainWindow::on_favorito_app_clicked()
{

}


void MainWindow::on_descargar_app_clicked()
{

}


void MainWindow::on_no_descargados_2_clicked()
{

}

