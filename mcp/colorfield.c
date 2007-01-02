/***************************************************************************

 TheBar.mcc - Next Generation Toolbar MUI Custom Class
 Copyright (C) 2003-2005 Alfonso Ranieri
 Copyright (C) 2005-2007 by TheBar.mcc Open Source Team

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
#include "private.h"

/***********************************************************************/

struct data
{
    struct MUI_RGBcolor rgb;
    LONG                pen;
    ULONG               flags;
};

/***********************************************************************/

enum
{
    FLG_Setup   = 1<<0,
    FLG_FreePen = 1<<1,
};


/***********************************************************************/

static ULONG
mNew(struct IClass *cl,Object *obj,struct opSet *msg)
{
    if((obj = (Object *)DoSuperMethodA(cl,obj,(Msg)msg)))
    {
        //struct data *data = INST_DATA(cl,obj);

        msg->MethodID = OM_SET;
        DoMethodA(obj,(Msg)msg);
        msg->MethodID = OM_NEW;
    }

    return (ULONG)obj;
}

/***********************************************************************/

static ULONG
mGet(struct IClass *cl,Object *obj,struct opGet *msg)
{
    struct data *data = INST_DATA(cl,obj);

    switch (msg->opg_AttrID)
    {
        case MUIA_Colorfield_RGB:
            *msg->opg_Storage = (ULONG)&data->rgb;
            return TRUE;
    }

    return FALSE;
}

/***********************************************************************/

static ULONG
mSets(struct IClass *cl,Object *obj,struct opSet *msg)
{
    struct data    *data = INST_DATA(cl,obj);
    struct TagItem *tag;
    struct TagItem          *tstate;
    ULONG          rgb;

    for(tstate = msg->ops_AttrList; (tag = NextTagItem(&tstate)); )
    {
        ULONG tidata = tag->ti_Data;

        switch(tag->ti_Tag)
        {
            case MUIA_Colorfield_RGB:
                if (data->rgb.red!=((struct MUI_RGBcolor *)tidata)->red ||
                    data->rgb.green!=((struct MUI_RGBcolor *)tidata)->green ||
                    data->rgb.blue!=((struct MUI_RGBcolor *)tidata)->blue)
                {
                    data->rgb.red   = ((struct MUI_RGBcolor *)tidata)->red;
                    data->rgb.green = ((struct MUI_RGBcolor *)tidata)->green;
                    data->rgb.blue  = ((struct MUI_RGBcolor *)tidata)->blue;

                    rgb = TRUE;
                }
                else tag->ti_Tag = TAG_IGNORE;
                break;
        }
    }

    if (rgb)
    {
        if (data->flags & FLG_Setup)
        {
            if (data->flags & FLG_FreePen)
            {
            }
        }

        MUI_Redraw(obj,MADF_DRAWUPDATE);
    }

    return DoSuperMethodA(cl,obj,(Msg)msg);
}

/***********************************************************************/

static ULONG
mSetup(struct IClass *cl,Object *obj,Msg msg)
{
    struct data *data = INST_DATA(cl,obj);

    if ((GetBitMapAttr(_screen(obj)->RastPort.BitMap,BMA_DEPTH)>8) &&
        CyberGfxBase && IsCyberModeID(GetVPModeID(&_screen(obj)->ViewPort)))
        data->flags |= FLG_Cyber;
    else data->flags &= ~FLG_Cyber;

    return DoSuperMethodA(cl,obj,msg);
}

/***********************************************************************/

static ULONG
mDraw(struct IClass *cl,Object *obj,struct MUIP_Draw *msg)
{
    struct data *data = INST_DATA(cl,obj);

    DoSuperMethodA(cl,obj,(Msg)msg);

    if ((data->flags & FLG_Framed) && (msg->flags & (MADF_DRAWUPDATE|MADF_DRAWOBJECT)))
    {
        struct RastPort rp;

        copymem(&rp,_rp(obj),sizeof(rp));

        SetAPen(&rp,MUIPEN(data->barFrameShinePen));
        Move(&rp,_left(obj),_bottom(obj));
        Draw(&rp,_left(obj),_top(obj));
        Draw(&rp,_right(obj),_top(obj));

        SetAPen(&rp,MUIPEN(data->barFrameShadowPen));
        Draw(&rp,_right(obj),_bottom(obj));
        Draw(&rp,_left(obj)+1,_bottom(obj));
    }

    return 0;
}

/***********************************************************************/

static ULONG SAVEDS ASM
dispatcher(REG(a0,struct IClass *cl),REG(a2,Object *obj),REG(a1,Msg msg))
{
    switch (msg->MethodID)
    {
        case OM_NEW:         return mNew(cl,obj,(APTR)msg);
        case OM_GET:         return mGet(cl,obj,(APTR)msg);
        case OM_SET:         return mSets(cl,obj,(APTR)msg);
        case MUIM_Setup:     return mSetup(cl,obj,(APTR)msg);
        case MUIM_Show:      return mShow(cl,obj,(APTR)msg);
        case MUIM_DragQuery: return mDragQuery(cl,obj,(APTR)msg);
        case MUIM_DragDrop:  return mDragDrop(cl,obj,(APTR)msg);
        default:             return DoSuperMethodA(cl,obj,msg);
    }
}

/***********************************************************************/

void
free(void)
{
    if (ColorWheelBase)
    {
        CloseLibrary(ColorWheelBase);
        ColorWheelBase = NULL;
    }

    if (GradientSliderBase)
    {
        CloseLibrary(GradientSliderBase);
        GradientSliderBase = NULL;
    }

    if (gradientslider)
    {
        MUI_DeleteCustomClass(gradientslider);
        gradientslider = NULL;
    }

    if (colorwheel)
    {
        MUI_DeleteCustomClass(colorwheel);
        colorwheel = NULL;
    }

    if (lib_)
    {
        MUI_DeleteCustomClass(lib_);
        lib_ = NULL;
    }
}

/***********************************************************************/

ULONG
init(void)
{
    if ((ColorWheelBase = OpenLibrary("gadgets/colorwheel.gadget",0)) &&
        (GradientSliderBase = OpenLibrary("gadgets/gradientslider.gadget",0)) &&
        initColorwheel() &&
        initGradientslider() &&
        (lib_ = MUI_CreateCustomClass(NULL,MUIC_Group,NULL,sizeof(struct data),Dispatcher)))
    {
        if (lib_flags & BASEFLG_MUI20)
            lib_class->mcc_Class->cl_ID = "";

        return TRUE;
    }

    free();

    return FALSE;
}

/***********************************************************************/
