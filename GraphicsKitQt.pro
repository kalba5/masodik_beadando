TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        application.cpp \
        legordulolista.cpp \
        main.cpp \
        szambeallit.cpp \
        widget.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -lgraphics64
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -lgraphics64d
else:unix: LIBS += -L$$PWD/./ -lgraphics64

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -llibSDL2.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -llibSDL2.dll
else:unix: LIBS += -L$$PWD/./ -llibSDL2.dll

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -llibSDL2_ttf.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -llibSDL2_ttf.dll
else:unix: LIBS += -L$$PWD/./ -llibSDL2_ttf.dll


INCLUDEPATH += $$PWD/SDL2
DEPENDPATH += $$PWD/SDL2

HEADERS += \
    application.hpp \
    legordulolista.hpp \
    szambeallit.hpp \
    widget.hpp
