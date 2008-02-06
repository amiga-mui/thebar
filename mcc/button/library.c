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

#include <proto/exec.h>
#include <proto/muimaster.h>

/******************************************************************************/
/*                                                                            */
/* MCC/MCP name and version                                                   */
/*                                                                            */
/* ATTENTION:  The FIRST LETTER of NAME MUST be UPPERCASE                     */
/*                                                                            */
/******************************************************************************/

#include "class.h"
#include "private.h"
#include "rev.h"

#include "mcc_common.h"

#include "Debug.h"

#define VERSION       LIB_VERSION
#define REVISION      LIB_REVISION

#define SUPERCLASS    MUIC_Area
#define CLASS         MUIC_TheButton

#define INSTDATA      InstData

#define USERLIBID     CLASS " " LIB_REV_STRING CPU " (" LIB_DATE ") " LIB_COPYRIGHT
#define MASTERVERSION 19

#define USEDCLASSESP  used_classesP
static const char * const used_classesP[] = { "TheBar.mcp", NULL };

#define CLASSINIT
#define CLASSEXPUNGE

#define MIN_STACKSIZE 8192

struct Library *DataTypesBase = NULL;
struct Library *CyberGfxBase = NULL;
struct Library *DiskfontBase = NULL;
struct Library *PictureDTBase = NULL;

#if defined(__amigaos4__)
struct DataTypesIFace *IDataTypes = NULL;
struct CyberGfxIFace *ICyberGfx = NULL;
struct DiskfontIFace *IDiskfont = NULL;
#endif

// some variables we carry for the whole lifetime of the lib
struct SignalSemaphore lib_poolSem;
APTR  lib_pool = NULL;
ULONG lib_flags = 0;
ULONG lib_alpha = 0xffffffff;

/******************************************************************************/
/* define the functions used by the startup code ahead of including mccinit.c */
/******************************************************************************/
static BOOL ClassInit(UNUSED struct Library *base);
static BOOL ClassExpunge(UNUSED struct Library *base);

/******************************************************************************/
/* include the lib startup code for the mcc/mcp  (and muimaster inlines)      */
/******************************************************************************/
#include "mccinit.c"

/******************************************************************************/
/* define all implementations of our user functions                           */
/******************************************************************************/
static BOOL ClassInit(UNUSED struct Library *base)
{
  ENTER();

  if((lib_pool = CreatePool(MEMF_ANY, 2048, 1024)))
  {
    InitSemaphore(&lib_poolSem);

    if((DataTypesBase = OpenLibrary("datatypes.library", 37)) &&
       GETINTERFACE(IDataTypes, struct DataTypesIFace *, DataTypesBase))
    {
      if((DiskfontBase = OpenLibrary("diskfont.library", 37)) &&
         GETINTERFACE(IDiskfont, struct DiskfontIFace *, DiskfontBase))
      {
        // we open the cybgraphics.library but without failing if
        // it doesn't exist
        if((CyberGfxBase = OpenLibrary("cybergraphics.library", 41)) &&
           GETINTERFACE(ICyberGfx, struct CyberGfxIFace *, CyberGfxBase))
        { }

        PictureDTBase = OpenLibrary("picture.datatype", 0);

        // check the version of MUI)
        if(MUIMasterBase->lib_Version >= MUIVER20)
        {
          setFlag(lib_flags, BASEFLG_MUI20);

          if(MUIMasterBase->lib_Version > MUIVER20 || MUIMasterBase->lib_Revision >= 5341)
            setFlag(lib_flags, BASEFLG_MUI4);
        }

        setFlag(lib_flags, BASEFLG_Init);

        RETURN(TRUE);
        return(TRUE);
      }
    }
  }

  RETURN(FALSE);
  return(FALSE);
}

static BOOL ClassExpunge(UNUSED struct Library *base)
{
  ENTER();

  if(PictureDTBase)
  {
    CloseLibrary(PictureDTBase);
    PictureDTBase = NULL;
  }

  if(CyberGfxBase)
  {
    DROPINTERFACE(ICyberGfx);
    CloseLibrary(CyberGfxBase);
    CyberGfxBase = NULL;
  }

  if(DiskfontBase)
  {
    DROPINTERFACE(IDiskfont);
    CloseLibrary(DiskfontBase);
    DiskfontBase = NULL;
  }

  if(DataTypesBase)
  {
    DROPINTERFACE(IDataTypes);
    CloseLibrary(DataTypesBase);
    DataTypesBase = NULL;
  }

  clearFlag(lib_flags, BASEFLG_Init|BASEFLG_MUI20|BASEFLG_MUI4);

  RETURN(TRUE);
  return(TRUE);
}

#ifdef __AROS__
#include <aros/symbolsets.h>

ADD2INITLIB(ClassInit, 0);
ADD2EXPUNGELIB(ClassExpunge, 0);

#endif
