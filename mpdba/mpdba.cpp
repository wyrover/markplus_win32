#include "mpdba.h"
#include "QDebug"


Mpdba::Mpdba()
{
}

QString Mpdba::markdownToHtmlJs()
{
    MpScriptDao dao;
    return dao.markdownToHtmlJs();
}

QString Mpdba::htmlToMarkdownJs()
{
    MpScriptDao dao;
    return dao.htmlToMarkdownJs();
}
