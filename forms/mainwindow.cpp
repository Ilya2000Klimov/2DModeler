#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      uiLogin(new Login(this)), uiCanvas(ui->canvas), vShapeList(cs1c::vector<cs1c::Shape*>())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_Line_triggered()
{
    ShapeDialog myDialog;
    myDialog.setModal(true);
    myDialog.exec();
}

void MainWindow::on_actionAdd_Polyline_triggered()
{
    ShapeDialog myDialog1;
    myDialog1.setModal(true);
    myDialog1.exec();
}


void MainWindow::on_actionLogin_triggered()
{
    uiLogin->show();
}

