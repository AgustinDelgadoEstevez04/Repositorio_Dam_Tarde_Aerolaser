#include "loggin.h"
#include "ui_loggin.h"
#include <QMessageBox>
#include <QDebug>
#include "usuariomodel.h" // Incluimos UsuarioModel por si se quiere instanciar después de un login exitoso

loggin::loggin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loggin)
{
    ui->setupUi(this);

    // Conectar botones usando los nombres correctos de los widgets de tu .ui
    connect(ui->iniciar, &QPushButton::clicked, this, &loggin::on_iniciar_clicked);
    connect(ui->registrar, &QPushButton::clicked, this, &loggin::on_registrar_clicked);
    connect(ui->eliminar, &QPushButton::clicked, this, &loggin::on_eliminar_clicked);
}

loggin::~loggin()
{
    delete ui;
}

void loggin::on_iniciar_clicked()
{
    QString nombre = ui->usuario->text();
    QString contrasena = ui->contrasena->text();

    if (nombre.isEmpty() || contrasena.isEmpty()) {
        QMessageBox::warning(this, "Error de Inicio de Sesión", "Por favor, ingresa nombre de usuario y contraseña.");
        return;
    }

    // Usar el DAO para verificar credenciales (obtenerUsuarioPorNombre y verificarCredenciales son const)
    if (DatabaseManager::instance().usuarioDao.verificarCredenciales(nombre, contrasena)) {
        QMessageBox::information(this, "Inicio de Sesión Exitoso", "¡Bienvenido, " + nombre + "!");

        // OPCIONAL: Si necesitas un UsuarioModel para el usuario logeado
        // Por ejemplo, para pasarlo a otra ventana o a un contexto de QML.
        // Aquí solo se crea, no se mantiene como miembro de loggin.
        usuario loggedInUser = DatabaseManager::instance().usuarioDao.obtenerUsuarioPorNombre(nombre);
        if (loggedInUser.getid() != -1) {
            UsuarioModel* userModel = new UsuarioModel(loggedInUser, this); // 'this' como parent para que se elimine con la ventana
            qDebug() << "UsuarioModel creado para:" << userModel->nombre();
            // Aquí podrías emitir una señal para que la ventana principal lo reciba,
            // o abrir una nueva ventana y pasarle userModel.
            // Ejemplo: MainWindow* mainWindow = new MainWindow(userModel); mainWindow->show();
            // close(); // Cerrar la ventana de login
        } else {
            qDebug() << "Error: Usuario logeado no encontrado después de verificar credenciales.";
        }
    } else {
        QMessageBox::critical(this, "Error de Inicio de Sesión", "Nombre de usuario o contraseña incorrectos.");
    }
}

void loggin::on_registrar_clicked()
{
    QString nombre = ui->usuario->text();
    QString contrasena = ui->contrasena->text();

    if (nombre.isEmpty() || contrasena.isEmpty()) {
        QMessageBox::warning(this, "Error de Registro", "Por favor, ingresa nombre de usuario y contraseña.");
        return;
    }

    // Verificar si el nombre de usuario ya existe
    usuario existingUser = DatabaseManager::instance().usuarioDao.obtenerUsuarioPorNombre(nombre);
    if (existingUser.getid() != -1) {
        QMessageBox::warning(this, "Error de Registro", "El nombre de usuario ya existe. Por favor, elige otro.");
        return;
    }

    // Crear un nuevo objeto usuario (id puede ser -1 para auto-incremento en la DB)
    usuario nuevoUsuario(nombre, contrasena, -1);

    // Validar longitud del nombre de usuario y contraseña usando los setters de la clase usuario
    bool nombreValido = nuevoUsuario.setnombre(nombre);
    bool contrasenaValida = nuevoUsuario.setcontrasena(contrasena);

    if (!nombreValido) {
        QMessageBox::warning(this, "Error de Registro", "El nombre debe tener entre 6 y 30 caracteres.");
        return;
    }
    if (!contrasenaValida) {
        QMessageBox::warning(this, "Error de Registro", "La contraseña debe tener entre 6 y 30 caracteres.");
        return;
    }

    // Guardar el nuevo usuario en la base de datos
    // Se usa const_cast porque 'guardarUsuario' modifica la DB y DatabaseManager::instance() devuelve una referencia const
    usuariodao& dao = const_cast<usuariodao&>(DatabaseManager::instance().usuarioDao);
    if (dao.guardarUsuario(nuevoUsuario)) {
        QMessageBox::information(this, "Registro Exitoso", "Usuario registrado correctamente.");
        // Opcional: Limpiar los campos después del registro
        ui->usuario->clear();
        ui->contrasena->clear();
    } else {
        QMessageBox::critical(this, "Error de Registro", "No se pudo registrar el usuario. Consulte el log para más detalles.");
    }
}

void loggin::on_eliminar_clicked()
{
    QString nombreAEliminar = ui->usuario->text();

    if (nombreAEliminar.isEmpty()) {
        QMessageBox::warning(this, "Error", "Ingresa un nombre de usuario para eliminar.");
        return;
    }

    // Primero, obtener el usuario por nombre para obtener su ID
    usuario userToDelete = DatabaseManager::instance().usuarioDao.obtenerUsuarioPorNombre(nombreAEliminar);

    if (userToDelete.getid() != -1) { // Si se encuentra el usuario
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmar Eliminación",
                                      "¿Estás seguro de que quieres eliminar a " + nombreAEliminar + "?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            // Se usa const_cast porque 'eliminarUsuario' modifica la DB
            usuariodao& dao = const_cast<usuariodao&>(DatabaseManager::instance().usuarioDao);
            if (dao.eliminarUsuario(userToDelete.getid())) {
                QMessageBox::information(this, "Eliminado", "Usuario eliminado correctamente.");
                // Opcional: Limpiar los campos después de eliminar
                ui->usuario->clear();
                ui->contrasena->clear();
            } else {
                QMessageBox::critical(this, "Error al Eliminar", "No se pudo eliminar el usuario. Consulte el log para más detalles.");
            }
        }
    } else {
        QMessageBox::warning(this, "No Encontrado", "El usuario '" + nombreAEliminar + "' no está registrado.");
    }
}
