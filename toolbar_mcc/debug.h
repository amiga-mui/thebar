/***************************************************************************

 TheBar.mcc - Next Generation Toolbar MUI Custom Class
 Copyright (C) 2003-2005 Alfonso Ranieri
 Copyright (C) 2005-2022 TheBar Open Source Team

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 TheBar class Support Site:  http://www.sf.net/projects/thebar

 $Id$

***************************************************************************/

#ifndef DEBUG_H
#define DEBUG_H

// first we make sure all previously defined symbols are undefined now so
// that no other debug system interferes with ours.
#undef ENTER
#undef LEAVE
#undef RETURN
#undef SHOWVALUE
#undef SHOWPOINTER
#undef SHOWSTRING
#undef SHOWMSG
#undef STARTCLOCK
#undef STOPCLOCK
#undef D
#undef E
#undef W
#undef ASSERT

#if defined(DEBUG)

#include <assert.h>

// debug classes
#define DBC_CTRACE    (1<<0) // call tracing (ENTER/LEAVE etc.)
#define DBC_REPORT    (1<<1) // reports (SHOWVALUE/SHOWSTRING etc.)
#define DBC_ASSERT    (1<<2) // asserts (ASSERT)
#define DBC_TIMEVAL   (1<<3) // time evaluations (STARTCLOCK/STOPCLOCK)
#define DBC_DEBUG     (1<<4) // debugging output D()
#define DBC_ERROR     (1<<5) // error output     E()
#define DBC_WARNING   (1<<6) // warning output   W()
#define DBC_ALL       0xffffffff

// debug flags
#define DBF_ALWAYS    (1<<0)
#define DBF_STARTUP   (1<<1)     // for startup/shutdown events
#define DBF_SCALE     (1<<2)     // scale.c
#define DBF_ALL       0xffffffff

void SetupDebug(void);
void CleanupDebug(void);

void _ENTER(unsigned long dclass, const char *file, int line, const char *function);
void _LEAVE(unsigned long dclass, const char *file, int line, const char *function);
void _RETURN(unsigned long dclass, const char *file, int line, const char *function, unsigned long result);
void _SHOWVALUE(unsigned long dclass, unsigned long dflags, unsigned long value, int size, const char *name, const char *file, int line);
void _SHOWPOINTER(unsigned long dclass, unsigned long dflags, const void *p, const char *name, const char *file, int line);
void _SHOWSTRING(unsigned long dclass, unsigned long dflags, const char *string, const char *name, const char *file, int line);
void _SHOWMSG(unsigned long dclass, unsigned long dflags, const char *msg, const char *file, int line);
void _DPRINTF(unsigned long dclass, unsigned long dflags, const char *file, int line, const char *format, ...);

// Core class information class messages
#define ENTER()               _ENTER(DBC_CTRACE, __FILE__, __LINE__, __FUNCTION__)
#define LEAVE()               _LEAVE(DBC_CTRACE, __FILE__, __LINE__, __FUNCTION__)
#define RETURN(r)             _RETURN(DBC_CTRACE, __FILE__, __LINE__, __FUNCTION__, (long)r)
#define SHOWVALUE(f, v)       _SHOWVALUE(DBC_REPORT, f, (long)v, sizeof(v), #v, __FILE__, __LINE__)
#define SHOWPOINTER(f, p)     _SHOWPOINTER(DBC_REPORT, f, p, #p, __FILE__, __LINE__)
#define SHOWSTRING(f, s)      _SHOWSTRING(DBC_REPORT, f, s, #s, __FILE__, __LINE__)
#define SHOWMSG(f, m)         _SHOWMSG(DBC_REPORT, f, m, __FILE__, __LINE__)
#define D(f, ...)             _DPRINTF(DBC_DEBUG, f, __FILE__, __LINE__, __VA_ARGS__)
#define E(f, ...)             _DPRINTF(DBC_ERROR, f, __FILE__, __LINE__, __VA_ARGS__)
#define W(f, ...)             _DPRINTF(DBC_WARNING, f, __FILE__, __LINE__, __VA_ARGS__)
#define ASSERT(expression)      \
  ((void)                       \
   ((expression) ? 0 :          \
    (                           \
     _DPRINTF(DBC_ASSERT,       \
              DBF_ALWAYS,       \
              __FILE__,         \
              __LINE__,         \
              "failed assertion '%s'", \
              #expression),     \
     assert(#expression),       \
     0                          \
    )                           \
   )                            \
  )

#else // DEBUG

// to replace with NOPs is important here!
#define ENTER()              ((void)0)
#define LEAVE()              ((void)0)
#define RETURN(r)            ((void)0)
#define SHOWVALUE(f, v)      ((void)0)
#define SHOWPOINTER(f, p)    ((void)0)
#define SHOWSTRING(f, s)     ((void)0)
#define SHOWMSG(f, m)        ((void)0)
#define D(f, ...)            ((void)0)
#define E(f, ...)            ((void)0)
#define W(f, ...)            ((void)0)
#define ASSERT(expression)   ((void)0)

#endif // DEBUG

#endif // DEBUG_H
