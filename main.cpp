#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QTranslator>
#include<QInputDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator t;
        QStringList languages;
        languages <<"French" << "English" ;
        QString lang = QInputDialog::getItem(NULL, "Select Language", "Language",languages);
        if ( lang == "English")
        {
            t.load("C:/Users/Ihebc/OneDrive/Desktop/integration/Anglais.qm");
        }
        if (lang != "French")
        {
            a.installTranslator(&t);
        }
        MainWindow w;
    Connection c;
    bool test=c.createconnect();
    w.show();
    return a.exec();
}
