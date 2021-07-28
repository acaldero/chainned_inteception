#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[] )
{
    void *p  = NULL ;
    int size = 10 ;

    fprintf(stderr, "main: before malloc(%d)...\n", size) ;
    p = malloc(size) ;
    fprintf(stderr, "main: after malloc(%d) = %p\n", size, p) ;

    return 0;
}

