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
#include <stdlib.h>

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
        case 0:  return (ULONG)lib_class;
        default: return 0;
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

    if (DataTypesBase)
    {
        CloseLibrary(DataTypesBase);
        DataTypesBase = NULL;
    }

    if (DiskfontBase)
    {
        CloseLibrary(DiskfontBase);
        DiskfontBase = NULL;
    }

    if (GfxBase)
    {
        CloseLibrary((struct Library *)GfxBase);
        GfxBase = NULL;
    }

    if (MUIMasterBase)
    {
        if (lib_class)
        {
            MUI_DeleteCustomClass(lib_class);
            lib_class = NULL;
        }

        CloseLibrary(MUIMasterBase);
        MUIMasterBase = NULL;
    }

    if (lib_pool)
    {
        DeletePool(lib_pool);
        lib_pool = NULL;
    }

    lib_flags &= ~(BASEFLG_Init|BASEFLG_MUI20|BASEFLG_MUI4);
}

/***********************************************************************/

ULONG
initBase(void)
{
    if ((lib_pool      = CreatePool(MEMF_ANY,2048,1024)) &&
        (MUIMasterBase = OpenLibrary("muimaster.library",19)) &&
        (GfxBase       = (struct GfxBase *)OpenLibrary("graphics.library",40)) &&
        (DiskfontBase  = OpenLibrary("diskfont.library",37)) &&
        (DataTypesBase = OpenLibrary("datatypes.library",37)) &&
        initMCC())
    {
        REGARRAY UBYTE buf[16];

        DOSBase       = (struct DosLibrary *)lib_class->mcc_DOSBase;
        UtilityBase   = lib_class->mcc_UtilityBase;
        IntuitionBase = (struct IntuitionBase *)lib_class->mcc_IntuitionBase;

        if (MUIMasterBase->lib_Version>=MUIVER20)
        {
            lib_flags |= BASEFLG_MUI20;

            if (MUIMasterBase->lib_Version>MUIVER20 || MUIMasterBase->lib_Revision>=5341)
                lib_flags |= BASEFLG_MUI4;
        }

        CyberGfxBase = OpenLibrary("cybergraphics.library",41);

        if (GetVar("MUI/TheBarAlpha",buf,sizeof(buf),GVF_GLOBAL_ONLY)>0)
	    lib_alpha = strtoul(buf,NULL,16);
        else lib_alpha = 0xffffffff;

        lib_flags |= BASEFLG_Init;

        return TRUE;
    }

    freeBase();

    return FALSE;
}

/***********************************************************************/

