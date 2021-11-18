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
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit_id->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_Pf->setValidator(new QIntValidator(0,1000,this));
    ui->lineEdit_Num->setValidator(new QIntValidator(0,99999999,this));
    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                              QRegularExpression::CaseInsensitiveOption);
    ui->lineEdit_EM->setValidator(new QRegularExpressionValidator(rx, this));
    connect(ui->sendBtn,SIGNAL(clicked()),this,SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
     connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//ajouter************
void MainWindow::on_pushButtonAjouter_clicked()
{
    //recuperation
    int Id_c=ui->lineEdit_id->text().toInt();
    QString Prenom_c=ui->lineEdit_Pc->text();
    QString Nom_c=ui->lineEdit_Nc->text();
    QString Email_c=ui->lineEdit_EM->text();
    int Point_fidelite=ui->lineEdit_Pf->text().toInt();
    int Telephone_c=ui->lineEdit_Num->text().toInt();

    Client C ( Nom_c,Prenom_c,Email_c,Id_c,Point_fidelite,Telephone_c);//instancer
    bool test=C.ajouter();

    if(test)
    {
        //Refresh affichage
        ui->tableViewAficherClient->setModel(C.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajouter non effectuer"),QObject::tr("click cancel to exit"));
    }
}

//affichage*********
void MainWindow::on_pushButtonAfficher_clicked()
{
    ui->tableViewAficherClient->setModel(C.afficher());
}

//supprimer********************
void MainWindow::on_pushButtonSupprimer_clicked()
{
    QModelIndex index=on_tableViewAficherClient_activated();
    int Id_c=ui->tableViewAficherClient->model()->data(ui->tableViewAficherClient->model()->index(index.row(),0)).toInt();
    bool test1=C.supprimer(Id_c);
    if(test1)
    {
        //Refresh affichage
        ui->tableViewAficherClient->setModel(C.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectuer"),QObject::tr("click cancel to exit"));
    }
}

void MainWindow::on_pushButtonModifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
//modifier**************
void MainWindow::on_pushButtonModifier2_clicked()
{
    //modifier les valeur de class
    C.setnom(ui->lineEdit_nom_m->text());
    C.setpre(ui->lineEdit_prenom_m->text());
    C.setemail(ui->lineEdit_email_m->text());
    C.settel(ui->lineEdit_tel_m->text().toInt());
    C.setpf(ui->lineEdit_point_f_m->text().toInt());

    //modifier requete************
    QModelIndex index=on_tableViewAficherClient_activated();
    int Id_c=ui->tableViewAficherClient->model()->data(ui->tableViewAficherClient->model()->index(index.row(),0)).toInt();
    bool test2=C.modifier(Id_c);
    ui->stackedWidget->setCurrentIndex(0);
    if(test2)
    {
        //Refresh affichage
        ui->tableViewAficherClient->setModel(C.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectuer"),QObject::tr("click cancel to exit"));
    }
}




void MainWindow::on_cb_tri_activated()
{
    QString val=ui->cb_tri->currentText();
    ui->tableViewAficherClient->setModel(C.afficher_choix(val));
}

void MainWindow::on_pushButton_Contacter_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
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

    ui->file->setText( fileListString );

}

void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->currentText(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->currentText(),ui->msg->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void MainWindow::on_reserver_clicked()
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
        ui->tab_res->setModel(R.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajouter non effectuer"),QObject::tr("click cancel to exit"));
    }
}


void MainWindow::on_show_clicked()
{
    ui->tab_res->setModel(R.afficher());

}

void MainWindow::on_pb_supp_res_clicked()
{
    QString id_c=ui->le_supp_res->text();
    bool test1=R.supprimer(id_c);
    if(test1)
    {
        //Refresh affichage
        ui->tab_res->setModel(R.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectuer"),QObject::tr("click cancel to exit"));
    }
}

void MainWindow::on_pushButton_reserver_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_quitter_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_exitBtn_clicked()
{
close();
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_lineEdit_rechercher_textChanged()
{
    QString rech=ui->lineEdit_rechercher->text();
    ui->tableViewAficherClient->setModel(C.rechercheMulticritere(rech));
}

QModelIndex MainWindow::on_tableViewAficherClient_activated()
{
    return  ui->tableViewAficherClient->currentIndex();
}
