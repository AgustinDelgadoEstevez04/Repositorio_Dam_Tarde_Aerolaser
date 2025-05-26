#ifndef LICENCIA_H
#define LICENCIA_H
#include<QDate>

class licencia
{
public:
    enum Estado{Activa=1, Caducada=2, Proximaacaducar=3};
    licencia(int id = -1, int appId = -1, int userId = -1,
             Estado estado = Caducada, const QDate& fechaInicio = QDate(),
             const QDate& fechaFin = QDate());

    int id() const;
    int appId() const;
    int userId() const;
    Estado estado() const;
    QDate fechaInicio() const;
    QDate fechaFin() const;
    QString estadoToString() const;

    bool estaActiva() const;
    bool estaCaducada() const;
    bool estaProximaACaducar() const;

private:
    int m_id;
    int m_appId;
    int m_userId;
    Estado m_estado;
    QDate m_fechaInicio;
    QDate m_fechaFin;
};

#endif // LICENCIA_H
