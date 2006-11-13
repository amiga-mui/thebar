VERSION EQU 20
REVISION EQU 8
DATE MACRO
    dc.b '1.8.2005'
    ENDM
VERS MACRO
    dc.b 'TheBarVirt.mcc 20.8'
    ENDM
VSTRING MACRO
    dc.b '$VER: TheBarVirt.mcc 20.8 (1.8.2005) 2003-2005 Alfonso Ranieri <alforan@tin.it>',13,10,0
    ENDM
VERSTAG MACRO
    dc.b 0,'$VER: TheBarVirt.mcc 20.8 (1.8.2005)',0
    ENDM
