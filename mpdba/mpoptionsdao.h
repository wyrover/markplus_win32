#ifndef MPOPTIONSDAO_H
#define MPOPTIONSDAO_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlField>
#include <QString>
#include <QTextCodec>
#include "mplog.h"

class MpOptionsDao
{
public:
    MpOptionsDao();
    QString markdownToHtmlJs();
    QString htmlToMarkdownJs();
};

#endif // MPOPTIONSDAO_H
