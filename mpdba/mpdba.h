#ifndef MPDBA_H
#define MPDBA_H

#include <QString>
#include <QObject>
#include <QtSql/QSqlQuery>
#include <QtSql/QSQLiteDriver>
#include <QtSql/QSQLiteResult>
#include "mplog.h"
#include "mpoptionsdao.h"
#include "dba_global.h"

class DBASHARED_EXPORT MpDba
{

public:
    MpDba();

    /** 系统属性相关 **/
    QString markdownToHtmlJs();
    QString htmlToMarkdownJs();

    /** 系统用户相关 **/

    /** 云平台用户相关 **/

    /** Wordpress Post 相关 **/

private:
    MpOptionsDao mp_option_dao;
};

#endif // MPDBA_H
