#ifndef CAISSE_H
#define CAISSE_H
#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class caisse
{
public:
public:
    //constructeur
    caisse();
    caisse(int num_facture,QDate date_delevrance,float prix_unitair,int quantite,float prix_totale,int id_c);

    //getters
    int getnum_fact(){return num_facture;}
    QDate getdate(){return date_delevrance;}
    float getprix_unitair(){return  prix_unitaire;}
    int getquantite(){return  quantiter;}
    float getprix_totale(){return  prix_totale;}
    int getid_c(){return id_c;}

    //setters
    void setnum_fact(int n){num_facture=n;}
    void setdate(QDate d){date_delevrance=d;}
    void setprix_unitair(float p1){prix_unitaire=p1;}
    void setquantiter(int q){quantiter=q;}
    void setprix_totale(float p2){prix_totale=p2;}
    void setid_c(int id){id_c=id;}
    //CRUDs
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);

    //metier**********
    QSqlQueryModel * triParId();
    QSqlQueryModel * triParDate();
    QSqlQueryModel * triParPrix();
    QSqlQuery calculerecette();
    QSqlQueryModel * rechercheMulticritere(QString);




private:
    int num_facture,quantiter;
    float prix_totale,prix_unitaire;
    QDate date_delevrance;
    int id_c;
};

#endif // CAISSE_H
