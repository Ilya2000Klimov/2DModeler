#include "parsepreview.h"
#include "ui_parsepreview.h"

ParsePreview::ParsePreview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParsePreview)
{
    ui->setupUi(this);
}

ParsePreview::~ParsePreview()
{
    delete ui;
}
