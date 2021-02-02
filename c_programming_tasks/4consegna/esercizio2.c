//marcello feroce primo anno ingegneria e scienze informatiche
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    float numero;
	int bin[50];//stabilisco una dimensione massima dell'array che contiene il numero binario. nel caso specifico il numero binario ha un lunghezza massima di cinquanta cifre
	int a,b,c,d;

    printf("Inserisci un valore intero positivo diverso da zero: ");
    scanf("%f", &numero);
    while(numero<0 || numero!=(int)numero)
		{
			printf("il numero digitato deve essere intero e non negativo\n");//controllo affinchè il valore di numero sia corretto
			printf("digita un altro numero");scanf("%f",&numero);
		}
    a=0;
	while (numero>=1)//assegna al vettore del numero binario le cifre 0 e 1 del numero binario. Queste cifre vengono però inserite in posizioni opposte
	{ 
        bin[a]=(int)numero% 2 ;
        numero=(int)numero/2;
        a++;
    }
    printf("a e' %d\n",a);
    for(b=0;b<a;b++)//stampa il numero binario al contrario
	{
		printf("%d",bin[b]);
	}
    puts("");
    c=a-1;//c rappresenta la posizione massima dell'array
    for(b=0;b<a/2;b++)//inverte il numero binario
	{
		d=bin[c];
		bin[c]=bin[b];
		bin[b]=d;
		c--;
	}
    for(b=0;b<a;b++)//stampa il numero binario
	{
		printf("%d",bin[b]);
	}
	 return 0;

}
