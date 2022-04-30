#ifndef POLYLINE_H
#define POLYLINE_H
#include "shape.h"
class Polyline:public Shape
{
public:
    Polyline(QPaintDevice* device, int ID =-1);
    ~Polyline() override;
    virtual void draw(QPaintDevice *device) override;
    virtual void move(int x, int y, int points) const; //might need to change int point
    virtual void perimeter() override; //area and perimeter probably do not apply in this case
    virtual void area() override;

    int getPoints(); //function to get the remaining points of the polyline
    int setPoints(int remPoints);
private:
    int numOfPoints; // will need to find total polyline points

};
#endif // POLYLINE_H
