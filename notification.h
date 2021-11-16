#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <QSystemTrayIcon>
#include<QString>
class Notification
{
public:
    Notification();
    void notification_ajoutEmployer();
    void notification_supprimerEmployer();
    void notification_modifierEmployer();
};

#endif // NOTIFICATION_H
