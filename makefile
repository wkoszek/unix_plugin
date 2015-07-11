# Copyright (c) 2015 Wojciech A. Koszek <wojciech@koszek.com>
all: unix_plugin

CFLAGS+=-Wall -pedantic

unix_plugin: unix_plugin.c
	$(CC) $(CFLAGS) $< -o $@ -ldl

unix_lib.so: unix_lib.c
	$(CC) $(CFLAGS) -shared $< -o $@

tests:	unix_plugin unix_lib.so
	./unix_plugin unix_lib.so > test.o
	@echo "# Checking results (no output means it's ok)"
	diff -u test/test.t test.o

clean:
	rm -rf unix_plugin unix_lib.so test.o
