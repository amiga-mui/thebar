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
#include <proto/input.h>

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

#if !defined(__amigaos4__)
/***********************************************************************/

// own strlcpy/strlcat are only required for classic OS3 compiles and also
// only when libnix is used. clib2 and the newer libnix of MorphOS already
// has those functions.
#if !defined(__amigaos4__) && !defined(__MORPHOS__) && !defined(__AROS__) && defined(__libnix__)

size_t
strlcpy(char *dst, const char *src, size_t siz)
{
        char *d = dst;
        const char *s = src;
        size_t n = siz;

        /* Copy as many bytes as will fit */
        if (n != 0) {
                while (--n != 0) {
                        if ((*d++ = *s++) == '\0')
                                break;
                }
        }

        /* Not enough room in dst, add NUL and traverse rest of src */
        if (n == 0) {
                if (siz != 0)
                        *d = '\0';                /* NUL-terminate dst */
                while (*s++)
                        ;
        }

        return(s - src - 1);        /* count does not include NUL */
}
#endif

#if !defined(__amigaos4__)
size_t
strlcat(char *dst, const char *src, size_t siz)
{
        char *d = dst;
        const char *s = src;
        size_t n = siz;
        size_t dlen;

        /* Find the end of dst and adjust bytes left but don't go past end */
        while (n-- != 0 && *d != '\0')
                d++;
        dlen = d - dst;
        n = siz - dlen;

        if (n == 0)
                return(dlen + strlen(s));
        while (*s != '\0') {
                if (n != 1) {
                        *d++ = *s;
                        n--;
                }
                s++;
        }
        *d = '\0';

        return(dlen + (s - src));        /* count does not include NUL */
}
#endif

#endif

/***********************************************************************/

void stripUnderscore(STRPTR dest, STRPTR from, ULONG mode)
{
  BOOL done = FALSE;
  int i = TB_MAXLABELLEN;

  ENTER();

  while(*from != '\0' && --i)
  {
    if(*from == '_')
    {
      if(done)
      {
        if (mode == STRIP_First)
          *dest++ = *from;
      }
      else
        done = TRUE;
    }
    else
      *dest++ = *from;

    from++;
  }

  *dest = '\0';

  LEAVE();
}

/***********************************************************************/

#if !defined(__MORPHOS__) && !defined(__AROS__)

static int stcd_l(const char *in, long *value)
{
  ENTER();

  if(in)
  {
    char *ptr;

    switch(*in)
    {
      case '+':
      case '-':
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      {
        int ret;

        *value = strtol(in, &ptr, 10);
        ret = ptr-in;

        RETURN(ret);
        return ret;
      }
      break;
    }
  }

  *value = 0;

  RETURN(0);
  return 0;
}

#endif

/***********************************************************************/

struct TextFont *openFont(STRPTR name)
{
  char buf[256];
  STRPTR t, s;
  struct TextAttr ta;
  long ys;
  struct TextFont *font;

  ENTER();

  strlcpy(buf, name, sizeof(buf));

  SHOWSTRING(DBF_GUI, buf);

  if((t = strchr(buf,'/')) != NULL)
  {
    *t++ = 0;
    if(!stcd_l(t,&ys) || ys<=0)
      ys = 8;
  }
  else
    ys = 8;

  for(s = NULL, t = buf; *t; t++)
    if(*t == '.')
      s = t;
  if(s == NULL || stricmp(++s, "font"))
    strlcat(buf, ".font", sizeof(buf));

  SHOWSTRING(DBF_GUI, buf);

  memset(&ta, 0, sizeof(ta));
  ta.ta_Name  = buf;
  ta.ta_YSize = ys;
  ta.ta_Style = 0;
  ta.ta_Flags = 0;

  font = OpenDiskFont(&ta);

  RETURN(font);
  return font;
}

/***********************************************************************/
static APTR sharedPool;
#if !defined(__amigaos4__) && !defined(__MORPHOS__)
struct SignalSemaphore sharedPoolSema;
#endif

BOOL CreateSharedPool(void)
{
  BOOL success = FALSE;

  ENTER();

  #if defined(__amigaos4__)
  sharedPool = AllocSysObjectTags(ASOT_MEMPOOL, ASOPOOL_MFlags, MEMF_SHARED,
                                                ASOPOOL_Puddle, 2048,
                                                ASOPOOL_Threshold, 1024,
                                                ASOPOOL_Name, "TheButton.mcc shared pool",
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
#if defined(__amigaos4__) || defined(__MORPHOS__)
  return AllocVecPooled(sharedPool, size);
#else
  ULONG *mem;

  ENTER();

  size += sizeof(ULONG);

  ObtainSemaphore(&sharedPoolSema);

  if((mem = AllocPooled(sharedPool, size)) != NULL)
      *mem++ = size;

  ReleaseSemaphore(&sharedPoolSema);

  RETURN(mem);
  return mem;
#endif
}

/****************************************************************************/

void SharedFree(APTR mem)
{
#if defined(__amigaos4__) || defined(__MORPHOS__)
  FreeVecPooled(sharedPool, mem);
#else
  ENTER();

  ObtainSemaphore(&sharedPoolSema);

  FreePooled(sharedPool, (LONG *)mem-1, *((LONG *)mem-1));

  ReleaseSemaphore(&sharedPoolSema);

  LEAVE();
#endif
}

/***********************************************************************/

ULONG peekQualifier(void)
{
  ULONG rc = 0;
  struct MsgPort *port;

  ENTER();

  #if defined(__amigaos4__)
  if((port = AllocSysObject(ASOT_PORT, TAG_DONE)) != NULL)
  #else
  if((port = CreateMsgPort()) != NULL)
  #endif
  {
    struct IOStdReq *iorequest;

    #if defined(__amigaos4__)
    if((iorequest = AllocSysObjectTags(ASOT_IOREQUEST, ASOIOR_ReplyPort, port,
                                                       ASOIOR_Size, sizeof(*iorequest),
                                                       TAG_DONE)) != NULL)
    #else
    if((iorequest = (struct IOStdReq *)CreateIORequest(port, sizeof(*iorequest))) != NULL)
    #endif
    {
      if(OpenDevice("input.device", 0, (struct IORequest*)iorequest, 0) == 0)
      {
        struct Library *InputBase = (struct Library *)iorequest->io_Device;
        #ifdef __amigaos4__
        struct InputIFace *IInput;
        GETINTERFACE(IInput, InputBase);
        #endif
        rc = PeekQualifier();

        DROPINTERFACE(IInput);
        CloseDevice((struct IORequest*)iorequest);
      }

      #if defined(__amigaos4__)
      FreeSysObject(ASOT_IOREQUEST, iorequest);
      #else
      DeleteIORequest((struct IORequest *)iorequest);
      #endif
    }

    #if defined(__amigaos4__)
    FreeSysObject(ASOT_PORT, port);
    #else
    DeleteMsgPort(port);
    #endif
  }

  RETURN(rc);
  return(rc);
}

/***********************************************************************/

