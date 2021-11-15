#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QMessageBox>
#include <QFile>
#include <QTextStream>
#include<QDate>
#include<QDebug>
#include <QFileDialog>
#include"notification.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tableViewAficherfournisseur->setModel(f.afficher());
/****************************************************/


   QPixmap pix2("C:/Users/wajdi/Desktop/image/pix2.png");
// ajouter photo
int w=ui->label_pic ->width();

int h=ui->label_pic ->height();
          ui->label_pic->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));


// photo modifier

            // QPixmap pix2("C:/Users/wajdi/Desktop/image/pix2.png");

// photo afficher
            int w2=ui->label_aff ->width();

            int h2=ui->label_aff ->height();
                      ui->label_aff->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));
// photo supprimer


                                //historique
                               /* int w4=ui->label_h ->width();

                                int h4=ui->label_h ->height();
                                          ui->label_h->setPixmap(pix2.scaled(w4,h4,Qt::KeepAspectRatio));*/

// controle de  saisie
ui->lineEdit_num_f->setValidator(new QIntValidator(0,99999999,this));
ui->lineEdit_code_f->setValidator(new QIntValidator(0,9999,this));


   QRegularExpression rx("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
   QRegularExpression::CaseInsensitiveOption);
ui->lineEdit_nom_f->setValidator(new QRegularExpressionValidator(rx, this));

QRegularExpression rx1("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
       QRegularExpression::CaseInsensitiveOption);
ui->lineEdit_produit_vendu->setValidator(new QRegularExpressionValidator(rx, this));

QRegularExpression rx2("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
       QRegularExpression::CaseInsensitiveOption);
ui->lineEdit_produit_modifier->setValidator(new QRegularExpressionValidator(rx, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_clicked()
{

    //recuperation
   QString nom_f=ui->lineEdit_nom_f->text();
   ui->lineEdit_nom_f->clear();

    float prix_gros=ui->lineEdit_prix_gros->text().toFloat();
    ui->lineEdit_prix_gros->clear();

    int num_f=ui->lineEdit_num_f->text().toUInt();
    ui->lineEdit_num_f->clear();

    int code_f=ui->lineEdit_code_f->text().toUInt();
    ui->lineEdit_code_f->clear();

     QString produit_vendu=ui->lineEdit_produit_vendu->text();
     ui->lineEdit_produit_vendu->clear();
    fournisseur f(num_f,code_f,prix_gros,nom_f,produit_vendu);//instancer
    bool test=f.ajouter();
    if(test)
    {
        ui->tableViewAficherfournisseur->setModel(f.afficher());//rafraishissement
        QString c=QString::number(code_f);
        QString message2="ajouter un fournisseur: "+c;
        f.ajouterhist(message2);
        ui->tableView_hist->setModel(f.afficherhist());
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



void MainWindow::on_pushButtonSupprimer_clicked()
{
    QModelIndex index=on_tableViewAficherfournisseur_activated();
    int code_f=ui->tableViewAficherfournisseur->model()->data(ui->tableViewAficherfournisseur->model()->index(index.row(),0)).toInt();
    bool test1=f.supprimer(code_f);
    if(test1)
    {
        QString c=QString::number(code_f);
        QString message2="supprimer un fournisseur: "+c;
        f.ajouterhist(message2);
        ui->tableView_hist->setModel(f.afficherhist());
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


void MainWindow::on_pushButtonModifier_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}
void MainWindow::on_pushButtonRetourMod_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}
void MainWindow::on_pushButtonModifier2_clicked()
{
    //modifier les valeur de class

    f.setproduit_vendu(ui->lineEdit_produit_modifier->text());
   f.setprix_gros(ui->lineEdit_prix_modifier->text().toInt());


    //modifier requete************
   QModelIndex index=on_tableViewAficherfournisseur_activated();
   int code_f=ui->tableViewAficherfournisseur->model()->data(ui->tableViewAficherfournisseur->model()->index(index.row(),0)).toInt();
    bool test2=f.modifier(code_f);

    if(test2)
    {
        QString c=QString::number(code_f);
        QString message2="modifier un fournisseur: "+c;
        f.ajouterhist(message2);
        ui->tableView_hist->setModel(f.afficherhist());
        ui->tableViewAficherfournisseur->setModel(f.afficher());//rafraishissement
        QMessageBox::information(nullptr, QObject::tr("fournisseur modifié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->stackedWidget_2->setCurrentIndex(0);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("fournisseur non modifié"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }







void MainWindow::on_pushButtonafficher_clicked()
{
    ui->tableViewAficherfournisseur->setModel(f.afficher());
    ui->tableView_hist->setModel(f.afficherhist());
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


void MainWindow::on_lineEdit_chercher_cursorPositionChanged_textChanged()
{
    QString i=ui->lineEdit_chercher_cursorPositionChanged->text();
    ui->tableViewAficherfournisseur->setModel(f.rechercheMulticritere(i));
}

QModelIndex MainWindow::on_tableViewAficherfournisseur_activated()
{
    return ui->tableViewAficherfournisseur->currentIndex();



}

void MainWindow::on_pushButton_clicked()
{
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
