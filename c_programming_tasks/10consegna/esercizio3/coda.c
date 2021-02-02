#include<stdio.h>
#include<stdlib.h>
#include"funzioni.h"
int main()
{
	struct Cella*T;
	struct Cella*C;
	struct slista lis;
	int scelta=0;
	int choice=0;
	int val=0;
	int pos=0;
	printf("vuoi lavorare con una coda statica o dinamica?\nrispondere con 1 per statica(dimensione %d) o con 0 per dinamica",N);
	while(scanf("%d",&choice)==0||(choice!=1&&choice!=0))//lettura e controllo sull'imput
	{
		printf("ridigita");
		fflush(stdin);
	}
	fflush(stdin);
	if(choice==0)//coda dinamica
	{
		din_initlista(&T,&C);
		printf("in questo momento l'archivio e' vuoto.\n");
		scelta=menu();//stampo il menu e ricavo la scelta
		while(scelta!=5)//a seconda del valore restituito dalla funzione menu, eseguo una diversa funzione
		{
			switch(scelta)
			{
				case(1):
				{
					if(din_isempty(T)==1)
					{
						printf("la coda e' vuota\n");
						break;
					}
					else
					{
						printf("la coda non e' vuota\n");break;
					}
				}
				case(2):
				{
					printf("digita il valore che vuoi inserire");
					while(scanf("%d",&val)==0)
					{
						printf("ridigita");
						fflush(stdin);
					}
					fflush(stdin);
					din_enqueue(&T,&C,val);break;
				}
				case(3):
				{
					if(din_isempty(T)==1)
					{
						printf("la coda e' vuota");
						break;
					}
					printf("\nla testa e'=%d",din_dequeue(&T));break;
				}
				case(4):
				{
					if(din_isempty(T)==1)
					{
						printf("la coda e' vuota");
						break;
					}
					printf("\nla testa e'=%d",din_first(T));break;
				}
			}
			scelta=menu();
		}
	}
	if(choice==1)
	{
		stat_initlista(&lis);
		printf("in questo momento l'archivio e' vuoto.\n");
		scelta=menu();
		while(scelta!=5)//a seconda del valore restituito dalla funzione menu, eseguo una diversa funzione
		{
			switch(scelta)
			{
				case(1):
				{
					if(stat_isempty(&lis)==1)
					{
						printf("la coda e' vuota\n");
					}
					else
					{
						printf("la coda contiene elementi\n");
					}break;
				}
				case(2):
				{
					printf("digita il valore che vuoi inserire");
					while(scanf("%d",&val)==0)
					{
						printf("ridigita");
						fflush(stdin);
					}
					fflush(stdin);
					stat_enqueue(&lis,val);break;
				}
				case(3):
				{
					if(stat_isempty(&lis)==1)
					{
						printf("la coda e' vuota\n");
					}
					else
					{
						printf("la testa e' %d",stat_dequeue(&lis));
					}
					break;
				}
				case(4):
				{
					if(stat_isempty(&lis)==1)
					{
						printf("la coda e' vuota\n");
						break;
					}
					printf("la testa e' %d",stat_first(&lis));break;;break;
				}
			}
			scelta=menu();
		}
	}
	return 0;
}
