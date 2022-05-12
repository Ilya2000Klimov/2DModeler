#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"

namespace cs1c
{
class Square : public Shape
{
private:
    int x, y, width;

public:
    Square();
    Square(QPainter* pPainter);
    Square(int x, int y, int w);
    virtual ~Square();
    void setY(int y);
    void setX(int x);
    void setWidth(int w);
    int getWidth() const;
    int getX() const;
    int getY() const;
    virtual void draw(QPaintDevice* pDevice) override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
    virtual void operator>>(QTextStream& fileStream) override;
	virtual void setDimensions(int dimensions[]) override;
};
}
#endif // SQUARE_H
