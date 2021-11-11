#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "service.h"
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
private slots :
   void  on_pushButton_ajouter_clicked ();
   void  on_pushButton_supprimer_clicked();
   void on_pushButtonModifier_clicked();
   void on_pushButtonModifier2_clicked();
   void on_pushButtonafficher_clicked();
private:
    Ui::MainWindow *ui;
    Service S ;
};

#endif // MAINWINDOW_H
