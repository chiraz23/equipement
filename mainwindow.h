#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "competition.h"
#include "equipement.h"
#include "excel.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_ajouterComp_clicked();

    void on_supprimerComp_clicked();

    void on_modifierComp_clicked();

    void on_WeclcomeButton_clicked();

    void on_ajout_clicked();

    void on_annuler_clicked();

    void on_mise_a_jour_clicked();

    void on_pushButton_clicked();

   // void on_pushButton_3_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Competition cmptmp;
    Equipement eq;
};
#endif // MAINWINDOW_H
