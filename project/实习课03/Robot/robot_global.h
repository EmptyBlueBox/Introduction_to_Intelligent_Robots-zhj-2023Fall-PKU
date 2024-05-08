#ifndef ROBOT_GLOBAL_H
#define ROBOT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ROBOT_LIBRARY)
#  define ROBOTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ROBOTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ROBOT_GLOBAL_H
