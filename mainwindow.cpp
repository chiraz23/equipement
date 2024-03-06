#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipement.h"
#include "competition.h"
#include <QMessageBox>
#include <iostream>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(cmptmp.afficher());
    //*********eq
    ui->tableView_2->setModel(eq.AfficheEq());
}



MainWindow::~MainWindow()
{
    delete ui;
}

//************equipement***************
void MainWindow::on_ajout_clicked()
{
    int id=ui->lineEdit_ID_3->text().toInt();
    QString nom=ui->lineEdit_Nom->text();
    int nb=ui->lineEdit_Nb->text().toInt();
    QString frsr=ui->lineEdit_F->text();
    float dep = ui->lineEdit_Dep->text().toInt();
    QString etat,stat;
    if (ui->radioButton_3->isChecked()) {
            etat = "etat1";
        } else if (ui->radioButton_4->isChecked()) {
            etat = "etat2";
        } else if (ui->radioButton_5->isChecked()) {
            etat = "etat3";
        }
    if (ui->radioButton_1->isChecked()) {
            stat = "dispo";
        } else if (ui->radioButton_2->isChecked()) {
            stat = "occ";
        }


     Equipement E(id,nom,nb,frsr,dep,etat,stat);

    bool test=E.AjoutEq();
    if (test)
    {
        ui->tableView_2->setModel(eq.AfficheEq());
        ui->tableView_2->setModel(E.AfficheEq());
        ui->lineEdit_ID2->clear();
        ui->lineEdit_Nom2->clear();
        ui->lineEdit_Nb2->clear();
        ui->lineEdit_F2->clear();
        ui->lineEdit_Dep2->clear();
        ui->radioButton_3_3->setChecked(false);
        ui->radioButton_4_4->setChecked(false);
        ui->radioButton_5_5->setChecked(false);
        ui->radioButton_1_1->setChecked(false);
        ui->radioButton_2_2->setChecked(false);

        QMessageBox::information(nullptr, QObject::tr("OK"),
                              QObject::tr("Ajout effectué \n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }

    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué. \n "
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_annuler_clicked()
{
    close();
}


void MainWindow::on_mise_a_jour_clicked()
{
    QMessageBox tt;

    // Converting input values appropriately
    int id = ui->lineEdit_ID2->text().toInt();
    QString nom = ui->lineEdit_Nom2->text();
    int nb = ui->lineEdit_Nb2->text().toInt();
    QString frsr = ui->lineEdit_F2->text();
    float dep = ui->lineEdit_Dep2->text().toInt();

    QString etat, stat;

    if (ui->radioButton_3_3->isChecked()) {
        etat = "etat1";
    } else if (ui->radioButton_4_4->isChecked()) {
        etat = "etat2";
    } else if(ui->radioButton_5_5->isChecked()) {
        etat = "etat3";
    }

    if (ui->radioButton_1_1->isChecked()) {
        stat = "dispo";
    } else if(ui->radioButton_2_2->isChecked()) {
        stat = "occ";
    }

    Equipement E(id, nom, nb, frsr, dep, etat, stat);

    if(id != 0 )
    {
        bool test = E.ModifierEq(id);
        QMessageBox mb;
        if(test)
        {
            mb.setText("Modification effectuée");
            ui->tableView_2->setModel(E.AfficheEq());
            ui->lineEdit_ID2->clear();
            ui->lineEdit_Nom2->clear();
            ui->lineEdit_Nb2->clear();
            ui->lineEdit_F2->clear();
            ui->lineEdit_Dep2->clear();
            ui->radioButton_3_3->setChecked(false);
            ui->radioButton_4_4->setChecked(false);
            ui->radioButton_5_5->setChecked(false);
            ui->radioButton_1_1->setChecked(false);
            ui->radioButton_2_2->setChecked(false);
        }
        else
        {
            mb.setText("Modification non effectuée");
            mb.exec();
        }
    }
    else
    {
        tt.setText("Erreur: Veuillez remplir tous les champs correctement.");
        tt.exec();
    }
}

void MainWindow::on_pushButton_clicked()
{
    int id = ui->lineEdit12->text().toInt();
    bool test=eq.SupprimerEq(id);

    if(test)
    {
        ui->tableView_2->setModel(eq.AfficheEq());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée. \n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_20_clicked()
{
    Equipement e;
        int id=ui->lineEdit12_2->text().toInt();
        ui->tableView_2->setModel(e.rechercher(id));
        ui->tableView_2->clearSelection();
}


void MainWindow::on_pushButton_3_clicked()
{
    QString excelEQ = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xlsx)"));
        if (excelEQ .isEmpty())
            return;

        ExportExcelObject obj(excelEQ , "EQUIPEMENT", ui->tableView_3);

        //colums to export
        obj.addField(0, "ID", "number");
        obj.addField(1, "NOM", "varchar(100)");
        obj.addField(2, "NB", "number");
        obj.addField(3, "FRSR", "varchar(100)");
        obj.addField(4, "DEP", "float");
        obj.addField(5, "ETAT", "varchar(100)");
        obj.addField(6, "STAT", "varchar(100)");



        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal)
                                     );
        }

}
















//*************************************************************





void MainWindow::on_ajouterComp_clicked()
{
    int idcmp=ui->lineEditIdComp->text().toInt();
    int nbrp=ui->spinBox->text().toInt();
    int gg=ui->lineEditGagnants->text().toInt();
    QString endroit=ui->lineEditEndroit->text();
    QString dc=ui->dateComp->text();
    QString  cat=ui->lineEditCategorie->text();
    QString typep=ui->lineEditTypePrix->text();

     Competition C(idcmp,nbrp,gg,endroit,dc,cat,typep);

    bool test=C.ajouter();
    if (test)
    {
        ui->tableView->setModel(cmptmp.afficher());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                              QObject::tr("Ajout effectué \n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }

    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué. \n "
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_supprimerComp_clicked()
{
    int id = ui->lineEditSupprimer->text().toInt();
    bool test=cmptmp.supprimer(id);

    if(test)
    {
        ui->tableView->setModel(cmptmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée. \n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_modifierComp_clicked()
{
    QMessageBox tt;
    int idcmp=ui->lineEditIdComp2->text().toInt();
    int nbrp=ui->spinBox_2->text().toInt();
    int gg=ui->lineEditGagnants2->text().toInt();
    QString endroit=ui->lineEditEndroit2->text();
    QString dc=ui->dateComp2->text();
    QString typep=ui->lineEditTypePrix2->text();
    QString  cat=ui->lineEditCategorie2->text();
    Competition C(idcmp,nbrp,gg,endroit,dc,typep,cat);
    if(idcmp!=0 && nbrp!=0 && gg!=0 && endroit!="" && dc!="" && typep!="" && cat!="" )
    {
        bool test=C.modifier(idcmp);
        QMessageBox mb;
        if(test)
        {
            mb.setText("Modification effectuée");
            ui->tableView->setModel(C.afficher());
            ui->lineEditIdComp2->clear();
            ui->spinBox_2->clear();
            ui->lineEditGagnants2->clear();
            ui->lineEditEndroit2->clear();
            ui->dateComp2->clear();
            ui->lineEditCategorie2->clear();
            ui->lineEditTypePrix2->clear();
        }
        else
            mb.setText("Modification non effectuée");
            mb.exec();
    }
    else
    {
        tt.setText("erreur");
        tt.exec();
    }
}





void MainWindow::on_WeclcomeButton_clicked()
{
    ui->tabWidget_2->setCurrentIndex(1);
    ui->tableView->setModel(cmptmp.afficher());
    ui->tableView_2->setModel(eq.AfficheEq());
}








void MainWindow::on_pushButton_16_clicked()
{
    Equipement c;


    bool test=c.tri();
    if (test)
    {
        ui->tableView_2->setModel(eq.tri());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                              QObject::tr("tri effectué \n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }

    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("tri non effectué. \n "
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_25_clicked()
{
    Equipement c;


    bool test=c.trietat();
    if (test)
    {
        ui->tableView_2->setModel(eq.trietat());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                              QObject::tr("tri effectué \n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }

    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("tri non effectué. \n "
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_26_clicked()
{

    Equipement c;


    bool test=c.tridispo();
    if (test)
    {
        ui->tableView_2->setModel(eq.tridispo());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                              QObject::tr("tri effectué \n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }

    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("tri non effectué. \n "
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}
