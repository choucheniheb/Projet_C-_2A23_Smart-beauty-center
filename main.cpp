#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QTranslator>
#include<QInputDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QTranslator t;
        QStringList languages;
        languages <<"French" << "English" ;
        QString lang = QInputDialog::getItem(NULL, "Select Language", "Language",languages);
        if ( lang == "English")
        {
            t.load(":/anglais.qm");
        }
        if (lang != "French")
        {
            a.installTranslator(&t);
        }
    Connection c;
    bool test=c.createconnect();
    w.show();
    return a.exec();
}
