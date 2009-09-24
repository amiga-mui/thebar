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
static APTR sharedPool;
#if !defined(__amigaos4__) && !defined(__MORPHOS__)
static struct SignalSemaphore sharedPoolSema;
#endif

BOOL CreateSharedPool(void)
{
  BOOL success = FALSE;

  ENTER();

  #if defined(__amigaos4__)
  sharedPool = AllocSysObjectTags(ASOT_MEMPOOL, ASOPOOL_MFlags, MEMF_SHARED,
                                                ASOPOOL_Puddle, 2048,
                                                ASOPOOL_Threshold, 1024,
                                                #if defined(VIRTUAL)
                                                ASOPOOL_Name, "TheBarVirt.mcc shared pool",
                                                #else
                                                ASOPOOL_Name, "TheBar.mcc shared pool",
                                                #endif
                                                ASOPOOL_Protected, TRUE,
                                                TAG_DONE);
  #elif defined(__MORPHOS__)
  sharedPool = CreatePool(MEMF_SEM_PROTECTED, 2048, 1024);
  #else
  sharedPool = CreatePool(MEMF_ANY, 2048, 1024);
  InitSemaphore(&sharedPoolSema);
  #endif

  if(sharedPool != NULL)
    success = TRUE;

  RETURN(success);
  return(success);
}

void DeleteSharedPool(void)
{
  ENTER();

  if(sharedPool != NULL)
  {
    #if defined(__amigaos4__)
    FreeSysObject(ASOT_MEMPOOL, sharedPool);
    #else
    DeletePool(sharedPool);
    #endif

    sharedPool = NULL;
  }
}
APTR SharedAlloc(ULONG size)
{
  ULONG *mem;

  ENTER();

  size += sizeof(ULONG);

  #if !defined(__amigaos4__) && !defined(__MORPHOS__)
  ObtainSemaphore(&sharedPoolSema);
  #endif

  if((mem = AllocPooled(sharedPool, size)) != NULL)
    *mem++ = size;

  #if !defined(__amigaos4__) && !defined(__MORPHOS__)
  ReleaseSemaphore(&sharedPoolSema);
  #endif

  RETURN(mem);
  return mem;
}

/****************************************************************************/

void SharedFree(APTR mem)
{
  ENTER();

  if(mem != NULL)
  {
    ULONG *_mem = (ULONG *)mem;

    #if !defined(__amigaos4__) && !defined(__MORPHOS__)
    ObtainSemaphore(&sharedPoolSema);
    #endif

    FreePooled(sharedPool, &_mem[-1], _mem[-1]);

    #if !defined(__amigaos4__) && !defined(__MORPHOS__)
    ReleaseSemaphore(&sharedPoolSema);
    #endif
  }

  LEAVE();
}

/****************************************************************************/

APTR SharedRealloc(APTR mem, ULONG size)
{
  APTR newmem = NULL;

  ENTER();

  if(sharedPool != NULL && size != 0)
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
        SharedFree(mem);
      }
    }

    // ...and allocate a new one
    newmem = SharedAlloc(size);
  }

  RETURN(newmem);
  return newmem;
}

/****************************************************************************/
