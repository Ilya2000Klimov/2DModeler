#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include <QPointF>
#include <iostream>
#include <math.h>
const int DEFAULT_NUM_PTS = 8;
class Polygon:public Shape
{
public:
    Polygon(int numOfPoints,double x, double y);
    ~Polygon() override;
    virtual void draw(QPainter *paint) override;
    virtual void move(double x, double y, int points); 
    virtual double perimeter() override;
    virtual double area() override;

    int getX() const; //function to get the X coord
    int getY() const;
    void setPoints(int Xcoord[],int Ycoord[]);
    int getPoints() const;
    void setPoints(int );
private:
    int numOfPoints; // will need to find total polygon points
    const QPointF points[DEFAULT_NUM_PTS];
    double x;
    double y;
    double Xcoord[DEFAULT_NUM_PTS];
    double Ycoord[DEFAULT_NUM_PTS];


};

#endif // POLYGON_H
