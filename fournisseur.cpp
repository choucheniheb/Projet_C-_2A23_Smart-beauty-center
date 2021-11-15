#include "fournisseur.h"
#include <QSqlQuery>
#include <QString>
#include<QSqlQueryModel>
#include <QDateTime>
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
    QString res = QString::number(code_f);
    QString res2 = QString::number(num_f);
    QString res3 = QString::number(prix_gros);

    query.prepare("insert into fournisseur( numero_f, code_f, prix_gros, nom_f,produit_vendu) values(:num_f,:code_f,:prix_gros,:nom_f,:produit_vendu)");
    query.bindValue(":code_f",res);
    query.bindValue(":num_f",res2);
    query.bindValue(":prix_gros",res3);
    query.bindValue(":nom_f",nom_f);
    query.bindValue(":produit_vendu",produit_vendu);
    return query.exec();
}
//fonction afficher
QSqlQueryModel * fournisseur::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from fournisseur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CODE_F"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_F"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NUMERO_F"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX_GROS"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRODUIT_VENDU"));
    return model;
}
//fonction supprimer
bool fournisseur::supprimer(int code_f)
{
    QSqlQuery query;
    QString res = QString::number(code_f);
    query.prepare("delete from fournisseur where code_f= :code_f");
    query.bindValue(":code_f",res);
    return  query.exec();
}

//fonction modifier
bool fournisseur::modifier(int code_f)
{
    QSqlQuery query;
    QString res = QString::number(code_f);
    QString res2 = QString::number(num_f);
    QString res3 = QString::number(prix_gros);
    query.prepare("UPDATE fournisseur SET prix_gros= :prix_gros,produit_vendu= :produit_vendu WHERE code_f = :code_f");
    query.bindValue(":code_f",res);
    query.bindValue(":num_f",res2);
    query.bindValue(":prix_gros",res3);

    query.bindValue(":produit_vendu",produit_vendu);
    return query.exec();
}



QSqlQueryModel* fournisseur::rechercheMulticritere(QString recherche){
    QSqlQueryModel* trouve = new QSqlQueryModel();

    trouve->setQuery("SELECT * FROM FOURNISSEUR WHERE nom_f LIKE '"+recherche+"%' OR code_f LIKE '"+recherche+"%'OR produit_vendu LIKE '"+recherche+"%'");
    trouve->setHeaderData(0,Qt::Horizontal,QObject::tr("CODE_F"));
    trouve->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_F"));
    trouve->setHeaderData(2,Qt::Horizontal,QObject::tr("NUMERO_F"));
    trouve->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX_GROS"));
    trouve->setHeaderData(4,Qt::Horizontal,QObject::tr("PRODUIT_VENDU"));


    return trouve;
}

//historique**********
void fournisseur::ajouterhist(QString hist)
{
    QSqlQuery query;
    QString res= QDateTime::currentDateTime().toString();
    query.prepare("insert into historique(date_h,historique) values(:date_h,:historique)");
    query.bindValue(":date_h",res);
    query.bindValue(":historique",hist);
    query.exec();
}
QSqlQueryModel * fournisseur::afficherhist()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from historique");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("DATE_HISTORIQUE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("HISTORIQUE"));
    return  model;
}


