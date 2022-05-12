#include "Polygon.h"
#include "../file-parsing/ShapeListingSpecification.h"

using namespace cs1c;

Polygon::Polygon(int numOfPoints,double x, double y)
{
    this->numOfPoints=numOfPoints;
    this->x=x;
    this->y=y;
}

Polygon::~Polygon(){}

void Polygon::setPoints(int Xcoord[],int Ycoord[])
{
    for(int i=0;i<numOfPoints;i++)
    {
        std::cout<<"\nEnter x-coordinate value: ";
        std::cin>>Xcoord[i];
        std::cout<<"\nEnter y-coordinate value: ";
        std::cin>>Ycoord[i];
    }
}

int Polygon::getX() const
{
    for(int index=0;index<numOfPoints;index++)
    {
        return Xcoord[index];
    }
    return 0;
}

int Polygon::getY() const
{
    for(int index=0;index<numOfPoints;index++)
    {
        return Ycoord[index];
    }
    return 0;
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

void Polygon::move(int x, int y, int points)
{
    double moveX=0;
    double moveY=0;
    //difference between the first coordinate and the coordinate we are moving to
    moveX = x-Xcoord[0];
    moveY=y-Ycoord[0];

    //setting the new coordinates as that particular point, ie the point has moved
    //int points is the point that is being moved
    Xcoord[points]+=moveX;
    Ycoord[points]+=moveY;
}

double Polygon::area()
{
    double area=0;

    int xnum;
    int ynum=numOfPoints-1;
    //shoelace method
    for(xnum=0;xnum<numOfPoints;xnum++)
    {
        area=Xcoord[ynum]+Ycoord[xnum] *(Ycoord[ynum]-Xcoord[xnum]);
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
        perimeter+=std::sqrt(pow(Xcoord[i+1]-Xcoord[i],2)+pow(Ycoord[i+1]-Ycoord[i],2));
    }
    //Calculation for the side of the 0th point and the last point
    perimeter+=std::sqrt(pow(Xcoord[numOfPoints-1]-Xcoord[0],2)+pow(Ycoord[numOfPoints-1]-Ycoord[0],2));
return perimeter;
}
