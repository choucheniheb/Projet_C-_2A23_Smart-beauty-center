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
    void on_pushButtonAjouter_clicked();
    void on_pushButtonAfficher_clicked();
    void on_pushButtonSupprimer_clicked();
    void on_pushButtonModifier2_clicked();
    void on_pushButtonModifier_clicked();
    void on_cb_tri_activated();
    void on_pushButton_Contacter_clicked();
    void sendMail();
    void mailSent(QString);
    void browse();





    void on_reserver_clicked();

    void on_show_clicked();

    void on_pb_supp_res_clicked();

    void on_pushButton_reserver_clicked();

    void on_quitter_clicked();

    void on_exitBtn_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_rechercher_textChanged();

    QModelIndex on_tableViewAficherClient_activated();

private:
    Ui::MainWindow *ui;
    Client C;
    QStringList files;
    Reservation R;

};

#endif // MAINWINDOW_H
