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

#include "class.h"
#include "private.h"
#include "version.h"

/******************************************************************************/
/* include the minimal startup code to be able to start the class from a      */
/* shell without crashing the system                                          */
/******************************************************************************/
#include "shellstart.c"

#define VERSION       LIB_VERSION
#define REVISION      LIB_REVISION

#define SUPERCLASS    MUIC_TheBar
#define CLASS         MUIC_Toolbar

#define INSTDATA      InstData

#define USERLIBID     CLASS " " LIB_REV_STRING " (" LIB_DATE ") " LIB_COPYRIGHT " [" SYSTEMSHORT "/" CPU "]"
#define MASTERVERSION 19

#define USEDCLASSES used_mccs
static const char *used_mccs[] = { "TheBar.mcc", "TheButton.mcc", NULL };

#define USEDCLASSESP used_mcps
static const char *used_mcps[] = { "TheBar.mcp", NULL };

#define MIN_STACKSIZE 8192

#define CLASSINIT
static BOOL ClassInit(UNUSED struct Library *base);

#define CLASSEXPUNGE
static BOOL ClassExpunge(UNUSED struct Library *base);

// some variables we carry for the whole lifetime of the lib
ULONG lib_flags = 0;

/******************************************************************************/

static BOOL ClassInit(UNUSED struct Library *base);
static BOOL ClassExpunge(UNUSED struct Library *base);

/******************************************************************************/

#include <mccinit.c>

/******************************************************************************/

static BOOL ClassInit(UNUSED struct Library *base)
{
    ENTER();

    if(CreateSharedPool() == TRUE)
    {
        setFlag(lib_flags, BASEFLG_Init);

        RETURN(TRUE);
        return(TRUE);
    }

    ClassExpunge(base);

    RETURN(FALSE);
    return(FALSE);
}

/******************************************************************************/

static BOOL ClassExpunge(UNUSED struct Library *base)
{
    ENTER();

    DeleteSharedPool();

    clearFlag(lib_flags, BASEFLG_Init|BASEFLG_MUI20|BASEFLG_MUI4);

    LEAVE();

    RETURN(TRUE);
    return(TRUE);
}

/******************************************************************************/
