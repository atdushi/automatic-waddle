#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>

void (*hello_message)(const char *name);

bool init_library()
{
    void *hdl = dlopen("./libHello.so", RTLD_LAZY);
    if( NULL == hdl )
        return false;

    hello_message = (void (*)(const char*))dlsym(hdl, "hello_message");

    if( NULL == hello_message )
        return false;

    return true;
}

int main()
{
    // lsb_release -a

    // gcc -o hello main.c (создает исполняемый)

    // gcc -o hello.o -c hello.c (только компиляция)
    // gcc -o main.o -c main.c (только компиляция)
    // gcc -o hello hello.o main.o

    // gcc -o libHello.so -shared hello.c
    // nm ligHello.so
    // gcc main.c -L. -lHello -o hello
    // export LD_LIBRARY_PATH=.
    
    // gcc -o libHello.so -shared hello.cpp
    // nm ligHello.so
    // c++filt _Z13hello_messagePKc

    // ldd hello (какие библиотеки использует)

    if (init_library())
        hello_message("vasya");
    else
        printf("Library was not loaded!");

    
    return 0;
}