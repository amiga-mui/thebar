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

struct data
{
    Object *bar;
    long   pshine;
    long   pshadow;
    long   pfill;
    ULONG  flags;
};

enum
{
    FLG_Horiz          = 1<<0,
    FLG_ShowMe         = 1<<1,
    FLG_UseDragBarFill = 1<<2,
};

/***********************************************************************/

static ULONG
mNew(struct IClass *cl,Object *obj,struct opSet *msg)
{
    if (obj = (Object *)DoSuperNew(cl,obj,
            MUIA_InputMode,      MUIV_InputMode_Immediate,
            MUIA_ShowSelState,   FALSE,
            MUIA_CustomBackfill, TRUE,
            TAG_DONE))
    {
        register struct data *data = INST_DATA(cl,obj);

        data->bar   = (Object *)GetTagData(MUIA_TheButton_TheBar,FALSE,msg->ops_AttrList);
        data->flags = (GetTagData(MUIA_Group_Horiz,FALSE,msg->ops_AttrList) ? FLG_Horiz : 0) |
                      (GetTagData(MUIA_ShowMe,TRUE,msg->ops_AttrList) ? FLG_ShowMe : 0);
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
        case MUIA_TheButton_Spacer: *msg->opg_Storage = MUIV_TheButton_Spacer_DragBar; return TRUE;
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
            case MUIA_Pressed:
                if (tidata)
                {
                    struct Window *window;

                    get(_win(obj),MUIA_Window_Window,&window);
                    DoMethod(_app(obj),MUIM_Application_PushMethod,(ULONG)data->bar,4,MUIM_DoDrag,window->MouseX-_mleft(obj),window->MouseY-_mtop(obj),0);
                }
                break;

            case MUIA_Group_Horiz:
                if (tidata) data->flags |= FLG_Horiz;
                else data->flags &= ~FLG_Horiz;
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

    if (!getconfigitem(cl,obj,MUICFG_TheBar_DragBarShinePen,&pen))
        pen = MUIDEF_TheBar_DragBarShinePen;
    data->pshine = MUI_ObtainPen(muiRenderInfo(obj),(struct MUI_PenSpec *)pen,0);

    if (!getconfigitem(cl,obj,MUICFG_TheBar_DragBarShadowPen,&pen))
        pen = MUIDEF_TheBar_DragBarShadowPen;
    data->pshadow = MUI_ObtainPen(muiRenderInfo(obj),(struct MUI_PenSpec *)pen,0);

    if (getconfigitem(cl,obj,MUICFG_TheBar_UseDragBarFillPen,&val) ? *val : MUIDEF_TheBar_UseDragBarFillPen)
    {
        if (!getconfigitem(cl,obj,MUICFG_TheBar_DragBarFillPen,&pen))
            pen = MUIDEF_TheBar_DragBarFillPen;
        data->pfill = MUI_ObtainPen(muiRenderInfo(obj),(struct MUI_PenSpec *)pen,0);

        data->flags |= FLG_UseDragBarFill;
    }

    return TRUE;
}

/***********************************************************************/

static ULONG
mCleanup(struct IClass *cl,Object *obj,Msg msg)
{
    register struct data *data = INST_DATA(cl,obj);

    MUI_ReleasePen(muiRenderInfo(obj),data->pshine);
    MUI_ReleasePen(muiRenderInfo(obj),data->pshadow);
    if (data->flags & FLG_UseDragBarFill)
    {
        MUI_ReleasePen(muiRenderInfo(obj),data->pfill);
        data->flags &= ~FLG_UseDragBarFill;
    }

    return DoSuperMethodA(cl,obj,msg);
}

/***********************************************************************/

static ULONG
mAskMinMax(struct IClass *cl,Object *obj,struct MUIP_AskMinMax *msg)
{
    register struct data *data = INST_DATA(cl,obj);

    DoSuperMethodA(cl,obj,(Msg)msg);

    if (data->flags & FLG_Horiz)
    {
        msg->MinMaxInfo->MinWidth  += 9;
        msg->MinMaxInfo->MinHeight += 4;
        msg->MinMaxInfo->DefWidth  += 9;
        msg->MinMaxInfo->DefHeight += 4;
        msg->MinMaxInfo->MaxWidth  += 9;
        msg->MinMaxInfo->MaxHeight  = MBQ_MUI_MAXMAX;
    }
    else
    {
        msg->MinMaxInfo->MinWidth  += 4;
        msg->MinMaxInfo->MinHeight += 9;
        msg->MinMaxInfo->DefWidth  += 4;
        msg->MinMaxInfo->DefHeight += 9;
        msg->MinMaxInfo->MaxWidth   = MBQ_MUI_MAXMAX;
        msg->MinMaxInfo->MaxHeight += 9;
    }

    return 0;
}

/***********************************************************************/

static ULONG
mDraw(struct IClass *cl,Object *obj,struct MUIP_Draw *msg)
{
    register struct data *data = INST_DATA(cl,obj);

    DoSuperMethodA(cl,obj,(Msg)msg);

    if (msg->flags & (MADF_DRAWUPDATE|MADF_DRAWOBJECT))
    {
        struct RastPort rp;
        register WORD   l, t, r, b;

        copymem(&rp,_rp(obj),sizeof(rp));

        l = _mleft(obj);
        t = _mtop(obj);
        r = _mright(obj);
        b = _mbottom(obj);

        if (data->flags & FLG_Horiz)
        {
            SetAPen(&rp,MUIPEN(data->pshine));
            Move(&rp,l,b-1);
            Draw(&rp,l,t);
            Draw(&rp,l+3,t);

            if (data->flags & FLG_UseDragBarFill)
            {
                SetAPen(&rp,MUIPEN(data->pfill));
                RectFill(&rp,l+1,t+1,l+2,b-1);
            }

            SetAPen(&rp,MUIPEN(data->pshadow));
            Move(&rp,l+3,t+1);
            Draw(&rp,l+3,b);
            Draw(&rp,l,b);
        }
        else
        {
            SetAPen(&rp,MUIPEN(data->pshine));
            Move(&rp,r-1,t);
            Draw(&rp,l,t);
            Draw(&rp,l,t+3);

            if (data->flags & FLG_UseDragBarFill)
            {
                SetAPen(&rp,MUIPEN(data->pfill));
                RectFill(&rp,l+1,t+1,r-1,t+2);
            }

            SetAPen(&rp,MUIPEN(data->pshadow));
            Move(&rp,l+1,t+3);
            Draw(&rp,r,t+3);
            Draw(&rp,r,t);
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
        case MUIM_CustomBackfill: return mCustomBackfill(cl,obj,(APTR)msg);
        case MUIM_Setup:          return mSetup(cl,obj,(APTR)msg);
        case MUIM_Cleanup:        return mCleanup(cl,obj,(APTR)msg);
        default:                  return DoSuperMethodA(cl,obj,msg);
    }
}

M_DISPEND(dispatcher)

/***********************************************************************/

ULONG
initDragBarClass(void)
{
    if (lib_dragBarClass = MUI_CreateCustomClass(NULL,MUIC_Area,NULL,sizeof(struct data),DISP(dispatcher)))
    {
        if (lib_flags & BASEFLG_MUI20)
            lib_dragBarClass->mcc_Class->cl_ID = "TheBar_DragBar";

        return TRUE;
    }

    return FALSE;
}

/***********************************************************************/

