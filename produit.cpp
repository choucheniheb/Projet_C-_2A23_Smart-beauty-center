#include "produit.h"
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>

produit::produit()
{

  this -> nbre_produit=0;
  this -> prix_uni=0;
  this ->  prix_promo=0;
  this -> categorie="";
  this -> code_a_barre=0;
  this -> nom_produit="";
  this -> date_expiration="";
 // this -> stock="";
}

produit::produit(int code_a_barre, QString nom_produit , float prix_uni ,float prix_promo,QString categorie,QString date_expiration,int nbre_produit)
{

    this -> nbre_produit=nbre_produit;
    this -> prix_uni=prix_uni;
    this ->  prix_promo=prix_promo;
    this -> categorie=categorie;
    this -> code_a_barre=code_a_barre;
    this -> nom_produit=nom_produit;
    this -> date_expiration=date_expiration;
   // this -> stock=stock;
}
//get

int produit::getnbre_produit(){return nbre_produit;}
float produit::getprix_uni(){return prix_uni;}
float produit::getprix_promo(){return prix_promo;}
QString produit::getcategorie(){return categorie;}
int produit::getcode_a_barre(){return code_a_barre;}
QString produit::getnom_produit(){return nom_produit;}
QString produit::getdate_expiration(){return date_expiration;}
// bool produit::getstock(){return stock;}

//set

void produit::setnbre_produit(int nbre_produit){this -> nbre_produit=nbre_produit;}
void produit::setprix_uni(float prix_uni){this -> prix_uni=prix_uni;}
void produit::setprix_promo(float prix_promo){this -> prix_promo=prix_promo;}
void produit::setcategorie(QString categorie){this -> categorie=categorie;}
void produit::setcode_a_barre(int code_a_barre){this -> code_a_barre=code_a_barre;}
void produit::setnom_produit(QString nom_produit){this -> nom_produit=nom_produit;}
void produit::setdate_expiration(QString date_expiration){this -> date_expiration=date_expiration;}
// void produit::setstock(bool stock){this -> stock=stock;}


//fonction ajouter

bool produit::ajouter()
{ bool test=false;
    QSqlQuery query;
    QString res = QString::number(code_a_barre);

    query.prepare("insert into caise(int num_produit,QString code_a_barre, QString nom_produit , float prix_uni ,float prix_promo,QString date_expiration,int nbre_produit) values(:code_a_barre,:nom_produit,:prix_uni,:prix_promo,:date_expiration,:nbre_produit)");
    query.bindValue(":code_a_barre",res);
    query.bindValue(":prix_uni",prix_uni);
    query.bindValue(":prix_promo",prix_promo);
    query.bindValue(":date_expiration",date_expiration);
    query.bindValue(":nbre_produit",nbre_produit);
    query.exec();
return test;
}
//fonction afficher
QSqlQueryModel * produit::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from produit");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("code_a_barre"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_produit"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix_uni"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_promo"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_expiration"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("nbre_produit"));
}
//fonction supprimer
bool produit::supprimer(int code_a_barre)
{
    QSqlQuery query;
    QString res =QString::number(code_a_barre);
    query.prepare("delete from produit where code a barre= :code a barre");
    query.bindValue(":code_a_barre",res);
    return  query.exec();
}
//fonction modifier
bool produit::modifier(float prix_uni)
{
    QSqlQuery query;
    QString res = QString::number(prix_uni);
    query.prepare("UPDATE caise SET num_produit= :num_produit,code_a_barre= :code_a_barre,nom_produit= :nom_produit,prix_uni= :prix_uni,prix_promo= :prix_promo, date_expiration= :date_expiration,nbre_produit= :nbre_produit WHERE num_facture = :num_f");
    query.bindValue(":code_a_barre",res);
    query.bindValue(":code_a_barre",code_a_barre);
    query.bindValue(":nom_produit",nom_produit);
    query.bindValue(":prix_uni",prix_uni);
    query.bindValue(":prix_promo",prix_promo);
    query.bindValue(":date_expiration",date_expiration);
    query.bindValue(":nbre_produit",nbre_produit);
    return query.exec();
}

