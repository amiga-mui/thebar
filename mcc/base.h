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

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifndef EXEC_SEMAPHORES_H
#include <exec/semaphores.h>
#endif

#include "macros.h"

/***************************************************************************/

extern UBYTE                   lib_name[];
extern UBYTE	               lib_ver[];
extern ULONG                   lib_version;
extern ULONG                   lib_revision;

extern struct ExecBase         *SysBase;
extern struct DosLibrary       *DOSBase;
extern struct Library          *UtilityBase;
extern struct IntuitionBase    *IntuitionBase;
extern struct Library          *MUIMasterBase;
extern struct GfxBase          *GfxBase;
extern struct Library          *DataTypesBase;
extern struct Library          *CyberGfxBase;

extern struct SignalSemaphore  lib_sem;
extern struct Library          *lib_base;
extern ULONG                   lib_segList;
extern ULONG                   lib_flags;

extern struct MUI_CustomClass  *lib_spacerClass;
extern struct MUI_CustomClass  *lib_dragBarClass;
extern struct MUI_CustomClass  *lib_class;

/***************************************************************************/

enum
{
    BASEFLG_Init    = 1<<0,
    BASEFLG_MUI20   = 1<<1,
    BASEFLG_MUI4    = 1<<2,
    BASEFLG_MORPHOS = 1<<3,
};

/***************************************************************************/
