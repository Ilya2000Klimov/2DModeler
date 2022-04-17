#include "parserClass.h"

#include "QMetaEnum"
#include "ShapeListingSpecification.h"

//
bool cs1c::ShapeParser::validateFile(QFile& file)
{
    //QFile file(filePath);
    // is file NOT accessible for reading?
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }
    return true;
}

cs1c::ShapeParser::ShapeParser()
{}

std::vector<Shape> cs1c::ShapeParser::parseShape(QFile& file)
{
    // shape container to be returned
    std::vector<Shape> shapeList;
    // class for streaming data from a text file
    QTextStream in(&file);
    // so long as the file has not reached its end
    while (!in.atEnd()) {
        QString line = in.readLine();

        // for every line specifying a shape id
        if (line.startsWith("ShapeId"))
        {
            // Create temporary shape to simplify cases?
            // See header or ShapeListingSpecification.h
            // for reasoning behind the following.
            switch (metaShapeTypeEnum.keyToValue(// Convert c_str to enum
                        // Get QStr from file and remove "ShapeType: "
                        // leaving only the shape type word
                        in.readLine().remove(0, slp::SHAPE_TYPE_LENGTH)
                        // Convert QStr to char*
                        .toLatin1().data())
                    )
            {
                case Line:
                    shapeList.push_back(Line(line.remove(0, slp::SHAPE_ID_LENGTH)));
                    break;
                case Polyline:
                    shapeList.push_back(PolyLine(line.remove(0, slp::SHAPE_ID_LENGTH)));
                    break;
                case Polygon:
                    shapeList.push_back(Polygon(line.remove(0, slp::SHAPE_ID_LENGTH)));
                    break;
                case Rectangle:
                    shapeList.push_back(Rectangle(line.remove(0, slp::SHAPE_ID_LENGTH)));
                    break;
                case Square:
                    shapeList.push_back(Square(line.remove(0, slp::SHAPE_ID_LENGTH)));
                    break;
                case Ellipse:
                    shapeList.push_back(Ellipse(line.remove(0, slp::SHAPE_ID_LENGTH)));
                    break;
                case Circle:
                    shapeList.push_back(Circle(line.remove(0, slp::SHAPE_ID_LENGTH)));
                    break;
                case Text:
                    shapeList.push_back(Text(line.remove(0, slp::SHAPE_ID_LENGTH)));
                    break;
                default:
                    qDebug() << "Shape type not recognized.";
            }
        }
    }
    return shapeList;
}
