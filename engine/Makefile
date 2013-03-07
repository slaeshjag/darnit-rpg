# Project: muon
include $(TOPDIR)/config.mk

BIN		=	../darnit-rpg

SRCFILES	=	$(wildcard *.c)
OBJFILES	=	$(SRCFILES:.c=.o)
.PHONY: all clean

all: $(OBJFILES)
	@echo " [ LD ]	$(BIN)"
	@$(CC) $(CFLAGS) $(OBJFILES) -o $(BIN) $(LIBS) $(LDFLAGS)
	@echo " Done."
	@echo

clean:
	@echo " [ RM ]	$(OBJFILES)"
	@$(RM) $(OBJFILES)
	@echo " [ RM ]	$(BIN)"
	@$(RM) $(BIN)

%.o: %.c %.h
	@echo " [ CC ]	server/$<"
	@$(CC) $(CFLAGS) -c -o $@ $< 
