# Simple Makefile to compile, clean and format all the sample codes
# provided during the course of Advanced Programming

default: all

bear: clean all

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

clangify:
	+find . -type d -exec cp -f "./.clang-format" {} \;

clangify-revert:
	+cp -f ./.clang-format ./.clang-format-backup
	+find . -type d -exec rm -R -f {}/./.clang-format \;
	+mv -f ./.clang-format-backup ./.clang-format

.PHONY: all bear clean format default clangify clangify-revert
