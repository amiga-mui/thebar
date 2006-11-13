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
ULONG SAVEDS ASM query ( REG (d0,LONG which ));
#endif
void freeBase ( void );
ULONG initBase ( void );

/* utils.c */
#ifndef __MORPHOS__
ULONG STDARGS DoSuperNew ( struct IClass *cl , Object *obj , ULONG tag1 , ...);
#else
int min ( int a , int b );
int max ( int a , int b );
#endif
APTR allocVecPooled ( APTR pool , ULONG size );
void freeVecPooled ( APTR pool , APTR mem );
LONG xget ( Object *obj , ULONG attribute );

/* brc1.c */
USHORT BRCUnpack ( signed char *pSource , signed char *pDest , LONG srcBytes0 , LONG dstBytes0 );

/* spacer.c */
ULONG initSpacerClass ( void );

/* dragbar.c */
ULONG initDragBarClass ( void );

/* class.c */
ULONG initMCC ( void );

#endif /* _CLASS_PROTOS_H */
