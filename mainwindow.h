#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employers.h"
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
    void on_pushButtonafficher_clicked();


    void on_pushButton_Login_clicked();
    void on_rechercheEmployerButton_clicked();
    bool search(int t);

    void on_pushButton_clicked();

    void on_pushButton_40_clicked();


private:
    Ui::MainWindow *ui;
    Employers e;
};

#endif // MAINWINDOW_H
