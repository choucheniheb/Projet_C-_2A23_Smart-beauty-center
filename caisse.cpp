#include "caisse.h"
#include<QDebug>
caisse::caisse()
{

}
//constructure
caisse::caisse(int num_facture,QDate date_delevrance,float prix_unitair,int quantiter,float prix_totale,int id_c)
{
    this->num_facture=num_facture;
    this->date_delevrance=date_delevrance;
    this->prix_unitaire=prix_unitair;
    this->quantiter=quantiter;
    this->prix_totale=prix_totale;
    this->id_c=id_c;
}
//fonction ajouter
bool caisse::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(num_facture);
    QString res2= QString::number(prix_unitaire);
    QString res3= QString::number(quantiter);
    QString res4= QString::number(prix_totale);
    QString res5= QString::number(id_c);

   query.prepare("insert into FACTURES(NUM_FACTURE,DATE_D,PRIX_UNITAIRE,QUANTITE_F,PRIX_TOTALE,ID_C) values(:num_facture,:date,:prix_unitaire,:quantite,:prix_totale,:id_c)");
    query.bindValue(":num_facture",res);
    query.bindValue(":date",date_delevrance);
    query.bindValue(":id_c",res5);
    query.bindValue(":prix_unitaire",res2);
    query.bindValue(":quantite",res3);
    query.bindValue(":prix_totale",res4);
    return query.exec();
}

//fonction afficher
QSqlQueryModel * caisse::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from FACTURES");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM_FACTURE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRIX_UNITAIRE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_D"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE_F"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX_TOTALE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ID_C"));
    return model;
}

//fonction supprimer
bool caisse::supprimer(int num_facture)
{
    QSqlQuery query;
    QString res = QString::number(num_facture);
    query.prepare("DELETE FROM FACTURES WHERE NUM_FACTURE= :num_facture");
    query.bindValue(":num_facture",res);
    return  query.exec();
}

//modifier****************
bool caisse::modifier(int num_facture)
{
    QSqlQuery query;
    QString res = QString::number(num_facture);
    QString res2= QString::number(prix_unitaire);
    QString res3= QString::number(quantiter);
    QString res4= QString::number(prix_totale);
    query.prepare("UPDATE FACTURES SET DATE_D= :date, PRIX_UNITAIRE= :prix_unitaire, QUANTITE_F= :quntiter,PRIX_TOTALE= :prix_totale WHERE NUM_FACTURE = :num_facture");
    query.bindValue(":num_facture",res);
    query.bindValue(":date",date_delevrance);
    query.bindValue(":prix_unitaire",res2);
    query.bindValue(":quntiter",res3);
    query.bindValue(":prix_totale",res4);
    return query.exec();
}



//tri**********************************************************************
QSqlQueryModel * caisse::triParId()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from FACTURES ORDER BY CAST(num_facture AS number)");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM_FACTURE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRIX_UNITAIRE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_D"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE_F"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX_TOTALE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ID_C"));
    return model;
}
QSqlQueryModel * caisse::triParDate()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from FACTURES ORDER BY CAST(date_d as TIMESTAMP) desc");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM_FACTURE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRIX_UNITAIRE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_D"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE_F"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX_TOTALE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ID_C"));
    return model;
}
QSqlQueryModel * caisse::triParPrix()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from FACTURES ORDER BY CAST(prix_totale AS float) desc");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM_FACTURE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRIX_UNITAIRE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_D"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE_F"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX_TOTALE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ID_C"));
    return model;
}
//calculer recette**********************************************
QSqlQuery caisse::calculerecette()
{
    QSqlQuery query;
    QDate date=QDate::currentDate();
    query.prepare("SELECT SUM(prix_totale) FROM factures where date_d= :date_d");
    query.bindValue(":date_d",date);
    return query;
}


//rechercher*****************************
QSqlQueryModel* caisse::rechercheMulticritere(QString recherche)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM FACTURES WHERE NUM_FACTURE LIKE '"+recherche+"%' OR DATE_D LIKE '"+recherche+"%' OR PRIX_TOTALE LIKE '"+recherche+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM_FACTURE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRIX_UNITAIRE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_D"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE_F"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX_TOTALE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ID_C"));
    return model;
}
