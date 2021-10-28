#include "fournisseur.h"
#include <QSqlQuery>
#include <QString>
#include<QSqlQueryModel>
fournisseur::fournisseur(){}
fournisseur::fournisseur(int num_f,int code_f,float prix_gros,QString nom_f,QString produit_vendu)
{
   this-> num_f=num_f;
   this-> code_f=code_f;
   this-> prix_gros=prix_gros;
   this-> nom_f=nom_f;
   this-> produit_vendu=produit_vendu;

}

//getters
int fournisseur::getnum_f() {return num_f;}
int fournisseur::getcode_f() {return code_f;}
float fournisseur::getprix_gros() {return prix_gros;}
QString fournisseur::getnom_f() {return nom_f;}
QString fournisseur::getproduit_vendu() {return produit_vendu;}

//setters
void fournisseur::setnum_f(int num_f){this->num_f=num_f;}
void fournisseur::setcode_f(int code_f){this->code_f=code_f;}
void fournisseur::setprix_gros(float prix_gros){this->prix_gros=prix_gros;}
void fournisseur::setnom_f(QString nom_f){this->nom_f=nom_f;}
void fournisseur::setproduit_vendu(QString produit_vendu){this->produit_vendu=produit_vendu;}

//fonction ajouter
bool fournisseur::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(num_f);

    query.prepare("insert into caise(int num_f,int code_f,float prix_gros,QString nom_f,QString produit_vendu) values(:num_f,:code_f,:prix_gros,:nom_f,:produit_vendu)");
    query.bindValue(":num_f",res);
    query.bindValue(":code_f",code_f);
    query.bindValue(":prix_gros",prix_gros);
    query.bindValue(":nom_f",nom_f);
    query.bindValue(":produit_vendu",produit_vendu);
    return query.exec();
}
//fonction afficher
QSqlQueryModel * fournisseur::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from fournisseur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("num_f"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("code_f"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix_gros"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom_f"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("produit_vendu"));
}
//fonction supprimer
bool fournisseur::supprimer(int num_f)
{
    QSqlQuery query;
    QString res = QString::number(num_f);
    query.prepare("delete from caise where id= :id");
    query.bindValue(":id",res);
    return  query.exec();
}
//fonction modifier
bool fournisseur::modifier(float prix_gros)
{
    QSqlQuery query;
    QString res = QString::number(num_f);
    query.prepare("UPDATE caise SET num_fournisseur= :num_f,code_f= :code_f,prix_gros= :prix_gros, nom_f= :nom_f,produit_vendu= :produit_vendu WHERE num_f = :num_f");
    query.bindValue(":id",res);
    query.bindValue(":code_f",code_f);
    query.bindValue(":prix_gros",prix_gros);
    query.bindValue(":nom_f",nom_f);
    query.bindValue(":produit_vendu",produit_vendu);
    return query.exec();
}


