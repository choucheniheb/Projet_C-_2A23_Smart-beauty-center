#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseur.h"
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
   void on_pushButton_ajouter_clicked();
   void on_pushButtonSupprimer_clicked();
   void on_pushButtonModifier_clicked();
   void   on_pushButtonModifier2_clicked();
private:
    Ui::MainWindow *ui;
    fournisseur f;
};

#endif // MAINWINDOW_H
