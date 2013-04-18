TEMPLATE = app
CONFIG += link_pkgconfig
PKGCONFIG += opencv
CONFIG += console
CONFIG += qt

QT +=  core

SOURCES += main.cpp \
    ReconstruccionImagenes.cpp \
    Poblacion.cpp \
    Individuo.cpp \
    examples/GA/ga1.cpp \
    mouse.cpp \
    CirclesDetecting.cpp \
    FigureDetection.cpp

HEADERS += \
    ReconstruccionImagenes.h \
    Poblacion.h \
    Individuo.h \
    IConfiguracionParametros.h \
    FigureDetection.h

OTHER_FILES += \
    raya1.jpg \
    figuras.jpg

