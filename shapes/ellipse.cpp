#include "Ellipse.h"
#include "../file-parsing/ShapeListingSpecification.h"

const double PI = 3.14;

Ellipse::Ellipse()
{
    int x = 10;
    int y = 10;
    int height = 100;
    int wieght = 100;
}
//----------------------------------------------------------------------
Ellipse::Ellipse(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height) {}
//----------------------------------------------------------------------
Ellipse::~Ellipse() {}
//----------------------------------------------------------------------
void Ellipse::setX(int x)
{
    this->x = x;
}
//----------------------------------------------------------------------
void Ellipse::setY(int y)
{
    this->y = y;
}
//----------------------------------------------------------------------
void Ellipse::setWidth(int w)
{
    width = w;
}
//----------------------------------------------------------------------
void Ellipse::setHeight(int h)
{
    height = h;
}
//----------------------------------------------------------------------
int Ellipse::getX() const
{
    return x;
}
//----------------------------------------------------------------------
int Ellipse::getY() const
{
    return y;
}
//----------------------------------------------------------------------
int Ellipse::getHeight() const
{
    return height;
}
//----------------------------------------------------------------------
int Ellipse::getWidth() const
{
    return width;
}
//----------------------------------------------------------------------
void Ellipse::draw(QPaintDevice *device)
{
    paint->begin(device);
    paint->setPen(getPen());
    paint->setBrush(getBrush());
    paint->drawEllipse(x, y, width, height);
    paint->end();
}
//----------------------------------------------------------------------
void Ellipse::move(int x, int y)
{
    int newX = x;
    int newY = y;
    setX(newX);
    setY(newY);
}
//----------------------------------------------------------------------
double Ellipse::perimeter()
{
    double halfHeight = height/2; // Half because height represents b-axis
    double halfWidth = width/2; // Half because width represents a-axis
    double heightSqr = halfHeight * halfHeight;
    double widthSqr = halfWidth * halfWidth;

    // Approximation formula for perimeter of an Ellipse
    return (PI*(qSqrt(2*(heightSqr + widthSqr))));
}
//----------------------------------------------------------------------
double Ellipse::area()
{
    // Formula for area of an ellipse using height & width
    return (PI *(width/2) * (height/2));
}
//----------------------------------------------------------------------
