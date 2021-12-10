#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QDialog>
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QFileDialog>
#include <QMainWindow>
#include <QtCore/QCoreApplication>
#include <QMainWindow>
#include "client.h"
#include "reservation.h"
#include "arduino.h"
#include "notification.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButtonAjouter_client_clicked();
    void on_pushButtonAfficher_client_clicked();
    void on_pushButtonSupprimer_client_clicked();
    void on_pushButtonModifier2_client_clicked();
    void on_pushButtonModifier_client_clicked();
    void on_cb_tri_client_activated();
    void on_pushButton_Contacter_client_clicked();
    void sendMail();
    void mailSent(QString);
    void browse();
    void on_reserver_client_clicked();
   void on_show_client_clicked();

    void on_pb_supp_res_client_clicked();

    void on_pushButton_reserver_client_clicked();

    void on_quitter_client_clicked();

    void on_exitBtn_client_clicked();

    void on_pushButton_client_clicked();

    void on_lineEdit_rechercher_client_textChanged();

    QModelIndex on_tableViewAficherClient_client_activated();
/********************ARduinoo*****************************/
    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
        // ce slot est lancé à chaque réception d'un message de Arduino

        void on_pushButton_alarme_clicked();   // bouton ON

        void on_pushButton_alarme_2_clicked(); // bouton OFF

private:
    Ui::MainWindow *ui;
    Client C;
    QStringList files;
    Reservation R;
    /*******Arduino*****/
    QByteArray data; // variable contenant les données reçues

        Arduino A; // objet temporaire
     Notification N;
};

#endif // MAINWINDOW_H
