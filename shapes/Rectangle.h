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
