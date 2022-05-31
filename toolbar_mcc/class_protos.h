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

/* utils.c */
#if !defined(__MORPHOS__)
Object * VARARGS68K DoSuperNew(struct IClass *cl, Object *obj, ...);
#endif

BOOL CreateSharedPool(void);
void DeleteSharedPool(void);
APTR SharedAlloc(ULONG size);
void SharedFree(APTR mem);
