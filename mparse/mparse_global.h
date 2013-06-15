#ifndef MPARSE_GLOBAL_H
#define MPARSE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MPARSE_LIBRARY)
#  define MPARSESHARED_EXPORT Q_DECL_EXPORT
#else
#  define MPARSESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MPARSE_GLOBAL_H
