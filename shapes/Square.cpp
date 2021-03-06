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
Square::Square(QPainter** p_pPainter) : Shape(p_pPainter)
{
    x = 10;
    y = 10;
    width = 100;
}
//---------------------------------------------------------------
Square::Square(QPainter** p_pPainter, int x, int y, int w)
    : Shape(p_pPainter)
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
void Square::draw(QPaintDevice *device) const
{
    QPainter* paint = *p_pPaint;
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
void cs1c::Square::operator>>(QTextStream& fileStream)
{
    fileStream << "\nShapeId: " << this->getID()
        << "\nShapeType: Square"
        << "\nShapeDimensions: " << this->getX() << ", " << this->getY() << ", " <<this->getWidth()
        << "\nPenColor: " << slp::colorResolver.key(this->getPen().color())
        << "\nPenWidth: " << this->getPen().width()
        << "\nPenStyle: " << slp::penStyleResolver.key(this->getPen().style())
        << "\nPenCapStyle: " << slp::penCapStyleResolver.key(this->getPen().capStyle())
        << "\nPenJoinStyle: " << slp::penJoinStyleResolver.key(this->getPen().joinStyle())
        << "\nBrushColor: " << slp::colorResolver.key(this->getBrush().color())
		<< "\nBrushStyle: " << slp::brushStyleResolver.key(this->getBrush().style());
}

void cs1c::Square::setDimensions(int dimensions[], int dimensionsCount)
{
	x = dimensions[0];
	y = dimensions[1];
	width = dimensions[2];
}
