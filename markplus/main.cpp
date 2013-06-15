#include <QtGui/QApplication>
#include "mpgui.h"
#include <QSettings>
#include <QDebug>
#include <mpdba.h>
#include <mparse.h>
#include <v8.h>

using namespace v8;

void v8Test();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSettings *set = new QSettings("markplus.ini", QSettings::IniFormat, 0);
    bool str = set->value("window/maximum").toBool();
    set->setValue("window/title", "zhangliang605");
    set->setValue("sqlit/name", "mpdb.db");
    qDebug() << "--------------------------------->" <<str;
    MpDba dba;
    Mparse parse;
    //qDebug() << "------>" << dba.markdownToHtmlJs();
    qDebug() << "------>" << parse.markdownToHtml("---");
    //MpGui w;
    //w.show();
	return a.exec();
}

void v8Test()
{

}
