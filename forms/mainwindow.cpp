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
      //uiCanvas(ui->canvas),
      //p_pPaint(ui->canvas->pPaint),////dynamic_cast<QPainter*>(uiCanvas)),
      // Pass address of changing QPainter* from Canvas to all parsed objects

      pShapeList(&ui->canvas->vShapeList)
{
    ui->setupUi(this);

    shapeParser = new cs1c::ShapeParser(&(ui->canvas->pPaint));
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
    p_pPaint = &ui->canvas->pPaint;
ui->canvas->vShapeList.push_back(new cs1c::Rectangle(p_pPaint));
ui->canvas->updateGeometry();
}


void MainWindow::on_actionLoad_triggered()
{
    QFileDialog shapeListingDialogue;
    shapeListingDialogue.setNameFilter("*.txt");
    if(shapeListingDialogue.exec())
    {
        //*pShapeList == ui->canvas->vShapeList
        ui->canvas->vShapeList = shapeParser->parseShape(QString(shapeListingDialogue.selectedFiles().at(0)));
        //uiCanvas
        ui->canvas->updateGeometry();
    }
}

