TEMPLATE = app
CONFIG += link_pkgconfig
PKGCONFIG += opencv
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    ReconstruccionImagenes.cpp

HEADERS += \
    ReconstruccionImagenes.h

