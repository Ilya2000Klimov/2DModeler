#include "Polygon.h"
#include "../file-parsing/ShapeListingSpecification.h"

using namespace cs1c;

Polygon::Polygon()
{}
//----------------------------------------------------------------------
Polygon::Polygon(QPainter* pPainter) : Shape(pPainter)
{}
//----------------------------------------------------------------------
Polygon::Polygon(cs1c::vector<QPoint> vPoints)
    :vPoints{vPoints}
{}
//----------------------------------------------------------------------
Polygon::~Polygon() {}
//----------------------------------------------------------------------
void Polygon::setPoints(int x, int y)
{
    vPoints.push_back(QPoint(x, y));
}
//----------------------------------------------------------------------
cs1c::vector<QPoint>& Polygon::getPoints()
{
    return vPoints;
}
//----------------------------------------------------------------------
void Polygon::draw(QPaintDevice *device)
{
    paint->begin(device);
    paint->setPen(getPen());
    paint->setBrush(getBrush());
    paint->drawPolygon(vPoints.begin(), vPoints.size());
    paint->end();
}
//----------------------------------------------------------------------
void Polygon::move(int x, int y)
{
    for(QPoint& point : vPoints)
    {
        point.rx() += x;
        point.ry() += y;
    }
}
//----------------------------------------------------------------------
double Polygon::perimeter()
{
    return 0;
}
//----------------------------------------------------------------------
double Polygon::area()
{
    return 0;
}
//----------------------------------------------------------------------
void Polygon::operator>>(QTextStream& fileStream)
{
    fileStream << "\nShapeId: " << this->getID()
        << "\nShapeType: Ellipse"
        << "\nShapeDimensions: ";
    // Repeat for all but last point
    int i = 0;
    while(i < vPoints.size())
    {
         fileStream << vPoints[i - 1].x() << ", " << vPoints[i - 1].y() << ", ";
         i++;
    }
    fileStream << vPoints[i - 1].x() << ", " << vPoints[i - 1].y();
    fileStream << "\nPenColor: " << slp::colorResolver.key(this->getPen().color())
        << "\nPenWidth: " << this->getPen().width()
        << "\nPenStyle: " << slp::penStyleResolver.key(this->getPen().style())
        << "\nPenCapStyle: " << slp::penCapStyleResolver.key(this->getPen().capStyle())
        << "\nPenJoinStyle: " << slp::penJoinStyleResolver.key(this->getPen().joinStyle())
        << "\nBrushColor: " << slp::colorResolver.key(this->getBrush().color())
        << "\nBrushStyle: " << slp::brushStyleResolver.key(this->getBrush().style());
}
//----------------------------------------------------------------------
void Polygon::setDimensions(int dimensions[], int dimensionCount)
{
    vPoints = cs1c::vector<QPoint>();
    for (int i = 0; i < dimensionCount; i += 2)
        {
            setPoints(dimensions[i], dimensions[i+1]);
        }
}
//----------------------------------------------------------------------
