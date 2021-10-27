#include "service.h"
#include <QSqlQuery>

Service:: Service(QString nom_s,QString offre,QString date_offre, float prix_s, float prix_offre , int code , bool disponibilite)
{

    this->nom_s = nom_s;

    this->offre  = offre;

    this->date_offre = date_offre;

    this->prix_s = prix_s;

    this->prix_offre = prix_offre;

    this->code = code;

    this->disponibilite = disponibilite;


}

bool Service :: ajouter ()
{
    QSqlQuery  query ;
    QString res = QString :: number (code);

    query.prepare("insert into service (  nom_s , offre , date_offre , prix_s , prix_offre , code , disponibilite)""values  (:nom_s , :offre ,:date_offre ,:prix_s ,:prix_offre ,:code ,:disponibilite) ");

    //variables liees
    query.bindValue(": nom_s",nom_s);
    query.bindValue(": offre",offre);
    query.bindValue(": date_offre",date_offre);
    query.bindValue(": prix_s",prix_s);
    query.bindValue(": prix_offre",prix_offre);
    query.bindValue(": code ",res);
    query.bindValue(": disponibilite",disponibilite);

    return query.exec();

}

QSqlQueryModel *  Service ::afficher ()
{

    QSqlQueryModel * model = new QSqlQueryModel ();
    model ->setQuery ("select *from service");
    model ->setHeaderData(0, Qt:: Horizontal ,QObject :: tr ("nom_s"));
    model ->setHeaderData(1, Qt:: Horizontal ,QObject :: tr ("offre"));
    model ->setHeaderData(2, Qt:: Horizontal ,QObject :: tr ("date_offre"));
    model ->setHeaderData(3, Qt:: Horizontal ,QObject :: tr ("prix_s"));
    model ->setHeaderData(4, Qt:: Horizontal ,QObject :: tr ("prix_offre"));
    model ->setHeaderData(5, Qt:: Horizontal ,QObject :: tr ("code"));
    model ->setHeaderData(6, Qt:: Horizontal ,QObject :: tr ("disponibilite"));


}



 bool  Service :: supprimer (int code)
{

    QSqlQuery query ;
    QString res = QString::number(code);
    query.prepare("delete from service where code= :code");
    query.bindValue(":code",res);
    return  query.exec();

}


 bool  Service :: modifier (int code)
 {

     QSqlQuery query;
     QString res = QString::number(code);
     query.prepare("UPDATE service SET nom_s = :nom_s, offre= :offre , date_offre= :date_offre ,prix_s = :prix_s , prix_offre =: prix_offre , disponibilite =: disponibilite  WHERE code = :code");
     query.bindValue(":code",res);
     query.bindValue(":nom_s",nom_s);
     query.bindValue(":offre",offre);
     query.bindValue(":date_offre",date_offre);
     query.bindValue(":prix_s",prix_s);
     query.bindValue(":prix_offre",prix_offre);
     query.bindValue(":disponibilite",disponibilite);
     return query.exec();

 }
