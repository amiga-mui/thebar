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

//#define _riflags(obj) (muiRenderInfo(obj)->mri_Flags)
#define _riflags(obj) (MUIMRI_THINFRAMES)

/***********************************************************************/

struct data
{
    Object *bar;
    long   pshine;
    long   pshadow;
    UWORD  sp;
    ULONG  flags;
};

enum
{
    FLG_Horiz                = 1<<0,
    FLG_Bar                  = 1<<1,
    FLG_UserBarSpacerSpacing = 1<<2,
    FLG_ShowMe               = 1<<3,
};

/***********************************************************************/

static ULONG
mNew(struct IClass *cl,Object *obj,struct opSet *msg)
{
    if (obj = (Object *)DoSuperNew(cl,obj,
            MUIA_CustomBackfill,TRUE,
            TAG_MORE, (ULONG)msg->ops_AttrList))
    {
        register struct data    *data = INST_DATA(cl,obj);
        register struct TagItem *tag;

        data->bar   = (Object *)GetTagData(MUIA_TheButton_TheBar,FALSE,msg->ops_AttrList);
        data->flags = (GetTagData(MUIA_Group_Horiz,FALSE,msg->ops_AttrList) ? FLG_Horiz : 0) |
                      ((GetTagData(MUIA_TheButton_Spacer,MUIV_TheButton_Spacer_Bar,msg->ops_AttrList)==MUIV_TheButton_Spacer_Bar) ? FLG_Bar : 0) |
                      (GetTagData(MUIA_ShowMe,TRUE,msg->ops_AttrList) ? FLG_ShowMe : 0);

        if ((tag = FindTagItem(MUIA_TheBar_BarSpacerSpacing,msg->ops_AttrList)) &&
            ((int)tag->ti_Data>=0 && (int)tag->ti_Data<=16))
        {
            data->sp = tag->ti_Data;
            data->flags |= FLG_UserBarSpacerSpacing;
        }
    }

    return (ULONG)obj;
}

/***********************************************************************/

static ULONG
mGet(struct IClass *cl,Object *obj,struct opGet *msg)
{
    register struct data *data = INST_DATA(cl,obj);

    switch (msg->opg_AttrID)
    {
        case MUIA_TheButton_Spacer: *msg->opg_Storage = (data->flags & FLG_Bar) ? MUIV_TheButton_Spacer_Bar : MUIV_TheButton_Spacer_Button; return TRUE;
        case MUIA_ShowMe:           *msg->opg_Storage = (data->flags & FLG_ShowMe) ? TRUE : FALSE; return TRUE;
        default:                    return DoSuperMethodA(cl,obj,(Msg)msg);
    }
}

/***********************************************************************/

static ULONG
mSets(struct IClass *cl,Object *obj,struct opSet *msg)
{
    register struct data    *data = INST_DATA(cl,obj);
    register struct TagItem *tag;
    struct TagItem          *tstate;

    for (tstate = msg->ops_AttrList; tag = NextTagItem(&tstate); )
    {
        register ULONG tidata = tag->ti_Data;

        switch (tag->ti_Tag)
        {
            case MUIA_Group_Horiz:
                if (tidata) data->flags |= FLG_Horiz;
                else data->flags &= ~FLG_Horiz;
                break;

            case MUIA_TheButton_Spacer:
                if (tidata==MUIV_TheButton_Spacer_Bar) data->flags |= FLG_Bar;
                else data->flags &= ~FLG_Bar;
                break;

            case MUIA_ShowMe:
                if (BOOLSAME(data->flags & FLG_ShowMe,tidata)) tag->ti_Data = TAG_IGNORE;
                else
                {
                    if (tidata) data->flags |= FLG_ShowMe;
                    else data->flags &= ~FLG_ShowMe;
                }
                break;
        }
    }

    return DoSuperMethodA(cl,obj,(Msg)msg);
}

/***********************************************************************/

static ULONG
mSetup(struct IClass *cl,Object *obj,Msg msg)
{
    register struct data *data = INST_DATA(cl,obj);
    APTR                 pen;
    ULONG                *val;

    if (!(DoSuperMethodA(cl,obj,(Msg)msg))) return FALSE;

    if (data->flags & FLG_Bar)
    {
        if (!getconfigitem(cl,obj,MUICFG_TheBar_BarSpacerShinePen,&pen))
            pen = MUIDEF_TheBar_BarSpacerShinePen;
        data->pshine = MUI_ObtainPen(muiRenderInfo(obj),(struct MUI_PenSpec *)pen,0);

        if (!getconfigitem(cl,obj,MUICFG_TheBar_BarSpacerShadowPen,&pen))
            pen = MUIDEF_TheBar_BarSpacerShadowPen;
        data->pshadow = MUI_ObtainPen(muiRenderInfo(obj),(struct MUI_PenSpec *)pen,0);

        if (!(data->flags & FLG_UserBarSpacerSpacing))
        {
            data->sp = getconfigitem(cl,obj,MUICFG_TheBar_BarSpacerSpacing,&val) ?
                *val : MUIDEF_TheBar_BarSpacerSpacing;
        }
    }

    return TRUE;
}

/***********************************************************************/

static ULONG
mCleanup(struct IClass *cl,Object *obj,Msg msg)
{
    register struct data *data = INST_DATA(cl,obj);

    if (data->flags & FLG_Bar)
    {
        MUI_ReleasePen(muiRenderInfo(obj),data->pshine);
        MUI_ReleasePen(muiRenderInfo(obj),data->pshadow);
    }

    return DoSuperMethodA(cl,obj,msg);
}

/***********************************************************************/

static ULONG
mAskMinMax(struct IClass *cl,Object *obj,struct MUIP_AskMinMax *msg)
{
    register struct data *data = INST_DATA(cl,obj);
    register ULONG       delta = 2*data->sp+2;

    DoSuperMethodA(cl,obj,(Msg)msg);

    if (data->flags & FLG_Bar)
    {
        if (data->flags & FLG_Horiz)
        {
            if (_riflags(obj) & MUIMRI_THINFRAMES) delta += 2;

            msg->MinMaxInfo->MinWidth  += delta;
            msg->MinMaxInfo->DefWidth  += delta;
            msg->MinMaxInfo->MaxWidth  += delta;
            msg->MinMaxInfo->MaxHeight  = MBQ_MUI_MAXMAX;
        }
        else
        {
            msg->MinMaxInfo->MinHeight += delta;
            msg->MinMaxInfo->DefHeight += delta;
            msg->MinMaxInfo->MaxWidth   = MBQ_MUI_MAXMAX;
            msg->MinMaxInfo->MaxHeight += delta;
        }
    }
    else
    {
        msg->MinMaxInfo->MaxWidth  = MBQ_MUI_MAXMAX;
        msg->MinMaxInfo->MaxHeight = MBQ_MUI_MAXMAX;
    }

    return 0;
}

/***********************************************************************/

static ULONG
mDraw(struct IClass *cl,Object *obj,struct MUIP_Draw *msg)
{
    register struct data *data = INST_DATA(cl,obj);

    DoSuperMethodA(cl,obj,(Msg)msg);

    if ((data->flags & FLG_Bar) && (msg->flags & (MADF_DRAWOBJECT|MADF_DRAWOBJECT)))
    {
        register struct RastPort *rp = _rp(obj);

        if (data->flags & FLG_Horiz)
        {
            register UWORD l, t, b, fw = (_riflags(obj) & MUIMRI_THINFRAMES) ? 1 : 2;

            l = _mleft(obj)+(_mwidth(obj)>>1)-fw;
            t = _mtop(obj)+1;
            b = _mbottom(obj)-1;

            SetAPen(rp,MUIPEN(data->pshadow));
            RectFill(rp,l,t,l+fw-1,b);

            SetAPen(rp,MUIPEN(data->pshine));
            RectFill(rp,l+fw,t,l+fw+fw-1,b);
        }
        else
        {
            register UWORD l, t, r;

            l = _mleft(obj)+1;
            t = _mtop(obj)+(_mheight(obj)>>1)-1;
            r = _mright(obj)-1;

            SetAPen(rp,MUIPEN(data->pshadow));
            RectFill(rp,l,t,r,t);

            SetAPen(rp,MUIPEN(data->pshine));
            RectFill(rp,l,t+1,r,t+1);
        }
    }

    return 0;
}

/***********************************************************************/

static ULONG
mCustomBackfill(struct IClass *cl,Object *obj,struct MUIP_CustomBackfill *msg)
{
    register struct data *data = INST_DATA(cl,obj);

    if (data->bar)
        return DoMethod(data->bar,MUIM_CustomBackfill,
            msg->left,
            msg->top,
            msg->right,
            msg->bottom,
            msg->left+msg->xoffset,
            msg->top+msg->yoffset,
            0);
    else return DoSuperMethod(cl,obj,MUIM_DrawBackground,msg->left,msg->top,msg->right-msg->left+1,msg->bottom-msg->top+1,msg->xoffset,msg->yoffset,0);
}

/***********************************************************************/

M_DISP(dispatcher)
{
    M_DISPSTART

    switch(msg->MethodID)
    {
        case OM_NEW:              return mNew(cl,obj,(APTR)msg);
        case OM_GET:              return mGet(cl,obj,(APTR)msg);
        case OM_SET:              return mSets(cl,obj,(APTR)msg);
        case MUIM_AskMinMax:      return mAskMinMax(cl,obj,(APTR)msg);
        case MUIM_Draw:           return mDraw(cl,obj,(APTR)msg);
        case MUIM_Setup:          return mSetup(cl,obj,(APTR)msg);
        case MUIM_Cleanup:        return mCleanup(cl,obj,(APTR)msg);
        case MUIM_CustomBackfill: return mCustomBackfill(cl,obj,(APTR)msg);
        default:                  return DoSuperMethodA(cl,obj,msg);
    }
}

M_DISPEND(dispatcher)

/***********************************************************************/

ULONG
initSpacerClass(void)
{
    if (lib_spacerClass = MUI_CreateCustomClass(NULL,MUIC_Area,NULL,sizeof(struct data),DISP(dispatcher)))
    {
        if (lib_flags & BASEFLG_MUI20)
            lib_spacerClass->mcc_Class->cl_ID = "TheBar_Spacer";

        return TRUE;
    }

    return FALSE;
}

/***********************************************************************/

