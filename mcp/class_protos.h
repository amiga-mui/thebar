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

#ifndef _CLASS_PROTOS_H
#define _CLASS_PROTOS_H

/* init.c */
#ifdef __MORPHOS__
ULONG query ( void );
#else
ULONG SAVEDS ASM query ( REG (d0,LONG which) );
#endif
void freeBase ( void );
ULONG initBase ( void );

/* utils.c */
#ifndef __MORPHOS__
ULONG STDARGS DoSuperNew ( struct IClass *cl , Object *obj , ULONG tag1 , ...);
void sprintf ( char *to , char *fmt , ...);
int STDARGS snprintf ( char *buf , int size , char *fmt , ...);
#else
int snprintf ( STRPTR buf , int size , STRPTR fmt , ...) __attribute((varargs68k));
#endif
LONG xget ( Object * obj , ULONG attribute );
Object *olabel ( ULONG id );
Object *olabel1 ( ULONG id );
Object *ollabel1 ( ULONG id );
Object *olabel2 ( ULONG id );
Object *oflabel ( ULONG id );
Object *oclabel ( ULONG id );
Object *owspace ( ULONG weight );
Object *ofhspace ( STRPTR string );
Object *obutton ( ULONG text , ULONG help );
Object *ocycle ( STRPTR *array , ULONG key , ULONG help );
Object *ocheck ( ULONG key , ULONG help );
Object *oslider ( ULONG key , ULONG help , LONG min , LONG max );
Object *opop ( ULONG type , ULONG key );
Object *opoppen ( ULONG key , ULONG title , ULONG help );
Object *opopfri ( ULONG key , ULONG title , ULONG help );
Object *opopback ( ULONG gradient , ULONG key , ULONG title , ULONG help );
Object *opopframe ( ULONG key , ULONG title , ULONG help );
void drawGradient ( Object *obj , struct MUIS_TheBar_Gradient *grad );

/* loc.c */
void initStrings ( void );
STRPTR getString ( ULONG id );
ULONG getKeyChar ( STRPTR string );
void localizeArray ( STRPTR *strings , ULONG *ids );
void localizeMenus ( struct NewMenu *menu , ULONG *ids );

#ifndef __MORPHOS__
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

/* class.c */
void freeMCP ( void );
ULONG initMCP ( void );

#endif /* _CLASS_PROTOS_H */
