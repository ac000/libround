libround: libround.o
	gcc -O2 -shared -Wl,-soname,libround.so.0 -o libround.so.0.0.1 libround.o -lc

libround.o: libround.h libround.c
	gcc -fpic -O2 -Wall -c libround.c -lm

libroundtest: libroundtest.c
	gcc -Wall -O2 -o libroundtest libroundtest.c -lround -lm

clean:
	rm libround.so.* libroundtest *.o
