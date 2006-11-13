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

Object *
olabel(ULONG id)
{
    return Label((ULONG)getString(id));
}

/****************************************************************************/

Object *
olabel1(ULONG id)
{
    return Label1((ULONG)getString(id));
}

/****************************************************************************/

Object *
ollabel1(ULONG id)
{
    return LLabel1((ULONG)getString(id));
}

/***********************************************************************/

Object *
olabel2(ULONG id)
{
    return Label2((ULONG)getString(id));
}

/***********************************************************************/

Object *
oflabel(ULONG id)
{
    return FreeLabel((ULONG)getString(id));
}

/***********************************************************************/

Object *
oclabel(ULONG id)
{
    return CLabel((ULONG)getString(id));
}

/***********************************************************************/

Object *
owspace(ULONG weight)
{
    return RectangleObject, MUIA_Weight, weight, End;
}

/***********************************************************************/

Object *
ofhspace(STRPTR string)
{
    return RectangleObject, MUIA_FixHeightTxt, string, End;
}

/***********************************************************************/

Object *
obutton(ULONG text,ULONG help)
{
    register Object *obj;

    if (obj = MUI_MakeObject(MUIO_Button,(ULONG)getString(text)))
        SetAttrs(obj,MUIA_CycleChain,TRUE,MUIA_ShortHelp,(ULONG)getString(help),TAG_DONE);

    return obj;
}

/***********************************************************************/

Object *
ocycle(STRPTR *array,ULONG key,ULONG help)
{
    Object *obj;

    if (obj = MUI_MakeObject(MUIO_Cycle,(ULONG)getString(key),(ULONG)array))
        SetAttrs(obj,MUIA_CycleChain,TRUE,MUIA_ShortHelp,(ULONG)getString(help),TAG_DONE);

    return obj;
}

/***********************************************************************/

Object *
ocheck(ULONG key,ULONG help)
{
    register Object *obj;

    if (obj = MUI_MakeObject(MUIO_Checkmark,(ULONG)getString(key)))
        SetAttrs(obj,MUIA_CycleChain,TRUE,MUIA_ShortHelp,(ULONG)getString(help),TAG_DONE);

    return obj;
}

/***********************************************************************/

Object *
oslider(ULONG key,ULONG help,LONG min,LONG max)
{
    register Object *obj;

    if (obj = MUI_MakeObject(MUIO_Slider,(ULONG)getString(key),min,max))
        SetAttrs(obj,MUIA_CycleChain,TRUE,MUIA_ShortHelp,(ULONG)getString(help),TAG_DONE);

    return obj;
}

/***********************************************************************/

Object *
opop(ULONG type,ULONG key)
{
    register Object *obj;

    if (!(lib_flags & BASEFLG_MUI4) && (type==MUII_PopFont))
        type = MUII_PopUp;

    if (obj = MUI_MakeObject(MUIO_PopButton,type))
    {
        set(obj,MUIA_CycleChain,TRUE);

        if (key)
        {
            ULONG k;

            if (k = getKeyChar(getString(key)))
                set(obj,MUIA_ControlChar,ToLower(k));
        }
    }

    return obj;
}

/***********************************************************************/

Object *
opoppen(ULONG key,ULONG title,ULONG help)
{
    #ifdef __MORPHOS__
    return PoppenObject,
        MUIA_Window_Title, (ULONG)getString(title),
        MUIA_ControlChar,  (ULONG)getKeyChar(getString(key)),
        MUIA_Draggable,    TRUE,
        MUIA_CycleChain,   TRUE,
        MUIA_ShortHelp,    (ULONG)getString(help),
    End;
    #else
    if (lib_flags & BASEFLG_MUI20)
    {
        return PoppenObject,
            MUIA_Window_Title, (ULONG)getString(title),
            MUIA_ControlChar,  (ULONG)getKeyChar(getString(key)),
            MUIA_Draggable,    TRUE,
            MUIA_CycleChain,   TRUE,
            MUIA_ShortHelp,    (ULONG)getString(help),
        End;
    }
    else
    {
        return poppenObject,
            MUIA_Window_Title, (ULONG)getString(title),
            MUIA_ControlChar,  (ULONG)getKeyChar(getString(key)),
            MUIA_Draggable,    TRUE,
            MUIA_CycleChain,   TRUE,
            MUIA_ShortHelp,    (ULONG)getString(help),
        End;
    }
    #endif
}

/***********************************************************************/

Object *
opopfri(ULONG key,ULONG title,ULONG help)
{
    return MUI_NewObject("Popfrimage.mui",
        MUIA_Window_Title,     (ULONG)getString(title),
        MUIA_ControlChar,      (ULONG)getKeyChar(getString(key)),
        MUIA_CycleChain,       TRUE,
        MUIA_ShortHelp,        (ULONG)getString(help),
        0x80421794, 0,
        0x8042a547, 0,
        0x80426a55, 1,
        0x8042a92b, 0,
    End;
}

/***********************************************************************/

Object *
opopback(ULONG gradient,ULONG key,ULONG title,ULONG help)
{
    #ifdef __MORPHOS__
    return MUI_NewObject(MUIC_Popimage,
        MUIA_Imageadjust_Type, MUIV_Imageadjust_Type_Background,
        MUIA_Window_Title,     (ULONG)getString(title),
        MUIA_ControlChar,      (ULONG)getKeyChar(getString(key)),
        MUIA_Draggable,        TRUE,
        MUIA_CycleChain,       TRUE,
        MUIA_ShortHelp,        (ULONG)getString(help),
    End;
    #else
    if (lib_flags & BASEFLG_MUI20)
    {
        return MUI_NewObject(MUIC_Popimage,
            MUIA_Imageadjust_Type, MUIV_Imageadjust_Type_Background,
            MUIA_Window_Title,     (ULONG)getString(title),
            MUIA_ControlChar,      (ULONG)getKeyChar(getString(key)),
            MUIA_Draggable,        TRUE,
            MUIA_CycleChain,       TRUE,
            MUIA_ShortHelp,        (ULONG)getString(help),
        End;
    }
    else
    {
        return popbackObject,
            MUIA_Window_Title,           (ULONG)getString(title),
            MUIA_ControlChar,            (ULONG)getKeyChar(getString(key)),
            MUIA_Draggable,              TRUE,
            MUIA_CycleChain,             TRUE,
            MUIA_ShortHelp,              (ULONG)getString(help),
            MUIA_Popbackground_Gradient, gradient,
        End;
    }
    #endif
}

/***********************************************************************/

#ifndef PopframeObject
#define PopframeObject MUI_NewObject(MUIC_Popframe
#endif

Object *
opopframe(ULONG key,ULONG title,ULONG help)
{
    return PopframeObject,
        MUIA_Window_Title, (ULONG)getString(title),
        MUIA_Draggable,    TRUE,
        MUIA_CycleChain,   1,
	    MUIA_ShortHelp,    (ULONG)getString(help),
	    MUIA_ControlChar,  (ULONG)getKeyChar(getString(key)),
    End;
}

/***********************************************************************/

#ifndef __MORPHOS__
static UWORD fmtfunc[] = { 0x16c0, 0x4e75 };
void
sprintf(char *to,char *fmt,...)
{
    RawDoFmt(fmt,&fmt+1,(APTR)fmtfunc,to);
}
#endif

/***********************************************************************/

struct stream
{
    char    *buf;
    int     size;
    int     counter;
    int     stop;
};

#ifndef __MORPHOS__
static void SAVEDS ASM
snprintfStuff(REG(d0,char c),REG(a3,struct stream *s))
{
    if (!s->stop)
    {
        if (++s->counter>=s->size)
        {
            *(s->buf) = 0;
            s->stop   = 1;
        }
        else *(s->buf++) = c;
    }
}

int STDARGS
snprintf(char *buf,int size,char *fmt,...)
{
    struct stream s;

    s.buf     = buf;
    s.size    = size;
    s.counter = 0;
    s.stop    = 0;

    RawDoFmt(fmt,&fmt+1,(APTR)snprintfStuff,&s);

    return s.counter-1;
}
#else
static void
snprintfStuff(void)
{
    register struct stream *s = (struct stream *)REG_A3;
    register UBYTE         c  = (UBYTE)REG_D0;

    if (!s->stop)
    {
        if (++s->counter>=s->size)
        {
            *(s->buf) = 0;
            s->stop   = 1;
        }
        else *(s->buf++) = c;
    }
}

static struct EmulLibEntry snprintfStuffTrap = {TRAP_LIB,0,(void *)&snprintfStuff};

int
snprintf(STRPTR buf,int size,STRPTR fmt,...)
{
    struct stream s;
    va_list       va;

    va_start(va,fmt);

    s.buf     = buf;
    s.size    = size;
    s.counter = 0;
    s.stop    = 0;

    RawDoFmt(fmt,va->overflow_arg_area,(APTR)&snprintfStuffTrap,&s);

    va_end(va);

    return s.counter-1;
}
#endif

/****************************************************************************/

#ifndef __MORPHOS__
void
drawGradient(Object *obj,struct MUIS_TheBar_Gradient *grad)
{
    register struct RastPort *rp;
    register ULONG           rs, gs, bs, horiz, from, to;
    register int             i, x, d, step, rdif, gdif, bdif, r1, g1, b1, r2, g2, b2, r, g, b, rd, gd, bd, ridx, gidx, bidx;
    register UWORD           l = _mleft(obj), t = _mtop(obj), w = _mwidth(obj), h = _mheight(obj);

#ifdef __SASC
rd = rdif= ridx = gd = gidx = bd = bidx = 0;
#endif

    rp = _rp(obj);

    from  = grad->from;
    to    = grad->to;
    horiz = grad->flags & MUIV_TheBar_Gradient_Horiz;

    /* Compute diffs */
    r1 = (from & 0x00FF0000)>>16;
    g1 = (from & 0x0000FF00)>>8;
    b1 = (from & 0x000000FF);

    r2 = (to & 0x00FF0000)>>16;
    g2 = (to & 0x0000FF00)>>8;
    b2 = (to & 0x000000FF);

    if (r1>r2)
    {
        rdif = r1-r2;
        rs = FALSE;
    }
    else
    {
        rdif = r2-r1;
        rs = TRUE;
    }

    if (g1>g2)
    {
        gdif = g1-g2;
        gs = FALSE;
    }
    else
    {
        gdif = g2-g1;
        gs = TRUE;
    }

    if (b1>b2)
    {
        bdif = b1-b2;
        bs = FALSE;
    }
    else
    {
        bdif = b2-b1;
        bs = TRUE;
    }

    /* Find out max diff */
    step = (rdif>=gdif) ? rdif : gdif;
    if (bdif>step) step = bdif;

    /* Find out best step to minimize rest */
    if (horiz)
    {
        if (step>w) step = w;

        if (step==0) step = 1;
        else
        {
            x = w/step;
            if (w!=x*step)
            {
                step = w/(x+1);
                if (step>w) step = w;
            }
        }
    }
    else
    {
        if (step>h) step = h;

        if (step==0) step = 1;
        else
        {
            x = h/step;
            if (h!=x*step)
            {
                step = h/(x+1);
                if (step>h) step = h;
            }
        }
    }

    if (step>1)
    {
        /* Compute color components deltas */
        rd = rdif/step;
        if (!rd) rd = 1;

        gd = gdif/step;
        if (!gd) gd = 1;

        bd = bdif/step;
        if (!bd) bd = 1;

        /* Compute rests */
        ridx = (rdif>step) ? step/((rdif-step)/rd) : 0;
        gidx = (gdif>step) ? step/((gdif-step)/gd) : 0;
        bidx = (bdif>step) ? step/((bdif-step)/bd) : 0;
    }

    /* Here we go */
    d = (horiz) ? w/step : h/step;
    x = (horiz) ? l : t;
    r = r1;
    g = g1;
    b = b1;

    for (i = 0; i<step; i++)
    {
        register ULONG col = (r<<16) | (g<<8) | b;

        /* Fill; if last step fill all rest */
        if (horiz)
            if (i==step-1)
            {
                FillPixelArray(rp,x,t,w-x+l,h,col);
                break;
            }
            else FillPixelArray(rp,x,t,d,h,col);
        else
            if (i==step-1)
            {
                FillPixelArray(rp,l,x,w,h-x+t,col);
                break;
            }
            else FillPixelArray(rp,l,x,w,d,col);

        x += d;

        /* Add delta to each color component */
        if (rs)
        {
            r += rd;

            /* Time to add more one more delta? */
            if (i && ridx && !(i%ridx)) r += rd;
            if (r>r2) r = r2;
        }
        else
        {
            r -= rd;

            if (i && ridx && !(i%ridx)) r -= rd;
            if (r<r2) r = r2;
        }

        if (gs)
        {
            g += gd;

            if (i && gidx && !(i%gidx)) g += gd;
            if (g>g2) g = g2;
        }
        else
        {
            g -= gd;

            if (i && gidx && !(i%gidx)) g -= gd;
            if (g<g2) g = g2;
        }

        if (bs)
        {
            b += bd;

            if (i && bidx && !(i%bidx)) b += bd;
            if (b>b2) b = b2;
        }
        else
        {
            b -= bd;

            if (i && bidx && !(i%bidx)) b -= bd;
            if (b<b2) b = b2;
        }
    }
}
#endif

/***********************************************************************/
