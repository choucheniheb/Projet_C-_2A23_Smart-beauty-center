#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include "service.h"
#include <QString>
#include <QDate>
#include "service.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   // ui->setupUi(this);
        //QPixmap pix("C:/Users/Samar/Desktop/image/logo1.png");
        //int w = ui->label_pic->width();
        //int h = ui->label_pic->height();
        // ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}
 void MainWindow :: on_pushButton_ajouter_clicked ()
 {

     int code = ui-> lineEdit_code->text().toInt();
     QString nom_s = ui -> lineEdit_nom_s ->text();
     QString offre = ui -> lineEdit_offre ->text();
     //QDate date=ui->dateEdit_date;
     QDate date_offre ;

     float prix_s=ui->lineEdit_prix_s->text().toFloat();
     float prix_offre=ui->lineEdit_prix_offre->text().toFloat();



   Service S ( nom_s , offre ,  date_offre , prix_s, prix_offre, code ,disponibilite ); //instancer

   bool  test = S.ajouter ();

   if (test)
   {
       //Refresh affichage
       ui->tableViewAfficherService->setModel(S.afficher());
       QMessageBox :: information(nullptr , QObject :: tr("ok"),QObject::tr("ajouter effectue\n"),QObject::tr("click cancel to exit"));
   }else
   {
       QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajouter non effectue"),QObject::tr("click cancel to exit"));
   }
}




void MainWindow::on_pushButton_supprimer_clicked()
{
    int  code =ui->lineEdit_code->text().toInt();
    bool test1 = S.supprimer(code);
    if(test1)
    {
        //Refresh affichage
        ui->tableViewAfficherService->setModel(S.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectue\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectue"),QObject::tr("click cancel to exit"));
    }
}



 void MainWindow::on_pushButtonModifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
 void MainWindow::on_pushButtonModifier2_clicked()
{
    //modifier les valeur de class
    //S.setdate(ui->dateTimeEdit_modifier->text().to)
    S.setprix_s(ui->lineEdit_prix_s_modifier->text().toFloat());
    S.setprix_offre(ui->lineEdit_prix_offre_modifier->text().toFloat());
    S.setdate_offre(ui->lineEdit_date_offre_modifier->text().toInt());

    //modifier requete************
    int code =ui->lineEdit_code_modifier->text().toInt();
    bool test2=S.modifier(code);
    if(test2)
    {
        //Refresh affichage
        ui->tableViewAficherService->setModel(S.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectue\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectue"),QObject::tr("click cancel to exit"));
    }
}

