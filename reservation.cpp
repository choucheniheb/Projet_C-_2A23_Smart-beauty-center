#include "reservation.h"
Reservation::Reservation()
{

}
//constructure
Reservation :: Reservation(QString  id_c,QString code_s,QString em_c,QDateTime date_r)
{
 this->id_c=id_c;
 this->code_s=code_s;
 this->em_c=em_c;
 this->date_r=date_r;

}
//fonction ajouter
bool Reservation::ajouter()
{
    QSqlQuery query;
    QSqlQuery query1;
    query.prepare("insert into RESERVER(id_c,code_s,em_c,date_r) values(:id_c,:code_s,:em_c,:date_r)");
    query.bindValue(":id_c",id_c);
    query.bindValue(":code_s",code_s);
    query.bindValue(":em_c",em_c);
    query.bindValue(":date_r",date_r);


    query1.prepare("select ptf_s from services where code_s= :code_s");
    query1.bindValue(":code_s",code_s);
    query1.exec();
    query1.next();
    int ptf_s=query1.value(0).toInt();
    query1.prepare("select point_fidelite from client where id_c= :id_c");
    query1.bindValue(":id_c",id_c);
    query1.exec();
    query1.next();
    int point_f=query1.value(0).toInt()+ptf_s;
    query1.prepare("update client set point_fidelite= :point_fidelite where id_c= :id_c");
    query1.bindValue(":point_fidelite",point_f);
    query1.bindValue(":id_c",id_c);
    query1.exec();
    return query.exec();
}

//fonction afficher
QSqlQueryModel * Reservation::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM RESERVER");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("date_r"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_c"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("cod_s"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("em_c"));

    return model;
}

//fonction supprimer
bool Reservation::supprimer(QString id_c)
{
    QSqlQuery query;
    query.prepare("DELETE FROM RESERVER WHERE id_c= :id_c");
    query.bindValue(":id_c",id_c);
    return  query.exec();
}

