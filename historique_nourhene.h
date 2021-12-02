#ifndef HISTORIQUE_NOURHENE_H
#define HISTORIQUE_NOURHENE_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>


class historique_nourhene
{
    QString tmp;
public:
    historique_nourhene();
    void save(QString,QString,QString,QString,QString,QString,QString);
    QString load();
};

#endif // HISTORIQUE_NOURHENE_H
