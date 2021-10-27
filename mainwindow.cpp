#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>

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
       QPixmap pix6("C:/Users/HP/Desktop/image/ma.jpg");
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
}
MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::on_pushButtonAjouter_clicked()
{
    //recuperation
    int num_f=ui->lineEdit_num_fact->text().toInt();
    //QDate date=ui->dateEdit_date;
    QDate date;
    float prix_u=ui->lineEdit_prix_unitare->text().toFloat();
    int quntiter=ui->lineEdit_quantite->text().toUInt();
    float prix_t=ui->lineEdit_prix_totale->text().toFloat();
    caise c(num_f,date,prix_u,quntiter,prix_t);//instancer
    bool test=c.ajouter();

    if(test)
    {
        //Refresh affichage
        ui->tableViewAficherFacture->setModel(c.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajouter non effectuer"),QObject::tr("click cancel to exit"));
    }
}
void MainWindow::on_pushButtonSupprimer_clicked()
{
    int num_fact=ui->lineEdit_num_fact_sup->text().toUInt();
    bool test1=c.supprimer(num_fact);
    if(test1)
    {
        //Refresh affichage
        ui->tableViewAficherFacture->setModel(c.afficher());
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
    c.setprix_unitair(ui->lineEdit_prix_u_modifier->text().toFloat());
    c.setquntiter(ui->lineEdit_quntiter_modifier->text().toUInt());
    c.setprix_totale(ui->lineEdit_prix_t_modifier->text().toFloat());

    //modifier requete************
    int num_fact=ui->lineEdit_num_fact_modifier->text().toUInt();
    bool test2=c.modifier(num_fact);
    if(test2)
    {
        //Refresh affichage
        ui->tableViewAficherFacture->setModel(c.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {

*/

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

/*produit p();
produit p (code_a_barre,nom_produit,prix_uni ,prix_promo,categorie, date_expiration, nbre_produit);
bool test=p.ajouter();*/
if (prix)

}
