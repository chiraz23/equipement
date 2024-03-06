#include "competition.h"
#include <QDebug>
#include <iostream>
#include "QString"




Competition::Competition(int idComp,int nbrPar,int gagnants,QString endroit,QString dateComp,QString type_prix,QString categorie)
{

    this->idComp=idComp;
    this->nbrPar=nbrPar;
    this->gagnants=gagnants;
    this->endroit=endroit;
    this->dateComp=dateComp;
    this->type_prix=type_prix;
    this->categorie=categorie;

}



bool Competition::ajouter()
{

    QSqlQuery query;
    QString idd= QString::number(idComp);
    QString nbp= QString::number(nbrPar);
    QString gg= QString::number(gagnants);


    //prepare() prend la requete en parametre pour la préparer à l'éxecution
    query.prepare("insert into COMPETITION(idcomp,nbrpar,gagnants,endroit,datecomp,type_prix,categorie)""values(:idcomp,:nbrpar,:gagnants,:endroit,:datecomp,:type_prix,:categorie)");
    //Création des variables liées
    query.bindValue(":idcomp",idd);
    query.bindValue(":nbrpar",nbp);
    query.bindValue(":gagnants",gg);
    query.bindValue(":endroit",endroit);
    query.bindValue(":datecomp",dateComp);
    query.bindValue(":type_prix",type_prix);
    query.bindValue(":categorie",categorie);

    return query.exec(); // exec() envoie la requete pour l'exécuter


}

QSqlQueryModel *Competition::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from competition");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDCOMP"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NBRPAR"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("GAGNANTS"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ENDROIT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATECOMP"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TYPE_PRIX"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("CATEGORIE"));
    return model;



}

bool Competition::supprimer(int id)
{
QSqlQuery query;
QString idcompp=QString:: number(id);
query.prepare("Delete from competition where IDCOMP = :idcomp");
query.bindValue(":idcomp",idcompp);
return query.exec();



}



bool Competition::modifier(int selected){

    QSqlQuery query;


    query.prepare(" UPDATE COMPETITION SET IDCOMP= :idcomp ,NBRPAR= :nbrpar ,GAGNANTS= :gagnants ,ENDROIT= :endroit ,DATECOMP= :datecomp ,TYPE_PRIX= :type_prix ,CATEGORIE= :categorie "
                  " where IDCOMP= :idcomp");
    query.bindValue(":idcomp", selected);
    query.bindValue(":nbrpar", nbrPar);
    query.bindValue(":gagnants", gagnants);
    query.bindValue(":endroit", endroit);
    query.bindValue(":datecomp", dateComp);
    query.bindValue(":type_prix", type_prix);
    query.bindValue(":categorie", categorie);

    return    query.exec();

}

