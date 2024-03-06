#include "equipement.h"
#include <QDebug>
#include <iostream>
#include "QString"

Equipement::Equipement(int id,QString nom,int nb,QString frsr,int dep,QString etat,QString stat)
{

    this->id=id;
    this->nom=nom;
    this->nb=nb;
    this->frsr=frsr;
    this->dep=dep;
    this->etat=etat;
    this->stat=stat;

}



bool Equipement::AjoutEq()
{

    QSqlQuery query;
    QString a= QString::number(id);
    QString b= QString::number(nb);
    QString c= QString::number(dep);


    //préparation de la requete
    query.prepare("insert into EQUIPEMENT(id,nom,nb,frsr,dep,etat,stat)""values(:id,:nom,:nb,:frsr,:dep,:etat,:stat)");
    //Création des variables liées
    query.bindValue(":id",a);
    query.bindValue(":nom",nom);
    query.bindValue(":nb",b);
    query.bindValue(":frsr",frsr);
    query.bindValue(":dep",c);
    query.bindValue(":etat",etat);
    query.bindValue(":stat",stat);

    return query.exec(); // exec() envoie la requete pour l'exécuter


}

QSqlQueryModel *Equipement::AfficheEq()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from equipement");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NB"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("FRSR"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DEP"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("STAT"));
    return model;



}

bool Equipement::SupprimerEq(int idd)
{
QSqlQuery query;
QString id=QString:: number(idd);
query.prepare("Delete from equipement where ID = :id");
query.bindValue(":id",id);
return query.exec();


}



bool Equipement::ModifierEq(int selected){

    QSqlQuery query;


    query.prepare(" UPDATE EQUIPEMENT SET ID= :id ,NOM= :nom ,NB= :nb ,FRSR= :frsr ,DEP= :dep ,ETAT= :etat ,STAT= :stat "
                  " where ID= :id");
    query.bindValue(":id", selected);
    query.bindValue(":nom", nom);
    query.bindValue(":nb", nb);
    query.bindValue(":frsr", frsr);
    query.bindValue(":dep", dep);
    query.bindValue(":etat", etat);
    query.bindValue(":stat", stat);


    return    query.exec();

}

QSqlQueryModel * Equipement::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM EQUIPEMENT ORDER BY DEP");
        return model;
}
QSqlQueryModel * Equipement::tridispo()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM EQUIPEMENT ORDER BY STAT");
        return model;
}
QSqlQueryModel * Equipement::trietat()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM EQUIPEMENT ORDER BY ETAT");
        return model;
}

QSqlQueryModel* Equipement::rechercher(int a)
{
    QString res= QString::number(a);
    QSqlQueryModel * query=new QSqlQueryModel();
    query->setQuery("select * from EQUIPEMENT where (ID like '%"+res+"%' ) ");
    return    query;
}

