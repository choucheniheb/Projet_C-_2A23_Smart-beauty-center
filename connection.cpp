#include "connection.h"
//test Tutoriel Git
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");//inserer le nom de la source de données ODBC
db.setUserName("arij");//inserer nom de l'utilisateur
db.setPassword("arij");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
