#ifndef CLIENT_H
#define CLIENT_H
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
class Client
{
public:
    Client();
    Client (QString  Nom,QString Prenom,QString Email,int ID,int Pt_fid,int Tel);
    //getters

    QString getnom (){return Nom_c;}
    QString getpre (){return Prenom_c;}
    QString getemail (){return Email_c;}

    int getid(){return Id_c;}
    int getpf(){return Point_fidelite;}
    int gettel(){return Telephone_c;}

   //Setters

    void setnom(QString N ){Nom_c=N;}
    void setpre(QString P ){Prenom_c=P;}
    void setemail(QString E ){Email_c=E;}
    void setid(int x){Id_c=x;}
    void setpf(int pf){Point_fidelite=pf;}
    void settel(int t){Telephone_c=t;}


    //Fnct

    bool  ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool modifier(int Id_c);
    /*QSqlQueryModel * afficher_recherche(QString ch);
    QSqlQueryModel * afficher_recherche2(QString ch);
    QSqlQueryModel * afficher_recherche3(QString ch);*/

    QSqlQueryModel * afficher_choix(QString choix);
    QSqlQueryModel * rechercheMulticritere(QString);



    private:
    QString  Nom_c,Prenom_c,Email_c;
    int Id_c,Point_fidelite,Telephone_c;


};

#endif // CLIENT_H
