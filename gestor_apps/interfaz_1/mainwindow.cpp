#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DatabaseManager.h"
#include "loggin.h"
#include <QMessageBox>
#include <QDebug>
#include <QIcon>
#include <QPixmap>
#include <QThread>


MainWindow::MainWindow(int usuarioId, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), dbManager(DatabaseManager::instance()),
    modeloAplicaciones(new QStandardItemModel(this)), usuarioActualId(usuarioId),ultimaSeleccionEnListaApps(true),filtroActivo(2) {
    ui->setupUi(this);
    cargaraplicaciones();
    mostrarNombreUsuario();

    ui->lista_apps->setModel(modeloAplicaciones);
    ui->lista_apps->setIconSize(QSize(32, 32));

    connect(ui->barra_busqueda, &QLineEdit::textChanged, this, &MainWindow::filtrarAplicaciones);
    connect(ui->lista_apps, &QListView::clicked, this, &MainWindow::mostrarDetallesAplicacion);
    connect(ui->lista_filtro, &QListWidget::currentItemChanged, this, &MainWindow::on_lista_filtro_currentItemChanged);
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

    QList<aplicacion> listaCompletaApps = dbManager.aplicacionDao.obtenerTodasLasAplicaciones(); // O si tienes una lista en memoria

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

     ui->lista_filtro->clearSelection();
    ultimaSeleccionEnListaApps = true;

    int idApp = index.data(Qt::UserRole).toInt();
    aplicacion app = dbManager.aplicacionDao.obtenerAplicacionPorId(idApp);

    ui->label->setText("Descripción: " + app.descripcion());

    cargarLicencias(idApp);
}

void MainWindow::cargarLicencias(int appId) {

}

void MainWindow::on_usuario_nombre_linkActivated(const QString &link)
{

}


void MainWindow::on_cerrar_sesion_clicked()
{
    QMessageBox::StandardButton confirmacion;
    confirmacion = QMessageBox::question(this, "Cerrar sesión", "¿Estás seguro de que quieres cerrar sesión?",
                                         QMessageBox::Yes | QMessageBox::No);

    if (confirmacion == QMessageBox::No) {
        return;
    }


    usuarioActualId = -1;


    this->close(); // Cierra la ventana actual

    loggin *login = new loggin();
    login->show();
}


void MainWindow::on_barra_busqueda_cursorPositionChanged(int arg1, int arg2)
{

}


void MainWindow::on_favoritos_clicked()
{
        filtroActivo = 3; // 🔹 Guardamos que el filtro es de favoritos
        actualizarListaFiltro(filtroActivo); // 🔹 Recarga solo favoritas

        ui->lista_filtro->clear();


        QList<AplicacionUsuario> relaciones = dbManager.aplicacionusuarioDao.obtenerRelacionesPorUsuario(usuarioActualId);

        for (const AplicacionUsuario &rel : relaciones) {
            if (rel.esFavorito()) {
                aplicacion app = dbManager.aplicacionDao.obtenerAplicacionPorId(rel.getAplicacionId());

                QListWidgetItem *item = new QListWidgetItem(app.nombre());
                QIcon icon(app.icono());

                if (!icon.isNull()) {
                    item->setIcon(icon);
                } else {
                    qDebug() << "Advertencia: No se pudo cargar el icono para:" << app.nombre() << "en la ruta:" << app.icono();
                }

                item->setData(Qt::UserRole, app.id()); // Almacena el ID de la aplicación
                ui->lista_filtro->addItem(item);
            }
        }

}


void MainWindow::on_descargados_clicked()
{
    filtroActivo = 1;
    actualizarListaFiltro(filtroActivo);
        ui->lista_filtro->clear();


        QList<AplicacionUsuario> relaciones = dbManager.aplicacionusuarioDao.obtenerRelacionesPorUsuario(usuarioActualId);

        for (const AplicacionUsuario &rel : relaciones) {
            if (rel.getEstadoInstalacion() == AplicacionUsuario::Instalado) {
                aplicacion app = dbManager.aplicacionDao.obtenerAplicacionPorId(rel.getAplicacionId());

                QListWidgetItem *item = new QListWidgetItem(app.nombre());
                QIcon icon(app.icono());

                if (!icon.isNull()) {
                    item->setIcon(icon);
                } else {
                    qDebug() << "Advertencia: No se pudo cargar el icono para:" << app.nombre() << " en la ruta:" << app.icono();
                }

                item->setData(Qt::UserRole, app.id()); // Almacena el ID de la aplicación
                ui->lista_filtro->addItem(item);
            }
        }

  }



void MainWindow::on_no_descargados_clicked()
{ 
        filtroActivo = 2; // 🔹 Guardamos que el filtro es de no instaladas
        actualizarListaFiltro(filtroActivo); // 🔹 Recarga solo no instaladas

        ui->lista_filtro->clear();


        QList<AplicacionUsuario> relaciones = dbManager.aplicacionusuarioDao.obtenerRelacionesPorUsuario(usuarioActualId);

        for (const AplicacionUsuario &rel : relaciones) {
            if (rel.getEstadoInstalacion() == AplicacionUsuario::NoInstalado) {
                aplicacion app = dbManager.aplicacionDao.obtenerAplicacionPorId(rel.getAplicacionId());

                QListWidgetItem *item = new QListWidgetItem(app.nombre());
                QIcon icon(app.icono());

                if (!icon.isNull()) {
                    item->setIcon(icon);
                } else {
                    qDebug() << "Advertencia: No se pudo cargar el icono para:" << app.nombre() << " en la ruta:" << app.icono();
                }

                item->setData(Qt::UserRole, app.id()); // Almacena el ID de la aplicación
                ui->lista_filtro->addItem(item);
            }
        }


}


void MainWindow::on_lista_apps_indexesMoved(const QModelIndexList &indexes)
{

}


void MainWindow::on_lista_filtro_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous) {
    if (current) {
        ui->lista_apps->clearSelection();
        ultimaSeleccionEnListaApps = false;
    }
}



void MainWindow::on_favorito_app_clicked() {
    int idApp = -1;

    if (ultimaSeleccionEnListaApps) {
        QModelIndex indexApps = ui->lista_apps->currentIndex();
        if (indexApps.isValid()) {
            idApp = indexApps.data(Qt::UserRole).toInt();
        }
    } else {
        QListWidgetItem *itemFiltro = ui->lista_filtro->currentItem();
        if (itemFiltro) {
            idApp = itemFiltro->data(Qt::UserRole).toInt();
        }
    }

    if (idApp == -1) {
        QMessageBox::warning(this, "Error", "Seleccione una aplicación para marcar como favorita.");
        return;
    }

    AplicacionUsuario aplicacionUsuario = dbManager.aplicacionusuarioDao.obtenerRelacionPorIds(usuarioActualId, idApp);
    aplicacionUsuario.setFavorito(!aplicacionUsuario.esFavorito());

    if (dbManager.aplicacionusuarioDao.actualizarRelacion(aplicacionUsuario)) {
        QMessageBox::information(this, "Favoritos", QString("La aplicación ahora está %1.").arg(aplicacionUsuario.esFavorito() ? "marcada como favorita" : "desmarcada como favorita"));
         actualizarListaFiltro(filtroActivo);
    } else {
        QMessageBox::critical(this, "Error", "No se pudo actualizar el estado de favorito.");
    }
}


void MainWindow::on_descargar_app_clicked() {
    ui->barraProgreso->setRange(0, 100);
    ui->barraProgreso->setValue(0);
    ui->barraProgreso->setVisible(true);

    int idApp = -1;

    if (ultimaSeleccionEnListaApps) {
        QModelIndex indexApps = ui->lista_apps->currentIndex();
        if (indexApps.isValid()) {
            idApp = indexApps.data(Qt::UserRole).toInt();
        }
    } else {
        QListWidgetItem *itemFiltro = ui->lista_filtro->currentItem();
        if (itemFiltro) {
            idApp = itemFiltro->data(Qt::UserRole).toInt();
        }
    }

    if (idApp == -1) {
        QMessageBox::warning(this, "Error", "Seleccione una aplicación para instalar.");
        ui->barraProgreso->setVisible(false);
        return;
    }

    AplicacionUsuario aplicacionUsuario = dbManager.aplicacionusuarioDao.obtenerRelacionPorIds(usuarioActualId, idApp);

    if (aplicacionUsuario.getEstadoInstalacion() == AplicacionUsuario::Instalado) {
        QMessageBox::information(this, "Instalado", "La aplicación ya está instalada.");
        ui->barraProgreso->setVisible(false);
        return;
    }

    aplicacionUsuario.setEstadoInstalacion(AplicacionUsuario::Instalado);
    aplicacionUsuario.setEstadoLicencia(AplicacionUsuario::Activa);
    aplicacionUsuario.setFechaLicencia(QDate::currentDate());

    for (int i = 0; i <= 100; i += 10) {
        ui->barraProgreso->setValue(i);
        QThread::msleep(50);
    }

    if (dbManager.aplicacionusuarioDao.actualizarRelacion(aplicacionUsuario)) {
        QMessageBox::information(this, "Éxito", "La aplicación ha sido instalada y su licencia activada.");
         actualizarListaFiltro(filtroActivo);
    } else {
        QMessageBox::critical(this, "Error", "No se pudo actualizar la instalación y la licencia.");
    }

    ui->barraProgreso->setVisible(false);
}





void MainWindow::on_no_descargados_2_clicked() {
    ui->barraProgreso->setRange(0, 100);
    ui->barraProgreso->setValue(0);
    ui->barraProgreso->setVisible(true);

    int idApp = -1;

    if (ultimaSeleccionEnListaApps) {
        QModelIndex indexApps = ui->lista_apps->currentIndex();
        if (indexApps.isValid()) {
            idApp = indexApps.data(Qt::UserRole).toInt();
        }
    } else {
        QListWidgetItem *itemFiltro = ui->lista_filtro->currentItem();
        if (itemFiltro) {
            idApp = itemFiltro->data(Qt::UserRole).toInt();
        }
    }

    if (idApp == -1) {
        QMessageBox::warning(this, "Error", "Seleccione una aplicación para desinstalar.");
        ui->barraProgreso->setVisible(false);
        return;
    }

    AplicacionUsuario aplicacionUsuario = dbManager.aplicacionusuarioDao.obtenerRelacionPorIds(usuarioActualId, idApp);

    if (aplicacionUsuario.getEstadoInstalacion() == AplicacionUsuario::NoInstalado) {
        QMessageBox::information(this, "Ya desinstalada", "La aplicación ya está desinstalada.");
        ui->barraProgreso->setVisible(false);
        return;
    }

    aplicacionUsuario.setEstadoInstalacion(AplicacionUsuario::NoInstalado);

    for (int i = 0; i <= 100; i += 10) {
        ui->barraProgreso->setValue(i);
        QThread::msleep(50);
    }

    if (dbManager.aplicacionusuarioDao.actualizarRelacion(aplicacionUsuario)) {
        QMessageBox::information(this, "Éxito", "La aplicación ha sido desinstalada correctamente.");
         actualizarListaFiltro(filtroActivo);
    } else {
        QMessageBox::critical(this, "Error", "No se pudo actualizar la desinstalación.");
    }

    ui->barraProgreso->setVisible(false);
}




void MainWindow::mostrarNombreUsuario() {

    usuario usuario = dbManager.usuarioDao.obtenerUsuarioPorId(usuarioActualId);

    ui->usuario_nombre->setText(usuario.getnombre());
}

void MainWindow::actualizarListaFiltro(int tipoFiltro) {
    ui->lista_filtro->clear();

    QList<AplicacionUsuario> relaciones = dbManager.aplicacionusuarioDao.obtenerRelacionesPorUsuario(usuarioActualId);

    for (const AplicacionUsuario &rel : relaciones) {
        bool agregar = false;

        if (tipoFiltro == 1 && rel.getEstadoInstalacion() == AplicacionUsuario::Instalado) {
            agregar = true;
        }
        else if (tipoFiltro == 2 && rel.getEstadoInstalacion() == AplicacionUsuario::NoInstalado) {
            agregar = true;
        }
        else if (tipoFiltro == 3 && rel.esFavorito()) {
            agregar = true;
        }

        if (agregar) {
            aplicacion app = dbManager.aplicacionDao.obtenerAplicacionPorId(rel.getAplicacionId());

            QListWidgetItem *item = new QListWidgetItem(app.nombre());
            item->setIcon(QIcon(app.icono()));
            item->setData(Qt::UserRole, app.id());

            ui->lista_filtro->addItem(item);
        }
    }
}



void MainWindow::on_barraProgreso_valueChanged(int value)
{

}

