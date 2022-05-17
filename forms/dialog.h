#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "shapes/Shape.h"

namespace Ui {
class ShapeDialog;
}

class ShapeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShapeDialog(QWidget *parent = nullptr);
    ~ShapeDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ShapeDialog *ui;
};

#endif // DIALOG_H
