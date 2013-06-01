#-------------------------------------------------
#
# Project created by QtCreator 2013-06-01T19:02:09
#
#-------------------------------------------------

QT       -= gui

TARGET = syntaxparse
TEMPLATE = lib

DEFINES += SYNTAXPARSE_LIBRARY

INCLUDEPATH += ../include
INCLUDEPATH += ../include/log4cpp

SOURCES += syntaxparse.cpp

HEADERS += syntaxparse.h\
        syntaxparse_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/v8/release/ -lv8_base.ia32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/v8/debug/ -lv8_base.ia32
else:unix: LIBS += -L$$PWD/../lib/v8/ -lv8_base

INCLUDEPATH += $$PWD/../include/v8
DEPENDPATH += $$PWD/../include/v8

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../dba/release/ -ldba
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../dba/debug/ -ldba
else:unix: LIBS += -L$$OUT_PWD/../dba/ -ldba

INCLUDEPATH += $$PWD/../dba
DEPENDPATH += $$PWD/../dba

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../logger/release/ -llogger
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../logger/debug/ -llogger
else:unix: LIBS += -L$$OUT_PWD/../logger/ -llogger

INCLUDEPATH += $$PWD/../logger
DEPENDPATH += $$PWD/../logger
