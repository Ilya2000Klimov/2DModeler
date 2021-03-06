#include "Line.h"
#include "../file-parsing/ShapeListingSpecification.h"

using namespace cs1c;

Line::Line() : Shape()
{
    x1 = 10;
    y1 = 10;
    x2 = 100;
    y2 = 100;
}
//----------------------------------------------------------------------
Line::Line(QPainter** p_pPainter) : Shape(p_pPainter)
{
    x1 = 10;
    y1 = 10;
    x2 = 100;
    y2 = 100;
}
//----------------------------------------------------------------------
//Line::Line(int, int, int, int) // used for dialog.cpp
//{
//    x1 = 10;
//    y1 = 10;
//    x2 = 100;
//    y2 = 100;
//}
//----------------------------------------------------------------------
Line::Line(QPainter** p_pPainter, int xStart, int yStart, int xEnd, int yEnd) : Shape(p_pPainter)
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
void Line::draw(QPaintDevice *device) const
{
    QPainter* paint = *p_pPaint;
    paint->begin(device);
    paint->setPen(getPen());
    paint->setBrush(getBrush());
    paint->drawLine(x1, y1, x2, y2);
    paint->end();
}
//----------------------------------------------------------------------
void Line::move(int x, int y)
{
    setStartPoint(getStartX()+x,getStartY()+y);

    setEndPoint(getEndX() + x, getEndY() + y);
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
void cs1c::Line::operator>>(QTextStream& fileStream)
{
    fileStream << "\nShapeId: " << this->getID()
        << "\nShapeType: Line"
        << "\nShapeDimensions: " << this->x1 << ", " << this->y1
            << ", " << this->x2 << ", " << this->y2
        << "\nPenColor: " << slp::colorResolver.key(this->getPen().color())
        << "\nPenWidth: " << this->getPen().width()
        << "\nPenStyle: " << slp::penStyleResolver.key(this->getPen().style())
        << "\nPenCapStyle: " << slp::penCapStyleResolver.key(this->getPen().capStyle())
        << "\nPenJoinStyle: " << slp::penJoinStyleResolver.key(this->getPen().joinStyle());
}
//----------------------------------------------------------------------
void cs1c::Line::setDimensions(int dimensions[], int dimensionCount)
{
    x1 = dimensions[0];
    y1 = dimensions[1];
    x2 = dimensions[2];
    y2 = dimensions[3];
}
//----------------------------------------------------------------------
