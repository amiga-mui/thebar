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

#define CATCOMP_ARRAY
#include "class.h"

/***********************************************************************/

void
initStrings(void)
{
    if ((LocaleBase = OpenLibrary("locale.library",36)) &&
        (lib_cat = OpenCatalogA(NULL,"TheBar.catalog",NULL)))
    {
        register struct CatCompArrayType *cca;
        register int                     cnt;

        for (cnt = (sizeof(CatCompArray)/sizeof(struct CatCompArrayType))-1, cca = (struct CatCompArrayType *)CatCompArray+cnt;
             cnt>=0;
             cnt--, cca--)
        {
            register STRPTR s;

            if (s = GetCatalogStr(lib_cat,cca->cca_ID,cca->cca_Str)) cca->cca_Str = s;
        }
    }
}

/***********************************************************************/

STRPTR
getString(ULONG id)
{
    register int low, high;

    for (low = 0, high = (sizeof(CatCompArray)/sizeof(struct CatCompArrayType))-1; low<=high; )
    {
        register int                     mid = (low+high)>>1, cond;
        register struct CatCompArrayType *cca = (struct CatCompArrayType *)CatCompArray+mid;

        if ((cond = id-cca->cca_ID)==0)
            return lib_cat ? GetCatalogStr(lib_cat,id,cca->cca_Str) : cca->cca_Str;

        if (cond<0) high = mid-1;
        else low = mid+1;
    }

    return (STRPTR)"";
}

/***********************************************************************/

ULONG
getKeyChar(STRPTR string)
{
    register ULONG res = 0;

    if (!LocaleBase) return 0;

    if (string)
    {
        for (; *string && *string!='_'; string++);
        if (*string++) res = ToLower(*string);
    }

    return res;
}

/***********************************************************************/

void
localizeArray(STRPTR *strings,ULONG *ids)
{
    while (*ids)
        *strings++ = getString(*ids++);
}

/***********************************************************************/

void
localizeMenus(struct NewMenu *menu,ULONG *ids)
{
    while (menu->nm_Type!=NM_END)
    {
        register ULONG id = *ids++;

        if (id && menu->nm_Label!=NM_BARLABEL)
            menu->nm_Label = getString(id);

        menu++;
    }
}

/***********************************************************************/
