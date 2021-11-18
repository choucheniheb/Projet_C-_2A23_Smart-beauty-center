#include "employers.h"
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "smtp.h"
Employers::Employers()
{
    id_e=0;
    nom_e="";
    prenom_e="";
    adresse_e="";
    telephone_e=0;
    type="";
    specialite="";


}
Employers::Employers(int id,QString nom, QString prenom,QDateTime date_naissance,QString adresse,int telephone,QString type, QString specialite)
{
this->id_e=id;
this->nom_e=nom;
this->prenom_e=prenom;
this->date_naissance_e=date_naissance;
this->adresse_e=adresse;
this->telephone_e=telephone;
this->type=type;
this->specialite=specialite;
}

Employers::Employers(int id, QString entree, QString sortie,QString jour_travail)
{
    this->id_e=id;
    this->entree=entree;
    this->sortie=sortie;
    this->jour_travail=jour_travail;
}
bool Employers::ajouter()
{

    QSqlQuery query;
    QString res = QString::number(id_e); //convertion
    QString res1 = QString::number(telephone_e);

    query.prepare("insert into EMPLOYERS(id_e,nom_e,prenom_e, date_naissance_e, adresse_e,telephone_e,type,specialite)"" values(:id,:nom,:prenom, :date_naissance, :adresse,:telephone,:type,:specialite)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom_e);
    query.bindValue(":prenom",prenom_e);
    query.bindValue(":date_naissance",date_naissance_e);
    query.bindValue(":adresse",adresse_e);
    query.bindValue(":telephone",res1);
    query.bindValue(":type",type);
    query.bindValue(":specialite",specialite);
    return query.exec();
}
QSqlQueryModel * Employers::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select id_e,nom_e,prenom_e,date_naissance_e,adresse_e,telephone_e,type,specialite from Employers");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("telephone"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("specialite"));
    return model;
}


//**********************
bool Employers::ajouterh()
{
    QSqlQuery query;
    QString res = QString::number(id_e); //convertion

    query.prepare("update EMPLOYERS set entree= :entree,sortie= :sortie,jour_travail= :jour_travail where id_e= :id");
    query.bindValue(":id",res);
    query.bindValue(":entree",entree);
    query.bindValue(":sortie",sortie);
    query.bindValue(":jour_travail",jour_travail);
    return query.exec();
}

QSqlQueryModel* Employers::afficherh()
{
    QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery("SELECT id_e,entree,sortie,jour_travail FROM Employers");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("heure d'arrivee"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("heure de sortie"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("jour_travail"));
    return model;
}
//**********************


bool Employers::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("delete from EMPLOYERS where ID_E= :id");
    query.bindValue(":id",res);
    return  query.exec();
}

bool Employers::modifier(int id_e)
{
    QSqlQuery query;
    QString res = QString::number(id_e);
    QString res1 = QString::number(telephone_e);
    //QString res2 = QString::number(date);
    query.prepare("UPDATE EMPLOYERS SET adresse_e= :adresse,telephone_e= :telephone_e, type= :type, specialite= :specialite WHERE id_e = :id");
    query.bindValue(":id",res);
   // query.bindValue(":nom",nom_e);
    //query.bindValue(":prenom",prenom_e);
    //query.bindValue(":date_naissance",date_naissance_e);
    query.bindValue(":adresse",adresse_e);
    query.bindValue(":telephone_e",res1);
    query.bindValue(":type",type);
    query.bindValue(":specialite",specialite);
    return query.exec();
}


//***************************************RECHERCHE*********************
QSqlQueryModel* Employers::rechercheMulticritere(QString recherche){
    QSqlQueryModel* trouve = new QSqlQueryModel();

    trouve->setQuery("SELECT * FROM EMPLOYERS WHERE ID_E LIKE '"+recherche+"%' OR NOM_E LIKE '"+recherche+"%' OR PRENOM_E LIKE '"+recherche+"%'");
    trouve->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    trouve->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    trouve->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    trouve->setHeaderData(3,Qt::Horizontal,QObject::tr("date_naissance"));
    trouve->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
    trouve->setHeaderData(5,Qt::Horizontal,QObject::tr("telephone"));
    trouve->setHeaderData(6,Qt::Horizontal,QObject::tr("type"));
    trouve->setHeaderData(7,Qt::Horizontal,QObject::tr("specialite"));

    return trouve;
}

//*************************TRI**************

QSqlQueryModel * Employers::triParId()
{
    QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM EMPLOYERS ORDER BY CAST (ID_E AS number)");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_naissance"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("telephone"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("type"));
        model->setHeaderData(7,Qt::Horizontal,QObject::tr("specialite"));
        return model;
}


QSqlQueryModel * Employers::triParNom()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYERS ORDER BY NOM_E ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("telephone"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("specialite"));

    return model;
}

QSqlQueryModel * Employers::trierDate()
{
             QSqlQueryModel * model = new  QSqlQueryModel ();
             model->setQuery("SELECT * FROM EMPLOYERS ORDER BY CAST (DATE_NAISSANCE_E as TIMESTAMP) ASC");
             model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
             model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
             model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
             model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_naissance"));
             model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
             model->setHeaderData(5,Qt::Horizontal,QObject::tr("telephone"));
             model->setHeaderData(6,Qt::Horizontal,QObject::tr("type"));
             model->setHeaderData(7,Qt::Horizontal,QObject::tr("specialite"));
             return model;

}





