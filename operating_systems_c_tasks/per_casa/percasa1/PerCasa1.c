#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <stdint.h>
#include <pthread.h> 

#define N 10 /*numero studenti*/
#define M 5 /*numero copie*/

int numcopie =M;
pthread_mutex_t  mutex; 
pthread_cond_t   condstud, condSegretaria; 
int studinwait=0;
void *Segretaria (void *arg) 
{ 
	while(1) {
			pthread_mutex_lock(&mutex);							
			if(numcopie==0 && studinwait==N)/*volendo potrei anche togliere la condizione numcopie==0*/
			{
				while(numcopie!=M)
				{
					printf("segretaria mette copia %d\n",numcopie+1);
					fflush(stdout);
					sleep(1);
					numcopie++;
				}
				studinwait=0;
				pthread_cond_broadcast(&condstud);				
				pthread_cond_wait(&condSegretaria,&mutex);				
			}
			else
			{			
				pthread_cond_wait(&condSegretaria,&mutex);
			}
			pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
} 

void *Studente (void *arg) 
{ 
	int i=0;
	while (1)
	{	
		pthread_mutex_lock(&mutex);
		i=0;
		studinwait++;
		sleep(1);
		if(numcopie>1)
		{
			numcopie--;
			printf("studente %d prende una copia, e va in wait\n",(int32_t)arg);
			fflush(stdout);
			pthread_cond_wait(&condstud,&mutex);
			i=1;
		}
		if(numcopie==1 && i==0)
		{
			numcopie--;
			printf("studente %d prende ultima copia, va in wait e sveglia la segretaria\n",(int32_t)arg);
			fflush(stdout);
			pthread_cond_signal(&condSegretaria);
			pthread_cond_wait(&condstud,&mutex);
			i=1;
		}
		if(numcopie<=0 && i==0)
		{
			printf("studente %d non può prendere alcuna copia perchè finite, e va in wait\n",(int32_t)arg);
			fflush(stdout);			
			pthread_cond_signal(&condSegretaria);
			pthread_cond_wait(&condstud,&mutex);
		}
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);	 
}

int main () 
{ 
	pthread_t thread[N + 1];
	int i;
	if(M>N)
	{
		printf("il numero di copie deve essere <=numero degli studenti\n");
		exit(1);
	}
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&condstud, NULL);
	pthread_cond_init(&condSegretaria, NULL);
	printf("inizio\tnumcopie=%d\tnumstudenti=%d\n",M,N);
	for(i = 1; i < N+1; i++)
	{
		pthread_create(&thread[i], NULL, Studente, (void *)i);
	}
	pthread_create(&thread[0], NULL, Segretaria, (void *)0);
	
	pthread_exit(NULL);
	return 0; 
}
	
