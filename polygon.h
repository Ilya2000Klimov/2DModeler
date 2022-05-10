#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"

class Polygon:public Shape
{
public:
    Polygon(QPaintDevice* device, int ID =-1);
    ~Polygon() override;
    virtual void draw(QPaintDevice *device) override;
    virtual void move(int x, int y, int points) const; //might need to change int point
    virtual void perimeter() override;
    virtual void area() override;

    int getPoints(); //function to get the remaining vertices of the polygon
    int setPoints(int remPoints);
private:
    int numOfPoints; // will need to find total polygon points

};

#endif // POLYGON_H
