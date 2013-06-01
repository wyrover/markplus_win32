#ifndef SYNTAXPARSE_H
#define SYNTAXPARSE_H

#include <QFile>
#include <QString>
#include <QTextStream>
#include "syntaxparse_global.h"
#include "databaseaccess.h"
#include "logger.h"
#include "v8.h"

class SYNTAXPARSESHARED_EXPORT Syntaxparse
{

public:
    Syntaxparse();
    v8::Handle<v8::Context> createParseContext(v8::Isolate* isolate);
    v8::Handle<v8::Value> load(const v8::Arguments& args);
    v8::Handle<v8::Value> readFile(const char* name);
    v8::Handle<v8::Value> version(const v8::Arguments& value);
    QString executeString(v8::Isolate* isolate, v8::Handle<v8::String> source, v8::Handle<v8::Value> name, bool print_result, bool report_exceptions);
    void reportException(v8::Isolate* isolate, v8::TryCatch* handler);

private:
    Logger log;
    DataBaseAccess dba;
    const char* toCString(const v8::String::Utf8Value& value);
};

#endif // SYNTAXPARSE_H
