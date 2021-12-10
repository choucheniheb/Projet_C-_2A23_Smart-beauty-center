#ifndef HISTORIQUE_WAJDI_H
#define HISTORIQUE_WAJDI_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>

class historique_wajdi
{
    QString tmp;
  public:
      historique_wajdi();
      void save_wajdi(QString,QString,QString,QString,QString);


      QString load_wajdi();
};

#endif
