#ifndef THEBAR_MCC_H
#define THEBAR_MCC_H

/*
**  $VER: TheBar_mcc.h 20.6 (22.7.2005)
**  Includes Release 20.6
**
**  (C) Copyright 2003-2005 by Alfonso [alfie] Ranieri <alforan@tin.it>
**      All rights reserved
**
**      Destributed Under The Terms Of The LGPL II
*/

#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack(2)
  #elif defined(__VBCC__)
    #pragma amiga-align
  #endif
#endif

/***********************************************************************/

#define MUIC_TheButton  "TheButton.mcc"
#define TheButtonObject MUI_NewObject(MUIC_TheButton

#define MUIC_TheBar  "TheBar.mcc"
#define TheBarObject MUI_NewObject(MUIC_TheBar

#define MUIC_TheBarVirt  "TheBarVirt.mcc"
#define TheBarVirtObject MUI_NewObject(MUIC_TheBarVirt

#define THEBAR_VERSION     20
#define THEBARVIRT_VERSION 20
#define THEBUTTON_VERSION  20

/***********************************************************************/

#define TBUTTAGBASE 0xF76B01C8
#define TBTAGBASE   0xF76B022C

/***********************************************************************/
/*
** TheButton.mcc Attributes
*/

#define MUIA_TheButton_MinVer              (TBUTTAGBASE+0)   /* v11  ULONG,                         [I...]    */
#define MUIA_TheButton_TheBar              (TBUTTAGBASE+4)   /* v11  Object *,                      [ISG.]    */
#define MUIA_TheButton_Image               (TBUTTAGBASE+5)   /* v11  struct MUIS_TheBar_Brush  *,   [I...]    */
#define MUIA_TheButton_Label               (TBUTTAGBASE+6)   /* v11  STRPTR,                        [I...]    */
#define MUIA_TheButton_InVirtgroup         (TBUTTAGBASE+7)   /* v11  BOOL,                          [I...]    */
#define MUIA_TheButton_ViewMode            (TBUTTAGBASE+8)   /* v11  ULONG,                         [ISGN]    */
#define MUIA_TheButton_Borderless          (TBUTTAGBASE+9)   /* v11  BOOL,                          [I...]    */
#define MUIA_TheButton_Raised              (TBUTTAGBASE+10)  /* v11  BOOL,                          [ISGN]    */
#define MUIA_TheButton_Sunny               (TBUTTAGBASE+11)  /* v11  BOOL,                          [I...]    */
#define MUIA_TheButton_Scaled              (TBUTTAGBASE+12)  /* v11  BOOL,                          [ISGN]    */
#define MUIA_TheButton_NoClick             (TBUTTAGBASE+13)  /* v11  BOOL,                          [I...]    */
#define MUIA_TheButton_Toggle              (TBUTTAGBASE+14)  /* v11  BOOL,                          [I...]    */
#define MUIA_TheButton_Immediate           (TBUTTAGBASE+15)  /* v11  BOOL,                          [I...]    */
#define MUIA_TheButton_EnableKey           (TBUTTAGBASE+16)  /* v11  BOOL,                          [ISG.]    */
#define MUIA_TheButton_LabelPos            (TBUTTAGBASE+17)  /* v11  ULONG,                         [ISGN]    */
#define MUIA_TheButton_SelImage            (TBUTTAGBASE+18)  /* v12  struct MUIS_TheBar_Brush  *,   [I...]    */
#define MUIA_TheButton_DisImage            (TBUTTAGBASE+19)  /* v12  struct MUIS_TheBar_Brush  *,   [I...]    */
#define MUIA_TheButton_HorizTextGfxSpacing (TBUTTAGBASE+20)  /* v12  ULONG,                         [I...]    */
#define MUIA_TheButton_VertTextGfxSpacing  (TBUTTAGBASE+21)  /* v12  ULONG,                         [I...]    */
#define MUIA_TheButton_HorizInnerSpacing   (TBUTTAGBASE+22)  /* v12  ULONG,                         [I...]    */
#define MUIA_TheButton_TopInnerSpacing     (TBUTTAGBASE+23)  /* v12  ULONG,                         [I...]    */
#define MUIA_TheButton_BottomInnerSpacing  (TBUTTAGBASE+24)  /* v12  ULONG,                         [I...]    */
#define MUIA_TheButton_Precision           (TBUTTAGBASE+25)  /* v12  ULONG,                         [I...]    */
#define MUIA_TheButton_Event               (TBUTTAGBASE+26)  /* v12  ULONG,                         [I...]    */
#define MUIA_TheButton_Scale               (TBUTTAGBASE+27)  /* v12  ULONG,                         [I...]    */
#define MUIA_TheButton_DisMode             (TBUTTAGBASE+28)  /* v12  ULONG,                         [I...]    */
#define MUIA_TheButton_SpecialSelect       (TBUTTAGBASE+29)  /* v12  BOOL,                          [I...]    */
#define MUIA_TheButton_TextOverUseShine    (TBUTTAGBASE+30)  /* v12  BOOL,                          [I...]    */
#define MUIA_TheButton_IgnoreSelImages     (TBUTTAGBASE+31)  /* v12  BOOL,                          [I...]    */
#define MUIA_TheButton_IgnoreDisImages     (TBUTTAGBASE+32)  /* v12  BOOL,                          [I...]    */
#define MUIA_TheButton_Strip               (TBUTTAGBASE+33)  /* v13  struct MUIS_TheBar_Strip *,    [I...]    */
#define MUIA_TheButton_DontMove            (TBUTTAGBASE+34)  /* v15  BOOL,                          [I...]    */
#define MUIA_TheButton_NtRaiseActive       (TBUTTAGBASE+36)  /* v18  ULONG,                         [I...]    */

/***********************************************************************/
/*
** TheButton.mcc Attributes values
*/

/* MUIA_TheButton_ViewMode */
enum
{
    MUIV_TheButton_ViewMode_TextGfx,
    MUIV_TheButton_ViewMode_Gfx,
    MUIV_TheButton_ViewMode_Text,

    MUIV_TheButton_ViewMode_Last
};

/* MUIA_TheButton_LabelPos */
enum
{
    MUIV_TheButton_LabelPos_Bottom,
    MUIV_TheButton_LabelPos_Top,
    MUIV_TheButton_LabelPos_Right,
    MUIV_TheButton_LabelPos_Left,

    MUIV_TheButton_LabelPos_Last
};

/***********************************************************************/
/*
** TheButton.mcc Misc
*/

/* MUIA_TheButton_Label max size */
#define TB_MAXLABELLEN 32

/***********************************************************************/
/*
** TheBar.mcc Methods
*/

#define MUIM_TheBar_AddButton       (TBTAGBASE+3)   /* v11         */
#define MUIM_TheBar_GetObject       (TBTAGBASE+5)   /* v11         */
#define MUIM_TheBar_DoOnButton      (TBTAGBASE+6)   /* v11         */
#define MUIM_TheBar_SetAttr         (TBTAGBASE+7)   /* v11         */
#define MUIM_TheBar_GetAttr         (TBTAGBASE+8)   /* v11         */
#define MUIM_TheBar_Clear           (TBTAGBASE+9)   /* v11         */
#define MUIM_TheBar_Sort            (TBTAGBASE+10)  /* v11         */
#define MUIM_TheBar_Remove          (TBTAGBASE+11)  /* v11         */
#define MUIM_TheBar_GetDragImage    (TBTAGBASE+12)  /* v11         */

/***********************************************************************/
/*
** TheBar.mcc Methods structures
*/

struct MUIP_TheBar_AddButton       { ULONG MethodID; struct MUIS_TheBar_Button *button; };
struct MUIP_TheBar_AddSpacer       { ULONG MethodID; ULONG ID; ULONG type; };
struct MUIP_TheBar_GetObject       { ULONG MethodID; ULONG ID; };
struct MUIP_TheBar_DoOnButton      { ULONG MethodID; ULONG ID; ULONG method; /* ...args... */ };
struct MUIP_TheBar_SetAttr         { ULONG MethodID; ULONG ID; Tag attr; ULONG value; };
struct MUIP_TheBar_GetAttr         { ULONG MethodID; ULONG ID; Tag attr; ULONG *storage; };
struct MUIP_TheBar_Sort            { ULONG MethodID; LONG obj[1]; };
struct MUIP_TheBar_Remove          { ULONG MethodID; ULONG ID; };
struct MUIP_TheBar_GetDragImage    { ULONG MethodID; ULONG horiz; ULONG flags; };

/* MUIM_TheBar_SetAttr, MUIM_TheBar_GetAttr attr */
#define MUIV_TheBar_Attr_Hide      (TBTAGBASE+0) /* v11 */
#define MUIV_TheBar_Attr_Sleep     (TBTAGBASE+1) /* v11 */
#define MUIV_TheBar_Attr_Disabled  (TBTAGBASE+2) /* v11 */
#define MUIV_TheBar_Attr_Selected  (TBTAGBASE+3) /* v11 */

/***********************************************************************/
/*
** TheBar.mcc Attributes
*/

#define MUIA_TheBar_MinVer                (TBTAGBASE+10)  /* v11 ULONG,                         [I...]   */
#define MUIA_TheBar_Buttons               (TBTAGBASE+11)  /* v11 struct MUIS_TheBar_Button *,   [I...]   */
#define MUIA_TheBar_Images                (TBTAGBASE+12)  /* v11 struct MUIS_TheBar_Brush **,   [I.G.]   */
#define MUIA_TheBar_Pics                  (TBTAGBASE+13)  /* v11 STRTR *,                       [I...]   */
#define MUIA_TheBar_PicsDrawer            (TBTAGBASE+14)  /* v11 STRTR,                         [I...]   */
#define MUIA_TheBar_ViewMode              (TBTAGBASE+15)  /* v11 UWORD,                         [ISGN]   */
#define MUIA_TheBar_Borderless            (TBTAGBASE+16)  /* v11 BOOL,                          [ISGN]   */
#define MUIA_TheBar_Raised                (TBTAGBASE+17)  /* v11 BOOL,                          [ISGN]   */
#define MUIA_TheBar_Sunny                 (TBTAGBASE+18)  /* v11 BOOL,                          [ISGN]   */
#define MUIA_TheBar_Scaled                (TBTAGBASE+19)  /* v11 BOOL,                          [ISGN]   */
#define MUIA_TheBar_SpacerIndex           (TBTAGBASE+20)  /* v11 UWORD,                         [I.G.]   */
#define MUIA_TheBar_Strip                 (TBTAGBASE+21)  /* v11 STRPTR,                        [I...]   */
#define MUIA_TheBar_StripBrush            (TBTAGBASE+22)  /* v11 STRPTR,                        [I...]   */
#define MUIA_TheBar_EnableKeys            (TBTAGBASE+23)  /* v11 BOOL,                          [IS..]   */
#define MUIA_TheBar_TextOnly              (TBTAGBASE+24)  /* v11 BOOL,                          [..G.]   */
#define MUIA_TheBar_LabelPos              (TBTAGBASE+25)  /* v11 UWORD,                         [ISGN]   */
#define MUIA_TheBar_BarPos                (TBTAGBASE+26)  /* v11 ULONG,                         [ISGN]   */
#define MUIA_TheBar_DragBar               (TBTAGBASE+27)  /* v11 BOOL,                          [ISGN]   */
#define MUIA_TheBar_Frame                 (TBTAGBASE+28)  /* v11 BOOL,                          [ISGN]   */
#define MUIA_TheBar_Limbo                 (TBTAGBASE+29)  /* v11 BOOL,                          [.S..]   */
#define MUIA_TheBar_Active                (TBTAGBASE+30)  /* v11 ULONG,                         [ISGN]   */
#define MUIA_TheBar_Columns               (TBTAGBASE+31)  /* v11 ULONG,                         [ISGN]   */
#define MUIA_TheBar_Rows                  (TBTAGBASE+32)  /* v11 ULONG,                         [ISGN]   */
#define MUIA_TheBar_FreeHoriz             (TBTAGBASE+33)  /* v11 ULONG,                         [ISGN]   */
#define MUIA_TheBar_FreeVert              (TBTAGBASE+34)  /* v11 ULONG,                         [ISGN]   */
#define MUIA_TheBar_Free                  (TBTAGBASE+35)  /* v11 ULONG,                         [ISGN]   */
#define MUIA_TheBar_BarSpacer             (TBTAGBASE+36)  /* v11 ULONG,                         [ISGN]   */
#define MUIA_TheBar_Remove                (TBTAGBASE+37)  /* v11 ULONG,                         [ISGN]   */
#define MUIA_TheBar_AutoSpacerOrient      (TBTAGBASE+38)  /* v11 ULONG,                         [ISGN]   */
#define MUIA_TheBar_SelImages             (TBTAGBASE+39)  /* v12 struct MUIS_TheBar_Brush **,   [I.G.]   */
#define MUIA_TheBar_DisImages             (TBTAGBASE+40)  /* v12 struct MUIS_TheBar_Brush **,   [I.G.]   */
#define MUIA_TheBar_SelPics               (TBTAGBASE+41)  /* v12 STRTR *,                       [I...]   */
#define MUIA_TheBar_DisPics               (TBTAGBASE+42)  /* v12 STRTR *,                       [I...]   */
#define MUIA_TheBar_SelStrip              (TBTAGBASE+43)  /* v12 STRPTR,                        [I...]   */
#define MUIA_TheBar_DisStrip              (TBTAGBASE+44)  /* v12 STRPTR,                        [I...]   */
#define MUIA_TheBar_SelStripBrush         (TBTAGBASE+45)  /* v12 STRPTR,                        [I...]   */
#define MUIA_TheBar_DisStripBrush         (TBTAGBASE+46)  /* v12 STRPTR,                        [I...]   */
#define MUIA_TheBar_StripRows             (TBTAGBASE+47)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_StripCols             (TBTAGBASE+48)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_StripHorizSpace       (TBTAGBASE+49)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_StripVertSpace        (TBTAGBASE+50)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_HorizSpacing          (TBTAGBASE+51)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_VertSpacing           (TBTAGBASE+52)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_BarSpacerSpacing      (TBTAGBASE+53)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_HorizInnerSpacing     (TBTAGBASE+54)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_TopInnerSpacing       (TBTAGBASE+55)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_BottomInnerSpacing    (TBTAGBASE+56)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_LeftBarFrameSpacing   (TBTAGBASE+57)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_RightBarFrameSpacing  (TBTAGBASE+58)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_TopBarFrameSpacing    (TBTAGBASE+59)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_BottomBarFrameSpacing (TBTAGBASE+60)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_HorizTextGfxSpacing   (TBTAGBASE+61)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_VertTextGfxSpacing    (TBTAGBASE+62)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_Precision             (TBTAGBASE+63)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_Event                 (TBTAGBASE+64)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_Scale                 (TBTAGBASE+65)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_DisMode               (TBTAGBASE+66)  /* v12 ULONG,                         [I...]   */
#define MUIA_TheBar_SpecialSelect         (TBTAGBASE+67)  /* v12 BOOL,                          [I...]   */
#define MUIA_TheBar_TextOverUseShine      (TBTAGBASE+68)  /* v12 BOOL,                          [I...]   */
#define MUIA_TheBar_IgnoreSelImages       (TBTAGBASE+69)  /* v12 BOOL,                          [I...]   */
#define MUIA_TheBar_IgnoreDisImages       (TBTAGBASE+70)  /* v12 BOOL,                          [I...]   */
#define MUIA_TheBar_DontMove              (TBTAGBASE+71)  /* v15 BOOL,                          [I...]   */
#define MUIA_TheBar_MouseOver             (TBTAGBASE+72)  /* v18 ULONG,                         [ISGN]   */
#define MUIA_TheBar_NtRaiseActive         (TBTAGBASE+73)  /* v18 BOOL,                          [ISGN]   */
#define MUIA_TheBar_SpacersSize           (TBTAGBASE+74)  /* v18 BOOL,                          [ISGN]   */
#define MUIA_TheBar_Appareance            (TBTAGBASE+75)  /* v19 struct MUIS_TheBar_Appareance, [..G.]   */
#define MUIA_TheBar_IgnoreAppareance      (TBTAGBASE+76)  /* v19 BOOL 				[ISGN]   */

/***********************************************************************/
/*
** TheBar.mcc Attributes values
*/

/* MUIA_TheBar_ViewMode */
enum
{
    MUIV_TheBar_ViewMode_TextGfx,
    MUIV_TheBar_ViewMode_Gfx,
    MUIV_TheBar_ViewMode_Text,

    MUIV_TheBar_ViewMode_Last

};

/* MUIA_TheBar_LabelPos */
enum
{
    MUIV_TheBar_LabelPos_Bottom,
    MUIV_TheBar_LabelPos_Top,
    MUIV_TheBar_LabelPos_Right,
    MUIV_TheBar_LabelPos_Left,

    MUIV_TheBar_LabelPos_Last,
};

/* MUIA_TheBar_BarPos */
enum
{
    MUIV_TheBar_BarPos_Left,
    MUIV_TheBar_BarPos_Center,
    MUIV_TheBar_BarPos_Right,

    MUIV_TheBar_BarPos_Last,
};

#define MUIV_TheBar_BarPos_Up   MUIV_TheBar_BarPos_Left
#define MUIV_TheBar_BarPos_Down MUIV_TheBar_BarPos_Right

/* MUIA_TheBar_Remove */
enum
{
    MUIV_TheBar_Remove_BarSpacers    = 1<<0, /* v11 */
    MUIV_TheBar_Remove_ButtonSpacers = 1<<1, /* v11 */
    MUIV_TheBar_Remove_ImageSpacers  = 1<<2, /* v11 */

    MUIV_TheBar_Remove_All           = MUIV_TheBar_Remove_BarSpacers|MUIV_TheBar_Remove_ButtonSpacers|MUIV_TheBar_Remove_ImageSpacers,
};

/* MUIA_TheBar_Event */
enum
{
    MUIV_TheBar_Event_IntuiTicks,
    MUIV_TheBar_Event_MouseMove,
    MUIV_TheBar_Event_MouseObject, /* Only valid for MUI >=3.9 */

    MUIV_TheBar_Event_Last,
};

/* MUIA_TheBar_Precision */
enum
{
    MUIV_TheBar_Precision_GUI,
    MUIV_TheBar_Precision_Icon,
    MUIV_TheBar_Precision_Image,
    MUIV_TheBar_Precision_Exact,

    MUIV_TheBar_Precision_Last,
};

/* MUIA_TheBar_DisMode */
enum
{
    MUIV_TheBar_DisMode_Shape,
    MUIV_TheBar_DisMode_Grid,
    MUIV_TheBar_DisMode_FullGrid,
    MUIV_TheBar_DisMode_Sunny,

    MUIV_TheBar_DisMode_Last,
};

#define MUIV_TheBar_SkipPic ((STRPTR)(-1))

/***********************************************************************/
/*
** Structures
*/

/*
** MUIA_TheButton_Image is a pointer to this.
** MUIA_TheBar_Images is an array of pointers to this.
**/
struct MUIS_TheBar_Brush
{
    APTR  data;             /* Source data - actually it may be only a UBYTE *            */
    UWORD dataWidth;        /* Width of data                                              */
    UWORD dataHeight;       /* Height of data                                             */
    UWORD dataTotalWidth;   /* Total width of data                                        */
    UWORD left;             /* Left offset in data of this brush                          */
    UWORD top;              /* Top offset in data of this brush                           */
    UWORD width;            /* Width of this brush                                        */
    UWORD height;           /* Height of this brush                                       */
    ULONG *colors;          /* R,G,B or 0x00RRGGBB ULONG table                            */
    ULONG numColors;        /* Number of colors in colors                                 */
    ULONG trColor;          /* Transparent color number; 0<=trColor<256 !                 */
    ULONG compressedSize;   /* If data is byte run 1 compressed, it is its POSITIVE size  */
    ULONG flags;            /* As it says                                                 */
    ULONG reserved[4];      /* Avoid recompilation                                        */
};

enum
{
    BRFLG_ARGB      = 1<<0,
    BRFLG_AlphaMask = 1<<1,
    BRFLG_ColorRGB8 = 1<<2,
};

/*
** MUIA_TheButton_Strip is a pointer to this.
**/
struct MUIS_TheBar_Strip
{
    struct BitMap *normalBM;    /* Normal BitMap        */
    struct BitMap *greyBM;      /* Grey normal BitMap   */
    struct BitMap *mask;        /* Normal mask          */

    struct BitMap *snormalBM;   /* Selected BitMap      */
    struct BitMap *sgreyBM;     /* Selected grey BitMap */
    struct BitMap *smask;       /* Selected mask        */

    struct BitMap *dnormalBM;   /* Disabled BitMap      */
    struct BitMap *dgreyBM;     /* Grey disabled BitMap */
    struct BitMap *dmask;       /* Grey mask            */

    UBYTE	  *nchunky;
    UBYTE	  *gchunky;
    UBYTE         *snchunky;
    UBYTE         *sgchunky;
    UBYTE         *dnchunky;
    UBYTE	  *dgchunky;
};


/*
** MUIA_TheBar_Buttons is an array of this.
*/
struct MUIS_TheBar_Button
{
    ULONG         img;     /* Image index                                          */
    ULONG         ID;      /* Button ID                                            */
    STRPTR        text;    /* Button label (max TB_MAXLABELLEN) not copied!        */
    STRPTR        help;    /* Button help not copied!                              */
    ULONG         flags;   /* See below                                            */
    ULONG         exclude; /* Exclude mask                                         */
    struct IClass *class;  /* Easy way of getting a bar of subclassed buttons      */
    Object        *obj;    /* Filled when the button is created                    */
};

/* flags */
enum
{
    MUIV_TheBar_ButtonFlag_NoClick   = 1<<0, /* v11 MUIA_InputMode is MUIV_InputMode_None      */
    MUIV_TheBar_ButtonFlag_Immediate = 1<<1, /* v11 MUIA_InputMode is MUIV_InputMode_Immediate */
    MUIV_TheBar_ButtonFlag_Toggle    = 1<<2, /* v11 MUIA_InputMode is MUIV_InputMode_Toggle    */
    MUIV_TheBar_ButtonFlag_Disabled  = 1<<3, /* v11 MUIA_Disabled is TRUE                      */
    MUIV_TheBar_ButtonFlag_Selected  = 1<<4, /* v11 MUIA_Selected is TRUE                      */
    MUIV_TheBar_ButtonFlag_Sleep     = 1<<5, /* v11 MUIA_ShowMe is FALSE                       */
    MUIV_TheBar_ButtonFlag_Hide      = 1<<6, /* v11 MUIA_ShowMe is FALSE                       */
};

/* Special img values */
#define MUIV_TheBar_End            ((ULONG)-1) /* v11 Ends a MUIS_TheBar_Button array    */
#define MUIV_TheBar_BarSpacer      ((ULONG)-2) /* v11 Add a spacer                       */
#define MUIV_TheBar_ButtonSpacer   ((ULONG)-3) /* v11 Add a space spacer                 */
#define MUIV_TheBar_ImageSpacer    ((ULONG)-4) /* v11 Add an image  spacer               */

/* Returned by MUIM_TheBar_GetDragImage */
struct MUIS_TheBar_DragImage
{
    ULONG                width;
    ULONG                height;
    struct BitMap        *bitMap;
    struct MUI_DragImage *di;       /* Defined in MUIundoc.h */
    ULONG                dummy[8];  /* Avoid recompilation   */
};

/* MUIA_TheBar_Appareance */
struct MUIS_TheBar_Appareance
{
    ULONG viewMode;
    ULONG labelPos;
    ULONG dummy[2];
};

/* flags */
enum
{
    MUIV_TheBar_Appareance_Borderless = 1<<0,
    MUIV_TheBar_Appareance_Raised     = 1<<1,
    MUIV_TheBar_Appareance_Sunny      = 1<<2,
    MUIV_TheBar_Appareance_Scaled     = 1<<3,
    MUIV_TheBar_Appareance_BarSpacer  = 1<<4,
};

/***********************************************************************/

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack()
  #elif defined(__VBCC__)
    #pragma default-align
  #endif
#endif

#endif /* THEBAR_MCC_H */
