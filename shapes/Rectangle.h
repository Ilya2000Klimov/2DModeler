#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle();
    Rectangle(int length, int width);
    virtual ~Rectangle();
    virtual void draw(QPainter *paint) override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
    void setPoints(int w, int l);
    int getPoints() const;
private:
    int length;
    int width;
};
#endif // RECTANGLE_H
