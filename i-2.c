
#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>


static void* (*chained_malloc)(size_t)=NULL ;

void *malloc(size_t size)
{
    void *p = NULL ;

    if (chained_malloc==NULL)
    {
        chained_malloc = dlsym(RTLD_NEXT, "malloc") ;
        if (NULL == chained_malloc) {
            fprintf(stderr, "Error in `dlsym`: %s\n", dlerror()) ;
        }
    }

    fprintf(stderr, "i-2: before malloc(%ld)...\n", size) ;
    p = chained_malloc(size) ;
    fprintf(stderr, "i-2:  after malloc(%ld) = %p\n", size, p) ;

    return p ;
}

