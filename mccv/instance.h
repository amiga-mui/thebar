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

#ifndef _INSTANCE_H
#define _INSTANCE_H

/***********************************************************************/

struct pen
{
    UBYTE pen;
    UBYTE done;
};

#define STATICSORTSIZE 31

struct data
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
    ULONG			               objWidth;
    ULONG			               objHeight;
    #endif

    #ifdef __MORPHOS__
    ULONG			               userFrame;
    struct MUI_FrameSpec 	       frameSpec;
    #endif

    ULONG                          flags;
    ULONG                          userFlags;
    ULONG                          flags2;
    ULONG                          userFlags2;
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
    STRPTR         text;
    STRPTR         help;
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
void build ( struct data *data );
void freeBitMaps ( struct data *data );

/***********************************************************************/

#endif /* _INSTANCE_H */

