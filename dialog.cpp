#include "dialog.h"
#include "ui_dialog.h"
#include <QInputDialog>
#include "shapes/Shape.h"
#include "shapes/Line.h"


ShapeDialog::ShapeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShapeDialog)
{
    ui->setupUi(this);
    ui->label1->setText("");
    ui->label2->setText("");
    ui->label3->setText("");
    ui->label4->setText("");
}

ShapeDialog::~ShapeDialog()
{
    delete ui;
}

void ShapeDialog::on_pushButton_clicked()
{
    int x1 = QInputDialog::getInt(this, "x1", "Enter x1");
    ui->label1->setText(QString::number(x1));

    int y1 = QInputDialog::getInt(this, "y1", "Enter y1");
    ui->label2->setText(QString::number(y1));

    int x2 = QInputDialog::getInt(this, "x2", "Enter x2");
    ui->label3->setText(QString::number(x2));

    int y2 = QInputDialog::getInt(this, "y2", "Enter y2");
    ui->label4->setText(QString::number(y2));

    //Shape *dialogLine = new Line (x1, y1, x2, y2); // causes error

}

