# RoadTrafficForecast.pro
TEMPLATE = app
TARGET = RoadTrafficForecast
VERSION = 1.0.0

QT += core widgets charts

CONFIG += c++17

CONFIG(release, debug|release) {
    DEFINES += QT_NO_DEBUG_OUTPUT
}

SOURCES += \
    comparedialog.cpp \
    main.cpp \
    mainwindow.cpp \
    roadsegment.cpp \
    trafficcalculator.cpp \
    weatherhelper.cpp \
    traffichart.cpp

HEADERS += \
    comparedialog.h \
    mainwindow.h \
    roadsegment.h \
    trafficcalculator.h \
    weatherhelper.h \
    traffichart.h

unix:!macx {
    QMAKE_LFLAGS += -Wl,-rpath,.
}
