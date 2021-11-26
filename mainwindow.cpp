#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include<QPixmap>
#include<QLabel>
#include<QString>
#include<QMessageBox>
#include<QApplication>
#include<QtWidgets>
#include<QMainWindow>
#include<QFileDialog>
#include<QLabel>
#include "notification.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //

  //
    ui->setupUi(this);

    ui->code_edit_produit->setValidator ( new QIntValidator(0, 9999999, this));
    ui->prixu_edit_produit->setValidator ( new QIntValidator(0, 9999999, this));
    ui->prixp_edit_produit->setValidator ( new QIntValidator(0, 9999999, this));
    ui->prixu_edit_1_produit->setValidator ( new QIntValidator(0, 9999999, this));
    ui->prixp_edit_1_produit->setValidator ( new QIntValidator(0, 9999999, this));
   // ui->prixp_edit->setValidator ( new QDoubleValidator(0, 9999999, this));


    ui->nbreEdit_produit->setValidator ( new QIntValidator(0, 9999999, this));
    ui->nbreEdit_1_produit->setValidator ( new QIntValidator(0, 9999999, this));

    QRegularExpression rx("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                  QRegularExpression::CaseInsensitiveOption);
        ui->nom_edit_produit->setValidator(new QRegularExpressionValidator(rx, this));

        QRegularExpression rx1("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                      QRegularExpression::CaseInsensitiveOption);
            ui->categorie_edit_produit->setValidator(new QRegularExpressionValidator(rx, this));

    //
     QPixmap pix("C:/Users/HP/Desktop/image/makeup.jpg");
     QPixmap pix1("C:/Users/HP/Desktop/image/cosmetics.jpg");
       QPixmap pix2("C:/Users/HP/Desktop/image/bc.png");
       QPixmap pix3("C:/Users/HP/Desktop/image/k1.png");
       QPixmap pix4("C:/Users/HP/Desktop/image/parfums.jpg");
       QPixmap pix5("C:/Users/HP/Desktop/image/555.png");
       QPixmap pix6("C:/Users/HP/Desktop/image/mqqq11.png");
       QPixmap pix7("C:/Users/HP/Desktop/image/modifier.png");
      QPixmap pix14("C:/Users/HP/Desktop/image/99.png");
      QPixmap pix16("C:/Users/HP/Desktop/image/modifier1.png");
      QPixmap pix17("C:/Users/HP/Desktop/image/modifier1.png");
    // background1
      // int w = ui->label_bc->width();
   // int h = ui->label_bc->height();
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
int w17 = ui->label_17->width();
int h17 = ui->label_17->height();
    //cos
    ui->label_cos->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));
    //mq
    ui->label_mq->setPixmap(pix.scaled(w2,h2,Qt::KeepAspectRatio));

      //background categorie
    ui->label_bc_2->setPixmap(pix3.scaled(w3,h3,Qt::KeepAspectRatio));
    // background parfums
    ui->label_parfums->setPixmap(pix4.scaled(w4,h4,Qt::KeepAspectRatio));
    //ajouter
    ui->label_aa->setPixmap(pix5.scaled(w5,h5,Qt::KeepAspectRatio));
    //
     ui->label_mq1->setPixmap(pix6.scaled(w6,h6,Qt::KeepAspectRatio));
     //
      ui->label_17->setPixmap(pix17.scaled(w17,h17,Qt::KeepAspectRatio));

 //IMAGE ANIMEE///////////////
     ui->label_12->setMask((new QPixmap("C:/Users/HP/Desktop/image/promo9.gif"))->mask());
     QMovie *movie = new QMovie ("C:/Users/HP/Desktop/image/promo9.gif");
     ui->label_12->setMovie(movie);
     movie->start();
     ui->label_12->show();
//
     //code a barre metier/////////
           QPixmap pixc("C:/Users/HP/Desktop/code a barre (produits)/code a barre produit1.jpg");
           ui->label_picc->setPixmap(pixc);

                 QPixmap pixc1("C:/Users/HP/Desktop/code a barre (produits)/code a barre produit1.jpg");
                 ui->label_picc1->setPixmap(pixc1);
                 QPixmap pixc2("C:/Users/HP/Desktop/code a barre (produits)/code a barre produit1.jpg");
                 ui->label_picc2->setPixmap(pixc2);
}

//


MainWindow::~MainWindow()
{
    delete ui;
}


//ajout///////////

void MainWindow::on_aj_button_clicked()
{
    //code a barre
    int code_a_barre=ui->code_edit_produit->text().toInt();
    ui->code_edit_produit->clear();
    //nom
   QString nom_produit=ui->nom_edit_produit->text();
   ui->nom_edit_produit->clear();
   //prix uni
   float prix_uni=ui->prixu_edit_produit->text().toFloat();
   ui->prixu_edit_produit->clear();
   float prix_promo=ui->prixp_edit_produit->text().toFloat();
   ui->prixp_edit_produit->clear();
   //
   QString categorie=ui->categorie_edit_produit->text();
    ui->categorie_edit_produit->clear();

   QString date_expiration=ui->date_edit_produit->text();
   ui->date_edit_produit->clear();

   int quantite_produit=ui-> nbreEdit_produit->text().toInt();
   ui->nbreEdit_produit->clear();



produit p (code_a_barre,nom_produit,prix_uni,prix_promo,categorie, date_expiration, quantite_produit);
bool test=p.ajouter();
 if (test)
{
     QString c=QString::number(code_a_barre);
     QString message2="ajouter une produit"+c;
    // p.historique_produit(message2);
    //Refresh affichage
    ui->tableViewproduit->setModel(p.afficher());
   // ui->tableView_hist->setModel(p.afficher_historique_produit());

    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectuer\n"),QObject::tr("click cancel to exit"));
   histo.save("code_a_barre:"+ui->code_edit_produit->text(),"nom_p :"+ui->nom_edit_produit->text(),"prix_uni :"+ui->prixu_edit_produit->text(),"prix_promo :"+ui->prixp_edit_produit->text(),"categorie :"+ui->categorie_edit_produit->text(),"date_expiration :"+ui->date_edit_produit->text(),"quantite_produit :"+ui->nbreEdit_produit->text());
}else if ((categorie != "parfums" || categorie !="cosmetique" || categorie !="makeup") || (prix_uni < prix_promo) || (quantite_produit=0))
{
    QMessageBox::critical(nullptr,QObject::tr(" non ok"),QObject::tr("ajouter non effectuer"),QObject::tr("click cancel to exit"));
}
 QSqlQuery query;
 query.prepare("select quantite_produit from produit where quantite_produit < 6");
 query.exec();
 query.next();
 int q=query.value(0).toInt();
 QString nom=query.value(0).toString();
 if(q<=6)
 {
     notification n;
     n.notification_system();
 }

}



//supprimer///////////


void MainWindow::on_pushButtonSupprimer_clicked()
{
    QModelIndex index=on_tableViewproduit_activated();
    int code_a_barre=ui->tableViewproduit->model()->data(ui->tableViewproduit->model()->index(index.row(),0)).toInt();
bool test1=p.supprimer(code_a_barre);
if(test1)
{
    QString c=QString::number(code_a_barre);
    QString message2="supprimer une produit"+c;
  //  p.historique_produit(message2);
    //Refresh affichage
    ui->tableViewproduit->setModel(p.afficher());
   // ui->tableView_hist->setModel(p.afficher_historique_produit());
    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectuer\n"),QObject::tr("click cancel to exit"));
}else
{
    QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectuer"),QObject::tr("click cancel to exit"));
}
}
void MainWindow::on_pushButtonModifier_clicked()
{
ui->stackedWidget_3->setCurrentIndex(1);
}
void MainWindow::on_pushButtonModifier2_clicked()
{
//modifier les valeur de class
//c.setdate(ui->dateTimeEdit_modifier->text().to)
p.setprix_uni(ui->prixu_edit_1_produit->text().toFloat());
p.setprix_promo(ui->prixp_edit_1_produit->text().toFloat());
p.setquantite_produit(ui->nbreEdit_1_produit->text().toInt());

//modifier requete************
QModelIndex index=on_tableViewproduit_activated();
int code_a_barre=ui->tableViewproduit->model()->data(ui->tableViewproduit->model()->index(index.row(),0)).toInt();
bool test2=p.modifier(code_a_barre);
if(test2)
{
    QString c=QString::number(code_a_barre);
    QString message2="modifier une produit"+c;
    //p.historique_produit(message2);
    ui->stackedWidget_3->setCurrentIndex(0);
    //Refresh affichage
    ui->tableViewproduit->setModel(p.afficher());
   // ui->tableView_hist->setModel(p.afficher_historique_produit());
    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectuer\n"),QObject::tr("click cancel to exit"));
}else
{
    QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectuer"),QObject::tr("click cancel to exit"));
        }

QSqlQuery query;
query.prepare("select quantite_produit from produit where quantite_produit < 6");
query.exec();
query.next();
int q=query.value(0).toInt();
QString nom=query.value(0).toString();
if(q<=6)
{
    notification n;
    n.notification_system();
}


}


void MainWindow::on_lineEdit_chercher_cursorPositionChanged_textChanged()
{
    QString i=ui->lineEdit_chercher_cursorPositionChanged_produit->text();
    ui->tableViewproduit->setModel(p.rechercheMulticritere(i));
}

//


void MainWindow::on_makeup_bottom_produit_clicked()
{
    ui->stackedWidget2->setCurrentIndex(1);
}
void MainWindow::on_cosmetiques_bottom_produit_clicked()
{
    ui->stackedWidget2->setCurrentIndex(2);
}
void MainWindow::on_parfums_bottom_produit_clicked()
{
    ui->stackedWidget2->setCurrentIndex(3);
}

void MainWindow::on_pushButtonModifier2_2_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}

void MainWindow::on_categorie_bottom_clicked()
{
    ui->stackedWidget2->setCurrentIndex(0);
}




void MainWindow::on_codeabarre1_produitclicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName =QFileDialog::getOpenFileName(this, tr("Open Images"), "C:/Users/HP\Desktop/code a barre (produits)", tr("Image Files (*.png *.jpg *.bmp)"));
//to select and show the picture
    if (!fileName.isEmpty())
    {
        QImage image(fileName);
            ui->label_picc->setPixmap(QPixmap::fromImage(image));
    }
}

void MainWindow::on_codeabarre1_2_produitclicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName =QFileDialog::getOpenFileName(this, tr("Open Images"), "C:/Users/HP\Desktop/code a barre (produits)", tr("Image Files (*.png *.jpg *.bmp)"));
//to select and show the picture
    if (!fileName.isEmpty())
    {
        QImage image(fileName);
            ui->label_picc1->setPixmap(QPixmap::fromImage(image));
    }
}


void MainWindow::on_codeabarre1_3_produitclicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName =QFileDialog::getOpenFileName(this, tr("Open Images"), "C:/Users/HP\Desktop/code a barre (produits)", tr("Image Files (*.png *.jpg *.bmp)"));
//to select and show the picture
    if (!fileName.isEmpty())
    {
        QImage image(fileName);
            ui->label_picc2->setPixmap(QPixmap::fromImage(image));
    }
}


QModelIndex MainWindow::on_tableViewproduit_activated()
{
    return  ui->tableViewproduit->currentIndex();
}

void MainWindow::on_pushButton_refrech_clicked()
{
    ui->tableViewproduit->setModel(p.afficher());
   // ui->tableView_hist->setModel(p.afficher_historique_produit());
    QSqlQuery query;
    query.prepare("select quantite_produit from produit where quantite_produit < 6");
    query.exec();
    query.next();
    int q=query.value(0).toInt();
    QString nom=query.value(0).toString();
    if(q<=6)
    {
        notification n;
        n.notification_system();
    }


}

void MainWindow::on_historiqueButton_clicked()
{
    QFile file("C:/Users/HP/Desktop/historique.txt");
        if (!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"info",file.errorString());
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());

}
