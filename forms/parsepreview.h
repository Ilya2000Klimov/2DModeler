#ifndef PARSEPREVIEW_H
#define PARSEPREVIEW_H

#include <QFileDialog>

namespace Ui {
class ParsePreview;
}

class ParsePreview : public QFileDialog
{


public:
    explicit ParsePreview(QWidget *parent = nullptr);

};

#endif // PARSEPREVIEW_H
