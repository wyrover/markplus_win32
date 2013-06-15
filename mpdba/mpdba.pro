#-------------------------------------------------
#
# Project created by QtCreator 2013-06-01T16:42:54
#
#-------------------------------------------------

QT       += sql

QT       -= gui

TARGET = mpdba

TEMPLATE = lib

DEFINES += DBA_LIBRARY

SOURCES += \
    clouduserdao.cpp \
    mpoptionsdao.cpp \
    mpuserdao.cpp \
    mppostsdao.cpp \
    wptermsdao.cpp \
    wpuserdao.cpp \
    wordpresspost.cpp \
    wordpressuser.cpp \
    clouduser.cpp \
    markplususer.cpp \
    wordpressterm.cpp \
    mpdba.cpp

HEADERS +=\
        dba_global.h \
    clouduserdao.h \
    mpoptionsdao.h \
    mpuserdao.h \
    mppostsdao.h \
    wptermsdao.h \
    wpuserdao.h \
    wordpresspost.h \
    wordpressuser.h \
    clouduser.h \
    markplususer.h \
    wordpressterm.h \
    mpdba.h

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



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../mplog/release/ -lmplog
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../mplog/debug/ -lmplog
else:unix: LIBS += -L$$OUT_PWD/../mplog/ -lmplog

INCLUDEPATH += $$PWD/../mplog
DEPENDPATH += $$PWD/../mplog
