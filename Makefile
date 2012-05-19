libround: libround.o
	gcc -O2 -shared -Wl,-soname,libround.so.1 -o libround.so.1.0.0 libround.o -lc

libround.o: libround.h libround.c
	gcc -Wall -O2 -std=c99 -fpic -c libround.c -lm

libroundtest: libroundtest.c
	gcc -Wall -O2 -std=c99 -o libroundtest libroundtest.c -I. -L. -lround -lm

clean:
	rm libround.so.* libroundtest *.o
