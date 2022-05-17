#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
//!A Rectangle class
/*!
A class header file to construct a rectangle
*/
namespace cs1c
{
class Rectangle : public Shape
{
private:
    int x, y, width, height;
public:
    Rectangle();
    Rectangle(QPainter* pPainter);
    Rectangle(QPainter* pPainter, int x, int y, int width, int height);
    virtual ~Rectangle();
    void setY(int y);
    void setX(int x);
    void setHeight(int h);
    void setWidth(int w);
    int getHeight() const;
    int getWidth() const;
    int getX() const;
    int getY() const;
    virtual void draw(QPaintDevice* pDevice) override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
    virtual void operator>>(QTextStream& fileStream) override;
	virtual void setDimensions(int dimensions[],  int dementionsCount) override;
};
}
#endif // RECTANGLE_H
