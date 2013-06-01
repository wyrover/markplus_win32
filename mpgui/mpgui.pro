#-------------------------------------------------
#
# Project created by QtCreator 2013-06-01T18:36:02
#
#-------------------------------------------------

QT       += webkit

TARGET = mpgui
TEMPLATE = lib

DEFINES += MPGUI_LIBRARY

SOURCES += \
    workwidget.cpp \
    titlebar.cpp \
    statusbar.cpp \
    setmenu.cpp \
    qtwin.cpp \
    preview.cpp \
    mpgui.cpp \
    mdeditor.cpp \
    flowlayout.cpp

HEADERS +=\
        mpgui_global.h \
    workwidget.h \
    titlebar.h \
    statusbar.h \
    setmenu.h \
    qtwin.h \
    preview.h \
    mpgui_global.h \
    mpgui.h \
    mdeditor.h \
    flowlayout.h \
    config.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

FORMS += \
    workwidget.ui \
    titlebar.ui \
    mpgui.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../logger/release/ -llogger
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../logger/debug/ -llogger
else:unix: LIBS += -L$$OUT_PWD/../logger/ -llogger

INCLUDEPATH += $$PWD/../logger
DEPENDPATH += $$PWD/../logger

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../dba/release/ -ldba
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../dba/debug/ -ldba
else:unix: LIBS += -L$$OUT_PWD/../dba/ -ldba

INCLUDEPATH += $$PWD/../dba
DEPENDPATH += $$PWD/../dba

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../syntaxparse/release/ -lsyntaxparse
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../syntaxparse/debug/ -lsyntaxparse
else:unix: LIBS += -L$$OUT_PWD/../syntaxparse/ -lsyntaxparse

INCLUDEPATH += $$PWD/../syntaxparse
DEPENDPATH += $$PWD/../syntaxparse
