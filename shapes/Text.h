#ifndef TEXT_H
#define TEXT_H
#include <QFont>
#include "shape.h"

namespace cs1c
{
class Text : public Shape
{
private:
    QFont font;
    QString text;
    
public:
    Text();
    Text(QFont font);
    virtual ~Text();
    void setFont();
    QFont getFont() const;
    void setText();
    QString getText() const;
    virtual void draw(QPaintDevice *device) override;
    virtual void move() override;
    virtual void perimeter() override;
    virtual void area() override;
};
}
#endif // TEXT_H
