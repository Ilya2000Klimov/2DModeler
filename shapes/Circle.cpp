#include "Circle.h"
#include "../file-parsing/ShapeListingSpecification.h"

using namespace cs1c;

const double PI = 3.14;

Circle::Circle()
{
    x = 100;
    y = 100;
    radius = 300;
}
//----------------------------------------------------------------------
Circle::Circle(QPainter* pPainter) : Shape(pPainter)
{
    x = 100;
    y = 100;
    radius = 300;
}
//----------------------------------------------------------------------
Circle::Circle(QPainter* pPainter, int x, int y, int radius)
    : Shape(pPainter)
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
void Circle::draw(QPaintDevice *device) const
{
    paint->begin(device);
    paint->setPen(getPen());
    paint->setBrush(getBrush());
    paint->drawEllipse(x, y, radius, radius);
    paint->end();
}
//----------------------------------------------------------------------
void Circle::move(int x, int y)
{
    setX(x);
    setY(y);
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
//ShapeType Circle::type() const
//{
//    return ShapeType::Circle;
//}
//----------------------------------------------------------------------
void cs1c::Circle::operator>>(QTextStream& fileStream)
{
    fileStream << "\nShapeId: " << this->getID()
        << "\nShapeType: Circle"
        << "\nShapeDimensions: " << this->getX() << ", " << this->getY()
            << ", " << this->getRadius()
        << "\nPenColor: " << slp::colorResolver.key(this->getPen().color())
        << "\nPenWidth: " << this->getPen().width()
        << "\nPenStyle: " << slp::penStyleResolver.key(this->getPen().style())
        << "\nPenCapStyle: " << slp::penCapStyleResolver.key(this->getPen().capStyle())
        << "\nPenJoinStyle: " << slp::penJoinStyleResolver.key(this->getPen().joinStyle())
        << "\nBrushColor: " << slp::colorResolver.key(this->getBrush().color())
        << "\nBrushStyle: " << slp::brushStyleResolver.key(this->getBrush().style());
}
//----------------------------------------------------------------------
void cs1c::Circle::setDimensions(int dimensions[], int dimensionCount)
{
    x = dimensions[0];
    y = dimensions[1];
    radius = dimensions[2];
}
//----------------------------------------------------------------------
