#include "Rectangle.h"
#include "../file-parsing/ShapeListingSpecification.h"

using namespace cs1c;

Rectangle::Rectangle()
{
    x = 10;
    y = 10;
    height = 100;
    width = 100;
}
//----------------------------------------------------------------------
Rectangle::Rectangle(QPainter* pPainter) : Shape(pPainter)
{
    x = 10;
    y = 10;
    height = 100;
    width = 100;
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
void cs1c::Rectangle::operator>>(QTextStream& fileStream)
{
    fileStream << "\nShapeId: " << this->getID()
        << "\nShapeType: Rectangle"
        << "\nShapeDimensions: " << this->getX() << ", " << this->getY() << ", " << this->getWidth() << ", "  << this->getHeight()
        << "\nPenColor: " << slp::colorResolver.key(this->getPen().color())
        << "\nPenWidth: " << this->getPen().width()
        << "\nPenStyle: " << slp::penStyle.key(this->getPen().Style())
        << "\nPenCapStyle: " << slp::penCapStyle.key(this->getPen().capStyle())
        << "\nPenJoinStyle: " << slp::penJoinStyle.key(this->getPen().joinStyle())
        << "\nBrushColor: " << slp::colorResolver.key(this->getBrush().color())
		<< "\nBrushStyle: " << slp::brushStyleResolver.key(this->getBrush().style());
}

void cs1c::Rectangle::setDimensions(int dimensions[])
{
	for(int i = 0; i < 4; i++)
		x = dimensions[i];
}
