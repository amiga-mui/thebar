# TheBar.mcc TheBarVirt.mcc "build" makefile
#
# This script is used by "makefile" and can't be called directly

# what are we going to build
ifeq ($(T),mcc)
  NAME  = $(TNAME)
  ODIR  = $(OBJDIR)/mcc
else
  NAME  = $(TVNAME)
  ODIR  = $(OBJDIR)/mccv
  DMORE = -DVIRTUAL
endif

# set vars
TARGET  = $(BINDIR)/$(NAME)
VPATH   = $(ODIR)
CFLAGS += $(DMORE)
FOBJS   = $(addprefix $(ODIR)/,$(OBJS))

# main target
.PHONY: all
all: $(TARGET)

# build
$(TARGET): $(OBJS)
	@echo "  LD $(notdir $@)"
	@$(CC) $(LDFLAGS) -o $@.db $(FOBJS) $(M68KSTUBS) $(LDLIBS) -Wl,-Map,$@.map
	@$(STRIP) --remove-section=.comment -o $@ $@.db

# compile
$(OBJS):
	@echo "  CC $<"
	@$(CC) $(CFLAGS) $< -o $(ODIR)/$@

# include dependencies file
-include $(DEPFILE)

