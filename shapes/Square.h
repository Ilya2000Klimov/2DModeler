#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"
//!A Square class
/*!
A class header file to construct a square
*/
namespace cs1c
{
class Square : public Shape
{
private:
    int x, y, width; /*!< coordinates, width of square */

public:
    //!A default constructor
    /*!
    A default constructor to initialize the variable
    */
    Square();
    //!An alternate constructor
    /*!
    */
    Square(QPainter* pPainter);
    //!An alternate constructor
    /*!
    x,y value and width is passed as parameters for the alternate contructor
    */
    Square(QPainter* pPainter, int x, int y, int w);
    //!An destructor
    /*!
    */
    virtual ~Square();
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
    Sets the width as the int value passed in parameter
    */
    void setWidth(int w);
    //!An accessor function
    /*!
    Returns the width
    */
    int getWidth() const;
    //!An accessor function
    /*!
    Returns the x coordi
    */
    int getX() const;
    //!An accessor function
    /*!
    Returns the y-coord
    */
    int getY() const;
    virtual void draw(QPaintDevice* pDevice) override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
    virtual void operator>>(QTextStream& fileStream) override;
	virtual void setDimensions(int dimensions[], int dementionsCount) override;
};
}
#endif // SQUARE_H
