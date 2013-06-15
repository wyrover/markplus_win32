#ifndef MPDBA_GLOBAL_H
#define MPDBA_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MPDBA_LIBRARY)
#  define MPDBASHARED_EXPORT Q_DECL_EXPORT
#else
#  define MPDBASHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MPDBA_GLOBAL_H
