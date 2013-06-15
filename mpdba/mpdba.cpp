#include "mpdba.h"
#include "QDebug"


MpDba::MpDba()
{
}

QString MpDba::markdownToHtmlJs()
{
    return mp_option_dao.markdownToHtmlJs();
}

QString MpDba::htmlToMarkdownJs()
{
    MpOptionsDao dao;
    return mp_option_dao.htmlToMarkdownJs();
}
