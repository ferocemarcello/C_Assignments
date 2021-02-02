#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	int a=0;
	char frase[101];//lunga 101 perche contiene 100 caratteri più il terminatore di stringa
	int b=0;
	int i=0;
	char c;
	int numlet=0;//numero di lettere
	int cont[26]={0};//array che indica il numero di volte che compare una lette
	char alfa[26]="abcdefghijklmnopqrstuvwxyz";//array di lettere dell'alfabeto
	printf("scrivi una frase\n");
	c=getchar();// assegno ad una variabile c il carattere letto
	while(c!='\n')//ciclo che avvien finchè non si va a capo
	{
			if(isalpha(c)!=0)//se il carattere inserito è una lettera dell'alfabeto, aumenta il numero delle lettere di 1
			{
				numlet++;
			}
		frase[a]=tolower(c);//assegno ad una cella della stringa il valore di c
		a++;
		c=getchar();
	}
	frase[a]='\0';//assegno il terminatore di stringa'\0'
	for(i=97;i<=122;i++)//analizza ogni ascii delle lettere minuscole
	{
		for(b=0;b<a;b++)//analizza ogni lettera della frase
		{		
			if ((int)frase[b]==i)
			{
				cont[i-97]++;//incremento il numero di volte che compare quella lettera(la lettera nella posizione i-97)
			}
		}
	}
	for(b=0;b<26;b++)
	{
		printf("la lettera %c compare %d volte\n",alfa[b],cont[b]);
	}
	printf("\n\nil numero di vocali e' %d",cont[0]+cont[4]+cont[8]+cont[14]+cont[20]);
	printf("\n\nil numero di consonanti e' %d",numlet-(cont[0]+cont[4]+cont[8]+cont[14]+cont[20]));
	return 0;		
}
