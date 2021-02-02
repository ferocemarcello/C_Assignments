/* DBGpthread.c */

/* a causa dell'uso di strerror_r
   dove incluso, compilare con -D_POSIX_C_SOURCE >= 200112L
*/

#ifndef _MULTI_THREADED
	#define _MULTI_THREADED
#endif
#ifndef _POSIX_C_SOURCE
	#define _POSIX_C_SOURCE 200112L
#endif


#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <stdint.h>
#include <pthread.h> 
#include <errno.h>
#include <string.h>	/* per strerror_r  and  memset */
#include "printerror.h"

/* #define DEBUG */

void DBGpthread_mutex_lock(pthread_mutex_t *AddrMutex, const char *stringMsg) 
{
	int rc;	
#ifdef DEBUG
	if(stringMsg) printf("lock %s\n",stringMsg);
#endif
	rc = pthread_mutex_lock(AddrMutex);
	if(rc) PrintERROR_andExit(rc,"pthread_mutex_lock failed");
}

void DBGpthread_mutex_unlock( pthread_mutex_t *AddrMutex, const char *stringMsg)
{	int rc;
#ifdef DEBUG
	if(stringMsg) printf("unlock %s\n",stringMsg);
#endif
	rc = pthread_mutex_unlock(AddrMutex);
	if(rc) PrintERROR_andExit(rc,"pthread_mutex_unlock failed");
}

void DBGpthread_cond_wait(pthread_cond_t *AddrCond, pthread_mutex_t *AddrMutex, const char *stringMsg)
{	int rc;
#ifdef DEBUG
	if(stringMsg) printf("wait %s\n",stringMsg);
#endif
	rc = pthread_cond_wait(AddrCond,AddrMutex);
	if(rc) PrintERROR_andExit(rc,"pthread_cond_wait failed");
#ifdef DEBUG
	if(stringMsg) printf("wait exit %s\n",stringMsg);	
#endif
}

void DBGpthread_cond_signal(pthread_cond_t *AddrCond, const char *stringMsg)
{	int rc;	
#ifdef DEBUG
	if(stringMsg) printf("signal %s\n",stringMsg);
#endif
	rc = pthread_cond_signal(AddrCond);
	if(rc) PrintERROR_andExit(rc,"pthread_cond_signal failed");
}

void DBGpthread_cond_broadcast(pthread_cond_t *AddrCond, const char *stringMsg)
{	int rc;	
#ifdef DEBUG
	if(stringMsg) printf("broadcast %s\n",stringMsg);
#endif
	rc = pthread_cond_broadcast(AddrCond);
	if(rc) PrintERROR_andExit(rc,"pthread_cond_broadcast failed");
}



void DBGsleep( unsigned int NumSeconds, const char *stringMsg )
{
#ifdef DEBUG
	if(stringMsg) printf("sleep %s\n",stringMsg);
#endif
	sleep(NumSeconds);
}


void DBGnanosleep( unsigned int NumNanoSeconds, const char *stringMsg )
{
	struct timespec req;
#ifdef DEBUG
	if(stringMsg) printf("nanosleep %s\n",stringMsg);
#endif
	req.tv_sec=0;
	req.tv_nsec=NumNanoSeconds;
	nanosleep(&req,NULL);
}



