#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
Notification::Notification()
{

}

void Notification::notification_ajoutEmployer()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Employers ","nouveau employer est ajouté ",QSystemTrayIcon::Information,15000);
}

void Notification::notification_supprimerEmployer(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Employers ","nouveau employer est supprimé",QSystemTrayIcon::Information,15000);
}


void Notification::notification_modifierEmployer(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Employers ","nouveau employer est modifié",QSystemTrayIcon::Information,15000);

}
