#include <threads.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Implicitly casting the first parameters. */
extern int pthread_mutex_timedlock( mtx_t *, const struct timespec * );

#ifdef __cplusplus
}
#endif

int mtx_timedlock( mtx_t * _PDCLIB_restrict mtx, const struct timespec * _PDCLIB_restrict ts )
{
	return thrd_error;
}
