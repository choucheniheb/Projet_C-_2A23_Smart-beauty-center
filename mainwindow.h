#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QDialog>
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QFileDialog>
#include <QMainWindow>
#include <QtCore/QCoreApplication>
#include "employers.h"
#include <QTimer>
#include"DuMessengerConnectionDialog.h"
#include <QTcpSocket>
namespace  Ui{
class MainWindow;
}
QT_END_NAMESPACE
class QTcpSocket;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButtonAjouter_clicked();
    void on_pushButtonSupprimer_clicked();
    void on_pushButtonModifier_clicked();
    void on_pushButtonModifier2_clicked();
    void on_pushButtonafficher_clicked();


    void on_pushButton_Login_clicked();

    bool search(int t);


    void on_pushButton_40_clicked();


    void on_pushButtonAjouterh_clicked();

    void on_pushButton_planning_clicked();

    void on_comboBox_id_p_activated();

    void on_lineEdit_idEmployerachercher_cursorPositionChanged();

    void on_comboBoxTri_activated();

    void on_pushButton_PDF_clicked();

    void on_pushButton_Contacter_clicked();
    void browse();
    void sendMail();
    void mailSent(QString status);
    //void on_pushButton_43_clicked();

    void on_pushButton_6_clicked();

    QModelIndex on_tableViewAficherEmployers_activated();

    void on_pushButton_clicked();


    //******************
    void myfunction();
    //******************

    void on_QrCode_clicked();
    void on_pb_envoyer_clicked();

    void on_pb_connecter_clicked();

    void on_tableViewAficherEmployers_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Employers e;
    QStringList files;
    //**************
    QTimer *timer;
    QTcpSocket *mSocket;
};

#endif // MAINWINDOW_H
