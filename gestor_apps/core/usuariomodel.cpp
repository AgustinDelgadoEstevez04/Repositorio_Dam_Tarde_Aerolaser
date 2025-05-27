#include "usuariomodel.h"

UsuarioModel::UsuarioModel(const usuario& usr, QObject* parent) : QObject(parent), mUsuario(usr) {}

int UsuarioModel::id() const {
    return mUsuario.getid();
}

QString UsuarioModel::nombre() const {
    return mUsuario.getnombre();
}

QString UsuarioModel::contraseña() const {
    return mUsuario.getcontraseña();
}

void UsuarioModel::actualizarUsuario(const usuario& usr) {
    mUsuario = usr;
    emit usuarioActualizado();
}


