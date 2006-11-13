/*
**
** TheBar - Next Generation MUI Buttons Bar Class
**
** Copyright 2003-2005 by Alfonso [alfie] Ranieri <alforan@tin.it>
** All Rights Are Reserved.
**
** Destributed Under The Terms Of The LGPL II
**
**
**/

#ifndef _CLASS_H
#define _CLASS_H

#define __NOLIBBASE__
#define __USE_SYSBASE

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/utility.h>
#include <proto/graphics.h>
#include <proto/datatypes.h>
#include <proto/cybergraphics.h>
#include <proto/intuition.h>
#include <proto/muimaster.h>

#include <clib/alib_protos.h>
#include <clib/debug_protos.h>

#include <datatypes/pictureclass.h>
#include <utility/pack.h>
#include <cybergraphx/cybergraphics.h>
#include <mui/muiundoc.h>

#include <dos.h>
#include <string.h>

#include <TheBar_mcc.h>
#include <TheButton_mcc.h>
#include <TheBarPrefs.h>

#include "base.h"

#ifdef __MORPHOS__
#undef NewObject
APTR NewObject( struct IClass *classPtr, CONST_STRPTR classID, ULONG tag1, ... );
#undef MUI_NewObject
Object *MUI_NewObject(char *classname,Tag tag1,...);
#endif

/***********************************************************************/

extern char LIBNAME[];

/***********************************************************************/

#define spacerObject  NewObject(lib_spacerClass->mcc_Class,NULL
#define dragBarObject NewObject(lib_dragBarClass->mcc_Class,NULL

/***********************************************************************/

struct scale
{
    UWORD sw;
    UWORD sh;
    UWORD dw;
    UWORD dh;
};

/***********************************************************************/

enum
{
    MINTERM_ZERO        = 0,
    MINTERM_ONE         = ABC | ABNC | ANBC | ANBNC | NABC | NABNC | NANBC | NANBNC,
    MINTERM_COPY        = ABC | ABNC | NABC | NABNC,
    MINTERM_NOT_C       = ABNC | ANBNC | NABNC | NANBNC,
    MINTERM_B_AND_C     = ABC | NABC,
    MINTERM_NOT_B_AND_C = ANBC | NANBC,
    MINTERM_B_OR_C      = ABC | ABNC | NABC | NABNC | ANBC | NANBC,
};

/****************************************************************************/

#include "class_protos.h"

/***********************************************************************/

#endif /* _CLASS_H */
