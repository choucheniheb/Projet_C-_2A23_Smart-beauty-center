#include "client.h"
#include <QDebug>
Client::Client()
{

}
//constructure
Client :: Client (QString  Nom,QString Prenom,QString Email,int ID,int Pt_fid,int Tel)
{
 this->Nom_c=Nom;
 this->Prenom_c=Prenom;
 this->Id_c=ID;
 this->Point_fidelite=Pt_fid;
 this->Telephone_c=Tel;

 this->Email_c=Email;
}
//fonction ajouter
bool Client::ajouter()
{
    QSqlQuery query;
    QString id_str= QString::number(Id_c);
    QString pf_str = QString::number(Point_fidelite);
    QString tel_str= QString::number(Telephone_c);

    query.prepare("insert into client(ID_C,NOM_C,PRENOM_C,TELEPHONE_C,EMAIL,POINT_FIDELITE) values(:id_c,:nom_c,:prenom_c,:Telephone_c,:email,:point_fidelite)");
    query.bindValue(":id_c",id_str);
    query.bindValue(":nom_c",Nom_c);
    query.bindValue(":prenom_c",Prenom_c);
    query.bindValue(":email",Email_c);
    query.bindValue(":point_fidelite",pf_str);
    query.bindValue(":Telephone_c",tel_str);
    return query.exec();
}

//fonction afficher
QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_C"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_C"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_C"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TELEPHONE_C"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("POINT_FIDELITE"));
    return model;
}

//fonction supprimer
bool Client::supprimer(int Id_c)
{
    QSqlQuery query;
    QString id_str = QString::number(Id_c);
    query.prepare("DELETE FROM CLIENT WHERE ID_C= :Id_c");
    query.bindValue(":Id_c",id_str);
    return  query.exec();
}

bool Client::modifier(int Id_c)
{
    QSqlQuery query;
    QString id_str= QString::number(Id_c);
    QString pf_str = QString::number(Point_fidelite);
    QString tel_str= QString::number(Telephone_c);
    qDebug()<<tel_str;

    query.prepare("UPDATE client SET nom_c= :nom_c, prenom_c= :prenom_c,TELEPHONE_C= :Telephone_c,email= :email,point_fidelite= :point_fidelite WHERE id_c = :id_c");
    query.bindValue(":id_c",id_str);
    query.bindValue(":nom_c",Nom_c);
    query.bindValue(":prenom_c",Prenom_c);
    query.bindValue(":email",Email_c);
    query.bindValue(":point_fidelite",pf_str);
    query.bindValue(":Telephone_c",tel_str);
    return query.exec();
}


/*******recherche multi criteres*******************
QSqlQueryModel *Client:: afficher_recherche(QString ch)
{
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("SELECT * FROM CLIENT where  ID_C='"+ch+"' ");

    return model ;
}

QSqlQueryModel *Client:: afficher_recherche2(QString ch)
{
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("SELECT * FROM CLIENT where  NOM_C='"+ch+"' ");

    return model ;
}


QSqlQueryModel *Client:: afficher_recherche3(QString ch)
{
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("SELECT * FROM CLIENT where  TELEPHONE_C='"+ch+"' ");

    return model ;
}*******************/
/******RechercheAvancee******************/

QSqlQueryModel * Client::rechercheMulticritere(QString recherche)
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("SELECT * FROM client WHERE id_c LIKE '"+recherche+"%'OR nom_c LIKE '"+recherche+"%' or telephone_c LIKE '"+recherche+"%'");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_C"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_C"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_C"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("TELEPHONE_C"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("EMAIL"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("POINT_FIDELITE"));
        return model;
}


/****************************************/

QSqlQueryModel *Client:: afficher_choix(QString choix)
{
    QSqlQueryModel * model =new QSqlQueryModel();

     if(choix=="ID CROISSANT")
    {
        model->setQuery("SELECT * FROM CLIENT  ORDER BY ID_C ASC ;");
    }
    else if(choix=="ID DECROISSANT")
     {
         model->setQuery("SELECT * FROM CLIENT  ORDER BY ID_C DESC ;");
     }else if(choix=="NOM CROISSANT")
    {
        model->setQuery("SELECT * FROM CLIENT  ORDER BY NOM_C ASC ;");
    }else if(choix=="NOM DECROISSANT")
     {
         model->setQuery("SELECT * FROM CLIENT  ORDER BY NOM_C DESC;");
     }else if(choix=="PRENOM CROISSANT")
     {
         model->setQuery("SELECT * FROM CLIENT  ORDER BY PRENOM_C ASC ;");
     }else if(choix=="PRENOM DECROISSANT")
      {
          model->setQuery("SELECT * FROM CLIENT  ORDER BY PRENOM_C DESC;");
      }else if(choix=="TEL CROISSANT")
     {
         model->setQuery("SELECT * FROM CLIENT  ORDER BY TELEPHONE_C ASC;");
     }else if(choix=="TEL DECROISSANT")
     {
         model->setQuery("SELECT * FROM CLIENT  ORDER BY TELEPHONE_C DESC;");
     }else if(choix=="PT CROISSANT ")
     {
         model->setQuery("SELECT * FROM CLIENT  ORDER BY POINT_FIDELITE ASC;");
     }else if(choix=="PT DECROISSANT")
     {
         model->setQuery("SELECT * FROM CLIENT  ORDER BY POINT_FIDELITE DESC;");
     }else if(choix=="EMAIL CROISSANT")
     {
         model->setQuery("SELECT * FROM CLIENT  ORDER BY EMAIL ASC;");
     }else if(choix=="EMAIL DECROISSANT")
     {
         model->setQuery("SELECT * FROM CLIENT  ORDER BY EMAIL DESC;");
     } else if (choix=="CHOISIR")
    {
        model->setQuery("SELECT * FROM CLIENT ");
    }


    return model;



}










