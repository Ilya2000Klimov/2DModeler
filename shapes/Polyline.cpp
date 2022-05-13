#include "Polyline.h"
#include "../file-parsing/ShapeListingSpecification.h"

using namespace cs1c;

Polyline::Polyline(QPainter* pPainter, int ID) : Shape(pPainter)
{
    setID(ID);
}

Polyline::Polyline(int numOfPoints)
{
    vPoints.resize(numOfPoints);
}

Polyline::~Polyline(){}

void Polyline::draw(QPaintDevice* pDevice)
{
    paint->begin(pDevice);
    paint->setPen(getPen());
    paint->setBrush(getBrush());
    paint->drawPolyline(vPoints.begin(), vPoints.size());
    paint->end();
}

void Polyline::move(int x, int y)
{
    int moveX=0;
    int moveY=0;
    //difference between the first coordinate and the coordinate we are moving to
    moveX = x-vPoints[0].x();
    moveY=y-vPoints[0].y();

    //setting the new coordinates as that particular point, ie the point has moved
    //int points is the point that is being moved
    for(QPoint& point : vPoints)
    {
        point.rx() +=moveX;
        point.ry() +=moveY;
    }
}

double Polyline::area()
{
    return 0;
}
double Polyline::perimeter()
{
    return 0;
}

void Polyline::setPoints(int x, int y)
{
    vPoints.push_back(QPoint(x, y));
}

void cs1c::Polyline::operator>>(QTextStream& fileStream)
{
    fileStream << "\nShapeId: " << this->getID()
        << "\nShapeType: Ellipse"
        << "\nShapeDimensions: ";
    // Repeat for all but last point
    int i = 1;
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
        << "\nPenJoinStyle: " << slp::penJoinStyleResolver.key(this->getPen().joinStyle());
}

void cs1c::Polyline::setDimensions(int dimensions[], int dimensionCount)
{
    vPoints = cs1c::vector<QPoint>();
    for(int i = 0; i < dimensionCount; i += 2)
    {
        setPoints(dimensions[i], dimensions[i + 1]);
    }
}
