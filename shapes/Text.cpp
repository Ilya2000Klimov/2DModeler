#include "Text.h"

cs1c::Text::Text() : Shape()
{
    textFormat = QTextOption();
    font = QFont();
    textString = "";
}
cs1c::Text::Text(QPainter* pPainter) : Shape(pPainter)
{
    textFormat = QTextOption();
    font = QFont();
    textString = "";
}
cs1c::Text::Text(QFont font) : Shape()
{
    textFormat = QTextOption();
    font = font;
    textString = "";
}
cs1c::Text::~Text()
{
    
}
void cs1c::Text::setAlignment(QAlignment textAlignment)
{
    textFormat.setAlignment(textAlignment);
}
QAlignment cs1c::Text::getAlignment()
{
    return textFormat.alignment();
}
void cs1c::Text::setFont(QFont font)
{
    this->font = font;
}
QFont cs1c::Text::getFont() const
{
    return font;
}
void cs1c::Text::setText(QString text)
{
    textString = text;
}
QString cs1c::Text::getText() const
{
    return textString;
}
void cs1c::Text::draw() override
{
    // TODO: use consistent names
    pPainter->setFont(font);
    pPainter->setPen(pen)
    pPainter->drawText(textBounds, textString, textFormat);
}

void cs1c::Text::move(int x, int y) override
{
    textBounds.moveTo(x, y);
}
double cs1c::Text::perimeter() override
{
    return 2* (textBounds.width() + textBounds.height());
}
double cs1c::Text::area() override
{
    return textBounds.width() * textBounds.height();
}
