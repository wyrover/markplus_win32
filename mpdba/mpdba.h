#ifndef MPDBA_H
#define MPDBA_H

#include <QString>
#include <QObject>
#include <QtSql/QSqlQuery>
#include <QtSql/QSQLiteDriver>
#include <QtSql/QSQLiteResult>
#include "mplog.h"
#include "mpscriptdao.h"
#include "dba_global.h"

class DBASHARED_EXPORT Mpdba
{

public:
    Mpdba();
    QString markdownToHtmlJs();
    QString htmlToMarkdownJs();

};

#endif // MPDBA_H
