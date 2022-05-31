/***************************************************************************

 TheBar.mcc - Next Generation Toolbar MUI Custom Class
 Copyright (C) 2003-2005 Alfonso Ranieri
 Copyright (C) 2005-2022 TheBar Open Source Team

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

#include <graphics/gfxbase.h>
#include "class.h"
#include "private.h"
#include "version.h"

#if defined(__amigaos4__)
#include <dos/obsolete.h>
#endif

/***********************************************************************/

static struct MUIS_TheBar_Button *parseDescription(struct MUIP_Toolbar_Description *odesc)
{
	struct MUIP_Toolbar_Description *desc;
	LONG numButtons = 0;
	struct MUIS_TheBar_Button *buttons;

	// count the number of buttons and spacers
	desc = odesc;
	while(desc->Type != TDT_END)
	{
		if(desc->Type == TDT_SPACE || desc->Type == TDT_BUTTON)
		{
			numButtons++;
		}

		desc++;
	}

	// count one additional item for the terminator item
	numButtons++;

	// allocate memory for the button structures
	if((buttons = SharedAlloc(numButtons * sizeof(*buttons))) != NULL)
	{
		struct MUIS_TheBar_Button *b = buttons;
		ULONG imageIndex = 0;
		ULONG buttonId = 0;

		memset(buttons, 0, numButtons * sizeof(*buttons));

		desc = odesc;
		while(desc->Type != TDT_END)
		{
			if(desc->Type == TDT_SPACE)
			{
				b->img = MUIV_TheBar_BarSpacer;

				// the button ID counts for spacers and buttons
				buttonId++;
				b++;
			}
			else if(desc->Type == TDT_BUTTON)
			{
				b->img = imageIndex;
				b->ID = buttonId;
				b->text = desc->ToolText;
				b->help = desc->HelpString != NULL ? desc->HelpString : desc->ToolText;
				b->exclude = desc->MutualExclude;

				b->flags = 0;
				if(desc->Flags & TDF_TOGGLE)	b->flags |= MUIV_TheBar_ButtonFlag_Toggle;
			//  if(desc->Flags & TDF_RADIO)		// not supported
				if(desc->Flags & TDF_GHOSTED)	b->flags |= MUIV_TheBar_ButtonFlag_Disabled;
				if(desc->Flags & TDF_GONE)		b->flags |= MUIV_TheBar_ButtonFlag_Hide;
				if(desc->Flags & TDF_SELECTED)	b->flags |= MUIV_TheBar_ButtonFlag_Selected;

				// the image index counts for buttons only
				imageIndex++;
				// the button ID counts for spacers and buttons
				buttonId++;
				b++;
			}

			desc++;
		}

		// terminate the button array
		b->img = MUIV_TheBar_End;
	}

	return buttons;
}

/***********************************************************************/

static Object *getButton(Object *obj, ULONG id)
{
	return (Object *)DoMethod(obj, MUIM_TheBar_GetObject, id);
}

/***********************************************************************/

static IPTR mNew(struct IClass *cl, Object *obj, struct opSet *msg)
{
	struct TagItem newTags[10];
    struct TagItem *thebarTags = newTags;
    struct TagItem *tag;
    struct TagItem *tstate;

	struct MUIS_TheBar_Button *buttons = NULL;
	BOOL horiz = TRUE;
    LONG imageType = MUIV_Toolbar_ImageType_File;
    IPTR images = 0;
    IPTR selectedImages = 0;
    IPTR disabledImages = 0;
	BOOL enableKeys = FALSE;

    ENTER();

    for(tstate = msg->ops_AttrList; (tag = NextTagItem((APTR)&tstate)); )
    {
        switch(tag->ti_Tag)
        {
			case MUIA_Toolbar_Description:
			{
				buttons = parseDescription((struct MUIP_Toolbar_Description *)tag->ti_Data);
				thebarTags->ti_Tag = MUIA_TheBar_Buttons;
				thebarTags->ti_Data = (IPTR)buttons;
				thebarTags++;
			}
			break;

			case MUIA_Toolbar_Horizontal:
			{
				horiz = tag->ti_Data;
			}
			break;

			case MUIA_Toolbar_ImageGhost:
			{
				disabledImages = tag->ti_Data;
			}
			break;

			case MUIA_Toolbar_ImageNormal:
			{
				images = tag->ti_Data;
			}
			break;

			case MUIA_Toolbar_ImageSelect:
			{
				selectedImages = tag->ti_Data;
			}
			break;

			case MUIA_Toolbar_ImageType:
			{
				imageType = tag->ti_Data;
			}
			break;

			case MUIA_Toolbar_ParseUnderscore:
			{
				enableKeys = tag->ti_Data;
			}
			break;

			case MUIA_Toolbar_Path:
			{
				thebarTags->ti_Tag = MUIA_TheBar_PicsDrawer;
				thebarTags->ti_Data = tag->ti_Data;
				thebarTags++;
			}
			break;

			case MUIA_Toolbar_Permutation:
			{
				// not supported
			}
			break;

			case MUIA_Toolbar_Reusable:
			{
				// not supported
			}
			break;
		}
	}

	if(imageType == MUIV_Toolbar_ImageType_File)
	{
		if(images != 0)
		{
			thebarTags->ti_Tag = MUIA_TheBar_Strip;
			thebarTags->ti_Data = images;
			thebarTags++;
		}
		if(selectedImages != 0)
		{
			thebarTags->ti_Tag = MUIA_TheBar_SelStrip;
			thebarTags->ti_Data = selectedImages;
			thebarTags++;
		}
		if(disabledImages != 0)
		{
			thebarTags->ti_Tag = MUIA_TheBar_DisStrip;
			thebarTags->ti_Data = disabledImages;
			thebarTags++;
		}
	}

	thebarTags->ti_Tag = MUIA_Group_Horiz;
	thebarTags->ti_Data = horiz;
	thebarTags++;

	thebarTags->ti_Tag = MUIA_TheBar_EnableKeys;
	thebarTags->ti_Data = enableKeys;
	thebarTags++;

	thebarTags->ti_Tag = TAG_DONE;

    if((obj = (Object *)DoSuperNew(cl, obj,
		TAG_MORE, newTags)) != NULL)
    {
        struct InstData *data = INST_DATA(cl, obj);

        data->buttons = buttons;
        NewList((struct List *)&data->toolbarNotifies);
        data->helpString = NULL;
    }

    RETURN((IPTR)obj);
    return (IPTR)obj;
}

/***********************************************************************/

static IPTR mDispose(struct IClass *cl, Object *obj, Msg msg)
{
	struct InstData *data = INST_DATA(cl, obj);
	IPTR res;
	struct ToolbarNotify *notify;

	ENTER();

	while((notify = (struct ToolbarNotify *)RemHead((struct List *)&data->toolbarNotifies)) != NULL)
	{
		DoSuperMethod(cl, obj, MUIM_TheBar_KillNotify, notify->notify.ID, notify->notify.attr, notify->notify.dest);
		SharedFree(notify);
	}

	if(data->buttons != NULL)
	{
		SharedFree(data->buttons);
	}

	// call the super method to let MUI clear everything else
	res = DoSuperMethodA(cl, obj, msg);

	RETURN(res);
	return res;
}

/***********************************************************************/

static IPTR mGet(struct IClass *cl, Object *obj, struct opGet *msg)
{
	struct InstData *data = INST_DATA(cl, obj);
	BOOL result = FALSE;

	ENTER();

	switch(msg->opg_AttrID)
	{
		case MUIA_Toolbar_HelpString:      *msg->opg_Storage = (IPTR)data->helpString; result = TRUE; break;
		case MUIA_Toolbar_Path:            *msg->opg_Storage = xget(obj, MUIA_TheBar_PicsDrawer); result = TRUE; break;
		case MUIA_Toolbar_Permutation:     *msg->opg_Storage = 0; result = TRUE; break;
		case MUIA_Toolbar_Qualifier:       *msg->opg_Storage = data->keyQualifier; result = TRUE; break;

		case MUIA_Version:                 *msg->opg_Storage = LIB_VERSION; result = TRUE; break;
		case MUIA_Revision:                *msg->opg_Storage = LIB_REVISION; result = TRUE; break;

		default:                           result = DoSuperMethodA(cl, obj, (Msg)msg);
	}

	RETURN(result);
	return result;
}

/***********************************************************************/

static IPTR mSets(struct IClass *cl, Object *obj, struct opSet *msg)
{
	struct InstData *data = INST_DATA(cl, obj);
    struct TagItem *tag;
    struct TagItem *tstate;
    ULONG res;

    ENTER();

    for(tstate = msg->ops_AttrList; (tag = NextTagItem((APTR)&tstate)); )
    {
        switch(tag->ti_Tag)
        {
			case MUIA_Toolbar_HelpString:
			{
				data->helpString = (CONST_STRPTR)tag->ti_Data;
			}
			break;

			case MUIA_Toolbar_Qualifier:
			{
				data->keyQualifier = tag->ti_Data;
			}
			break;

			case MUIA_TheBar_HoveredButton:
			{
				ULONG id = tag->ti_Data;
				CONST_STRPTR help = NULL;

				if(id != (ULONG)-1)
				{
					struct MUIS_TheBar_Button *b;

					// find the help string of the currently hovered button
					for(b = data->buttons; b->img != MUIV_TheBar_End; b++)
					{
						if(b->ID == id)
						{
							help = b->help;
							break;
						}
					}
				}

				// set the help string and trigger possible notifications
				set(obj, MUIA_Toolbar_HelpString, help);
			}
			break;
        }
    }

    res = DoSuperMethodA(cl, obj, (Msg)msg);

    RETURN(res);
    return res;
}

/***********************************************************************/

static IPTR mBottomEdge(UNUSED struct IClass *cl, Object *obj, struct MUIP_Toolbar_Edge *msg)
{
	IPTR result = 0;
	Object *button;

	ENTER();

	if((button = getButton(obj, msg->Button)) != NULL)
	{
		result = xget(button, MUIA_TopEdge) + xget(button, MUIA_Height) - 1;
	}

	RETURN(result);
	return result;
}

/***********************************************************************/

static IPTR mKillNotify(struct IClass *cl, Object *obj, struct MUIP_Toolbar_KillNotify *msg)
{
	struct InstData *data = INST_DATA(cl, obj);
	IPTR result = 0;
	struct ToolbarNotify *notify;

	ENTER();

	for(notify = (struct ToolbarNotify *)data->toolbarNotifies.mlh_Head; notify->link.mln_Succ != NULL; notify = (struct ToolbarNotify *)notify->link.mln_Succ)
	{
		if(notify->notify.ID == msg->TrigButton && notify->notify.attr == msg->TrigAttr)
		{
			DoSuperMethod(cl, obj, MUIM_TheBar_KillNotify, notify->notify.ID, notify->notify.attr, notify->notify.dest);
			Remove((struct Node *)notify);
			SharedFree(notify);
			break;
		}
	}

	RETURN(result);
	return result;
}

/***********************************************************************/

static IPTR mKillNotifyObj(struct IClass *cl, Object *obj, UNUSED struct MUIP_Toolbar_KillNotifyObj *msg)
{
	struct InstData *data = INST_DATA(cl, obj);
	IPTR result = 0;
	struct ToolbarNotify *notify;

	ENTER();

	while((notify = (struct ToolbarNotify *)RemHead((struct List *)&data->toolbarNotifies)) != NULL)
	{
		DoSuperMethod(cl, obj, MUIM_TheBar_KillNotify, notify->notify.ID, notify->notify.attr, notify->notify.dest);
		SharedFree(notify);
	}

	RETURN(result);
	return result;
}

/***********************************************************************/

static IPTR mLeftEdge(UNUSED struct IClass *cl, Object *obj, struct MUIP_Toolbar_Edge *msg)
{
	IPTR result = 0;
	Object *button;

	ENTER();

	if((button = getButton(obj, msg->Button)) != NULL)
	{
		result = xget(button, MUIA_LeftEdge);
	}

	RETURN(result);
	return result;
}

/***********************************************************************/

static IPTR mMultiSet(struct IClass *cl, Object *obj, struct MUIP_Toolbar_MultiSet *msg)
{
	IPTR result = FALSE;
	ULONG thebarAttr;

	ENTER();

	switch(msg->Flag)
	{
		case MUIV_Toolbar_Set_Ghosted:
		{
			thebarAttr = MUIV_TheBar_Attr_Disabled;
		}
		break;

		case MUIV_Toolbar_Set_Gone:
		{
			thebarAttr = MUIV_TheBar_Attr_Hide;
		}
		break;

		case MUIV_Toolbar_Set_Selected:
		{
			thebarAttr = MUIV_TheBar_Attr_Selected;
		}
		break;

		default:
		{
			thebarAttr = 0;
		}
		break;
	}

	if(thebarAttr != 0)
	{
		ULONG *id = &msg->Button;
		while(*id != (ULONG)-1)
		{
			DoSuperMethod(cl, obj, MUIM_TheBar_SetAttr, *id, thebarAttr, msg->Value);
			id++;
		}

		result = TRUE;
	}

	RETURN(result);
	return result;
}

/***********************************************************************/

static IPTR mNotify(struct IClass *cl, Object *obj, struct MUIP_Toolbar_Notify *msg)
{
	struct InstData *data = INST_DATA(cl, obj);
	IPTR result = FALSE;
	ULONG notifySize;
	struct ToolbarNotify *notify;

	ENTER();

	notifySize = sizeof(*notify) + msg->FollowParams * sizeof(ULONG);
	if((notify = SharedAlloc(notifySize)) != NULL)
	{
		ULONG msgSize = sizeof(notify->notify) + msg->FollowParams * sizeof(ULONG);
		ULONG *params;
		ULONG p;

		memcpy(&notify->notify, msg, msgSize);

		// adjust some attributes for TheBar
		notify->notify.MethodID = MUIM_TheBar_Notify;
		switch(msg->TrigAttr)
		{
			case MUIV_Toolbar_Notify_Pressed:
			{
				notify->notify.attr = MUIA_Pressed;
			}
			break;

			case MUIV_Toolbar_Notify_Ghosted:
			{
				notify->notify.attr = MUIA_Disabled;
			}
			break;

			case MUIV_Toolbar_Notify_Active:
			case MUIV_Toolbar_Notify_Gone:
			case MUIV_Toolbar_Notify_LeftEdge:
			case MUIV_Toolbar_Notify_RightEdge:
			case MUIV_Toolbar_Notify_TopEdge:
			case MUIV_Toolbar_Notify_BottomEdge:
			default:
			{
				// not supported
				notify->notify.attr = TAG_IGNORE;
			}
			break;
		}

		// adjust some special trigger values for TheBar
		params = &notify->notify.followParams + 1;
		for(p = 0; p < notify->notify.followParams; p++)
		{
			if(*params == MUIV_Toolbar_Qualifier)
			{
				*params = MUIV_TheBar_Qualifier;
			}
		}

		// pass the message to TheBar, if it is supported at all
		if(notify->notify.attr != TAG_IGNORE)
		{
			DoSuperMethodA(cl, obj, (Msg)&notify->notify);
			result = TRUE;
		}

		// restore the original message content for later reference
		memcpy(&notify->notify, msg, msgSize);
		AddTail((struct List *)&data->toolbarNotifies, (struct Node *)notify);
	}

	RETURN(result);
	return result;
}

/***********************************************************************/

static IPTR mRedraw(UNUSED struct IClass *cl, Object *obj, struct MUIP_Toolbar_Redraw *msg)
{
	IPTR result = TRUE;
	ULONG id;

	ENTER();

	for(id = 0; id < 32; id++)
	{
		if(msg->Changes & (1 << id))
		{
			DoSuperMethod(cl, obj, MUIM_TheBar_DoOnButton, id, MUIM_Draw, MADF_DRAWOBJECT);
		}
	}

	RETURN(result);
	return result;
}

/***********************************************************************/

static IPTR mReloadImages(UNUSED struct IClass *cl, UNUSED Object *obj, UNUSED Msg msg)
{
	IPTR result = 0;

	ENTER();

	RETURN(result);
	return result;
}

/***********************************************************************/

static IPTR mRightEdge(UNUSED struct IClass *cl, Object *obj, struct MUIP_Toolbar_Edge *msg)
{
	IPTR result = 0;
	Object *button;

	ENTER();

	if((button = getButton(obj, msg->Button)) != NULL)
	{
		result = xget(button, MUIA_LeftEdge) + xget(button, MUIA_Width) - 1;
	}

	RETURN(result);
	return result;
}

/***********************************************************************/

static IPTR mSet(struct IClass *cl, Object *obj, struct MUIP_Toolbar_Set *msg)
{
	IPTR result = TRUE;
	ULONG thebarAttr;

	ENTER();

	switch(msg->Flag)
	{
		case MUIV_Toolbar_Set_Ghosted:
		{
			thebarAttr = MUIV_TheBar_Attr_Disabled;
		}
		break;

		case MUIV_Toolbar_Set_Gone:
		{
			thebarAttr = MUIV_TheBar_Attr_Hide;
		}
		break;

		case MUIV_Toolbar_Set_Selected:
		{
			thebarAttr = MUIV_TheBar_Attr_Selected;
		}
		break;

		default:
		{
			thebarAttr = 0;
		}
		break;
	}

	if(thebarAttr != 0)
	{
		DoSuperMethod(cl, obj, MUIM_TheBar_SetAttr, msg->Button, thebarAttr, msg->Value);
	}

	RETURN(result);
	return result;
}

/***********************************************************************/

static IPTR mTopEdge(UNUSED struct IClass *cl, Object *obj, struct MUIP_Toolbar_Edge *msg)
{
	IPTR result = 0;
	Object *button;

	ENTER();

	if((button = getButton(obj, msg->Button)) != NULL)
	{
		result = xget(button, MUIA_TopEdge);
	}

	RETURN(result);
	return result;
}

/***********************************************************************/

DISPATCHER(_Dispatcher)
{
	switch(msg->MethodID)
	{
		case OM_NEW:                        return mNew(cl, obj, (APTR)msg);
		case OM_DISPOSE:                    return mDispose(cl, obj, (APTR)msg);
		case OM_GET:                        return mGet(cl, obj, (APTR)msg);
		case OM_SET:                        return mSets(cl, obj, (APTR)msg);

		case MUIM_Toolbar_BottomEdge:       return mBottomEdge(cl, obj, (APTR)msg);
		case MUIM_Toolbar_KillNotify:       return mKillNotify(cl, obj, (APTR)msg);
		case MUIM_Toolbar_KillNotifyObj:    return mKillNotifyObj(cl, obj, (APTR)msg);
		case MUIM_Toolbar_LeftEdge:         return mLeftEdge(cl, obj, (APTR)msg);
		case MUIM_Toolbar_MultiSet:         return mMultiSet(cl, obj, (APTR)msg);
		case MUIM_Toolbar_Notify:           return mNotify(cl, obj, (APTR)msg);
		case MUIM_Toolbar_Redraw:           return mRedraw(cl, obj, (APTR)msg);
		case MUIM_Toolbar_ReloadImages:     return mReloadImages(cl, obj, (APTR)msg);
		case MUIM_Toolbar_RightEdge:        return mRightEdge(cl, obj, (APTR)msg);
		case MUIM_Toolbar_Set:              return mSet(cl, obj, (APTR)msg);
		case MUIM_Toolbar_TopEdge:          return mTopEdge(cl, obj, (APTR)msg);

		default:                            return DoSuperMethodA(cl, obj, msg);
	}
}

/**********************************************************************/
