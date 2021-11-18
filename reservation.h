#ifndef RESERVATION_H
#define RESERVATION_H
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
#include <QDateTime>

class Reservation
{
public:
    Reservation();
    Reservation(QString,QString,QString,QDateTime);
    bool  ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString id);
    bool modifier(QString Id_c);



private:
    QString id_c,code_s,em_c;
    QDateTime date_r;


};

#endif // RESERVATION_H
