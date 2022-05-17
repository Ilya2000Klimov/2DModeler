#ifndef CIRCLESERIALIZER_H
#define CIRCLESERIALIZER_H

#include <QDialog>

namespace Ui {
class CircleSerializer;
}

class CircleSerializer : public QDialog
{
    Q_OBJECT

public:
    explicit CircleSerializer(QWidget *parent = nullptr);
    ~CircleSerializer();

private:
    Ui::CircleSerializer *ui;
};

#endif // CIRCLESERIALIZER_H
