//MARCELLO FEROCE primo anno ingegneria e scienze infomatiche
#include <stdio.h>
#include <stdlib.h>
int main()
{
	float num;
	int c=0;
	int div=0;
	num=0;
	printf("inserisci un numero intero");
	scanf("%f",&num);
	while(num!=(int)num)
	{
		printf("il numero digitato deve essere intero\n");//controllo affinchè il valore di n sia corretto
		printf("digita un altro numero");scanf("%f",&num);
	}
	div=1;//il divisore iniziale è 1, visto che tutti i numeri sono divisibili per 1
	c=1;
	while(div<=num)//il divisore è sempre più piccolo del dividendo(num)
	{
		if((int)num%div==0)
		{
			printf("\nil divisore %d e' %d",c,div);
			c=c+1;//contatore
		}
	div=div+1;//aumenta il divisore fino a raggiungere il valore del dividendo
	}
	
	return 0;
}
