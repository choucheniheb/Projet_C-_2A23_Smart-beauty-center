#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include "service.h"
#include <QString>
#include <QDate>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QDesktopServices>
#include <QtQuickWidgets>
#include <QQuickItem>


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ////setup images
        QPixmap pix("C:/Users/Samar/Desktop/image/image.png");
        int w = ui->label_pic->width();
        int h = ui->label_pic->height();
         ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

         QPixmap pix1("C:/Users/Samar/Desktop/image/image.png");
         int w1 = ui->label_pic1->width();
         int h1 = ui->label_pic1->height();
          ui->label_pic1->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));


          /*QPixmap pix1("C:/Users/Samar/Desktop/image/image.png");
          int w1 = ui->label_pic1->width();
          int h1 = ui->label_pic1->height();
           ui->label_pic1->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));*/




   //// controle de saisie sur les entiers et reels
         ui->lineEdit_code->setValidator(new QIntValidator(0,9999999,this));

         ui->lineEdit_prix_s->setValidator(new QIntValidator(0,9999999,this));
         ui->lineEdit_prix_offre->setValidator(new QIntValidator(0,9999999,this));

     //// controle de saisie sue les chaines
         QRegularExpression rx("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",QRegularExpression::CaseInsensitiveOption);
                 ui->lineEdit_nom_s->setValidator(new QRegularExpressionValidator(rx, this));

          QRegularExpression rx1("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",QRegularExpression::CaseInsensitiveOption);
                  ui->lineEdit_offre->setValidator(new QRegularExpressionValidator(rx, this));

          QRegularExpression rx2("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
                   ui->lineEdit_nom->setValidator(new QRegularExpressionValidator(rx, this));


         QRegularExpression rx3("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",QRegularExpression::CaseInsensitiveOption);
                   ui->lineEdit_disponibilite->setValidator(new QRegularExpressionValidator(rx, this));


/// map
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();

    auto obj = ui->quickWidget->rootObject();
    connect(this, SIGNAL(setCenter(QVariant,QVariant)), obj, SLOT(setCenter(QVariant,QVariant)));
    emit setCenter(25.000,50.000);



}
MainWindow::~MainWindow()
{
    delete ui;
}
 void MainWindow::on_pushButton_ajouter_clicked ()
 {

     int code_s = ui->lineEdit_code->text().toInt();
     QString nom_s = ui->lineEdit_nom_s->text();
     QString offre = ui->lineEdit_offre->text();
     QDate date_offre=ui->dateEditAjouter->date();
     float prix_s=ui->lineEdit_prix_s->text().toFloat();
     float prix_offre=ui->lineEdit_prix_offre->text().toFloat();
   Service S ( nom_s , offre ,  date_offre , prix_s, prix_offre, code_s ,"oui"); //instancer
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
    QModelIndex index=on_tableViewAfficherService_activated();
    int code_s =ui->tableViewAfficherService->model()->data(ui->tableViewAfficherService->model()->index(index.row(),0)).toInt();
    bool test=S.supprimer(code_s);
    if(test)
    {
        QMessageBox :: information(nullptr , QObject :: tr("ok"),QObject::tr("supprimer effectue\n"),QObject::tr("click cancel to exit"));
        //Refresh affichage
        ui->tableViewAfficherService->setModel(S.afficher());
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
    S.setprix_s(ui->lineEdit_prix->text().toFloat());
    S.setprix_offre(ui->lineEdit_prix_offre_2->text().toFloat());
    S.setdate_offre(ui->date_offre_modifier->date());
    S.setdisponibilite(ui->lineEdit_disponibilite->text());
    S.setnom_s(ui->lineEdit_nom->text());
    //modifier requete************
    QModelIndex index=on_tableViewAfficherService_activated();
    int code_s =ui->tableViewAfficherService->model()->data(ui->tableViewAfficherService->model()->index(index.row(),0)).toInt();
    bool test2=S.modifier(code_s);
    if(test2)
    {
        //Refresh affichage
        ui->tableViewAfficherService->setModel(S.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectue\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectue"),QObject::tr("click cancel to exit"));
    }
}


  void MainWindow::on_pushButtonafficher_clicked()
  {
       ui->tableViewAfficherService->setModel(S.afficher());
  }







  void MainWindow::on_lineEdit_chercher_cursorPositionChanged_textChanged()
{
    QString i=ui->lineEdit_chercher_cursorPositionChanged->text();
    ui->tableViewAfficherService->setModel(S.rechercheavancee(i));

}






  ////PDF

  void MainWindow::on_pushButton_pdf_clicked()
  {

      QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                         "/home",
                                                         QFileDialog::ShowDirsOnly
                                                         | QFileDialog::DontResolveSymlinks);
             qDebug()<<dir;
             QPdfWriter pdf(dir+"/PdfService.pdf");                                 QPainter painter(&pdf);
                                      int i = 4000;
                                           painter.setPen(Qt::red);

                                           painter.setFont(QFont("Arial", 30));
                                           painter.drawText(2100,1200,"Liste Des services");
                                           painter.setPen(Qt::black);
                                           painter.setFont(QFont("Arial", 50));
                                           painter.drawRect(1000,200,6500,2000);
                                           painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/Samar/Desktop/image/pddf.png"));
                                           painter.drawRect(0,3000,9600,500);
                                           painter.setFont(QFont("Arial", 9));
                                           painter.setPen(Qt::blue);
                                           painter.drawText(300,3300,"CODE_S");
                                           painter.drawText(2300,3300,"NOM_S");
                                           painter.drawText(4300,3300,"PRIX_s");
                                           painter.drawText(6300,3300,"DISPONIBILITE");
                                           painter.drawText(8300,3300,"OFFRE");
                                           painter.drawText(10300,3300,"DATE_OFFRE");
                                           painter.drawText(12300,3300,"PRIX_OFFRE");

                                           QSqlQuery query;
                                           query.prepare("select * from SERVICES");
                                           query.exec();
                                           while (query.next())
                                           {
                                               painter.drawText(300,i,query.value(0).toString());
                                               painter.drawText(2300,i,query.value(1).toString());
                                               painter.drawText(4300,i,query.value(2).toString());
                                               painter.drawText(6300,i,query.value(3).toString());



                                              i = i +500;
                                           }
                                           int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                                               QMessageBox::Yes |  QMessageBox::No);
                                               if (reponse == QMessageBox::Yes)
                                               {
                                                   QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PdfService.pdf"));

                                                   painter.end();
                                               }
                                               else
                                               {
                                                    painter.end();


  }
  }

///// video

void MainWindow::on_pushButton_folder_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File(*.*)");
    on_pushButton_stop_clicked();
    player->setMedia(QUrl::fromLocalFile(filename));
    on_pushButton_play_clicked();


    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);
    this->setCentralWidget(vw);
}

void MainWindow::on_pushButton_play_clicked()
{

   player->play();
   ui->statusBar->showMessage("playing");

}


void MainWindow::on_pushButton_pause_clicked()
{
    player->pause();
    ui->statusBar->showMessage("Paused...");
}

void MainWindow::on_pushButton_stop_clicked()
{
    player->stop();
    ui->statusBar->showMessage("Stoping");
}




QModelIndex MainWindow::on_tableViewAfficherService_activated()
{
    return ui->tableViewAfficherService->currentIndex();
}

void MainWindow::on_pushButton_retour_modifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
