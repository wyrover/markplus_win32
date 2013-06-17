#include "mpscriptdao.h"

MpScriptDao::MpScriptDao()
{
}

QString MpScriptDao::markdownToHtmlJs()
{
    QString js = "";
    QSqlDatabase dbconn;
    dbconn = QSqlDatabase::addDatabase("QSQLITE");
    dbconn.setDatabaseName("system");
    if(!dbconn.open())
    {
        MpLog log;
        log.error("Data Base System Open Failed,Please Confirm it exists...");
    }
    QSqlQuery query;
    query.exec("select * from script where name = 'marked' limit 1");
    while(query.next())
    {
        js = query.value(2).toString();
    }
    dbconn.close();
    return js;
}

QString MpScriptDao::htmlToMarkdownJs()
{
    return "";
}
