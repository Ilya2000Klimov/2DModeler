#ifndef PENANDBRUSHSERIALIZER_H
#define PENANDBRUSHSERIALIZER_H

#include <QDialog>

namespace Ui {
class PenAndBrushSerializer;
}

class PenAndBrushSerializer : public QDialog
{
    Q_OBJECT

public:
    explicit PenAndBrushSerializer(QWidget *parent = nullptr);
    ~PenAndBrushSerializer();

private:
    Ui::PenAndBrushSerializer *ui;
};

#endif // PENANDBRUSHSERIALIZER_H
