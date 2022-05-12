#include "Square.h"
#include "../file-parsing/ShapeListingSpecification.h"

using namespace cs1c;

Square::Square()
{
    x = 10;
    y = 10;
    width = 100;
}
//----------------------------------------------------------------------
Square::Square(int x, int y, int w)
{
    this->x = x;
    this->y = y;
    width = w;
}
//----------------------------------------------------------------------
Square::~Square() {}
//----------------------------------------------------------------------
void Square::setY(int y)
{
    this->y = y;
}
//----------------------------------------------------------------------
void Square::setX(int x)
{
    this->x = x;
}
//----------------------------------------------------------------------
void Square::setWidth(int w)
{
    width = w;
}
//----------------------------------------------------------------------
int Square::getWidth() const
{
    return width;
}
//----------------------------------------------------------------------
int Square::getX() const
{
    return x;
}
//----------------------------------------------------------------------
int Square::getY() const
{
    return y;
}
//----------------------------------------------------------------------
void Square::draw(QPaintDevice *device)
{
    paint->begin(device);
    paint->setPen(getPen());
    paint->setBrush(getBrush());
    paint->drawRect(x, y, width, width);
    paint->end();
}
//----------------------------------------------------------------------
void Square::move(int x, int y)
{
    int newX = x;
    int newY = y;
    setX(newX);
    setY(newY);
}
//----------------------------------------------------------------------
double Square::perimeter()
{
    return (4*width);
}
//----------------------------------------------------------------------
double Square::area()
{
    return (width * width);
}
//----------------------------------------------------------------------
