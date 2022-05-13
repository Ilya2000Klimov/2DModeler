#include "Polyline.h"
//#include "../file-parsing/ShapeListingSpecification.h"

using namespace cs1c;

Polyline::Polyline()
{}
//----------------------------------------------------------------------
Polyline::Polyline(QPainter* pPainter) : Shape(pPainter)
{}
//----------------------------------------------------------------------
Polyline::Polyline(cs1c::vector<QPoint> vPoints) : vPoints{vPoints}
{}
//----------------------------------------------------------------------
Polyline::~Polyline() {}
//----------------------------------------------------------------------
void Polyline::setPoints(int x, int y)
{
    // Uses vector fucntion push_back to add QPoints to the vector
    vPoints.push_back(QPoint(x, y));
}
//----------------------------------------------------------------------
QVector<QPoint>& Polyline::getPoints()
{
    return vPoints;
}
//----------------------------------------------------------------------
void Polyline::setDimensions(int dimensions[], int dimensionCount)
{
    int count = dimensionCount/2;

    for (int i = 0; i < dimensionCount; i += 2)
        {
            setPoints(dimensions[i], dimensions[i+1]);
        }
}
//----------------------------------------------------------------------
void Polyline::draw(QPaintDevice *device)
{
    paint = this;
    paint->begin(device); // Paint device begins to paint
    paint->setPen(getPen()); // set pen calling shape function
    paint->setBrush(getBrush()); // set brush calling shape function
    // Calling QPainter's drawPolyline function
    paint->drawPolyline(vPoints.begin(), vPoints.size());
    paint->end(); // Ends painting
}
//----------------------------------------------------------------------
void Polyline::move(int x, int y)
{
    for(QPoint& point : vPoints)
        {
            point.rx() += x;
            point.ry() += y;
        }
}
//----------------------------------------------------------------------
double Polyline::perimeter()
{
    return 0; // Polyline does not have perimeter
}
//----------------------------------------------------------------------
double Polyline::area()
{
    return 0; // Polyline does not have area
}
//----------------------------------------------------------------------
