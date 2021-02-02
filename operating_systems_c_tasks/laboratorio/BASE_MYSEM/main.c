/* file:  main.c      */

#ifndef _MULTI_THREADED
	#define _MULTI_THREADED
#endif
#ifndef _POSIX_C_SOURCE
	#define _POSIX_C_SOURCE 200112L
#endif


#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <string.h>     /* String handling */
#include <pthread.h>    /* POSIX Threads */

#include "printerror.h"
#include "mySem.h"

#define NUMTHREADS  8
#define NUMADMITTED 6
/* global vars */
/* mySemaphores are declared global so they can be accessed 
   in main() and in thread routine,
   here, the semaphore is used as a mutex+condvar
*/
mySem_t mySem;
int counter;     /* shared variable */

void *ThreadFunction ( void *ptr )
{
    int x, rc; 
    x = *((int *) ptr);
    printf("Thread %d: Waiting to enter critical region...\n", x);
    fflush(stdout);
    rc=mySem_wait(&mySem);       /* down semaphore */
    if( rc != 0 ) PrintErrnoAndExit( "mySem_wait");
    /* START CRITICAL REGION */
    printf("Thread %d: Now in critical region...  sleeping \n", x);
    fflush(stdout);
    sleep(1);
    counter++;
    /* END CRITICAL REGION */    
    rc = mySem_post(&mySem);       /* up semaphore */
    if( rc != 0 ) PrintErrnoAndExit( "mySem_post");

    printf("Thread %d leave critical region...\n", x);
    fflush(stdout);
    
    pthread_exit(NULL); /* exit thread */
}

int main()
{
    int i[NUMTHREADS], rc, j;
    pthread_t thread[NUMTHREADS];
   
    /* argument to threads */
    for(j=0;j<NUMTHREADS;j++)  i[j]=j; 
    
    /* rc =mySem_init(&mySem, 0, 1); initialize mySem to 1 - binary semaphore */
    /* initialize mySem to NUMADMITTED - n-ary mySemaphore */
    rc =mySem_init(&mySem, 0, NUMADMITTED);
                                /* second param = 0 - semaphore is local */
    if( rc != 0 ) PrintErrnoAndExit( "mySem_init");
                                 
    /* Note: you can check if thread has been successfully created by checking return value of
       pthread_create */                                 
    for(j=0;j<NUMTHREADS;j++) {
        rc = pthread_create (&thread[j], NULL, ThreadFunction, (void *) &i[j]);
        if( rc != 0 ) PrintErrnoAndExit( "pthread_create");
    }
    
    for(j=0;j<NUMTHREADS;j++) {
        rc = pthread_join(thread[j], NULL);
        if( rc != 0 ) PrintErrnoAndExit( "pthread_join");
    }

    rc = mySem_destroy(&mySem); /* destroy semaphore */
    if( rc != 0 ) PrintErrnoAndExit( "mySem_destroy");
                  
    /* exit */  
    exit(0);
} /* main() */



