#include "mplog.h"


MpLog::MpLog()
{
    initConfig();
}

void MpLog::debug(QString log)
{
    logfile->debug(log.toLatin1().data());
}

void MpLog::info(QString log)
{
    logfile->info(log.toLatin1().data());
}

void MpLog::notice(QString log)
{
    logfile->notice(log.toLatin1().data());
}

void MpLog::wran(QString log)
{
    logfile->warn(log.toLatin1().data());
}

void MpLog::error(QString log)
{
    logfile->error(log.toLatin1().data());
}

void MpLog::crit(QString log)
{
    logfile->crit(log.toLatin1().data());
}

void MpLog::alert(QString log)
{
    logfile->alert(log.toLatin1().data());
}

void MpLog::falt(QString log)
{
    logfile->fatal(log.toLatin1().data());
}

void MpLog::initConfig()
{
    root = &log4cpp::Category::getRoot();
    logfile = &log4cpp::Category::getInstance(std::string("logfile"));
    log4cpp::Layout* layout = new log4cpp::BasicLayout;
    log4cpp::Appender* appender = new log4cpp::FileAppender("FileAppender", "./log.txt");
    appender->setLayout(layout);
    logfile->setAdditivity(false);
    logfile->setAppender(appender);
    logfile->setPriority(log4cpp::Priority::DEBUG);
}
