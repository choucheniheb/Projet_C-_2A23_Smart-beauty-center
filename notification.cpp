#include "notification.h"

Notification::Notification()
{

}


void Notification::Notification_system()
{
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon();
    notifyIcon->show();
    notifyIcon->showMessage(" Motion detected","",QSystemTrayIcon::Information,15000);
}
void Notification::Notification_sys()
{
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon();
    notifyIcon->show();
    notifyIcon->showMessage("Motion Ended  ","",QSystemTrayIcon::Information,15000);
}
