#include "hello.h"

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

    hello_message("vasya");
    return 0;
}