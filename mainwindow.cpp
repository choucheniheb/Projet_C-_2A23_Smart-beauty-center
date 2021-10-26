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
       QPixmap pix2("C:/Users/HP/Desktop/image/bc.jpg");
       QPixmap pix3("C:/Users/HP/Desktop/image/k.jpg");
       QPixmap pix4("C:/Users/HP/Desktop/image/parfums.jpg");
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
}
MainWindow::~MainWindow()
{
    delete ui;
}


