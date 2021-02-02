//marcello feroce primo anno ingegneria e scienze informatiche matricola numero 0000730777
#include<stdio.h>
#include<stdlib.h>

int main()
{
	float n;
	int k;
	float fat;

	printf("Digita un numero naturale n\n");
	scanf("%f",&n);
	while(n<0 || n!=(int)n || n>34)
	{
		printf("il numero digitato deve essere intero, non negativo, e non deve superare 34\n");//controllo affinchè il valore di n sia corretto
		printf("digita un altro numero\n");scanf("%f",&n);
	}//richiedo un altro numero
	fat=1;
	for(k=n;k>0;k--)
	{
		fat=fat*k;
	}//ciclo for per il calcolo del fattoriale
	printf("\nil fattoriale(con il for) e' %g\n",fat);
	k=n;
	fat=1;
	while(k>0)
	{
		fat=fat*k;k--;
	}//ciclo while per il calcolo del fattoriale
	printf("il fattoriale(con il while) e' %g",fat);
	
	return 0;
}
