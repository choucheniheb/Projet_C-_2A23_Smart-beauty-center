#include "historique.h"

historique::historique()
{

}
void historique::save(QString code_a_barre ,QString nom_p, QString prix_uni, QString prix_promo, QString categorie, QString date_expiration, QString quantite_produit)
{    QFile file ("C:/Users/HP/Desktop/historique.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";

     QTextStream out(&file);
     out << code_a_barre+"\n"+nom_p << "\n"+prix_uni << "\n"+prix_promo<< "\n"+categorie << "\n"+date_expiration << "\n"+quantite_produit << "\n""------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n";


}
QString historique::load()
{   tmp="";
    QFile file("C:/Users/HP/Desktop/historique.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      tmp="";

    QTextStream in(&file);

   while (!in.atEnd()) {

         QString myString = in.readLine();
         tmp+=myString+"\n";

   }
   return tmp;
}
