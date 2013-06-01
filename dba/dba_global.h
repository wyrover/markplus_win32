#ifndef DBA_GLOBAL_H
#define DBA_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DBA_LIBRARY)
#  define DBASHARED_EXPORT Q_DECL_EXPORT
#else
#  define DBASHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DBA_GLOBAL_H
