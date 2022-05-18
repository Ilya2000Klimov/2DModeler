#include "Text.h"
#include "../file-parsing/ShapeListingSpecification.h"

using namespace cs1c;

Text::Text() : Shape() // Default constructor
{
    textFormat = QTextOption();
    font = QFont();
    textString = "";
    penColor = Qt::SolidLine; // penColor default
}
//----------------------------------------------------------------------
Text::Text(QPainter** p_pPainter) : Shape(p_pPainter)
{
    textFormat = QTextOption();
    font = QFont();
    textString = "";
    penColor = Qt::SolidLine; // penColor default
}
//----------------------------------------------------------------------
Text::Text(QPainter** p_pPainter, QFont font) : Shape(p_pPainter)
{
    textFormat = QTextOption();
    this->font = font;
    textString = "";
    penColor = Qt::SolidLine; // penColor default
}
//----------------------------------------------------------------------
Text::~Text() {}
//----------------------------------------------------------------------
void Text::setAlignment(Qt::Alignment textAlignment) // Align test on canvas
{
    textFormat.setAlignment(textAlignment);
}
//----------------------------------------------------------------------
Qt::Alignment Text::getAlignment()
{
    return textFormat.alignment(); // Return Akignment
}
//----------------------------------------------------------------------
void Text::setRect(int x, int y, int h, int w) // set rectangle for text bounds
{
    // Parameters for a rectangle
    textBounds.setX(x);
    textBounds.setY(y);
    textBounds.setHeight(h);
    textBounds.setWidth(w);
}
//----------------------------------------------------------------------
QRect Text::getRect() const
{
    return textBounds; // return QRect
}
//----------------------------------------------------------------------
void Text::setFont(QFont font)
{
    this->font = font;
}
//----------------------------------------------------------------------
QFont Text::getFont() const
{
    return font;
}
//----------------------------------------------------------------------
void Text::setText(QString text)
{
    textString = text;
}
//----------------------------------------------------------------------
QString Text::getText() const
{
    return textString;
}
//----------------------------------------------------------------------
void Text::setTextPointSize(int size) // set text size
{
    font.setPointSize(size);
}
//----------------------------------------------------------------------
void Text::setTextFontFamily(QString fontFamily) // set font style
{
    if(fontFamily == "Comic Sans MS")
    {
        font.setFamily("Comic Sans MS");
    }
    else if(fontFamily == "AnyStyle")
    {
        font.setStyleHint(QFont::AnyStyle);
    }
    else if(fontFamily == "SansSerif")
    {
        font.setStyleHint(QFont::SansSerif);
    }
    else if(fontFamily == "Helvetica")
    {
        font.setStyleHint(QFont::Helvetica);
    }
    else if(fontFamily == "Serif")
    {
        font.setStyleHint(QFont::Serif);
    }
    else if(fontFamily == "Times")
    {
        font.setStyleHint(QFont::Times);
    }
    else if(fontFamily == "TypeWriter")
    {
        font.setStyleHint(QFont::TypeWriter);
    }
    else if(fontFamily == "Courier")
    {
        font.setStyleHint(QFont::Courier);
    }
    else if(fontFamily == "OldEnglish")
    {
        font.setStyleHint(QFont::OldEnglish);
    }
    else if(fontFamily == "Decorative")
    {
        font.setStyleHint(QFont::Decorative);
    }
    else if(fontFamily == "Monospace")
    {
        font.setStyleHint(QFont::Monospace);
    }
    else if(fontFamily == "Fantasy")
    {
        font.setStyleHint(QFont::Fantasy);
    }
    else if(fontFamily == "Cursive")
    {
        font.setStyleHint(QFont::Cursive);
    }
    else if(fontFamily == "System")
    {
        font.setStyleHint(QFont::System);
    }
    else
    {
        font.setFamily("Comic Sans MS");
    }
}
//----------------------------------------------------------------------
void Text::setTextFontStyle(QString fontStyle) // set font style
{
    if(fontStyle == "StyleNormal")
    {
        font.setStyle(QFont::StyleNormal);
    }
    else if(fontStyle == "StyleItalic")
    {
        font.setStyle(QFont::StyleItalic);
    }
    else if(fontStyle == "StyleOblique")
    {
        font.setStyle(QFont::StyleOblique);
    }
}
//----------------------------------------------------------------------
void Text::setTextFontWeight(QString weight) // set font weight
{
    if(weight == "Thin")
    {
        font.setWeight(QFont::Thin);
    }
    else if(weight == "ExtraLight")
    {
        font.setWeight(QFont::ExtraLight);
    }
    else if(weight == "Light")
    {
        font.setWeight(QFont::Light);
    }
    else if(weight == "Normal")
    {
        font.setWeight(QFont::Normal);
    }
    else if(weight == "Medium")
    {
        font.setWeight(QFont::Medium);
    }
    else if(weight == "DemiBold")
    {
        font.setWeight(QFont::DemiBold);
    }
    else if(weight == "Bold")
    {
        font.setWeight(QFont::Bold);
    }
    else if(weight == "ExtraBold")
    {
        font.setWeight(QFont::ExtraBold);
    }
    else if(weight == "Black")
    {
        font.setWeight(QFont::Black);
    }
}
//----------------------------------------------------------------------
void Text::setColor(QString c) // set text color
{
    penColor.setColor(c);
}
//----------------------------------------------------------------------
void Text::draw(QPaintDevice* pDevice) const //override
{
    QPainter* paint = *p_pPaint;
    paint->begin(pDevice); // Paint device begins to paint
    paint->setFont(font); // set font text
    paint->setPen(penColor); // set color
    // Calling QPainter's drawText function
    paint->drawText(textBounds, textString, textFormat);
    paint->end(); // Ends painting
}
//----------------------------------------------------------------------
void Text::move(int x, int y) //override
{
    textBounds.moveTo(x, y);
}
//----------------------------------------------------------------------
double Text::perimeter() //override
{
    return 2* (textBounds.width() + textBounds.height());
}
//----------------------------------------------------------------------
double Text::area() //override
{
    return textBounds.width() * textBounds.height();
}
//----------------------------------------------------------------------
void Text::operator>>(QTextStream& fileStream)
{
    fileStream << "\nShapeId: " << this->getID()
        << "\nShapeType: Text"
        << "\nShapeDimensions: " << this->textBounds.x() << ", " << this->textBounds.y()
            << ", " << this->textBounds.height() << ", " << this->textBounds.width()
        << "\nTextString: " << this->textString
        << "\nTextColor: " << slp::colorResolver.key(this->getPen().color())
        << "\nTextAlignment: " << slp::alignmentFlagResolver.key(this->textFormat.alignment())
        << "\nTextPointSize: " << this->font.pointSize()
        << "\nTextFontFamily: " << this->font.family()
        << "\nTextFontStyle: " << slp::fontStyleResolver.key(this->font.style())
        << "\nTextFontWeight: " << slp::fontWeightResolver.key(this->font.weight());
}
void Text::setDimensions(int dimensions[], int dimensionsCount)
{
    textBounds.setRect(dimensions[0], dimensions[1], dimensions[2], dimensions[3]);
}
