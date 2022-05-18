#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <QtMath>
#include "Shape.h"

//!An Ellipse class
/*!
A class header file to create an ellipse
*/
namespace cs1c
{
class Ellipse : public Shape
{
private:
    int x, y, width, height; /*!< The x,y coordinate value and width and height of the ellipse*/

public:
    //!A default constructor
    /*!
    A default constructor to initialize the variable
    */
    Ellipse();
    //!An altenate constructor
    /*!
    */
    Ellipse(QPainter** p_pPainter);
    //!An alternate constructor
    /*!
    x,y value and width and height is passed as parameters for the alternate contructor
    */
    Ellipse(QPainter** p_pPainter, int x, int y, int width, int height);
    //! A destructor
    /*!
    Ellipse object destroyed
    */
    virtual ~Ellipse();
    //!A mutator function
    /*!
    Sets the x-value as the int value passed in parameter
    */
    void setX(int x);
    //!A mutator function
    /*!
    Sets the y-value as the int value passed in parameter
    */
    void setY(int y);
    //!A mutator function
    /*!
    Sets the width of the ellipse as the int value passed in parameter
    */
    void setWidth(int w);
    //!A mutator function
    /*!
    Sets the height as the int value passed in parameter
    */
    void setHeight(int h);
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
    //!A draw function
    /*!
    Function to draw the ellipse
    */
    virtual void draw(QPaintDevice* pDevice) const override;
    //!A move function
    /*!
    Function to move the ellipse
    */
    virtual void move(int x, int y) override;
    //!A perimeter function
    /*!
    Returns the calculated perimeter of the ellipse
    */
    virtual double perimeter() override;
    //!An area function
    /*!
    Returns the area of the ellipse
    */
    virtual double area() override;
    virtual void operator>>(QTextStream& fileStream) override;
    virtual void setDimensions(int dimensions[], int dimensionCount) override;
};
}
#endif // ELLIPSE_H

