#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DatabaseManager.h"
#include "loggin.h"
#include <QMessageBox>
#include <QDebug>
#include <QIcon>
#include <QPixmap>


MainWindow::MainWindow(int usuarioId, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), dbManager(DatabaseManager::instance()),
    modeloAplicaciones(new QStandardItemModel(this)), usuarioActualId(usuarioId) { // 🔹 Ahora usuarioActualId está correctamente inicializado
    ui->setupUi(this);
    cargaraplicaciones();
    mostrarNombreUsuario();

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

    // Por ejemplo, si tienes una clase llamada LoginWindow:
    loggin *login = new loggin();
    login->show();
}


void MainWindow::on_barra_busqueda_cursorPositionChanged(int arg1, int arg2)
{

}


void MainWindow::on_favoritos_clicked()
{

        ui->lista_filtro->clear(); // 🔹 Limpia la lista antes de filtrar

        // 🔹 Obtener todas las relaciones usuario-aplicación
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

        QMessageBox::information(this, "Favoritos", "Se han filtrado las aplicaciones favoritas en la lista de filtros.");

}


void MainWindow::on_descargados_clicked()
{
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

        QMessageBox::information(this, "Aplicaciones Instaladas", "Se han filtrado las aplicaciones instaladas en la lista.");
  }



void MainWindow::on_no_descargados_clicked()
{
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

        QMessageBox::information(this, "Aplicaciones No Instaladas", "Se han filtrado las aplicaciones no instaladas en la lista.");

}


void MainWindow::on_lista_apps_indexesMoved(const QModelIndexList &indexes)
{

}


void MainWindow::on_lista_filtro_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
}


void MainWindow::on_favorito_app_clicked()
{
    QModelIndex index = ui->lista_apps->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Error", "Seleccione una aplicación para marcar como favorita.");
        return;
    }

    int idApp = index.data(Qt::UserRole).toInt();

    if (usuarioActualId <= 0) {
        QMessageBox::critical(this, "Error", "No se pudo obtener el ID del usuario.");
        return;
    }

    // Obtener la relación usuario-aplicación
    AplicacionUsuario aplicacionUsuario = dbManager.aplicacionusuarioDao.obtenerRelacionPorIds(usuarioActualId, idApp);

    //  Cambiar favorito de true a false, o de false a true
    aplicacionUsuario.setFavorito(!aplicacionUsuario.esFavorito());

    if (dbManager.aplicacionusuarioDao.actualizarRelacion(aplicacionUsuario)) {
        QMessageBox::information(this, "Favorito", QString("La aplicación ahora está %1.")
                                                       .arg(aplicacionUsuario.esFavorito() ? "marcada como favorita" : "desmarcada como favorita"));
    } else {
        QMessageBox::critical(this, "Error", "No se pudo actualizar el estado de favorito.");
    }
}


void MainWindow::on_descargar_app_clicked()
{
    QModelIndex index = ui->lista_apps->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Error", "Seleccione una aplicación para descargar.");
        return;
    }

    int idApp = index.data(Qt::UserRole).toInt();

    if (usuarioActualId <= 0) {
        QMessageBox::critical(this, "Error", "No se pudo obtener el ID del usuario.");
        return;
    }

    // Obtener la relación usuario-aplicación
    AplicacionUsuario aplicacionUsuario = dbManager.aplicacionusuarioDao.obtenerRelacionPorIds(usuarioActualId, idApp);

    if (aplicacionUsuario.getEstadoInstalacion() == AplicacionUsuario::Instalado) {
        QMessageBox::information(this, "Instalado", "La aplicación ya está instalada.");
        return;
    }


    aplicacionUsuario.setEstadoInstalacion(AplicacionUsuario::Instalado);

    aplicacionUsuario.setEstadoLicencia(AplicacionUsuario::Activa);
    aplicacionUsuario.setFechaLicencia(QDate::currentDate());

    if (dbManager.aplicacionusuarioDao.actualizarRelacion(aplicacionUsuario)) {
        QMessageBox::information(this, "Éxito", "La aplicación ha sido instalada y su licencia activada correctamente.");
    } else {
        QMessageBox::critical(this, "Error", "No se pudo actualizar la instalación y la licencia.");
    }
}


void MainWindow::on_no_descargados_2_clicked()
{
        QModelIndex index = ui->lista_apps->currentIndex();
        if (!index.isValid()) {
            QMessageBox::warning(this, "Error", "Seleccione una aplicación para desinstalar.");
            return;
        }

        int idApp = index.data(Qt::UserRole).toInt();

        if (usuarioActualId <= 0) {
            QMessageBox::critical(this, "Error", "No se pudo obtener el ID del usuario.");
            return;
        }

        // Obtener la relación usuario-aplicación
        AplicacionUsuario aplicacionUsuario = dbManager.aplicacionusuarioDao.obtenerRelacionPorIds(usuarioActualId, idApp);

        if (aplicacionUsuario.getEstadoInstalacion() == AplicacionUsuario::NoInstalado) {
            QMessageBox::information(this, "Ya desinstalada", "La aplicación ya está desinstalada.");
            return;
        }

        // Cambiar el estado a NoInstalado
        aplicacionUsuario.setEstadoInstalacion(AplicacionUsuario::NoInstalado);
        if (dbManager.aplicacionusuarioDao.actualizarRelacion(aplicacionUsuario)) {
            QMessageBox::information(this, "Éxito", "La aplicación ha sido desinstalada correctamente.");
        } else {
            QMessageBox::critical(this, "Error", "No se pudo actualizar la desinstalación.");
        }
}
void MainWindow::mostrarNombreUsuario() {
    // 🔹 Obtener los datos del usuario desde la base de datos
    usuario usuario = dbManager.usuarioDao.obtenerUsuarioPorId(usuarioActualId);

    // 🔹 Actualizar el QLabel con el nombre del usuario
    ui->usuario_nombre->setText(usuario.getnombre());
}


