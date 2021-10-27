#include "employers.h"
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

Employers::Employers(){}
Employers::Employers(int id,QString nom, QString prenom,QDate date_naissance,QString adresse,int telephone,QString type, QString specialite)
{
this->id=id;
this->nom=nom;
this->prenom=prenom;
this->date_naissance=date_naissance;
this->adresse=adresse;
this->telephone=telephone;
this->type=type;
this->specialite=specialite;
}
bool Employers::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("insert into employes(id,nom,prenom, date_naissance, adresse,telephone,type,specialite) values(:id,:nom,:prenom, :date_naissance, :adresse,:telephone,:type,:specialite)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date_naissance",date_naissance);
    query.bindValue(":adresse",adresse);
    query.bindValue(":telephone",telephone);
    query.bindValue(":type",type);
    query.bindValue(":specialite",specialite);
    return query.exec();
}
QSqlQueryModel * Employers::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employes");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("telephone"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("specialite"));
}
bool Employers::supprimer(int)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("delete from employes where id= :id");
    query.bindValue(":id",res);
    return  query.exec();
}

bool Employers::modifier(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("UPDATE employes SET nom= :nom, prenom= :prenom,date_naissance= :date_naissance,adresse= :adresse,telephone= :telephone, type= :type, specialite= :specialite WHERE id = :id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date_naissance",date_naissance);
    query.bindValue(":adresse",adresse);
    query.bindValue(":telephone",telephone);
    query.bindValue(":type",type);
    query.bindValue(":specialite",specialite);
    return query.exec();
}


/*
caise::caise(){}
//constructeur
caise::caise(int num_facture,QDate date,float prix_unitair,int quntiter,float prix_totale)
{
    this->num_facture=num_facture;
    this->date=date;
    this->prix_unitaire=prix_unitair;
    this->quntiter=quntiter;
    this->prix_totale=prix_totale;
}
//fonction ajouter
bool caise::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(num_facture);

    query.prepare("insert into caise(num_facture,date_D,prix_unitaire,quntiter,prix_totale) values(:num_facture,:date,:prix_unitaire,:quntiter,:prix_totale)");
    query.bindValue(":num_facture",res);
    query.bindValue(":date_D",date);
    query.bindValue(":prix_unitaire",prix_unitaire);
    query.bindValue(":quntiter",quntiter);
    query.bindValue(":prix_totale",prix_totale);
    return query.exec();
}
//fonction afficher
QSqlQueryModel * caise::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from caise");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("num_facture"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix_unitaire"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("quntiter"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("prix_totale"));
}
//fonction supprimer
bool caise::supprimer(int num_facture)
{
    QSqlQuery query;
    QString res = QString::number(num_facture);
    query.prepare("delete from caise where id= :id");
    query.bindValue(":id",res);
    return  query.exec();
}
//fonction modifier
bool caise::modifier(int num_f)
{
    QSqlQuery query;
    QString res = QString::number(num_facture);
    query.prepare("UPDATE caise SET date= :date, prix_unitaire= :prix_unitaire, quntiter= :quntiter,prix_totale= :prix_totale WHERE num_facture = :num_f");
    query.bindValue(":id",res);
    query.bindValue(":date",date);
    query.bindValue(":prix_unitaire",prix_unitaire);
    query.bindValue(":quntiter",quntiter);
    query.bindValue(":prix_totale",prix_totale);
    return query.exec();
}
 */
