#include <stdio.h>
#include "pdclib/_PDCLIB_glue.h"

#ifdef __cplusplus
extern "C" {
#endif

extern int close( int fd );

#ifdef __cplusplus
}
#endif

int _PDCLIB_close( int fd )
{
    return -1;
}
