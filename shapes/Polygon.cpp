#include "Polygon.h"
#include "../file-parsing/ShapeListingSpecification.h"

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
void Polygon::draw(QPaintDevice *device) const
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
void cs1c::Polygon::operator>>(QTextStream& fileStream)
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
        << "\nPenJoinStyle: " << slp::penJoinStyleResolver.key(this->getPen().joinStyle())
        << "\nBrushColor: " << slp::colorResolver.key(this->getBrush().color())
        << "\nBrushStyle: " << slp::brushStyleResolver.key(this->getBrush().style());
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
