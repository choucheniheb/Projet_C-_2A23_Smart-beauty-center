#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "employers.h"
#include <QMessageBox>

//liiindaaa
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        QPixmap pix("C:/Users/asus/OneDrive/Desktop/image/logo1.png");
        QPixmap pix1("C:/Users/asus/OneDrive/Desktop/image/logo2.png");
        QPixmap pix2("C:/Users/asus/OneDrive/Desktop/image/logo3.png");
        int w = ui->label_pic->width();
        int h = ui->label_pic->height();

        int w1 = ui->label_pic1->width();
        int h1 = ui->label_pic1->height();

        int w2 = ui->label_pic2->width();
        int h2 = ui->label_pic2->height();

         ui->label_pic->setPixmap(pix1.scaled(w,h,Qt::KeepAspectRatio));
          ui->label_pic1->setPixmap(pix.scaled(w1,h1,Qt::KeepAspectRatio));
          ui->label_pic2->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButtonAjouter_clicked()
{
    //recuperation
    int id=ui->lineEdit_id->text().toInt();
    QString  nom=ui->lineEdit_nom->text();
    QString  prenom=ui->lineEdit_prenom->text();
    QDate date_naissance=ui->dateTimeEdit_ajouter->date();
    QString  adresse=ui->lineEdit_adresse->text();
    int telephone=ui->lineEdit_telephone->text().toInt();
    QString  type=ui->lineEdit_type->text();
    QString  specialite=ui->lineEdit_specialite->text();

    Employers e( id, nom, prenom,date_naissance, adresse,telephone,type,specialite);//instancer
    bool test=e.ajouter();

    if(test)
    {
        //Refresh affichage
        //ui->tableViewAficherEmployers->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectue\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectue"),QObject::tr("click cancel to exit"));
    }
}
void MainWindow::on_pushButtonSupprimer_clicked()
{
    int id=ui->lineEdit_id_sup->text().toUInt();
    bool test1=e.supprimer(id);
    if(test1)
    {
        //Refresh affichage
        //ui->tableViewAficherEmployers->setModel(e.afficher());
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
    e.setnom(ui->lineEdit_nom_e_modifier->text());
    e.setprenom(ui->lineEdit_prenom_e_modifier->text());
    e.setdate_naissance(ui->lineEdit_date_naissance_e_modifier->date());
    e.setadresse(ui->lineEdit_adresse_e_modifier->text());
    e.settelephone(ui->lineEdit_telephone_e_modifier->text().toInt());
    e.settype(ui->lineEdit_type_modifier->text());
    e.setspecialite(ui->lineEdit_specialite_modifier->text());

    //modifier requete************
    int id_e=ui->lineEdit_id_e_modifier->text().toUInt();
    bool test2=e.modifier(id_e);
    if(test2)
    {
        //Refresh affichage
        ui->tableViewAficherEmployers->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectuer"),QObject::tr("click cancel to exit"));
    }
}
