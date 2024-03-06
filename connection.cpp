#include "connection.h"
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
Connection::Connection(){}

bool Connection::createconnection()

{
bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");
db.setUserName("chiraz");//inserer nom de l'utilisateur
db.setPassword("chiraz");//inserer mot de passe de cet utilisateur

if (db.open()) test=true;

return  test;
}

void Connection::closeconnection()
{
    db.close();}
