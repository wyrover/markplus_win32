#-------------------------------------------------
#
# Project created by QtCreator 2013-06-15T08:49:53
#
#-------------------------------------------------

QT       += sql

QT       -= gui

TARGET = mplog
TEMPLATE = lib

DEFINES += MPLOG_LIBRARY

INCLUDEPATH += ../include \
            += ../include/log4cpp

SOURCES += mplog.cpp

HEADERS += mplog.h\
        mplog_global.h

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
