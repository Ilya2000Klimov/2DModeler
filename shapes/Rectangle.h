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
    int x, y, width, height;  /*!< coordinates, width and height of rectangle */
public:
    //!A default constructor
    /*!
    A default constructor to initialize the variable
    */
    Rectangle();
    //!An alternate constructor
    /*!
    */
    Rectangle(QPainter* pPainter);
    //!An alternate constructor
    /*!
    x,y value and width and height is passed as parameters for the alternate contructor
    */
    Rectangle(QPainter* pPainter, int x, int y, int width, int height);
    //! A destructor
    /*!
    Rectangle object destroyed
    */
    virtual ~Rectangle();
    //!A mutator function
    /*!
    Sets the y-value as the int value passed in parameter
    */
    void setY(int y);
    //!A mutator function
    /*!
    Sets the x-value as the int value passed in parameter
    */
    void setX(int x);
    //!A mutator function
    /*!
    Sets the height as the int value passed in parameter
    */
    void setHeight(int h);
    //!A mutator function
    /*!
    Sets the width as the int value passed in parameter
    */
    void setWidth(int w);
    //!An accessor function
    /*!
    Returns the height
    */
    int getHeight() const;
    //!An accessor function
    /*!
    Returns the width
    */
    int getWidth() const;
    //!An accessor function
    /*!
    Returns the x-value
    */
    int getX() const;
    //!An accessor function
    /*!
    Returns the y-value
    */
    int getY() const;
    virtual void draw(QPaintDevice* pDevice) const override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
    virtual void operator>>(QTextStream& fileStream) override;
	virtual void setDimensions(int dimensions[],  int dementionsCount) override;
};
}
#endif // RECTANGLE_H
