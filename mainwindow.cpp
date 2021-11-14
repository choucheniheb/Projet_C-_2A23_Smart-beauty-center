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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //
    //
 /* ui->comboBox->addItem("parfums");
 ui->comboBox->addItem("cosmetiques");
  ui->comboBox->addItem("makeup"); */
  //
    ui->setupUi(this);

    ui->code_edit->setValidator ( new QIntValidator(0, 9999999, this));
    ui->prixu_edit->setValidator ( new QIntValidator(0, 9999999, this));
    ui->prixp_edit->setValidator ( new QIntValidator(0, 9999999, this));

   // ui->prixp_edit->setValidator ( new QDoubleValidator(0, 9999999, this));

    ui->lineEditcodeabarresupprimer->setValidator ( new QIntValidator(0, 9999999, this));
    ui->codeabarrem->setValidator ( new QIntValidator(0, 9999999, this));
    ui->nbreEdit->setValidator ( new QIntValidator(0, 9999999, this));
    ui->nbreEdit_1->setValidator ( new QIntValidator(0, 9999999, this));

    QRegularExpression rx("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                  QRegularExpression::CaseInsensitiveOption);
        ui->nom_edit->setValidator(new QRegularExpressionValidator(rx, this));

        QRegularExpression rx1("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                      QRegularExpression::CaseInsensitiveOption);
            ui->categorie_edit->setValidator(new QRegularExpressionValidator(rx, this));

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
int w7 = ui->label_10->width();
int h7 = ui->label_10->height();

int w14 = ui->label_14->width();
int h14 = ui->label_14->height();
//
int w16 = ui->label_16->width();
int h16 = ui->label_16->height();
//
int w17 = ui->label_17->width();
int h17 = ui->label_17->height();
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
     ui->label_10->setPixmap(pix7.scaled(w7,h7,Qt::KeepAspectRatio));
     ui->label_14->setPixmap(pix14.scaled(w14,h14,Qt::KeepAspectRatio));

     ui->label_16->setPixmap(pix16.scaled(w16,h16,Qt::KeepAspectRatio));

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


MainWindow::~MainWindow()
{
    delete ui;
}


//ajout///////////

void MainWindow::on_aj_button_clicked()
{
    //code a barre
    int code_a_barre=ui->code_edit->text().toInt();
    ui->code_edit->clear();
    //nom
   QString nom_produit=ui->nom_edit->text();
   ui->nom_edit->clear();
   //prix uni
   float prix_uni=ui->prixu_edit->text().toFloat();
   ui->prixu_edit->clear();
   float prix_promo=ui->prixp_edit->text().toFloat();
   ui->prixp_edit->clear();
   //
   QString categorie=ui->categorie_edit->text();
    ui->categorie_edit->clear();

   QString date_expiration=ui->date_edit->text();
   ui->date_edit->clear();

   int quantite_produit=ui-> nbreEdit->text().toInt();
   ui->nbreEdit->clear();



produit p (code_a_barre,nom_produit,prix_uni,prix_promo,categorie, date_expiration, quantite_produit);
bool test=p.ajouter();
 if (test)
{
     if (quantite_produit < 10)
       {
           QMessageBox::warning(this,"WARNING","la quantité du produit est très peu");
       }

    //Refresh affichage
    ui->tableViewproduit->setModel(p.afficher());
    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectuer\n"),QObject::tr("click cancel to exit"));
}else if ((categorie != "parfums" && categorie !="cosmetique" && categorie !="makeup") || (prix_uni < prix_promo) || (quantite_produit=0))
{
    QMessageBox::critical(nullptr,QObject::tr(" non ok"),QObject::tr("ajouter non effectuer"),QObject::tr("click cancel to exit"));
}
}



//supprimer///////////


void MainWindow::on_pushButtonSupprimer_clicked()
{

int code_a_barre=ui->lineEditcodeabarresupprimer->text().toInt();
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
p.setquantite_produit(ui->nbreEdit_1->text().toInt());
int quantite_produit=ui-> nbreEdit_1->text().toInt();


//modifier requete************
int code_a_barre=ui->codeabarrem->text().toInt();
bool test2=p.modifier(code_a_barre);
if(test2)
{
    if (quantite_produit < 10)
      {
          QMessageBox::warning(this,"WARNING","la quantité du produit est très peu");
      }

    //Refresh affichage
    ui->tableViewproduit->setModel(p.afficher());
    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectuer\n"),QObject::tr("click cancel to exit"));
}else
{
    QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectuer"),QObject::tr("click cancel to exit"));
        }

}


void MainWindow::lineEdit_produitrechercher_cursorPositionChanged()
{
    QString i=ui->lineEdit_produitrechercher->text();
    ui->tableViewproduit->setModel(p.rechercheMulticritere(i));
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

void MainWindow::on_pushButtonModifier2_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_categorie_bottom_clicked()
{
    ui->stackedWidget2->setCurrentIndex(0);
}




void MainWindow::on_codeabarre1_clicked()
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

void MainWindow::on_codeabarre1_2_clicked()
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

void MainWindow::on_codeabarre1_3_clicked()
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

