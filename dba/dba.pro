#-------------------------------------------------
#
# Project created by QtCreator 2013-06-01T16:42:54
#
#-------------------------------------------------

QT       += sql

QT       -= gui

TARGET = dba

TEMPLATE = lib

DEFINES += DBA_LIBRARY

SOURCES += databaseaccess.cpp

HEADERS += databaseaccess.h\
        dba_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}


INCLUDEPATH += ../include
INCLUDEPATH += ../include/log4cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../logger/release/ -llogger
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../logger/debug/ -llogger
else:unix: LIBS += -L$$OUT_PWD/../logger/ -llogger

INCLUDEPATH += $$PWD/../logger
DEPENDPATH += $$PWD/../logger
