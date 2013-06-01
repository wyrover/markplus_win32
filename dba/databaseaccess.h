#ifndef DATABASEACCESS_H
#define DATABASEACCESS_H

#include <QString>
#include <QObject>
#include <QtSql/QSqlQuery>
#include <QtSql/QSQLiteDriver>
#include <QtSql/QSQLiteResult>
#include "logger.h"
#include "dba_global.h"

class DBASHARED_EXPORT DataBaseAccess
{

public:
    DataBaseAccess();
    QString getSyntaxParse(QString);

private:
    QSqlDatabase getDataBase(QString dbname);
};

#endif // DATABASEACCESS_H
