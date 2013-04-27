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
    Reproduccion.cpp \
    Chromosome.cpp \
    AlgoritmoGenetico.cpp \
    FigureDetection.cpp \
    figure.cpp \
    SimpleNode.cpp \
    SimpleList.cpp
HEADERS += \
    ReconstruccionImagenes.h \
    Poblacion.h \
    Individuo.h \
    IConfiguracionParametros.h \
    Reproduccion.h \
    Chromosome.h \
    AlgoritmoGenetico.h \
    FigureDetection.h \
    figure.h \
    SimpleNode.h \
    SimpleList.h \
    ListADT.h

OTHER_FILES += \
    raya1.png
