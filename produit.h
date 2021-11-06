#ifndef PRODUIT_H
#define PRODUIT_H
#include <QSqlQuery>
#include <QString>
// #include <QDate>
#include <QSqlQueryModel>


class produit
{


public:
    produit();
    produit (int code_a_barre, QString nom_p,float prix_uni ,float prix_promo,QString categorie,QString date_expiration,int quantite_produit);
// get

    int getquantite_produit();
    float getprix_uni();
    float getprix_promo();
    QString getcategorie();
    int getcode_a_barre();
    QString getnom_p();
    QString getdate_expiration();
    // bool getstock();

    // set

void setquantite_produit(int);
void setprix_uni(float);
void setprix_promo(float);
void setcategorie(QString);
void setcode_a_barre(int);
void setnom_p(QString);
void setdate_expiration(QString);
//void setstock(bool);

// cRuds
   bool ajouter();
   QSqlQueryModel    *   afficher();
   bool modifier(int);
   bool supprimer(int);

private:

    int quantite_produit;
    float prix_uni , prix_promo;
    QString categorie;
    int code_a_barre;
    QString nom_p;
    QString date_expiration;

};


#endif // PRODUIT_H

