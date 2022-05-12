#include "Polygon.h"
using namespace cs1c

Polygon::Polygon()
{
    count = 0;
    p_point = nullptr;
}
//----------------------------------------------------------------------
Polygon::Polygon(QPoint* p_point, int count)
{
    this->p_point = p_point;
    this->count = count;
}
//----------------------------------------------------------------------
Polygon::~Polygon() {}
//----------------------------------------------------------------------
void Polygon::setPoints(int x, int y)
{
    myPoints.push_back(QPoint(x, y));
    count++;
}
//----------------------------------------------------------------------
QVector<QPoint>& Polygon::getPoints()
{
    return myPoints;
}
//----------------------------------------------------------------------
void Polygon::draw(QPaintDevice *device)
{
    paint = this;
    paint->begin(device);
    paint->setPen(getPen());
    paint->setBrush(getBrush());
    paint->drawPolygon(myPoints.begin(), count);
    paint->end();
}
//----------------------------------------------------------------------
void Polygon::move(int x, int y)
{

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
    while(i < count)
    {
         fileStream << points[i - 1].x() << ", " << points[i - 1].y() << ", ";
         i++;
    }
    fileStream << points[i - 1].x() << ", " << points[i - 1].y();
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
    count = dimensionCount/2;

    for (int i = 0; i < dimensionCount; i += 2)
        {
            setPoints(dimensions[i], dimensions[i+1]);
        }
}
//----------------------------------------------------------------------
