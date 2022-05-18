#include "Ellipse.h"
#include "../file-parsing/ShapeListingSpecification.h"

using namespace cs1c;

const double PI = 3.14;

Ellipse::Ellipse()
{
    x = 10;
    y = 10;
    height = 100;
    width = 100;
}
//----------------------------------------------------------------------
Ellipse::Ellipse(QPainter** p_pPainter) : Shape(p_pPainter)
{
    x = 10;
    y = 10;
    height = 100;
    width = 100;
}
//----------------------------------------------------------------------
Ellipse::Ellipse(QPainter** p_pPainter, int x, int y, int width, int height)
    : Shape(p_pPainter), x(x), y(y), width(width), height(height)
{}
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
void Ellipse::draw(QPaintDevice *device) const
{
    QPainter* paint = *p_pPaint;
    paint->begin(device);
    paint->setPen(getPen());
    paint->setBrush(getBrush());
    paint->drawEllipse(x, y, width, height);
    paint->end();
}
//----------------------------------------------------------------------
void Ellipse::move(int x, int y)
{
    setX(x);
    setY(y);
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
void cs1c::Ellipse::operator>>(QTextStream& fileStream)
{
    fileStream << "\nShapeId: " << this->getID()
        << "\nShapeType: Ellipse"
        << "\nShapeDimensions: " << this->x << ", " << this->y
            << ", " << this->width << ", " << this->height
        << "\nPenColor: " << slp::colorResolver.key(this->getPen().color())
        << "\nPenWidth: " << this->getPen().width()
        << "\nPenStyle: " << slp::penStyleResolver.key(this->getPen().style())
        << "\nPenCapStyle: " << slp::penCapStyleResolver.key(this->getPen().capStyle())
        << "\nPenJoinStyle: " << slp::penJoinStyleResolver.key(this->getPen().joinStyle())
        << "\nBrushColor: " << slp::colorResolver.key(this->getBrush().color())
        << "\nBrushStyle: " << slp::brushStyleResolver.key(this->getBrush().style());
}
//----------------------------------------------------------------------
void cs1c::Ellipse::setDimensions(int dimensions[], int dimensionCount)
{
    x = dimensions[0];
    y = dimensions[1];
    width = dimensions[2];
    height = dimensions[3];
}
//----------------------------------------------------------------------
