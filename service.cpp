#include "service.h"
#include <QSqlQuery>



Service::Service (){}

Service::Service(QString nom_s,QString offre,QDate date_offre, float prix_s, float prix_offre , int code_s , bool disponibilite)
{

    this->nom_s = nom_s;

    this->offre  = offre;

    this->date_offre = date_offre ;

    this->prix_s = prix_s;

    this->prix_offre = prix_offre;

    this->code_s = code_s;

    this->disponibilite = disponibilite;


}

bool Service :: ajouter ()
{
    QSqlQuery  query ;
    QString res = QString :: number (code_s);
    QString res1 = QString :: number (prix_s);
    QString res2 = QString :: number (prix_offre);
    QString res3 = QString :: number (disponibilite);
    query.prepare("insert into services(code_s,nom_s,prix_s,disponibilite,offre,date_offre,prix_offre) values(:code_s,:nom_s,:prix_s,:disponibilite,:offre,:date_offre,:prix_offre)");

    //variables liees
    query.bindValue(":code_s",res);
    query.bindValue(":nom_s",nom_s);
    query.bindValue(":prix_s",res1);
    query.bindValue(":disponibilite",res3);
    query.bindValue(":offre ",offre);
    query.bindValue(":date_offre",date_offre);
    query.bindValue(":prix_offre",res2);

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
    model ->setHeaderData(5, Qt:: Horizontal ,QObject :: tr ("code_s"));
    model ->setHeaderData(6, Qt:: Horizontal ,QObject :: tr ("disponibilite"));

  return model ;
}



 bool  Service :: supprimer (int code_s)
{

    QSqlQuery query ;
    QString res = QString::number(code_s);
    query.prepare("delete from services where code_s = :code_s");
    query.bindValue(":code_s",res);
    return  query.exec();

}


 bool  Service :: modifier (int code)
 {

     QSqlQuery query;
     QString res = QString::number(code);
     query.prepare("UPDATE services SET nom_s= :nom_s, offre= :offre, date_offre= :date_offre, prix_s= :prix_s, prix_offre= :prix_offre, disponibilite= :disponibilite where code_s= :code_s");
     query.bindValue(":code_s",res);
     query.bindValue(":nom_s",nom_s);
     query.bindValue(":offre",offre);
     query.bindValue(":date_offre",date_offre);
     query.bindValue(":prix_s",prix_s);
     query.bindValue(":prix_offre",prix_offre);
     query.bindValue(":disponibilite",disponibilite);
     return query.exec();

 }
