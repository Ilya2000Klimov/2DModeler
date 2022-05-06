#include "Circle.h"

const double PI = 3.14;

Circle::Circle()
{
    x = 100;
    y = 100;
    radius = 300;
}
//----------------------------------------------------------------------
Circle::Circle(int x, int y, int radius)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
}
//----------------------------------------------------------------------
Circle::~Circle() {}
//----------------------------------------------------------------------
void Circle::setRadius(int r)
{
    radius = r;
}
//----------------------------------------------------------------------
void Circle::setX(int x)
{
    this->x = x;
}
//----------------------------------------------------------------------
void Circle::setY(int y)
{
    this->y = y;
}
//----------------------------------------------------------------------
int Circle::getRadius() const
{
    return radius;
}
//----------------------------------------------------------------------
int Circle::getX() const
{
    return x;
}
//----------------------------------------------------------------------
int Circle::getY() const
{
    return y;
}
//----------------------------------------------------------------------
void Circle::draw(QPainter *paint)
{
    paint->setPen(getPen());
    paint->setBrush(getBrush());
    paint->drawEllipse(x, y, radius, radius);
}
//----------------------------------------------------------------------
void Circle::move(int x, int y)
{
    int newX = x;
    int newY = y;
    setX(newX);
    setY(newY);
}
//----------------------------------------------------------------------
double Circle::perimeter()
{
    return (2 * PI* radius);
}
//----------------------------------------------------------------------
double Circle::area()
{
    return (PI * (radius * radius));
}
//----------------------------------------------------------------------
