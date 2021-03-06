/* DBGpthread.h */

#ifndef __DBGPTHREAD_H__
#define __DBGPTHREAD_H__

#include <unistd.h> 
#include <stdlib.h> 
#include <pthread.h> 

void DBGpthread_mutex_lock( pthread_mutex_t *AddrMutex, const char *stringMsg );
void DBGpthread_mutex_unlock( pthread_mutex_t *AddrMutex, const char *stringMsg );
void DBGpthread_cond_wait( pthread_cond_t *AddrCond, pthread_mutex_t *AddrMutex, const char *stringMsg );
void DBGpthread_cond_signal( pthread_cond_t *AddrCond, const char *stringMsg );
void DBGsleep( unsigned int NumSeconds, const char *stringMsg );

#endif  /*  __DBGPTHREAD_H__ */


