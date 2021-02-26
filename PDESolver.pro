TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    pde.cpp \
    value.cpp \
    mesh.cpp \
    errorpool.cpp

HEADERS += \
    pde.h \
    value.h \
    mesh.h \
    errorpool.h
