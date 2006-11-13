
TARGET  = TheBar.mcp
DEST    = SYS:Classes/MUI

CC 	= ppc-morphos-gcc
CDEFS   = -DUSE_INLINE_STDARG
CFLAGS  = $(CDEFS) $(CWARN) -O2 -fomit-frame-pointer -mcpu=750 -mstring -mmultiple -noixemul -fstrict-aliasing -I../include/
LDFLAGS = -noixemul
CWARN   = -Wall\
  	  -Wno-missing-braces\
  	  -Wno-parentheses\
          -Wno-switch\
          -Wstrict-prototypes\
  	  -Werror-implicit-function-declaration\
          -Wpointer-arith

OBJS = libinit.o init.o utils.o loc.o class.o

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -nostartfiles -o $@ $(OBJS)
	ppc-morphos-strip $@

install:
	@copy $(TARGET) $(DEST)
	@delete $(TARGET)
	@avail flush

libinit.o:              libinit.c class.h TheBar.mcp_rev.h base.h loc.h class_protos.h
init.o:                 init.c class.h TheBar_iff.h base.h loc.h class_protos.h
utils.o:                utils.c class.h base.h loc.h class_protos.h
loc.o:                  loc.c class.h base.h loc.h class_protos.h
class.o:                class.c class.h base.h loc.h class_protos.h TheBar.mcp_rev.h

