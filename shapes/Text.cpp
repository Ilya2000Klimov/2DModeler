#include "Text.h"

cs1c::Text::Text() : Shape()
{
    font = QFont();
    text = "";
}
cs1c::Text::Text(QPainter* pPainter) : Shape(pPainter)
{
    font = QFont();
    text = "";
}
cs1c::Text::Text(QFont font) : Shape()
{
    font = font;
    text = "";
}
cs1c::Text::~Text()
{
    
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
    this->text = text;
}
QString cs1c::Text::getText() const
{
    return text;
}
void cs1c::Text::draw(QPaintDevice *device) override
{
    
}
void cs1c::Text::move() override
{
    
}
void cs1c::Text::perimeter() override
{
    
}
void cs1c::Text::area() override
{
    
}