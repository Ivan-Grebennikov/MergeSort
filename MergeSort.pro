TARGET = MergeSort
TEMPLATE = app
CONFIG += release
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

wxCXXFLAGS = $$system(wx-config --cxxflags --unicode=yes --debug=no)
wxLinkOptions = $$system(wx-config --debug=no --libs --unicode=yes)

LIBS += $$wxLinkOptions
QMAKE_CXXFLAGS_RELEASE += $$wxCXXFLAGS
QMAKE_CXXFLAGS_RELEASE += -O0


SOURCES += src/main.cpp \
    src/gmtask.cpp \
    src/gmthread.cpp \
    src/gmthreadpool.cpp \
    src/gmscripttask.cpp \
    src/gmmaintask.cpp

HEADERS += \
    include/gmtask.h \
    include/gmthread.h \
    include/gmthreadpool.h \
    include/gmscripttask.h \
    include/gmmaintask.h
