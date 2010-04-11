libround: libround.o
	gcc -O2 -shared -Wl,-soname,libround.so.0 -o libround.so.0.0 libround.o -lc

libround.o: libround.h libround.c
	gcc -fPIC -O2 -Wall -c libround.c -lm

libroundtest: libround.o libroundtest.c
	gcc -Wall -O2 -o libroundtest libroundtest.c -L. -lround -lm

clean:
	rm libround.so.0.0 libroundtest *.o
