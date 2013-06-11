#include "mpoptionsdao.h"

MpOptionsDao::MpOptionsDao()
{
}

QString MpOptionsDao::markdownToHtmlJs()
{
    QString js = "";
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QSqlDatabase dbconn = QSqlDatabase::addDatabase("QSQLITE");
    dbconn.setDatabaseName("system");
    if(!dbconn.open())
    {
        Logger log;
        log.error("Data Base System Open Failed");
    }
    QSqlQuery query;
    query.exec("select * from mp_options where option_key = 'marked' limit 1");
    while(query.next())
    {
        js = query.value(2).toString();
    }
    dbconn.close();
    return js;
}

QString MpOptionsDao::htmlToMarkdownJs()
{
    return "";
}
