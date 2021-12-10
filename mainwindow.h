#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "service.h"
#include <QMainWindow>
#include<QSql>
#include <QDebug>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include <QtQuickWidgets>
#include <QQuickItem>
#include <QVariant>
#include "arduino.h"
#include "notification.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QSqlDatabase db ;
    void connClose()
    {
        db.close();
        db.removeDatabase("Atelier_Connexion.db");
    }
    bool connOpen()
    {
        db =QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("Atelier_Connexion.db");
          if (db.open()){
              qDebug() <<"no connection to Database";
              return false;
          }else{
              qDebug()<<"Database connected";
              return true;
          }
    }


    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots :
   void  on_pushButton_ajouter_clicked ();
   void  on_pushButton_supprimer_clicked();
   void on_pushButtonModifier_clicked();
   void on_pushButtonModifier2_clicked();
   void on_pushButtonafficher_clicked();
  void on_lineEdit_chercher_cursorPositionChanged_textChanged();
  void on_pushButton_pdf_clicked();




 void on_pushButton_folder_clicked();

/*void on_pushButton_play_clicked();

  void on_pushButton_pause_clicked();

  void on_pushButton_stop_clicked();*/


  QModelIndex on_tableViewAfficherService_activated();

  void on_pushButton_retour_modifier_clicked();

  void on_pushButton_location_clicked();

  void on_lineEdit_textChanged(const QString &arg1);

  void on_pushButton_alarme_clicked();

  void on_pushButton_alarme2_clicked();

  void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
  // ce slot est lancé à chaque réception d'un message de Arduino


  void on_comboBox_a_activated(const QString &arg1);


  



private:
    Ui::MainWindow *ui;
    Service S ;

    QMediaPlayer* player;
    QVideoWidget* vw ;
    QProgressBar* bar ;
    QSlider* slider ;


    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
    Notification N;

signals:
void setCenter(QVariant, QVariant);

};

#endif // MAINWINDOW_H
