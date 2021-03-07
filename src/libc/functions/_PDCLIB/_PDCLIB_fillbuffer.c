#include <stdio.h>
#include "pdclib/_PDCLIB_glue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef long ssize_t;
extern ssize_t read( int fd, void * buf, size_t count );

#ifdef __cplusplus
}
#endif

int _PDCLIB_fillbuffer( struct _PDCLIB_file_t * stream )
{
	return 1;
}
