#-------------------------------------------------
#
# Project created by QtCreator 2013-06-01T18:05:24
#
#-------------------------------------------------

QT       -= gui

TARGET = logger
TEMPLATE = lib

DEFINES += LOGGER_LIBRARY

SOURCES += logger.cpp

HEADERS += logger.h\
        logger_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/log4cpp/release/ -llog4cpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/log4cpp/debug/ -llog4cpp
else:unix: LIBS += -L$$PWD/../lib/log4cpp/ -llog4cpp

INCLUDEPATH += $$PWD/../include
INCLUDEPATH += ../include/log4cpp
DEPENDPATH += $$PWD/../include
