buildall: lib exe

exe: main.c hello.h
	gcc main.c -L. -lHello -o hello

lib: hello.h hello.c
	gcc -o libHello.so -shared hello.c

clean:
	-rm hello libHello.so *.o 2>/dev/null