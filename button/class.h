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
#define USE_BUITLIN_MATH

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/utility.h>
#include <proto/diskfont.h>
#include <proto/graphics.h>
#include <proto/datatypes.h>
#include <proto/cybergraphics.h>
#include <proto/intuition.h>
#include <proto/muimaster.h>

#include <clib/alib_protos.h>
#include <clib/debug_protos.h>

#include <graphics/rpattr.h>
#include <graphics/gfxmacros.h>
#include <utility/pack.h>
#include <datatypes/pictureclass.h>
#include <cybergraphx/cybergraphics.h>
#include <mui/muiundoc.h>

#ifndef __MORPHOS__
#include <dos.h>
#endif

#include <string.h>

#include <TheBar_mcc.h>
#include <TheButton_mcc.h>
#include <TheBarPrefs.h>

#include "base.h"

//#define USE_BASTARD_MACROS
//#include <poolbastard.h>

/****************************************************************************/

#define _riflags(obj) (muiRenderInfo(obj)->mri_Flags)

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
** stripUnderscore() modes
*/

enum
{
    STRIP_First,
    STRIP_All,
};

/***********************************************************************/

struct scale
{
    UWORD w;
    UWORD tw;
    UWORD sl;
    UWORD st;
    UWORD sw;
    UWORD sh;
    UWORD dw;
    UWORD dh;
};

/***********************************************************************/

#include "class_protos.h"

/***********************************************************************/

#endif /* _CLASS_H */
