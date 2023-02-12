.PHONY: all install uninstall

all:
	# Hello this is only an installation Makefile for now
	# for examples and tests see the devel branches
	@echo " "
	

install:
	cp -r gcl /usr/local/include/

uninstall:
	rm -rf /usr/local/include/gcl
