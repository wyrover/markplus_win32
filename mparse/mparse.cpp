#include "mparse.h"
#include "QDebug"

Mparse::Mparse()
{

    markedContext = v8::Context::New();
    initEnvironment();
}

void Mparse::initEnvironment()
{
    MpDba dba;
    QString markedJs = dba.markdownToHtmlJs();
    v8::Context::Scope scope(markedContext);
    v8::Handle<v8::String> markedSource = v8::String::New(markedJs.toLatin1().data());
    v8::Handle<v8::Script> markedScript = v8::Script::Compile(markedSource);
    v8::Handle<v8::Value> markedResult = markedScript->Run();
}

QString Mparse::markdownToHtml(QString markdown)
{
    v8::Context::Scope scope(markedContext);
    QString cmd = QString("marked('%1');").arg(markdown);
    v8::Handle<v8::String> source = v8::String::New(cmd.toLatin1().data());
    v8::Handle<v8::Script> script = v8::Script::Compile(source);
    v8::Handle<v8::Value> result = script->Run();
    v8::String::Utf8Value str(result);
    return QString(ToCString(str));
}

QString Mparse::htmlToMarkdown(QString html)
{
    return html;
}

const char* Mparse::ToCString(const v8::String::Utf8Value& value) {
  return *value ? *value : "<string conversion failed>";
}
