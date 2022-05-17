#include "serializepreview.h"
#include "ui_serializepreview.h"
#include <algorithm>
#include "../shapes/Shape.h"

SerializePreview::SerializePreview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerializePreview)
{
    ui->setupUi(this);
}

SerializePreview::~SerializePreview()
{
    delete ui;
}

void SerializePreview::on_buttonBox_accepted()
{

}


void SerializePreview::on_buttonBox_rejected()
{
    this->hide();
}

// Sorting selection
void SerializePreview::on_comboBox_activated(int index)
{

    QTextStream();
    switch(index)
    {
    // sort by ID
    case 0:

        break;
        // sort by PERIMETER
    case 1:
        break;
        // sort by AREA
    case 2:
        break;
    default: ;
        // something went wrong
    }
}

