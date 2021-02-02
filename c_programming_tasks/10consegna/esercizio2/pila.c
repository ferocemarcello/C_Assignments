#include<stdio.h>
#include<stdlib.h>
#include"funzioni.h"//includo l'header file funzioni.h
int main()
{
	struct Cella*T;//dichiaro il puntatore a struct Cella T, testa
	struct Cella*C;//dichiaro il puntatore a struct Cella C, coda
	struct slista lis;//dichiaro la variabile di tipo struct slista
	int scelta=0;//variabile per la scelta nel menu
	int choice=0;//variabile per la scelta tra pila dinamica, e pila statica
	int val=0;//variabile usata per leggere ed usare un valore
	printf("vuoi lavorare con una pila statica o dinamica?\nrispondere con 1 per statica(dimensione %d) o con 0 per dinamica",N);
	while(scanf("%d",&choice)==0||(choice!=1&&choice!=0))//lettura e controllo sull'imput
	{
		printf("ridigita");
		fflush(stdin);
	}
	fflush(stdin);
	if(choice==0)
	{
		din_initlista(&T,&C);//inizializzo la lista dinamica
		printf("in questo momento l'archivio e' vuoto.\n");
		scelta=menu();//stampa il menu e restituisce la scelta
		while(scelta!=5)//a seconda del valore restituito dalla funzione menu, eseguo una diversa funzione
		{
			switch(scelta)
			{
				case(1):
				{
					if(din_isempty(T)==1)//la funzione din_isempty(struct Cella*) restituisce 1 se la pila è vuota
					{
						printf("la pila e' vuota\n");
					}
					else
					{
						printf("la pila non e' vuota\n");
					}
					break;
				}
				case(2):
				{
					printf("digita il valore che vuoi inserire\n");
					while(scanf("%d",&val)==0)//lettura e controllo sull'imput
					{
						printf("ridigita\n");
						fflush(stdin);
					}
					fflush(stdin);
					din_push(&T,&C,val);break;//inserisce un valore in testa
				}
				case(3):
				{
					if(din_isempty(T)==1)//se la pila è vuota, non posso restituire la testa
					{
						printf("la pila e' vuota\n");
						break;
					}
					printf("\nla testa e'=%d\n",din_pop(&T));break;//la funzione din_pop(struct Cella**)restituisce la testa e la elimina
				}
				case(4):
				{
					if(din_isempty(T)==1)//se la pila è vuota, non posso restituire la testa
					{
						printf("la pila e' vuota\n");
						break;
					}
					printf("\nla testa e'=%d\n",din_top(T));break;//la funzione din_top(struct Cella**)restituisce la testa
				}
			}
			scelta=menu();
		}
	}
	if(choice==1)//pila statica
	{
		stat_initlista(&lis);
		printf("in questo momento l'archivio e' vuoto.\n");
		scelta=menu();//stampo il menu e ricavo la scelta
		while(scelta!=5)//a seconda del valore restituito dalla funzione menu, eseguo una diversa funzione
		{
			switch(scelta)
			{
				case(1)://la funzione stat_isempty(struct Cella*) restituisce 1 se la pila è vuota
				{
					if(stat_isempty(&lis)==1)
					{
						printf("la pila e' vuota\n");
					}
					else
					{
						printf("la pila contiene elementi\n");
					}break;
				}
				case(2):
				{
					printf("digita il valore che vuoi inserire\n");
					while(scanf("%d",&val)==0)//lettura e controllo sull'imput
					{
						printf("ridigita");
						fflush(stdin);
					}
					fflush(stdin);
					stat_push(&lis,val);break;//inserisce un valore in testa
				}
				case(3):
				{
					if(stat_isempty(&lis)==1)//se la pila è vuota, non posso restituire la testa
					{
						printf("la pila e' vuota\n");
						break;
					}
					printf("la testa e' %d\n",stat_pop(&lis));break;//la funzione stat_pop(struct Cella**)restituisce la testa e la elimina
				}
				case(4):
				{
					if(stat_isempty(&lis)==1)//se la pila è vuota, non posso restituire la testa
					{
						printf("la pila e' vuota\n");
						break;
					}
					printf("la testa e' %d\n",stat_top(&lis));break;;break;//la funzione stat_pop(struct Cella**)restituisce la testa
				}
			}
			scelta=menu();
		}
	}
	
	return 0;
}
