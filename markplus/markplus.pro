# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app

TARGET = markplus

QT += core gui webkit sql

INCLUDEPATH += ../include
INCLUDEPATH += ../include/log4cpp

SOURCES += ./main.cpp

RESOURCES += markplus.qrc

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../mpgui/release/ -lmpgui
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../mpgui/debug/ -lmpgui
else:unix: LIBS += -L$$OUT_PWD/../mpgui/ -lmpgui

INCLUDEPATH += $$PWD/../mpgui
DEPENDPATH += $$PWD/../mpgui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../syntaxparse/release/ -lsyntaxparse
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../syntaxparse/debug/ -lsyntaxparse
else:unix: LIBS += -L$$OUT_PWD/../syntaxparse/ -lsyntaxparse

INCLUDEPATH += $$PWD/../syntaxparse
DEPENDPATH += $$PWD/../syntaxparse
