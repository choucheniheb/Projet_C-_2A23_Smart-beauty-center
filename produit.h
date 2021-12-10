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
    produit (QString code_a_barre, QString nom_p,int prix_uni ,int prix_promo,QString categorie,QString date_expiration,int quantite_produit);
// get

    int getquantite_produit();
    int getprix_uni();
    int getprix_promo();
    QString getcategorie();
    QString getcode_a_barre();
    QString getnom_p();
    QString getdate_expiration();
    // bool getstock();

    // set

void setquantite_produit(int);
void setprix_uni(int);
void setprix_promo(int);
void setcategorie(QString);
void setcode_a_barre(QString);
void setnom_p(QString);
void setdate_expiration(QString);
//void setstock(bool);

// cRuds
   bool ajouter();
   QSqlQueryModel    *   afficher();
   bool modifier(QString);
   bool supprimer(QString);
   //metier

QSqlQueryModel * rechercheMulticritere(QString recherche);
void historique_produit(QString);
QSqlQueryModel * afficher_historique_produit();

private:
    int quantite_produit;
    int prix_uni , prix_promo;
    QString categorie;
    QString code_a_barre;
    QString nom_p;
    QString date_expiration;

};


#endif // PRODUIT_H

