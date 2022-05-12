#include "Line.h"
#include "../file-parsing/ShapeListingSpecification.h"

Line::Line() : Shape()
{
    int x1 = 10;
    int y1 = 10;
    int x2 = 100;
    int y2 = 100;
}
//----------------------------------------------------------------------
Line::Line(int xStart, int yStart, int xEnd, int yEnd) : Shape()
{
    x1 = xStart;
    y1 = yStart;
    x2 = xEnd;
    y2 = yEnd;
}
//----------------------------------------------------------------------
Line::~Line() {}
//----------------------------------------------------------------------
void Line::setStartPoint(int x, int y)
{
    x1 = x;
    y1 = y;
}
//----------------------------------------------------------------------
void Line::setEndPoint(int x, int y)
{
    x2 = x;
    y2 = y;
}
//----------------------------------------------------------------------
int Line::getStartX() const
{
    return x1;
}
//----------------------------------------------------------------------
int Line::getStartY() const
{
    return y1;
}
//----------------------------------------------------------------------
int Line::getEndX() const
{
    return x2;
}
//----------------------------------------------------------------------
int Line::getEndY() const
{
    return y2;
}
//----------------------------------------------------------------------
void Line::draw(QPaintDevice *device)
{
    paint->begin(device);
    paint->setPen(getPen());
    paint->setBrush(getBrush());
    paint->drawLine(x1, y1, x2, y2);
    paint->end();
}
//----------------------------------------------------------------------
void Line::move(int x, int y)
{
    setStartPoint(x,y);

    int newEndX = x2 + x;
    int newEndY = y2 + y;

    setEndPoint(newEndX, newEndY);
}
//----------------------------------------------------------------------
double Line::perimeter()
{
    return 0; // There is no perimeter for a line
}
//----------------------------------------------------------------------
double Line::area()
{
    return 0; // There is no area for a line
}
//----------------------------------------------------------------------
