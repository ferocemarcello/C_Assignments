#include<stdio.h>
#include<stdlib.h>
struct smercato
{
	int *codicevenditore;
	int *codiceprodotto;
	int *quantitavenduto;
	
}mercato;

int main()
{
	int n=0;
	int a=0;
	int giorni=0;
	srand((unsigned int) time(NULL));
	printf("quanti sono i venditori?");
	scanf("%d",&n);
	mercato.codicevenditore=(int*)malloc(n*sizeof(int));
	for(a=0;a<n;a++)
	{
		mercato.codicevenditore[a]=rand()%10;
		while(mercato.codicevenditore[a]==mercato.codicevenditore[a-1] &&a>0)
		{
			mercato.codicevenditore[a]=rand()%10;
		}
		printf("codicevenditore[%d]=%d\n",a,mercato.codicevenditore[a]);
	}
	mercato.codiceprodotto=(int*)malloc(n*sizeof(int));
	for(a=0;a<n;a++)
	{
		mercato.codiceprodotto[a]=rand()%10;
		while(mercato.codiceprodotto[a]==mercato.codiceprodotto[a-1] &&a>0)
		{
			mercato.codiceprodotto[a]=rand()%10;
		}
		printf("codiceprodotto[%d]=%d\n",a,mercato.codiceprodotto[a]);
	}
	mercato.quantitavenduto=(int*)malloc(n*sizeof(int));
	for(a=0;a<n;a++)
	{
		mercato.quantitavenduto[a]=rand()%10;
		while(mercato.quantitavenduto[a]==mercato.quantitavenduto[a-1] &&a>0)
		{
			mercato.quantitavenduto[a]=rand()%10;
		}
		printf("quantitavenduto[%d]=%d\n",a,mercato.quantitavenduto[a]);
	}
	printf("a quanti giorni ammonta il periodo?");
	scanf("%d",&giorni);
	return 0;
}
