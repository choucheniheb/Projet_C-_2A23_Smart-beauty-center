#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include<QPixmap>
#include <QString>
#include<QDebug>
#include <QDate>
#include <QMessageBox>
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

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    //image****
    ui->setupUi(this);
    ui->stackedWidget1->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);
    ui->dateTimeEdit_ajouter->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_modifier->setDateTime(QDateTime::currentDateTime());
    //ajouter**************
    ui->lineEdit_num_fact->setValidator ( new QIntValidator(0, 999999999, this));
    ui->lineEdit_prix_unitaire->setValidator ( new QIntValidator(0, 999999999, this));
    ui->lineEdit_quantite->setValidator ( new QIntValidator(0, 999999999, this));
    ui->lineEdit_prix_totale->setValidator ( new QIntValidator(0, 999999999, this));
    //modifier***************
    ui->lineEdit_prix_u_modifier->setValidator ( new QIntValidator(0, 999999999, this));
    ui->lineEdit_quntiter_modifier->setValidator ( new QIntValidator(0, 999999999, this));
    ui->lineEdit_prix_t_modifier->setValidator ( new QIntValidator(0, 999999999, this));
    //tri**********************
        QPixmap pix("C:/Users/Ihebc/OneDrive/Desktop/gestion de caise/image/pix2.png");
        int w1 = ui->label_pic1->width();
        int h1 = ui->label_pic1->height();
        ui->label_pic1->setPixmap(pix.scaled(w1,h1,Qt::KeepAspectRatio));
        //insrtion image2
        int w2 = ui->label_pic2->width();
        int h2 = ui->label_pic2->height();
        ui->label_pic2->setPixmap(pix.scaled(w2,h2,Qt::KeepAspectRatio));
        //insrtion image3
        int w3 = ui->label_pic3->width();
        int h3 = ui->label_pic3->height();
        ui->label_pic3->setPixmap(pix.scaled(w3,h3,Qt::KeepAspectRatio));
        //insrtion image4
        int w4 = ui->label_pic4->width();
        int h4 = ui->label_pic4->height();
        ui->label_pic4->setPixmap(pix.scaled(w4,h4,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//ajouter************
void MainWindow::on_pushButtonAjouter_clicked()
{
    //recuperation
    int num_f=ui->lineEdit_num_fact->text().toInt();
    ui->lineEdit_num_fact->clear();
    QDateTime date=ui->dateTimeEdit_ajouter->dateTime();
    float prix_u=ui->lineEdit_prix_unitaire->text().toFloat();
    ui->lineEdit_prix_unitaire->clear();
    int quantite=ui->lineEdit_quantite->text().toInt();
    ui->lineEdit_quantite->clear();
    int id_c=ui->comboBox_id_c->currentText().toInt();
    float prix_t=ui->lineEdit_prix_totale->text().toFloat();
    ui->lineEdit_prix_totale->clear();
    caisse c(num_f,date,prix_u,quantite,prix_t,id_c);//instancer
    bool test=c.ajouter();

    if(test)
    {
        //Refresh affichage
        ui->tableViewAficherFacture->setModel(c.afficher());
        QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("SELECT num_facture from FACTURES");
        ui->comboBox_num_facture_mod->setModel(model);
        ui->comboBox_num_fact_sup->setModel(model);
        //****************************************
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajouter non effectuer"),QObject::tr("click cancel to exit"));
    }
}

//affichage*********
void MainWindow::on_pushButtonAfficher_clicked()
{
    ui->tableViewAficherFacture->setModel(c.afficher());
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT num_facture from FACTURES");
    ui->comboBox_num_facture_mod->setModel(model);
    ui->comboBox_num_fact_sup->setModel(model);
    QSqlQueryModel *model1=new QSqlQueryModel();
    model1->setQuery("SELECT id_c from client");
    ui->comboBox_id_c->setModel(model1);
}

//paiment******
void MainWindow::on_pushButtom_Pousser_clicked()
{
QDesktopServices::openUrl(QUrl("https://www.coinbase.com/dashboard"));
}


//supprimer********************
void MainWindow::on_pushButtonSupprimer_clicked()
{
    int num_fact=ui->comboBox_num_fact_sup->currentText().toInt();
    bool test1=c.supprimer(num_fact);
    if(test1)
    {
        //Refresh affichage
        ui->tableViewAficherFacture->setModel(c.afficher());
        QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("SELECT num_facture from FACTURES");
        ui->comboBox_num_facture_mod->setModel(model);
        ui->comboBox_num_fact_sup->setModel(model);
        //****************************************
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectuer"),QObject::tr("click cancel to exit"));
    }
}

void MainWindow::on_pushButtonModifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QSqlQuery query;
    QString res=ui->comboBox_num_facture_mod->currentText();
    query.prepare("SELECT prix_unitaire from FACTURES WHERE num_facture= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    ui->lineEdit_prix_u_modifier->setText(query.value(0).toString());
    query.prepare("SELECT prix_totale from FACTURES WHERE num_facture= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    ui->lineEdit_prix_t_modifier->setText(query.value(0).toString());
    query.prepare("SELECT quantite_f from FACTURES WHERE num_facture= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    ui->lineEdit_quntiter_modifier->setText(query.value(0).toString());
}

//modifier**************
void MainWindow::on_pushButtonModifier2_clicked()
{
    //modifier les valeur de class
    c.setdate(ui->dateTimeEdit_modifier->dateTime());
    c.setprix_unitair(ui->lineEdit_prix_u_modifier->text().toFloat());
    ui->lineEdit_prix_u_modifier->clear();
    c.setquantiter(ui->lineEdit_quntiter_modifier->text().toInt());
    ui->lineEdit_quntiter_modifier->clear();
    c.setprix_totale(ui->lineEdit_prix_t_modifier->text().toFloat());
    ui->lineEdit_prix_t_modifier->clear();

    //modifier requete************
    int num_fact=ui->comboBox_num_facture_mod->currentText().toInt();
    bool test2=c.modifier(num_fact);
    ui->stackedWidget->setCurrentIndex(0);
    if(test2)
    {
        //Refresh affichage
        ui->tableViewAficherFacture->setModel(c.afficher());
        QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("SELECT num_facture from FACTURES");
        ui->comboBox_num_facture_mod->setModel(model);
        ui->comboBox_num_fact_sup->setModel(model);
        //****************************************
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectuer\n"),QObject::tr("click cancel to exit"));
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectuer"),QObject::tr("click cancel to exit"));
    }
}

//recette***********
void MainWindow::on_recette_clicked()
{
    ui->stackedWidget1->setCurrentIndex(1);
    QSqlQuery query=c.calculerecette();
    query.exec();
    query.next();
    ui->lineEditRecette->setText(query.value(0).toString());
}

//retour***********
void MainWindow::on_pushButtonRetourRecette_clicked()
{
    ui->stackedWidget1->setCurrentIndex(0);
}

//retour************
void MainWindow::on_pushButtonRetourModifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
//tri***************
void MainWindow::on_comboBoxCriter_activated()
{
    if(ui->comboBoxCriter->currentText()=="Tri par id")
    {
        ui->tableViewAficherFacture->setModel(c.triParId());
    }else if(ui->comboBoxCriter->currentText()=="Tri par date")
    {
        ui->tableViewAficherFacture->setModel(c.triParDate());
    }else if(ui->comboBoxCriter->currentText()=="Tri par prix")
    {
        ui->tableViewAficherFacture->setModel(c.triParPrix());
    }
}

void MainWindow::on_pushButtonImprimer_clicked()
{
    ui->stackedWidget1->setCurrentIndex(2);
    QSqlQuery query;
    QModelIndex index;
    index=on_tableViewAficherFacture_activated();
    QString res= ui->tableViewAficherFacture->model()->data(ui->tableViewAficherFacture->model()->index(index.row(),0)).toString();
    qDebug()<<res;
    query.prepare("SELECT id_c from FACTURES WHERE num_facture= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    QString id_c=query.value(0).toString();
    query.prepare("SELECT prix_unitaire from FACTURES WHERE num_facture= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    QString prix_uni=query.value(0).toString();
    query.prepare("SELECT quantite_f from FACTURES WHERE num_facture= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    QString quantite=query.value(0).toString();
    query.prepare("SELECT prix_totale from FACTURES WHERE num_facture= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    QString prix_totale=query.value(0).toString();
    query.prepare("SELECT nom_c from client WHERE id_c= :id_c");
    query.bindValue(":id_c",id_c);
    query.exec();
    query.next();
    QString nom=query.value(0).toString();
    query.prepare("SELECT prenom_c from client WHERE id_c= :id_c");
    query.bindValue(":id_c",id_c);
    query.exec();
    query.next();
    QString prenom=query.value(0).toString();
    query.prepare("SELECT telephone_c from client WHERE id_c= :id_c");
    query.bindValue(":id_c",id_c);
    query.exec();
    query.next();
    QString tel=query.value(0).toString();
    query.prepare("SELECT date_d from FACTURES WHERE num_facture= :res");
    query.bindValue(":res",res);
    query.exec();
    query.next();
    QString date=query.value(0).toString();
    QString imp="\t\t\t\t\t\t id client: "+id_c+"\n \t\t\t\t\t\t nom et prenom: "+nom+" "+prenom+"\n \t\t\t\t\t\t telephone: "+tel+"\n \t\t\t\t\t\t date:"+date+"\n\n\n\n \t\t\t prix produit: "+prix_uni+"\n \t\t\t quantiter: "+quantite+"\n \t\t\t prix totale: "+prix_totale;
    ui->textEdit_impression->setText(imp);
    QFont serifFont("Times", 10, QFont::Bold);
    ui->textEdit_impression->setFont(serifFont);
}

void MainWindow::on_pushButton_impression_clicked()
{
    QPrinter printer;
    QPrintDialog dialog(&printer,this);
    if(ui->textEdit_impression->textCursor().hasSelection())
        dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);

    if(dialog.exec()!=QDialog::Accepted)
    {return;}
}

void MainWindow::on_pushButtonRetourIm_clicked()
{
    ui->stackedWidget1->setCurrentIndex(0);
}


QModelIndex MainWindow::on_tableViewAficherFacture_activated()
{
        return ui->tableViewAficherFacture->currentIndex();
}

void MainWindow::on_lineEdit_prix_unitaire_editingFinished()
{
    float prix_u=ui->lineEdit_prix_unitaire->text().toFloat();
    int quantite=ui->lineEdit_quantite->text().toInt();
    QString totale=QString::number(prix_u*quantite);
    ui->lineEdit_prix_totale->setText(totale);
}

void MainWindow::on_lineEdit_quantite_editingFinished()
{
    float prix_u=ui->lineEdit_prix_unitaire->text().toFloat();
    int quantite=ui->lineEdit_quantite->text().toInt();
    QString totale=QString::number(prix_u*quantite);
    ui->lineEdit_prix_totale->setText(totale);
}

void MainWindow::on_pushButton_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                         model->setQuery("select * from factures where prix_totale < 50000 ");
                         float age=model->rowCount();
                         model->setQuery("select * from factures where prix_totale between 50000 and 100000 ");
                         float agee=model->rowCount();
                         model->setQuery("select * from factures where prix_totale > 100000 ");
                         float ageee=model->rowCount();
                         float total=age+agee+ageee;
                         QString a=QString("moins de 50 dinar "+QString::number((age*100)/total,'f',2)+"%" );
                         QString b=QString("entre 50 et 100 dinar"+QString::number((agee*100)/total,'f',2)+"%" );
                         QString c=QString("plus 100 dinar"+QString::number((ageee*100)/total,'f',2)+"%" );
                         QPieSeries *series = new QPieSeries();
                         series->append(a,age);
                         series->append(b,agee);
                         series->append(c,ageee);
                 if (age!=0)
                 {QPieSlice *slice = series->slices().at(0);
                  slice->setLabelVisible();
                  slice->setPen(QPen());}
                 if ( agee!=0)
                 {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(1);
                          //slice1->setExploded();
                          slice1->setLabelVisible();
                 }
                 if(ageee!=0)
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


void MainWindow::on_lineEdit_rechercher_textChanged()
{
    QString rech=ui->lineEdit_rechercher->text();
    ui->tableViewAficherFacture->setModel(c.rechercheMulticritere(rech));
}
