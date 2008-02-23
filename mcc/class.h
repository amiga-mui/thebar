/***************************************************************************

 TheBar.mcc - Next Generation Toolbar MUI Custom Class
 Copyright (C) 2003-2005 Alfonso Ranieri
 Copyright (C) 2005-2007 by TheBar.mcc Open Source Team

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

#ifndef _CLASS_H
#define _CLASS_H

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/utility.h>
#include <proto/graphics.h>
#include <proto/datatypes.h>
#include <proto/cybergraphics.h>
#include <proto/intuition.h>
#include <proto/muimaster.h>

#include <clib/alib_protos.h>

#ifndef __AROS__
#include <clib/debug_protos.h>
#endif

#include <datatypes/pictureclass.h>
#include <utility/pack.h>
#include <cybergraphx/cybergraphics.h>

#include <string.h>

#include <mui/TheBar_mcc.h>

#include "SDI_compiler.h"

// these systems are able to handle alpha channel information
#if defined(__MORPHOS__) || defined(__amigaos4__) || defined(__AROS__)
	#define WITH_ALPHA			1
#endif

/***********************************************************************/

#ifdef __AROS__
#define spacerObject  BOOPSIOBJMACRO_START(lib_spacerClass->mcc_Class)
#define dragBarObject BOOPSIOBJMACRO_START(lib_dragBarClass->mcc_Class)
#else
#define spacerObject  NewObject(lib_spacerClass->mcc_Class,NULL
#define dragBarObject NewObject(lib_dragBarClass->mcc_Class,NULL
#endif

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
/*
** MUI undocs
*/

#ifndef MUIM_Backfill
#define MUIM_Backfill 0x80428d73
struct  MUIP_Backfill        { ULONG MethodID; LONG left; LONG top; LONG right; LONG bottom; LONG xoffset; LONG yoffset; LONG lum; };
#endif

#ifndef MUIA_CustomBackfill
#define MUIA_CustomBackfill  0x80420a63
#endif

#ifndef MUIM_CustomBackfill  
#define MUIM_CustomBackfill  MUIM_Backfill
#endif

#ifndef MUIP_CustomBackfill
#define MUIP_CustomBackfill  MUIP_Backfill
#endif

#ifndef MUIM_CreateDragImage
#define MUIM_CreateDragImage 0x8042eb6f /* V18 */ /* Custom Class */
struct  MUIP_CreateDragImage { ULONG MethodID; LONG touchx; LONG touchy; ULONG flags; }; /* Custom Class */

struct MUI_DragImage
{
    struct BitMap *bm;
    WORD width;  
    WORD height;
    WORD touchx; 
    WORD touchy;
    ULONG flags;
};

#endif

#ifndef MUIM_DeleteDragImage 
#define MUIM_DeleteDragImage 0x80423037
struct MUIP_DeleteDragImage {ULONG MethodID; struct MUI_DragImage *di;};
#endif

// xget()
// Gets an attribute value from a MUI object
#ifdef __AROS__
#define xget XGET
#else
ULONG xget(Object *obj, const ULONG attr);
#if defined(__GNUC__)
  // please note that we do not evaluate the return value of GetAttr()
  // as some attributes (e.g. MUIA_Selected) always return FALSE, even
  // when they are supported by the object. But setting b=0 right before
  // the GetAttr() should catch the case when attr doesn't exist at all
  #define xget(OBJ, ATTR) ({ULONG b=0; GetAttr(ATTR, OBJ, &b); b;})
#endif
#endif

/****************************************************************************/

/* utils.c */
#ifdef __MORPHOS__

#elif defined(__AROS__)
Object *DoSuperNew(struct IClass *cl, Object *obj, IPTR tag1, ...);
#else
Object * VARARGS68K DoSuperNew(struct IClass *cl, Object *obj, ...);
#endif
APTR allocVecPooled(APTR pool, ULONG size);
void freeVecPooled (APTR pool, APTR mem);
APTR reallocVecPooledNC(APTR pool,APTR mem,ULONG size);

/* brc1.c */
int BRCUnpack(APTR pSource, APTR pDest, LONG srcBytes0, LONG dstBytes0);

/* spacer.c */
BOOL initSpacerClass(void);

/* dragbar.c */
BOOL initDragBarClass(void);

/***********************************************************************/

#endif /* _CLASS_H */
