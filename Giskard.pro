TEMPLATE = app
CONFIG += link_pkgconfig
PKGCONFIG += opencv
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    ReconstruccionImagenes.cpp \
    Poblacion.cpp \
    Individuo.cpp \
    examples/GA/ga1.cpp

HEADERS += \
    ReconstruccionImagenes.h \
    Poblacion.h \
    Individuo.h

OTHER_FILES += \
    raya1.jpg

