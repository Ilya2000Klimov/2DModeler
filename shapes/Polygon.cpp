#include "Polygon.h"
#include "../file-parsing/ShapeListingSpecification.h"

using namespace cs1c;

Polygon::Polygon(QPainter* pPainter) : Shape(pPainter)
{
    this->numOfPoints= 0;
    this->x=0;
    this->y=0;
}

Polygon::Polygon(int numOfPoints,int x, int y)
{
    this->numOfPoints=numOfPoints;
    this->x=x;
    this->y=y;
}

Polygon::~Polygon(){}

void Polygon::setPoints()
{
   /* for(int i=0;i<numOfPoints;i++)
    {
        std::cout<<"\nEnter x-coordinate value: ";
        std::cin>>Xcoord[i];
        std::cout<<"\nEnter y-coordinate value: ";
        std::cin>>Ycoord[i];
    }*/
    for(QPointF& point : points)
    {
       vPoint.push_back(point);
    }
}

void Polygon::setX(int x)
{
    this->x=x;
}

void Polygon::setY(int y)
{
    this->y=y;
}

int Polygon::getX() const
{
   /* for(int index=0;index<numOfPoints;index++)
    {
        return Xcoord[index];
    }
    return 0;*/
    return x;
}

int Polygon::getY() const
{
   /* for(int index=0;index<numOfPoints;index++)
    {
        return Ycoord[index];
    }
    return 0;*/
    return y;
}

void Polygon::setPoints(int numOfPoints)
{
    this->numOfPoints=numOfPoints;
}

int Polygon::getPoints() const
{
    return numOfPoints;
}

void Polygon::draw(QPaintDevice* pDevice)
{
    paint->begin(pDevice);
    paint->setPen(getPen());
    paint->setBrush(getBrush());
    paint->drawPolygon(points,numOfPoints);
    paint->end();
}

void Polygon::move(int x, int y)
{
   /* double moveX=0;
    double moveY=0;
    //difference between the first coordinate and the coordinate we are moving to
    moveX = x-Xcoord[0];
    moveY=y-Ycoord[0];

    //setting the new coordinates as that particular point, ie the point has moved
    //int points is the point that is being moved
    Xcoord[points]+=moveX;
    Ycoord[points]+=moveY;*/

    double moveX=0;
    double moveY=0;
    //difference between the first coordinate and the coordinate we are moving to
    moveX = x-Xcoord[0];
    moveY=y-Ycoord[0];

    //setting the new coordinates as that particular point, ie the point has moved
    //int points is the point that is being moved
    for(QPointF& point : points)
    {
        point.rx() +=moveX;
        point.ry() +=moveY;
    }
}

double Polygon::area()
{
    double area=0;


    int xnum;
    int ynum=numOfPoints-1;
    //shoelace method
    for(xnum=0;xnum<numOfPoints;xnum++)
    {
        //area=Xcoord[ynum]+Ycoord[xnum] *(Ycoord[ynum]-Xcoord[xnum]); //formula for area of a polygon
        area=vPoint[ynum].x()+vPoint[xnum].y() *(vPoint[ynum].y()-vPoint[xnum].x());
        ynum=xnum;
    }
    area = abs(area/2);
    return area;
}
double Polygon::perimeter()
{
    double perimeter=0;

    for(int i=0;i<numOfPoints;i++)
    {
        //perimeter+=std::sqrt(pow(Xcoord[i+1]-Xcoord[i],2)+pow(Ycoord[i+1]-Ycoord[i],2));
        perimeter+=std::sqrt(pow(vPoint[i+1].x()-vPoint[i].x(),2)+pow(vPoint[i+1].y()-vPoint[i].y(),2));
    }
    //Calculation for the side of the 0th point and the last point
    //perimeter+=std::sqrt(pow(Xcoord[numOfPoints-1]-Xcoord[0],2)+pow(Ycoord[numOfPoints-1]-Ycoord[0],2));
     perimeter+=std::sqrt(pow(vPoint[numOfPoints-1].x()-vPoint[0].x(),2)+pow(vPoint[numOfPoints-1].y()-vPoint[0].y(),2));
return perimeter;
}
