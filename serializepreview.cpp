#include "serializepreview.h"
#include "ui_serializepreview.h"

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
