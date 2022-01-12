VERSION = 1.0.4

CC	= gcc
CFLAGS	= -Wall -Wextra -std=c99 -g -O2 -fexceptions -fvisibility=hidden -fPIC
LDFLAGS	= -shared -Wl,-z,defs,-z,relro,-z,now,--as-needed
LIBS	= -lm

libround: libround.o
	$(CC) $(LDFLAGS),-soname,libround.so.1 -o libround.so.$(VERSION) libround.o $(LIBS)

libround.o: libround.h libround.c
	$(CC) $(CFLAGS) -c libround.c

libroundtest: libroundtest.c
	$(CC) $(CFLAGS) -o libroundtest libroundtest.c -I. -L. -lround $(LIBS)

clean:
	rm -f libround.so.* libroundtest *.o
