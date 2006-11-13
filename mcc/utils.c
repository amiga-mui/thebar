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

LONG
xget(Object *obj,ULONG attribute)
{
    LONG x;

    return get(obj,attribute,&x) ? x : 0;
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

#ifdef __MORPHOS__
int
min(int a,int b)
{
    return (a>=b) ? b :a;
}
#endif

/****************************************************************************/

#ifdef __MORPHOS__
int
max(int a,int b)
{
    return (a>=b) ? a :b;
}
#endif

/****************************************************************************/

