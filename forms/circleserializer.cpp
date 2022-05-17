#include "circleserializer.h"
#include "ui_circleserializer.h"

CircleSerializer::CircleSerializer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CircleSerializer)
{
    ui->setupUi(this);
}

CircleSerializer::~CircleSerializer()
{
    delete ui;
}
