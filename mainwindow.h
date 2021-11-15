#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "caisse.h"
#include <QPrintDialog>
#include <QPrinter>

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
    void on_pushButtonSupprimer_clicked();
    void on_pushButtonModifier_clicked();
    void on_pushButtonModifier2_clicked();
    void on_recette_clicked();
    void on_pushButtonRetourRecette_clicked();
    void on_pushButtonRetourModifier_clicked();
    void on_pushButtonAfficher_clicked();
    void on_pushButtom_Pousser_clicked();
    void on_comboBoxCriter_activated();

    void on_pushButtonImprimer_clicked();

    void on_pushButton_impression_clicked();

    void on_pushButtonRetourIm_clicked();

    QModelIndex on_tableViewAficherFacture_activated();

    void on_lineEdit_prix_unitaire_editingFinished();

    void on_lineEdit_quantite_editingFinished();

    void on_pushButton_stat_clicked();

    void on_lineEdit_rechercher_textChanged();

private:
    Ui::MainWindow *ui;
    MainWindow *secgialog;
    caisse c;
};

#endif // MAINWINDOW_H
