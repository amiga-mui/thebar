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

***************************************************************************/

/* utils.c */
#ifdef __MORPHOS__
#elif defined(__AROS__)
Object * DoSuperNew(struct IClass *cl, Object *obj, IPTR tag1, ...);
#else
Object * VARARGS68K DoSuperNew(struct IClass *cl, Object *obj, ...);
int stch_l(const char *chr_ptr, long *u_ptr);
#endif

Object *obutton(ULONG text,ULONG help);
Object *ocycle(STRPTR *array,ULONG key,ULONG help);
Object *ocheck(ULONG key,ULONG help);
Object *oslider(ULONG key,ULONG help,LONG min,LONG max);
Object *opop(ULONG type,ULONG key);
Object *opoppen(ULONG key,ULONG title,ULONG help);
Object *opopfri(ULONG key,ULONG title,ULONG help);
Object *opopback(ULONG gradient,ULONG key,ULONG title,ULONG help);
Object *opopframe(ULONG key,ULONG title,ULONG help);
void drawGradient(Object *obj, struct MUIS_TheBar_Gradient *grad);
#if !defined(__amigaos4__) && !defined(__AROS__)
STDARGS void msprintf(STRPTR buf,STRPTR fmt,...);
STDARGS int msnprintf(STRPTR buf,int size,STRPTR fmt,...);
#endif

/* loc.c */
struct Catalog *openCatalogVR(CONST_STRPTR name,ULONG minVer,ULONG minRev);
void initStrings(void);
STRPTR tr(ULONG id);
ULONG getKeyChar(STRPTR string);

#if !defined(__MORPHOS__) && !defined(__amigaos4__)
/* coloradjust.c */
void freeColoradjust ( void );
ULONG initColoradjust ( void );

/* penadjust.c */
void freePenadjust ( void );
ULONG initPenadjust ( void );

/* backgroundadjust.c */
void freeBackgroundadjust ( void );
ULONG initBackgroundadjust ( void );

/* poppen.c */
void freePoppen ( void );
ULONG initPoppen ( void );

/* popbackground.c */
void freePopbackground ( void );
ULONG initPopbackground ( void );
#endif

