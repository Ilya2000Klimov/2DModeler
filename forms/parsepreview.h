#ifndef PARSEPREVIEW_H
#define PARSEPREVIEW_H

#include <QWidget>

namespace Ui {
class ParsePreview;
}

class ParsePreview : public QWidget
{
    Q_OBJECT

public:
    explicit ParsePreview(QWidget *parent = nullptr);
    ~ParsePreview();

private:
    Ui::ParsePreview *ui;
};

#endif // PARSEPREVIEW_H
