#ifndef MPARSE_H
#define MPARSE_H

#include <QString>
#include "mparse_global.h"
#include "v8.h"
#include "mpdba.h"

class MPARSESHARED_EXPORT Mparse
{
    
public:
    Mparse();
    QString markdownToHtml(QString markdown);
    QString htmlToMarkdown(QString html);

private:
    v8::HandleScope handleScope;
    v8::Persistent<v8::Context> markedContext;
    void initEnvironment();
    const char* ToCString(const v8::String::Utf8Value& value);
    QString filterIllegalChar(QString input);
};

#endif // MPARSE_H
