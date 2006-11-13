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

#include <math.h>
#if !defined(_FFP)
void __stdargs _CXFERR(int code) {}
#endif
double __except(int a,const char *b,double c,double e,double f) { return f; }


/***********************************************************************/

struct ScaleData
{
    APTR  data;
    LONG  cy;
    FLOAT sourcey;
    FLOAT deltax;
    FLOAT deltay;
};

/***********************************************************************/

static void
scaleLine(struct scale *sce,struct ScaleData *data,UBYTE *src,UBYTE *dst)
{
    LONG w8 = (sce->dw>>3)+1, cx = 0, dx = data->deltax*65536;

    src += data->cy*sce->sw;

    switch (sce->dw & 7)
    {
        do
        {
            *dst++ = src[cx>>16];         cx += dx;
            case 7: *dst++ = src[cx>>16]; cx += dx;
            case 6: *dst++ = src[cx>>16]; cx += dx;
            case 5: *dst++ = src[cx>>16]; cx += dx;
            case 4: *dst++ = src[cx>>16]; cx += dx;
            case 3: *dst++ = src[cx>>16]; cx += dx;
            case 2: *dst++ = src[cx>>16]; cx += dx;
            case 1: *dst++ = src[cx>>16]; cx += dx;
            case 0: w8--;

        } while (w8);
    }

    data->cy = data->sourcey += data->deltay;
}

/***********************************************************************/

void
scale(struct scale *sce,UBYTE *src,UBYTE *dst)
{
    if (sce && src && dst)
    {
        struct ScaleData scdata;
        LONG             y;

        scdata.cy      = 0;
        scdata.sourcey = 0;

        scdata.deltax  = sce->sw - 1;
        scdata.deltax  /= (sce->dw - 1);

        scdata.deltay  = sce->sh - 1;
        scdata.deltay  /= (sce->dh - 1);

        for (y = 0; y<sce->dh; ++y)
        {
            scaleLine(sce,&scdata,src,dst);
            dst += sce->dw;
        }
    }
}

/***********************************************************************/
