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
	$(CC) $(CFLAGS) -o $@ $(LIBDIR)/$(LIB) $(LINKLIBS) $(LINKFLAGS) 

$(LIBDIR)/$(LIB): $(LIBDIR)
	$(LIBLINK) $(LINKARGS) $(LIBDIR)/$(LIB) $(OBJS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -g -O0 -std=c11 -c -o $@ $<

$(ODIR) $(BINDIR) $(LIBDIR):
	mkdir $@
