#ifndef MPSCRIPTDAO_H
#define MPSCRIPTDAO_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlField>
#include <QString>
#include "mplog.h"

class MpScriptDao
{
public:
    MpScriptDao();
    QString markdownToHtmlJs();
    QString htmlToMarkdownJs();
};

#endif // MPSCRIPTDAO_H
