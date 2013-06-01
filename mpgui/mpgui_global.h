#ifndef MPGUI_GLOBAL_H
#define MPGUI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MPGUI_LIBRARY)
#  define MPGUISHARED_EXPORT Q_DECL_EXPORT
#else
#  define MPGUISHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MPGUI_GLOBAL_H
