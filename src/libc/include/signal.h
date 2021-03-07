#ifndef _PDCLIB_SIGNAL_H
#define _PDCLIB_SIGNAL_H _PDCLIB_SIGNAL_H

#include "pdclib/_PDCLIB_internal.h"

/* Abnormal termination / abort() */
#define SIGABRT 6
/* Arithmetic exception / division by zero / overflow */
#define SIGFPE  8
/* Illegal instruction */
#define SIGILL  4
/* Interactive attention signal */
#define SIGINT  2
/* Invalid memory access */
#define SIGSEGV 11
/* Termination request */
#define SIGTERM 15

/* The following should be defined to pointer values that could NEVER point to
   a valid signal handler function. (They are used as special arguments to
   signal().) Again, these are the values used by Linux.
*/
#define SIG_DFL (void (*)( int ))0
#define SIG_ERR (void (*)( int ))-1
#define SIG_IGN (void (*)( int ))1

typedef _PDCLIB_sig_atomic_t sig_atomic_t;

/* Installs a signal handler "func" for the given signal.
   A signal handler is a function that takes an integer as argument (the signal
   number) and returns void.

   Note that a signal handler can do very little else than:
   1) assign a value to a static object of type "volatile sig_atomic_t",
   2) call signal() with the value of sig equal to the signal received,
   3) call _Exit(),
   4) call abort().
   Virtually everything else is undefind.

   The signal() function returns the previous installed signal handler, which
   at program start may be SIG_DFL or SIG_ILL. (This implementation uses
   SIG_DFL for all handlers.) If the request cannot be honored, SIG_ERR is
   returned and errno is set to an unspecified positive value.
*/
_PDCLIB_PUBLIC void (*signal( int sig, void (*func)( int ) ) )( int );

/* Raises the given signal (executing the registered signal handler with the
   given signal number as parameter).
   This implementation does not prevent further signals of the same time from
   occuring, but executes signal( sig, SIG_DFL ) before entering the signal
   handler (i.e., a second signal before the signal handler re-registers itself
   or SIG_IGN will end the program).
   Returns zero if successful, nonzero otherwise. */
_PDCLIB_PUBLIC int raise( int sig );

#endif
