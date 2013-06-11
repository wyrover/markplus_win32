#include <QtGui/QApplication>
#include "mpgui.h"
#include <QSettings>
#include <QDebug>
#include <databaseaccess.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QSettings *set = new QSettings("markplus.ini", QSettings::IniFormat, 0);
	bool str = set->value("window/maximum").toBool();
	set->setValue("window/title", "zhangliang605");
	set->setValue("sqlit/name", "mpdb.db");
	qDebug() << "--------------------------------->" <<str;
    DataBaseAccess dba;
    qDebug() << "------>" << dba.getSyntaxParse("marked");
	MpGui w;
	w.show();
	return a.exec();
}
