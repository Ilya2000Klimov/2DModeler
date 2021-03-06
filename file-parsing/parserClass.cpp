#include "parserClass.h"
#include "ShapeListingSpecification.h"// include file format information

//#include "QMetaEnum"
//#include "shapes/Circle.h"
#include "shapes/AllShapes.h"

// Helper function prototype
QString getPropertyData(QTextStream&);


// validateFile
bool cs1c::ShapeParser::validateFile(QFile* file)
{
    //QFile file(filePath);
    // is file NOT accessible for reading?
    if (file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return true;
    }
    return false;
}

// Constructor
cs1c::ShapeParser::ShapeParser(QPainter** p_pPainter)
{
    slp::initShapeTypeResolver(p_pPainter);
}
// parseShape
cs1c::vector<cs1c::Shape*> cs1c::ShapeParser::parseShape(const QString fileUrl)
{
    openFile = new QFile(fileUrl);
    // shape container to be returned
    cs1c::vector<Shape*> shapeList;

    qDebug() << "Parse Call!";
    // Gating function
    // ensure file is opened correctly
    if(!validateFile(openFile))
    {
        delete openFile;
        openFile = nullptr;
        return shapeList;
    }
    qDebug() << "File opened!";
    //Shape& currentShape;
    // class for streaming data from a text file
    QTextStream openFileStream(openFile);

    // Strings to be processed
    QStringList dimensionList;
    QString shapeType;
    // Processed generic Shape properties
    int shapeId = 0;
    int* shapeDimensions;


    // so long as the file has not reached its end
    while (!openFileStream.atEnd()) {
        // For each shape listed:
        // Skip preceeding blankspace
        openFileStream.readLine();
        // alt: while(openFileStream.readLine())

        // Get properties of all shapes

        shapeId = getPropertyData(openFileStream).toInt();
        shapeType = getPropertyData(openFileStream);
        dimensionList = getPropertyData(openFileStream).split(", ");

        // Create new shape from file
        auto currentShape = slp::shapeTypeResolver.value(shapeType);
        //shapeList.push_back(slp::shapeTypeResolver.value(shapeType));
        // Convenient access to working shape
        //Shape& currentShape = shapeList.back();

        // ===============
        // For all Shapes
        // ===============
        // ID
        currentShape->setID(shapeId);

        // Dimensions
        shapeDimensions = new int[dimensionList.size()]{};
        for(int i = 0; i < dimensionList.size(); i++)//QStringList::iterator itDimension = dimensionList.begin(); itDimension != dimensionList.end(); ++itDimension)
        {
            shapeDimensions[i] = dimensionList.value(i).toInt();
        }
        currentShape->setDimensions(shapeDimensions, dimensionList.size());

        // =========================
        // For Text only properties
        // =========================
        if(shapeType.contains("Text"))
        {
            QString textString = getPropertyData(openFileStream);
            QColor textColor = slp::colorResolver.value(getPropertyData(openFileStream));
            Qt::Alignment textAlignment = slp::alignmentFlagResolver.value(getPropertyData(openFileStream));
            int textPointSize = getPropertyData(openFileStream).toInt();
            QString textFontFamily = getPropertyData(openFileStream);

            QFont textFont(textFontFamily);
            textFont.setStyle(slp::fontStyleResolver.value(getPropertyData(openFileStream)));
            textFont.setWeight(slp::fontWeightResolver.value(getPropertyData(openFileStream)));

            // Apply text properties from file
            dynamic_cast<cs1c::Text*>(currentShape)->setText(textString);
            currentShape->setPen(textColor, textPointSize, Qt::PenStyle::NoPen, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::RoundJoin);
            dynamic_cast<cs1c::Text*>(currentShape)->setAlignment(textAlignment);
            dynamic_cast<cs1c::Text*>(currentShape)->setFont(textFont);
        }
        // ============================
        // Surface and Line properties
        // ============================
        else
        {
            QColor penColor = slp::colorResolver.value(getPropertyData(openFileStream));
            int penWidth = getPropertyData(openFileStream).toInt();
            Qt::PenStyle penStyle = slp::penStyleResolver.value(getPropertyData(openFileStream));
            Qt::PenCapStyle penCapStyle = slp::penCapStyleResolver.value(getPropertyData(openFileStream));
            Qt::PenJoinStyle penJoinStyle = slp::penJoinStyleResolver.value(getPropertyData(openFileStream));

            // Apply pen properties from file
            currentShape->setPen(
                        penColor,
                        penWidth,
                        penStyle,
                        penCapStyle,
                        penJoinStyle
                        );
            // ============================
            // For Surface only properties
            // ============================
            if(!shapeType.toUpper().contains("LINE"))
            {
                QColor brushColor = slp::colorResolver.value(getPropertyData(openFileStream));
                Qt::BrushStyle brushStyle = slp::brushStyleResolver.value(getPropertyData(openFileStream));

                // Apply brush properties from file
                currentShape->setBrush(brushColor, brushStyle);
            }
        }
        shapeList.push_back(currentShape);
        qDebug() << "Shape added!";
    }
    return shapeList;
}
void cs1c::ShapeParser::serializeShapes(cs1c::vector<Shape*>& shapeList)
{
    // class for streaming data from a text file
    QTextStream openFileStream(openFile);
    for(Shape* shape : shapeList)
    {
//        switch(shape->type())
//        {
//        case Line:
//            break;
//        case Polyline:
//            break;
//        case Polygon:
//            break;
//        case Rectangle:
//            break;
//        case Square:
//            break;
//        case Ellipse:
//            break;
//        case Circle:
//            // Cast to specific derived shape
//            auto circle = dynamic_cast<cs1c::Circle*>(shape);
//            // Copy - paste from Circle.cpp operator>>
//            openFileStream << "\nShapeId: " << circle->getID()
//                << "\nShapeType: Circle"
//                << "\nShapeDimensions: " << circle->getX() << ", " << circle->getY()
//                    << ", " << circle->getRadius()
//                << "\nPenColor: " << slp::colorResolver.key(circle->getPen().color())
//                << "\nPenWidth: " << circle->getPen().width()
//                << "\nPenStyle: " << slp::penStyleResolver.key(circle->getPen().style())
//                << "\nPenCapStyle: " << slp::penCapStyleResolver.key(circle->getPen().capStyle())
//                << "\nPenJoinStyle: " << slp::penJoinStyleResolver.key(circle->getPen().joinStyle())
//                << "\nBrushColor: " << slp::colorResolver.key(circle->getBrush().color())
//                << "\nBrushStyle: " << slp::brushStyleResolver.key(circle->getBrush().style());
//            break;
//        case Text:
//            break;
//        default:
//            // Error handle
//        }
        *shape >> openFileStream;
    }
}

QString getPropertyData(QTextStream& fileStream)
{
    return fileStream.readLine().split(": ").back();
}
