#ifndef _PRIVATE_H
#define _PRIVATE_H

/***************************************************************************

 TheBar.mcc - Next Generation Toolbar MUI Custom Class
 Copyright (C) 2003-2005 Alfonso Ranieri
 Copyright (C) 2005-2006 by TheBar.mcc Open Source Team

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

#include <mui/TheBar_mcc.h>

#include "TheBar_mcp.h"

/***************************************************************************/

extern ULONG lib_flags;

extern struct MUI_CustomClass *ThisClass;
extern struct MUI_CustomClass *lib_spacerClass;
extern struct MUI_CustomClass *lib_dragBarClass;

enum
{
    BASEFLG_Init    = 1<<0,
    BASEFLG_MUI20   = 1<<1,
    BASEFLG_MUI4    = 1<<2,
    BASEFLG_MORPHOS = 1<<3,
};

/***************************************************************************/

struct MUI_FrameSpec
{
  char buf[32];
};

struct pen
{
    UBYTE pen;
    UBYTE done;
};

#define STATICSORTSIZE 31

struct InstData
{
    APTR                           pool;
    struct MinList                 buttons;

    struct Screen                  *screen;
    ULONG                          screenDepth;

    struct MUIS_TheBar_Brush       **brushes;
    struct MUIS_TheBar_Brush       **sbrushes;
    struct MUIS_TheBar_Brush       **dbrushes;
    struct MUIS_TheBar_Strip       strip;
    ULONG                          nbr;

    struct MUIS_TheBar_Brush       image;
    struct pen                     pens[256];
    struct pen                     gpens[256];

    struct MUIS_TheBar_Brush       simage;
    struct pen                     spens[256];
    struct pen                     sgpens[256];

    struct MUIS_TheBar_Brush       dimage;
    struct pen                     dpens[256];
    struct pen                     dgpens[256];

    Object                         *db;

    ULONG                          spacer;
    ULONG                          barPos;
    ULONG                          viewMode;
    ULONG                          labelPos;

    ULONG                          buttonWidth;
    ULONG                          buttonHeight;
    ULONG                          width;
    ULONG                          height;

    ULONG                          precision;
    ULONG                          scale;
    ULONG                          disMode;
    ULONG                          active;
    ULONG                          changes;
    ULONG                          remove;

    LONG                           cols;
    LONG                           rows;
    LONG                           lcols;
    LONG                           lrows;

    ULONG                          horizSpacing;
    ULONG                          vertSpacing;
    ULONG                          leftBarFrameSpacing;
    ULONG                          rightBarFrameSpacing;
    ULONG                          topBarFrameSpacing;
    ULONG                          bottomBarFrameSpacing;
    ULONG                          barSpacerSpacing;
    ULONG                          horizInnerSpacing;
    ULONG                          topInnerSpacing;
    ULONG                          bottomInnerSpacing;
    ULONG                          horizTextGfxSpacing;
    ULONG                          vertTextGfxSpacing;
    LONG                           barFrameShinePen;
    LONG                           barFrameShadowPen;

    ULONG                          sortMsgID;
    ULONG                          sort[STATICSORTSIZE+1];

    ULONG                          stripsRows;
    ULONG                          stripsCols;
    ULONG                          stripHorizSpace;
    ULONG                          stripVertSpace;

    struct MUI_DragImage           *dm;
    struct MUIS_TheBar_DragImage   di;

    struct BitMap                  *gradbm;
    struct MUIS_TheBar_Gradient    grad;

    struct MUIS_TheBar_Appareance  ap;

    ULONG                          id;

    ULONG                          spacersSize;

    #ifdef VIRTUAL
    ULONG			                     objWidth;
    ULONG			                     objHeight;
    #endif

    #ifdef __MORPHOS__
    ULONG			                     userFrame;
    struct MUI_FrameSpec 	         frameSpec;
    #endif

    ULONG                          flags;
    ULONG                          userFlags;
    ULONG                          flags2;
    ULONG                          userFlags2;

    struct MUI_EventHandlerNode    eh;
};

/* flags */
enum
{
    FLG_Horiz              = 1<<0,
    FLG_Borderless         = 1<<1,
    FLG_Raised             = 1<<2,
    FLG_Scaled             = 1<<3,
    FLG_Sunny              = 1<<4,
    FLG_EnableKeys         = 1<<5,
    FLG_Setup              = 1<<6,
    FLG_Limbo              = 1<<7,
    FLG_TextOnly           = 1<<8,
    FLG_FreeBrushes        = 1<<9,
    FLG_FreeStrip          = 1<<10,
    FLG_Background         = 1<<11,
    FLG_IsInVirtgroup      = 1<<12,
    FLG_DragBar            = 1<<13,
    FLG_Framed             = 1<<14,
    FLG_Table              = 1<<15,
    FLG_FreeHoriz          = 1<<16,
    FLG_FreeVert           = 1<<17,
    FLG_BarSpacer          = 1<<18,
    FLG_AutoSpacerOrient   = 1<<19,
    FLG_Strip              = 1<<20,
    FLG_CyberMap           = 1<<21,
    FLG_CyberDeep          = 1<<22,
    FLG_RebuildbitMaps     = 1<<23,
};

/* flags 2 */
enum
{
    FLG2_Gradient            = 1<<0,
    FLG2_IgnoreAppareance    = 1<<1,
    FLG2_ForceWindowActivity = 1<<2,
    FLG2_EventHandler        = 1<<3,
};

/* userFlags */
enum
{
    UFLG_UserHorizSpacing          = 1<<0,
    UFLG_UserVertSpacing           = 1<<1,
    UFLG_UserBarSpacerSpacing      = 1<<2,
    UFLG_UserHorizInnerSpacing     = 1<<3,
    UFLG_UserTopInnerSpacing       = 1<<4,
    UFLG_UserBottomInnerSpacing    = 1<<5,
    UFLG_UserLeftBarFrameSpacing   = 1<<6,
    UFLG_UserRightBarFrameSpacing  = 1<<7,
    UFLG_UserTopBarFrameSpacing    = 1<<8,
    UFLG_UserBottomBarFrameSpacing = 1<<9,
    UFLG_UserHorizTextGfxSpacing   = 1<<10,
    UFLG_UserVertTextGfxSpacing    = 1<<11,
    UFLG_UserPrecision             = 1<<12,
    UFLG_UserScale                 = 1<<13,
    UFLG_UserDisMode               = 1<<14,
    UFLG_UserSpecialSelect         = 1<<15,
    UFLG_SpecialSelect             = 1<<16,
    UFLG_UserTextOverUseShine      = 1<<17,
    UFLG_TextOverUseShine          = 1<<18,
    UFLG_UserIgnoreSelImages       = 1<<19,
    UFLG_IgnoreSelImages           = 1<<20,
    UFLG_UserIgnoreDisImages       = 1<<21,
    UFLG_IgnoreDisImages           = 1<<22,
};

/* userFlags2 */
enum
{
    UFLG2_UserDontMove             = 1<<0,
    UFLG2_DontMove                 = 1<<1,
    UFLG2_UserNtRaiseActive        = 1<<2,
    UFLG2_NtRaiseActive            = 1<<3,
    UFLG2_UserSpacersSize          = 1<<4,
    UFLG2_UserFrame	               = 1<<5,
};

/***********************************************************************/

struct button
{
  struct MinNode link;
  ULONG          ID;
  Object         *obj;
  ULONG          img;
  const char     *text;
  const char     *help;
  struct IClass  *class;
  struct MinList notifies;
  ULONG          exclude;

  ULONG          flags;
};

enum
{
    BFLG_NoClick   = 1<<0,
    BFLG_Immediate = 1<<1,
    BFLG_Toggle    = 1<<2,
    BFLG_Disabled  = 1<<3,
    BFLG_Selected  = 1<<4,
    BFLG_Sleep     = 1<<5,
    BFLG_Hide      = 1<<6,

    BFLG_TableHide = 1<<23,
};

#define BUTTON(b) ((struct button *)(b))

struct notify
{
    struct MinNode     link;
    struct MUIP_Notify notify;
};

#define NOTIFY(n) ((struct notify *)(n))

/***********************************************************************/

/* build.c */
void build(struct InstData *data);
void freeBitMaps(struct InstData *data);

/***********************************************************************/

// some undocumented but valid MUI specials
#define MUIM_CustomBackfill                 0x80428d73 /* private */ /* V11 */
#define MUIM_CreateDragImage                0x8042eb6f /* private */ /* V18 */
#define MUIM_DeleteDragImage                0x80423037 /* private */ /* V18 */
#define MUIM_DoDrag                         0x804216bb /* V20 */

#define MUIA_CustomBackfill                 0x80420a63 /* V11 isg BOOL              */ /* private */
#define MUIA_Group_Forward                  0x80421422 /* V11 .s. BOOL              */

struct MUIP_CreateDragImage                 { ULONG MethodID; LONG touchx; LONG touchy; ULONG flags; }; /* private */
struct MUIP_DeleteDragImage                 { ULONG MethodID; struct MUI_DragImage *di; }; /* private */
struct MUIP_CustomBackfill                  { ULONG MethodID; LONG left; LONG top; LONG right; LONG bottom; LONG xoffset; LONG yoffset; };

struct MUI_DragImage
{
	struct BitMap *bm;
	WORD width;  /* exact width and height of bitmap */
	WORD height;
	WORD touchx; /* position of pointer click relative to bitmap */
	WORD touchy;
	ULONG flags; /* see flags below, all other flags reserved for future use */
	PLANEPTR mask;
};

#define MUIVER20 20

/***********************************************************************/

// some general macros
#define RAWIDTH(w)                      ((((UWORD)(w))+15)>>3 & 0xFFFE)
#define BOOLSAME(a,b)                   (((a) ? TRUE : FALSE)==((b) ? TRUE : FALSE))
#define copymem(to,from,len)            memcpy((to), (from), (len))
#define getconfigitem(cl,obj,item,ptr)  DoSuperMethod(cl,obj,MUIM_GetConfigItem,item,(ULONG)ptr)

#endif /* _PRIVATE_H */
