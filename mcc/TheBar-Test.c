/***************************************************************************

 TheBar.mcc - Next Generation Toolbar MUI Custom Class
 Copyright (C) 2003-2005 Alfonso Ranieri
 Copyright (C) 2005-2006 by TheBar.mcc Open Source Team

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 TheBar class Support Site:  http://www.sf.net/projects/thebar

 $Id: build.c 5 2006-11-29 00:34:46Z damato $

***************************************************************************/

#include <stdio.h>
#include <string.h>

#include <clib/alib_protos.h>

#include <exec/tasks.h>
#include <libraries/mui.h>
#include <devices/clipboard.h>
#include <libraries/iffparse.h>

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/muimaster.h>
#include <proto/intuition.h>
#include <proto/iffparse.h>
#include <proto/utility.h>

#include "private.h"
#include "mcc_common.h"
#include "class.h"
#include "Debug.h"

#include "SDI_hook.h"

// global data
static const char *appareances[] = { "Images and text", "Images", "Text", NULL};
static const char *labelPoss[] = { "Bottom", "Top", "Right", "Left", NULL};

static struct MUIS_TheBar_Button buttons[] =
{
  { 0, 0, "_Pred", "Pread mail.",    0, 0, NULL, NULL },
  { 1, 1, "_Next", "Next mail.",     0, 0, NULL, NULL },
  { 2, 2, "_Move", "Move somewhere.",0, 0, NULL, NULL },
  { MUIV_TheBar_BarSpacer, 3, NULL, NULL, 0, 0, NULL, NULL },
  { 3, 4, "_Forw", "Forward somewhere.", 0, 0, NULL, NULL },
  { 4, 5, "F_ind", "Find something.", 0, 0, NULL, NULL },
  { 5, 6, "_Save", "Save mail.", 0, 0, NULL, NULL },
  { MUIV_TheBar_End , 0, NULL, NULL, 0, 0, NULL, NULL },
};


// static hooks

#if defined(__amigaos4__)
struct Library *DiskfontBase = NULL;
struct Library *GfxBase = NULL;
struct Library *IntuitionBase = NULL;
struct Library *KeymapBase = NULL;
struct Library *LayersBase = NULL;
struct Library *LocaleBase = NULL;
struct Library *MUIMasterBase = NULL;
struct Library *RexxSysBase = NULL;
struct Library *UtilityBase = NULL;
struct Library *IFFParseBase = NULL;
struct Library *WorkbenchBase = NULL;
struct Library *CyberGfxBase = NULL;
struct Library *DataTypesBase = NULL;
#elif defined(__MORPHOS__)
struct Library *DiskfontBase = NULL;
struct Library *GfxBase = NULL;
struct IntuitionBase *IntuitionBase = NULL;
struct Library *KeymapBase = NULL;
struct Library *LayersBase = NULL;
struct Library *LocaleBase = NULL;
struct Library *MUIMasterBase = NULL;
struct Library *RexxSysBase = NULL;
struct Library *UtilityBase = NULL;
struct Library *IFFParseBase = NULL;
struct Library *WorkbenchBase = NULL;
struct Library *CyberGfxBase = NULL;
struct Library *DataTypesBase = NULL;
#else
struct Library *DiskfontBase = NULL;
struct Library *GfxBase = NULL;
struct IntuitionBase *IntuitionBase = NULL;
struct Library *KeymapBase = NULL;
struct Library *LayersBase = NULL;
struct Library *LocaleBase = NULL;
struct Library *MUIMasterBase = NULL;
struct Library *RexxSysBase = NULL;
struct Library *UtilityBase = NULL;
struct Library *IFFParseBase = NULL;
struct Library *WorkbenchBase = NULL;
struct Library *CyberGfxBase = NULL;
struct Library *DataTypesBase = NULL;
#endif

#if defined(__amigaos4__)
struct DiskfontIFace *IDiskfont = NULL;
struct GraphicsIFace *IGraphics = NULL;
struct IntuitionIFace *IIntuition = NULL;
struct KeymapIFace *IKeymap = NULL;
struct LayersIFace *ILayers = NULL;
struct LocaleIFace *ILocale = NULL;
struct MUIMasterIFace *IMUIMaster = NULL;
struct RexxSysIFace *IRexxSys = NULL;
struct UtilityIFace *IUtility = NULL;
struct IFFParseIFace *IIFFParse = NULL;
struct WorkbenchIFace *IWorkbench = NULL;
struct CyberGfxIFace *ICyberGfx = NULL;
struct DataTypesIFace *IDataTypes = NULL;
#endif

DISPATCHERPROTO(_Dispatcher);
struct  MUI_CustomClass *ThisClass = NULL;
struct MUI_CustomClass *lib_spacerClass = NULL;
struct MUI_CustomClass *lib_dragBarClass = NULL;
ULONG lib_flags = 0;

int main(void)
{
  if((DiskfontBase = OpenLibrary("diskfont.library", 38)) &&
    GETINTERFACE(IDiskfont, DiskfontBase))
  if((GfxBase = OpenLibrary("graphics.library", 38)) &&
    GETINTERFACE(IGraphics, GfxBase))
  if((IntuitionBase = (APTR)OpenLibrary("intuition.library", 38)) &&
    GETINTERFACE(IIntuition, IntuitionBase))
  if((KeymapBase = OpenLibrary("keymap.library", 38)) &&
    GETINTERFACE(IKeymap, KeymapBase))
  if((LayersBase = OpenLibrary("layers.library", 38)) &&
    GETINTERFACE(ILayers, LayersBase))
  if((LocaleBase = OpenLibrary("locale.library", 38)) &&
    GETINTERFACE(ILocale, LocaleBase))
  if((RexxSysBase = OpenLibrary("rexxsyslib.library", 36)) &&
    GETINTERFACE(IRexxSys, RexxSysBase))
  if((UtilityBase = OpenLibrary("utility.library", 38)) &&
    GETINTERFACE(IUtility, UtilityBase))
  if((IFFParseBase = OpenLibrary("iffparse.library", 36)) &&
    GETINTERFACE(IIFFParse, IFFParseBase))
  if((DataTypesBase = OpenLibrary("datatypes.library", 37)) &&
    GETINTERFACE(IDataTypes, DataTypesBase))
  {
  	// Open cybergraphics.library (optional)
    if((CyberGfxBase = OpenLibrary("cybergraphics.library", 41)) &&
       GETINTERFACE(ICyberGfx, CyberGfxBase) == FALSE)
    {
      CloseLibrary(CyberGfxBase);
      CyberGfxBase = NULL;
    }

  	// Open workbench.library (optional)
		if((WorkbenchBase = OpenLibrary("workbench.library", 0)) &&
  		 GETINTERFACE(IWorkbench, WorkbenchBase) == FALSE)
		{
      CloseLibrary(WorkbenchBase);
      WorkbenchBase = NULL;
    }

    #if defined(DEBUG)
    SetupDebug();
    #endif

    ENTER();

    if((MUIMasterBase = OpenLibrary("muimaster.library", MUIMASTER_VMIN)) &&
      GETINTERFACE(IMUIMaster, MUIMasterBase))
    {
      Object *app, *win, *sb, *appareance, *labelPos, *borderless, *sunny, *raised, *scaled, *update;

      // now we init our subclasses
      initSpacerClass();
      initDragBarClass();

      ThisClass = MUI_CreateCustomClass(NULL, MUIC_Group, NULL, sizeof(struct InstData), ENTRY(_Dispatcher));

      if(ThisClass && (app = ApplicationObject,
                         MUIA_Application_Title,         "TheBar Demo1",
                         MUIA_Application_Version,       "$VER: TheBarDemo1 1.0 (24.6.2003)",
                         MUIA_Application_Copyright,     "Copyright 2003 by Alfonso Ranieri",
                         MUIA_Application_Author,        "Alfonso Ranieri <alforan@tin.it>",
                         MUIA_Application_Description,  "TheBar example",
                         MUIA_Application_Base,         "THEBAREXAMPLE",

                         SubWindow, win = WindowObject,
                           MUIA_Window_ID,             MAKE_ID('M','A','I','N'),
                           MUIA_Window_Title,          "TheBar Demo1",
                           WindowContents, VGroup,
                             Child, sb = NewObject(ThisClass->mcc_Class, NULL,
                               MUIA_Group_Horiz,       TRUE,
                               MUIA_TheBar_EnableKeys, TRUE,
                               MUIA_TheBar_Buttons,    buttons,
                               MUIA_TheBar_PicsDrawer, "PROGDIR://demo/pics",
                               MUIA_TheBar_Strip,      "Read.toolbar",
                               MUIA_TheBar_SelStrip,   "Read_S.toolbar",
                               MUIA_TheBar_DisStrip,   "Read_G.toolbar",
                               MUIA_TheBar_StripCols,  11,
                             End,
                             Child, VGroup,
                               GroupFrameT("Settings"),
                               Child, HGroup,
                                 Child, Label2("Appareance"),
                                 Child, appareance = MUI_MakeObject(MUIO_Cycle,NULL,appareances),
                                 Child, Label2("Label pos"),
                                 Child, labelPos = MUI_MakeObject(MUIO_Cycle,NULL,labelPoss),
                               End,
                               Child, HGroup,
                                 Child, HSpace(0),
                                 Child, Label1("Borderless"),
                                 Child, borderless = MUI_MakeObject(MUIO_Checkmark,NULL),
                                 Child, HSpace(0),
                                 Child, Label1("Sunny"),
                                 Child, sunny = MUI_MakeObject(MUIO_Checkmark,NULL),
                                 Child, HSpace(0),
                                 Child, Label1("Raised"),
                                 Child, raised = MUI_MakeObject(MUIO_Checkmark,NULL),
                                 Child, HSpace(0),
                                 Child, Label1("Scaled"),
                                 Child, scaled = MUI_MakeObject(MUIO_Checkmark,NULL),
                                 Child, HSpace(0),
                               End,
                             End,
                             Child, update = MUI_MakeObject(MUIO_Button,"_Update"),
                           End,
                         End,
                       End))
      {
        ULONG sigs = 0, id;

        DoMethod(win,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,MUIV_Notify_Application,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);
        DoMethod(update,MUIM_Notify,MUIA_Pressed,FALSE,app,2,MUIM_Application_ReturnID,TAG_USER);

        set(win,MUIA_Window_Open,TRUE);

        while((LONG)(id = DoMethod(app,MUIM_Application_NewInput,&sigs)) != MUIV_Application_ReturnID_Quit)
        {
          if(id==TAG_USER)
          {
            ULONG appareanceV, labelPosV, borderlessV, sunnyV, raisedV, scaledV;

            get(appareance,MUIA_Cycle_Active,&appareanceV);
            get(labelPos,MUIA_Cycle_Active,&labelPosV);
            get(borderless,MUIA_Selected,&borderlessV);
            get(sunny,MUIA_Selected,&sunnyV);
            get(raised,MUIA_Selected,&raisedV);
            get(scaled,MUIA_Selected,&scaledV);

            SetAttrs(sb,MUIA_TheBar_ViewMode,   appareanceV,
                        MUIA_TheBar_LabelPos,   labelPosV,
                        MUIA_TheBar_Borderless, borderlessV,
                        MUIA_TheBar_Sunny,      sunnyV,
                        MUIA_TheBar_Raised,     raisedV,
                        MUIA_TheBar_Scaled,     scaledV,
                        TAG_DONE);
          }

          if(sigs)
          {
            sigs = Wait(sigs | SIGBREAKF_CTRL_C);
            if(sigs & SIGBREAKF_CTRL_C) break;
          }
        }

        D(DBF_STARTUP, "cleaning up application object...");
        MUI_DisposeObject(app);
        
        D(DBF_STARTUP, "cleaning up mcc...");
        if(ThisClass)
          MUI_DeleteCustomClass(ThisClass);
      }
      else
        printf("Failed to create application\n");

     if(lib_dragBarClass)
       MUI_DeleteCustomClass(lib_dragBarClass);

     if(lib_spacerClass)
       MUI_DeleteCustomClass(lib_spacerClass);

      DROPINTERFACE(IMUIMaster);
      CloseLibrary(MUIMasterBase);
      MUIMasterBase = NULL;
    }
  }

  D(DBF_STARTUP, "freeing library bases/interfaces...");

	if(WorkbenchBase)
	{
		DROPINTERFACE(IWorkbench);
		WorkbenchBase = NULL;
	}

  if(CyberGfxBase)
  {
    DROPINTERFACE(ICyberGfx);
    CloseLibrary(CyberGfxBase);
    CyberGfxBase = NULL;
  }

  if(DataTypesBase)
  {
    DROPINTERFACE(IDataTypes);
    CloseLibrary(DataTypesBase);
    DataTypesBase = NULL;
  }

  if(IFFParseBase)
  {
    DROPINTERFACE(IIFFParse);
    CloseLibrary(IFFParseBase);
    IFFParseBase = NULL;
  }

  if(UtilityBase)
  {
    DROPINTERFACE(IUtility);
    CloseLibrary(UtilityBase);
  }

  if(RexxSysBase)
  {
    DROPINTERFACE(IRexxSys);
    CloseLibrary(RexxSysBase);
  }

  if(LocaleBase)
  {
    DROPINTERFACE(ILocale);
    CloseLibrary(LocaleBase);
  }

  if(LayersBase)
  {
    DROPINTERFACE(ILayers);
    CloseLibrary(LayersBase);
  }

  if(KeymapBase)
  {
    DROPINTERFACE(IKeymap);
    CloseLibrary(KeymapBase);
  }

  if(IntuitionBase)
  {
    DROPINTERFACE(IIntuition);
    CloseLibrary((struct Library *)IntuitionBase);
  }

  if(GfxBase)
  {
    DROPINTERFACE(IGraphics);
    CloseLibrary(GfxBase);
  }

  if(DiskfontBase)
  {
    DROPINTERFACE(IDiskfont);
    CloseLibrary(DiskfontBase);
  }

  RETURN(0);
  return 0;
}
