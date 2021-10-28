#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "caisse.h"
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
private:
    Ui::MainWindow *ui;
    caisse c;
};

#endif // MAINWINDOW_H
