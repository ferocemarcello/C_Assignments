#define NUM_THREADS 10
#include<stdint.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
int32_t G=0;
void PrintHello(void*threadid)
{
	int conta=0;
	while(1)
	{
		if(G==(int32_t)threadid)
		{
			sleep(1);
			if(G<9)
			{
				G++;
			}
			else
			{
				G=0;
			}
			conta++;
			printf("indice=%d, contatore=%d\n",(int32_t)threadid,conta);
		}
	}
}
int main()
{
int rc,i;
pthread_t threads[NUM_THREADS];
for(i=0;i<NUM_THREADS;i++)
{
	printf("creo il thread%d\n",i);
	rc=pthread_create(&threads[i],NULL,PrintHello,(void*)i);
	if(rc)
	{
		printf("errore rc is%d\n",rc);
		exit(-1);
	}
}
pthread_exit(NULL);
return 0;
}