#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DatabaseManager.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), dbManager(DatabaseManager::instance()), modeloAplicaciones(new QStandardItemModel(this)) {
    ui->setupUi(this);
    cargaraplicaciones();

    ui->listView->setModel(modeloAplicaciones);

    connect(ui->lineEdit_3, &QLineEdit::textChanged, this, &MainWindow::filtrarAplicaciones);
    connect(ui->listView, &QListView::clicked, this, &MainWindow::mostrarDetallesAplicacion);
}

MainWindow::~MainWindow() {
    delete ui;
    delete modeloAplicaciones;
}

void MainWindow::insertarAplicacionesSiBDVacia() {
    if (dbManager.aplicacionDao.obtenerTodasLasAplicaciones().isEmpty()) {
        QList<aplicacion> aplicaciones = {
            aplicacion(0, "Gestor de Archivos", "Organiza documentos y archivos", ":/imagenes/archivos.png", aplicacion::no_instalado),
            aplicacion(0, "Editor de Texto", "Escribe y edita documentos de texto", ":/imagenes/editor.png", aplicacion::no_instalado),
            aplicacion(0, "Calculadora Científica", "Realiza cálculos matemáticos avanzados", ":/imagenes/calculadora.png", aplicacion::no_instalado),
            aplicacion(0, "Reproductor de Música", "Escucha tus canciones favoritas", ":/imagenes/musica.png", aplicacion::no_instalado),
            aplicacion(0, "Calendario", "Administra tu agenda y eventos", ":/imagenes/calendario.png", aplicacion::no_instalado),
            aplicacion(0, "Gestor de Tareas", "Organiza y gestiona tus actividades diarias", ":/imagenes/tareas.png", aplicacion::no_instalado),
            aplicacion(0, "Explorador Web", "Accede a sitios web y realiza búsquedas en internet", ":/imagenes/web.png", aplicacion::no_instalado),
            aplicacion(0, "Lector de PDFs", "Abre y visualiza archivos en formato PDF", ":/imagenes/pdf.png", aplicacion::no_instalado)
        };

        for (const aplicacion &app : aplicaciones) {
            dbManager.aplicacionDao.guardarAplicacion(app);
        }

        qDebug() << "Aplicaciones insertadas porque la base de datos estaba vacía.";
    } else {
        qDebug() << "La base de datos ya tiene aplicaciones, no se insertaron nuevas.";
    }
}

void MainWindow::cargaraplicaciones() {
    aplicaciones.clear();
    QList<aplicacion> listaApps = dbManager.aplicacionDao.obtenerTodasLasAplicaciones();
    modeloAplicaciones->clear();

    for (const aplicacion &app : listaApps) {
        AplicacionModel *modeloApp = new AplicacionModel(app, this);
        aplicaciones.append(modeloApp);

        QStandardItem *item = new QStandardItem(app.nombre());
        item->setData(app.id(), Qt::UserRole);
        modeloAplicaciones->appendRow(item);
    }
}

void MainWindow::filtrarAplicaciones() {
    QString filtro = ui->lineEdit_3->text().toLower();
    modeloAplicaciones->clear();

    for (AplicacionModel *appModel : aplicaciones) {
        if (appModel->nombre().toLower().contains(filtro)) {
            QStandardItem *item = new QStandardItem(appModel->nombre());
            item->setData(appModel->id(), Qt::UserRole);
            modeloAplicaciones->appendRow(item);
        }
    }
}

void MainWindow::mostrarDetallesAplicacion() {
    QModelIndex index = ui->listView->currentIndex();
    if (!index.isValid()) return;

    int idApp = index.data(Qt::UserRole).toInt();
    aplicacion app = dbManager.aplicacionDao.obtenerAplicacionPorId(idApp);

    ui->label_4->setText("Aplicación: " + app.nombre());

    cargarLicencias(idApp);
}

void MainWindow::cargarLicencias(int appId) {
    licencias.clear();
    ui->listWidget->clear();

    QList<licencia> listaLicencias = dbManager.licenciaDao.obtenerLicenciasPorEstado(licencia::Activa);

    for (const licencia &lic : listaLicencias) {
        if (lic.appId() == appId) {
            LicenciaModel *modeloLic = new LicenciaModel(lic, this);
            licencias.append(modeloLic);

            ui->listWidget->addItem(lic.estadoToString());
        }
    }
}


