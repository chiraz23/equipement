#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Competition
{
    private:
    int idComp,nbrPar,gagnants;
    QString endroit,dateComp,type_prix,categorie;
public:
// Constructeurs
    Competition(){};
    Competition(int,int,int,QString,QString,QString,QString);

    //getters
    int get_IdComp(){return idComp;}
    int get_NbrPar(){return nbrPar;}
    int get_Gagnants(){return gagnants;}
    QString get_Endroit(){return endroit;}
    QString get_DateComp(){return dateComp;}
    QString get_TypePrix(){return type_prix;}
    QString get_Categorie(){return categorie;}



    //setters
    void setIdComp(int n);
    void setNbrPar(int n1);
    void setGagnants(int n2);
    void setEndroit(QString n3);
    void setDateComp(QString n4);
    void setTypePrix(QString n5);
    void setCategorie(QString n6);


    // CRUD competition
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);


};



#endif // CLIENT_H
