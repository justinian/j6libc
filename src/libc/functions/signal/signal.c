#include <signal.h>
#include <stdlib.h>

void ( *signal( int sig, void ( *func )( int ) ) )( int )
{
	return SIG_ERR;
}
