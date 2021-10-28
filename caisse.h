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
    caisse(int num_facture,QDate date,float prix_unitair,int quantite,float prix_totale);

    //getters
    int getnum_fact(){return num_facture;}
    QDate getdate(){return date;}
    float getprix_unitair(){return  prix_unitaire;}
    int getquantite(){return  quantiter;}
    float getprix_totale(){return  prix_totale;}

    //setters
    void setnum_fact(int n){num_facture=n;}
    void setdate(QDate d){date=d;}
    void setprix_unitair(float p1){prix_unitaire=p1;}
    void setquantiter(int q){quantiter=q;}
    void setprix_totale(float p2){prix_totale=p2;}
    //CRUDs
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);



private:
    int num_facture,quantiter;
    float prix_totale,prix_unitaire;
    QDate date;
};

#endif // CAISSE_H
