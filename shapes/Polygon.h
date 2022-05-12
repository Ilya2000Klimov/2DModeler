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
    Polygon(QPainter* pPainter);
    Polygon(int numOfPoints,int x, int y);
    ~Polygon() override;
    virtual void draw(QPaintDevice* pDevice) override;
    virtual void move(int x, int y) override;
    void move(int x, int y, int points);
    virtual double perimeter() override;
    virtual double area() override;
    virtual void operator>>(QTextStream& fileStream) override;
    virtual void setDimensions(int dimensions[], int dimensionCount) override;

    int getX() const; //function to get the X coord
    int getY() const;
    void setPoints();
    int getPoints() const;
    void setPoints(int );
    void setX(int x);
    void setY(int y);
private:
    // Note: Don't place variables in global scope
    static const int DEFAULT_NUM_PTS = 8;
    int numOfPoints; // variable to find total number of points in the polygon
    std::vector<QPointF> vPoint; //vector to store the points of the polygon in
    QPoint* points;// Used b/c QPainter drawPoly is QPoint*
    double x;
    double y;
    double Xcoord[DEFAULT_NUM_PTS];
    double Ycoord[DEFAULT_NUM_PTS];

};
}

#endif // POLYGON_H
