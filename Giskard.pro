TEMPLATE = app
CONFIG += link_pkgconfig
PKGCONFIG += opencv
CONFIG += console
CONFIG += qt
QT +=  core
QMAKE_CXXFLAGS += -std=c++0x

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
    Chromosome.cpp \
    AlgoritmoGenetico.cpp
HEADERS += \
    ReconstruccionImagenes.h \
    Poblacion.h \
    Individuo.h \
    IConfiguracionParametros.h \
    FigureDetection.h \
    Reproduccion.h \
    Chromosome.h \
    AlgoritmoGenetico.h

OTHER_FILES += \
    raya1.png

