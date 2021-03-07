#include <stdlib.h>
#include "pdclib/_PDCLIB_glue.h"
#include "j6/types.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void j6_process_exit( j6_handle_t handle, int status ) _PDCLIB_NORETURN;

#ifdef __cplusplus
}
#endif

void _PDCLIB_Exit( int status )
{
    j6_process_exit( 1, status );
}
