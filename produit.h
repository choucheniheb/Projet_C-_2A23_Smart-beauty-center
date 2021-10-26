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
    produit (int num_produit, QString code_a_barre, QString nom_produit,float prix_uni ,float prix_promo,QString date_expiration,int nbre_produit);
// get
    int getnum_produit();
    int getnbre_produit();
    float getprix_uni();
    float getprix_promo();
    QString getcategorie();
    QString getcode_a_barre();
    QString getnom_produit();
    QString getdate_expiration();
    // bool getstock();

    // set
void setnum_produit(int);
void setnbre_produit(int);
void setprix_uni(float);
void setprix_promo(float);
void setcategorie(QString);
void setcode_a_barre(QString);
void setnom_produit(QString);
void setdate_expiration(QString);
//void setstock(bool);

// cRuds
   bool ajouter();
   QSqlQueryModel    *   afficher();
   bool modifier(float);
   bool supprimer(QString);

private:
   int num_produit;
    int nbre_produit;
    float prix_uni , prix_promo;
    QString categorie;
    QString code_a_barre;
    QString nom_produit;
    QString date_expiration;
    // bool stock;
};


#endif // PRODUIT_H

