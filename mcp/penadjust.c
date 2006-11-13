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
#include <stdlib.h>

/***********************************************************************/

static struct MUI_CustomClass *penslist = NULL;

#define penslistObject NewObject(penslist->mcc_Class,NULL

/***********************************************************************/

static ULONG penIDs[] =
{
    Msg_Poppen_Shine,
    Msg_Poppen_Halfshine,
    Msg_Poppen_Background,
    Msg_Poppen_Halfshadow,
    Msg_Poppen_Shadow,
    Msg_Poppen_Text,
    Msg_Poppen_Fill,
    Msg_Poppen_Mark,
    0
};
static STRPTR pens[IDSSIZE(penIDs)];

/***********************************************************************/

struct penslistData
{
    Object *list;
    Object *pens[8];
    APTR   pimages[8];
    LONG   active;
};

/***********************************************************************/

static ULONG
mPenslistNew(struct IClass *cl,Object *obj,struct opSet *msg)
{
    register Object *list;

    if (obj = (Object *)DoSuperNew(cl,obj,
            MUIA_CycleChain,    TRUE,
            MUIA_Listview_List, list = ListObject,
                InputListFrame,
                MUIA_Background,         MUII_ListBack,
                MUIA_List_ConstructHook, MUIV_List_ConstructHook_String,
                MUIA_List_DestructHook,  MUIV_List_DestructHook_String,
            End,
            TAG_MORE,msg->ops_AttrList))
    {
        register struct penslistData *data = INST_DATA(cl,obj);

        data->list   = list;
        data->active = -1;
    }

    return (ULONG)obj;
}

/***********************************************************************/

static ULONG
mPenslistSets(struct IClass *cl,Object *obj,struct opSet *msg)
{
    register struct penslistData *data = INST_DATA(cl,obj);
    register struct TagItem      *tag;
    struct TagItem               *tstate;

    for (tstate = msg->ops_AttrList; tag = NextTagItem(&tstate); )
    {
        register ULONG tidata = tag->ti_Data;

        switch(tag->ti_Tag)
        {
            case MUIA_List_Active:
                data->active = (LONG)tidata;
                break;
        }
    }

    return DoSuperMethodA(cl,obj,(Msg)msg);
}

/***********************************************************************/

static ULONG
mPenslistSetup(struct IClass *cl,Object *obj,Msg msg)
{
    register struct penslistData *data = INST_DATA(cl,obj);
    register int                 i;
    struct RastPort              rp;
    struct TextExtent            te;
    UWORD                        w, h;

    if (!DoSuperMethodA(cl,obj,msg)) return FALSE;

    copymem(&rp,&_screen(obj)->RastPort,sizeof(rp));
    SetFont(&rp,_font(obj));
    TextExtent(&rp,"X",1,&te);
    w =  te.te_Height;
    h =  te.te_Height;
    if (h>4) h -= 2;

    for (i = 0; i<8; i++)
    {
        register char buf[64];

        snprintf(buf,sizeof(buf),"2:m%ld",i);

        data->pens[i] = ImageObject,
            MUIA_Image_FreeHoriz, TRUE,
            MUIA_Image_FreeVert,  TRUE,
            MUIA_FixWidth,        w,
            MUIA_FixHeight,       h,
            MUIA_Image_Spec,      buf,
        End;

        if (data->pens[i])
        {
            data->pimages[i] = (APTR)DoMethod(data->list,MUIM_List_CreateImage,data->pens[i],0);
            snprintf(buf,sizeof(buf),"\33O[%08lx] %s",data->pimages[i],pens[i]);
            DoMethod(data->list,MUIM_List_InsertSingle,buf,MUIV_List_Insert_Bottom);
        }
    }

    set(data->list,MUIA_List_Active,data->active);

    return TRUE;
}

/***********************************************************************/

static ULONG
mPenslistCleanup(struct IClass *cl,Object *obj,Msg msg)
{
    register struct penslistData *data = INST_DATA(cl,obj);
    register int                 i;

    for (i = 0; i<7; i++)
    {
        if (data->pens[i])
        {
            if (data->pimages[i])
            {
                DoMethod(data->list,MUIM_List_DeleteImage,data->pimages[i]);
                data->pimages[i] = NULL;
            }

            MUI_DisposeObject(data->pens[i]);
            data->pens[i] = NULL;
        }
    }

    DoMethod(data->list,MUIM_List_Clear);

    return DoSuperMethodA(cl,obj,msg);
}

/***********************************************************************/

static ULONG
mPenslistShow(struct IClass *cl,Object *obj,Msg msg)
{
    if (!DoSuperMethodA(cl,obj,msg)) return FALSE;
    set(_win(obj),MUIA_Window_DefaultObject,obj);

    return TRUE;
}

/***********************************************************************/

static ULONG SAVEDS ASM
penslistDispatcher(REG(a0,struct IClass *cl),REG(a2,Object *obj),REG(a1,Msg msg))
{
    switch (msg->MethodID)
    {
        case OM_NEW:       return mPenslistNew(cl,obj,(APTR)msg);
        case OM_SET:       return mPenslistSets(cl,obj,(APTR)msg);
        case MUIM_Setup:   return mPenslistSetup(cl,obj,(APTR)msg);
        case MUIM_Cleanup: return mPenslistCleanup(cl,obj,(APTR)msg);
        case MUIM_Show:    return mPenslistShow(cl,obj,(APTR)msg);
        default:           return DoSuperMethodA(cl,obj,msg);
    }
}

/***********************************************************************/

static ULONG
initPenslist(void)
{
    if (penslist = MUI_CreateCustomClass(NULL,MUIC_Listview,NULL,sizeof(struct penslistData),penslistDispatcher))
    {
        if (lib_flags & BASEFLG_MUI20)
            penslist->mcc_Class->cl_ID = "Penslist";

        localizeArray(pens,penIDs);

        return TRUE;
    }

    return FALSE;
}

/***********************************************************************/

static ULONG titleIDs[] =
{
    Msg_Poppen_MUI,
    Msg_Poppen_Colormap,
    Msg_Poppen_RGB,
    0
};
static STRPTR titles[IDSSIZE(titleIDs)];

enum
{
    PAGE_MUI,
    PAGE_Colormap,
    PAGE_RGB,
};

/***********************************************************************/

struct penadjustData
{
    Object *mui;
    Object *colormap;
    Object *rgb;
    char   spec[sizeof(struct MUI_PenSpec)];
    ULONG  flags;
};

/***********************************************************************/

static ULONG
mPenadjustNew(struct IClass *cl,Object *obj,struct opSet *msg)
{
    register Object *mui, *colormap, *rgb;

    if (obj = (Object *)DoSuperNew(cl,obj,
            MUIA_Register_Titles, titles,
            MUIA_CycleChain,      TRUE,

            /* MUI */
            Child, mui = penslistObject, End,

            /* Colormap */
            Child, VGroup,
                Child, owspace(1),
                Child, colormap = oslider(0,Msg_Poppen_ColorMapHelp,-128,127),
                Child, owspace(1),
            End,

            /* RGB */
            Child, rgb = coloradjustObject, End,

            TAG_MORE, msg->ops_AttrList))
    {
        register struct penadjustData *data = INST_DATA(cl,obj);
        register Object               *pop;

        data->mui      = mui;
        data->colormap = colormap;
        data->rgb      = rgb;

        pop = (Object *)GetTagData(MUIA_Popbackground_PopObj,NULL,msg->ops_AttrList);
        DoMethod(mui,MUIM_Notify,MUIA_Listview_DoubleClick,MUIV_EveryTime,MUIV_Notify_Application,5,MUIM_Application_PushMethod,pop,2,MUIM_Popbackground_Close,TRUE);
    }

    return (ULONG)obj;
}

/***********************************************************************/

static ULONG
mPenadjustGet(struct IClass *cl,Object *obj,struct opGet *msg)
{
    register struct penadjustData *data = INST_DATA(cl,obj);

    switch (msg->opg_AttrID)
    {
        case MUIA_Pendisplay_Spec:
            if (DoMethod(obj,MUIM_Popbackground_GetSpec,data->spec,NULL,0)==MUIV_Popbackground_GetSpec_Fail)
                return FALSE;
            *msg->opg_Storage = (ULONG)data->spec;
            return TRUE;

        default:
            return DoSuperMethodA(cl,obj,(Msg)msg);
    }
}

/***********************************************************************/

static ULONG
mPenadjustSets(struct IClass *cl,Object *obj,struct opSet *msg)
{
    register struct penadjustData *data = INST_DATA(cl,obj);
    register struct TagItem       *tag;
    struct TagItem                *tstate;

    for (tstate = msg->ops_AttrList; tag = NextTagItem(&tstate); )
    {
        register ULONG tidata = tag->ti_Data;

        switch(tag->ti_Tag)
        {
            case MUIA_Pendisplay_Spec:
                if (DoMethod(obj,MUIM_Popbackground_SetSpec,tidata,NULL,0)!=MUIV_Popbackground_SetSpec_Fail)
                    stccpy(data->spec,(STRPTR)tidata,sizeof(data->spec));
                break;
        }
    }

    return DoSuperMethodA(cl,obj,(Msg)msg);
}

/***********************************************************************/

static ULONG
mPenadjustDragQuery(struct IClass *cl,Object *obj,struct MUIP_DragQuery *msg)
{
    STRPTR x;

    if (obj==msg->obj) return MUIV_DragQuery_Refuse;

    if ((get(msg->obj,MUIA_Pendisplay_Spec,&x) && x && *x) ||
        get(msg->obj,MUIA_Popbackground_Grad,&x))
        return MUIV_DragQuery_Accept;

    if (get(msg->obj,MUIA_Imagedisplay_Spec,&x) && x && (*x=='2') && (*(x+1)==':'))
        return MUIV_DragQuery_Accept;

    return MUIV_DragQuery_Refuse;
}

/***********************************************************************/

static ULONG
mPenadjustDragDrop(struct IClass *cl,Object *obj,struct MUIP_DragDrop *msg)
{
    STRPTR x;

    if (get(msg->obj,MUIA_Pendisplay_Spec,&x)) set(obj,MUIA_Pendisplay_Spec,x);
    else
        if (get(msg->obj,MUIA_Imagedisplay_Spec,&x)) set(obj,MUIA_Pendisplay_Spec,x+2);
        else
            if (get(msg->obj,MUIA_Popbackground_Grad,&x))
            {
                register char  spec[sizeof(struct MUI_PenSpec)];
                register ULONG c, r, g, b;

                c = (((struct MUIS_TheBar_Gradient *)x)->flags & MUIV_TheBar_Gradient_DragTo) ? ((struct MUIS_TheBar_Gradient *)x)->to : ((struct MUIS_TheBar_Gradient *)x)->from;
                r = c>>16;
                g = (c>>8) & 0xff;
                b = c & 0xff;

                sprintf(spec,"r%08lx,%08lx,%08lx",(r<<24)|(r<<16)|(r<<8)|r,(g<<24)|(g<<16)|(g<<8)|g,(b<<24)|(b<<16)|(b<<8)|b);
                set(obj,MUIA_Pendisplay_Spec,spec);
            }

    return 0;
}

/***********************************************************************/

static ULONG
mPenadjustSetSpec(struct IClass *cl,Object *obj,struct MUIP_Popbackground_SetSpec *msg)
{
    register struct penadjustData *data = INST_DATA(cl,obj);
    register char                 *spec = msg->spec, c;

    if (msg->flags & MUIV_Popbackground_SetSpec_Image)
    {
        if (!spec || (*spec++!='2') || (!*spec++==':') || !(c = *spec++) || !*spec)
            return MUIV_Popbackground_SetSpec_Fail;
    }
    else
        if (!spec || !(c = *spec++) || !*spec) return MUIV_Popbackground_SetSpec_Fail;

    switch (c)
    {
        /* MUI */
        case 'm':
        {
            register LONG v;

            v = atoi(spec);
            if (v<0 || v>7) return MUIV_Popbackground_SetSpec_Fail;

            set(data->mui,MUIA_List_Active,v);
            superset(cl,obj,MUIA_Group_ActivePage,PAGE_MUI);
            return MUIV_Popbackground_SetSpec_Spec;
        }

        /* Colormap */
        case 'p':
        {
            register LONG v;

            v = atoi(spec);
            if (v<-128 || v>127) return MUIV_Popbackground_SetSpec_Fail;

            set(data->colormap,MUIA_Numeric_Value,v);
            superset(cl,obj,MUIA_Group_ActivePage,PAGE_Colormap);
            return MUIV_Popbackground_SetSpec_Spec;
        }

        /* RGB */
        case 'r':
        {
            struct MUI_RGBcolor rgb;
            register char       *p, *s;

            p = strchr(spec,',');
            if (!p) return MUIV_Popbackground_SetSpec_Fail;
            *p = 0;
            if (stch_l(spec,(LONG *)&rgb.red)!=8) return MUIV_Popbackground_SetSpec_Fail;
            *p++ = ',';

            s = p;
            p = strchr(s,',');
            if (!p) return MUIV_Popbackground_SetSpec_Fail;
            *p = 0;
            if (stch_l(s,(LONG *)&rgb.green)!=8) return MUIV_Popbackground_SetSpec_Fail;
            *p++ = ',';

            s = p;
            if (stch_l(s,(LONG *)&rgb.blue)!=8) return MUIV_Popbackground_SetSpec_Fail;

            set(data->rgb,MUIA_Coloradjust_RGB,&rgb);
            superset(cl,obj,MUIA_Group_ActivePage,PAGE_RGB);
            return MUIV_Popbackground_SetSpec_Spec;
         }

        default:
            return MUIV_Popbackground_SetSpec_Fail;
    }
}

/***********************************************************************/

static ULONG
mPenadjustGetSpec(struct IClass *cl,Object *obj,struct MUIP_Popbackground_GetSpec *msg)
{
    register struct penadjustData *data = INST_DATA(cl,obj);
    register char                 spec[32];
    register ULONG                res = MUIV_Popbackground_GetSpec_Spec;
    LONG                          x;

    superget(cl,obj,MUIA_Group_ActivePage,&x);
    switch(x)
    {
        /* MUI */
        case PAGE_MUI:
            get(data->mui,MUIA_List_Active,&x);
            if (x>=0) sprintf(spec,"m%ld",x);
            else res = MUIV_Popbackground_GetSpec_Fail;
            break;

        /* Colormap */
        case PAGE_Colormap:
            get(data->colormap,MUIA_Numeric_Value,&x);
            sprintf(spec,"p%ld",x);
            break;

        /* RGB */
        case PAGE_RGB:
        {
            struct MUI_RGBcolor *rgb;

            get(data->rgb,MUIA_Coloradjust_RGB,&rgb);
            sprintf(spec,"r%08lx,%08lx,%08lx",rgb->red,rgb->green,rgb->blue);
            break;
        }
    }

    if (res==MUIV_Popbackground_GetSpec_Fail) *msg->spec = 0;
    else
    {
        if (msg->flags & MUIV_Popbackground_GetSpec_Image) sprintf(msg->spec,"2:%s",spec);
        else strcpy(msg->spec,spec);
    }

    return res;
}

/***********************************************************************/

static ULONG SAVEDS ASM
penadjustDispatcher(REG(a0,struct IClass *cl),REG(a2,Object *obj),REG(a1,Msg msg))
{
    switch (msg->MethodID)
    {
        case OM_NEW:                     return mPenadjustNew(cl,obj,(APTR)msg);
        case OM_GET:                     return mPenadjustGet(cl,obj,(APTR)msg);
        case OM_SET:                     return mPenadjustSets(cl,obj,(APTR)msg);
        case MUIM_DragQuery:             return mPenadjustDragQuery(cl,obj,(APTR)msg);
        case MUIM_DragDrop:              return mPenadjustDragDrop(cl,obj,(APTR)msg);
        case MUIM_Popbackground_SetSpec: return mPenadjustSetSpec(cl,obj,(APTR)msg);
        case MUIM_Popbackground_GetSpec: return mPenadjustGetSpec(cl,obj,(APTR)msg);
        default:                         return DoSuperMethodA(cl,obj,msg);
    }
}

/***********************************************************************/

void
freePenadjust(void)
{
    if (penslist)
    {
        MUI_DeleteCustomClass(penslist);
        penslist = NULL;
    }

    if (lib_penadjust)
    {
        MUI_DeleteCustomClass(lib_penadjust);
        lib_penadjust = NULL;
    }
}

/***********************************************************************/

ULONG
initPenadjust(void)
{
    if (initPenslist() &&
        (lib_penadjust = MUI_CreateCustomClass(NULL,MUIC_Register,NULL,sizeof(struct penadjustData),penadjustDispatcher)))
    {
        if (lib_flags & BASEFLG_MUI20)
            lib_penadjust->mcc_Class->cl_ID = "Penadjust";

        localizeArray(titles,titleIDs);

        return TRUE;
    }

    freePenadjust();

    return FALSE;
}

/***********************************************************************/
