# Hey Emacs, this is a -*- makefile -*-
#----------------------------------------------------------------------------
# $Id$

all:
	@$(MAKE) -w -C optiboot $@
	@cp optiboot/*.hex .
	@$(MAKE) -w -C optiboot clean
	@$(MAKE) -w -C caterina $@
	@cp caterina/*.hex .
	@$(MAKE) -w -C caterina clean
	@$(MAKE) -w -C caterina VARIANT=TOUERIS_MODBUS $@
	@cp caterina/*.hex .
	@$(MAKE) -w -C caterina VARIANT=TOUERIS_MODBUS clean

clean:
	@$(MAKE) -w -C optiboot $@
	@$(MAKE) -w -C caterina $@
	@$(MAKE) -w -C caterina VARIANT=TOUERIS_MODBUS $@

distclean:
	@$(MAKE) -w -C optiboot $@
	@$(MAKE) -w -C caterina $@
	@$(MAKE) -w -C caterina VARIANT=TOUERIS_MODBUS $@
	@rm -f *.hex

rebuild: clean all

.PHONY: all clean distclean rebuild 
