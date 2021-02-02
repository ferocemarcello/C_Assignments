#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

#define DEP 5
#define WITH 4
#define NBAN 3

pthread_mutex_t mutexdata[NBAN];
pthread_t depT[DEP], withT[WITH],bancadit;
int nOp[NBAN]={0};
int amount[NBAN]={0};

void* thDeposit(void*i)
{
	int rc;
	while(1)
	{
		sleep(1);
		rc=pthread_mutex_lock(&mutexdata[(int)i]);
		//printf("rcdeposit=%d\n",rc);
		if(rc!=0)
		{
			printf("lock deposit failed\n");
			exit(1);
		}
		/*else
		{
			printf("lock deposit succeeded\n");
		}*/
		amount[(int)i]+=10;
printf("deposito 10 nella banca %d\n",(int)i);
		nOp[(int)i]++;
		sleep(1);
		rc = pthread_mutex_unlock (&mutexdata[(int)i]);
		if(rc!=0)
		{
			printf("unlock deposit failed\n");
			exit(1);
		}
		/*else
		{
			printf("unlock deposit succeeded\n");
		}*/
	}
	pthread_exit(NULL);
}
void*BancaDitalia(void* i)
{
	int totamount=0;
	int totOp=0;
	int j=0;
	int rc;
	while(1)
	{
		rc=pthread_mutex_lock(&mutexdata[0]);
		//printf("rcitalia=%d\n",rc);
		if(rc!=0)
		{
			printf("lock italia failed\n");
			exit(1);
		}
		/*else
		{
			printf("lock italia succeeded\n");
		}*/
		pthread_mutex_lock(&mutexdata[1]);
		pthread_mutex_lock(&mutexdata[2]);
		for(j=0;j<NBAN;j++)
		{
			totamount+=amount[j];
			totOp+=nOp[j];
		}
		printf("totamount=%d,totOp=%d\n",totamount,totOp);
		rc=pthread_mutex_unlock(&mutexdata[0]);
		if(rc!=0)
		{
			printf("unlock italia failed\n");
			exit(1);
		}
		rc=pthread_mutex_unlock(&mutexdata[1]);
		rc=pthread_mutex_unlock(&mutexdata[2]);
		/*else
		{
			printf("unlock italia succeeded\n");
		}*/
		sleep(3);
	}
	pthread_exit(NULL);
}
void* thWithdraw(void*i)
{
	int rc;
	while(1)
	{
		sleep(1);
		rc=pthread_mutex_lock(&mutexdata[(int)i]);
		//printf("rcwithdraw=%d\n",rc);
		if(rc!=0)
		{
			printf("lock withdraw failed\n");
			exit(1);
		}
		/*else
		{
			printf("lock withdraw succeeded\n");
		}*/
		amount[(int)i]-=9;
printf("prelievo 9 dalla banca %d\n",(int)i);
		sleep(1);
		rc = pthread_mutex_unlock (&mutexdata[(int)i]);
		if(rc!=0)
		{
			printf("unlock withdraw failed\n");
			exit(1);
		}
		/*else
		{
			printf("unlock withdraw succeeded\n");
		}*/
	}
	pthread_exit(NULL);
}
int main()
{
	int j=0;
	int z=0;
	int rc;
	int i;
	for(i=0;i<3;i++)
	{
		rc=pthread_mutex_init(&mutexdata[(int)i],NULL);
	}
	
	if(rc!=0)
	{
		printf("non riesco a inizializzare la mutex init\n");
		exit(1);
	}
	for(i=0;i<NBAN;i++)
	{
		for(j=0;j<DEP;j++)
		{
			rc=pthread_create(&depT[j],NULL,thDeposit,(void*)i);
			if(rc!=0)
			{
				printf("non riesco a creare il thread deposito");
				exit(1);
			}
		}
		for(z=0;z<WITH;z++)
		{
			rc=pthread_create(&withT[z],NULL,thWithdraw,(void*)i);
			if(rc!=0)
			{
				printf("non riesco a creare il thread withdraw");
				exit(1);
			}
		}
	}
	rc=pthread_create(&bancadit,NULL,BancaDitalia,NULL);
	if(rc!=0)
	{
		printf("non riesco a creare il thread banca");
		exit(1);
	}
	pthread_exit(NULL);
}
