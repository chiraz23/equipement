#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Equipement
{
private:
    QString frsr,nom,etat,stat;
    int id,nb;
    int dep;
public:

    Equipement(){};
    Equipement(int,QString,int,QString,int,QString,QString);

    //getters
    int GetId(){return id;}
    QString GetNom(){return nom;}
    int GetNb(){return nb;}
    QString GetFrsr(){return frsr;}
    float GetDep(){return dep;}
    QString GetStat() const{return stat;}
    QString GetEtat() const{return etat;};

   //setters
    void SetId(int a);
    void SetNom(QString b);
    void SetNb(int c);
    void SetFrsr(QString e);
    void SetDep(int f);
    void SetStat(QString g);
    void setEtat(QString h);

    //CRUD
    bool AjoutEq();
    QSqlQueryModel * AfficheEq();
    bool SupprimerEq(int);
    bool ModifierEq(int);
    QSqlQueryModel * tri();
    QSqlQueryModel * trietat();
    QSqlQueryModel * tridispo();
    QSqlQueryModel * rechercher(int);



};

#endif // EQUIPEMENT_H
