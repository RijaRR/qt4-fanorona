#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scene.h"
#include "dialog.h"
#include "rule.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _scene = new Scene(this);
    ui->graphicsView->setScene(_scene);
    connect(ui->actionNouveau,SIGNAL(triggered()),_scene,SLOT(newGame()));

    Dialog* d= new Dialog(this);
    d->show();



    connect(d,SIGNAL(option(int)),_scene,SLOT(setOption(int)));
    connect(ui->actionRule,SIGNAL(triggered()),this,SLOT(showRule()));
    connect(ui->desacAction,SIGNAL(toggled(bool)),_scene,SLOT(disableToolTip(bool)));
    connect(_scene,SIGNAL(gameWonBy(int)),this,SLOT(gameEnd()));
    connect(ui->actionSwitch,SIGNAL(triggered()),this,SLOT(switchRule()));


}

void MainWindow::showRule()
{
     Rule* r= new Rule(this);
     r->show();
}

void MainWindow::switchRule()
{
    Dialog* d= new Dialog(this);
    d->show();
    connect(d,SIGNAL(option(int)),_scene,SLOT(setOption(int)));
}

void MainWindow::gameEnd()
{

    QMessageBox::information(this, tr("Fin de la partie"),
                                 tr("C'est la fin de la partie, entrer dans option pour jouer de nouveau"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
