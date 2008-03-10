# TheBar.mcc TheBarVirt.mcc makefile
# Invoke it as:
# "make"               - to generate the targets in host format
# "make OS=os"         - to generate the targets in os format, where os is one of os4, os3, morphos, aros
# "make DEBUG=1"       - to generate the targets in host format with debugging
# "make OS=os DEBUG=1" - to generate the targets in os format, where os is one of os4, os3, morphos, aros with debugging

# host
ifndef (HOST)
  HOST = $(shell uname)
  ifeq ($(HOST),AmigaOS)
    ifeq ($(shell uname -m),powerpc)
      HOST = AmigaOS4
    endif
    ifeq ($(shell uname -m),ppc)
      HOST = AmigaOS4
    endif
  endif
endif

# os
ifndef (OS)
  ifeq ($(HOST),AmigaOS4)
    OS = os4
  else
  ifeq ($(HOST),AmigaOS)
    OS = os3
  else
  ifeq ($(HOST),MorphOS)
    OS = mos
  else
  ifeq ($(HOST),Aros)
    OS = aros
  else
    OS = os4
  endif
  endif
  endif
  endif
endif

# debug
ifeq ($(DEBUG),1)
 override DEBUG = -DDEBUG -O0
endif

# commands
MKDIR  = mkdir
CP     = cp
RM     = rm -f
FLUSH  = avail flush
DUMP   = objdump
CHMOD  = chmod u+x
FC     = flexcat

# override commands by os
ifeq ($(HOST),AmigaOS4)
  # AmigaOS4 host
  RM    = delete force
  MKDIR = makedir
  DATE  = gdate
else
ifeq ($(HOST),AmigaOS)
  # AmigaOS3 host
  RM    = delete force
  MKDIR = makedir
else
ifeq ($(HOST),MorphOS)
  # MorphOS host
endif
endif
endif

# commons definitions
TNAME   = TheBar.mcc
TVNAME  = TheBarVirt.mcc
OBJDIR  = .obj_$(OS)
BINDIR  = bin_$(OS)
DEPFILE = makefile.dep

# Common compiler/linker flags
WARN     = -W -Wall
OPTFLAGS = -O2
DEBUGSYM = -gstabs
CFLAGS   = -c -I../include $(CPU) $(WARN) $(OPTFLAGS) -fomit-frame-pointer $(DEBUGSYM) $(DEBUG)
LDFLAGS  = $(CPU) $(DEBUGSYM) -nostartfiles
LDLIBS   =

# options by os
ifeq ($(OS),os4)
  # AmigaOS4
  CC         = ppc-amigaos-gcc
  STRIP      = ppc-amigaos-strip
  OBJDUMP    = ppc-amigaos-objdump
  CRT        = newlib
  CPU        = -mcpu=powerpc
  CFLAGS    += -mcrt=$(CRT) -D__USE_INLINE__ -D__NEW_TIMEVAL_DEFINITION_USED__ -DNO_PPCINLINE_STDARG -Wa,-mregnames
  LDFLAGS   += -mcrt=$(CRT)
  M68KSTUBS  = $(OBJDIR)/mccclass_68k.o
  DESTDIR    = MUI:Libs/MUI
else
ifeq ($(OS),os3)
  # AmigaOS3
  CC       = m68k-amigaos-gcc
  STRIP    = m68k-amigaos-strip
  OBJDUMP  = m68k-amigaos-objdump
  CPU	   = -m68020-60 -msoft-float
  CFLAGS  += -noixemul -DNO_INLINE_STDARG
  LDFLAGS += -noixemul
  LDLIBS  += -ldebug -lmui
  DESTDIR  = MUI:Libs/MUI
else
ifeq ($(OS),mos)
  # MorphOS
  CC       = ppc-morphos-gcc
  STRIP    = ppc-morphos-strip
  OBJDUMP  = ppc-morphos-objdump
  CPU      = -mcpu=750
  CFLAGS  += -noixemul -nostartfiles -DUSE_INLINE_STDARG
  LDFLAGS += -noixemul
  LDLIBS  += -ldebug
  DESTDIR  = Sys:Classes/MUI
else
ifeq ($(OS),aros)
  # AROS
  CC      = i686-aros-gcc
  STRIP   = i686-aros-strip
  OBJDUMP = i686-aros-objdump
  CPU     =
  DESTDIR = Sys:Classes/Zune
endif
endif
endif
endif

# objects 
OBJS     = library.o utils.o brc1.o dragbar.o spacer.o scale.o build.o class.o debug.o
TESTOBJS = TheBar-Test.o brc1.o build.o class.o dragbar.o scale.o spacer.o utils.o debug.o

# let's export all
export

# here we are
.PHONY: all
ifeq ($(wildcard $(DEPFILE)),$(DEPFILE))
all: $(BINDIR) $(OBJDIR) $(M68KSTUBS)
    # great, we have a dependecies file, let's make our target
	@make --no-print-directory -f makefile.do T=mcc
	@make --no-print-directory -f makefile.do T=mccv
else
all: depend
    # no dependecies, create it and then call me again
	@make --no-print-directory all
endif

# create binaries directory
$(BINDIR):
	@echo  "  Creating $(OS) binaries directory"
	@$(MKDIR) $(BINDIR)

# create objects directories
$(OBJDIR):
	@echo  "  Creating $(OS) objects directories"
	@$(MKDIR) $(OBJDIR)
	@$(MKDIR) $(OBJDIR)/mcc
	@$(MKDIR) $(OBJDIR)/mccv

$(M68KSTUBS): ../include/mccclass_68k.c
	@echo "  CC $(notdir $<)"
	@$(CC) $(CFLAGS) $< -o $@

# clean
.PHONY: clean
clean:
	@echo "  => Cleaning..."
	@$(RM) $(addprefix $(OBJDIR)/mcc/,$(OBJS)) $(addprefix $(OBJDIR)/mccv/,$(OBJS)) $(M68KSTUBS)
	@$(RM) $(BINDIR)/$(TNAME) $(BINDIR)/$(TNAME).db $(BINDIR)/$(TNAME).map $(BINDIR)/$(TVNAME) $(BINDIR)/$(TVNAME).db $(BINDIR)/$(TVNAME).map
	@echo "  <= Done."

# install
.PHONY: install
install: all
	@echo "  => Installing..."
	@$(CP) $(BINDIR)/$(TNAME) $(DESTDIR)
	@$(CP) $(BINDIR)/$(TVNAME) $(DESTDIR)
	@echo "  <= Done."

# create the dependencies file
.PHONY: depend
depend:
	@echo "  => Generating dependencies, takes about 6 seconds on *Amiga*, 2 seconds on gentoo x86 :-( ..."
	@$(CC) -MM $(CFLAGS) $(patsubst %.o,%.c, $(OBJS)) >$(DEPFILE)
	@echo "  <= Done."

