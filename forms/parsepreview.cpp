#include "parsepreview.h"
#include "ui_parsepreview.h"

ParsePreview::ParsePreview(QWidget *parent) :
    QFileDialog(parent)
{
    this->setNameFilter(".txt");
}
