#include<stdio.h>
#include<stdlib.h>
int fattoriale(int n)//funzione ricorsiva che richiama se stessa finchè l'argomento della funzione è <=1, quindi restituisce 1.
{
	if(n<=1)
	{
		return 1;
	}
	else
	{
	return n*fattoriale(n-1);//la funzione restituisce n*(n-1)*(n-2)... finche non si arriva a moltiplicare per n-(n-1)=1
	}
}
int main()
{
	int numero=6;//numero di cui si vuole il fattoriale
	int num=numero;
	int k=0;
	printf("numero=%d\n",numero);
	fattoriale(numero);//ottengo il valore della funzione
	while(numero>=1)//ciclo per stampare a video con una tabulazione crescente le ricorsioni
	{
		for(k=0;k<=num-numero;k++)
		{
			printf("\t");
		}
		printf("quindi chiama fattoriale(%d)\n",numero);
		numero--;
	}
	for(k=0;k<=num-numero;k++)
		{
			printf("\t");
		}
	printf("fattoriale(1)=%d\n",fattoriale(1));
	while(numero<num-1)//stampo a video con una tabulazione decrescente il valore del fattoriale di num-numero, con numero decrescente
	{
		for(k=0;k<=num-numero-1;k++)
		{
			printf("\t");
		}
		numero++;
		printf("fattoriale(%d)=%d\n",numero+1,fattoriale(numero+1));
	}
	return 0;
}
