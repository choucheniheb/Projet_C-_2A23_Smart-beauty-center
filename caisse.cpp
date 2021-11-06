#include "caisse.h"

caisse::caisse()
{

}
//constructure
caisse::caisse(int num_facture,QDate date,float prix_unitair,int quantiter,float prix_totale)
{
    this->num_facture=num_facture;
    this->date=date;
    this->prix_unitaire=prix_unitair;
    this->quantiter=quantiter;
    this->prix_totale=prix_totale;
}
//fonction ajouter
bool caisse::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(num_facture);
    QString res2= QString::number(prix_unitaire);
    QString res3= QString::number(quantiter);
    QString res4= QString::number(prix_totale);

    query.prepare("insert into FACTURES(NUM_FACTURE,DATE_D,PRIX_UNITAIRE,QUANTITE,PRIX_TOTALE) values(:num_facture,:date,:prix_unitaire,:quantite,:prix_totale)");
    query.bindValue(":num_facture",res);
    query.bindValue(":date",date);
    query.bindValue(":prix_unitaire",res2);
    query.bindValue(":quantite",res3);
    query.bindValue(":prix_totale",res4);
    return query.exec();
}

//fonction afficher
QSqlQueryModel * caisse::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM factures");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM_FACTURE"));
    //model->setHeaderData(1,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRIX_UNITAIRE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("QUANTITE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX_TOTALE"));
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

bool caisse::modifier(int num_facture)
{
    QSqlQuery query;
    QString res = QString::number(num_facture);
    QString res2= QString::number(prix_unitaire);
    QString res3= QString::number(quantiter);
    QString res4= QString::number(prix_totale);
    query.prepare("UPDATE FACTURES SET DATE_D= :date, PRIX_UNITAIRE= :prix_unitaire, QUANTITE= :quntiter,PRIX_TOTALE= :prix_totale WHERE NUM_FACTURE = :num_facture");
    query.bindValue(":num_facture",res);
    query.bindValue(":date",date);
    query.bindValue(":prix_unitaire",res2);
    query.bindValue(":quntiter",res3);
    query.bindValue(":prix_totale",res4);
    return query.exec();
}

