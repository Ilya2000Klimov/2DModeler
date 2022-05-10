#include "ellipse.h"

Ellipse::Ellipse(double x,double y, double a, double b)
{
    this->x=x;
    this->y=y;
    this->a=a;
    this->b=b;
}
Ellipse::~Ellipse(){}

void Ellipse::setX(double x)
{
    this->x=x;
}

void Ellipse::setY(double y)
{
    this->y=y;
}

double Ellipse::getX( ) const
{
    return x;
}

double Ellipse::getY( ) const
{
    return y;
}

void Ellipse::setA(double a)
{
    this->a=a;
}

void Ellipse::setB(double b)
{
    this->b=b;
}

double Ellipse::getA( ) const
{
    return a;
}

double Ellipse::getB( ) const
{
    return b;
}

void Ellipse::draw(QPainter *paint)
{
    paint->setPen(getPen());
    paint->setBrush(getBrush());
    paint->drawEllipse(x,y,a,b);
}
void Ellipse::move(double x, double y)
{
    double moveX=x;
    double moveY=y;
    setX(moveX);
    setY(moveY);
}
double Ellipse::perimeter()
{
    double perimeter =0.0;
    perimeter=PI*(((3*a)+b)-std::sqrt(((3*a)+b)*(a+(3*b)))); //Ramanujan's formula
    return perimeter;

}
double Ellipse::area()
{
    double area =0.0;
    area=PI*a*b;
    return area;
}
