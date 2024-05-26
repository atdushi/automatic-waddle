#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>

int (*hello)(int num);

bool init_library(const char *lib, const char *name)
{
    void *hdl = dlopen(lib, RTLD_LAZY);
    if( NULL == hdl )
        return false;

    hello = (int (*)(int))dlsym(hdl, name);

    if( NULL == hello )
        return false;

    return true;
}

int main(int argc, char *argv[])
{
    if (init_library(argv[1], argv[2]))
        printf("%d\n", hello(atoi(argv[3])));
    else
        return 1;

    return 0;
}