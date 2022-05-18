#include "Polyline.h"
#include "../file-parsing/ShapeListingSpecification.h"

using namespace cs1c;

Polyline::Polyline()
{}
//----------------------------------------------------------------------
Polyline::Polyline(QPainter* pPainter) : Shape(pPainter)
{}
//----------------------------------------------------------------------
Polyline::Polyline(QVector<QPoint> vPoints) : vPoints{vPoints}
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
void cs1c::Polyline::operator>>(QTextStream& fileStream)
{
    fileStream << "\nShapeId: " << this->getID()
        << "\nShapeType: Polyline"
        << "\nShapeDimensions: ";
    // Iterate until second-to-last element of vPoints
    for(auto itPoints = vPoints.begin(); itPoints != vPoints.end(); itPoints++)
    {
        fileStream << itPoints->x() << ", " << itPoints->y() << ", ";
    }
    // for last element in vPoints
    fileStream << vPoints.last().x() << ", " << vPoints.last().y()
        << "\nPenColor: " << slp::colorResolver.key(this->getPen().color())
        << "\nPenWidth: " << this->getPen().width()
        << "\nPenStyle: " << slp::penStyleResolver.key(this->getPen().style())
        << "\nPenCapStyle: " << slp::penCapStyleResolver.key(this->getPen().capStyle())
        << "\nPenJoinStyle: " << slp::penJoinStyleResolver.key(this->getPen().joinStyle());
}
//----------------------------------------------------------------------
void Polyline::setDimensions(int dimensions[], int dimensionCount)
{
    vPoints = QVector<QPoint>();

    for (int i = 0; i < dimensionCount; i += 2)
        {
            setPoints(dimensions[i], dimensions[i+1]);
        }
}
//----------------------------------------------------------------------
void Polyline::draw(QPaintDevice *device) const
{
    //paint = this; // This might be needed for the canvas

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
