#ifndef EMPLOYERS_H
#define EMPLOYERS_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employers
{
public:
    //constructeurs
    Employers();
    Employers(int id,QString nom, QString prenom,QDateTime date_naissance,QString adresse,int telephone,QString type, QString specialite);
    Employers(int id, QString,QString,QString);
    bool ajouter();
    bool ajouterh();
    QSqlQueryModel * afficher();
    QSqlQueryModel* afficherh();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * rechercheMulticritere(QString);
    QSqlQueryModel * triParId();
    QSqlQueryModel * triParNom();
    QSqlQueryModel * trierDate();
    void chat(QString,QString,QString);
    QSqlQueryModel* affichermessage(QString,QString);

    //getters
    int getid()
    {
        return id_e;
    }
    int gettelephone()
    {
        return telephone_e;
    }
    QDateTime getdate_naissance()
    {
        return date_naissance_e;
    }
    QString getnom()
    {
        return nom_e;
    }
    QString getprenom()
    {
        return prenom_e;
    }
    QString getadresse()
    {
        return adresse_e;
    }
    QString gettype()
    {
        return type;
    }
    QString getspecialite()
    {
        return specialite;
    }


    //SETTERS
    void setid(int i){id_e=i;}
    void setnom(QString n){nom_e=n;}
    void setprenom(QString p){prenom_e=p;}
    void setdate_naissance(QDateTime d){date_naissance_e=d;}
    void setadresse(QString a){adresse_e=a;}
    void settelephone(int t){telephone_e=t;}
    void settype(QString y){type=y;}
    void setspecialite(QString s){specialite=s;}
    void setentree(QString h){entree=h;}
    void setsortie(QString m){sortie=m;}

private:
    int id_e,telephone_e;
    QString nom_e,prenom_e,adresse_e,type,specialite;
    QDateTime date_naissance_e;
    QString entree,sortie;
    QString jour_travail;
};

#endif // EMPLOYERS_H
