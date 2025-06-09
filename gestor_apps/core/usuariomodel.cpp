#include "usuariomodel.h"
#include "databasemanager.h"
UsuarioModel::UsuarioModel(const usuario& usr, QObject* parent) : QObject(parent), mUsuario(usr) {}

int UsuarioModel::id() const {
    return mUsuario.getid();
}

QString UsuarioModel::nombre() const {
    return mUsuario.getnombre();
}

QString UsuarioModel::contrasena() const {
    return mUsuario.getcontrasena();
}

void UsuarioModel::actualizarDesdeDAO() {
    usuario nuevoUsuario = DatabaseManager::instance().usuarioDao.obtenerUsuarioPorId(mUsuario.getid());
    mUsuario = nuevoUsuario;
    emit usuarioActualizado();
}

QString UsuarioModel::avatar() const {
    return mUsuario.getAvatar();
}


