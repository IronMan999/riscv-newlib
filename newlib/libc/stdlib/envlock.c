/*
FUNCTION
<<__env_lock>>, <<__env_unlock>>--lock environ variable

INDEX
	__env_lock
INDEX
	__env_unlock

ANSI_SYNOPSIS
	#include "envlock.h"
	void __env_lock (void *<[reent]>);
	void __env_unlock (void *<[reent]>);

TRAD_SYNOPSIS
	void __env_lock(<[reent]>)
	char *<[reent]>;

	void __env_unlock(<[reent]>)
	char *<[reent]>;

DESCRIPTION
The <<setenv>> family of routines call these functions when they need
to modify the environ variable.  The version of these routines supplied
in the library does not do anything.  If multiple threads of execution
can call <<setenv>>, or if <<setenv>> can be called reentrantly, then
you need to define your own versions of these functions in order to
safely lock the memory pool during a call.  If you do not, the memory
pool may become corrupted.

A call to <<setenv>> may call <<__env_lock>> recursively; that is,
the sequence of calls may go <<__env_lock>>, <<__env_lock>>,
<<__env_unlock>>, <<__env_unlock>>.  Any implementation of these
routines must be careful to avoid causing a thread to wait for a lock
that it already holds.
*/

void
__env_lock (ptr)
     struct _reent *ptr;
{
}

void
__env_unlock (ptr)
     struct _reent *ptr;
{
}
