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


}

loggin::~loggin()
{
    delete ui;
}

void loggin::on_iniciar_clicked()
{
    QString nombre = ui->usuario->text().trimmed(); // trimmed() elimina espacios en blanco
    QString contrasena = ui->contrasena->text();

    // Validación de campos vacíos
    if (nombre.isEmpty()) {
        QMessageBox::warning(this, "Error de Inicio de Sesión", "El nombre de usuario es obligatorio.");
        ui->usuario->setFocus(); // Poner foco en el campo usuario
        return;
    }

    if (contrasena.isEmpty()) {
        QMessageBox::warning(this, "Error de Inicio de Sesión", "La contraseña es obligatoria.");
        ui->contrasena->setFocus(); // Poner foco en el campo contraseña
        return;
    }

    // Validación adicional de longitud mínima de contraseña
    if (contrasena.length() < 6) {
        QMessageBox::warning(this, "Error de Inicio de Sesión", "La contraseña debe tener al menos 6 caracteres.");
        ui->contrasena->setFocus();
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
    QString nombre = ui->usuario->text().trimmed(); // trimmed() elimina espacios en blanco
    QString contrasena = ui->contrasena->text();

    // Validación de campos vacíos
    if (nombre.isEmpty()) {
        QMessageBox::warning(this, "Error de Registro", "El nombre de usuario es obligatorio.");
        ui->usuario->setFocus();
        return;
    }

    if (contrasena.isEmpty()) {
        QMessageBox::warning(this, "Error de Registro", "La contraseña es obligatoria.");
        ui->contrasena->setFocus();
        return;
    }

    // Validaciones adicionales de seguridad para contraseña
    if (contrasena.length() < 6) {
        QMessageBox::warning(this, "Error de Registro", "La contraseña debe tener al menos 6 caracteres.");
        ui->contrasena->setFocus();
        return;
    }

    if (contrasena.length() > 30) {
        QMessageBox::warning(this, "Error de Registro", "La contraseña no puede tener más de 30 caracteres.");
        ui->contrasena->setFocus();
        return;
    }

    // Validación adicional: contraseña no puede ser solo espacios
    if (contrasena.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Error de Registro", "La contraseña no puede contener solo espacios en blanco.");
        ui->contrasena->setFocus();
        return;
    }

    // Validación opcional: contraseña debe contener al menos un carácter que no sea espacio
    bool tieneCaracterValido = false;
    for (const QChar &c : contrasena) {
        if (!c.isSpace()) {
            tieneCaracterValido = true;
            break;
        }
    }

    if (!tieneCaracterValido) {
        QMessageBox::warning(this, "Error de Registro", "La contraseña debe contener al menos un carácter válido.");
        ui->contrasena->setFocus();
        return;
    }

    usuario nuevoUsuario(nombre, contrasena, 0); // ID 0 para nuevo usuario (se generará en la DB)

    if (!nuevoUsuario.setnombre(nombre)) {
        QMessageBox::warning(this, "Error de Registro", "El nombre de usuario no cumple con los requisitos de longitud (6-30 caracteres).");
        ui->usuario->setFocus();
        return;
    }
    if (!nuevoUsuario.setcontrasena(contrasena)) {
        QMessageBox::warning(this, "Error de Registro", "La contraseña no cumple con los requisitos de longitud (6-30 caracteres).");
        ui->contrasena->setFocus();
        return;
    }

    // **Paso 2: Verificar si el nombre de usuario ya existe en la base de datos**
    usuario usuarioExistente = DatabaseManager::instance().usuarioDao.obtenerUsuarioPorNombre(nombre);

    if (usuarioExistente.getid() != -1) {
        QMessageBox::warning(this, "Error de Registro", "El nombre de usuario '" + nombre + "' ya existe. Por favor, elige otro.");
        ui->usuario->setFocus();
        return; // Detener el proceso de registro
    }

    // **Paso 3: Si el nombre de usuario no existe, proceder con el registro**
    if (DatabaseManager::instance().usuarioDao.guardarUsuario(nuevoUsuario)) {
        QMessageBox::information(this, "Registro Exitoso", "Usuario '" + nombre + "' registrado correctamente.");
        // Opcional: Limpiar los campos después de un registro exitoso
        ui->usuario->clear();
        ui->contrasena->clear();
        ui->usuario->setFocus(); // Volver a poner foco en usuario para nuevo registro
    } else {
        QMessageBox::critical(this, "Error de Registro", "No se pudo registrar el usuario. Consulte el log para más detalles.");
    }
}

void loggin::on_eliminar_clicked()
{
    QString nombreAEliminar = ui->usuario->text().trimmed(); // Eliminar espacios en blanco
    QString contrasena = ui->contrasena->text();

    if (nombreAEliminar.isEmpty()) {
        QMessageBox::warning(this, "Error", "Ingresa un nombre de usuario para eliminar.");
        ui->usuario->setFocus();
        return;
    }

    // NUEVO: Hacer que la contraseña sea obligatoria también para eliminar (seguridad adicional)
    if (contrasena.isEmpty()) {
        QMessageBox::warning(this, "Error", "Ingresa la contraseña del usuario para confirmar la eliminación.");
        ui->contrasena->setFocus();
        return;
    }

    // Primero, verificar que las credenciales sean correctas antes de eliminar
    if (!DatabaseManager::instance().usuarioDao.verificarCredenciales(nombreAEliminar, contrasena)) {
        QMessageBox::critical(this, "Error", "Credenciales incorrectas. No se puede eliminar el usuario.");
        return;
    }

    // Obtener el usuario por nombre para obtener su ID
    usuario userToDelete = DatabaseManager::instance().usuarioDao.obtenerUsuarioPorNombre(nombreAEliminar);

    if (userToDelete.getid() != -1) { // Si se encuentra el usuario
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmar Eliminación",
                                      "¿Estás seguro de que quieres eliminar a " + nombreAEliminar + "?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            if (DatabaseManager::instance().usuarioDao.eliminarUsuario(userToDelete.getid())) {
                QMessageBox::information(this, "Eliminado", "Usuario eliminado correctamente.");
                // Opcional: Limpiar los campos después de eliminar
                ui->usuario->clear();
                ui->contrasena->clear();
                ui->usuario->setFocus();
            } else {
                QMessageBox::critical(this, "Error al Eliminar", "No se pudo eliminar el usuario. Consulte el log para más detalles.");
            }
        }
    } else {
        QMessageBox::warning(this, "No Encontrado", "El usuario '" + nombreAEliminar + "' no está registrado.");
    }
}
