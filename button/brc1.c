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

#define DUMP     0
#define RUN      1
#define MINRUN   3
#define MAXRUN 128
#define MAXDAT 128

/***********************************************************************/

USHORT
BRCUnpack(signed char *pSource,signed char *pDest,LONG srcBytes0,LONG dstBytes0)
{
    register signed char *source = pSource, *dest = pDest, c;
    register SHORT  n;
    register LONG   srcBytes = srcBytes0, dstBytes = dstBytes0;
    USHORT          error = TRUE;

    while(dstBytes>0)
    {
        if ((srcBytes-=1)<0)
        {
            goto errorExit;
        }

        n = *source++;

        if (n>=0)
        {
            n += 1;

            if ((srcBytes -= n)<0)
            {
            	goto errorExit;
            }

            if ((dstBytes -= n)<0)
            {
            	goto errorExit;
            }

            do { *dest++ = *source++;} while(--n>0);
        }
        else
            if (n!=-128)
            {
                n = -n+1;
                if ((srcBytes -= 1)<0)
                {
                    goto errorExit;
                }

                if ((dstBytes -= n)<0)
                {
                    goto errorExit;
                }

                c = *source++;

                do
                {
                    *dest++ = c;
                } while(--n>0);
            }
    }

    error = FALSE;

    errorExit:

    return error;
}

/***********************************************************************/
