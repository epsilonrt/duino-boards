# Hey Emacs, this is a -*- makefile -*-
#----------------------------------------------------------------------------
# $Id$

all: package
rebuild: clean package

bootloader:
	@$(MAKE) -w -C duino-boards/bootloaders

clean:
	@$(MAKE) -w -C duino-boards/bootloaders $(MAKECMDGOALS)

distclean:
	@$(MAKE) -w -C duino-boards/bootloaders $(MAKECMDGOALS)
	@rm -f package_epsilonrt_duino_boards_index.json
	@rm -f duino-boards.tar.gz

version: duino-boards.tar.gz
	$(eval VERSION_TINY=$(shell git-version -t))
	$(eval VERSION=$(VERSION_TINY).$(shell git-version -p))
	@echo Package Version: $(VERSION)

hash: duino-boards.tar.gz
	$(eval HASH=$(shell openssl dgst -sha256 $< | sed -e 's/.* //'))
	@echo Package Hash256: $(HASH)

size: duino-boards.tar.gz
	$(eval SIZE=$(shell stat -c %s $<))
	@echo Package Size: $(SIZE) bytes

duino-boards.tar.gz: bootloader
	@tar czf $@  duino-boards

tar: duino-boards.tar.gz

package_epsilonrt_duino_boards_index.json: package_epsilonrt_duino_boards_index.json.in version hash size 
	@sed -e 's/@HASH@/$(HASH)/' -e 's/@VERSION@/$(VERSION)/' -e 's/@VERSION_TINY@/$(VERSION_TINY)/' -e 's/@SIZE@/$(SIZE)/' $< > $@

package: package_epsilonrt_duino_boards_index.json
	@echo  "\n\nYou should install '$<' and 'duino-boards.tar.gz' in the release space: https://github.com/epsilonrt/duino-boards/releases/tag/v$(VERSION)"

.PHONY: all clean distclean rebuild tar version hash size package
