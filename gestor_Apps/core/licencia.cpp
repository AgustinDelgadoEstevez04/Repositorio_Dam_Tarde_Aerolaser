#include "licencia.h"

licencia::licencia(int id, int appId, int userId, Estado estado, const QDate& fechaInicio, const QDate& fechaFin)
    : m_id(id), m_appId(appId), m_userId(userId), m_estado(estado), m_fechaInicio(fechaInicio), m_fechaFin(fechaFin) {}

int licencia::id()const {
    return m_id;
}

int licencia::appId()const{
    return m_appId;
}

int licencia::userId()const{
    return m_userId;
}

licencia::Estado licencia::estado() const{
    return m_estado;
}

QDate licencia::fechaInicio()const{
    return m_fechaInicio;
}

QDate licencia::fechaFin()const{
    return m_fechaFin;
}

QString licencia::estadoToString() const{
    switch (m_estado) {
    case Activa:
        return "activa";
        break;
    case Caducada:
        return "caducada";
        break;
    case Proximaacaducar:
        return "proxima a caducar";
        break;
    default:
        return "desconocido";
        break;
    }
}

bool licencia::estaActiva()const{
    return m_estado==Activa;
}

bool licencia::estaCaducada()const{
    return QDate::currentDate()>m_fechaFin;
}

bool licencia::estaProximaACaducar()const{
    estaCaducada() && QDate::currentDate().addDays(7)>=m_fechaFin;
}

