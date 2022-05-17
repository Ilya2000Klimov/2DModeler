#include "Polygon.h"
//#include "../file-parsing/ShapeListingSpecification.h"

using namespace cs1c;

Polygon::Polygon()
{}
//----------------------------------------------------------------------
Polygon::Polygon(QPainter* pPainter) : Shape(pPainter)
{}
//----------------------------------------------------------------------
Polygon::Polygon(QVector<QPoint> vPoints) :vPoints{vPoints}
{}
//----------------------------------------------------------------------
Polygon::~Polygon() {}
//----------------------------------------------------------------------
void Polygon::setPoints(int x, int y)
{
    // Uses vector fucntion push_back to add QPoints to the vector
    vPoints.push_back(QPoint(x, y));
}
//----------------------------------------------------------------------
QVector<QPoint>& Polygon::getPoints()
{
    return vPoints;
}
//----------------------------------------------------------------------
void Polygon::draw(QPaintDevice *device)
{
    //paint = this; // This might be needed for the canvas

    paint->begin(device); // Paint device begins to paint
    paint->setPen(getPen()); // set pen calling shape function
    paint->setBrush(getBrush()); // set brush calling shape function
    // Calling QPainter's drawPolyline function
    paint->drawPolygon(vPoints.begin(), vPoints.size());
    paint->end();// Ends painting
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
void Polygon::setDimensions(int dimensions[], int dimensionCount)
{
    vPoints = QVector<QPoint>();

    for (int i = 0; i < dimensionCount; i += 2)
        {
            setPoints(dimensions[i], dimensions[i+1]);
        }
}
//----------------------------------------------------------------------
