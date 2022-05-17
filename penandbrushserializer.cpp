#include "penandbrushserializer.h"
#include "ui_penandbrushserializer.h"

PenAndBrushSerializer::PenAndBrushSerializer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PenAndBrushSerializer)
{
    ui->setupUi(this);
}

PenAndBrushSerializer::~PenAndBrushSerializer()
{
    delete ui;
}
