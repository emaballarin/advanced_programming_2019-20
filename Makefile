# Simple Makefile to compile, clean and format all the sample codes
# provided during the course of Advanced Programming

default: all

all:
	+$(MAKE) $@ -C lectures
	+$(MAKE) $@ -C exercises

clean:
	+$(MAKE) $@ -C lectures
	+$(MAKE) $@ -C exercises
	@find . -type f \( -name '*~' -o -name 'a.out' \) -exec rm '{}' \;

format:
	+$(MAKE) $@ -C lectures
	+$(MAKE) $@ -C exercises

.PHONY: all clean format default
