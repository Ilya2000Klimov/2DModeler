#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include <QPointF>
#include <math.h>
const int DEFAULT_NUM_PTS = 5;
class Polygon:public Shape
{
public:
    Polygon(QPaintDevice* device, int ID =-1);
    ~Polygon() override;
    virtual void draw(QPainter *paint) override;
    virtual void move(int x, int y, int points) const; //might need to change int point
    virtual double perimeter() override;
    virtual double area() override;

    int getPoints(); //function to get the remaining vertices of the polygon
    int setPoints(int remPoints);
private:
    int numOfPoints; // will need to find total polygon points
    const QPointF points[DEFAULT_NUM_PTS];
    double x;
    double y;
    double Xcoord[DEFAULT_NUM_PTS];
    double Ycoord[DEFAULT_NUM_PTS];

};

#endif // POLYGON_H
