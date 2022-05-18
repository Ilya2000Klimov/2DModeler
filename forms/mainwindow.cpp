#include <QFileDialog>
#include "mainwindow.h"
#include "qevent.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "../file-parsing/parserClass.h"
//#include "shapes/Shape.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      uiLogin(new Login(this)),
      uiCanvas(ui->canvas),
      //pPaint(ui->canvas->pPaint),////dynamic_cast<QPainter*>(uiCanvas)),
      shapeParser(cs1c::ShapeParser(uiCanvas->pPaint)),
      pShapeList(&uiCanvas->vShapeList)
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


void MainWindow::on_actionSave_triggered()
{

}


void MainWindow::on_actionLoad_triggered()
{
    QFileDialog shapeListingDialogue;
    shapeListingDialogue.setNameFilter("*.txt");
    if(shapeListingDialogue.exec())
    {
        *pShapeList = shapeParser.parseShape(shapeListingDialogue.selectedFiles().at(0));
        //uiCanvas->updateGeometry();
    }
}

