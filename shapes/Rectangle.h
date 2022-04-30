#ifndef LINE_H
#define LINE_H
#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle();
    Rectangle(int length, int width);
    virtual ~Rectangle();
    virtual void draw(QPaintDevice *device) override;
    virtual void move(int x, int y, int points) override;
    virtual void perimeter() override;
    virtual void area() override;
    void setPoints(int w, int l);
    int getPoints() const;
private:
    int length;
    int width;
};
#endif // RECTANGLE_H