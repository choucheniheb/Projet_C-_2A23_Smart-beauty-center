#ifndef SERVICE_H
#define SERVICE_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>



class Service
{
public:
    Service();
     Service(QString nom_s,QString offre,QDate date_offre, float prix_s, float prix_offre , int code_s ,QString disponibilite,int pt_f);
    //getters


    QString getnom_s (){return nom_s;}
    QString getoffre (){return offre;}
    QDate getdate_offre (){return date_offre;}
    float getprix_s (){return prix_s;}
    float getprix_offre (){return prix_offre;}
    int getcode_s (){return code_s;}
    QString getdisponibilite (){return disponibilite;}
    int getpt_f(){return pt_f;}



    //setters
    void setnom_s(QString n){nom_s = n;}
    void setoffre(QString o){offre = o;}
    void setdate_offre(QDate d ){date_offre = d;}
    void setprix_s(float p){prix_s = p;}
    void setprix_offre(float po){prix_offre = po;}
    void setcode_s(int c){code_s = c;}
    void setdisponibilite (QString di ){disponibilite = di;}
    void setpt_f(int p){pt_f=p;}




    // fonctionnealite de base relative a la classe service
    bool ajouter() ;
    QSqlQueryModel * afficher ();
    bool supprimer (int);
    bool modifier (int);
    QSqlQueryModel* rechercheavancee(QString recherche);



private:
     QString nom_s;
     QString offre;
     QDate date_offre;
     float prix_s ;
     float prix_offre ;
     int code_s,pt_f ;
     QString disponibilite ;
     QString recherche ;
};

#endif // SERVICE_H
