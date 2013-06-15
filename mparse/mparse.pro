#-------------------------------------------------
#
# Project created by QtCreator 2013-06-15T08:59:10
#
#-------------------------------------------------

QT       += sql

QT       -= gui

TARGET = mparse
TEMPLATE = lib

DEFINES += MPARSE_LIBRARY

INCLUDEPATH += ../include
INCLUDEPATH += ../include/v8
INCLUDEPATH += ../include/log4cpp

SOURCES += mparse.cpp

HEADERS += mparse.h\
        mparse_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/v8/release/ -lv8_base.ia32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/v8/debug/ -lv8_base.ia32
else:unix: LIBS += -L$$PWD/../lib/v8/ -lv8_base.ia32

INCLUDEPATH += $$PWD/../include/v8
DEPENDPATH += $$PWD/../include/v8
