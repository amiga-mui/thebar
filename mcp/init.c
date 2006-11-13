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

#include "class.h"
#define USE_THEBAR_BODY
#define USE_THEBAR_COLORS
#include "TheBar_iff.h"

/***********************************************************************/

enum
{
    MUIV_Query_MCC,
    MUIV_Query_MCP,
    MUIV_Query_MCPImage,
    MUIV_Query_OnlyGlobal,
    MUIV_Query_InfoClass,
    MUIV_Query_UsedClasses,
    MUIV_Query_UsedClassesP,
    MUIV_Query_ShortHelp,
};

/***********************************************************************/

#ifdef __MORPHOS__
ULONG query(void)
#else
ULONG SAVEDS ASM query(REG(d0,LONG which))
#endif
{
#ifdef __MORPHOS__
    LONG which = REG_D0;
#endif

    switch (which)
    {
        case MUIV_Query_MCP:
            return (ULONG)lib_class;

        case MUIV_Query_MCPImage:
            return (ULONG)BodychunkObject,
                MUIA_FixWidth,              THEBAR_WIDTH,
                MUIA_FixHeight,             THEBAR_HEIGHT,
                MUIA_Bitmap_Width,          THEBAR_WIDTH,
                MUIA_Bitmap_Height,         THEBAR_HEIGHT,
                MUIA_Bodychunk_Depth,       THEBAR_DEPTH,
                MUIA_Bodychunk_Body,        TheBar_body,
                MUIA_Bodychunk_Compression, THEBAR_COMPRESSION,
                MUIA_Bodychunk_Masking,     THEBAR_MASKING,
                MUIA_Bitmap_SourceColors,   TheBar_colors,
                MUIA_Bitmap_Transparent,    0,
            End;

        case MUIV_Query_ShortHelp:
            return (ULONG)getString(Msg_PrefsShortHelp);

        default:
            return 0;
    }
}

/****************************************************************************/

void
freeBase(void)
{
    if (CyberGfxBase)
    {
        CloseLibrary(CyberGfxBase);
        CyberGfxBase = NULL;
    }

    if (MUIMasterBase)
    {
#ifndef __MORPHOS__
        freeColoradjust();
        freePenadjust();
        freeBackgroundadjust();
        freePoppen();
        freePopbackground();
#endif
        freeMCP();
    }

    if (LocaleBase)
    {
        if (lib_cat)
        {
            CloseCatalog(lib_cat);
            lib_cat = NULL;
        }

        CloseLibrary((struct Library *)LocaleBase);
        LocaleBase = NULL;
    }

    if (IFFParseBase)
    {
        CloseLibrary((struct Library *)IFFParseBase);
        IFFParseBase = NULL;
    }

    if (DataTypesBase)
    {
        CloseLibrary(DataTypesBase);
        DataTypesBase = NULL;
    }

    if (GfxBase)
    {
        CloseLibrary((struct Library *)GfxBase);
        GfxBase = NULL;
    }

    lib_flags &= ~(BASEFLG_Init|BASEFLG_MUI20|BASEFLG_MUI4);
}

/***********************************************************************/

ULONG
initBase(void)
{
    if ((GfxBase       = (struct GfxBase *)OpenLibrary("graphics.library",40)) &&
        (DataTypesBase = OpenLibrary("datatypes.library",37)) &&
        (IFFParseBase = OpenLibrary("iffparse.library",37)) &&
        (MUIMasterBase = OpenLibrary("muimaster.library",19)))
    {
        if (MUIMasterBase->lib_Version>=MUIVER20)
        {
            lib_flags |= BASEFLG_MUI20;
            if (MUIMasterBase->lib_Revision>=5341) lib_flags |= BASEFLG_MUI4;
        }

        initStrings();

        #ifdef __MORPHOS__
        if (initMCP())
        #else
        if (initMCP() &&
            ((lib_flags & BASEFLG_MUI20) || (initColoradjust() && initPenadjust() && initBackgroundadjust() && initPoppen() && initPopbackground())))
        #endif
        {
            DOSBase       = (struct DosLibrary *)lib_class->mcc_DOSBase;
            UtilityBase   = lib_class->mcc_UtilityBase;
            IntuitionBase = (struct IntuitionBase *)lib_class->mcc_IntuitionBase;

            CyberGfxBase = OpenLibrary("cybergraphics.library",41);

            lib_flags |= BASEFLG_Init;

            return TRUE;
        }
    }

    freeBase();

    return FALSE;
}

/***********************************************************************/

