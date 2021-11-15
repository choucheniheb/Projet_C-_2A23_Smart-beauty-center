#include "notification.h"

notification::notification()
{

}
void notification::notification_livrer()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon();
    notifyIcon->show();
        notifyIcon->showMessage("Gestion des fournisseurs ","vous avez une livraison aujourd'hui ",QSystemTrayIcon::Information,15000);
}
