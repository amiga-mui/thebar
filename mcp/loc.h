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

#ifndef LOC_H
#define LOC_H


/****************************************************************************/


/* This file was created automatically by CatComp.
 * Do NOT edit by hand!
 */


#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifdef CATCOMP_ARRAY
#undef CATCOMP_NUMBERS
#undef CATCOMP_STRINGS
#define CATCOMP_NUMBERS
#define CATCOMP_STRINGS
#endif

#ifdef CATCOMP_BLOCK
#undef CATCOMP_STRINGS
#define CATCOMP_STRINGS
#endif


/****************************************************************************/


#ifdef CATCOMP_NUMBERS

#define Msg_Reg_Colors 1
#define Msg_Reg_Appareance 2
#define Msg_Reg_Spacing 3
#define Msg_Reg_Options 4
#define Msg_Title_Backgrounds 100
#define Msg_GroupBackground 101
#define Msg_GroupBackground_Help 102
#define Msg_GroupBackground_Title 103
#define Msg_UseGroupBackground 104
#define Msg_UseGroupBackground_Help 105
#define Msg_ButtonBackground 106
#define Msg_ButtonBackground_Help 107
#define Msg_ButtonBackground_Title 108
#define Msg_UseButtonBackground 109
#define Msg_UseButtonBackground_Help 110
#define Msg_Title_Frame 111
#define Msg_FrameShinePen 112
#define Msg_FrameShinePen_Help 113
#define Msg_FrameShinePen_Title 114
#define Msg_FrameShadowPen 115
#define Msg_FrameShadowPen_Help 116
#define Msg_FrameShadowPen_Title 117
#define Msg_FrameStyle_Recessed 118
#define Msg_FrameStyle_Normal 119
#define Msg_FrameStyle 120
#define Msg_FrameStyle_Help 121
#define Msg_Title_Disabled 122
#define Msg_DisabledBody 123
#define Msg_DisabledBody_Help 124
#define Msg_DisabledBody_Title 125
#define Msg_DisabledShadow 126
#define Msg_DisabledShadow_Help 127
#define Msg_DisabledShadow_Title 128
#define Msg_Title_BarSpacer 129
#define Msg_BarSpacerShinePen 130
#define Msg_BarSpacerShinePen_Help 131
#define Msg_BarSpacerShinePen_Title 132
#define Msg_BarSpacerShadowPen 133
#define Msg_BarSpacerShadowPen_Help 134
#define Msg_BarSpacerShadowPen_Title 135
#define Msg_Title_BarFrame 136
#define Msg_BarFrameShine 137
#define Msg_BarFrameShine_Help 138
#define Msg_BarFrameShine_Title 139
#define Msg_BarFrameShadow 140
#define Msg_BarFrameShadow_Help 141
#define Msg_BarFrameShadow_Title 142
#define Msg_Title_DragBar 143
#define Msg_DragBarShine 144
#define Msg_DragBarShine_Help 145
#define Msg_DragBarShine_Title 146
#define Msg_DragBarShadow 147
#define Msg_DragBarShadow_Help 148
#define Msg_DragBarShadow_Title 149
#define Msg_DragBarFill 150
#define Msg_DragBarFill_Help 151
#define Msg_DragBarFill_Title 152
#define Msg_UseDragBarFill 153
#define Msg_UseDragBarFill_Help 154
#define Msg_Frame 155
#define Msg_Frame_Help 156
#define Msg_Frame_Title 157
#define Msg_TextFont 200
#define Msg_TextFont_Help 201
#define Msg_TextGfxFont 202
#define Msg_TextGfxFont_Help 203
#define Msg_ViewMode 204
#define Msg_ViewMode_Help 205
#define Msg_Appareance_Text 206
#define Msg_TextGfx 207
#define Msg_Gfx 208
#define Msg_Text 209
#define Msg_Borderless 210
#define Msg_Borderless_Help 211
#define Msg_Sunny 212
#define Msg_Sunny_Help 213
#define Msg_Raised 214
#define Msg_Raised_Help 215
#define Msg_Scaled 216
#define Msg_Scaled_Help 217
#define Msg_BarSpacer 218
#define Msg_BarSpacer_Help 219
#define Msg_EnableKeys 220
#define Msg_EnableKeys_Help 221
#define Msg_LabelPos 222
#define Msg_LabelPos_Help 223
#define Msg_LabelPos_Bottom 224
#define Msg_LabelPos_Top 225
#define Msg_LabelPos_Right 226
#define Msg_LabelPos_Left 227
#define Msg_Title_GroupSpacing 300
#define Msg_HorizGroupSpacing 301
#define Msg_HorizGroupSpacing_Help 302
#define Msg_VertGroupSpacing 303
#define Msg_VertGroupSpacing_Help 304
#define Msg_BarSpacerSpacing 305
#define Msg_BarSpacerSpacing_Help 306
#define Msg_Title_InnerSpacing 307
#define Msg_HorizInnerSpacing 308
#define Msg_HorizInnerSpacing_Help 309
#define Msg_TopInnerSpacing 310
#define Msg_TopInnerSpacing_Help 311
#define Msg_BottomInnerSpacing 312
#define Msg_BottomInnerSpacing_Help 313
#define Msg_Title_BarFrameSpacing 314
#define Msg_LeftBarFrameSpacing 315
#define Msg_LeftBarFrameSpacing_Help 316
#define Msg_RightBarFrameSpacing 317
#define Msg_RightBarFrameSpacing_Help 318
#define Msg_TopBarFrameSpacing 319
#define Msg_TopBarFrameSpacing_Help 320
#define Msg_BottomBarFrameSpacing 321
#define Msg_BottomBarFrameSpacing_Help 322
#define Msg_Title_TextGfxSpacing 323
#define Msg_HorizTextGfxSpacing 324
#define Msg_HorizTextGfxSpacing_Help 325
#define Msg_VertTextGfxSpacing 326
#define Msg_VertTextGfxSpacing_Help 327
#define Msg_Precision_Gui 400
#define Msg_Precision_Icon 401
#define Msg_Precision_Image 402
#define Msg_Precision_Exact 403
#define Msg_Precision 404
#define Msg_Precision_Help 405
#define Msg_Event_IntuiTicks 406
#define Msg_Event_MouseMove 407
#define Msg_Event 408
#define Msg_Event_Help 409
#define Msg_Scale 410
#define Msg_Scale_Help 411
#define Msg_SpecialSelect 412
#define Msg_SpecialSelect_Help 413
#define Msg_TextOverUseShine 414
#define Msg_TextOverUseShine_Help 415
#define Msg_IgnoreSelImages 416
#define Msg_IgnoreSelImages_Help 417
#define Msg_IgnoreDisImages 418
#define Msg_IgnoreDisImages_Help 419
#define Msg_DisMode_Shape 420
#define Msg_DisMode_Grid 421
#define Msg_DisMode_FullGrid 422
#define Msg_DisMode 423
#define Msg_DisMode_Help 424
#define Msg_DontMove 425
#define Msg_DontMove_Help 426
#define Msg_DisMode_Sunny 427
#define Msg_NtRaiseActive 428
#define Msg_NtRaiseActive_Help 429
#define Msg_SpacersSize 430
#define Msg_SpacersSize_Help 431
#define Msg_SpacersSize_Quarter 432
#define Msg_SpacersSize_Half 433
#define Msg_SpacersSize_One 434
#define Msg_Event_MouseObject 435
#define Msg_Item_Defaults 500
#define Msg_Item_alfie_Defaults 501
#define Msg_NoMUI20Event_Help 502
#define Msg_Info_First 600
#define Msg_Info_Reserved 601
#define Msg_Info_Rest 602
#define Msg_Info_Translator 603
#define Msg_Item_Globals 604
#define Msg_Item_LastSaved 605
#define Msg_Item_Restore 606
#define Msg_Pop_OK 700
#define Msg_Pop_OK_Help 701
#define Msg_Pop_Cancel 702
#define Msg_Pop_Cancel_Help 703
#define Msg_Popback_Pattern 710
#define Msg_Popback_Color 711
#define Msg_Popback_Bitmap 712
#define Msg_Popback_Gradient 713
#define Msg_Popback_HorizGradient 714
#define Msg_Popback_HorizGradientHelp 715
#define Msg_Popback_VertGradient 716
#define Msg_Popback_VertGradientHelp 717
#define Msg_Popback_From 718
#define Msg_Popback_To 719
#define Msg_Popback_Swap 720
#define Msg_Popback_SwapHelp 721
#define Msg_Poppen_MUI 800
#define Msg_Poppen_Colormap 801
#define Msg_Poppen_RGB 802
#define Msg_Poppen_Shine 803
#define Msg_Poppen_Halfshine 804
#define Msg_Poppen_Background 805
#define Msg_Poppen_Halfshadow 806
#define Msg_Poppen_Shadow 807
#define Msg_Poppen_Text 808
#define Msg_Poppen_Fill 809
#define Msg_Poppen_Mark 810
#define Msg_Poppen_ColorMapHelp 811
#define Msg_ColoradjustRed 900
#define Msg_Coloradjust_RedHelp 901
#define Msg_ColoradjustGreen 902
#define Msg_Coloradjust_GreenHelp 903
#define Msg_ColoradjustBlue 904
#define Msg_Coloradjust_BlueHelp 905
#define Msg_Coloradjust_WheelAbbr 906
#define Msg_Coloradjust_WheelHelp 907
#define Msg_Coloradjust_GradientHelp 908
#define Msg_PrefsShortHelp 1000

#endif /* CATCOMP_NUMBERS */


/****************************************************************************/


#ifdef CATCOMP_STRINGS

#define Msg_Reg_Colors_STR "Colors"
#define Msg_Reg_Appareance_STR "Appareance"
#define Msg_Reg_Spacing_STR "Spacing"
#define Msg_Reg_Options_STR "Options"
#define Msg_Title_Backgrounds_STR "Backgrounds"
#define Msg_GroupBackground_STR "Bar"
#define Msg_GroupBackground_Help_STR "Bar background."
#define Msg_GroupBackground_Title_STR "Bar background"
#define Msg_UseGroupBackground_STR "Active"
#define Msg_UseGroupBackground_Help_STR "If selected, the bar gets\nyour preferred background,\notherwise it gets its\nparent background."
#define Msg_ButtonBackground_STR "Buttons"
#define Msg_ButtonBackground_Help_STR "Active buttons background."
#define Msg_ButtonBackground_Title_STR "Active buttons background"
#define Msg_UseButtonBackground_STR "Active"
#define Msg_UseButtonBackground_Help_STR "If selected, the buttons get\nyour preferred background,\notherwise they get their\nparent background."
#define Msg_Title_Frame_STR "Buttons frame"
#define Msg_FrameShinePen_STR "Shine"
#define Msg_FrameShinePen_Help_STR "Active buttons frame shine pen."
#define Msg_FrameShinePen_Title_STR "Frame shine pen"
#define Msg_FrameShadowPen_STR "Shadow"
#define Msg_FrameShadowPen_Help_STR "Active buttons frame shadow pen."
#define Msg_FrameShadowPen_Title_STR "Frame shadow pen"
#define Msg_FrameStyle_Recessed_STR "Recessed"
#define Msg_FrameStyle_Normal_STR "Normal"
#define Msg_FrameStyle_STR "Style"
#define Msg_FrameStyle_Help_STR "Active buttons frame style."
#define Msg_Title_Disabled_STR "Disabled buttons"
#define Msg_DisabledBody_STR "Body"
#define Msg_DisabledBody_Help_STR "Disabled buttons body pen. It is used as\nmain pen for disabled buttons in Shape\nmode and as grid pen for disabled\nbuttons in Grid modes."
#define Msg_DisabledBody_Title_STR "Body pen"
#define Msg_DisabledShadow_STR "Shadow"
#define Msg_DisabledShadow_Help_STR "Disabled buttons shadow pen. It is used as\nsecondary pen for disabled buttons in Shape\nmode and as text pen for disabled buttons\nin Grid modes."
#define Msg_DisabledShadow_Title_STR "Shadow pen"
#define Msg_Title_BarSpacer_STR "Bar spacer"
#define Msg_BarSpacerShinePen_STR "Shine"
#define Msg_BarSpacerShinePen_Help_STR "Bar spacer shine pen."
#define Msg_BarSpacerShinePen_Title_STR "Spacer shine pen"
#define Msg_BarSpacerShadowPen_STR "Shadow"
#define Msg_BarSpacerShadowPen_Help_STR "Bar spacer shadow pen."
#define Msg_BarSpacerShadowPen_Title_STR "Spacer shadow pen"
#define Msg_Title_BarFrame_STR "Bar frame"
#define Msg_BarFrameShine_STR "Shine"
#define Msg_BarFrameShine_Help_STR "Bar frame shine pen."
#define Msg_BarFrameShine_Title_STR "Frame shine pen"
#define Msg_BarFrameShadow_STR "Shadow"
#define Msg_BarFrameShadow_Help_STR "Bar frame shadow pen."
#define Msg_BarFrameShadow_Title_STR "Frame shadow pen"
#define Msg_Title_DragBar_STR "DragBar"
#define Msg_DragBarShine_STR "Shine"
#define Msg_DragBarShine_Help_STR "DragBar shine pen."
#define Msg_DragBarShine_Title_STR "DragBar shine pen"
#define Msg_DragBarShadow_STR "Shadow"
#define Msg_DragBarShadow_Help_STR "DragBar shadow pen."
#define Msg_DragBarShadow_Title_STR "DragBar shadow pen"
#define Msg_DragBarFill_STR "Fill"
#define Msg_DragBarFill_Help_STR "DragBar fill pen."
#define Msg_DragBarFill_Title_STR "DragBar fill pen"
#define Msg_UseDragBarFill_STR "Use"
#define Msg_UseDragBarFill_Help_STR "If selected, the dragbar fill\npen is used."
#define Msg_Frame_STR "Frame"
#define Msg_Frame_Help_STR "Bar frame"
#define Msg_Frame_Title_STR "Bar frame"
#define Msg_TextFont_STR "Text"
#define Msg_TextFont_Help_STR "Text only buttons font."
#define Msg_TextGfxFont_STR "TextGfx"
#define Msg_TextGfxFont_Help_STR "Text and image buttons font."
#define Msg_ViewMode_STR "View mode"
#define Msg_ViewMode_Help_STR "Adjust the appareance of the buttons."
#define Msg_Appareance_Text_STR "The options below are used by TheBar if and only if the\nobject requested for it at creation time. It means that\nif the programmer didn't decide otherwise, they are simply\nignored."
#define Msg_TextGfx_STR "Icons and text"
#define Msg_Gfx_STR "Icons only"
#define Msg_Text_STR "Text only"
#define Msg_Borderless_STR "Borderless"
#define Msg_Borderless_Help_STR "If selected, buttons are borderless."
#define Msg_Sunny_STR "Highlight"
#define Msg_Sunny_Help_STR "If selected, buttons, normally in black\nand white, are colored when the\nmouse is over them."
#define Msg_Raised_STR "Raised"
#define Msg_Raised_Help_STR "If selected, buttons, normally frameless,\nare framed when the mouse is over them."
#define Msg_Scaled_STR "Scaled"
#define Msg_Scaled_Help_STR "If selected, buttons are scaled."
#define Msg_BarSpacer_STR "Bar spacer"
#define Msg_BarSpacer_Help_STR "If selected, a bar spacer is used\nas buttons separator."
#define Msg_EnableKeys_STR "Enable keys"
#define Msg_EnableKeys_Help_STR "If selected, buttons short cuts\nare active."
#define Msg_LabelPos_STR "Labels at"
#define Msg_LabelPos_Help_STR "Adjust the position of text in\nIcons and text buttons."
#define Msg_LabelPos_Bottom_STR "Bottom"
#define Msg_LabelPos_Top_STR "Top"
#define Msg_LabelPos_Right_STR "Right"
#define Msg_LabelPos_Left_STR "Left"
#define Msg_Title_GroupSpacing_STR "Bar"
#define Msg_HorizGroupSpacing_STR "Horiz"
#define Msg_HorizGroupSpacing_Help_STR "Pixels between two buttons in a bar row."
#define Msg_VertGroupSpacing_STR "Vert"
#define Msg_VertGroupSpacing_Help_STR "Pixels between two bar rows."
#define Msg_BarSpacerSpacing_STR "Bar"
#define Msg_BarSpacerSpacing_Help_STR "Pixels between a Bar spacer\nand the previous/next object."
#define Msg_Title_InnerSpacing_STR "Buttons"
#define Msg_HorizInnerSpacing_STR "Horiz"
#define Msg_HorizInnerSpacing_Help_STR "Pixels between the left/right frame\nborder and the button contents."
#define Msg_TopInnerSpacing_STR "Top"
#define Msg_TopInnerSpacing_Help_STR "Pixels between the top frame border\nand the button contents."
#define Msg_BottomInnerSpacing_STR "Bottom"
#define Msg_BottomInnerSpacing_Help_STR "Pixels between the bottom frame border\nand the button contents."
#define Msg_Title_BarFrameSpacing_STR "Bar frame"
#define Msg_LeftBarFrameSpacing_STR "Left"
#define Msg_LeftBarFrameSpacing_Help_STR "Pixels between the left frame border\nand the bar contents."
#define Msg_RightBarFrameSpacing_STR "Right"
#define Msg_RightBarFrameSpacing_Help_STR "Pixels between the right frame border\nand the bar contents."
#define Msg_TopBarFrameSpacing_STR "Top"
#define Msg_TopBarFrameSpacing_Help_STR "Pixels between the top frame border\nand the bar contents."
#define Msg_BottomBarFrameSpacing_STR "Bottom"
#define Msg_BottomBarFrameSpacing_Help_STR "Pixels between the bottom frame border\nand the bar contents."
#define Msg_Title_TextGfxSpacing_STR "Text/Gfx"
#define Msg_HorizTextGfxSpacing_STR "Horiz"
#define Msg_HorizTextGfxSpacing_Help_STR "Pixels between an image and\nits left/right placed label."
#define Msg_VertTextGfxSpacing_STR "Vert"
#define Msg_VertTextGfxSpacing_Help_STR "Pixels between an image and\nits bottom/top placed label."
#define Msg_Precision_Gui_STR "Bad"
#define Msg_Precision_Icon_STR "Poor"
#define Msg_Precision_Image_STR "Good"
#define Msg_Precision_Exact_STR "Best"
#define Msg_Precision_STR "Quality"
#define Msg_Precision_Help_STR "Precision to use when obtaining pens."
#define Msg_Event_IntuiTicks_STR "IntuiTicks"
#define Msg_Event_MouseMove_STR "MouseMove"
#define Msg_Event_STR "Event"
#define Msg_Event_Help_STR "How to verify if the mouse is over a button:\n- IntuiTicks: it is verified periodically\n- MouseMove: it is verified at every mouse move\n- MouseObject, it is verified at when the mouse\nover a new object"
#define Msg_Scale_STR "Scale"
#define Msg_Scale_Help_STR "Scale factor for scaled images."
#define Msg_SpecialSelect_STR "Special select"
#define Msg_SpecialSelect_Help_STR "If selected, buttons contents is moved\nwhen they are selected or active."
#define Msg_TextOverUseShine_STR "Special text"
#define Msg_TextOverUseShine_Help_STR "If selected, active buttons labels\nare drawn with the shine pen."
#define Msg_IgnoreSelImages_STR "Ignore selected images"
#define Msg_IgnoreSelImages_Help_STR "If selected, selected images\nare ignored."
#define Msg_IgnoreDisImages_STR "Ignore disabled images"
#define Msg_IgnoreDisImages_Help_STR "If selected, disabled images\nare ignored."
#define Msg_DisMode_Shape_STR "Shape"
#define Msg_DisMode_Grid_STR "Grid"
#define Msg_DisMode_FullGrid_STR "Full grid"
#define Msg_DisMode_STR "Disable"
#define Msg_DisMode_Help_STR "How to render disabled buttons."
#define Msg_DontMove_STR "Don't move"
#define Msg_DontMove_Help_STR "If selected, the contents of the buttons\nis not moved when they are active."
#define Msg_DisMode_Sunny_STR "Grey"
#define Msg_NtRaiseActive_STR "Don't raise active buttons"
#define Msg_NtRaiseActive_Help_STR "If selected, active buttons are not raised."
#define Msg_SpacersSize_STR "Spacers size"
#define Msg_SpacersSize_Help_STR "Size of spacers."
#define Msg_SpacersSize_Quarter_STR "Quarter of a button"
#define Msg_SpacersSize_Half_STR "Half of a button"
#define Msg_SpacersSize_One_STR "As a button"
#define Msg_Event_MouseObject_STR "MouseObject"
#define Msg_Item_Defaults_STR "Reset to defaults"
#define Msg_Item_alfie_Defaults_STR "alfie's defaults"
#define Msg_NoMUI20Event_Help_STR "How to verify if the mouse is over a button:\n- IntuiTicks: it is verified periodically\n- MouseMove: it is verified at every mouse move"
#define Msg_Info_First_STR "%s\nCopyright 2003-2005 by Alfonso Ranieri."
#define Msg_Info_Reserved_STR "All Rights Are Reserved."
#define Msg_Info_Rest_STR "Please write to <alforan@tin.it> for\ndevelopers docs and licensing terms."
#define Msg_Info_Translator_STR ""
#define Msg_Item_Globals_STR "Reset to global"
#define Msg_Item_LastSaved_STR "Last saved"
#define Msg_Item_Restore_STR "Restore"
#define Msg_Pop_OK_STR "OK"
#define Msg_Pop_OK_Help_STR "Accept changes."
#define Msg_Pop_Cancel_STR "Cancel"
#define Msg_Pop_Cancel_Help_STR "Exit without changing."
#define Msg_Popback_Pattern_STR "Pattern"
#define Msg_Popback_Color_STR "Color"
#define Msg_Popback_Bitmap_STR "Bitmap"
#define Msg_Popback_Gradient_STR "Gradient"
#define Msg_Popback_HorizGradient_STR "Horizontal"
#define Msg_Popback_HorizGradientHelp_STR "If selected, you get a\nhorizontal gradient."
#define Msg_Popback_VertGradient_STR "Vertical"
#define Msg_Popback_VertGradientHelp_STR "If selected, you get a\nvertical gradient."
#define Msg_Popback_From_STR "From color"
#define Msg_Popback_To_STR "To color"
#define Msg_Popback_Swap_STR "Swap"
#define Msg_Popback_SwapHelp_STR "Swaps from/to colors."
#define Msg_Poppen_MUI_STR "MUI"
#define Msg_Poppen_Colormap_STR "Colormap"
#define Msg_Poppen_RGB_STR "RGB"
#define Msg_Poppen_Shine_STR "Shine"
#define Msg_Poppen_Halfshine_STR "Halfshine"
#define Msg_Poppen_Background_STR "Background"
#define Msg_Poppen_Halfshadow_STR "Halfshadow"
#define Msg_Poppen_Shadow_STR "Shadow"
#define Msg_Poppen_Text_STR "Text"
#define Msg_Poppen_Fill_STR "Fill"
#define Msg_Poppen_Mark_STR "Mark"
#define Msg_Poppen_ColorMapHelp_STR "Select a screen color entry."
#define Msg_ColoradjustRed_STR "Red"
#define Msg_Coloradjust_RedHelp_STR "The red component of the color."
#define Msg_ColoradjustGreen_STR "Green"
#define Msg_Coloradjust_GreenHelp_STR "The green component of the color."
#define Msg_ColoradjustBlue_STR "Blue"
#define Msg_Coloradjust_BlueHelp_STR "The blue component of the color."
#define Msg_Coloradjust_WheelAbbr_STR "GCBMRY"
#define Msg_Coloradjust_WheelHelp_STR "Move the mouse to select a color."
#define Msg_Coloradjust_GradientHelp_STR "The brightness of the color."
#define Msg_PrefsShortHelp_STR "Next generation tool bar class."

#endif /* CATCOMP_STRINGS */


/****************************************************************************/


#ifdef CATCOMP_ARRAY

struct CatCompArrayType
{
    LONG   cca_ID;
    STRPTR cca_Str;
};

static const struct CatCompArrayType CatCompArray[] =
{
    {Msg_Reg_Colors,(STRPTR)Msg_Reg_Colors_STR},
    {Msg_Reg_Appareance,(STRPTR)Msg_Reg_Appareance_STR},
    {Msg_Reg_Spacing,(STRPTR)Msg_Reg_Spacing_STR},
    {Msg_Reg_Options,(STRPTR)Msg_Reg_Options_STR},
    {Msg_Title_Backgrounds,(STRPTR)Msg_Title_Backgrounds_STR},
    {Msg_GroupBackground,(STRPTR)Msg_GroupBackground_STR},
    {Msg_GroupBackground_Help,(STRPTR)Msg_GroupBackground_Help_STR},
    {Msg_GroupBackground_Title,(STRPTR)Msg_GroupBackground_Title_STR},
    {Msg_UseGroupBackground,(STRPTR)Msg_UseGroupBackground_STR},
    {Msg_UseGroupBackground_Help,(STRPTR)Msg_UseGroupBackground_Help_STR},
    {Msg_ButtonBackground,(STRPTR)Msg_ButtonBackground_STR},
    {Msg_ButtonBackground_Help,(STRPTR)Msg_ButtonBackground_Help_STR},
    {Msg_ButtonBackground_Title,(STRPTR)Msg_ButtonBackground_Title_STR},
    {Msg_UseButtonBackground,(STRPTR)Msg_UseButtonBackground_STR},
    {Msg_UseButtonBackground_Help,(STRPTR)Msg_UseButtonBackground_Help_STR},
    {Msg_Title_Frame,(STRPTR)Msg_Title_Frame_STR},
    {Msg_FrameShinePen,(STRPTR)Msg_FrameShinePen_STR},
    {Msg_FrameShinePen_Help,(STRPTR)Msg_FrameShinePen_Help_STR},
    {Msg_FrameShinePen_Title,(STRPTR)Msg_FrameShinePen_Title_STR},
    {Msg_FrameShadowPen,(STRPTR)Msg_FrameShadowPen_STR},
    {Msg_FrameShadowPen_Help,(STRPTR)Msg_FrameShadowPen_Help_STR},
    {Msg_FrameShadowPen_Title,(STRPTR)Msg_FrameShadowPen_Title_STR},
    {Msg_FrameStyle_Recessed,(STRPTR)Msg_FrameStyle_Recessed_STR},
    {Msg_FrameStyle_Normal,(STRPTR)Msg_FrameStyle_Normal_STR},
    {Msg_FrameStyle,(STRPTR)Msg_FrameStyle_STR},
    {Msg_FrameStyle_Help,(STRPTR)Msg_FrameStyle_Help_STR},
    {Msg_Title_Disabled,(STRPTR)Msg_Title_Disabled_STR},
    {Msg_DisabledBody,(STRPTR)Msg_DisabledBody_STR},
    {Msg_DisabledBody_Help,(STRPTR)Msg_DisabledBody_Help_STR},
    {Msg_DisabledBody_Title,(STRPTR)Msg_DisabledBody_Title_STR},
    {Msg_DisabledShadow,(STRPTR)Msg_DisabledShadow_STR},
    {Msg_DisabledShadow_Help,(STRPTR)Msg_DisabledShadow_Help_STR},
    {Msg_DisabledShadow_Title,(STRPTR)Msg_DisabledShadow_Title_STR},
    {Msg_Title_BarSpacer,(STRPTR)Msg_Title_BarSpacer_STR},
    {Msg_BarSpacerShinePen,(STRPTR)Msg_BarSpacerShinePen_STR},
    {Msg_BarSpacerShinePen_Help,(STRPTR)Msg_BarSpacerShinePen_Help_STR},
    {Msg_BarSpacerShinePen_Title,(STRPTR)Msg_BarSpacerShinePen_Title_STR},
    {Msg_BarSpacerShadowPen,(STRPTR)Msg_BarSpacerShadowPen_STR},
    {Msg_BarSpacerShadowPen_Help,(STRPTR)Msg_BarSpacerShadowPen_Help_STR},
    {Msg_BarSpacerShadowPen_Title,(STRPTR)Msg_BarSpacerShadowPen_Title_STR},
    {Msg_Title_BarFrame,(STRPTR)Msg_Title_BarFrame_STR},
    {Msg_BarFrameShine,(STRPTR)Msg_BarFrameShine_STR},
    {Msg_BarFrameShine_Help,(STRPTR)Msg_BarFrameShine_Help_STR},
    {Msg_BarFrameShine_Title,(STRPTR)Msg_BarFrameShine_Title_STR},
    {Msg_BarFrameShadow,(STRPTR)Msg_BarFrameShadow_STR},
    {Msg_BarFrameShadow_Help,(STRPTR)Msg_BarFrameShadow_Help_STR},
    {Msg_BarFrameShadow_Title,(STRPTR)Msg_BarFrameShadow_Title_STR},
    {Msg_Title_DragBar,(STRPTR)Msg_Title_DragBar_STR},
    {Msg_DragBarShine,(STRPTR)Msg_DragBarShine_STR},
    {Msg_DragBarShine_Help,(STRPTR)Msg_DragBarShine_Help_STR},
    {Msg_DragBarShine_Title,(STRPTR)Msg_DragBarShine_Title_STR},
    {Msg_DragBarShadow,(STRPTR)Msg_DragBarShadow_STR},
    {Msg_DragBarShadow_Help,(STRPTR)Msg_DragBarShadow_Help_STR},
    {Msg_DragBarShadow_Title,(STRPTR)Msg_DragBarShadow_Title_STR},
    {Msg_DragBarFill,(STRPTR)Msg_DragBarFill_STR},
    {Msg_DragBarFill_Help,(STRPTR)Msg_DragBarFill_Help_STR},
    {Msg_DragBarFill_Title,(STRPTR)Msg_DragBarFill_Title_STR},
    {Msg_UseDragBarFill,(STRPTR)Msg_UseDragBarFill_STR},
    {Msg_UseDragBarFill_Help,(STRPTR)Msg_UseDragBarFill_Help_STR},
    {Msg_Frame,(STRPTR)Msg_Frame_STR},
    {Msg_Frame_Help,(STRPTR)Msg_Frame_Help_STR},
    {Msg_Frame_Title,(STRPTR)Msg_Frame_Title_STR},
    {Msg_TextFont,(STRPTR)Msg_TextFont_STR},
    {Msg_TextFont_Help,(STRPTR)Msg_TextFont_Help_STR},
    {Msg_TextGfxFont,(STRPTR)Msg_TextGfxFont_STR},
    {Msg_TextGfxFont_Help,(STRPTR)Msg_TextGfxFont_Help_STR},
    {Msg_ViewMode,(STRPTR)Msg_ViewMode_STR},
    {Msg_ViewMode_Help,(STRPTR)Msg_ViewMode_Help_STR},
    {Msg_Appareance_Text,(STRPTR)Msg_Appareance_Text_STR},
    {Msg_TextGfx,(STRPTR)Msg_TextGfx_STR},
    {Msg_Gfx,(STRPTR)Msg_Gfx_STR},
    {Msg_Text,(STRPTR)Msg_Text_STR},
    {Msg_Borderless,(STRPTR)Msg_Borderless_STR},
    {Msg_Borderless_Help,(STRPTR)Msg_Borderless_Help_STR},
    {Msg_Sunny,(STRPTR)Msg_Sunny_STR},
    {Msg_Sunny_Help,(STRPTR)Msg_Sunny_Help_STR},
    {Msg_Raised,(STRPTR)Msg_Raised_STR},
    {Msg_Raised_Help,(STRPTR)Msg_Raised_Help_STR},
    {Msg_Scaled,(STRPTR)Msg_Scaled_STR},
    {Msg_Scaled_Help,(STRPTR)Msg_Scaled_Help_STR},
    {Msg_BarSpacer,(STRPTR)Msg_BarSpacer_STR},
    {Msg_BarSpacer_Help,(STRPTR)Msg_BarSpacer_Help_STR},
    {Msg_EnableKeys,(STRPTR)Msg_EnableKeys_STR},
    {Msg_EnableKeys_Help,(STRPTR)Msg_EnableKeys_Help_STR},
    {Msg_LabelPos,(STRPTR)Msg_LabelPos_STR},
    {Msg_LabelPos_Help,(STRPTR)Msg_LabelPos_Help_STR},
    {Msg_LabelPos_Bottom,(STRPTR)Msg_LabelPos_Bottom_STR},
    {Msg_LabelPos_Top,(STRPTR)Msg_LabelPos_Top_STR},
    {Msg_LabelPos_Right,(STRPTR)Msg_LabelPos_Right_STR},
    {Msg_LabelPos_Left,(STRPTR)Msg_LabelPos_Left_STR},
    {Msg_Title_GroupSpacing,(STRPTR)Msg_Title_GroupSpacing_STR},
    {Msg_HorizGroupSpacing,(STRPTR)Msg_HorizGroupSpacing_STR},
    {Msg_HorizGroupSpacing_Help,(STRPTR)Msg_HorizGroupSpacing_Help_STR},
    {Msg_VertGroupSpacing,(STRPTR)Msg_VertGroupSpacing_STR},
    {Msg_VertGroupSpacing_Help,(STRPTR)Msg_VertGroupSpacing_Help_STR},
    {Msg_BarSpacerSpacing,(STRPTR)Msg_BarSpacerSpacing_STR},
    {Msg_BarSpacerSpacing_Help,(STRPTR)Msg_BarSpacerSpacing_Help_STR},
    {Msg_Title_InnerSpacing,(STRPTR)Msg_Title_InnerSpacing_STR},
    {Msg_HorizInnerSpacing,(STRPTR)Msg_HorizInnerSpacing_STR},
    {Msg_HorizInnerSpacing_Help,(STRPTR)Msg_HorizInnerSpacing_Help_STR},
    {Msg_TopInnerSpacing,(STRPTR)Msg_TopInnerSpacing_STR},
    {Msg_TopInnerSpacing_Help,(STRPTR)Msg_TopInnerSpacing_Help_STR},
    {Msg_BottomInnerSpacing,(STRPTR)Msg_BottomInnerSpacing_STR},
    {Msg_BottomInnerSpacing_Help,(STRPTR)Msg_BottomInnerSpacing_Help_STR},
    {Msg_Title_BarFrameSpacing,(STRPTR)Msg_Title_BarFrameSpacing_STR},
    {Msg_LeftBarFrameSpacing,(STRPTR)Msg_LeftBarFrameSpacing_STR},
    {Msg_LeftBarFrameSpacing_Help,(STRPTR)Msg_LeftBarFrameSpacing_Help_STR},
    {Msg_RightBarFrameSpacing,(STRPTR)Msg_RightBarFrameSpacing_STR},
    {Msg_RightBarFrameSpacing_Help,(STRPTR)Msg_RightBarFrameSpacing_Help_STR},
    {Msg_TopBarFrameSpacing,(STRPTR)Msg_TopBarFrameSpacing_STR},
    {Msg_TopBarFrameSpacing_Help,(STRPTR)Msg_TopBarFrameSpacing_Help_STR},
    {Msg_BottomBarFrameSpacing,(STRPTR)Msg_BottomBarFrameSpacing_STR},
    {Msg_BottomBarFrameSpacing_Help,(STRPTR)Msg_BottomBarFrameSpacing_Help_STR},
    {Msg_Title_TextGfxSpacing,(STRPTR)Msg_Title_TextGfxSpacing_STR},
    {Msg_HorizTextGfxSpacing,(STRPTR)Msg_HorizTextGfxSpacing_STR},
    {Msg_HorizTextGfxSpacing_Help,(STRPTR)Msg_HorizTextGfxSpacing_Help_STR},
    {Msg_VertTextGfxSpacing,(STRPTR)Msg_VertTextGfxSpacing_STR},
    {Msg_VertTextGfxSpacing_Help,(STRPTR)Msg_VertTextGfxSpacing_Help_STR},
    {Msg_Precision_Gui,(STRPTR)Msg_Precision_Gui_STR},
    {Msg_Precision_Icon,(STRPTR)Msg_Precision_Icon_STR},
    {Msg_Precision_Image,(STRPTR)Msg_Precision_Image_STR},
    {Msg_Precision_Exact,(STRPTR)Msg_Precision_Exact_STR},
    {Msg_Precision,(STRPTR)Msg_Precision_STR},
    {Msg_Precision_Help,(STRPTR)Msg_Precision_Help_STR},
    {Msg_Event_IntuiTicks,(STRPTR)Msg_Event_IntuiTicks_STR},
    {Msg_Event_MouseMove,(STRPTR)Msg_Event_MouseMove_STR},
    {Msg_Event,(STRPTR)Msg_Event_STR},
    {Msg_Event_Help,(STRPTR)Msg_Event_Help_STR},
    {Msg_Scale,(STRPTR)Msg_Scale_STR},
    {Msg_Scale_Help,(STRPTR)Msg_Scale_Help_STR},
    {Msg_SpecialSelect,(STRPTR)Msg_SpecialSelect_STR},
    {Msg_SpecialSelect_Help,(STRPTR)Msg_SpecialSelect_Help_STR},
    {Msg_TextOverUseShine,(STRPTR)Msg_TextOverUseShine_STR},
    {Msg_TextOverUseShine_Help,(STRPTR)Msg_TextOverUseShine_Help_STR},
    {Msg_IgnoreSelImages,(STRPTR)Msg_IgnoreSelImages_STR},
    {Msg_IgnoreSelImages_Help,(STRPTR)Msg_IgnoreSelImages_Help_STR},
    {Msg_IgnoreDisImages,(STRPTR)Msg_IgnoreDisImages_STR},
    {Msg_IgnoreDisImages_Help,(STRPTR)Msg_IgnoreDisImages_Help_STR},
    {Msg_DisMode_Shape,(STRPTR)Msg_DisMode_Shape_STR},
    {Msg_DisMode_Grid,(STRPTR)Msg_DisMode_Grid_STR},
    {Msg_DisMode_FullGrid,(STRPTR)Msg_DisMode_FullGrid_STR},
    {Msg_DisMode,(STRPTR)Msg_DisMode_STR},
    {Msg_DisMode_Help,(STRPTR)Msg_DisMode_Help_STR},
    {Msg_DontMove,(STRPTR)Msg_DontMove_STR},
    {Msg_DontMove_Help,(STRPTR)Msg_DontMove_Help_STR},
    {Msg_DisMode_Sunny,(STRPTR)Msg_DisMode_Sunny_STR},
    {Msg_NtRaiseActive,(STRPTR)Msg_NtRaiseActive_STR},
    {Msg_NtRaiseActive_Help,(STRPTR)Msg_NtRaiseActive_Help_STR},
    {Msg_SpacersSize,(STRPTR)Msg_SpacersSize_STR},
    {Msg_SpacersSize_Help,(STRPTR)Msg_SpacersSize_Help_STR},
    {Msg_SpacersSize_Quarter,(STRPTR)Msg_SpacersSize_Quarter_STR},
    {Msg_SpacersSize_Half,(STRPTR)Msg_SpacersSize_Half_STR},
    {Msg_SpacersSize_One,(STRPTR)Msg_SpacersSize_One_STR},
    {Msg_Event_MouseObject,(STRPTR)Msg_Event_MouseObject_STR},
    {Msg_Item_Defaults,(STRPTR)Msg_Item_Defaults_STR},
    {Msg_Item_alfie_Defaults,(STRPTR)Msg_Item_alfie_Defaults_STR},
    {Msg_NoMUI20Event_Help,(STRPTR)Msg_NoMUI20Event_Help_STR},
    {Msg_Info_First,(STRPTR)Msg_Info_First_STR},
    {Msg_Info_Reserved,(STRPTR)Msg_Info_Reserved_STR},
    {Msg_Info_Rest,(STRPTR)Msg_Info_Rest_STR},
    {Msg_Info_Translator,(STRPTR)Msg_Info_Translator_STR},
    {Msg_Item_Globals,(STRPTR)Msg_Item_Globals_STR},
    {Msg_Item_LastSaved,(STRPTR)Msg_Item_LastSaved_STR},
    {Msg_Item_Restore,(STRPTR)Msg_Item_Restore_STR},
    {Msg_Pop_OK,(STRPTR)Msg_Pop_OK_STR},
    {Msg_Pop_OK_Help,(STRPTR)Msg_Pop_OK_Help_STR},
    {Msg_Pop_Cancel,(STRPTR)Msg_Pop_Cancel_STR},
    {Msg_Pop_Cancel_Help,(STRPTR)Msg_Pop_Cancel_Help_STR},
    {Msg_Popback_Pattern,(STRPTR)Msg_Popback_Pattern_STR},
    {Msg_Popback_Color,(STRPTR)Msg_Popback_Color_STR},
    {Msg_Popback_Bitmap,(STRPTR)Msg_Popback_Bitmap_STR},
    {Msg_Popback_Gradient,(STRPTR)Msg_Popback_Gradient_STR},
    {Msg_Popback_HorizGradient,(STRPTR)Msg_Popback_HorizGradient_STR},
    {Msg_Popback_HorizGradientHelp,(STRPTR)Msg_Popback_HorizGradientHelp_STR},
    {Msg_Popback_VertGradient,(STRPTR)Msg_Popback_VertGradient_STR},
    {Msg_Popback_VertGradientHelp,(STRPTR)Msg_Popback_VertGradientHelp_STR},
    {Msg_Popback_From,(STRPTR)Msg_Popback_From_STR},
    {Msg_Popback_To,(STRPTR)Msg_Popback_To_STR},
    {Msg_Popback_Swap,(STRPTR)Msg_Popback_Swap_STR},
    {Msg_Popback_SwapHelp,(STRPTR)Msg_Popback_SwapHelp_STR},
    {Msg_Poppen_MUI,(STRPTR)Msg_Poppen_MUI_STR},
    {Msg_Poppen_Colormap,(STRPTR)Msg_Poppen_Colormap_STR},
    {Msg_Poppen_RGB,(STRPTR)Msg_Poppen_RGB_STR},
    {Msg_Poppen_Shine,(STRPTR)Msg_Poppen_Shine_STR},
    {Msg_Poppen_Halfshine,(STRPTR)Msg_Poppen_Halfshine_STR},
    {Msg_Poppen_Background,(STRPTR)Msg_Poppen_Background_STR},
    {Msg_Poppen_Halfshadow,(STRPTR)Msg_Poppen_Halfshadow_STR},
    {Msg_Poppen_Shadow,(STRPTR)Msg_Poppen_Shadow_STR},
    {Msg_Poppen_Text,(STRPTR)Msg_Poppen_Text_STR},
    {Msg_Poppen_Fill,(STRPTR)Msg_Poppen_Fill_STR},
    {Msg_Poppen_Mark,(STRPTR)Msg_Poppen_Mark_STR},
    {Msg_Poppen_ColorMapHelp,(STRPTR)Msg_Poppen_ColorMapHelp_STR},
    {Msg_ColoradjustRed,(STRPTR)Msg_ColoradjustRed_STR},
    {Msg_Coloradjust_RedHelp,(STRPTR)Msg_Coloradjust_RedHelp_STR},
    {Msg_ColoradjustGreen,(STRPTR)Msg_ColoradjustGreen_STR},
    {Msg_Coloradjust_GreenHelp,(STRPTR)Msg_Coloradjust_GreenHelp_STR},
    {Msg_ColoradjustBlue,(STRPTR)Msg_ColoradjustBlue_STR},
    {Msg_Coloradjust_BlueHelp,(STRPTR)Msg_Coloradjust_BlueHelp_STR},
    {Msg_Coloradjust_WheelAbbr,(STRPTR)Msg_Coloradjust_WheelAbbr_STR},
    {Msg_Coloradjust_WheelHelp,(STRPTR)Msg_Coloradjust_WheelHelp_STR},
    {Msg_Coloradjust_GradientHelp,(STRPTR)Msg_Coloradjust_GradientHelp_STR},
    {Msg_PrefsShortHelp,(STRPTR)Msg_PrefsShortHelp_STR},
};

#endif /* CATCOMP_ARRAY */


/****************************************************************************/


#ifdef CATCOMP_BLOCK

static const char CatCompBlock[] =
{
    "\x00\x00\x00\x01\x00\x08"
    Msg_Reg_Colors_STR "\x00\x00"
    "\x00\x00\x00\x02\x00\x0C"
    Msg_Reg_Appareance_STR "\x00\x00"
    "\x00\x00\x00\x03\x00\x08"
    Msg_Reg_Spacing_STR "\x00"
    "\x00\x00\x00\x04\x00\x08"
    Msg_Reg_Options_STR "\x00"
    "\x00\x00\x00\x64\x00\x0C"
    Msg_Title_Backgrounds_STR "\x00"
    "\x00\x00\x00\x65\x00\x04"
    Msg_GroupBackground_STR "\x00"
    "\x00\x00\x00\x66\x00\x10"
    Msg_GroupBackground_Help_STR "\x00"
    "\x00\x00\x00\x67\x00\x10"
    Msg_GroupBackground_Title_STR "\x00\x00"
    "\x00\x00\x00\x68\x00\x08"
    Msg_UseGroupBackground_STR "\x00\x00"
    "\x00\x00\x00\x69\x00\x5E"
    Msg_UseGroupBackground_Help_STR "\x00"
    "\x00\x00\x00\x6A\x00\x08"
    Msg_ButtonBackground_STR "\x00"
    "\x00\x00\x00\x6B\x00\x1C"
    Msg_ButtonBackground_Help_STR "\x00\x00"
    "\x00\x00\x00\x6C\x00\x1A"
    Msg_ButtonBackground_Title_STR "\x00"
    "\x00\x00\x00\x6D\x00\x08"
    Msg_UseButtonBackground_STR "\x00\x00"
    "\x00\x00\x00\x6E\x00\x64"
    Msg_UseButtonBackground_Help_STR "\x00"
    "\x00\x00\x00\x6F\x00\x0E"
    Msg_Title_Frame_STR "\x00"
    "\x00\x00\x00\x70\x00\x06"
    Msg_FrameShinePen_STR "\x00"
    "\x00\x00\x00\x71\x00\x20"
    Msg_FrameShinePen_Help_STR "\x00"
    "\x00\x00\x00\x72\x00\x10"
    Msg_FrameShinePen_Title_STR "\x00"
    "\x00\x00\x00\x73\x00\x08"
    Msg_FrameShadowPen_STR "\x00\x00"
    "\x00\x00\x00\x74\x00\x22"
    Msg_FrameShadowPen_Help_STR "\x00\x00"
    "\x00\x00\x00\x75\x00\x12"
    Msg_FrameShadowPen_Title_STR "\x00\x00"
    "\x00\x00\x00\x76\x00\x0A"
    Msg_FrameStyle_Recessed_STR "\x00\x00"
    "\x00\x00\x00\x77\x00\x08"
    Msg_FrameStyle_Normal_STR "\x00\x00"
    "\x00\x00\x00\x78\x00\x06"
    Msg_FrameStyle_STR "\x00"
    "\x00\x00\x00\x79\x00\x1C"
    Msg_FrameStyle_Help_STR "\x00"
    "\x00\x00\x00\x7A\x00\x12"
    Msg_Title_Disabled_STR "\x00\x00"
    "\x00\x00\x00\x7B\x00\x06"
    Msg_DisabledBody_STR "\x00\x00"
    "\x00\x00\x00\x7C\x00\x8A"
    Msg_DisabledBody_Help_STR "\x00\x00"
    "\x00\x00\x00\x7D\x00\x0A"
    Msg_DisabledBody_Title_STR "\x00\x00"
    "\x00\x00\x00\x7E\x00\x08"
    Msg_DisabledShadow_STR "\x00\x00"
    "\x00\x00\x00\x7F\x00\x90"
    Msg_DisabledShadow_Help_STR "\x00"
    "\x00\x00\x00\x80\x00\x0C"
    Msg_DisabledShadow_Title_STR "\x00\x00"
    "\x00\x00\x00\x81\x00\x0C"
    Msg_Title_BarSpacer_STR "\x00\x00"
    "\x00\x00\x00\x82\x00\x06"
    Msg_BarSpacerShinePen_STR "\x00"
    "\x00\x00\x00\x83\x00\x16"
    Msg_BarSpacerShinePen_Help_STR "\x00"
    "\x00\x00\x00\x84\x00\x12"
    Msg_BarSpacerShinePen_Title_STR "\x00\x00"
    "\x00\x00\x00\x85\x00\x08"
    Msg_BarSpacerShadowPen_STR "\x00\x00"
    "\x00\x00\x00\x86\x00\x18"
    Msg_BarSpacerShadowPen_Help_STR "\x00\x00"
    "\x00\x00\x00\x87\x00\x12"
    Msg_BarSpacerShadowPen_Title_STR "\x00"
    "\x00\x00\x00\x88\x00\x0A"
    Msg_Title_BarFrame_STR "\x00"
    "\x00\x00\x00\x89\x00\x06"
    Msg_BarFrameShine_STR "\x00"
    "\x00\x00\x00\x8A\x00\x16"
    Msg_BarFrameShine_Help_STR "\x00\x00"
    "\x00\x00\x00\x8B\x00\x10"
    Msg_BarFrameShine_Title_STR "\x00"
    "\x00\x00\x00\x8C\x00\x08"
    Msg_BarFrameShadow_STR "\x00\x00"
    "\x00\x00\x00\x8D\x00\x16"
    Msg_BarFrameShadow_Help_STR "\x00"
    "\x00\x00\x00\x8E\x00\x12"
    Msg_BarFrameShadow_Title_STR "\x00\x00"
    "\x00\x00\x00\x8F\x00\x08"
    Msg_Title_DragBar_STR "\x00"
    "\x00\x00\x00\x90\x00\x06"
    Msg_DragBarShine_STR "\x00"
    "\x00\x00\x00\x91\x00\x14"
    Msg_DragBarShine_Help_STR "\x00\x00"
    "\x00\x00\x00\x92\x00\x12"
    Msg_DragBarShine_Title_STR "\x00"
    "\x00\x00\x00\x93\x00\x08"
    Msg_DragBarShadow_STR "\x00\x00"
    "\x00\x00\x00\x94\x00\x14"
    Msg_DragBarShadow_Help_STR "\x00"
    "\x00\x00\x00\x95\x00\x14"
    Msg_DragBarShadow_Title_STR "\x00\x00"
    "\x00\x00\x00\x96\x00\x06"
    Msg_DragBarFill_STR "\x00\x00"
    "\x00\x00\x00\x97\x00\x12"
    Msg_DragBarFill_Help_STR "\x00"
    "\x00\x00\x00\x98\x00\x12"
    Msg_DragBarFill_Title_STR "\x00\x00"
    "\x00\x00\x00\x99\x00\x04"
    Msg_UseDragBarFill_STR "\x00"
    "\x00\x00\x00\x9A\x00\x2C"
    Msg_UseDragBarFill_Help_STR "\x00\x00"
    "\x00\x00\x00\x9B\x00\x06"
    Msg_Frame_STR "\x00"
    "\x00\x00\x00\x9C\x00\x0A"
    Msg_Frame_Help_STR "\x00"
    "\x00\x00\x00\x9D\x00\x0A"
    Msg_Frame_Title_STR "\x00"
    "\x00\x00\x00\xC8\x00\x06"
    Msg_TextFont_STR "\x00\x00"
    "\x00\x00\x00\xC9\x00\x18"
    Msg_TextFont_Help_STR "\x00"
    "\x00\x00\x00\xCA\x00\x08"
    Msg_TextGfxFont_STR "\x00"
    "\x00\x00\x00\xCB\x00\x1E"
    Msg_TextGfxFont_Help_STR "\x00\x00"
    "\x00\x00\x00\xCC\x00\x0A"
    Msg_ViewMode_STR "\x00"
    "\x00\x00\x00\xCD\x00\x26"
    Msg_ViewMode_Help_STR "\x00"
    "\x00\x00\x00\xCE\x00\xB4"
    Msg_Appareance_Text_STR "\x00"
    "\x00\x00\x00\xCF\x00\x10"
    Msg_TextGfx_STR "\x00\x00"
    "\x00\x00\x00\xD0\x00\x0C"
    Msg_Gfx_STR "\x00\x00"
    "\x00\x00\x00\xD1\x00\x0A"
    Msg_Text_STR "\x00"
    "\x00\x00\x00\xD2\x00\x0C"
    Msg_Borderless_STR "\x00\x00"
    "\x00\x00\x00\xD3\x00\x26"
    Msg_Borderless_Help_STR "\x00\x00"
    "\x00\x00\x00\xD4\x00\x0A"
    Msg_Sunny_STR "\x00"
    "\x00\x00\x00\xD5\x00\x5C"
    Msg_Sunny_Help_STR "\x00"
    "\x00\x00\x00\xD6\x00\x08"
    Msg_Raised_STR "\x00\x00"
    "\x00\x00\x00\xD7\x00\x52"
    Msg_Raised_Help_STR "\x00"
    "\x00\x00\x00\xD8\x00\x08"
    Msg_Scaled_STR "\x00\x00"
    "\x00\x00\x00\xD9\x00\x22"
    Msg_Scaled_Help_STR "\x00\x00"
    "\x00\x00\x00\xDA\x00\x0C"
    Msg_BarSpacer_STR "\x00\x00"
    "\x00\x00\x00\xDB\x00\x38"
    Msg_BarSpacer_Help_STR "\x00"
    "\x00\x00\x00\xDC\x00\x0C"
    Msg_EnableKeys_STR "\x00"
    "\x00\x00\x00\xDD\x00\x2C"
    Msg_EnableKeys_Help_STR "\x00"
    "\x00\x00\x00\xDE\x00\x0A"
    Msg_LabelPos_STR "\x00"
    "\x00\x00\x00\xDF\x00\x38"
    Msg_LabelPos_Help_STR "\x00\x00"
    "\x00\x00\x00\xE0\x00\x08"
    Msg_LabelPos_Bottom_STR "\x00\x00"
    "\x00\x00\x00\xE1\x00\x04"
    Msg_LabelPos_Top_STR "\x00"
    "\x00\x00\x00\xE2\x00\x06"
    Msg_LabelPos_Right_STR "\x00"
    "\x00\x00\x00\xE3\x00\x06"
    Msg_LabelPos_Left_STR "\x00\x00"
    "\x00\x00\x01\x2C\x00\x04"
    Msg_Title_GroupSpacing_STR "\x00"
    "\x00\x00\x01\x2D\x00\x06"
    Msg_HorizGroupSpacing_STR "\x00"
    "\x00\x00\x01\x2E\x00\x2A"
    Msg_HorizGroupSpacing_Help_STR "\x00\x00"
    "\x00\x00\x01\x2F\x00\x06"
    Msg_VertGroupSpacing_STR "\x00\x00"
    "\x00\x00\x01\x30\x00\x1E"
    Msg_VertGroupSpacing_Help_STR "\x00\x00"
    "\x00\x00\x01\x31\x00\x04"
    Msg_BarSpacerSpacing_STR "\x00"
    "\x00\x00\x01\x32\x00\x3A"
    Msg_BarSpacerSpacing_Help_STR "\x00"
    "\x00\x00\x01\x33\x00\x08"
    Msg_Title_InnerSpacing_STR "\x00"
    "\x00\x00\x01\x34\x00\x06"
    Msg_HorizInnerSpacing_STR "\x00"
    "\x00\x00\x01\x35\x00\x44"
    Msg_HorizInnerSpacing_Help_STR "\x00"
    "\x00\x00\x01\x36\x00\x04"
    Msg_TopInnerSpacing_STR "\x00"
    "\x00\x00\x01\x37\x00\x3E"
    Msg_TopInnerSpacing_Help_STR "\x00\x00"
    "\x00\x00\x01\x38\x00\x08"
    Msg_BottomInnerSpacing_STR "\x00\x00"
    "\x00\x00\x01\x39\x00\x40"
    Msg_BottomInnerSpacing_Help_STR "\x00"
    "\x00\x00\x01\x3A\x00\x0A"
    Msg_Title_BarFrameSpacing_STR "\x00"
    "\x00\x00\x01\x3B\x00\x06"
    Msg_LeftBarFrameSpacing_STR "\x00\x00"
    "\x00\x00\x01\x3C\x00\x3C"
    Msg_LeftBarFrameSpacing_Help_STR "\x00\x00"
    "\x00\x00\x01\x3D\x00\x06"
    Msg_RightBarFrameSpacing_STR "\x00"
    "\x00\x00\x01\x3E\x00\x3C"
    Msg_RightBarFrameSpacing_Help_STR "\x00"
    "\x00\x00\x01\x3F\x00\x04"
    Msg_TopBarFrameSpacing_STR "\x00"
    "\x00\x00\x01\x40\x00\x3A"
    Msg_TopBarFrameSpacing_Help_STR "\x00"
    "\x00\x00\x01\x41\x00\x08"
    Msg_BottomBarFrameSpacing_STR "\x00\x00"
    "\x00\x00\x01\x42\x00\x3E"
    Msg_BottomBarFrameSpacing_Help_STR "\x00\x00"
    "\x00\x00\x01\x43\x00\x0A"
    Msg_Title_TextGfxSpacing_STR "\x00\x00"
    "\x00\x00\x01\x44\x00\x06"
    Msg_HorizTextGfxSpacing_STR "\x00"
    "\x00\x00\x01\x45\x00\x3A"
    Msg_HorizTextGfxSpacing_Help_STR "\x00\x00"
    "\x00\x00\x01\x46\x00\x06"
    Msg_VertTextGfxSpacing_STR "\x00\x00"
    "\x00\x00\x01\x47\x00\x3A"
    Msg_VertTextGfxSpacing_Help_STR "\x00\x00"
    "\x00\x00\x01\x90\x00\x04"
    Msg_Precision_Gui_STR "\x00"
    "\x00\x00\x01\x91\x00\x06"
    Msg_Precision_Icon_STR "\x00\x00"
    "\x00\x00\x01\x92\x00\x06"
    Msg_Precision_Image_STR "\x00\x00"
    "\x00\x00\x01\x93\x00\x06"
    Msg_Precision_Exact_STR "\x00\x00"
    "\x00\x00\x01\x94\x00\x08"
    Msg_Precision_STR "\x00"
    "\x00\x00\x01\x95\x00\x26"
    Msg_Precision_Help_STR "\x00"
    "\x00\x00\x01\x96\x00\x0C"
    Msg_Event_IntuiTicks_STR "\x00\x00"
    "\x00\x00\x01\x97\x00\x0A"
    Msg_Event_MouseMove_STR "\x00"
    "\x00\x00\x01\x98\x00\x06"
    Msg_Event_STR "\x00"
    "\x00\x00\x01\x99\x00\xCA"
    Msg_Event_Help_STR "\x00\x00"
    "\x00\x00\x01\x9A\x00\x06"
    Msg_Scale_STR "\x00"
    "\x00\x00\x01\x9B\x00\x20"
    Msg_Scale_Help_STR "\x00"
    "\x00\x00\x01\x9C\x00\x10"
    Msg_SpecialSelect_STR "\x00\x00"
    "\x00\x00\x01\x9D\x00\x4A"
    Msg_SpecialSelect_Help_STR "\x00\x00"
    "\x00\x00\x01\x9E\x00\x0E"
    Msg_TextOverUseShine_STR "\x00\x00"
    "\x00\x00\x01\x9F\x00\x42"
    Msg_TextOverUseShine_Help_STR "\x00\x00"
    "\x00\x00\x01\xA0\x00\x18"
    Msg_IgnoreSelImages_STR "\x00\x00"
    "\x00\x00\x01\xA1\x00\x2A"
    Msg_IgnoreSelImages_Help_STR "\x00"
    "\x00\x00\x01\xA2\x00\x18"
    Msg_IgnoreDisImages_STR "\x00\x00"
    "\x00\x00\x01\xA3\x00\x2A"
    Msg_IgnoreDisImages_Help_STR "\x00"
    "\x00\x00\x01\xA4\x00\x06"
    Msg_DisMode_Shape_STR "\x00"
    "\x00\x00\x01\xA5\x00\x06"
    Msg_DisMode_Grid_STR "\x00\x00"
    "\x00\x00\x01\xA6\x00\x0A"
    Msg_DisMode_FullGrid_STR "\x00"
    "\x00\x00\x01\xA7\x00\x08"
    Msg_DisMode_STR "\x00"
    "\x00\x00\x01\xA8\x00\x20"
    Msg_DisMode_Help_STR "\x00"
    "\x00\x00\x01\xA9\x00\x0C"
    Msg_DontMove_STR "\x00\x00"
    "\x00\x00\x01\xAA\x00\x4C"
    Msg_DontMove_Help_STR "\x00"
    "\x00\x00\x01\xAB\x00\x06"
    Msg_DisMode_Sunny_STR "\x00\x00"
    "\x00\x00\x01\xAC\x00\x1C"
    Msg_NtRaiseActive_STR "\x00\x00"
    "\x00\x00\x01\xAD\x00\x2C"
    Msg_NtRaiseActive_Help_STR "\x00"
    "\x00\x00\x01\xAE\x00\x0E"
    Msg_SpacersSize_STR "\x00\x00"
    "\x00\x00\x01\xAF\x00\x12"
    Msg_SpacersSize_Help_STR "\x00\x00"
    "\x00\x00\x01\xB0\x00\x14"
    Msg_SpacersSize_Quarter_STR "\x00"
    "\x00\x00\x01\xB1\x00\x12"
    Msg_SpacersSize_Half_STR "\x00\x00"
    "\x00\x00\x01\xB2\x00\x0C"
    Msg_SpacersSize_One_STR "\x00"
    "\x00\x00\x01\xB3\x00\x0C"
    Msg_Event_MouseObject_STR "\x00"
    "\x00\x00\x01\xF4\x00\x12"
    Msg_Item_Defaults_STR "\x00"
    "\x00\x00\x01\xF5\x00\x12"
    Msg_Item_alfie_Defaults_STR "\x00\x00"
    "\x00\x00\x01\xF6\x00\x88"
    Msg_NoMUI20Event_Help_STR "\x00\x00"
    "\x00\x00\x02\x58\x00\x2C"
    Msg_Info_First_STR "\x00\x00"
    "\x00\x00\x02\x59\x00\x1A"
    Msg_Info_Reserved_STR "\x00\x00"
    "\x00\x00\x02\x5A\x00\x4A"
    Msg_Info_Rest_STR "\x00"
    "\x00\x00\x02\x5B\x00\x02"
    Msg_Info_Translator_STR "\x00\x00"
    "\x00\x00\x02\x5C\x00\x10"
    Msg_Item_Globals_STR "\x00"
    "\x00\x00\x02\x5D\x00\x0C"
    Msg_Item_LastSaved_STR "\x00\x00"
    "\x00\x00\x02\x5E\x00\x08"
    Msg_Item_Restore_STR "\x00"
    "\x00\x00\x02\xBC\x00\x04"
    Msg_Pop_OK_STR "\x00\x00"
    "\x00\x00\x02\xBD\x00\x10"
    Msg_Pop_OK_Help_STR "\x00"
    "\x00\x00\x02\xBE\x00\x08"
    Msg_Pop_Cancel_STR "\x00\x00"
    "\x00\x00\x02\xBF\x00\x18"
    Msg_Pop_Cancel_Help_STR "\x00\x00"
    "\x00\x00\x02\xC6\x00\x08"
    Msg_Popback_Pattern_STR "\x00"
    "\x00\x00\x02\xC7\x00\x06"
    Msg_Popback_Color_STR "\x00"
    "\x00\x00\x02\xC8\x00\x08"
    Msg_Popback_Bitmap_STR "\x00\x00"
    "\x00\x00\x02\xC9\x00\x0A"
    Msg_Popback_Gradient_STR "\x00\x00"
    "\x00\x00\x02\xCA\x00\x0C"
    Msg_Popback_HorizGradient_STR "\x00\x00"
    "\x00\x00\x02\xCB\x00\x2C"
    Msg_Popback_HorizGradientHelp_STR "\x00"
    "\x00\x00\x02\xCC\x00\x0A"
    Msg_Popback_VertGradient_STR "\x00\x00"
    "\x00\x00\x02\xCD\x00\x2A"
    Msg_Popback_VertGradientHelp_STR "\x00"
    "\x00\x00\x02\xCE\x00\x0C"
    Msg_Popback_From_STR "\x00\x00"
    "\x00\x00\x02\xCF\x00\x0A"
    Msg_Popback_To_STR "\x00\x00"
    "\x00\x00\x02\xD0\x00\x06"
    Msg_Popback_Swap_STR "\x00\x00"
    "\x00\x00\x02\xD1\x00\x16"
    Msg_Popback_SwapHelp_STR "\x00"
    "\x00\x00\x03\x20\x00\x04"
    Msg_Poppen_MUI_STR "\x00"
    "\x00\x00\x03\x21\x00\x0A"
    Msg_Poppen_Colormap_STR "\x00\x00"
    "\x00\x00\x03\x22\x00\x04"
    Msg_Poppen_RGB_STR "\x00"
    "\x00\x00\x03\x23\x00\x06"
    Msg_Poppen_Shine_STR "\x00"
    "\x00\x00\x03\x24\x00\x0A"
    Msg_Poppen_Halfshine_STR "\x00"
    "\x00\x00\x03\x25\x00\x0C"
    Msg_Poppen_Background_STR "\x00\x00"
    "\x00\x00\x03\x26\x00\x0C"
    Msg_Poppen_Halfshadow_STR "\x00\x00"
    "\x00\x00\x03\x27\x00\x08"
    Msg_Poppen_Shadow_STR "\x00\x00"
    "\x00\x00\x03\x28\x00\x06"
    Msg_Poppen_Text_STR "\x00\x00"
    "\x00\x00\x03\x29\x00\x06"
    Msg_Poppen_Fill_STR "\x00\x00"
    "\x00\x00\x03\x2A\x00\x06"
    Msg_Poppen_Mark_STR "\x00\x00"
    "\x00\x00\x03\x2B\x00\x1E"
    Msg_Poppen_ColorMapHelp_STR "\x00\x00"
    "\x00\x00\x03\x84\x00\x04"
    Msg_ColoradjustRed_STR "\x00"
    "\x00\x00\x03\x85\x00\x20"
    Msg_Coloradjust_RedHelp_STR "\x00"
    "\x00\x00\x03\x86\x00\x06"
    Msg_ColoradjustGreen_STR "\x00"
    "\x00\x00\x03\x87\x00\x22"
    Msg_Coloradjust_GreenHelp_STR "\x00"
    "\x00\x00\x03\x88\x00\x06"
    Msg_ColoradjustBlue_STR "\x00\x00"
    "\x00\x00\x03\x89\x00\x22"
    Msg_Coloradjust_BlueHelp_STR "\x00\x00"
    "\x00\x00\x03\x8A\x00\x08"
    Msg_Coloradjust_WheelAbbr_STR "\x00\x00"
    "\x00\x00\x03\x8B\x00\x22"
    Msg_Coloradjust_WheelHelp_STR "\x00"
    "\x00\x00\x03\x8C\x00\x1E"
    Msg_Coloradjust_GradientHelp_STR "\x00\x00"
    "\x00\x00\x03\xE8\x00\x20"
    Msg_PrefsShortHelp_STR "\x00"
};

#endif /* CATCOMP_BLOCK */


/****************************************************************************/


struct LocaleInfo
{
    APTR li_LocaleBase;
    APTR li_Catalog;
};


#ifdef CATCOMP_CODE

STRPTR GetString(struct LocaleInfo *li, LONG stringNum)
{
LONG   *l;
UWORD  *w;
STRPTR  builtIn;

    l = (LONG *)CatCompBlock;

    while (*l != stringNum)
    {
        w = (UWORD *)((ULONG)l + 4);
        l = (LONG *)((ULONG)l + (ULONG)*w + 6);
    }
    builtIn = (STRPTR)((ULONG)l + 6);

#undef LocaleBase
#define LocaleBase li->li_LocaleBase
    
    if (LocaleBase)
        return(GetCatalogStr(li->li_Catalog,stringNum,builtIn));
#undef LocaleBase

    return(builtIn);
}


#endif /* CATCOMP_CODE */


/****************************************************************************/


#endif /* LOC_H */
