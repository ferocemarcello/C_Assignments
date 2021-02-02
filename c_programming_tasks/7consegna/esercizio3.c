#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 15 //numero di studenti
#define G 50 //range di voti
int main()
{
	int *vet;int k=0;int n=0;int maggiore=0;int minore=0;int a=0;int b=0;
	srand((unsigned int) time(NULL));
	vet=(int *)malloc(N*sizeof(int));
	for(k=0;k<N;k++)
	{
		vet[k]=rand()%(G+1);
	}
	printf("digita un valore compreso tra 0 e %d\t",G);
	scanf("%d",&n);
	k=0;
	for(k=0;k<N;k++)//verifico la/e posizione/i di un numero nell'array
	{
		if(n==vet[k])
		{
			printf("\nla posizione nell'array e' %d",k);
			b=1;
		}
	}
	puts("");
	for(k=0;k<N;k++)
	{
		if(n==*(vet+k))
		{
			printf("\nla posizione nell'array e' %d",k);
			b=1;
		}
	}
	if(b==0)
	{
		printf("\nnumero non trovato nell'array\n");
	}
	maggiore=vet[0];
	for(k=0;k<N;k++)//verifico qual è il numero maggiore
	{
		if(maggiore<vet[k])
		{
			maggiore=vet[k];
		}
	}
	maggiore=*(vet);
	for(k=0;k<N;k++)
	{
		if(maggiore<*(vet+k))
		{
			maggiore=*(vet+k);
		}
	}
	printf("\n\nil numero maggiore e' %d\n",maggiore);
	minore=vet[0];
	for(k=0;k<N;k++)//verifico qual è il numero minore
	{
		if(minore>vet[k])
		{
			minore=vet[k];
		}
	}
	minore=*(vet);
	for(k=0;k<N;k++)
	{
		if(minore>*(vet+k))
		{
			minore=*(vet+k);
		}
	}
	printf("il numero minore e' %d\n\n",minore);
	
	for(k=0;k<N/2;k++)//reverse
	{
		a=vet[k];
		vet[k]=vet[N-k-1];
		vet[N-k-1]=a;
	}
	for(k=0;k<N;k++)//stampo il reverse
	{
		printf("voto studente %d=%d\n",k+1,vet[k]);
	}
	puts("");
	for(k=0;k<N/2;k++)//reverse
	{
		a=*(vet+k);
		*(vet+k)=*(vet+(N-k-1));
		*(vet+(N-k-1))=a;
	}
	free(vet);
	return 0;
}
