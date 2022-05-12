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
void Circle::draw(QPaintDevice *device)
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
//----------------------------------------------------------------------
void cs1c::Circle::operator>>(QTextStream& fileStream)
{
    fileStream << "\nShapeId: " << this->getID()
        << "\nShapeType: Circle"
        << "\nShapeDimensions: " << this->textBounds.x() << ", " << this->textBounds.y()
            << ", " << this->textBounds.height() << ", " << this->textBounds.width()
        << "\nTextString: " << this->textString
        << "\nTextColor: blue" << slp::colorResolver.key(this->getPen().color())
        << "\nTextAlignment: " << slp::alignmentFlagResolver.key(this->textFormat.alignment())
        << "\nTextPointSize: " << this->font.pointSize()
        << "\nTextFontFamily: " << this->font.family()
        << "\nTextFontStyle: " << slp::fontStyleResolver.key(this->font.style())
        << "\nTextFontWeight: " << slp::fontWeightResolver.key(this->font.weight());
}
