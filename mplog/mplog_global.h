#ifndef MPLOG_GLOBAL_H
#define MPLOG_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MPLOG_LIBRARY)
#  define MPLOGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MPLOGSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MPLOG_GLOBAL_H
