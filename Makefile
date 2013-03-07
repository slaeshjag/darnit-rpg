# Project: muon
include config.mk
MAKEFLAGS	+=	--no-print-directory

TOPDIR		=	$(shell pwd)
export TOPDIR

.PHONY: all server install clean

all:
	@echo " [ CD ] engine/"
	+@make -C engine/
	@echo " [ CD ] example/"
	+@make -C example/

engine:
	@echo " [ CD ] engine/"
	+@make -C engine/
	
install:
	@echo " Stub"
	
clean:
	@echo " [ CD ] engine/"
	+@make -C engine/ clean
	@echo " [ CD ] example/"
	+@make -C example/ clean
