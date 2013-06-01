#include "syntaxparse.h"


Syntaxparse::Syntaxparse()
{
}

v8::Handle<v8::Context> Syntaxparse::createParseContext(v8::Isolate *isolate)
{
    v8::Handle<v8::ObjectTemplate> global = v8::ObjectTemplate::New();

    return v8::Context::New(isolate, NULL, global);
}

v8::Handle<v8::Value> Syntaxparse::load(const v8::Arguments &args)
{
    return v8::Undefined();
}

v8::Handle<v8::Value> Syntaxparse::readFile(const char *name)
{
    QString js;
    js = dba.getSyntaxParse(QString(name));
    char* parse = js.toLatin1().data();
    int size = js.length();
    v8::Handle<v8::String> result = v8::String::New(parse, size);
    delete[] parse;

    return result;
}

v8::Handle<v8::Value> Syntaxparse::version(const v8::Arguments &value)
{
    return v8::String::New(v8::V8::GetVersion());
}

QString Syntaxparse::executeString(v8::Isolate *isolate, v8::Handle<v8::String> source, v8::Handle<v8::Value> name, bool print_result, bool report_exceptions)
{
    const char* mdResult;
    v8::HandleScope handle_scope(isolate);
    v8::TryCatch try_catch;
    v8::Handle<v8::Script> script = v8::Script::Compile(source, name);
    if(script.IsEmpty())
    {
        if(report_exceptions)
            reportException(isolate, &try_catch);
        mdResult = toCString(v8::String::Utf8Value(source));
    }
    else
    {
        v8::Handle<v8::Value> result = script->Run();
        if(result.IsEmpty())
        {
            if(report_exceptions)
                reportException(isolate, &try_catch);
            mdResult = toCString(v8::String::Utf8Value(source));
        }
        else if (print_result && !result->IsUndefined())
        {
            mdResult = toCString(v8::String::Utf8Value(source));
        }
    }
    return true;
}

const char* Syntaxparse::toCString(const v8::String::Utf8Value &value)
{
    return *value ? *value : "<string conversion failed>";
}

void Syntaxparse::reportException(v8::Isolate *isolate, v8::TryCatch *try_catch)
{
    v8::HandleScope handle_scope(isolate);
    v8::String::Utf8Value exception(try_catch->Exception());
    const char* exception_string = toCString(exception);
    v8::Handle<v8::Message> message = try_catch->Message();
    if(message.IsEmpty())
    {
        Logger log;
        log.debug(QString(exception_string));
    }
    else
    {
        v8::String::Utf8Value filename(message->GetScriptResourceName());
        const char* filename_string = toCString(filename);
        int linenum = message->GetLineNumber();
        log.wran(QString("V8 Exception --  file name : ") + QString(filename_string) + QString(", line number : ") + QString(linenum + ", exception : ") + QString(exception_string));
    }
    v8::String::Utf8Value stack_trace(try_catch->StackTrace());
    if(stack_trace.length() > 0)
    {
        const char* stack_trace_string = toCString(stack_trace);
        log.wran(QString("V8 Exception -- Stack Trace Msg : ") + QString(stack_trace_string));
    }
}
