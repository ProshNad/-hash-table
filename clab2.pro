TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    contact.cpp \
    book.cpp \
    SHA256.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    contact.h \
    book.h \
    SHA256.h

OTHER_FILES += \
    ../build-clab2-Desktop_Qt_5_3_MinGW_32bit-Debug/m.ini \
    ../build-clab2-Desktop_Qt_5_3_MinGW_32bit-Debug/memory.json

