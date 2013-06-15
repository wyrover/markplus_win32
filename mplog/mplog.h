#ifndef MPLOG_H
#define MPLOG_H

#include "QObject"
#include "QString"
#include "mplog_global.h"
#include "Appender.hh"
#include "FileAppender.hh"
#include "BasicLayout.hh"
#include "Category.hh"
#include "PropertyConfigurator.hh"

class MPLOGSHARED_EXPORT MpLog
{
    
public:
    MpLog();
    void debug(QString log);
    void info(QString log);
    void notice(QString log);
    void wran(QString log);
    void error(QString log);
    void crit(QString log);
    void alert(QString log);
    void falt(QString log);

private:
    log4cpp::Category *root;
    log4cpp::Category *logfile;
    void initConfig();
};

#endif // MPLOG_H
