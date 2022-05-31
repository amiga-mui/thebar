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

#define __NOLIBBASE__
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/utility.h>
#include <proto/intuition.h>
#include <proto/muimaster.h>

#include <clib/alib_protos.h>

#ifndef __AROS__
#include <clib/debug_protos.h>
#endif

#include <string.h>

#include <mui/TheBar_mcc.h>
#include <mui/Toolbar_mcc.h>

#include <mcc_common.h>
#include <SDI_compiler.h>
#include <SDI_hook.h>
#include <SDI_stdarg.h>

#if defined(__amigaos4__)
#define __USE_CLASSIC_MINTERM__
#include <graphics/minterm.h>
#endif

#include "debug.h"

/***************************************************************************/

#if defined(__amigaos4__)
extern struct Library         *SysBase;
extern struct Library         *DOSBase;
extern struct Library         *IntuitionBase;
#else
extern struct ExecBase        *SysBase;
extern struct DosLibrary      *DOSBase;
extern struct IntuitionBase   *IntuitionBase;
#endif
#if defined(__AROS__)
extern struct UtilityBase     *UtilityBase;
#else
extern struct Library         *UtilityBase;
#endif
extern struct Library         *MUIMasterBase;

extern ULONG                  lib_flags;

enum
{
  BASEFLG_Init         = 1<<0,
  BASEFLG_MUI20        = 1<<1,
  BASEFLG_MUI4         = 1<<2,
};

/***************************************************************************/
/*
** Macros
*/

#define _riflags(obj) (muiRenderInfo(obj)->mri_Flags)

#define RAWIDTH(w)                      ((((UWORD)(w))+15)>>3 & 0xFFFE)
#define BOOLSAME(a,b)                   (((a) ? TRUE : FALSE)==((b) ? TRUE : FALSE))

#define getconfigitem(cl,obj,item,ptr)  DoSuperMethod(cl,obj,MUIM_GetConfigItem,item,(IPTR)ptr)
#define superset(cl,obj,tag,val)        SetSuperAttrs(cl,obj,tag,(IPTR)(val),TAG_DONE)
#define superget(cl,obj,tag,storage)    DoSuperMethod(cl,obj,OM_GET,tag,(IPTR)(storage))
#define nnsuperset(cl,obj,tag,val)      SetSuperAttrs(cl,obj,tag,(IPTR)(val),MUIA_NoNotify,TRUE,TAG_DONE)
#undef set
#define set(obj,attr,value)             SetAttrs((Object *)(obj),(IPTR)(attr),(IPTR)(value),TAG_DONE)
#undef get
#define get(obj,attr,store)             GetAttr((IPTR)(attr),(APTR)obj,(IPTR *)((IPTR)(store)))

#define setFlag(mask, flag)             (mask) |= (flag)
#define clearFlag(mask, flag)           (mask) &= ~(flag)
#define isAnyFlagSet(mask, flag)        (((mask) & (flag)) != 0)
#define isFlagSet(mask, flag)           (((mask) & (flag)) == (flag))
#define isFlagClear(mask, flag)         (((mask) & (flag)) == 0)

#ifdef __MORPHOS__
#undef NewObject
#undef MUI_NewObject
#undef DoSuperNew
APTR NewObject(struct IClass *classPtr,CONST_STRPTR classID,ULONG tag1,...);
Object *MUI_NewObject(CONST_STRPTR classname,Tag tag1,...);
#endif

// xget()
// Gets an attribute value from a MUI object
IPTR xget(Object *obj, const IPTR attr);
#if defined(__GNUC__)
  // please note that we do not evaluate the return value of GetAttr()
  // as some attributes (e.g. MUIA_Selected) always return FALSE, even
  // when they are supported by the object. But setting b=0 right before
  // the GetAttr() should catch the case when attr doesn't exist at all
  #define xget(OBJ, ATTR) ({IPTR b=0; GetAttr(ATTR, OBJ, &b); b;})
#endif

/****************************************************************************/

#include "class_protos.h"

/***********************************************************************/
