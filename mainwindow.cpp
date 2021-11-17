#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "employers.h"
#include <QMessageBox>
#include <QValidator>
#include <QDebug>
#include <QPainter>
#include <QPdfWriter>
#include "smtp.h"
#include <QDateTime>

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

using qrcodegen::QrCode;

//liiindaaa
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //************************
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
    timer->start(1000);
    //************************
   ui->stackedWidget->setCurrentIndex(1);
   ui->stackedWidget_3->setCurrentIndex(0);
    ui->stackedWidget_8->setCurrentIndex(0);
        QPixmap pix("C:/Users/asus/OneDrive/Desktop/image/logo3.png");
        QPixmap pix1("C:/Users/asus/OneDrive/Desktop/image/logo2.png");
        QPixmap pix2("C:/Users/asus/OneDrive/Desktop/image/logo3.png");
        QPixmap pix3("C:/Users/asus/OneDrive/Desktop/image/logo3.png");
        QPixmap pix4("C:/Users/asus/OneDrive/Desktop/image/logo3.png");
        QPixmap pix5("C:/Users/asus/OneDrive/Desktop/image/logo3.png");
        int w = ui->label_pic->width();
        int h = ui->label_pic->height();

        int w1 = ui->label_pic1->width();
        int h1 = ui->label_pic1->height();

        int w3 = ui->label_pic_2->width();
        int h3 = ui->label_pic_2->height();


        int w5 = ui->label_pic->width();
        int h5 = ui->label_pic->height();

         ui->label_pic->setPixmap(pix1.scaled(w,h,Qt::KeepAspectRatio));
         ui->label_pic1->setPixmap(pix.scaled(w1,h1,Qt::KeepAspectRatio));
         ui->label_pic_2->setPixmap(pix3.scaled(w3,h3,Qt::KeepAspectRatio));
         ui->label_7->setPixmap(pix5.scaled(w5,h5,Qt::KeepAspectRatio));
//AJOUTER
        ui->lineEdit_id->setValidator ( new QIntValidator(0, 99999999, this));
        ui->lineEdit_telephone->setValidator ( new QIntValidator(0, 99999999, this));
        QRegularExpression rx("\\b[A-Z._%+-]+ [A-Z.-]+\\[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
                    ui->lineEdit_nom->setValidator(new QRegularExpressionValidator(rx, this));
         QRegularExpression rx1("\\b[A-Z._%+-]+ [A-Z.-]+\\[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
                    ui->lineEdit_prenom->setValidator(new QRegularExpressionValidator(rx1, this));
         QRegularExpression rx2("\\b[A-Z._%+-]+ [A-Z.-]+\\[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
                               ui->lineEdit_type->setValidator(new QRegularExpressionValidator(rx2, this));
          QRegularExpression rx3("\\b[A-Z._%+-]+ [A-Z.-]+\\[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
                               ui->lineEdit_specialite->setValidator(new QRegularExpressionValidator(rx3, this));
//MODIFIER
        ui->lineEdit_telephone_e_modifier->setValidator ( new QIntValidator(0, 99999999, this));
        QRegularExpression rx4("\\b[A-Z._%+-]+ [A-Z.-]+\\[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
         QRegularExpression rx5("\\b[A-Z._%+-]+ [A-Z.-]+\\[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
         QRegularExpression rx6("\\b[A-Z._%+-]+ [A-Z.-]+\\[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
                               ui->lineEdit_type_modifier->setValidator(new QRegularExpressionValidator(rx2, this));
          QRegularExpression rx7("\\b[A-Z._%+-]+ [A-Z.-]+\\[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
                               ui->lineEdit_specialite_modifier->setValidator(new QRegularExpressionValidator(rx3, this));

connect(ui->sendBtn_6,SIGNAL(clicked()),this,SLOT(sendMail()));
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::myfunction()
{
    QTime time =QTime::currentTime();
    QString time_text = time.toString("hh:mm:ss");
    ui->time_label->setText(time_text);
    ui->time_label_2->setText(time_text);
    ui->time_label_3->setText(time_text);
    ui->time_label_4->setText(time_text);
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

void MainWindow::on_pushButtonAjouter_clicked()
{
    Notification n;
    int id=ui->lineEdit_id->text().toInt();
    ui->lineEdit_id->clear();
    QString  nom=ui->lineEdit_nom->text();
    ui->lineEdit_nom->clear();
    QString  prenom=ui->lineEdit_prenom->text();
    ui->lineEdit_prenom->clear();
    QDateTime date_naissance=ui->dateTimeEdit_ajouter->dateTime();
    ui->dateTimeEdit_ajouter->clear();
    QString  adresse=ui->lineEdit_adresse->text();
    ui->lineEdit_adresse->clear();
    int telephone=ui->lineEdit_telephone->text().toInt();
    ui->lineEdit_telephone->clear();
    QString  type=ui->lineEdit_type->text();
    ui->lineEdit_type->clear();
    QString  specialite=ui->lineEdit_specialite->text();
    ui->lineEdit_specialite->clear();


    Employers e( id, nom, prenom,date_naissance, adresse,telephone,type,specialite);
    bool test=e.ajouter();

    if(test)
        //if requete executee
    {
        //Refresh affichage
        ui->tableViewAficherEmployers->setModel(e.afficher());
        n.notification_ajoutEmployer();
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectue\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectue"),QObject::tr("click cancel to exit"));
    }
}
void MainWindow::on_pushButtonSupprimer_clicked()
{
    Notification n;
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
        n.notification_supprimerEmployer();
        //Refresh affichage
        ui->tableViewAficherEmployers->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectuer"),QObject::tr("click cancel to exit"));
    }
    }
}
void MainWindow::on_pushButtonModifier_clicked()
{
    Notification n;
    ui->stackedWidget_3->setCurrentIndex(3);
    QSqlQuery query;
    QModelIndex index=on_tableViewAficherEmployers_activated();
    QString res=ui->tableViewAficherEmployers->model()->data(ui->tableViewAficherEmployers->model()->index(index.row(),0)).toString();
    query.prepare("select adresse_e from EMPLOYERS where id_e= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    ui->lineEdit_adresse_e_modifier->setText(query.value(0).toString());
    query.prepare("select type from EMPLOYERS where id_e= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    ui->lineEdit_type_modifier->setText(query.value(0).toString());
    query.prepare("select specialite from EMPLOYERS where id_e= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    ui->lineEdit_specialite_modifier->setText(query.value(0).toString());
    query.prepare("select telephone_e from EMPLOYERS where id_e= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    ui->lineEdit_telephone_e_modifier->setText(query.value(0).toString());
}

void MainWindow::on_pushButtonModifier2_clicked()
{
    Notification n;
    e.setadresse(ui->lineEdit_adresse_e_modifier->text());
    e.settelephone(ui->lineEdit_telephone_e_modifier->text().toInt());
    e.settype(ui->lineEdit_type_modifier->text());
    e.setspecialite(ui->lineEdit_specialite_modifier->text());
    QModelIndex index=on_tableViewAficherEmployers_activated();
    int id_e=ui->tableViewAficherEmployers->model()->data(ui->tableViewAficherEmployers->model()->index(index.row(),0)).toInt();
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


void MainWindow::on_pushButtonafficher_clicked()
{
    ui->tableViewAficherEmployers->setModel(e.afficher());
    ui->tableViewAficherEmployersh->setModel(e.afficherh());
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select id_e from EMPLOYERS");
    ui->comboBox_id_p->setModel(model);
}


void MainWindow::on_pushButton_40_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}



//*********************************
void MainWindow::on_pushButtonAjouterh_clicked()
{
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
    QString username = ui->lineEdit_username->text();
           QString password = ui->lineEdit_password->text();

           if (username == "admin" && password == "admin" || username=="employer" && password == "employer") {
               QMessageBox::information(this, "Login", "Username and password are correct");
            ui->stackedWidget->setCurrentIndex(0);

           }
           else {
               QMessageBox::warning(this, "Login", "Username and password are not correct");
           }
}


void MainWindow::on_pushButton_planning_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
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

void MainWindow::on_pushButtonEnvoyer_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString message= ui->lineEditEnvoyer->text();
    e.chat(message,username,password);
    //Refresh affichage
    ui->tableViewAfficherMessage->setModel(e.affichermessage(username,password));
}







void MainWindow::on_comboBoxTri_activated()
{
    if(ui->comboBoxTri->currentText()=="Tri par id")
        {
            ui->tableViewAficherEmployers->setModel(e.triParId());
        }
    else if(ui->comboBoxTri->currentText()=="Tri par nom")
        {
            ui->tableViewAficherEmployers->setModel(e.triParNom());
        }
    else if(ui->comboBoxTri->currentText()=="Tri par date")
        {
            ui->tableViewAficherEmployers->setModel(e.trierDate());
        }
}





//************************************



void MainWindow::on_pushButtonAfficherMessage_clicked()
{
    //Refresh affichage
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    ui->tableViewAfficherMessage->setModel(e.affichermessage(username,password));
}





//********************MAILING*****************************

void MainWindow::on_pushButton_Contacter_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(2);
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

    ui->file_6->setText( fileListString );

}

void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname_6->text(), ui->paswd_6->text(), ui->server_6->text(), ui->port_6->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname_6->text(), ui->rcpt_6->text() , ui->subject_7->currentText(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail(ui->uname_6->text(), ui->rcpt_6->text() , ui->subject_7->currentText(),ui->msg->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}

QModelIndex MainWindow::on_tableViewAficherEmployers_activated()
{
    return ui->tableViewAficherEmployers->currentIndex();
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}



void MainWindow::on_pushButton_PDF_clicked()
{
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

void MainWindow::on_QrCode_clicked()
{
    if(ui->tableViewAficherEmployers->currentIndex().row()==-1)
               QMessageBox::information(nullptr, QObject::tr("QrCode"),
                                        QObject::tr("Veuillez Choisir un employeur du Tableau.\n"
                                                    "Click Ok to exit."), QMessageBox::Ok);
           else
           {
                int ID_E=ui->tableViewAficherEmployers->model()->data(ui->tableViewAficherEmployers->model()->index(ui->tableViewAficherEmployers->currentIndex().row(),0)).toInt();
                const QrCode qr = QrCode::encodeText(std::to_string(ID_E).c_str(), QrCode::Ecc::LOW);
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
