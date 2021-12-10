#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QMessageBox>
#include <QFile>
#include <QTextStream>
#include<QDate>
#include<QDebug>
#include <QFileDialog>
#include <QTcpSocket>
#include"notification.h"
#include "dumessengerconnectiondialog.h"
#include <QString>
#include <QIntValidator>

//*******************************************************
#include <QDesktopServices>
#include <QUrl>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QApplication>
//********************************************************
#include <QLabel>
#include <QMainWindow>
#include <QtWidgets>
//***********************************************************
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
#include <QUrl>
//*****************************************************************
#include <QPixmap>
#include "employers.h"
#include <QMessageBox>
#include <QValidator>
#include <QDebug>
#include <QPainter>
#include <QPdfWriter>
#include "smtp.h"
#include <QDateTime>
#include "employers.h"

#include <QAbstractSocket>

#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include <QPrintDialog>

#include <QSystemTrayIcon>
#include <QValidator>
#include"notification.h"

//*******************************QRCODE****************************************
#include <string>
#include <vector>
#include<QDirModel>
#include <qrcode.h>
#include <string>
#include <iostream>
#include <fstream>
#include <QtSvg/QSvgRenderer>



#include <string>
#include <vector>
#include<QDirModel>
#include <qrcode.h>

#include <iostream>
#include <fstream>
#include <QtSvg/QSvgRenderer>
#include "qrcode.h"
#include <QSound>
#include <QMediaPlaylist>
#include "notification_samar.h"
//*********************************************************************************************



using qrcodegen::QrCode;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //**********************Arduino*****************************
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     //QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label_wajdi_nourhene())); // permet de lancer
     //QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label_iheb_arij())); // permet de lancer
     //QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label_aziz_samar())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
    //***************************************************
    mSocket=new QTcpSocket(this);
    connect(mSocket,&QTcpSocket::readyRead,[&](){
        QTextStream T(mSocket);
       auto text=T.readAll();
       ui->textEdit->append(text);
       ui->textEdit_employer->append(text);
    });
     ui->tableViewAficherfournisseur->setModel(f.afficher());
     //************************
     timer = new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
     timer->start(1000);
     //************************
     QWidget::showMaximized();
/****************************************************/
     ui->stackedWidget_integration->setCurrentIndex(6);
     ui->stackedWidget_produit->setCurrentIndex(0);
     ui->stackedWidget_fournisseur->setCurrentIndex(0);
     ui->stackedWidget_client->setCurrentIndex(0);
     ui->stackedWidget_employer->setCurrentIndex(0);
     ui->stackedWidget_service->setCurrentIndex(0);
//*********************************************************/


// controle de  saisie wajdi
ui->lineEdit_num_fournisseur->setValidator(new QIntValidator(0,99999999,this));
ui->lineEdit_code_fournisseur->setValidator(new QIntValidator(0,9999,this));
QRegularExpression rx("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
 QRegularExpression::CaseInsensitiveOption);
ui->lineEdit_nom_fournisseur->setValidator(new QRegularExpressionValidator(rx, this));
QRegularExpression rx1("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",QRegularExpression::CaseInsensitiveOption);
ui->lineEdit_produit_vendu_fournisseur->setValidator(new QRegularExpressionValidator(rx, this));
QRegularExpression rx2("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",QRegularExpression::CaseInsensitiveOption);
ui->lineEdit_produit_modifier_fournisseur->setValidator(new QRegularExpressionValidator(rx, this));

//controle de saisie iheb
ui->stackedWidget_facture->setCurrentIndex(0);
ui->dateTimeEdit_modifier_facture->setDateTime(QDateTime::currentDateTime());
//ajouter**************
ui->lineEdit_num_fact_facture->setValidator ( new QIntValidator(0, 999999999, this));
ui->lineEdit_prix_unitaire_facture->setValidator ( new QIntValidator(0, 999999999, this));
ui->lineEdit_quantite_facture->setValidator ( new QIntValidator(0, 999999999, this));
ui->lineEdit_prix_totale_facture->setValidator ( new QIntValidator(0, 999999999, this));
//modifier***************
ui->lineEdit_prix_u_modifier_facture->setValidator ( new QIntValidator(0, 999999999, this));
ui->lineEdit_quntiter_modifier_facture->setValidator ( new QIntValidator(0, 999999999, this));
ui->lineEdit_prix_t_modifier_facture->setValidator ( new QIntValidator(0, 999999999, this));
//controle de saisie nourhen
    ui->prixu_edit_produit->setValidator ( new QIntValidator(0, 9999999, this));
    ui->prixp_edit_produit->setValidator ( new QIntValidator(0, 9999999, this));
    ui->prixu_edit_1_produit->setValidator ( new QIntValidator(0, 9999999, this));
    ui->prixp_edit_1_produit->setValidator ( new QIntValidator(0, 9999999, this));
   // ui->prixp_edit->setValidator ( new QDoubleValidator(0, 9999999, this));
    ui->nbreEdit_produit->setValidator ( new QIntValidator(0, 9999999, this));
    ui->nbreEdit_1_produit->setValidator ( new QIntValidator(0, 9999999, this));
    ui->nom_edit_produit->setValidator(new QRegularExpressionValidator(rx, this));
    ui->categorie_edit_produit->setValidator(new QRegularExpressionValidator(rx, this));

 //IMAGE ANIMEE///////////////
     ui->label_22->setMask((new QPixmap("C:/Users/Ihebc/OneDrive/Desktop/integration/image integration/promo9.gif"))->mask());
     QMovie *movie = new QMovie ("C:/Users/Ihebc/OneDrive/Desktop/integration/image integration/promo9.gif");
     ui->label_22->setMovie(movie);
     movie->start();
     ui->label_22->show();
//
     //code a barre metier/////////
           QPixmap pixc("C:/Users/HP/Desktop/code a barre (produits)/code a barre produit1.jpg");
           ui->label_picc->setPixmap(pixc);

                 QPixmap pixc1("C:/Users/HP/Desktop/code a barre (produits)/code a barre produit1.jpg");
                 ui->label_picc1->setPixmap(pixc1);
                 QPixmap pixc2("C:/Users/HP/Desktop/code a barre (produits)/code a barre produit1.jpg");
                 ui->label_picc2->setPixmap(pixc2);
//controle de saisie aziz
                 ui->lineEdit_id_client_3->setValidator(new QIntValidator(0,999999,this));
                 ui->lineEdit_Pf_client_3->setValidator(new QIntValidator(0,1000,this));
                 ui->lineEdit_Num_client_3->setValidator(new QIntValidator(0,99999999,this));
                 QRegularExpression rx15000("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                                           QRegularExpression::CaseInsensitiveOption);
                 ui->lineEdit_EM_client_3->setValidator(new QRegularExpressionValidator(rx, this));
                 connect(ui->sendBtn_client_3,SIGNAL(clicked()),this,SLOT(sendMail()));
                 connect(ui->exitBtn_client_3, SIGNAL(clicked()),this, SLOT(close()));
                  connect(ui->browseBtn_client_3, SIGNAL(clicked()), this, SLOT(browse()));
//saisie samar******************************************************************************
                  //// controle de saisie sur les entiers et reels
                        ui->lineEdit_code->setValidator(new QIntValidator(0,9999999,this));

                        ui->lineEdit_prix_s->setValidator(new QIntValidator(0,9999999,this));
                        ui->lineEdit_prix_offre->setValidator(new QIntValidator(0,9999999,this));

                    //// controle de saisie sue les chaines
                        QRegularExpression rx30("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",QRegularExpression::CaseInsensitiveOption);
                                ui->lineEdit_nom_s->setValidator(new QRegularExpressionValidator(rx30, this));
                                 ui->lineEdit_offre->setValidator(new QRegularExpressionValidator(rx30, this));
                                  ui->lineEdit_nom->setValidator(new QRegularExpressionValidator(rx30, this));
                                  ui->lineEdit_disponibilite->setValidator(new QRegularExpressionValidator(rx30, this));
//saisie arij******************************************************************************************************************3
                                  //AJOUTER
                                          ui->lineEdit_id_employer_employer->setValidator ( new QIntValidator(0, 99999999, this));
                                          ui->lineEdit_telephone_employer->setValidator ( new QIntValidator(0, 99999999, this));
                                          QRegularExpression rx18("\\b[A-Z._%+-]+ [A-Z.-]+\\[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
                                                      ui->lineEdit_nom_employer->setValidator(new QRegularExpressionValidator(rx18, this));
                                                      ui->lineEdit_prenom_employer->setValidator(new QRegularExpressionValidator(rx18, this));
                                                                 ui->lineEdit_type_employer->setValidator(new QRegularExpressionValidator(rx18, this));
                                                                 ui->lineEdit_specialite_employer->setValidator(new QRegularExpressionValidator(rx18, this));
                                  //MODIFIER
                                          ui->lineEdit_telephone_e_modifier->setValidator ( new QIntValidator(0, 99999999, this));
                                                                 ui->lineEdit_type_modifier->setValidator(new QRegularExpressionValidator(rx18, this));
                                                                 ui->lineEdit_specialite_modifier->setValidator(new QRegularExpressionValidator(rx18, this));

                                  connect(ui->sendBtn_6,SIGNAL(clicked()),this,SLOT(sendMail_employer()));
                                  connect(ui->exitBtn_6, SIGNAL(clicked()),this, SLOT(close()));
                                   connect(ui->browseBtn_6, SIGNAL(clicked()), this, SLOT(browse_employer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::update_label_wajdi_nourhene()
{
    data=A.read_from_arduino();
    ch+=data;
    A.write_to_arduino("1");
    QSqlQuery query;
    query.prepare("select prix_uni from produit where code_a_barre= :code_a_barre");
    query.bindValue(":code_a_barre",ch);
    query.exec();
    query.next();
    QString d=query.value(0).toString();
    qDebug()<<d;
    data=A.read_from_arduino();





}

void MainWindow::update_label_iheb_arij()
{
    data=A.read_from_arduino();

    if(data=="9")
    {
        ui->stackedWidget_integration->setCurrentIndex(7);
        int c=A.write_to_arduino("2");
    }

    else  if (data=="0")
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("acces non autorise"),QObject::tr("click cancel to exit"));
    }
}


void MainWindow::update_label_aziz_samar()
{
    data=A.read_from_arduino();
    Notification_SAMAR n;
        if(data=="7") {


           n.Notification_system();

            }
        else if (data=="8")
            n.Notification_sys();
}

void MainWindow::on_pushButton_alarme_clicked()   // implémentation du slot bouton on
{
     A.write_to_arduino("7"); //envoyer 1 à arduino
}


void MainWindow::on_pushButton_alarme2_clicked()   // implémentation du slot bouton on
{
     A.write_to_arduino("8"); //envoyer 1 à arduino
}




void MainWindow::on_comboBox_a_activated(const QString &arg1)
{
    if (ui->comboBox_a->currentText()== "ON")
    {
        A.write_to_arduino("7");

    } else
        if (ui->comboBox_a->currentText()== "OFF")
        {
        A.write_to_arduino("8");
        }


}



void MainWindow::on_pushButton_ajouter_fournisseur_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    //recuperation
   QString nom_f=ui->lineEdit_nom_fournisseur->text();

    float prix_gros=ui->lineEdit_prix_gros_fournisseur->text().toFloat();

    int num_f=ui->lineEdit_num_fournisseur->text().toUInt();

    int code_f=ui->lineEdit_code_fournisseur->text().toUInt();

     QString produit_vendu=ui->lineEdit_produit_vendu_fournisseur->text();
    fournisseur f(num_f,code_f,prix_gros,nom_f,produit_vendu);//instancer
    bool test=f.ajouter();
    if(test)
    {
        ui->tableViewAficherfournisseur->setModel(f.afficher());//rafraishissement
        hist_wajdi.save_wajdi("code_f:"+ui->lineEdit_code_fournisseur->text(),"nom :"+ui->lineEdit_nom_fournisseur->text(),"num_f :"+ui->lineEdit_num_fournisseur->text(),"prix_gros :"+ui->lineEdit_prix_gros_fournisseur->text(),"produit_vendu :"+ui->lineEdit_produit_vendu_fournisseur->text());
        //clear*********************
        ui->lineEdit_nom_fournisseur->clear();
        ui->lineEdit_prix_gros_fournisseur->clear();
        ui->lineEdit_num_fournisseur->clear();
        ui->lineEdit_code_fournisseur->clear();
        ui->lineEdit_produit_vendu_fournisseur->clear();
        //*****************************
        QMessageBox::information(nullptr, QObject::tr("fournisseur ajouté"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("fournisseur non ajouté"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }



/********************************************************************/



void MainWindow::on_pushButtonSupprimer_fournisseur_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QModelIndex index=on_tableViewAficherfournisseur_activated();
    int code_f=ui->tableViewAficherfournisseur->model()->data(ui->tableViewAficherfournisseur->model()->index(index.row(),0)).toInt();
    bool test1=f.supprimer(code_f);
    if(test1)
    {
        ui->tableViewAficherfournisseur->setModel(f.afficher());//rafraishissement
        QMessageBox::information(nullptr, QObject::tr("fournisseur supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("fournisseur non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

/*********************************************/


void MainWindow::on_pushButtonModifier_fournisseur_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_fournisseur->setCurrentIndex(3);
}
void MainWindow::on_pushButtonRetourMod_fournisseur_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_fournisseur->setCurrentIndex(2);
}
void MainWindow::on_pushButtonModifier2_fournisseur_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    //modifier les valeur de class

    f.setproduit_vendu(ui->lineEdit_produit_modifier_fournisseur->text());
   f.setprix_gros(ui->lineEdit_prix_modifier_fournisseur->text().toInt());


    //modifier requete************
   QModelIndex index=on_tableViewAficherfournisseur_activated();
   int code_f=ui->tableViewAficherfournisseur->model()->data(ui->tableViewAficherfournisseur->model()->index(index.row(),0)).toInt();
    bool test2=f.modifier(code_f);

    if(test2)
    {
        ui->tableViewAficherfournisseur->setModel(f.afficher());//rafraishissement
        QMessageBox::information(nullptr, QObject::tr("fournisseur modifié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->stackedWidget_fournisseur->setCurrentIndex(2);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("fournisseur non modifié"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }







void MainWindow::on_pushButtonafficher_fournisseur_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->tableViewAficherfournisseur->setModel(f.afficher());
    QSqlQuery query;
    QString res = QDate::currentDate().toString();
    qDebug()<<res;
    query.prepare("select DATE_LIVRAISON from livrer where DATE_LIVRAISON = :DATE_LIVRAISON");
    query.bindValue(":DATE_LIVRAISON",res);
    query.exec();
    query.next();
    QString date=query.value(0).toString();
    qDebug()<<date;
    QString a=QDate::currentDate().toString();
    if(date==a)
    {
        notification n;
        n.notification_livrer();
    }
}


void MainWindow::on_lineEdit_chercher_fournisseur_textChanged()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QString i=ui->lineEdit_chercher_fournisseur->text();
    ui->tableViewAficherfournisseur->setModel(f.rechercheMulticritere(i));
}

QModelIndex MainWindow::on_tableViewAficherfournisseur_activated()
{
    return ui->tableViewAficherfournisseur->currentIndex();



}

void MainWindow::on_pushButton_excel_fournisseur_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QTableView *table;
                   table = ui->tableViewAficherfournisseur;

                   QString filters("xlsx files (.xlsx);;All files (.*)");
                   QString defaultFilter("CSV files (*.xlsx)");
                   QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                      filters, &defaultFilter);
                   QFile file(fileName);

                   QAbstractItemModel *model =  table->model();
                   if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                       QTextStream data(&file);
                       QStringList strList;
                       for (int i = 0; i < model->columnCount(); i++) {
                           if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                               strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") << "\n";
                       for (int i = 0; i < model->rowCount(); i++) {
                           strList.clear();
                           for (int j = 0; j < model->columnCount(); j++) {

                               if (model->data(model->index(i, j)).toString().length() > 0)
                                   strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                               else
                                   strList.append("");
                           }
                           data << strList.join(";") + "\n";
                       }
                       file.close();
                       QMessageBox::information(nullptr, QObject::tr("Export excel"),
                                                 QObject::tr("Export avec succes .\n"
                                                             "Click OK to exit."), QMessageBox::Ok);
        }
}

void MainWindow::on_pb_envoyer_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QTextStream T(mSocket);
    T<<ui->le_nickname->text()<<": "<<ui->le_message->text();
    mSocket->flush();
    ui->le_message->clear();
}

void MainWindow::on_pb_connecter_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    {
    dumessengerconnectiondialog D(this);
    if(D.exec()==QDialog::Rejected)
    {
        return;

    }
    mSocket->connectToHost(D.hostname(),D.port());

    }
}

void MainWindow::on_pushButtonAjouter_facture_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    //recuperation
    int num_f=ui->lineEdit_num_fact_facture->text().toInt();
    ui->lineEdit_num_fact_facture->clear();
    QDate date=QDate::currentDate();
    float prix_u=ui->lineEdit_prix_unitaire_facture->text().toFloat();
    ui->lineEdit_prix_unitaire_facture->clear();
    int quantite=ui->lineEdit_quantite_facture->text().toInt();
    ui->lineEdit_quantite_facture->clear();
    int id_c=ui->comboBox_id_c_facture->currentText().toInt();
    float prix_t=ui->lineEdit_prix_totale_facture->text().toFloat();
    ui->lineEdit_prix_totale_facture->clear();
    caisse c(num_f,date,prix_u,quantite,prix_t,id_c);//instancer
    bool test=c.ajouter();

    if(test)
    {
        //Refresh affichage
        ui->tableViewAficherFacture_facture->setModel(c.afficher());
        //****************************************
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajouter non effectuer"),QObject::tr("click cancel to exit"));
    }
}



void MainWindow::on_pushButtonAfficher_facture_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->tableViewAficherFacture_facture->setModel(c.afficher());
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT num_facture from FACTURES");
    QSqlQueryModel *model1=new QSqlQueryModel();
    model1->setQuery("SELECT id_c from client");
    ui->comboBox_id_c_facture->setModel(model1);
}



void MainWindow::on_pushButtom_Pousser_facture_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QDesktopServices::openUrl(QUrl("https://www.coinbase.com/dashboard"));
}


void MainWindow::on_pushButtonSupprimer_facture_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QModelIndex index;
    index=on_tableViewAficherFacture_activated();
    int num_fact= ui->tableViewAficherFacture_facture->model()->data(ui->tableViewAficherFacture_facture->model()->index(index.row(),0)).toInt();
    bool test1=c.supprimer(num_fact);
    if(test1)
    {
        //Refresh affichage
        ui->tableViewAficherFacture_facture->setModel(c.afficher());
        //****************************************
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectuer"),QObject::tr("click cancel to exit"));
    }
}



void MainWindow::on_pushButtonModifier_facture_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_facture->setCurrentIndex(3);
    QSqlQuery query;
    QModelIndex index;
    index=on_tableViewAficherFacture_activated();
    QString res= ui->tableViewAficherFacture_facture->model()->data(ui->tableViewAficherFacture_facture->model()->index(index.row(),0)).toString();
    query.prepare("SELECT prix_unitaire from FACTURES WHERE num_facture= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    ui->lineEdit_prix_u_modifier_facture->setText(query.value(0).toString());
    query.prepare("SELECT prix_totale from FACTURES WHERE num_facture= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    ui->lineEdit_prix_t_modifier_facture->setText(query.value(0).toString());
    query.prepare("SELECT quantite_f from FACTURES WHERE num_facture= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    ui->lineEdit_quntiter_modifier_facture->setText(query.value(0).toString());
}


void MainWindow::on_pushButtonModifier2_facture_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    //modifier les valeur de class
    c.setdate(ui->dateTimeEdit_modifier_facture->date());
    c.setprix_unitair(ui->lineEdit_prix_u_modifier_facture->text().toFloat());
    ui->lineEdit_prix_u_modifier_facture->clear();
    c.setquantiter(ui->lineEdit_quntiter_modifier_facture->text().toInt());
    ui->lineEdit_quntiter_modifier_facture->clear();
    c.setprix_totale(ui->lineEdit_prix_t_modifier_facture->text().toFloat());
    ui->lineEdit_prix_t_modifier_facture->clear();

    //modifier requete************
    QModelIndex index;
    index=on_tableViewAficherFacture_activated();
    int num_fact= ui->tableViewAficherFacture_facture->model()->data(ui->tableViewAficherFacture_facture->model()->index(index.row(),0)).toInt();
    bool test2=c.modifier(num_fact);
    ui->stackedWidget_facture->setCurrentIndex(2);
    if(test2)
    {
        //Refresh affichage
        ui->tableViewAficherFacture_facture->setModel(c.afficher());
        //****************************************
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectuer"),QObject::tr("click cancel to exit"));
    }
}


void MainWindow::on_recette_facture_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_facture->setCurrentIndex(4);
    QSqlQuery query=c.calculerecette();
    query.exec();
    query.next();
    ui->lineEditRecette_facture->setText(query.value(0).toString());
}



void MainWindow::on_pushButtonRetourRecette_facture_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_facture->setCurrentIndex(0);
}



void MainWindow::on_pushButtonRetourModifier_facture_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_facture->setCurrentIndex(2);
}


void MainWindow::on_comboBoxCriter_facture_activated()
{
    if(ui->comboBoxCriter_facture->currentText()=="Tri par id")
    {
        ui->tableViewAficherFacture_facture->setModel(c.triParId());
    }else if(ui->comboBoxCriter_facture->currentText()=="Tri par date")
    {
        ui->tableViewAficherFacture_facture->setModel(c.triParDate());
    }else if(ui->comboBoxCriter_facture->currentText()=="Tri par prix")
    {
        ui->tableViewAficherFacture_facture->setModel(c.triParPrix());
    }
}


void MainWindow::on_pushButtonImprimer_facture_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QString strStream;
                QTextStream out(&strStream);



                const int rowCount = ui->tableViewAficherFacture_facture->model()->rowCount();
                const int columnCount = ui->tableViewAficherFacture_facture->model()->columnCount();

                out <<  "<html>\n"
                    "<head>\n"

                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%60 les postes</title>\n").arg("poste")
                    <<  "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<table border=1 cellspacing=0 cellpadding=2>\n";
                out << "<thead><tr bgcolor=#f0f0f0>";
                for (int column = 0; column < columnCount; column++)
                    if (! ui->tableViewAficherFacture_facture->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableViewAficherFacture_facture->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tableViewAficherFacture_facture->isColumnHidden(column)) {
                            QString data = ui->tableViewAficherFacture_facture->model()->data(ui->tableViewAficherFacture_facture->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                if (dialog->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }

                delete document;
}
QModelIndex MainWindow::on_tableViewAficherFacture_activated()
{
        return ui->tableViewAficherFacture_facture->currentIndex();
}




void MainWindow::on_lineEdit_prix_unitaire_facture_editingFinished()
{
    float prix_u=ui->lineEdit_prix_unitaire_facture->text().toFloat();
    int quantite=ui->lineEdit_quantite_facture->text().toInt();
    QString totale=QString::number(prix_u*quantite);
    ui->lineEdit_prix_totale_facture->setText(totale);
}



void MainWindow::on_lineEdit_quantite_facture_editingFinished()
{
    float prix_u=ui->lineEdit_prix_unitaire_facture->text().toFloat();
    int quantite=ui->lineEdit_quantite_facture->text().toInt();
    QString totale=QString::number(prix_u*quantite);
    ui->lineEdit_prix_totale_facture->setText(totale);
}


void MainWindow::on_pushButton_stat_facture_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QSqlQueryModel * model= new QSqlQueryModel();
                         model->setQuery("select * from factures where prix_totale < 50000 ");
                         float e=model->rowCount();
                         model->setQuery("select * from factures where prix_totale between 50000 and 100000 ");
                         float ee=model->rowCount();
                         model->setQuery("select * from factures where prix_totale > 100000 ");
                         float eee=model->rowCount();
                         float total=e+ee+eee;
                         QString a=QString("moins de 50 dinar "+QString::number((e*100)/total,'f',2)+"%" );
                         QString b=QString("entre 50 et 100 dinar"+QString::number((ee*100)/total,'f',2)+"%" );
                         QString c=QString("plus 100 dinar"+QString::number((eee*100)/total,'f',2)+"%" );
                         QPieSeries *series = new QPieSeries();
                         series->append(a,e);
                         series->append(b,ee);
                         series->append(c,eee);
                 if (e!=0)
                 {QPieSlice *slice = series->slices().at(0);
                  slice->setLabelVisible();
                  slice->setPen(QPen());}
                 if ( ee!=0)
                 {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(1);
                          //slice1->setExploded();
                          slice1->setLabelVisible();
                 }
                 if(eee!=0)
                 {
                          // Add labels to rest of slices
                          QPieSlice *slice2 = series->slices().at(2);
                          //slice1->setExploded();
                          slice2->setLabelVisible();
                 }
                         // Create the chart widget
                         QChart *chart = new QChart();
                         // Add data to chart with title and hide legend
                         chart->addSeries(series);
                         chart->setTitle("Pourcentage Par prix totale : nombre de factures: "+ QString::number(total));
                         chart->legend()->hide();
                         // Used to display the chart
                         QChartView *chartView = new QChartView(chart);
                         chartView->setRenderHint(QPainter::Antialiasing);
                         chartView->resize(1000,500);
                         chartView->show();
}


void MainWindow::on_lineEdit_rechercher_facture_textChanged()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QString rech=ui->lineEdit_rechercher_facture->text();
    ui->tableViewAficherFacture_facture->setModel(c.rechercheMulticritere(rech));
}



void MainWindow::on_pushButtonreset_facture_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QSqlQuery query;
    query.prepare("DELETE FROM FACTURES");
    query.exec();
    ui->tableViewAficherFacture_facture->setModel(c.afficher());
}





//ajout///////////

void MainWindow::on_aj_button_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    //code a barre
    QString code_a_barre=ui->code_edit_produit->text();
    //nom
   QString nom_produit=ui->nom_edit_produit->text();
   //prix uni
   float prix_uni=ui->prixu_edit_produit->text().toFloat();
   float prix_promo=ui->prixp_edit_produit->text().toFloat();
   //
   QString categorie=ui->categorie_edit_produit->text();

   QString date_expiration=ui->date_edit_produit->text();

   int quantite_produit=ui-> nbreEdit_produit->text().toInt();



produit p (code_a_barre,nom_produit,prix_uni,prix_promo,categorie, date_expiration, quantite_produit);
bool test=p.ajouter();
 if (test)
{
     QMediaPlayer *music=new QMediaPlayer();
     music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
     music->setVolume(5);
     music->play();
    //Refresh affichage
    ui->tableViewproduit->setModel(p.afficher());

    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectuer\n"),QObject::tr("click cancel to exit"));
   histo.save("code_a_barre:"+ui->code_edit_produit->text(),"nom_p :"+ui->nom_edit_produit->text(),"prix_uni :"+ui->prixu_edit_produit->text(),"prix_promo :"+ui->prixp_edit_produit->text(),"categorie :"+ui->categorie_edit_produit->text(),"date_expiration :"+ui->date_edit_produit->text(),"quantite_produit :"+ui->nbreEdit_produit->text());
    //clear************************************************
   ui->code_edit_produit->clear();
   ui->nom_edit_produit->clear();
   ui->prixu_edit_produit->clear();
   ui->prixp_edit_produit->clear();
   ui->categorie_edit_produit->clear();
   ui->date_edit_produit->clear();
   ui->nbreEdit_produit->clear();

   //******************************************************
 }else if ((categorie != "parfums" || categorie !="cosmetique" || categorie !="makeup") || (prix_uni < prix_promo) || (quantite_produit=0))
{
    QMessageBox::critical(nullptr,QObject::tr(" non ok"),QObject::tr("ajouter non effectuer"),QObject::tr("click cancel to exit"));
}
 QSqlQuery query;
 query.prepare("select quantite_produit from produit where quantite_produit < 6");
 query.exec();
 query.next();
 int q=query.value(0).toInt();
 if(q<=6)
 {
     notification_nourhene n;
     n.notification_system();
 }

}



//supprimer///////////


void MainWindow::on_pushButtonSupprimer_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QModelIndex index=on_tableViewproduit_activated();
    QString code_a_barre=ui->tableViewproduit->model()->data(ui->tableViewproduit->model()->index(index.row(),0)).toString();
bool test1=p.supprimer(code_a_barre);
if(test1)
{
    //Refresh affichage
    ui->tableViewproduit->setModel(p.afficher());
   // ui->tableView_hist->setModel(p.afficher_historique_produit());
    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectuer\n"),QObject::tr("click cancel to exit"));
}else
{
    QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectuer"),QObject::tr("click cancel to exit"));
}
}
void MainWindow::on_pushButtonModifier_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
ui->stackedWidget_produit->setCurrentIndex(3);
}
void MainWindow::on_pushButtonModifier2_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
//modifier les valeur de class
//c.setdate(ui->dateTimeEdit_modifier->text().to)
p.setprix_uni(ui->prixu_edit_1_produit->text().toFloat());
p.setprix_promo(ui->prixp_edit_1_produit->text().toFloat());
p.setquantite_produit(ui->nbreEdit_1_produit->text().toInt());

//modifier requete************
QModelIndex index=on_tableViewproduit_activated();
QString code_a_barre=ui->tableViewproduit->model()->data(ui->tableViewproduit->model()->index(index.row(),0)).toString();
bool test2=p.modifier(code_a_barre);
if(test2)
{
    ui->stackedWidget_produit->setCurrentIndex(2);
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
    notification_nourhene n;
    n.notification_system();
}


}


void MainWindow::on_lineEdit_chercher_produit_textChanged()
{
    QString i=ui->lineEdit_chercher_produit->text();
    ui->tableViewproduit->setModel(p.rechercheMulticritere(i));
}


//


void MainWindow::on_makeup_bottom_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_produit->setCurrentIndex(5);
}
void MainWindow::on_cosmetiques_bottom_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    //ui->stackedWidget2_produit->setCurrentIndex(2);
}
void MainWindow::on_parfums_bottom_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    //ui->stackedWidget2_produit->setCurrentIndex(3);
}

void MainWindow::on_pushButtonModifier2_2_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_produit->setCurrentIndex(2);
}

void MainWindow::on_categorie_bottom_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_produit->setCurrentIndex(4);
}




void MainWindow::on_codeabarre1_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName =QFileDialog::getOpenFileName(this,tr("Open Images"),"C:/Users/HP/Desktop/code a barre (produits)",tr("Image Files (*.png *.jpg *.bmp)"));
//to select and show the picture
    if (!fileName.isEmpty())
    {
        QImage image(fileName);
            ui->label_picc->setPixmap(QPixmap::fromImage(image));
    }
}

void MainWindow::on_codeabarre1_2_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName =QFileDialog::getOpenFileName(this, tr("Open Images"), "C:/Users/HP/Desktop/code a barre (produits)", tr("Image Files (*.png *.jpg *.bmp)"));
//to select and show the picture
    if (!fileName.isEmpty())
    {
        QImage image(fileName);
            ui->label_picc1->setPixmap(QPixmap::fromImage(image));
    }
}


void MainWindow::on_codeabarre1_3_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName =QFileDialog::getOpenFileName(this, tr("Open Images"), "C:/Users/HP/Desktop/code a barre (produits)", tr("Image Files (*.png *.jpg *.bmp)"));
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

void MainWindow::on_pushButton_refrech_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
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
        notification_nourhene n;
        n.notification_system();
    }


}

void MainWindow::on_historiqueButton_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QFile file("C:/Users/Ihebc/OneDrive/Desktop/integration/historique nourhene.txt");
        if (!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"info",file.errorString());
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());

}


//aziiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiz
//ajouter************
void MainWindow::on_pushButtonAjouter_client_3_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    //recuperation
    int Id_c=ui->lineEdit_id_client_3->text().toInt();
    QString Prenom_c=ui->lineEdit_Pc_client_3->text();
    QString Nom_c=ui->lineEdit_Nc_client_3->text();
    QString Email_c=ui->lineEdit_EM_client_3->text();
    int Point_fidelite=ui->lineEdit_Pf_client_3->text().toInt();
    int Telephone_c=ui->lineEdit_Num_client_3->text().toInt();

    Client C ( Nom_c,Prenom_c,Email_c,Id_c,Point_fidelite,Telephone_c);//instancer
    bool test=C.ajouter();

    if(test)
    {
        //Refresh affichage
        ui->tableViewAficherClient_client_3->setModel(C.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajouter non effectuer"),QObject::tr("click cancel to exit"));
    }
}

//affichage*********
void MainWindow::on_pushButtonAfficher_client_3_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->tableViewAficherClient_client_3->setModel(C.afficher());
}

//supprimer********************
void MainWindow::on_pushButtonSupprimer_client_3_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QModelIndex index=on_tableViewAficherClient_client_3_activated();
    int Id_c=ui->tableViewAficherClient_client_3->model()->data(ui->tableViewAficherClient_client_3->model()->index(index.row(),0)).toInt();
    bool test1=C.supprimer(Id_c);
    if(test1)
    {
        //Refresh affichage
        ui->tableViewAficherClient_client_3->setModel(C.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectuer"),QObject::tr("click cancel to exit"));
    }
}

void MainWindow::on_pushButtonModifier_client_3_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_client->setCurrentIndex(5);
}
//modifier**************
void MainWindow::on_pushButtonModifier2_client_3_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    //modifier les valeur de class
    C.setnom(ui->lineEdit_nom_m_client_3->text());
    C.setpre(ui->lineEdit_prenom_m_client_3->text());
    C.setemail(ui->lineEdit_email_m_client_3->text());
    C.settel(ui->lineEdit_tel_m_client_3->text().toInt());
    C.setpf(ui->lineEdit_point_f_m_client_3->text().toInt());

    //modifier requete************
    QModelIndex index=on_tableViewAficherClient_client_3_activated();
    int Id_c=ui->tableViewAficherClient_client_3->model()->data(ui->tableViewAficherClient_client_3->model()->index(index.row(),0)).toInt();
    bool test2=C.modifier(Id_c);
    ui->stackedWidget_client->setCurrentIndex(3);
    if(test2)
    {
        //Refresh affichage
        ui->tableViewAficherClient_client_3->setModel(C.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectuer"),QObject::tr("click cancel to exit"));
    }
}




void MainWindow::on_cb_tri_client_3_activated()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QString val=ui->cb_tri_client_3->currentText();
    ui->tableViewAficherClient_client_3->setModel(C.afficher_choix(val));
}

void MainWindow::on_pushButton_Contacter_client_3_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_client->setCurrentIndex(3);
}

void MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file_client_3->setText( fileListString );

}

void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname_client_3->text(), ui->paswd_client_3->text(), ui->server_client_3->text(), ui->port_client_3->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname_client_3->text(), ui->rcpt_client_3->text() , ui->subject_client_3->currentText(),ui->msg_client_3->toPlainText(), files );
    else
        smtp->sendMail(ui->uname_client_3->text(), ui->rcpt_client_3->text() , ui->subject_client_3->currentText(),ui->msg_client_3->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void MainWindow::on_reserver_client_3_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    //recuperation
   QString id_c=ui->le_cl_3->text();
   QString code_s=ui->le_s_3->text();
   QString em_c=ui->le_em_3->text();
   QDateTime date_r=ui->le_dtime_3->dateTime();
    Reservation R ( id_c,code_s,em_c,date_r);//instancer
    bool test=R.ajouter();

    if(test)
    {
        //Refresh affichage
        ui->tab_res_client_3->setModel(R.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajouter non effectuer"),QObject::tr("click cancel to exit"));
    }
}


void MainWindow::on_show_client_3_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->tab_res_client_3->setModel(R.afficher());

}

void MainWindow::on_pb_supp_res_client_3_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QString id_c=ui->le_supp_res_client_3->text();
    bool test1=R.supprimer(id_c);
    if(test1)
    {
        //Refresh affichage
        ui->tab_res_client_3->setModel(R.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectuer"),QObject::tr("click cancel to exit"));
    }
}

void MainWindow::on_pushButton_reserver_client_3_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_client->setCurrentIndex(4);
}

void MainWindow::on_quitter_client_3_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_client->setCurrentIndex(0);
}

void MainWindow::on_exitBtn_client_3_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
close();
}

void MainWindow::on_pushButton_client_3_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_client->setCurrentIndex(0);

}

void MainWindow::on_lineEdit_rechercher_client_3_textChanged()
{
    QString rech=ui->lineEdit_rechercher_client_3->text();
    ui->tableViewAficherClient_client_3->setModel(C.rechercheMulticritere(rech));
}

QModelIndex MainWindow::on_tableViewAficherClient_client_3_activated()
{
    return  ui->tableViewAficherClient_client_3->currentIndex();
}






void MainWindow::on_pushButton_go_to_caisse_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_integration->setCurrentIndex(0);
}


void MainWindow::on_pushButton_go_to_fournisseur_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_integration->setCurrentIndex(1);
}


void MainWindow::on_pushButton_go_to_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_integration->setCurrentIndex(2);
}



void MainWindow::on_pushButton_go_to_client_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_integration->setCurrentIndex(3);
}



//samar ********************
void MainWindow::on_pushButton_ajouter_clicked ()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();

    int code_s = ui->lineEdit_code->text().toInt();
    QString nom_s = ui->lineEdit_nom_s->text();
    QString offre = ui->lineEdit_offre->text();
    QDate date_offre=ui->dateEditAjouter->date();
    float prix_s=ui->lineEdit_prix_s->text().toFloat();
    float prix_offre=ui->lineEdit_prix_offre->text().toFloat();
    int ptf_s=ui->lineEdit_ptf_s->text().toInt();
  Service S ( nom_s , offre ,  date_offre , prix_s, prix_offre, code_s ,"oui",ptf_s); //instancer
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
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
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
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
   ui->stackedWidget_service->setCurrentIndex(3);
}
void MainWindow::on_pushButtonModifier2_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
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
       ui->stackedWidget_service->setCurrentIndex(2);
       QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectue\n"),QObject::tr("click cancel to exit"));
   }else
   {
       QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectue"),QObject::tr("click cancel to exit"));
   }
}


 void MainWindow::on_pushButtonafficher_clicked()
 {
     QMediaPlayer *music=new QMediaPlayer();
     music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
     music->setVolume(5);
     music->play();
      ui->tableViewAfficherService->setModel(S.afficher());
 }

 void MainWindow::on_lineEdit_chercher_service_textChanged()
{
     QMediaPlayer *music=new QMediaPlayer();
     music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
     music->setVolume(5);
     music->play();
   QString i=ui->lineEdit_chercher_service->text();
   ui->tableViewAfficherService->setModel(S.rechercheavancee(i));

}






 ////PDF

 void MainWindow::on_pushButton_pdf_clicked()
 {
     QMediaPlayer *music=new QMediaPlayer();
     music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
     music->setVolume(5);
     music->play();

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
                                              painter.drawText(8300,i,query.value(4).toString());
                                              painter.drawText(10300,i,query.value(5).toString());
                                              painter.drawText(12300,i,query.value(6).toString());


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
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
   QString filename=QFileDialog::getOpenFileName(
               this,tr("Open File"),"c://","All files (*.*);;Text File (*.txt);;Music File(*.mp4)");

   QDesktopServices::openUrl(QUrl("file:///"+filename,QUrl::TolerantMode));
   player = new QMediaPlayer(this);
   vw = new QVideoWidget(this);
   player->setVideoOutput(vw);
   this->setCentralWidget(vw);
}






QModelIndex MainWindow::on_tableViewAfficherService_activated()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
   return ui->tableViewAfficherService->currentIndex();
}

void MainWindow::on_pushButton_retour_modifier_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
   ui->stackedWidget_service->setCurrentIndex(2);
}

void MainWindow::on_pushButton_location_clicked()

{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
       QString p=ui->comboBox_location->currentText();
       QDesktopServices::openUrl(QUrl("http://maps.google.com.sg/maps?q="+p+"&oe=utf-8&rls=org.mozilla:en-US:official&client=firefox-a&um=1&ie=UTF-8&hl=en&sa=N&tab=wl"));

}
//arij**************************************************************************************************
void MainWindow::myfunction()
{
    QTime time =QTime::currentTime();
    QString time_text = time.toString("hh:mm:ss");
    ui->time_label_2->setText(time_text);
}
bool MainWindow::search(int t)
{bool test=false;

       for (int var = 0; var < ui->tableViewAficherEmployers->model()->rowCount(); ++var) {
           if(ui->tableViewAficherEmployers->model()->index(var,0).data().toInt()==t){
              ;
              test=true;
           }
       }
       return test;
}

void MainWindow::on_pushButtonAjouter_employer_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    int id=ui->lineEdit_id_employer_employer->text().toInt();
    ui->lineEdit_id_employer_employer->clear();
    QString  nom=ui->lineEdit_nom_employer->text();
    ui->lineEdit_nom_employer->clear();
    QString  prenom=ui->lineEdit_prenom_employer->text();
    ui->lineEdit_prenom_employer->clear();
    QDateTime date_naissance=ui->dateTimeEdit_ajouter_employer->dateTime();
    ui->dateTimeEdit_ajouter_employer->clear();
    QString  adresse=ui->lineEdit_adresse_employer->text();
    ui->lineEdit_adresse_employer->clear();
    int telephone=ui->lineEdit_telephone_employer->text().toInt();
    ui->lineEdit_telephone_employer->clear();
    QString  type=ui->lineEdit_type_employer->currentText();
    QString  specialite=ui->lineEdit_specialite_employer->currentText();


    Employers e( id, nom, prenom,date_naissance, adresse,telephone,type,specialite);
    bool test=e.ajouter();

    if(test)
        //if requete executee
    {
        //Refresh affichage
        ui->tableViewAficherEmployers->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectue\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectue"),QObject::tr("click cancel to exit"));
    }
}
void MainWindow::on_pushButtonSupprimer_employer_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QModelIndex index=on_tableViewAficherEmployers_activated();
    int id=ui->tableViewAficherEmployers->model()->data(ui->tableViewAficherEmployers->model()->index(index.row(),0)).toInt();
    bool t=search(id);
    if(t==false)
    {
     QMessageBox::information(nullptr,QObject::tr("Error"),QObject::tr("id inexistant\n"),QObject::tr("click cancel to exit"));
    }
    else
    {
    bool test1=e.supprimer(id);
    if(test1)
    {
        //Refresh affichage
        ui->tableViewAficherEmployers->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectuer"),QObject::tr("click cancel to exit"));
    }
    }
}
void MainWindow::on_pushButtonModifier_employer_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_employer->setCurrentIndex(5);
    QSqlQuery query;
    QModelIndex index=on_tableViewAficherEmployers_activated();
    QString res=ui->tableViewAficherEmployers->model()->data(ui->tableViewAficherEmployers->model()->index(index.row(),0)).toString();
    query.prepare("select adresse_e from EMPLOYERS where id_e= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    ui->lineEdit_adresse_e_modifier->setText(query.value(0).toString());;
    query.prepare("select telephone_e from EMPLOYERS where id_e= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    ui->lineEdit_telephone_e_modifier->setText(query.value(0).toString());
}

void MainWindow::on_pushButtonModifier2_employer_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    e.setadresse(ui->lineEdit_adresse_e_modifier->text());
    e.settelephone(ui->lineEdit_telephone_e_modifier->text().toInt());
    e.settype(ui->lineEdit_type_modifier->currentText());
    e.setspecialite(ui->lineEdit_specialite_modifier->currentText());
    QModelIndex index=on_tableViewAficherEmployers_activated();
    int id_e=ui->tableViewAficherEmployers->model()->data(ui->tableViewAficherEmployers->model()->index(index.row(),0)).toInt();
    bool test2=e.modifier(id_e);
    if(test2)
    {
        //Refresh affichage
        ui->tableViewAficherEmployers->setModel(e.afficher());
        ui->stackedWidget_employer->setCurrentIndex(2);
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectuer"),QObject::tr("click cancel to exit"));
    }
}


void MainWindow::on_pushButtonafficher_employer_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->tableViewAficherEmployers->setModel(e.afficher());
    ui->tableViewAficherEmployersh->setModel(e.afficherh());
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select id_e from EMPLOYERS");
    ui->comboBox_id_p->setModel(model);
}


void MainWindow::on_pushButton_40_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_employer->setCurrentIndex(0);
}



//*********************************
void MainWindow::on_pushButtonAjouterh_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    int id=ui->comboBox_id_p->currentText().toInt();
    QString  entree=ui->timeEdit_entree->text();
    QString  sortie=ui->timeEdit_sortie->text();
    QString  jour_travail=ui->comboBoxJour->currentText();

    Employers e(id,entree,sortie,jour_travail);
    bool test=e.ajouterh();

    if(test)
        //if requete executee
    {
        //Refresh affichage
        ui->tableViewAficherEmployersh->setModel(e.afficherh());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectue\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectue"),QObject::tr("click cancel to exit"));
    }
}

//login******************************
void MainWindow::on_pushButton_Login_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);

    QSound::play("C:/Users/Ihebc/OneDrive/Desktop/integration/son/y2mate.com-Scars-To-Your-Beautiful-Alessia-Cara-Violin-Cover.wav");
    music->play();
    QString username = ui->lineEdit_username->text();
           QString password = ui->lineEdit_password->text();
           ui->lineEdit_username->clear();
           ui->lineEdit_password->clear();
           if ((username == "admin" && password == "admin") || (username=="employer" && password == "employer")) {
               QMessageBox::information(this, "Login", "Username and password are correct");
            ui->stackedWidget_integration->setCurrentIndex(7);

           }
           else {
               QMessageBox::warning(this, "Login", "Username and password are not correct");
           }
}


void MainWindow::on_pushButton_planning_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_employer->setCurrentIndex(3);
}

void MainWindow::on_comboBox_id_p_activated()
{
    QSqlQuery query;
    QString res= ui->comboBox_id_p->currentText();
    query.prepare("select entree from EMPLOYERS where id_e= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    ui->timeEdit_entree->setTime(query.value(0).toTime());
    query.prepare("select sortie from EMPLOYERS where id_e= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    ui->timeEdit_sortie->setTime(query.value(0).toTime());
    query.prepare("select jour_travail from EMPLOYERS where id_e= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    if(query.value(0)=="lundi->mercredi")
        ui->comboBoxJour->setCurrentIndex(0);
    else if(query.value(0)=="jeudi->samedi")
        ui->comboBoxJour->setCurrentIndex(1);
}




void MainWindow::on_lineEdit_idEmployerachercher_cursorPositionChanged()
{
    QString i=ui->lineEdit_idEmployerachercher->text();
    ui->tableViewAficherEmployers->setModel(e.rechercheMulticritere(i));
}








void MainWindow::on_comboBoxTri_activated()
{
    if(ui->comboBoxTri_employer->currentText()=="Tri par id")
        {
            ui->tableViewAficherEmployers->setModel(e.triParId());
        }
    else if(ui->comboBoxTri_employer->currentText()=="Tri par nom")
        {
            ui->tableViewAficherEmployers->setModel(e.triParNom());
        }
    else if(ui->comboBoxTri_employer->currentText()=="Tri par date")
        {
            ui->tableViewAficherEmployers->setModel(e.trierDate());
        }
}






//********************MAILING*****************************

void MainWindow::on_pushButton_Contacter_employer_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_employer->setCurrentIndex(4);
}

void MainWindow::browse_employer()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file_6->setText( fileListString );

}

void MainWindow::sendMail_employer()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    Smtp* smtp = new Smtp(ui->uname_6->text(), ui->paswd_6->text(), ui->server_6->text(), ui->port_6->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname_6->text(), ui->rcpt_6->text() , ui->subject_7->currentText(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail(ui->uname_6->text(), ui->rcpt_6->text() , ui->subject_7->currentText(),ui->msg->toPlainText());
}

void MainWindow::mailSent_employer(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void MainWindow::on_pushButton_6_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_employer->setCurrentIndex(0);
}

QModelIndex MainWindow::on_tableViewAficherEmployers_activated()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    return ui->tableViewAficherEmployers->currentIndex();
}

void MainWindow::on_pushButton_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_employer->setCurrentIndex(0);
}



void MainWindow::on_pushButton_PDF_employer_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
            QString strStream;
            strStream = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
                if (QFileInfo(strStream).suffix().isEmpty()) { strStream.append(".pdf"); }

                QPrinter printer(QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A3);
                printer.setOutputFileName(strStream);
                      QTextStream out(&strStream);

                      const int rowCount = ui->tableViewAficherEmployers->model()->rowCount();
                      const int columnCount = ui->tableViewAficherEmployers->model()->columnCount();
                      QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                      out <<"<html>\n"
                            "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          << "<title>ERP - COMmANDE LIST<title>\n "
                          << "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"
                          "<h1 style=\"text-align: center;\"><strong> ******LISTE DES EMPLOYERS ****** "+TT+"</strong></h1>"
                         //   " <img src="logo.png" alt="Trulli" width="1000" height="500">"
                          "<table style=\"text-align: center; font-size: 15px;\" border=1>\n "
                            "</br> </br>";
                      // headers
                      out << "<thead><tr bgcolor=#d6e5ff>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->tableViewAficherEmployers->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->tableViewAficherEmployers->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->tableViewAficherEmployers->isColumnHidden(column)) {
                                  QString data =ui->tableViewAficherEmployers->model()->data(ui->tableViewAficherEmployers->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table>\n"
                          "</body>\n"
                          "</html>\n";

                      QTextDocument document;
                      document.setHtml(strStream);
                      document.print(&printer);

}


void MainWindow::on_pb_envoyer_employer_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QTextStream T(mSocket);
    T<<ui->le_nickname_employer->text()<<": "<<ui->le_message_employer->text();
    mSocket->flush();
    ui->le_message_employer->clear();
}

void MainWindow::on_pb_connecter_employer_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    dumessengerconnectiondialog D(this);
    if(D.exec()==QDialog::Rejected)
    {
        return;

    }
    mSocket->connectToHost(D.hostname(),D.port());
}



void MainWindow::on_pushButton_go_to_service_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_integration->setCurrentIndex(4);
}


void MainWindow::on_pushButton_go_to_employer_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_integration->setCurrentIndex(5);
}


void MainWindow::on_pushButton_gestion_facture_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_facture->setCurrentIndex(2);
}


void MainWindow::on_pushButton_ajouter_facture_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_facture->setCurrentIndex(1);
}


void MainWindow::on_pushButtonRetourAjouter_facture_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_facture->setCurrentIndex(0);
}


void MainWindow::on_pushButtonRetourAfficher_facture_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_facture->setCurrentIndex(0);
}


void MainWindow::on_pushButton_quiter_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_integration->setCurrentIndex(7);
}


void MainWindow::on_pushButton_ajouter_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_produit->setCurrentIndex(1);
}


void MainWindow::on_pushButton_gestion_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_produit->setCurrentIndex(2);
}


void MainWindow::on_pushButton_categorie_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_produit->setCurrentIndex(4);
}


void MainWindow::on_pushButton_historique_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_produit->setCurrentIndex(6);
}


void MainWindow::on_pushButton_quitter_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_integration->setCurrentIndex(7);
}


void MainWindow::on_rt_button_produit_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_produit->setCurrentIndex(0);
}


void MainWindow::on_pushButton_retour_categorie_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_produit->setCurrentIndex(0);
}


void MainWindow::on_categorie_bottom_hist_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_produit->setCurrentIndex(0);
}


void MainWindow::on_pushButton_retour_gestion_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_produit->setCurrentIndex(0);
}


void MainWindow::on_pushButton_ajouter_fournisseur_2_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_fournisseur->setCurrentIndex(1);
}


void MainWindow::on_pushButton_gestion_fournisseur_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_fournisseur->setCurrentIndex(2);
}


void MainWindow::on_pushButton_chat_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_fournisseur->setCurrentIndex(5);
}


void MainWindow::on_pushButton_historique_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_fournisseur->setCurrentIndex(4);
}


void MainWindow::on_pushButton_quitter_fournisseur_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_integration->setCurrentIndex(7);
}


void MainWindow::on_pushButton_3_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_fournisseur->setCurrentIndex(0);
}


void MainWindow::on_pushButton_retour_histourique_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_fournisseur->setCurrentIndex(0);
}


void MainWindow::on_pushButton_retour_chat_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_fournisseur->setCurrentIndex(0);
}


void MainWindow::on_pushButton_retourA_fournisseur_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_fournisseur->setCurrentIndex(0);
}


void MainWindow::on_pushButton_quitter_facture_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    ui->stackedWidget_integration->setCurrentIndex(7);
}


void MainWindow::on_historiqueButton_fournisseur_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/son/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QFile file("C:/Users/Ihebc/OneDrive/Desktop/integration/historique wajdi.txt");
            if (!file.open(QIODevice::ReadOnly))
                QMessageBox::information(0,"info",file.errorString());
            QTextStream in(&file);
            ui->textBrowser_wajdi->setText(in.readAll());
}


void MainWindow::on_pushButton_retour_aj_employer_clicked()
{
    ui->stackedWidget_employer->setCurrentIndex(0);
}


void MainWindow::on_pushButton_retour_employer_clicked()
{
    ui->stackedWidget_employer->setCurrentIndex(0);
}


void MainWindow::on_pushButton_retour_reserver_employer_clicked()
{
    ui->stackedWidget_employer->setCurrentIndex(0);
}


void MainWindow::on_pushButton_retour_chat_employer_clicked()
{
    ui->stackedWidget_employer->setCurrentIndex(0);
}


void MainWindow::on_pushButton_ajouter_employer_clicked()
{
    ui->stackedWidget_employer->setCurrentIndex(1);
}


void MainWindow::on_pushButton_gestion_employer_clicked()
{
    ui->stackedWidget_employer->setCurrentIndex(2);
}


void MainWindow::on_pushButton_chat_employer_clicked()
{
    ui->stackedWidget_employer->setCurrentIndex(6);
}


void MainWindow::on_pushButton_quiter_employer_clicked()
{
    ui->stackedWidget_integration->setCurrentIndex(7);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget_integration->setCurrentIndex(6);
}


void MainWindow::on_pushButton_11_client_3_clicked()
{
    ui->stackedWidget_client->setCurrentIndex(2);
}


void MainWindow::on_pushButton_retour_affichage_clicked()
{
    ui->stackedWidget_client->setCurrentIndex(0);
}


void MainWindow::on_pushButtonretour_aj_client_clicked()
{
    ui->stackedWidget_client->setCurrentIndex(0);
}


void MainWindow::on_pushButton_ajouter_client_clicked()
{
    ui->stackedWidget_client->setCurrentIndex(1);
}


void MainWindow::on_pushButton_gestion_client_clicked()
{
    ui->stackedWidget_client->setCurrentIndex(2);
}


void MainWindow::on_pushButton_quitter_client_clicked()
{
    ui->stackedWidget_integration->setCurrentIndex(7);
}


void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget_service->setCurrentIndex(0);
}


void MainWindow::on_pushButton_retour_aj_ser_clicked()
{
    ui->stackedWidget_service->setCurrentIndex(0);
}


void MainWindow::on_pushButton_ajouter_service_clicked()
{
    ui->stackedWidget_service->setCurrentIndex(1);
}


void MainWindow::on_pushButton_gestion_service_clicked()
{
    ui->stackedWidget_service->setCurrentIndex(2);
}


void MainWindow::on_pushButton_quitter_service_clicked()
{
    ui->stackedWidget_integration->setCurrentIndex(7);
}


void MainWindow::on_tableViewAficherEmployers_activated(const QModelIndex &index)
{
    Employers e;
        if(ui->tableViewAficherEmployers->currentIndex().row()==-1)
               QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                        QObject::tr("Veuillez Choisir un employeur du Tableau.\n"
                                                    "Click Ok to exit."), QMessageBox::Ok);
           else
           {
                       e.setid(ui->lineEdit_id_employer_employer ->text().toInt());
                       e.setnom(ui->lineEdit_nom_employer ->text());
                       e.setprenom(ui->lineEdit_prenom_employer ->text());

                       e.setadresse(ui->lineEdit_adresse_employer ->text());
                       e.settelephone(ui->lineEdit_telephone_employer ->text().toInt());
                       e.settype(ui->lineEdit_type_employer ->currentText());
                       e.setspecialite(ui->lineEdit_specialite_employer ->currentText());



             QString  rawQr = "ID_E:%1 NOM_E:%2 PRENOM_E:%3 ADRESSE_E:%4 TELEPHONE_E:%5 TYPE:%6 SPECIALITE:%7 " ;
                rawQr = rawQr.arg(e.getid()).arg(e.getnom()).arg(e.getprenom()).arg(e.getadresse()).arg(e.gettelephone()).arg(e.gettype()).arg(e.getspecialite());
                QrCode qr = QrCode::encodeText(rawQr.toUtf8().constData(), QrCode::Ecc::HIGH);

                std::ofstream myfile;
                myfile.open ("qrcode.svg") ;
                myfile << qr.toSvgString(1);
                myfile.close();
                QSvgRenderer svgRenderer(QString("qrcode.svg"));
                QPixmap pix( QSize(90, 90) );
                QPainter pixPainter( &pix );
                svgRenderer.render( &pixPainter );
                ui->label_code->setPixmap(pix);
        }
}

