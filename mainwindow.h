#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseur.h"
#include <QMainWindow>
#include<dumessengerconnectiondialog.h>
#include <QTcpSocket>
//****************************************
#include "caisse.h"
#include <QPrintDialog>
#include <QPrinter>
#include <QPainter>
//*********************************************
#include "notification_nourhene.h"
#include "historique_nourhene.h"
#include "produit.h"
//*****************************************************
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
//**********************************************************
#include "service.h"
#include<QSql>
#include <QDebug>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
/*#include <QtQuickWidgets>
#include <QQuickItem>*/
#include <QVariant>
//********************************************************
#include <QString>
#include <QDialog>
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QFileDialog>
#include <QMainWindow>
#include <QtCore/QCoreApplication>
#include "employers.h"
#include <QTimer>
#include <QTcpSocket>

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
    void on_pushButton_ajouter_fournisseur_clicked();
    void on_pushButtonSupprimer_fournisseur_clicked();
    void on_pushButtonModifier_fournisseur_clicked();
    void   on_pushButtonModifier2_fournisseur_clicked();
    void on_pushButtonRetourMod_fournisseur_clicked();
    void on_pushButtonafficher_fournisseur_clicked();
    void on_lineEdit_chercher_fournisseur_textChanged();
    QModelIndex on_tableViewAficherfournisseur_activated();
    void on_pushButton_excel_fournisseur_clicked();
    void on_pb_envoyer_clicked();
    void on_pb_connecter_clicked();
    //***************************************************************************************************
    void on_lineEdit_rechercher_facture_textChanged();
    void on_pushButtonreset_facture_clicked();
    void on_pushButton_go_to_caisse_clicked();
    void on_pushButton_go_to_fournisseur_clicked();
    void on_pushButton_stat_facture_clicked();
    void on_lineEdit_quantite_facture_editingFinished();
    void on_lineEdit_prix_unitaire_facture_editingFinished();
    QModelIndex on_tableViewAficherFacture_activated();
    void on_pushButtonImprimer_facture_clicked();
    void on_comboBoxCriter_facture_activated();
    void on_pushButtonRetourModifier_facture_clicked();
    void on_pushButtonRetourRecette_facture_clicked();
    void on_recette_facture_clicked();
    void on_pushButtonModifier2_facture_clicked();
    void on_pushButtonModifier_facture_clicked();
    void on_pushButtonSupprimer_facture_clicked();
    void on_pushButtom_Pousser_facture_clicked();
    void on_pushButtonAfficher_facture_clicked();
    void on_pushButtonAjouter_facture_clicked();
    //*****************************************************************************************************
    void on_pushButtonSupprimer_produit_clicked();
        void on_aj_button_produit_clicked();
    void on_pushButtonModifier_produit_clicked();
    void on_pushButtonModifier2_produit_clicked();
    void on_makeup_bottom_produit_clicked();
    void on_cosmetiques_bottom_produit_clicked();
    void on_parfums_bottom_produit_clicked();
    void on_pushButtonModifier2_2_produit_clicked();
    void on_categorie_bottom_produit_clicked();
    void on_codeabarre1_produit_clicked();
    void on_codeabarre1_2_produit_clicked();
    void on_codeabarre1_3_produit_clicked();
    QModelIndex on_tableViewproduit_activated();
    void on_pushButton_refrech_produit_clicked();
    void on_historiqueButton_produit_clicked();
    void on_pushButton_go_to_produit_clicked();

    void on_lineEdit_chercher_produit_textChanged();
    //**************************************************************************************************************
    void on_pushButtonAjouter_client_3_clicked();
    void on_pushButtonAfficher_client_3_clicked();
    void on_pushButtonSupprimer_client_3_clicked();
    void on_pushButtonModifier2_client_3_clicked();
    void on_pushButtonModifier_client_3_clicked();
    void on_cb_tri_client_3_activated();
    void on_pushButton_Contacter_client_3_clicked();
    void sendMail();
    void mailSent(QString);
    void browse();
    void on_reserver_client_3_clicked();
    void on_show_client_3_clicked();
    void on_pb_supp_res_client_3_clicked();
    void on_pushButton_reserver_client_3_clicked();
    void on_quitter_client_3_clicked();
    void on_exitBtn_client_3_clicked();
    void on_pushButton_client_3_clicked();
    void on_lineEdit_rechercher_client_3_textChanged();
    QModelIndex on_tableViewAficherClient_client_3_activated();

    void on_pushButton_go_to_client_clicked();
    //***********************************************************************************************************************
    void  on_pushButton_ajouter_clicked ();
    void  on_pushButton_supprimer_clicked();
    void on_pushButtonModifier_clicked();
    void on_pushButtonModifier2_clicked();
    void on_pushButtonafficher_clicked();
   void on_lineEdit_chercher_service_textChanged();
   void on_pushButton_pdf_clicked();
  void on_pushButton_folder_clicked();
   QModelIndex on_tableViewAfficherService_activated();
   void on_pushButton_retour_modifier_clicked();
   void on_pushButton_location_clicked();
   //*****************************************************************************************
   void on_pushButtonAjouter_employer_clicked();
   void on_pushButtonSupprimer_employer_clicked();
   void on_pushButtonModifier_employer_clicked();
   void on_pushButtonModifier2_employer_clicked();
   void on_pushButtonafficher_employer_clicked();
   void on_pushButton_Login_clicked();
   bool search(int t);
   void on_pushButton_40_clicked();
   void on_pushButtonAjouterh_clicked();
   void on_pushButton_planning_clicked();
   void on_comboBox_id_p_activated();
   void on_lineEdit_idEmployerachercher_cursorPositionChanged();
   void on_comboBoxTri_activated();
   void on_pushButton_PDF_employer_clicked();
   void on_pushButton_Contacter_employer_clicked();
   void browse_employer();
   void sendMail_employer();
   void mailSent_employer(QString status);
   void on_pushButton_6_clicked();
   QModelIndex on_tableViewAficherEmployers_activated();
   void on_pushButton_clicked();
   //******************
   void myfunction();
   //******************
   void on_QrCode_clicked();
   void on_pb_envoyer_employer_clicked();
   void on_pb_connecter_employer_clicked();
   void on_tableViewAficherEmployers_clicked(const QModelIndex &index);


   void on_pushButton_go_to_service_clicked();

   void on_pushButton_go_to_employer_clicked();

   void on_pushButton_gestion_facture_clicked();

   void on_pushButton_ajouter_facture_clicked();

   void on_pushButtonRetourAjouter_facture_clicked();

   void on_pushButtonRetourAfficher_facture_clicked();

   void on_pushButton_quiter_clicked();

private:
    Ui::MainWindow *ui;
    fournisseur f;
    QTcpSocket *mSocket;
    caisse c;
    MainWindow *secgialog;
    produit p;
    historique_nourhene histo;
    historique_nourhene histo1;
    Client C;
    QStringList files;
    Reservation R;
    Service S ;

    QMediaPlayer* player;
    QVideoWidget* vw ;
    QProgressBar* bar ;
    QSlider* slider ;

    Employers e;
    //**************
    QTimer *timer;
};

#endif // MAINWINDOW_H
