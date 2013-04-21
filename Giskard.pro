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
    examples/GA/ga2.cpp \
    mouse.cpp \
    CirclesDetecting.cpp \
    FigureDetection.cpp \
    Reproduccion.cpp \
    util/baseconversion.cpp
HEADERS += \
    ReconstruccionImagenes.h \
    Poblacion.h \
    Individuo.h \
    IConfiguracionParametros.h \
    FigureDetection.h \
    Reproduccion.h \
    util/baseconversion.h

OTHER_FILES += \
    raya1.png

