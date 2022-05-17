#ifndef TEXT_H
#define TEXT_H
#include <QString>
#include <QFont>
#include <QTextOption>
#include <QTextStream>
#include <QPen>
#include "Shape.h"

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
    Text();
    Text(QPainter* pPainter);
    Text(QFont font, QPainter* pPainter);
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
    virtual void draw(QPaintDevice* pDevice) override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
    virtual void operator>>(QTextStream& fileStream) override;
    virtual void setDimensions(int dimensions[], int dementionsCount) override;
};
}
#endif // TEXT_H
