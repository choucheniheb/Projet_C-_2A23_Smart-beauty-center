#include "historique_wajdi.h"

historique_wajdi::historique_wajdi()
{

}
void historique_wajdi::save_wajdi(QString code_f,QString nom_f, QString num_f, QString prix_gros, QString produit_vendu)
{    QFile file ("C:/Users/Ihebc/OneDrive/Desktop/integration/historique wajdi.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";

     QTextStream out(&file);
     out << code_f+"\n"+nom_f << "\n"+num_f << "\n"+prix_gros << "\n"+produit_vendu  << "\n""------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n";


}
QString historique_wajdi::load_wajdi()
{   tmp="";
    QFile file("C:/Users/Ihebc/OneDrive/Desktop/integration/historique wajdi.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      tmp="";

    QTextStream in(&file);

   while (!in.atEnd()) {

         QString myString = in.readLine();
         tmp+=myString+"\n";

   }
   return tmp;
}
