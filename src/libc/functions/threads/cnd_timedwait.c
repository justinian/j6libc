#include <threads.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Implicitly casing the parameters. */
extern int pthread_cond_timedwait( cnd_t *, mtx_t *, const struct timespec * );

#ifdef __cplusplus
}
#endif

int cnd_timedwait(
		cnd_t * _PDCLIB_restrict cond,
		mtx_t * _PDCLIB_restrict mtx,
		const struct timespec * _PDCLIB_restrict ts )
{
	return thrd_error;
}
