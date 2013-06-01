#include "databaseaccess.h"


DataBaseAccess::DataBaseAccess()
{
}

QSqlDatabase DataBaseAccess::getDataBase(QString dbname)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbname);
    return db;
}

QString DataBaseAccess::getSyntaxParse(QString js)
{
    //获取语法解析相关内容
    QSqlDatabase db = getDataBase("sys");
    if(!db.open())
    {
        Logger log;
        log.error(QObject::tr("can not open sys.db, please confirm the existing of this file"));
        return "";
    }
    QString content;
    QSqlQuery query;
    QString sql = "select * from " + js + " limit 1";
    query.exec(sql);
    while(query.next())
    {
        content = query.value(2).toString();
    }
    db.close();
    return content;
}
