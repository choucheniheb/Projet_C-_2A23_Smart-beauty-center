#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QSqlQuery>
#include <QString>
#include<QTableView>
#include <QSqlQueryModel>
class fournisseur
{
public:
    fournisseur();
    fournisseur(int num_f,int code_f,float prix_gros,QString nom_f,QString produit_vendu);


    //getters
    int getnum_f();
    int getcode_f();
    float getprix_gros();
    QString getnom_f();
    QString getproduit_vendu();

    //setters
    void setnum_f(int);
    void setcode_f(int);
    void setprix_gros(float);
    void setnom_f(QString);
    void setproduit_vendu(QString);

    // cRuds
    bool ajouter();
    QSqlQueryModel    *   afficher();
    bool modifier(int);
    bool supprimer(int);
    //metier
    QSqlQueryModel * rechercheMulticritere(QString recherche);
    void ajouterhist(QString);
    QSqlQueryModel * afficherhist();

private:
    int num_f,code_f;
    float prix_gros;
    QString nom_f,produit_vendu;


};

#endif // FOURNISSEUR_H
