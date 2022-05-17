#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), vShapeList(cs1c::vector<cs1c::Shape*>())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::login_clicked()
{
    auto* login = new Login(this);
    login->show();
}

void MainWindow::on_actionAdd_Line_triggered()
{
    Dialog myDialog;
    myDialog.setModal(true);
    myDialog.exec();
}

