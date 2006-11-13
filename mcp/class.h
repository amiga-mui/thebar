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
#include <proto/graphics.h>
#include <proto/utility.h>
#include <proto/locale.h>
#include <proto/cybergraphics.h>
#include <proto/intuition.h>
#include <proto/muimaster.h>

#include <clib/alib_protos.h>
#include <clib/debug_protos.h>
#include <libraries/gadtools.h>

#include <mui/muiundoc.h>

#ifndef __MORPHOS_
#include <dos/dos.h>
#endif

#include <string.h>

#include <TheBarPrefs.h>
#include <TheBar_mcc.h>
#include <TheButton_mcc.h>

#include "base.h"

#define CATCOMP_NUMBERS
#include "loc.h"

#ifdef __MORPHOS__
#undef NewObject
APTR NewObject( struct IClass *classPtr, CONST_STRPTR classID, ULONG tag1, ... );
#undef MUI_NewObject
Object *MUI_NewObject(char *classname,Tag tag1,...);
#endif

/***********************************************************************/

#define COLORADJBASE 0xF76B1000

#define MUIA_Coloradj_RedComp    COLORADJBASE+0
#define MUIA_Coloradj_GreenComp  COLORADJBASE+1
#define MUIA_Coloradj_BlueComp   COLORADJBASE+2
#define MUIA_Coloradj_Colorfield COLORADJBASE+3

/***********************************************************************/

#define POPBACKTAGBASE TBPTAGBASE+100

#define POPBACKGROUNDSPECSIZE 280

/***********************************************************************/
/*
** Methods
*/

#define MUIM_Popbackground_Open          POPBACKTAGBASE+0
#define MUIM_Popbackground_Close         POPBACKTAGBASE+1
#define MUIM_Popbackground_SetSpec       POPBACKTAGBASE+2
#define MUIM_Popbackground_GetSpec       POPBACKTAGBASE+3
#define MUIM_Popbackground_SelectPattern POPBACKTAGBASE+4
#define MUIM_Popbackground_ShowBitmap    POPBACKTAGBASE+5
#define MUIM_Popbackground_GradientCol   POPBACKTAGBASE+6
#define MUIM_Popbackground_Swap          POPBACKTAGBASE+7
#define MUIM_Popbackground_SetStatus     POPBACKTAGBASE+8
#define MUIM_Popbackground_GetStatus     POPBACKTAGBASE+9

/***********************************************************************/
/*
** Methods structures
*/

struct MUIP_Popbackground_Close
{
    ULONG MethodID;
    ULONG success;
};

struct MUIP_Popbackground_SetSpec
{
    ULONG                       MethodID;
    STRPTR                      spec;
    struct MUIS_TheBar_Gradient *grad;
    ULONG                       flags;
};

enum
{
    MUIV_Popbackground_SetSpec_Image = 1<<0,
};

enum
{
    MUIV_Popbackground_SetSpec_Fail,
    MUIV_Popbackground_SetSpec_Spec,
    MUIV_Popbackground_SetSpec_Grad,
};

struct MUIP_Popbackground_GetSpec
{
    ULONG                       MethodID;
    STRPTR                      spec;
    struct MUIS_TheBar_Gradient *grad;
    ULONG                       flags;
};

enum
{
    MUIV_Popbackground_GetSpec_Image = 1<<0,
};


enum
{
    MUIV_Popbackground_GetSpec_Fail,
    MUIV_Popbackground_GetSpec_Spec,
    MUIV_Popbackground_GetSpec_Grad,
};

struct MUIP_Popbackground_SelectPattern
{
    ULONG MethodID;
    ULONG id;
};

struct MUIP_Popbackground_GradientCol
{
    ULONG MethodID;
    ULONG from;
};

struct MUIP_Popbackground_SetStatus
{
    ULONG                            MethodID;
    struct MUIS_Popbackground_Status *status;
};

struct MUIP_Popbackground_GetStatus
{
    ULONG                            MethodID;
    struct MUIS_Popbackground_Status *status;
};

/***********************************************************************/
/*
** Attributes
*/

#define MUIA_Popbackground_PopObj     POPBACKTAGBASE+0
#define MUIA_Popbackground_BackObj    POPBACKTAGBASE+1
#define MUIA_Popbackground_Gradient   POPBACKTAGBASE+2
#define MUIA_Popbackground_Grad       POPBACKTAGBASE+3
#define MUIA_Popbackground_From       POPBACKTAGBASE+4
#define MUIA_Popbackground_To         POPBACKTAGBASE+5
#define MUIA_Popbackground_File       POPBACKTAGBASE+6
#define MUIA_Popbackground_Horiz      POPBACKTAGBASE+7

/***********************************************************************/
/*
** Structures
*/

struct MUI_PopbackgroundSpec
{
    char buf[POPBACKGROUNDSPECSIZE];
};

struct MUIS_Popbackground_Status
{
    LONG                        pattern;
    LONG                        pen;
    LONG                        colormap;
    ULONG                       rgb;
    char                        bitmap[256];
    struct MUIS_TheBar_Gradient grad;
};

/***********************************************************************/
/*
** MUI macros
*/

#define coloradjustObject       NewObject(lib_coloradjust->mcc_Class,NULL
#define penadjustObject         NewObject(lib_penadjust->mcc_Class,NULL
#define backgroundadjustObject  NewObject(lib_backgroundadjust->mcc_Class,NULL
#define poppenObject            NewObject(lib_poppen->mcc_Class,NULL
#define popbackObject           NewObject(lib_popbackground->mcc_Class,NULL

/***********************************************************************/
/*
** MUI undoc stuff
*/

#ifndef MUIA_Window_MenuGadget
#define MUIA_Window_MenuGadget       0x8042324E
#endif

#ifndef MUIA_Window_SnapshotGadget
#define MUIA_Window_SnapshotGadget   0x80423C55
#endif

#ifndef MUIA_Window_ConfigGadget
#define MUIA_Window_ConfigGadget     0x8042E262
#endif

#ifndef MUIA_Window_IconifyGadget
#define MUIA_Window_IconifyGadget    0x8042BC26
#endif

/***********************************************************************/
/*
** Menus macros
*/

#define MTITLE(t)           {NM_TITLE,(STRPTR)(t),0,0,0,0}
#define MITEM(d)            {NM_ITEM,NULL,0,0,0,(APTR)(d)}
#define MBAR                {NM_ITEM,(STRPTR)NM_BARLABEL,0,0,0,NULL}
#define MEND                {NM_END,NULL,0,0,0,NULL}

/***********************************************************************/

#define IDSSIZE(ids) (sizeof(ids)/sizeof(ULONG))

/***********************************************************************/

#ifndef MUIM_Mccprefs_RegisterGadget
#define MUIM_Mccprefs_RegisterGadget 0x80424828
#endif

#ifndef MUII_PopFont
#define MUII_PopFont 42
#endif

/***********************************************************************/

#include "class_protos.h"

/***********************************************************************/

#endif /* _CLASS_H */
