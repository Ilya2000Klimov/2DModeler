#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

//!A Circle class
/*!
A class header file to create circle
*/
namespace cs1c
{
class Circle : public Shape
{
private:
    int x, y, radius; /*!< The x, y coordinate and radius of the circle */

public:
    //!A default constructor
    /*!
    A default constructor to initiallize the variables
    */
    Circle();
    //!An alternate constructor
    /*!
    */
    Circle(QPainter* pPainter);
    //!An alternate constructor
    /*!
    x, y corrdinates and the radius are passed as parameters of the constructors
    */
    Circle(QPainter* pPainter, int x, int y, int radius);
    //!A destructor
    /*!
    Circle object is detroyed.
    */
    virtual ~Circle();
    //! A mutator function
    /*!
    Function sets the radius as the integer value passed as parameter
    */
    void setRadius(int r);
    //! A mutator function
    /*!
    Function sets the x - value as the integer value passed as parameter
    */
    void setX(int x);
    //! A mutator function
    /*!
    Function sets the y - value as the integer value passed as parameter
    */
    void setY(int y);
    //! An accessor function
    /*!
    Function gets the radius of the circle
    */
    int getRadius() const;
    //! An accessor function
    /*!
    Function gets the x-value of the circle
    */
    int getX() const;
    //! An accessor function
    /*!
    Function gets the y-value of the circle
    */
    int getY() const;
    //! A draw function
    /*!
    A function to draw the circle
    */
    virtual void draw(QPaintDevice* pDevice) override;
    //! A move function
    /*!
    A function to move the circle
    */
    virtual void move(int x, int y) override;
    //! A perimeter function
    /*!
    A function that returns the perimeter of the circle
    */
    virtual double perimeter() override;
    //! An area function
    /*!
    A function that returns the area of the circle
    */
    virtual double area() override;
    
//    virtual ShapeType type() const override;
    virtual void operator>>(QTextStream& fileStream) override;
    virtual void setDimensions(int dimensions[], int dimensionCount) override;
};
}
#endif // CIRCLE_H
