#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produit.h"
#include "historique.h"
#include <QMainWindow>

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

void on_pushButtonSupprimer_clicked();
    void on_aj_button_clicked();


void on_pushButtonModifier_clicked();
void on_pushButtonModifier2_clicked();

void on_makeup_bottom_clicked();

void on_cosmetiques_bottom_clicked();

void on_parfums_bottom_clicked();
void on_pushButtonModifier2_2_clicked();

void on_categorie_bottom_produit_clicked();

void on_codeabarre1_produit_clicked();

void on_codeabarre1_2_produit_clicked();

void on_codeabarre1_3_produit_clicked();
void on_lineEdit_chercher_cursorPositionChanged_textChanged();

QModelIndex on_tableViewproduit_activated();

void on_pushButton_refrech_clicked();

void on_historiqueButton_clicked();

private:
    Ui::MainWindow *ui;
produit p;
historique histo;
};

#endif // MAINWINDOW_H
