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

    query.prepare("INSERT INTO caise(num_facture,date_D,prix_unitaire,quntiter,prix_totale) VALUES(:num_facture,:date,:prix_unitaire,:quntiter,:prix_totale)");
    query.bindValue(":num_facture",res);
    query.bindValue(":date_D",date);
    query.bindValue(":prix_unitaire",prix_unitaire);
    query.bindValue(":quntiter",quantiter);
    query.bindValue(":prix_totale",prix_totale);
    return query.exec();
}

//fonction afficher
QSqlQueryModel * caisse::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from caise");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("num_facture"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix_unitaire"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("quntiter"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("prix_totale"));
    return model;
}

//fonction supprimer
bool caisse::supprimer(int num_facture)
{
    QSqlQuery query;
    QString res = QString::number(num_facture);
    query.prepare("delete from caise where id= :id");
    query.bindValue(":id",res);
    return  query.exec();
}

bool caisse::modifier(int num_facture)
{
    QSqlQuery query;
    QString res = QString::number(num_facture);
    query.prepare("UPDATE caise SET date= :date, prix_unitaire= :prix_unitaire, quntiter= :quntiter,prix_totale= :prix_totale WHERE num_facture = :num_f");
    query.bindValue(":id",res);
    query.bindValue(":date",date);
    query.bindValue(":prix_unitaire",prix_unitaire);
    query.bindValue(":quntiter",quantiter);
    query.bindValue(":prix_totale",prix_totale);
    return query.exec();
}

