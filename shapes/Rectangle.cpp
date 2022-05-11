#include "Rectangle.h"

Rectangle::Rectangle()
{
    int x = 10;
    int y = 10;
    int height = 100;
    int wieght = 100;
}
//----------------------------------------------------------------------
Rectangle::Rectangle(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height) {}
//----------------------------------------------------------------------
Rectangle::~Rectangle() {}
//----------------------------------------------------------------------
void Rectangle::setY(int y)
{
    this->y = y;
}
//----------------------------------------------------------------------
void Rectangle::setX(int x)
{
    this->x = x;
}
//----------------------------------------------------------------------
void Rectangle::setHeight(int h)
{
    height = h;
}
//----------------------------------------------------------------------
void Rectangle::setWidth(int w)
{
    width = w;
}
//----------------------------------------------------------------------
int Rectangle::getHeight() const
{
    return height;
}
//----------------------------------------------------------------------
int Rectangle::getWidth() const
{
    return width;
}
//----------------------------------------------------------------------
int Rectangle::getX() const
{
    return x;
}
//----------------------------------------------------------------------
int Rectangle::getY() const
{
    return y;
}
//----------------------------------------------------------------------
void Rectangle::draw(QPaintDevice *device)
{
    paint = this;
    paint->begin(device);
    paint->setPen(getPen());
    paint->setBrush(getBrush());
    paint->drawRect(x, y, width, height);
    paint->end();
}
//----------------------------------------------------------------------
void Rectangle::move(int x, int y)
{
    int newX = x;
    int newY = y;
    setX(newX);
    setY(newY);
}
//----------------------------------------------------------------------
double Rectangle::perimeter()
{
    return (2*(width + height));
}
//----------------------------------------------------------------------
double Rectangle::area()
{
    return (height * width);
}
//----------------------------------------------------------------------
