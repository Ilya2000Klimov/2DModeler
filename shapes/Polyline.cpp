#include "Polyline.h"
#include "../file-parsing/ShapeListingSpecification.h"

using namespace cs1c;

Polyline::Polyline(QPainter* pPainter, int ID) : Shape(pPainter)
{
    setID(ID);
}

Polyline::Polyline(int numOfPoints)
{
    this->numOfPoints=numOfPoints;
}

Polyline::~Polyline(){}

void Polyline::draw(QPaintDevice* pDevice)
{
    paint->begin(pDevice);
    paint->setPen(getPen());
    paint->setBrush(getBrush());
    paint->drawPolyline(points, numOfPoints);
    paint->end();
}

void Polyline::move(int x, int y)
{
    QPoint (x,y);
    double moveX=0;
    double moveY=0;
    //difference between the first coordinate and the coordinate we are moving to
    moveX = x-vPoint[0].x();
    moveY=y-vPoint[0].y();

    //setting the new coordinates as that particular point, ie the point has moved
    //int points is the point that is being moved
    for(QPointF& point : arrOfPoints)
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

void Polyline::setPoints(QPoint* remPoints,int numOfPoints)
{
    for(QPointF& point : arrOfPoints)
    {
       vPoint.push_back(point);
    }
}

void cs1c::Polyline::operator>>(QTextStream& fileStream)
{
    fileStream << "\nShapeId: " << this->getID()
        << "\nShapeType: Ellipse"
        << "\nShapeDimensions: ";
    // Repeat for all but last point
    int i = 1;
    while(i < numOfPoints)
    {
         fileStream << points[i - 1].x() << ", " << points[i - 1].y() << ", ";
         i++;
    }
    fileStream << points[i - 1].x() << ", " << points[i - 1].y();
    fileStream << "\nPenColor: " << slp::colorResolver.key(this->getPen().color())
        << "\nPenWidth: " << this->getPen().width()
        << "\nPenStyle: " << slp::penStyleResolver.key(this->getPen().style())
        << "\nPenCapStyle: " << slp::penCapStyleResolver.key(this->getPen().capStyle())
        << "\nPenJoinStyle: " << slp::penJoinStyleResolver.key(this->getPen().joinStyle());
}

void cs1c::Polyline::setDimensions(int dimensions[], int dimensionCount)
{
    points = new QPoint[dimensionCount];
    numOfPoints = dimensionCount;
    for(int i = 0; i < dimensionCount; i += 2)
    {
        points[i].setX(dimensions[i]);
        points[i].setY(dimensions[i + 1]);
    }
}
