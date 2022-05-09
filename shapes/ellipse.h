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
    int a; // semi major axis#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"
#include <math.h>

const double PI = 3.14;
class Ellipse:public Shape
{
public:
    Ellipse(double x,double y, double a, double b);
    ~Ellipse() override;
    virtual void draw(QPainter *paint) override;
    virtual void move(double x, double y);
    virtual double perimeter() override;
    virtual double area() override;

    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    double getA() const;
    double getB() const;
    void setA(double a);
    void setB(double b);


private:
    double a; // semi major axis
    double b; // semi minor axis
    double x; //x coordinate
    double y; //y coordinate
};

#endif // ELLIPSE_H

    int b; // semi minor axis

};

#endif // ELLIPSE_H
