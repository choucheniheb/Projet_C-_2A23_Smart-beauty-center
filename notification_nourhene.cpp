#include "notification_nourhene.h"

notification_nourhene::notification_nourhene()
{

}
void notification_nourhene::notification_system()
{
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon();
    notifyIcon->show();
    notifyIcon->showMessage("gestion des produits","quantite presque insuffisante",QSystemTrayIcon::Information,15000);
}
