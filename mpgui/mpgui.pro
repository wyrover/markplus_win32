#-------------------------------------------------
#
# Project created by QtCreator 2013-06-01T18:36:02
#
#-------------------------------------------------

QT       += webkit sql

TARGET = mpgui
TEMPLATE = lib

DEFINES += MPGUI_LIBRARY

INCLUDEPATH += ../include \
    ../include/log4cpp \
    ../include/v8

SOURCES += \
    workwidget.cpp \
    titlebar.cpp \
    statusbar.cpp \
    qtwin.cpp \
    preview.cpp \
    mpgui.cpp \
    mdeditor.cpp \
    flowlayout.cpp \
    basedialog.cpp \
    attributedialog.cpp \
    windowstatus.cpp \
    setupmenu.cpp

HEADERS +=\
        mpgui_global.h \
    workwidget.h \
    titlebar.h \
    statusbar.h \
    qtwin.h \
    preview.h \
    mpgui_global.h \
    mpgui.h \
    mdeditor.h \
    flowlayout.h \
    config.h \
    basedialog.h \
    attributedialog.h \
    windowstatus.h \
    setupmenu.h

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
    mpgui.ui \
    attributebasewidget.ui \
    basedialog.ui



RESOURCES += \
    mpgui.qrc

OTHER_FILES += \
    res/skin/default.qss

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../mplog/release/ -lmplog
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../mplog/debug/ -lmplog
else:unix: LIBS += -L$$OUT_PWD/../mplog/ -lmplog

INCLUDEPATH += $$PWD/../mplog
DEPENDPATH += $$PWD/../mplog

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../mpdba/release/ -lmpdba
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../mpdba/debug/ -lmpdba
else:unix: LIBS += -L$$OUT_PWD/../mpdba/ -lmpdba

INCLUDEPATH += $$PWD/../mpdba
DEPENDPATH += $$PWD/../mpdba

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../mparse/release/ -lmparse
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../mparse/debug/ -lmparse
else:unix: LIBS += -L$$OUT_PWD/../mparse/ -lmparse

INCLUDEPATH += $$PWD/../mparse
DEPENDPATH += $$PWD/../mparse
