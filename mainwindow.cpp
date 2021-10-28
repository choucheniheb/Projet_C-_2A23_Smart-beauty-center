#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

        QPixmap pix2("C:/Users/wajdi/Desktop/image/pix2.png");
// ajouter photo
int w=ui->label_pic ->width();

int h=ui->label_pic ->height();
          ui->label_pic->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));


// modifier photo
    int w1=ui->label_mod ->width();

  int h1=ui->label_mod ->height();
            ui->label_mod->setPixmap(pix2.scaled(w1,h1,Qt::KeepAspectRatio));


            // QPixmap pix2("C:/Users/wajdi/Desktop/image/pix2.png");

// afficher photo
            int w2=ui->label_aff ->width();

            int h2=ui->label_aff ->height();
                      ui->label_aff->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));
// supprimer
                      int w3=ui->label_sup ->width();

                      int h3=ui->label_sup ->height();
                                ui->label_sup->setPixmap(pix2.scaled(w3,h3,Qt::KeepAspectRatio));

                                //historique
                                int w4=ui->label_h ->width();

                                int h4=ui->label_h ->height();
                                          ui->label_h->setPixmap(pix2.scaled(w4,h4,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_clicked()
{

    //recuperation
   QString nom_f=ui->lineEdit_nom_f->text();
    float prix_gros=ui->lineEdit_prix_gros->text().toFloat();
    int num_f=ui->lineEdit_num_f->text().toUInt();
    int code_f=ui->lineEdit_code_f->text().toUInt();
     QString produit_vendu=ui->lineEdit_produit_vendu->text();
    fournisseur f(num_f,code_f,prix_gros,nom_f,produit_vendu);//instancer
    bool test=f.ajouter();

    if(test)
    {
        //Refresh affichage
        ui->tableViewAficherfournisseur->setModel(f.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajouter non effectuer"),QObject::tr("click cancel to exit"));
    }
}
void MainWindow::on_pushButtonSupprimer_clicked()
{
    int num_f=ui->lineEdit_num_f_sup->text().toUInt();
    bool test1=f.supprimer(num_f);
    if(test1)
    {
        //Refresh affichage
        ui->tableViewAficherfournisseur->setModel(f.afficher());
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

    f.setproduit_vendu(ui->lineEdit_produit_modifier->text());
   f.setprix_gros(ui->lineEdit_prix_modifier->text().toInt());


    //modifier requete************
    int code_f=ui->lineEdit_code_f_modifier->text().toInt();
    bool test2=f.modifier(code_f);
    if(test2)
    {
        //Refresh affichage
        ui->tableViewAficherfournisseur->setModel(f.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectuer"),QObject::tr("click cancel to exit"));
    }
}


