#include "historique.h"

historique::historique()
{

}
void historique::save(QString code_f,QString nom_f, QString num_f, QString prix_gros, QString produit_vendu)
{    QFile file ("C:/Users/wajdi/Desktop/historique.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";

     QTextStream out(&file);
     out << code_f+"\n"+nom_f << "\n"+num_f << "\n"+prix_gros << "\n"+produit_vendu  << "\n""------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n";


}
QString historique::load()
{   tmp="";
    QFile file("C:/Users/wajdi/Desktop/historique.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      tmp="";

    QTextStream in(&file);

   while (!in.atEnd()) {

         QString myString = in.readLine();
         tmp+=myString+"\n";

   }
   return tmp;
}
