#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
private:
    int x, y, width, height;
public:
    Rectangle();
    Rectangle(int x, int y, int width, int height);
    virtual ~Rectangle();
    void setY(int y);
    void setX(int x);
    void setHeight(int h);
    void setWidth(int w);
    int getHeight() const;
    int getWidth() const;
    int getX() const;
    int getY() const;
    virtual void draw(QPainter *paint) override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
};
#endif // RECTANGLE_H
