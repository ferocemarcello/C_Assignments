#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 21
int main()
{
	int n=0,i=0,z=0,a=0;float f=0;int**seq;int maggiore=0;int vet[N]={0};
	srand((unsigned int) time(NULL));
	printf("scrivi numero n\t");
	while(scanf("%f",&f)==0||f!=(int)f)//controllo sull'utente
	{
		printf("\nscrivi un numero intero\t");
		fflush(stdin);
	}
	n=f;
	seq=(int**)malloc(n*sizeof(int*));//alloco il puntatore di puntatore
	if(seq==NULL)
	{
		printf("spazio insufficente");
		free(seq);
		exit(1);
	}
	for(i=0;i<n;i++)
	{
		seq[i]=(int*)malloc((i+2)*sizeof(int));//alloco il puntatore nella posizione i
		if(seq[i]==NULL)
		{
			printf("spazio insufficente");
			free(seq[i]);
			exit(1);
		}
		for(z=0;z<i+2;z++)
		{
			seq[i][z]=rand()%(N-1);
		}
	}
	for(i=0;i<n;i++)
	{
		for(z=0; z<i+2; z++)
		{
			printf("%d ", seq[i][z]);//stampo il puntatore a puntotore a interi
		}
		puts("");
	}
	maggiore=seq[0][0];
	for(i=0;i<n;i++)//trovo il numero maggiore
	{
		for(z=0;z<i+2;z++)
		{
			if(maggiore<seq[i][z])
			{
				maggiore=seq[i][z];
			}
		}
	}
	printf("\nil numero maggiore e' %d\n",maggiore);
	for(i=0;i<n;i++)//trovo quante volte compare ogni numero
	{
		for(z=0;z<i+2;z++)
		{
			for(a=0;a<N;a++)
			{
				if(a==seq[i][z])
				{
					vet[a]++;	
				}
			}
		}
	}
	for(a=0;a<N;a++)
	{
		printf("il numero %d compare %d volte\n",a,vet[a]);
	}
	for(z=0;z<n;z++)//Dealloco la memoria
    {
    	free(seq[z]);
	}
	free(seq);
	return 0;
}
