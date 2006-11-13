
TARGET  = TheBar.mcc
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

OBJS = libinit.o init.o utils.o brc1.o spacer.o dragbar.o build.o class.o

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -nostartfiles -o $@ $(OBJS)
	ppc-morphos-strip $@

install:
	@copy $(TARGET) $(DEST)
	@delete $(TARGET)
	@avail flush

libinit.o:  libinit.c class.h TheBar.mcc_rev.h base.h class_protos.h
init.o:     init.c class.h base.h class_protos.h
utils.o:    utils.c class.h base.h class_protos.h
brc1.o:     brc1.c
spacer.o:   spacer.c class.h base.h class_protos.h
dragbar.o:  dragbar.c class.h base.h class_protos.h
build.o:    build.c class.h instance.h base.h class_protos.h
class.o:    class.c class.h instance.h base.h class_protos.h

