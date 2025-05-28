#include "loggin.h"
#include "ui_loggin.h"
#include <QMessageBox>
#include <QDebug>
#include "databasemanager.h" // Asegúrate de que esto esté incluido
#include "usuario.h"         // Asegúrate de que esto esté incluido
#include "usuariodao.h"      // Asegúrate de que esto esté incluido, aunque DatabaseManager lo contiene, es buena práctica.

loggin::loggin(QWidget *parent)
    // IMPORTANTISIMO: Si quieres usar exec(), loggin DEBE HEREDAR de QDialog, no QMainWindow
    // Si necesitas que sea una ventana principal con barra de menú, etc., entonces NO uses exec()
    // Si ya lo cambiaste a QDialog, esta línea debería ser: : QDialog(parent)
    : QMainWindow(parent) // <--- VERIFICA ESTO EN TU loggin.h Y CÁMBIALO A QDialog SI LO QUIERES MODAL
    , ui(new Ui::loggin)
{
    ui->setupUi(this);

    // Conectar botones usando los nombres correctos de los widgets de tu .ui
    // Asumo que tienes QLineEdit con objectName "usuario" y "contrasena"
    // y QPushButton con objectName "iniciar" y "registrar".
    connect(ui->iniciar, &QPushButton::clicked, this, &loggin::on_iniciar_clicked);
    connect(ui->registrar, &QPushButton::clicked, this, &loggin::on_registrar_clicked);
    // Asumo que tienes un botón de eliminar. Si no, puedes quitar esta línea.
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

    // Usar el DAO para verificar credenciales
    if (DatabaseManager::instance().usuarioDao.verificarCredenciales(nombre, contrasena)) {
        QMessageBox::information(this, "Inicio de Sesión", "¡Inicio de sesión exitoso!");
        // Aquí podrías emitir una señal o llamar a accept() si loggin es un QDialog
        // Si loggin es un QDialog:
        // accept();
        // Si loggin es un QMainWindow y quieres ocultarla y mostrar la MainWindow:
        // this->hide();
        // MainWindow *mainWindow = new MainWindow(); // O pasar el usuario loggeado
        // mainWindow->show();
    } else {
        QMessageBox::critical(this, "Error de Inicio de Sesión", "Nombre de usuario o contraseña incorrectos.");
    }
}

void loggin::on_registrar_clicked()
{
    QString nombre = ui->usuario->text();
    QString contrasena = ui->contrasena->text();


    // **Paso 1: Validar longitud del nombre y contraseña (según tu clase usuario)**
    // Asumo que los setters de 'usuario' ya validan esto.
    usuario nuevoUsuario(nombre, contrasena,0); // ID -1 para nuevo usuario (se generará en la DB)

    if (!nuevoUsuario.setnombre(nombre)) {
        QMessageBox::warning(this, "Error de Registro", "El nombre de usuario no cumple con los requisitos de longitud (6-30 caracteres).");
        return;
    }
    if (!nuevoUsuario.setcontrasena(contrasena)) {
        QMessageBox::warning(this, "Error de Registro", "La contraseña no cumple con los requisitos de longitud (6-30 caracteres).");
        return;
    }

    // **Paso 2: Verificar si el nombre de usuario ya existe en la base de datos**
    usuario usuarioExistente = DatabaseManager::instance().usuarioDao.obtenerUsuarioPorNombre(nombre);

    if (usuarioExistente.getid() != -1) {
        // Si getid() es diferente de -1, significa que un usuario con ese nombre ya existe.
        QMessageBox::warning(this, "Error de Registro", "El nombre de usuario '" + nombre + "' ya existe. Por favor, elige otro.");
        return; // Detener el proceso de registro
    }

    // **Paso 3: Si el nombre de usuario no existe, proceder con el registro**
    // No necesitamos const_cast aquí porque hemos quitado 'const' de usuarioDao en DatabaseManager.h
    if (DatabaseManager::instance().usuarioDao.guardarUsuario(nuevoUsuario)) {
        QMessageBox::information(this, "Registro Exitoso", "Usuario '" + nombre + "' registrado correctamente.");
        // Opcional: Limpiar los campos después de un registro exitoso
        ui->usuario->clear();
        ui->contrasena->clear();
    } else {
        QMessageBox::critical(this, "Error de Registro", "No se pudo registrar el usuario. Consulte el log para más detalles.");
        // DatabaseManager::debugQuery(una_consulta_aqui_si_hubiera_una_específica_del_error);
    }
}

void loggin::on_eliminar_clicked()
{
    QString nombreAEliminar = ui->usuario->text(); // Asumiendo 'usuario' es el QLineEdit para el nombre de usuario

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
            // Ya no es necesario const_cast si has quitado 'const' de usuarioDao en DatabaseManager.h
            // usuariodao& dao = const_cast<usuariodao&>(DatabaseManager::instance().usuarioDao);
            if (DatabaseManager::instance().usuarioDao.eliminarUsuario(userToDelete.getid())) {
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
