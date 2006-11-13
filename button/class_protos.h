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
#endif
APTR allocVecPooled ( APTR pool , ULONG size );
void freeVecPooled ( APTR pool , APTR mem );
void stripUnderscore ( STRPTR dest , STRPTR from , ULONG mode );
struct TextFont *openFont ( STRPTR name );
APTR allocArbitratePooled ( ULONG size );
APTR freeArbitratePooled ( APTR mem , ULONG size );
APTR allocArbitrateVecPooled ( ULONG size );
APTR freeArbitrateVecPooled ( APTR mem );

/* brc1.c */
USHORT BRCUnpack ( signed char *pSource , signed char *pDest , LONG srcBytes0 , LONG dstBytes0 );

/* scale.c */
void scale ( struct scale *sce , UBYTE *src , UBYTE *dst );
void scaleRGB ( struct scale *sce , ULONG *src , ULONG *dst );

/* class.c */
ULONG initMCC ( void );

#ifdef __MORPHOS__
ULONG WritePixelArrayAlpha(APTR, UWORD, UWORD, UWORD, struct RastPort *, UWORD, UWORD, UWORD, UWORD, ULONG);
#define WritePixelArrayAlpha(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	LP10(216, ULONG , WritePixelArrayAlpha, \
		APTR ,             __p0, a0, \
		UWORD ,            __p1, d0, \
		UWORD ,            __p2, d1, \
		UWORD , 	   __p3, d2, \
		struct RastPort *, __p4, a1, \
		UWORD , 	   __p5, d3, \
		UWORD , 	   __p6, d4, \
		UWORD ,            __p7, d5, \
		UWORD ,            __p8, d6, \
		ULONG ,            __p9, d7, \
		, CyberGfxBase, 0, 0, 0, 0, 0, 0)
#endif

#endif /* _CLASS_PROTOS_H */
