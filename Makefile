ifdef _WIN32
lib = numa.dll
CC = cpp.exe
app = numa-check
else
lib = libnuma.so
CC = g++
app = numa-check
endif

CFLAGS = -Wall -ansi -pedantic

all: $(app) $(lib)

lib%.so: %.c
	$(CC) -shared -fPIC $(CFLAGS) -o $@ $<

clean:
	$(RM) $(app) $(lib)

run: all
	./$(app) main

$(lib): features.h
