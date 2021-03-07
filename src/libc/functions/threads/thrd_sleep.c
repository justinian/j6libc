#include <threads.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Implicitly casting the parameters. */
extern int nanosleep( const struct timespec *, struct timespec * );

#ifdef __cplusplus
}
#endif

int thrd_sleep( const struct timespec * duration, struct timespec * remaining )
{
    return -2;
}
