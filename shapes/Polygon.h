#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"
#include <QPointF>
#include <iostream>
#include <math.h>

namespace cs1c
{
class Polygon: public Shape
{
public:
    Polygon(int numOfPoints,double x, double y);
    ~Polygon() override;
    virtual void draw(QPaintDevice* pDevice) override;
    virtual void move(int x, int y) override;
    void move(int x, int y, int points);
    virtual double perimeter() override;
    virtual double area() override;

    int getX() const; //function to get the X coord
    int getY() const;
    void setPoints(int Xcoord[],int Ycoord[]);
    int getPoints() const;
    void setPoints(int );
private:
    // Note: Don't place variables in global scope
    static const int DEFAULT_NUM_PTS = 8;
    int numOfPoints; // will need to find total polygon points
    QPointF points[DEFAULT_NUM_PTS];
    double x;
    double y;
    double Xcoord[DEFAULT_NUM_PTS];
    double Ycoord[DEFAULT_NUM_PTS];


};
}

#endif // POLYGON_H
