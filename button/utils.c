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

/***********************************************************************/

#ifndef __MORPHOS__
ULONG STDARGS
DoSuperNew(struct IClass *cl,Object *obj,ULONG tag1,...)
{
    return DoSuperMethod(cl,obj,OM_NEW,&tag1,NULL);
}
#endif

/***********************************************************************/

void
stripUnderscore(STRPTR dest,STRPTR from,ULONG mode)
{
    register ULONG done = 0;
    register int   i = TB_MAXLABELLEN;

    while (*from && --i)
    {
        if (*from=='_')
        {
            if (done)
            {
                if (mode==STRIP_First) *dest++ = *from;
            }
            else done = 1;
        }
        else *dest++ = *from;

        from++;
    }

    *dest = '\0';
}

/***********************************************************************/

struct TextFont *
openFont(STRPTR name)
{
    REGARRAY UBYTE buf[256];
    register STRPTR t, s;
    struct TextAttr ta;
    long            ys;

    strcpy(buf,name);

    if (t = strchr(buf,'/'))
    {
        *t++ = 0;
        if (!stcd_l(t,&ys) || ys<=0) ys = 8;
    }
    else ys = 8;

    for (s = NULL, t = buf; *t; t++) if (*t=='.') s = t;
    if (!s || stricmp(++s,"font")) strcat(buf,".font");

    ta.ta_Name  = buf;
    ta.ta_YSize = ys;
    ta.ta_Style = 0;
    ta.ta_Flags = 0;

    return OpenDiskFont(&ta);
}

/***********************************************************************/

APTR
allocVecPooled(APTR pool,ULONG size)
{
    register ULONG *mem;

    if (mem = AllocPooled(pool,size = size+sizeof(ULONG)))
        *mem++ = size;

    return mem;
}

/****************************************************************************/

void
freeVecPooled(APTR pool,APTR mem)
{
    FreePooled(pool,(LONG *)mem-1,*((LONG *)mem-1));
}

/****************************************************************************/

APTR
allocArbitratePooled(ULONG size)
{
    register APTR mem;

    ObtainSemaphore(&lib_poolSem);
    mem = AllocPooled(lib_pool,size);
    ReleaseSemaphore(&lib_poolSem);

    return mem;
}

/***********************************************************************/

APTR
freeArbitratePooled(APTR mem,ULONG size)
{
    ObtainSemaphore(&lib_poolSem);
    FreePooled(lib_pool,mem,size);
    ReleaseSemaphore(&lib_poolSem);

    return mem;
}

/***********************************************************************/

APTR
allocArbitrateVecPooled(ULONG size)
{
    register APTR mem;

    ObtainSemaphore(&lib_poolSem);
    mem = allocVecPooled(lib_pool,size);
    ReleaseSemaphore(&lib_poolSem);

    return mem;
}

/***********************************************************************/

APTR
freeArbitrateVecPooled(APTR mem)
{
    ObtainSemaphore(&lib_poolSem);
    freeVecPooled(lib_pool,mem);
    ReleaseSemaphore(&lib_poolSem);

    return mem;
}

/***********************************************************************/

