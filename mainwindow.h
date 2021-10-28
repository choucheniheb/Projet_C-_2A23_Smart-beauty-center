#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produit.h"

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

private:
    Ui::MainWindow *ui;
produit p;
};

#endif // MAINWINDOW_H
