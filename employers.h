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
    Employers(int id,QString nom, QString prenom,QDate date_naissance,QString adresse,int telephone,QString type, QString specialite);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    //getters
    int getid()
    {
        return id;
    }
    int gettelephone()
    {
        return telephone;
    }
    QDate getdate_naissance()
    {
        return date_naissance;
    }
    QString getnom()
    {
        return nom;
    }
    QString getprenom()
    {
        return prenom;
    }
    QString getadresse()
    {
        return adresse;
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
    void setid(int i){id=i;}
    void setnom(QString n){nom=n;}
    void setprenom(QString p){prenom=p;}
    void setdate_naissance(QDate d){date_naissance =d;}
    void setadresse(QString a){adresse=a;}
    void settelephone(int t){telephone=t;}
    void settype(QString y){type=y;}
    void setspecialite(QString s){specialite=s;}

private:
    int id,telephone;
    QString nom,prenom,adresse,type,specialite;
    QDate date_naissance;
};

#endif // EMPLOYERS_H
