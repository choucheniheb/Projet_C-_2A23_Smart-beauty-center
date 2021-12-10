#include "service.h"
#include <QSqlQuery>



Service::Service (){}

Service::Service(QString nom_s,QString offre,QDate date_offre, float prix_s, float prix_offre , int code_s , QString disponibilite,int pt_f)
{

    this->nom_s = nom_s;

    this->offre  = offre;

    this->date_offre = date_offre ;

    this->prix_s = prix_s;

    this->prix_offre = prix_offre;

    this->code_s = code_s;

    this->disponibilite = disponibilite;
    this->pt_f=pt_f;


}

bool Service :: ajouter ()
{
    QSqlQuery  query ;
    QString res = QString :: number (code_s);
    QString res1 = QString :: number (prix_s);
    QString res2 = QString :: number (prix_offre);
    QString res3 = QString :: number (pt_f);
    query.prepare("insert into services(code_s,nom_s,prix_s,disponibilite,offre,date_offre,prix_offre,ptf_s) values(:code_s,:nom_s,:prix_s,:disponibilite,:offre,:date_offre,:prix_offre,:ptf_s)");

    //variables liees
    query.bindValue(":code_s",res);
    query.bindValue(":nom_s",nom_s);
    query.bindValue(":prix_s",res1);
    query.bindValue(":disponibilite",disponibilite);
    query.bindValue(":offre",offre);
    query.bindValue(":date_offre",date_offre);
    query.bindValue(":prix_offre",res2);
    query.bindValue(":ptf_s",res3);

    return query.exec();

}

QSqlQueryModel *  Service ::afficher ()
{

    QSqlQueryModel * model = new QSqlQueryModel ();
    model ->setQuery ("select *from services");
    model ->setHeaderData(0, Qt:: Horizontal ,QObject :: tr ("CODE_S"));
    model ->setHeaderData(1, Qt:: Horizontal ,QObject :: tr ("NOM_S"));
    model ->setHeaderData(2, Qt:: Horizontal ,QObject :: tr ("PRIX_S"));
    model ->setHeaderData(3, Qt:: Horizontal ,QObject :: tr ("DISPONIBILTE"));
    model ->setHeaderData(4, Qt:: Horizontal ,QObject :: tr ("OFFRE"));
    model ->setHeaderData(5, Qt:: Horizontal ,QObject :: tr ("DATE_OFFRE"));
    model ->setHeaderData(6, Qt:: Horizontal ,QObject :: tr ("PRIX_OFFRE"));

  return model ;
}



 bool  Service :: supprimer (int code_s)
{

    QSqlQuery query ;
    QString res= QString::number(code_s);
    query.prepare("DELETE FROM services WHERE code_s=:code_s");
    query.bindValue(":code_s",res);
    return query.exec();
}


 bool  Service :: modifier (int code_s)
 {

     QSqlQuery query;
     QString res = QString :: number (code_s);
     QString res1 = QString :: number (prix_s);
     QString res2 = QString :: number (prix_offre);
     query.prepare("UPDATE services SET nom_s= :nom_s,date_offre= :date_offre, prix_s= :prix_s, prix_offre= :prix_offre, disponibilite= :disponibilite where code_s= :code_s");
     query.bindValue(":code_s",res);
     query.bindValue(":nom_s",nom_s);
     query.bindValue(":offre",offre);
     query.bindValue(":date_offre",date_offre);
     query.bindValue(":prix_s",res1);
     query.bindValue(":prix_offre",res2);
     query.bindValue(":disponibilite",disponibilite);
     return query.exec();

 }






 QSqlQueryModel* Service::rechercheavancee(QString recherche){
     QSqlQueryModel* trouve = new QSqlQueryModel();

     trouve->setQuery("SELECT * FROM services WHERE CODE_S LIKE '"+recherche+"%' OR NOM_S LIKE '"+recherche+"%' OR OFFRE LIKE '"+recherche+"%'");
     trouve ->setHeaderData(0, Qt:: Horizontal ,QObject :: tr ("CODE_S"));
     trouve ->setHeaderData(1, Qt:: Horizontal ,QObject :: tr ("NOM_S"));
     trouve ->setHeaderData(2, Qt:: Horizontal ,QObject :: tr ("PRIX_S"));
     trouve ->setHeaderData(3, Qt:: Horizontal ,QObject :: tr ("DISPONIBILTE"));
     trouve ->setHeaderData(4, Qt:: Horizontal ,QObject :: tr ("OFFRE"));
     trouve ->setHeaderData(5, Qt:: Horizontal ,QObject :: tr ("DATE_OFFRE"));
     trouve ->setHeaderData(6, Qt:: Horizontal ,QObject :: tr ("PRIX_OFFRE"));

     return trouve;
 }
