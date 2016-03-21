TARGET = MergeSort
TEMPLATE = app
CONFIG += debug
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

wxCXXFLAGS = $$system(wx-config --cxxflags --unicode=yes --debug=yes)
wxLinkOptions = $$system(wx-config --debug=yes --libs --unicode=yes)

LIBS += $$wxLinkOptions
QMAKE_CXXFLAGS_DEBUG += $$wxCXXFLAGS
QMAKE_CXXFLAGS_DEBUG += -O0


SOURCES += src/main.cpp \
    src/gmtask.cpp \
    src/gmthread.cpp \
    src/gmthreadpool.cpp \
    src/gmmergesorttask.cpp \
    src/mergesortfunc.cpp

HEADERS += \
    include/gmtask.h \
    include/gmthread.h \
    include/gmthreadpool.h \
    include/gmmergesorttask.h \
    include/mergesortfuncs.h
