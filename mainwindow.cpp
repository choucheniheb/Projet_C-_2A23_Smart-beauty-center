#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include <QString>
#include<QDebug>
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget_client->setCurrentIndex(0);
    ui->lineEdit_id_client->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_Pf_client->setValidator(new QIntValidator(0,1000,this));
    ui->lineEdit_Num_client->setValidator(new QIntValidator(0,99999999,this));
    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                              QRegularExpression::CaseInsensitiveOption);
    ui->lineEdit_EM_client->setValidator(new QRegularExpressionValidator(rx, this));
    connect(ui->sendBtn_client,SIGNAL(clicked()),this,SLOT(sendMail()));
    connect(ui->exitBtn_client, SIGNAL(clicked()),this, SLOT(close()));
     connect(ui->browseBtn_client, SIGNAL(clicked()), this, SLOT(browse()));
     int ret=A.connect_arduino(); // lancer la connexion à arduino
     switch(ret){
     case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
         break;
     case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
     case(-1):qDebug() << "arduino is not available";
     }
      QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
      //le slot update_label suite à la reception du signal readyRead (reception des données).


}

MainWindow::~MainWindow()
{
    delete ui;
}

//ajouter************
void MainWindow::on_pushButtonAjouter_client_clicked()
{
    //recuperation
    int Id_c=ui->lineEdit_id_client->text().toInt();
    QString Prenom_c=ui->lineEdit_Pc_client->text();
    QString Nom_c=ui->lineEdit_Nc_client->text();
    QString Email_c=ui->lineEdit_EM_client->text();
    int Point_fidelite=ui->lineEdit_Pf_client->text().toInt();
    int Telephone_c=ui->lineEdit_Num_client->text().toInt();

    Client C ( Nom_c,Prenom_c,Email_c,Id_c,Point_fidelite,Telephone_c);//instancer
    bool test=C.ajouter();

    if(test)
    {
        //Refresh affichage
        ui->tableViewAficherClient_client->setModel(C.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajouter non effectuer"),QObject::tr("click cancel to exit"));
    }
}

//affichage*********
void MainWindow::on_pushButtonAfficher_client_clicked()
{
    ui->tableViewAficherClient_client->setModel(C.afficher());
}

//supprimer********************
void MainWindow::on_pushButtonSupprimer_client_clicked()
{
    QModelIndex index=on_tableViewAficherClient_client_activated();
    int Id_c=ui->tableViewAficherClient_client->model()->data(ui->tableViewAficherClient_client->model()->index(index.row(),0)).toInt();
    bool test1=C.supprimer(Id_c);
    if(test1)
    {
        //Refresh affichage
        ui->tableViewAficherClient_client->setModel(C.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectuer"),QObject::tr("click cancel to exit"));
    }
}

void MainWindow::on_pushButtonModifier_client_clicked()
{
    ui->stackedWidget_client->setCurrentIndex(3);
}
//modifier**************
void MainWindow::on_pushButtonModifier2_client_clicked()
{
    //modifier les valeur de class
    C.setnom(ui->lineEdit_nom_m_client->text());
    C.setpre(ui->lineEdit_prenom_m_client->text());
    C.setemail(ui->lineEdit_email_m_client->text());
    C.settel(ui->lineEdit_tel_m_client->text().toInt());
    C.setpf(ui->lineEdit_point_f_m_client->text().toInt());

    //modifier requete************
    QModelIndex index=on_tableViewAficherClient_client_activated();
    int Id_c=ui->tableViewAficherClient_client->model()->data(ui->tableViewAficherClient_client->model()->index(index.row(),0)).toInt();
    bool test2=C.modifier(Id_c);
    ui->stackedWidget_client->setCurrentIndex(0);
    if(test2)
    {
        //Refresh affichage
        ui->tableViewAficherClient_client->setModel(C.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectuer"),QObject::tr("click cancel to exit"));
    }
}




void MainWindow::on_cb_tri_client_activated()
{
    QString val=ui->cb_tri_client->currentText();
    ui->tableViewAficherClient_client->setModel(C.afficher_choix(val));
}

void MainWindow::on_pushButton_Contacter_client_clicked()
{
    ui->stackedWidget_client->setCurrentIndex(1);
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

    ui->file_client->setText( fileListString );

}

void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname_client->text(), ui->paswd_client->text(), ui->server_client->text(), ui->port_client->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname_client->text(), ui->rcpt_client->text() , ui->subject_client->currentText(),ui->msg_client->toPlainText(), files );
    else
        smtp->sendMail(ui->uname_client->text(), ui->rcpt_client->text() , ui->subject_client->currentText(),ui->msg_client->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void MainWindow::on_reserver_client_clicked()
{
    //recuperation
   QString id_c=ui->le_cl->text();
   QString code_s=ui->le_s->text();
   QString em_c=ui->le_em->text();
   QDateTime date_r=ui->le_dtime->dateTime();
    Reservation R ( id_c,code_s,em_c,date_r);//instancer
    bool test=R.ajouter();

    if(test)
    {
        //Refresh affichage
        ui->tab_res_client->setModel(R.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajouter non effectuer"),QObject::tr("click cancel to exit"));
    }
}


void MainWindow::on_show_client_clicked()
{
    ui->tab_res_client->setModel(R.afficher());

}

void MainWindow::on_pb_supp_res_client_clicked()
{
    QString id_c=ui->le_supp_res_client->text();
    bool test1=R.supprimer(id_c);
    if(test1)
    {
        //Refresh affichage
        ui->tab_res_client->setModel(R.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectuer"),QObject::tr("click cancel to exit"));
    }
}

void MainWindow::on_pushButton_reserver_client_clicked()
{
    ui->stackedWidget_client->setCurrentIndex(2);
}

void MainWindow::on_quitter_client_clicked()
{
    ui->stackedWidget_client->setCurrentIndex(0);
}

void MainWindow::on_exitBtn_client_clicked()
{
close();
}

void MainWindow::on_pushButton_client_clicked()
{
    ui->stackedWidget_client->setCurrentIndex(0);

}

void MainWindow::on_lineEdit_rechercher_client_textChanged()
{
    QString rech=ui->lineEdit_rechercher_client->text();
    ui->tableViewAficherClient_client->setModel(C.rechercheMulticritere(rech));
}

QModelIndex MainWindow::on_tableViewAficherClient_client_activated()
{
    return  ui->tableViewAficherClient_client->currentIndex();
}
/***************ARduino*********/
/*void MainWindow::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_3->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_3->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}*/
void MainWindow::on_pushButton_alarme_clicked()   // implémentation du slot bouton on
{
     A.write_to_arduino("1"); //envoyer 1 à arduino
}

void MainWindow::on_pushButton_alarme_2_clicked()  // implémentation du slot bouton off
{

     A.write_to_arduino("0");  //envoyer 0 à arduino
}

