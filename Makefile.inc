LIBLINK = ar
LINKARGS = rsv
LIBDIR = ../lib
BINDIR = ../bin
ODIR = ../obj
CC=gcc
_OBJS := $(addsuffix .o, $(FILES))
OBJS := $(patsubst %, $(ODIR)/%, $(_OBJS))
LINKLIBS := $(patsubst %, $(LIBDIR)/%, $(_LINKLIBS))

all: $(BINDIR)/$(MAIN)

$(BINDIR)/$(MAIN): $(ODIR) $(BINDIR) $(LIBDIR) $(OBJS) $(LIBDIR)/$(LIB)
	$(CC) -o $@ $(LIBDIR)/$(LIB) $(LINKLIBS) $(CFLAGS) 

$(LIBDIR)/$(LIB): $(LIBDIR)
	$(LIBLINK) $(LINKARGS) $(LIBDIR)/$(LIB) $(OBJS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

$(ODIR) $(BINDIR) $(LIBDIR):
	mkdir $@
