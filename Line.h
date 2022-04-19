#ifndef LINE_H
#define LINE_H
#include "shape.h"

class Line : public Shape
{
private:
    QPoint start;
    QPoint end;
public:
    Line();
    Line(QPoint start, QPoint end);
    virtual ~Line();
    void setPoints(QPoint start, QPoint end);
    void getPoints() const;
    virtual void draw(QPaintDevice *device) override;
    virtual void move(int x, int y, int points ) const override;
    virtual void perimeter() override;
    virtual void area() override;
};
#endif // LINE_H
