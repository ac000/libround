libround: libround.o
	gcc -O2 -shared -Wl,-soname,libround.so.1 -o libround.so.1.0.2 libround.o -lc

libround.o: libround.h libround.c
	gcc -Wall -Wextra -O2 -std=c99 -pedantic -fpic -c libround.c -lm

libroundtest: libroundtest.c
	gcc -Wall -Wextra -O2 -std=c99 -pedantic -o libroundtest libroundtest.c -I. -L. -lround -lm

clean:
	rm -f libround.so.* libroundtest *.o
