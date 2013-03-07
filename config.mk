# Project: muon
# Makefile configurations

PREFIX		=	/usr/local
DATAPATH	=	/usr/share/games/muon
APPLICATIONSPATH=	/usr/share/applications

DBGFLAGS	=	-O0 -g -D__DEBUG__
#DBGFLAGS	=	-O3 -g
CFLAGS		+=	-Wall $(INCS) $(DBGFLAGS)
LDFLAGS		+=	-ldarnit
RM		=	rm -f

