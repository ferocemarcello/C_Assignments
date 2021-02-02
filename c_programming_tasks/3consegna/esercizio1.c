//marcello feroce primo anno ingegneria e scienze informatiche matricola numero 0000730777
#include<stdio.h>
#include<stdlib.h>

int main()
{
	float r,c;
	int t,s;
	printf("Digita il numero delle righe");
	scanf("%f",&r);
		while(r<0 || r!=(int)r)
		{
			printf("il numero digitato deve essere intero e non negativo\n");//controllo affinchè il valore di n sia corretto
			printf("digita un altro numero");scanf("%f",&r);
		}
	printf("Digita il numero delle colonne");
	scanf("%f",&c);
	while(c<0 || c!=(int)c)
	{
		printf("il numero digitato deve essere intero e non negativo\n");//controllo affinchè il valore di n sia corretto
		printf("digita un altro numero");scanf("%f",&c);
	}
	
	printf("\n\ntavola pitagorica dell'addizione con il ciclo for");
	puts("");
	puts("");
	for(s=0;s<r;s=s+1)//tavola pitagorica dell'addizione con il ciclo for
	{
		for(t=1;t<=c;t=t+1)
		{
			printf("%d\t",t+s);//uso un ciclo for annidato in un altro ciclo for: prima eseguo il calcolo su ogni casella di una riga, poi scendo alla riga in basso
		}
		puts("");
	}

	s=0;
	t=0;
	printf("\n\ntavola pitagorica dell'addizione con il ciclo while");
	puts("");
	puts("");
	while(s<r)//tavola pitagorica dell'addizione con il ciclo while
	{
		t=0;
		while(t<c)
		{
			printf("%d\t",t+s);t=t+1;	
		}
		puts("");s=s+1;
	}
	s=0;
	t=0;
	printf("\n\ntavola pitagorica della moltiplicazione con il ciclo for");
	puts("");
	puts("");
	for(s=0;s<r;s=s+1)//tavola pitagorica della moltiplicazione con il ciclo for
	{
		for(t=0;t<c;t=t+1)
		{
			printf("%d\t",t*s);//uso un ciclo for annidato in un altro ciclo for: prima eseguo il calcolo su ogni casella di una riga, poi scendo alla riga in basso
		}
		puts("");
	}
	s=0;
	t=0;
	printf("\n\ntavola pitagorica della moltiplicazione con il ciclo while");
	puts("");
	puts("");
	while(s<r)//tavola pitagorica della moltiplicazione con il ciclo while
	{
		t=0;
		while(t<c)
		{
			printf("%d\t",t*s);t=t+1;	
		}
	puts("");s=s+1;
	}
	return 0;
}
