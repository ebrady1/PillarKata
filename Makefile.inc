CC=gcc
CFLAGS +=-I.
BINDIR = ../bin
ODIR = ../obj
_OBJS := $(addsuffix .o, $(FILES))
OBJS := $(patsubst %, $(ODIR)/%, $(_OBJS))

all: $(BINDIR)/$(MAIN)

$(BINDIR)/$(MAIN): $(ODIR) $(BINDIR) $(OBJS)
	$(CC) $(OBJS) -o $@ $(CFLAGS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR) $(BINDIR):
	mkdir $@
