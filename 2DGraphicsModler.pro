QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    forms/canvas.cpp \
    forms/circleserializer.cpp \
    forms/dialog.cpp \
    file-parsing/ShapeListingSpecification.cpp \
    forms/login.cpp \
    forms/parsepreview.cpp \
    main.cpp \
    forms/mainwindow.cpp \
    forms/penandbrushserializer.cpp \
    forms/serializepreview.cpp \
    shapes/Circle.cpp \
    shapes/Ellipse.cpp \
    shapes/Line.cpp \
    shapes/Polygon.cpp \
    shapes/Polyline.cpp \
    shapes/Rectangle.cpp \
    shapes/Shape.cpp \
    shapes/Square.cpp \
    shapes/Text.cpp \
    file-parsing/parserClass.cpp
    file-parsing/ShapeListingSpecification.cpp

HEADERS += \
    forms/canvas.h \
    forms/circleserializer.h \
    forms/dialog.h \
    forms/login.h \
    forms/mainwindow.h \
    forms/parsepreview.h \
    forms/penandbrushserializer.h \
    forms/serializepreview.h \
    ui_login.h \
    ui_mainwindow.h \
    vector.h \
    shapes/AllShapes.h \
    shapes/Circle.h \
    shapes/Ellipse.h \
    shapes/Line.h \
    shapes/Polygon.h \
    shapes/Polyline.h \
    shapes/Rectangle.h \
    shapes/Shape.h \
    shapes/Square.h \
    shapes/Text.h \
    file-parsing/parserClass.h \
    file-parsing/ShapeListingSpecification.h

FORMS += \
    circleserializer.ui \
    dialog.ui \
    login.ui \
    mainwindow.ui \
    penandbrushserializer.ui \
    serializepreview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
