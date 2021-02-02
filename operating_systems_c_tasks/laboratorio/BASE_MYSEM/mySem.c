#include <pthread.h>    /* POSIX Threads */
#include "mySem.h"
#include "printerror.h"
int mySem_init( mySem_t *mysem, int pshared, unsigned int value )
{		int i=0;
		if(pshared==0)
		{
			if(mysem==NULL)
			{
				exit(1);
			}
			else
			{
				i=pthread_mutex_init(&((*mysem).mutex),NULL);
				if(i!=0)
				{
					printf("non riesco a inizializzare la mutex init\n");
					exit(1);
				}
				i=pthread_cond_init(&((*mysem).cond),NULL);
				if(i!=0)
				{
					printf("non riesco a inizializzare la cond init\n");
					exit(1);
				}				
				((*mysem).counter)=value;
				return 0;
			}
		}
		exit(1);
}
int mySem_wait( mySem_t *mysem )
{
	int i=0;
	i=pthread_mutex_lock(&((*mysem).mutex));
	if(i!=0)
	{
		printf("non riesco a fare la mutex lock\n");
		return -1;
	}
	while(((*mysem).counter)<=0)
	{
		i=pthread_cond_wait(&((*mysem).cond),&((*mysem).mutex));
		if(i!=0)
		{
			printf("non riesco a fare la wait\n");
			return -1;
		}
	}
	((*mysem).counter)--;
	i=pthread_mutex_unlock(&((*mysem).mutex));
	if(i!=0)
		{
			printf("non riesco a fare la mutex unlock\n");
			return -1;
		}
	return 0;
}
int mySem_post( mySem_t *mysem )
{
	int i=0;
	i=pthread_mutex_lock(&((*mysem).mutex));
	if(i!=0)
	{
		printf("non riesco a fare la mutex lock\n");
		return -1;
	}
	(*mysem).counter++;
	if(((*mysem).counter)>0)
	{
		i=pthread_cond_signal(&((*mysem).cond));
		if(i!=0)
		{
			printf("non riesco a fare la signal\n");
			return -1;
		}
	}
	i=pthread_mutex_unlock(&((*mysem).mutex));
	if(i!=0)
	{
		printf("non riesco a fare la mutex unlock\n");
		return -1;
	}
	return 0;
}
int mySem_destroy( mySem_t *mysem)
{
	int i=0;
	i=pthread_mutex_destroy(&((*mysem).mutex));
	if(i!=0)
	{
		printf("non riesco a fare la mutex destroy\n");
		return -1;
	}
	i=pthread_cond_destroy(&((*mysem).cond));
	if(i!=0)
	{
		printf("non riesco a fare la cond destroy\n");
		return -1;
	}
	return 0;
}
