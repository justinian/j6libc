#include <threads.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Implicity casting the parameter. */
extern int pthread_mutex_trylock( mtx_t * );

#ifdef __cplusplus
}
#endif

int mtx_trylock( mtx_t * mtx )
{
	return thrd_error;
}
