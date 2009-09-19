/***************************************************************************

 TheBar.mcc - Next Generation Toolbar MUI Custom Class
 Copyright (C) 2003-2005 Alfonso Ranieri
 Copyright (C) 2005-2009 by TheBar.mcc Open Source Team

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

/***********************************************************************/

// DoSuperNew()
// Calls parent NEW method within a subclass
#ifdef __MORPHOS__

#elif defined(__AROS__)
IPTR DoSuperNew(struct IClass *cl, Object *obj, IPTR tag1, ...)
{
  AROS_SLOWSTACKTAGS_PRE(tag1)
  retval = DoSuperMethod(cl, obj, OM_NEW, AROS_SLOWSTACKTAGS_ARG(tag1));
  AROS_SLOWSTACKTAGS_POST
}
#else
Object * VARARGS68K DoSuperNew(struct IClass *cl, Object *obj, ...)
{
  Object *rc;
  VA_LIST args;

  VA_START(args, obj);
  rc = (Object *)DoSuperMethod(cl, obj, OM_NEW, VA_ARG(args, ULONG), NULL);
  VA_END(args);

  return rc;
}
#endif

/***********************************************************************/
static APTR pool;
#if !defined(__amigaos4__) && !defined(__MORPHOS__)
static struct SignalSemaphore poolSema;
#endif

BOOL myCreatePool(void)
{
  BOOL success = FALSE;

  ENTER();

  #if defined(__amigaos4__)
  pool = AllocSysObjectTags(ASOT_MEMPOOL, ASOPOOL_MFlags, MEMF_SHARED,
                                          ASOPOOL_Puddle, 2048,
                                          ASOPOOL_Threshold, 1024,
                                          #if defined(VIRTUAL)
                                          ASOPOOL_Name, "TheBarVirt.mcc pool",
                                          #else
                                          ASOPOOL_Name, "TheBar.mcc pool",
                                          #endif
                                          TAG_DONE);
  #elif defined(__MORPHOS__)
  pool = CreatePool(MEMF_SEM_PROTECTED, 2048, 1024);
  #else
  pool = CreatePool(MEMF_ANY, 2048, 1024);
  InitSemaphore(&poolSema);
  #endif

  if(pool != NULL)
    success = TRUE;

  RETURN(success);
  return(success);
}

void myDeletePool(void)
{
  ENTER();

  if(pool != NULL)
  {
    #if defined(__amigaos4__)
    FreeSysObject(ASOT_MEMPOOL, pool);
    #else
    DeletePool(pool);
    #endif

    pool = NULL;
  }
}
APTR allocVecPooled(ULONG size)
{
  ULONG *mem;

  ENTER();

  size += sizeof(ULONG);

  #if !defined(__amigaos4__) && !defined(__MORPHOS__)
  ObtainSemaphore(&poolSema);
  #endif

  if((mem = AllocPooled(pool, size)) != NULL)
    *mem++ = size;

  #if !defined(__amigaos4__) && !defined(__MORPHOS__)
  ReleaseSemaphore(&poolSema);
  #endif

  RETURN(mem);
  return mem;
}

/****************************************************************************/

void freeVecPooled(APTR mem)
{
  ENTER();

  if(mem != NULL)
  {
    ULONG *_mem = (ULONG *)mem;

    #if !defined(__amigaos4__) && !defined(__MORPHOS__)
    ObtainSemaphore(&poolSema);
    #endif

    FreePooled(pool, &_mem[-1], _mem[-1]);

    #if !defined(__amigaos4__) && !defined(__MORPHOS__)
    ReleaseSemaphore(&poolSema);
    #endif
  }

  LEAVE();
}

/****************************************************************************/

APTR reallocVecPooledNC(APTR mem, ULONG size)
{
  APTR newmem = NULL;

  ENTER();

  if(pool != NULL && size != 0)
  {
    if(mem != NULL)
    {
      ULONG *_mem = (ULONG *)mem;

      if(_mem[-1] - sizeof(ULONG) >= size)
      {
        // the previous allocation has at least the size of the
        // new required space, so we just return the old memory block
        RETURN(mem);
        return(mem);
      }
      else
      {
        // free the old block...
        freeVecPooled(mem);
      }
    }

    // ...and allocate a new one
    newmem = allocVecPooled(size);
  }

  RETURN(newmem);
  return newmem;
}

/****************************************************************************/
