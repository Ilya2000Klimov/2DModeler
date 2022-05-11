#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <QtMath>
#include "Shape.h"

class Ellipse : public Shape
{
private:
    int x, y, width, height;

public:
    Ellipse();
    Ellipse(int x, int y, int width, int height);
    virtual ~Ellipse();
    void setX(int x);
    void setY(int y);
    void setWidth(int w);
    void setHeight(int h);
    int getX() const;
    int getY() const;
    int getHeight() const;
    int getWidth() const;
    virtual void draw(QPaintDevice *device) override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
};
#endif // ELLIPSE_H

