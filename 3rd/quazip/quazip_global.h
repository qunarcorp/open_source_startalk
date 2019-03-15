#ifndef QUAZIP_GLOBAL_H
#define QUAZIP_GLOBAL_H

#include <QtCore/qglobal.h>
#define QUAZIP_BUILD

#ifdef QUAZIP_STATIC
#define QUAZIP_EXPORT
#else
/**
 * When building a DLL with MSVC, QUAZIP_BUILD must be defined.
 * qglobal.h takes care of defining Q_DECL_* correctly for msvc/gcc.
 */
#if defined(QUAZIP_BUILD)
	#define QUAZIP_EXPORT Q_DECL_EXPORT
#else
	#define QUAZIP_EXPORT Q_DECL_IMPORT
#endif
#endif // QUAZIP_STATIC

#ifdef __GNUC__
#define UNUSED __attribute__((__unused__))
#else
#define UNUSED
#endif

#define QUAZIP_EXTRA_NTFS_MAGIC 0x000Au
#define QUAZIP_EXTRA_NTFS_TIME_MAGIC 0x0001u

#endif // QUAZIP_GLOBAL_H
