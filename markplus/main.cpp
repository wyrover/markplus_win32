#include <QtGui/QApplication>
#include "mpgui.h"
#include <QSize>
#include <QSettings>
#include <QDebug>
#include <QTextCodec>
#include <mpdba.h>
#include <mparse.h>
#include <v8.h>

using namespace v8;

void v8Test();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QSettings *set = new QSettings("markplus.ini", QSettings::IniFormat, 0);
    bool str = set->value("window/maxwin").toBool();
    QSize size = set->value("window/size").toSize();
    set->setValue("window/size", QSize(801, 601));
    set->setValue("window/position", QPoint(50, 50));
    //set->setValue("sqlit/name", "mpdb.db");
    qDebug() << "--------------------------------->" <<str<<size;
    Mpdba dba;
    Mparse parse;
    //qDebug() << "------>" << dba.markdownToHtmlJs();
    qDebug() << "------>" << parse.markdownToHtml("---\\n##hello\\n###good");
    MpGui w;
    w.show();
	return a.exec();
}

void v8Test()
{

}
