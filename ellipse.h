#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"
class Ellipse:public Shape
{
public:
    Ellipse(QPaintDevice* device, int ID =-1);
    ~Ellipse() override;
    virtual void draw(QPaintDevice *device) override;
    virtual void move(int x, int y) const; //might need to include more functions for the ellipse to be moved
    virtual void perimeter() override;
    virtual void area() override;


private:
    int a; // semi major axis
    int b; // semi minor axis

};

#endif // ELLIPSE_H
