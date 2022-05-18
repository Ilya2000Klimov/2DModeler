#ifndef TEXT_H
#define TEXT_H
#include <QString>
#include <QFont>
#include <QTextOption>
#include <QTextStream>
#include <QPen>
#include "Shape.h"
//!A Text class
/*!
A class header file to create Text
*/
namespace cs1c
{
class Text : public Shape
{
private:
    QRect textBounds;
    QTextOption textFormat;
    QFont font;
    QString textString;
    QPen penColor;

public:
    //!A default constructor
    /*!
    A default constructor to initialize the variable
    */
    Text();
    //!An alternate constructor
    /*!
    */
    Text(QPainter* pPainter);
    Text(QPainter* pPainter, QFont font);
    virtual ~Text();
    void setAlignment(Qt::Alignment textAlignment);
    Qt::Alignment getAlignment();
    void setRect(int x, int y, int h, int w);
    QRect getRect() const;
    void setFont(QFont font);
    QFont getFont() const;
    void setText(QString textString);
    QString getText() const;
    void setTextPointSize(int size);
    void setTextFontFamily(QString font);
    void setTextFontStyle(QString fontStyle);
    void setTextFontWeight(QString weight);
    void setColor(QString c);
    virtual void draw(QPaintDevice* pDevice) const override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
    virtual void operator>>(QTextStream& fileStream) override;
    virtual void setDimensions(int dimensions[], int dementionsCount) override;
};
}
#endif // TEXT_H
