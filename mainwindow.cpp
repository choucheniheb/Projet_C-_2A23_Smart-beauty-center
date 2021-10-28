#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include<QPixmap>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/HP/Desktop/image/makeup.jpg");
     QPixmap pix1("C:/Users/HP/Desktop/image/cosmetics.jpg");
       QPixmap pix2("C:/Users/HP/Desktop/image/bc.png");
       QPixmap pix3("C:/Users/HP/Desktop/image/k.jpg");
       QPixmap pix4("C:/Users/HP/Desktop/image/parfums.jpg");
       QPixmap pix5("C:/Users/HP/Desktop/image/aa1.png");
       QPixmap pix6("C:/Users/HP/Desktop/image/mqqq.png");
       //QPixmap pix7("C:/Users/HP/Desktop/image/ma.jpg");
    // background1
       int w = ui->label_bc->width();
    int h = ui->label_bc->height();
    //background categorie
    int w3 = ui->label_bc_2->width();
    int h3 = ui->label_bc_2->height();
    //categorie makeup
    int w2 = ui->label_mq->width();
    int h2 = ui->label_mq->height();
    //categorie cos
    int w1 = ui->label_cos->width();
    int h1 = ui->label_cos->height();
    //parfums
    int w4 = ui->label_parfums->width();
    int h4 = ui->label_parfums->height();
    // ajouter
    int w5 = ui->label_aa->width();
 int h5 = ui->label_aa->height();
 //
 int w6 = ui->label_mq1->width();
int h6 = ui->label_mq1->height();
//
//int w7 = ui->label_mq1->width();
//int h7 = ui->label_mq1->height();
    //cos
    ui->label_cos->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));
    //mq
    ui->label_mq->setPixmap(pix.scaled(w2,h2,Qt::KeepAspectRatio));
      //background1 bienvevue
    ui->label_bc->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
      //background categorie
    ui->label_bc_2->setPixmap(pix3.scaled(w3,h3,Qt::KeepAspectRatio));
    // background parfums
    ui->label_parfums->setPixmap(pix4.scaled(w4,h4,Qt::KeepAspectRatio));
    //ajouter
    ui->label_aa->setPixmap(pix5.scaled(w5,h5,Qt::KeepAspectRatio));
    //
     ui->label_mq1->setPixmap(pix6.scaled(w6,h6,Qt::KeepAspectRatio));
     //
    // ui->label_10->setPixmap(pix7.scaled(w7,h7,Qt::KeepAspectRatio));
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_aj_button_clicked()
{
    //code a barre
    int code_a_barre=ui->code_edit->text().toInt();
    //nom
   QString nom_produit=ui->nom_edit->text();
   //prix uni
   float prix_uni=ui->prixu_edit->text().toFloat();
   float prix_promo=ui->prixp_edit->text().toFloat();
   //
   QString categorie=ui->categorie_edit->text();
   QString date_expiration=ui->date_edit->text();
   int nbre_produit=ui-> nbreEdit->text().toInt();
//
   if ((prix_uni > prix_promo) && (categorie == "makeup" || categorie == "cosmetiques" || categorie == "parfums") && (nbre_produit != 0 || prix_uni != 0 ||  prix_promo != 0 || categorie != "" || code_a_barre != 0 || nom_produit != "" || date_expiration != ""))
   {
       QMessageBox::information(this,"ajouter produit","ajouter effectuer");
   }
   else

   {
        QMessageBox::critical(this,"ajouter produit","ajouter non effectuer");
   }

   //

produit (code_a_barre,nom_produit,prix_uni,prix_promo,categorie, date_expiration, nbre_produit);
bool test=p.ajouter();
 if(test)
{
    //Refresh affichage
    ui->tableViewproduit->setModel(p.afficher());
    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectuer\n"),QObject::tr("click cancel to exit"));
}else
{
    QMessageBox::critical(nullptr,QObject::tr(" non ok"),QObject::tr("ajouter non effectuer"),QObject::tr("click cancel to exit"));
}
}
void MainWindow::on_pushButtonSupprimer_clicked()
{
int code_a_barre=ui->lineEditcodeabarresupprimer->text().toUInt();
bool test1=p.supprimer(code_a_barre);
if(test1)
{
    //Refresh affichage
    ui->tableViewproduit->setModel(p.afficher());
    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectuer\n"),QObject::tr("click cancel to exit"));
}else
{
    QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectuer"),QObject::tr("click cancel to exit"));
}
}
void MainWindow::on_pushButtonModifier_clicked()
{
ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pushButtonModifier2_clicked()
{
//modifier les valeur de class
//c.setdate(ui->dateTimeEdit_modifier->text().to)
p.setprix_uni(ui->prixu_edit_1->text().toFloat());
p.setprix_promo(ui->prixp_edit_1->text().toFloat());
p.setcategorie(ui->categorie_edit_1->text());
p.setdate_expiration(ui->date_edit_1->text());
p.setnbre_produit(ui->nbreEdit_1->text().toInt());


//modifier requete************
int code_a_barre=ui->codeabarrem->text().toInt();
bool test2=p.modifier(code_a_barre);
if(test2)
{
    //Refresh affichage
    ui->tableViewproduit->setModel(p.afficher());
    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectuer\n"),QObject::tr("click cancel to exit"));
}else
{
    QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectuer"),QObject::tr("click cancel to exit"));
        }

}
void MainWindow::on_makeup_bottom_clicked()
{
    ui->stackedWidget2->setCurrentIndex(1);
}
void MainWindow::on_cosmetiques_bottom_clicked()
{
    ui->stackedWidget2->setCurrentIndex(2);
}
void MainWindow::on_parfums_bottom_clicked()
{
    ui->stackedWidget2->setCurrentIndex(3);
}
