#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include <QString>
#include<QDebug>
#include <QDate>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    //image****
    ui->setupUi(this);
    //affichage
    ui->tableViewAficherFacture->setModel(c.afficher());
        QPixmap pix("C:/Users/Ihebc/OneDrive/Desktop/gestion de caise/image/pix2.png");
        int w1 = ui->label_pic1->width();
        int h1 = ui->label_pic1->height();
        ui->label_pic1->setPixmap(pix.scaled(w1,h1,Qt::KeepAspectRatio));
        //insrtion image2
        int w2 = ui->label_pic2->width();
        int h2 = ui->label_pic2->height();
        ui->label_pic2->setPixmap(pix.scaled(w2,h2,Qt::KeepAspectRatio));
        //insrtion image3
        int w3 = ui->label_pic3->width();
        int h3 = ui->label_pic3->height();
        ui->label_pic3->setPixmap(pix.scaled(w3,h3,Qt::KeepAspectRatio));
        //insrtion image4
        int w4 = ui->label_pic4->width();
        int h4 = ui->label_pic4->height();
        ui->label_pic4->setPixmap(pix.scaled(w4,h4,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//ajouter************
void MainWindow::on_pushButtonAjouter_clicked()
{
    //recuperation
    int num_f=ui->lineEdit_num_fact->text().toInt();
    QDate date=ui->dateTimeEdit_ajouter->date();
    qDebug()<<date;
    float prix_u=ui->lineEdit_prix_unitaire->text().toFloat();
    int quantite=ui->lineEdit_quantite->text().toInt();
    float prix_t=ui->lineEdit_prix_totale->text().toFloat();
    caisse c(num_f,date,prix_u,quantite,prix_t);//instancer
    bool test=c.ajouter();

    if(test)
    {
        /*Refresh affichage
        ui->tableViewAficherFacture->setModel(c.afficher());*/
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajouter non effectuer"),QObject::tr("click cancel to exit"));
    }
}


//supprimer********************
void MainWindow::on_pushButtonSupprimer_clicked()
{
    int num_fact=ui->lineEdit_num_fact_sup->text().toInt();
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

//modifier**************
void MainWindow::on_pushButtonModifier2_clicked()
{
    //modifier les valeur de class
    //c.setdate(ui->dateTimeEdit_modifier->date());
    c.setprix_unitair(ui->lineEdit_prix_u_modifier->text().toFloat());
    c.setquantiter(ui->lineEdit_quntiter_modifier->text().toInt());
    c.setprix_totale(ui->lineEdit_prix_t_modifier->text().toFloat());

    //modifier requete************
    int num_fact=ui->lineEdit_num_fact_modifier->text().toInt();
    bool test2=c.modifier(num_fact);
    ui->stackedWidget->setCurrentIndex(0);
    if(test2)
    {
        //Refresh affichage
        ui->tableViewAficherFacture->setModel(c.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectuer"),QObject::tr("click cancel to exit"));
    }
}

//recette***********
void MainWindow::on_recette_clicked()
{
    ui->stackedWidget1->setCurrentIndex(1);
}

//retour***********
void MainWindow::on_pushButtonRetourRecette_clicked()
{
    ui->stackedWidget1->setCurrentIndex(0);
}

//retour************
void MainWindow::on_pushButtonRetourModifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
