#include "notification.h"

notification::notification()
{

}
void notification::notification_system()
{
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon();
    notifyIcon->show();
    notifyIcon->showMessage("gestion des produits","quantite presque insuffisante",QSystemTrayIcon::Information,15000);
}
