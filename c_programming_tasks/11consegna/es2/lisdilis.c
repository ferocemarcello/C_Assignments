#include<stdio.h>
#include<stdlib.h>
#include"funzioni.h"
int main()
{
	struct anno*Tanno;//testa
	struct anno*Canno;//coda
	int scelta=0;
	initlista(&Tanno,&Canno);
	scelta=menu();//stampo il menu e richiedo la scelta dell'utente
	while(scelta!=8)//a seconda del valore restituito dalla funzione menu, eseguo una diversa funzione
	{
		switch(scelta)
		{
			case(1):
			{
				nuovoanno(&Tanno,&Canno);break;
			}
			case(2):
			{
				nuovostudente(&Tanno,&Canno);break;
			}
			case(3):
			{
				cancellastud(&Tanno,&Canno);break;
			}
			case(4):
			{
				visualizzatutto(Tanno,Canno);break;
			}
			case(5):
			{
				visualizzastud(Tanno,Canno);break;
			}
			case(6):
			{
				nonesame(Tanno,Canno);break;
			}
			case(7):
			{
				maxanno(Tanno,Canno);break;
			}
		}
		scelta=menu();
	}
	return 0;
}
