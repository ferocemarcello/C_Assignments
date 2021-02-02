#include<stdio.h>
#include<stdlib.h>
int main()
{
	int vet1[31];int vet2[31];int disp=0;int disp2=0;int k,s,c1,c2,d;
	printf("immetti i giorni del mese liberi del primo collega(separati da uno spazio)(con 0 termina l'inserimento)");
	c1=0;
	for(k=0;k<31;k++)
	{
		printf("\ngiorno %d:",k+1);//faccio inserire i giorni disponibili del primo collega
		scanf("%d",&disp);
		while(disp>31 || disp<0)
		{
			printf("inserisci un valore intero e compreso tra 0 e 31");
			scanf("%d",&disp);
		}
		if(disp!=0)
		{
			c1+=1;
			vet1[k]=disp;
		}
		else break;
		
	}
	printf("c1 e' %d",c1);
	printf("immetti i giorni del mese liberi del secondo collega(separati da uno spazio)(con 0 termina l'inserimento)");
	c2=0;
	for(k=0;k<31;k++)
	{
		printf("\ngiorno %d:",k+1);//faccio inserire i giorni disponibili del secondo collega
		scanf("%d",&disp);
		while(disp>31 || disp<0)
		{
			printf("inserisci un valore intero e compreso tra 0 e 31");
			scanf("%d",&disp);
		}
		if(disp!=0)
		{
			c2=c2+1;
			vet2[k]=disp;
		}
		else break;
	}
	k=0;
	s=0;
	d=0;	
	for(k=0;k<c1;k++)//stampo i giorni disponibili per entrambi
	{
		for(s=0;s<c2;s++)
		{
			if(vet2[s]==vet1[k]){printf("\ngiorno del mese disponibile per entrambi i colleghi: %d",vet2[s]);d=1;}
		}
	}
	if(d!=1)
	{
		printf("nessun giorno disponibile per entrambi");
	}
	return 0;
}
