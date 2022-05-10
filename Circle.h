#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class Circle : public Shape
{
private:
    int x, y, radius;

public:
    Circle();
    Circle(int x, int y, int radius);
    virtual ~Circle();
    void setRadius(int r);
    void setX(int x);
    void setY(int y);
    int getRadius() const;
    int getX() const;
    int getY() const;
    virtual void draw(QPaintDevice *device) override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
};
#endif // CIRCLE_H