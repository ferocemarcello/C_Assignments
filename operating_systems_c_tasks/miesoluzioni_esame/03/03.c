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
#include "printerror.h"
#include "DBGpthread.h"

#define NUMALFA 5
#define NUMBETA 4

int turnoalfa=0;
int qualealfa=0;
int qualebeta=-1;

pthread_mutex_t  mutex; 
pthread_cond_t condalfas[NUMALFA];
pthread_cond_t condbetas[NUMBETA];	

void *beta (void *arg) 
{ 
	int rc=0;
	while(1)
	{
		rc=pthread_mutex_lock(&mutex);
		if(rc)
		{
			printf("\nmutex lock failed\n");
			exit(1);
		}
		while(turnoalfa==0 || qualebeta!=(int)arg)
		{
			rc=pthread_cond_wait(&condbetas[(int)arg],&mutex);
			if(rc)
			{
				printf("\nwait failed\n");
				exit(1);
			}
		}
		printf("beta %d sta correndo\n",(int)arg+1);
		fflush(stdout);
		sleep(1);
		if(qualealfa==NUMALFA-1)
		{
			qualealfa=0;
		}
		else
		{
			qualealfa++;
		}
		turnoalfa=0;
		printf("beta %d cede il testimone a alfa %d\n",(int)arg+1,qualealfa+1);
		rc=pthread_cond_signal(&condalfas[qualealfa]);
		if(rc)
		{
			printf("\nsignal failed\n");
			exit(1);
		}
		rc=pthread_mutex_unlock(&mutex);
		if(rc)
		{
			printf("\nmutex unlock failed\n");
			exit(1);
		}
	}
	pthread_exit(NULL); 
} 

void *alfa (void *arg) 
{ 	
	int rc=0;
	while(1)
	{
		rc=pthread_mutex_lock(&mutex);
		if(rc)
		{
			printf("\nmutex lock failed\n");
			exit(1);
		}
		while(turnoalfa!=0 || qualealfa!=(int)arg)
		{
			rc=pthread_cond_wait(&condalfas[(int)arg],&mutex);
			if(rc)
			{
				printf("\nwait failed\n");
				exit(1);
			}
		}
		printf("alfa %d sta correndo\n",(int)arg+1);
		fflush(stdout);
		sleep(1);
		if(qualebeta==NUMBETA-1)
		{
			qualebeta=0;
		}
		else
		{
			qualebeta++;
		}
		turnoalfa=1;
		printf("alfa %d cede il testimone a beta %d\n",(int)arg+1,qualebeta+1);
		rc=pthread_cond_signal(&condbetas[qualebeta]);
		if(rc)
		{
			printf("\nsignal failed\n");
			exit(1);
		}
		rc=pthread_mutex_unlock(&mutex);
		if(rc)
		{
			printf("\nmutex unlock failed\n");
			exit(1);
		}
	}
	pthread_exit(NULL); 
} 

int main (int argc, char* argv[] ) 
{ 
	pthread_t    tha; 
	pthread_t    thb; 
	int  rc, i;

	rc = pthread_mutex_init(&mutex, NULL); 
	if( rc ) PrintERROR_andExit(rc,"pthread_mutex_init failed");

	for(i=0;i<NUMALFA;i++)
	{
		rc=pthread_create( &tha,NULL,alfa,(void*)i); 
		if(rc) PrintERROR_andExit(rc,"pthread_create failed");
		rc = pthread_cond_init(&condalfas[i], NULL); 
		if( rc ) PrintERROR_andExit(rc,"pthread_cond_init failed");
	}

	for(i=0;i<NUMBETA;i++) 
	{
		rc=pthread_create( &thb,NULL,beta,(void*)i); 
		if(rc) PrintERROR_andExit(rc,"pthread_create failed");
		rc = pthread_cond_init(&condbetas[i], NULL); 
		if( rc ) PrintERROR_andExit(rc,"pthread_cond_init failed");
	}
	pthread_exit(NULL); 

	return(0); 
} 