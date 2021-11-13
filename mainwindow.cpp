#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "employers.h"
#include <QMessageBox>
#include <QValidator>
#include <QDebug>
#include "smtp.h"


//liiindaaa
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->stackedWidget_8->setCurrentIndex(0);
        QPixmap pix("C:/Users/asus/OneDrive/Desktop/image/logo1.png");
        QPixmap pix1("C:/Users/asus/OneDrive/Desktop/image/logo2.png");
        QPixmap pix2("C:/Users/asus/OneDrive/Desktop/image/logo3.png");
        QPixmap pix3("C:/Users/asus/OneDrive/Desktop/image/logo3.png");
         QPixmap pix4("C:/Users/asus/OneDrive/Desktop/image/logo3.png");
        int w = ui->label_pic->width();
        int h = ui->label_pic->height();

        int w1 = ui->label_pic1->width();
        int h1 = ui->label_pic1->height();

        int w2 = ui->label_pic2->width();
        int h2 = ui->label_pic2->height();

        int w3 = ui->label_pic_2->width();
        int h3 = ui->label_pic_2->height();

        int w4 = ui->label_pic->width();
        int h4 = ui->label_pic->height();

         ui->label_pic->setPixmap(pix1.scaled(w,h,Qt::KeepAspectRatio));
         ui->label_pic1->setPixmap(pix.scaled(w1,h1,Qt::KeepAspectRatio));
         ui->label_pic2->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));
         ui->label_pic_2->setPixmap(pix3.scaled(w3,h3,Qt::KeepAspectRatio));
         ui->label->setPixmap(pix4.scaled(w4,h4,Qt::KeepAspectRatio));
//AJOUTER
        ui->lineEdit_id->setValidator ( new QIntValidator(0, 99999999, this));
        ui->lineEdit_telephone->setValidator ( new QIntValidator(0, 99999999, this));
        QRegularExpression rx("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
                    ui->lineEdit_nom->setValidator(new QRegularExpressionValidator(rx, this));
         QRegularExpression rx1("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
                    ui->lineEdit_prenom->setValidator(new QRegularExpressionValidator(rx1, this));
         QRegularExpression rx2("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
                               ui->lineEdit_type->setValidator(new QRegularExpressionValidator(rx2, this));
          QRegularExpression rx3("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
                               ui->lineEdit_specialite->setValidator(new QRegularExpressionValidator(rx3, this));
//MODIFIER
        ui->lineEdit_telephone_e_modifier->setValidator ( new QIntValidator(0, 99999999, this));
        QRegularExpression rx4("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
         QRegularExpression rx5("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
         QRegularExpression rx6("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
                               ui->lineEdit_type_modifier->setValidator(new QRegularExpressionValidator(rx2, this));
          QRegularExpression rx7("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b", QRegularExpression::CaseInsensitiveOption);
                               ui->lineEdit_specialite_modifier->setValidator(new QRegularExpressionValidator(rx3, this));


}
MainWindow::~MainWindow()
{
    delete ui;
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
    int id=ui->lineEdit_id->text().toInt();
    ui->lineEdit_id->clear();
    QString  nom=ui->lineEdit_nom->text();
    ui->lineEdit_nom->clear();
    QString  prenom=ui->lineEdit_prenom->text();
    ui->lineEdit_prenom->clear();
    QDate date_naissance=ui->dateTimeEdit_ajouter->date();
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
        QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("select id_e from EMPLOYERS");
        ui->comboBox_id_modifier->setModel(model);
        ui->comboBox_id_supprimer->setModel(model);
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectue\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectue"),QObject::tr("click cancel to exit"));
    }
}
void MainWindow::on_pushButtonSupprimer_clicked()
{
    int id=ui->comboBox_id_supprimer->currentText().toUInt();
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
        QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("select id_e from EMPLOYERS");
        ui->comboBox_id_modifier->setModel(model);
        ui->comboBox_id_supprimer->setModel(model);
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectuer"),QObject::tr("click cancel to exit"));
    }
    }
}
void MainWindow::on_pushButtonModifier_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    QSqlQuery query;
    QString res= ui->comboBox_id_modifier->currentText();
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
    e.setadresse(ui->lineEdit_adresse_e_modifier->text());
    e.settelephone(ui->lineEdit_telephone_e_modifier->text().toInt());
    e.settype(ui->lineEdit_type_modifier->text());
    e.setspecialite(ui->lineEdit_specialite_modifier->text());

    int id_e=ui->comboBox_id_modifier->currentText().toInt();
    bool test2=e.modifier(id_e);
    if(test2)
    {
        //Refresh affichage
        ui->tableViewAficherEmployers->setModel(e.afficher());
        QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("select id_e from EMPLOYERS");
        ui->comboBox_id_modifier->setModel(model);
        ui->comboBox_id_supprimer->setModel(model);
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectuer"),QObject::tr("click cancel to exit"));
    }
}


void MainWindow::on_pushButtonafficher_clicked()
{
    ui->tableViewAficherEmployers->setModel(e.afficher());
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select id_e from EMPLOYERS");
    ui->comboBox_id_modifier->setModel(model);
    ui->comboBox_id_supprimer->setModel(model);
}


void MainWindow::on_pushButton_40_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}


























//login******************************
void MainWindow::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
           QString password = ui->lineEdit_password->text();

           if (username == "admin" && password == "admin") {
               QMessageBox::information(this, "Login", "Username and password are correct");
            ui->stackedWidget->setCurrentIndex(0);

           }
           else {
               QMessageBox::warning(this, "Login", "Username and password are not correct");
           }
}



//************BOUTON RECHERCHER*************************
void MainWindow::on_rechercheEmployerButton_clicked()
{
        QString i=ui->lineEdit_idEmployerachercher->text();
        ui->tableViewAficherEmployers->setModel(e.rechercheMulticritere(i));
}



//*********************BOUTON EMAIL******************************
void MainWindow::on_pushButton_clicked()
{
    Smtp *newMail  = new Smtp("arij.afaya@esprit.tn","chouchene.iheb00@gmail.com"," Your Subject","My body text");
    //delete newMail;
}


