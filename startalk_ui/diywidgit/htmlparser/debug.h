#ifdef DEBUGP
#undef DEBUGP
#endif

#ifdef __cplusplus
#include <cstdio>
#if defined(WIN32) && !defined(__MINGW32__)
#include <cstring>
#endif
#else
#include <stdio.h>
#if defined(WIN32) && !defined(__MINGW32__)
#include <string.h>
#endif
#endif

#if defined(WIN32) && !defined(__MINGW32__)
#ifndef __DEBUG_H__
#define __DEBUG_H__
#include <stdarg.h>
inline void debugprintf(const char *format, ...)
{
    va_list ap;
	char *f = NULL;
	const char *p="%s:%d ";
	size_t plen = strlen(p);
    va_start(ap, format);
	f = (char *)malloc(plen + strlen(format) + 1);
	if (!f) return;
	memcpy(f, p, plen);
	memcpy(f + plen, format, strlen(format) + 1);
    vfprintf(stderr, f, ap);
    va_end(ap);
	free(f);
}
inline void dummyprintf(const char *format, ...)
{}
#endif
#endif

#ifdef DEBUG
#if defined(WIN32) && !defined(__MINGW32__)
#define DEBUGP debugprintf
#else
#define DEBUGP(args...) do { fprintf(stderr, "%s:%d ", __FILE__, __LINE__); fprintf(stderr, ## args); } while(0)
#endif
#else
#if defined(WIN32) && !defined(__MINGW32__)
#define DEBUGP dummyprintf
#else
#define DEBUGP(args...)
#endif
#endif
