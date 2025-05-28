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


