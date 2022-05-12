#ifndef TEXT_H
#define TEXT_H
#include <QString>
#include <QFont>
#include <QTextOption>
#include <QTextStream>
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

public:
    Text();
    Text(QPainter* pPainter);
    Text(QFont font);
    virtual ~Text();
    void setAlignment(Qt::Alignment textAlignment);
    Qt::Alignment getAlignment();
    void setFont(QFont font);
    QFont getFont() const;
    void setText(QString textString);
    QString getText() const;
    virtual void draw(QPaintDevice* pDevice) override;
    virtual void move(int x, int y) override;
    virtual double perimeter() override;
    virtual double area() override;
    virtual void operator>>(QTextStream& fileStream) override;
};
}
#endif // TEXT_H
